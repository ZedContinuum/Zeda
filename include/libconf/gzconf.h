#ifndef __H_GZCONF_
#define __H_GZCONF_

#include "libconf/libconf.h"

#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
#  include <fcntl.h>
#  include <io.h>
#  define SET_BINARY_MODE(file) setmode(fileno(file), O_BINARY)
#else
#  define SET_BINARY_MODE(file)
#endif

class gz {

public:

  gz(int chunkSize);
  ~gz();
  int Compress();
  int Decompress();
  std::string GetError(int error);
protected:
  int CHUNKSIZE;

};

#endif
