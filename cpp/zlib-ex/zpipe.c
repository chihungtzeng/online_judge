/* zpipe.c: example of proper use of zlib's inflate() and deflate()
   Not copyrighted -- provided to the public domain
   Version 1.4  11 December 2005  Mark Adler */

/* Version history:
   1.0  30 Oct 2004  First version
   1.1   8 Nov 2004  Add void casting for unused return values
                     Use switch statement for inflate() return values
   1.2   9 Nov 2004  Add assertions to document zlib guarantees
   1.3   6 Apr 2005  Remove incorrect assertion in inf()
   1.4  11 Dec 2005  Add hack to avoid MSDOS end-of-line conversions
                     Avoid some compiler warnings for input and output buffers
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <iostream>

#include "glog/logging.h"
#include "zlib.h"

#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#include <fcntl.h>
#include <io.h>
#define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
#else
#define SET_BINARY_MODE(file)
#endif

#define CHUNK 16384

size_t fread_all(const char *filename, uint8_t *dest) {
  FILE *fp = fopen(filename, "r");
  size_t nread = 0;
  size_t total = 0;
  while ((nread = fread(dest + total, sizeof(uint8_t), CHUNK, fp)) != 0) {
    total += nread;
  }
  fclose(fp);
  return total;
}

int fwrite_all(const char *filename, uint8_t *contents, size_t len) {
  FILE *fp = fopen(filename, "w");
  size_t nwrite = 0;
  size_t total = 0;
  while ((nwrite = fwrite(contents + total, sizeof(uint8_t), len - total,
                          fp)) != 0) {
    total += nwrite;
  }
  return bool(total == len);
}

int cmpr(uint8_t *src, size_t src_len, uint8_t *dest, size_t dest_len, size_t *cmpr_len) {
  int ret, flush;
  unsigned have;
  z_stream strm;
  strm.zalloc = Z_NULL;
  strm.zfree = Z_NULL;
  strm.opaque = Z_NULL;
  ret = deflateInit(&strm, Z_DEFAULT_COMPRESSION);
  if (ret != Z_OK) return ret;

  strm.avail_in = src_len;
  strm.next_in = src;

  strm.avail_out = dest_len;
  strm.next_out = dest;
  ret = deflate(&strm, Z_FINISH); /* no bad return value */
  assert(ret != Z_STREAM_ERROR);  /* state not clobbered */
  LOG(INFO) << "Z_STREAM_ERROR: " << Z_STREAM_ERROR;
  LOG(INFO) << "Z_ERRNO: " << Z_ERRNO;
  LOG(INFO) << "Z_MEM_ERROR: " << Z_MEM_ERROR;
  LOG(INFO) << "Z_OK: " << Z_MEM_ERROR;
  *cmpr_len = dest_len - strm.avail_out;
  (void)deflateEnd(&strm);
  return ret;
}

/* Compress from file source to file dest until EOF on source.
   def() returns Z_OK on success, Z_MEM_ERROR if memory could not be
   allocated for processing, Z_STREAM_ERROR if an invalid compression
   level is supplied, Z_VERSION_ERROR if the version of zlib.h and the
   version of the library linked do not match, or Z_ERRNO if there is
   an error reading or writing the files. */
int def(FILE *source, FILE *dest, int level) {
  int ret, flush;
  unsigned have;
  z_stream strm;
  unsigned char in[CHUNK];
  unsigned char out[CHUNK];

  /* allocate deflate state */
  strm.zalloc = Z_NULL;
  strm.zfree = Z_NULL;
  strm.opaque = Z_NULL;
  ret = deflateInit(&strm, level);
  if (ret != Z_OK) return ret;

  /* compress until end of file */
  do {
    strm.avail_in = fread(in, 1, CHUNK, source);
    if (ferror(source)) {
      (void)deflateEnd(&strm);
      return Z_ERRNO;
    }
    flush = feof(source) ? Z_FINISH : Z_NO_FLUSH;
    strm.next_in = in;

    /* run deflate() on input until output buffer not full, finish
       compression if all of source has been read in */
    do {
      strm.avail_out = CHUNK;
      strm.next_out = out;
      ret = deflate(&strm, flush);   /* no bad return value */
      assert(ret != Z_STREAM_ERROR); /* state not clobbered */
      have = CHUNK - strm.avail_out;
      if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
        (void)deflateEnd(&strm);
        return Z_ERRNO;
      }
    } while (strm.avail_out == 0);
    assert(strm.avail_in == 0); /* all input will be used */

    /* done when last data in file processed */
  } while (flush != Z_FINISH);
  assert(ret == Z_STREAM_END); /* stream will be complete */

  /* clean up and return */
  (void)deflateEnd(&strm);
  return Z_OK;
}

