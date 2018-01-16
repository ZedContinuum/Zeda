#include "libconf/libconf.h"

int main() {
  //Initialize
  gz *gzip = new gz(LC_MB(16));
  int ret = 0;

  ret = gzip->Compress();
  std::cout << LC_GetError(ret) << std::endl;

  ret = gzip->Decompress();
  std::cout << LC_GetError(ret) << std::endl;

  return 0;
}
