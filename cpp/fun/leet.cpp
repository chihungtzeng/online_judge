#include <glog/logging.h>
#include <glog/stl_logging.h>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <queue>
using namespace std;

struct CarState {
  int steps, speed, pos, dir;
  bool operator>(const CarState& other) const {
    return steps > other.steps;
  }

  CarState(int steps=0, int speed=0, int pos=0, int dir=1): steps(steps), speed(speed), pos(pos), dir(dir) {}
};

void *my_memcpy_v1(void* dest, void* src, size_t n) {
  uint8_t *dest8 = static_cast<uint8_t *>(dest);
  uint8_t *src8 = static_cast<uint8_t *>(src);
  for(size_t i=0; i<n; i++){
    *dest8++ = *src8++;
  }
  return dest;
}

void *my_memcpy_v2(void* dest, void* src, size_t n) {
  uint8_t *dest8 = static_cast<uint8_t *>(dest);
  uint8_t *src8 = static_cast<uint8_t *>(src);
  while(n > 0){
    *dest8++ = *src8++;
    n--;
  }
  return dest;
}

void *my_memcpy_v3(void* dest, void* src, size_t n) {
  uint64_t *dest64 = static_cast<uint64_t *>(dest);
  uint64_t *src64 = static_cast<uint64_t *>(src);
  size_t ncopy = 0;
  while(ncopy + 8 < n){
    *dest64++ = *src64++;
    ncopy += 8;
  }
  uint8_t *dest8 = reinterpret_cast<uint8_t *>(dest64);
  uint8_t *src8 = reinterpret_cast<uint8_t *>(src64);
  while(ncopy < n){
    *dest8++ = *src8++;
    ncopy++;
  }
  return dest;
}

void *my_memcpy_v4(void* dest, void* src, size_t n) {
  uint64_t *dest64 = static_cast<uint64_t *>(dest);
  uint64_t *src64 = static_cast<uint64_t *>(src);
  while(n >= 8){
    *dest64++ = *src64++;
    n -= 8;
  }
  uint8_t *dest8 = reinterpret_cast<uint8_t *>(dest64);
  uint8_t *src8 = reinterpret_cast<uint8_t *>(src64);
  while(n > 0){
    *dest8++ = *src8++;
    n--;
  }
  return dest;
}

void *my_memmove_v1(void* dest, void* src, size_t n) {
  uint8_t *d8 = static_cast<uint8_t *>(dest) + n;
  uint8_t *s8 = static_cast<uint8_t *>(src) + n;
  d8--;
  s8--;
  while(d8 >= dest) {
    *d8-- = *s8--;
  }
  return dest;
}

void *my_memmove_v2(void* dest, void* src, size_t n) {
 int k = n / 8, r = n % 8;
  uint64_t *d64 = static_cast<uint64_t *>(dest) + k - 1;
  uint64_t *s64 = static_cast<uint64_t *>(src) + k - 1;
  while(k--){
    *d64-- = *s64--;
  }
  uint8_t *d8 = static_cast<uint8_t *>(dest) + n - 1;
  uint8_t *s8 = static_cast<uint8_t *>(src) + n - 1;
  while(r--) {
    *d8-- = *s8--;
  }
  return dest;
}

int** mymalloc2d(int row, int col) {
  int **ptr = (int **) malloc(row*sizeof(int *));
  int *data = (int *) malloc(sizeof(int)*row*col);
  size_t offset = 0;
  for(int i=0; i<row; i++){
    *(ptr + i) = data + offset;
    offset += col;
  }
  return ptr;
}

void myfree2d(int **ptr){
  if (ptr){
    if (*ptr) {
      free(*ptr);
      *ptr = nullptr;
    }
    free(ptr);
    ptr=nullptr;
  }
}

int** mymalloc2d_v2(int row, int col) {
  size_t header = row * sizeof(int *);
  size_t data_len = row * col * sizeof(int);
  int **ptr = (int **) malloc(header + data_len);
  size_t offset = 0;
  const size_t inc = col * sizeof(int);
  for (int i=0; i<row; i++){
    *(ptr + i) = (int *) ((uint8_t *) ptr + header + offset);
    offset += inc;
  }
  return ptr;
}

void myfree2d_v2(int **ptr){
  if (ptr){
    free(ptr);
    ptr=nullptr;
  }
}
