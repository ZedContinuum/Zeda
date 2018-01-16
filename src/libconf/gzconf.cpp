#include "libconf/libconf.h"

gz::gz(int chunksize) {
  CHUNKSIZE = chunksize;
  tempBuffer = new char[CHUNKSIZE];
  std::cout << "Chunksize: " << CHUNKSIZE << std::endl;
}

gz::~gz() {
  delete tempBuffer;
}

int gz::Compress() {
  return LC_OK;
}

int gz::Decompress() {
  return LC_GZ_INIT_FAIL;
}