/* Decompress from file source to file dest until stream ends or EOF.
   inf() returns Z_OK on success, Z_MEM_ERROR if memory could not be
   allocated for processing, Z_DATA_ERROR if the deflate data is
   invalid or incomplete, Z_VERSION_ERROR if the version of zlib.h and
   the version of the library linked do not match, or Z_ERRNO if there
   is an error reading or writing the files. */
int inf(FILE *source, FILE *dest) {
  int ret;
  unsigned have;
  z_stream strm;
  unsigned char in[CHUNK];
  unsigned char out[CHUNK];

  /* allocate inflate state */
  strm.zalloc = Z_NULL;
  strm.zfree = Z_NULL;
  strm.opaque = Z_NULL;
  strm.avail_in = 0;
  strm.next_in = Z_NULL;
  ret = inflateInit(&strm);
  if (ret != Z_OK) return ret;

  /* decompress until deflate stream ends or end of file */
  do {
    strm.avail_in = fread(in, 1, CHUNK, source);
    if (ferror(source)) {
      (void)inflateEnd(&strm);
      return Z_ERRNO;
    }
    if (strm.avail_in == 0) break;
    strm.next_in = in;

    /* run inflate() on input until output buffer not full */
    do {
      strm.avail_out = CHUNK;
      strm.next_out = out;
      ret = inflate(&strm, Z_NO_FLUSH);
      assert(ret != Z_STREAM_ERROR); /* state not clobbered */
      switch (ret) {
        case Z_NEED_DICT:
          ret = Z_DATA_ERROR; /* and fall through */
        case Z_DATA_ERROR:
        case Z_MEM_ERROR:
          (void)inflateEnd(&strm);
          return ret;
      }
      have = CHUNK - strm.avail_out;
      if (fwrite(out, 1, have, dest) != have || ferror(dest)) {
        (void)inflateEnd(&strm);
        return Z_ERRNO;
      }
    } while (strm.avail_out == 0);

    /* done when inflate() says it's done */
  } while (ret != Z_STREAM_END);

  /* clean up and return */
  (void)inflateEnd(&strm);
  return ret == Z_STREAM_END ? Z_OK : Z_DATA_ERROR;
}

/* report a zlib or i/o error */
void zerr(int ret) {
  fputs("zpipe: ", stderr);
  switch (ret) {
    case Z_ERRNO:
      if (ferror(stdin)) fputs("error reading stdin\n", stderr);
      if (ferror(stdout)) fputs("error writing stdout\n", stderr);
      break;
    case Z_STREAM_ERROR:
      fputs("invalid compression level\n", stderr);
      break;
    case Z_DATA_ERROR:
      fputs("invalid or incomplete deflate data\n", stderr);
      break;
    case Z_MEM_ERROR:
      fputs("out of memory\n", stderr);
      break;
    case Z_VERSION_ERROR:
      fputs("zlib version mismatch!\n", stderr);
  }
}

/* compress or decompress from stdin to stdout */
int main2(int argc, char **argv) {
  int ret;

  /* avoid end-of-line conversions */
  SET_BINARY_MODE(stdin);
  SET_BINARY_MODE(stdout);

  /* do compression if no arguments */
  if (argc == 1) {
    ret = def(stdin, stdout, Z_DEFAULT_COMPRESSION);
    if (ret != Z_OK) zerr(ret);
    return ret;
  }

  /* do decompression if -d specified */
  else if (argc == 2 && strcmp(argv[1], "-d") == 0) {
    ret = inf(stdin, stdout);
    if (ret != Z_OK) zerr(ret);
    return ret;
  }

  /* otherwise, report usage */
  else {
    fputs("zpipe usage: zpipe [-d] < source > dest\n", stderr);
    return 1;
  }
}

int main(int argc, char *argv[]) {
  constexpr size_t buf_size = 1<<22;
  uint8_t *src = new uint8_t[buf_size];
  auto nread = fread_all("lett.bin", src);
  LOG(INFO) << nread;

  constexpr size_t dest_len = 1 << 10;
  uint8_t *dest = new uint8_t[dest_len];

  //size_t cmpr_len = 0;
  //auto cmpr_ret = cmpr(src, nread, dest, buf_size, &cmpr_len);
  long unsigned int cmpr_len = dest_len;
  auto cmpr_ret = compress(dest, &cmpr_len, src, nread);
  LOG(INFO) << "cmpr_len: " << cmpr_len << " cmpr_ret: " << cmpr_ret;

  auto ret = fwrite_all("temp.bin", dest, cmpr_len);
  delete[] src;
  delete[] dest;

  return 0;
}
// size_t fread_all(FILE *fp, uint8_t *dest) {
