#ifndef __H_LIBCONF_
#define __H_LIBCONF_

// Includes
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include "zlib.h"

// Local Includes
#include "libconf/gzconf.h"
#include "libconf/conf.h"

static int LC_MB(int MB) {
  return MB * 1000000;
}

static std::string LC_GetError(int error) {
  switch(error) {
  case 0: return "No error"; break;
  case 1: return "GZip Failed to initialize"; break;
  case 2: return "Failed to load: not a valid gzip file"; break;
  case 3: return "GZip memory fail"; break;
  case 4: return "Not Implemented!!!"; break;
  default: return "This is not a valid error code"; break;
  }
};

enum LC_ERROR {
	      LC_OK,
	      LC_GZ_INIT_FAIL,
	      LC_GZ_CANNOT_OPEN,
	      LC_GZ_MEMORY_ERROR,
	      LC_NOT_IMPLEMENTED
};

#endif
