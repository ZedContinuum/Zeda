# Makefile

Name    = $(shell basename $(CURDIR))
Version = 0.0.0-alpha

CC      = gcc
BFlags  = -std=c11 -march=native
CFlags  = $(BFlags) -w -O3
DFlags  = $(BFlags) -Wall -g -O2
#LFlags  = ``

Sources = $(shell find . -name '*.cpp' -printf '%P\n')
Manuals = $(CURDIR)/man
Scripts = $(CURDIR)/scripts
Tests   = $(CURDIR)/tests
Install = /usr/local

Build   = $(CURDIR)/build
Bin     = $(Build)/bin
Lib     = $(Build)/lib
Man     = $(Build)/man
Share   = $(Build)/share

export Name Version
export CC BFlags CFlags DFlags LFlags
export Sources Manuals Scripts Tests Install
export Build Bin Lib Man Share

all: $(Sources)
	[ -d $(Bin) ] || mkdir -p $(Bin); \
	$(CC) $(CFlags) $(Sources) $(LFlags) -o $(Bin)/$(Name)

debug: $(Sources)
	[ -d $(Bin) ] || mkdir -p $(Bin); \
	$(CC) $(DFlags) $(Sources) $(LFlags) -o $(Bin)/$(Name)

#test:

install:
	[ -d $(Bin) ]   && cp -r $(Bin)/*   $(Install)/bin/
#	[ -d $(Lib) ]   && cp -r $(Lib)/*   $(Install)/lib/
#	[ -d $(Man) ]   && cp -r $(Man)/*   $(Install)/man/
#	[ -d $(Share) ] && cp -r $(Share)/* $(Install)/share/

uninstall:
	[ -d $(Bin) ]   && rm -rf $(Install)/bin/$(Name)
#	[ -d $(Lib) ]   && rm -rf $(Install)/lib/$(Name)
#	[ -d $(Man) ]   && rm -rf $(Install)/man/$(Name)
#	[ -d $(Share) ] && rm -rf $(Install)/share/$(Name)

clean:
	@rm -rf $(Build)

#distclean:

help:
	@echo "make: $(Name): Available options:"
	@echo "	 (default)    Build '$(Name)' with '$(CFlags)'"
	@echo "	 debug	      Build '$(Name)' with '$(DFlags)'"
#	@echo "	 test	      Run all tests in testing suite"
	@echo "	 install      Install '$(Name)' to '$(Install)'"
	@echo "	 uninstall    Remove '$(Name)' from '$(Install)'"
	@echo "	 clean	      Delete temporary files"
#	@echo "	 distclean    Delete all unshipped files"
