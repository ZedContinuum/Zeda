#include "libconf/libconf.h"

gz::gz(int chunksize) {
  CHUNKSIZE = chunksize;
  std::cout << "Chunksize: " << CHUNKSIZE << std::endl;
}

gz::~gz() {
}

int gz::Compress() {
  return LC_OK;
}

int gz::Decompress() {
  return LC_GZ_INIT_FAIL;
}
