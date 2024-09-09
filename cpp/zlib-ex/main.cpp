#include <glog/logging.h>
#include <zlib.h>

#include <vector>
using namespace std;

void rep64() {
  vector<int> org;
  for (int i = 0; i < 65536; i++) {
    org.push_back(i % 64);
  }
  const uint64_t org_len = org.size() * sizeof(int);
  unsigned char *cmpr_data = new unsigned char[org_len];

  uint64_t cmpr_size = org_len;

  // 0: no compression, 1: best speed, 9: best compression
  const int cmpr_level = 1;
  compress2(cmpr_data, &cmpr_size,
            reinterpret_cast<const unsigned char *>(&org.front()), org_len,
            cmpr_level);

  LOG(INFO) << "org size: " << org_len << " cmpr size: " << cmpr_size;


  // uncompress
  vector<int> decmpr_data(org.size());
  uint64_t decmpr_len = org_len;
  auto ret = uncompress(
      reinterpret_cast<unsigned char*>(&decmpr_data[0]),
      &decmpr_len,
      cmpr_data,
      cmpr_size);
  CHECK(ret == Z_OK) << "uncompress returns " << ret;
  CHECK(decmpr_len == org_len);
  CHECK(decmpr_data[37621] == 53);
  CHECK(decmpr_data.back() == 63);


  delete[] cmpr_data;

}

int main(int argc, char **argv) {
  rep64();
  return 0;
}
