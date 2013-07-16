GENCCODE_ASSEMBLY_TYPE=-a gcc
SO=so
SOBJ=so
A=a
LIBPREFIX=lib
LIB_EXT_ORDER=.50.1.2
COMPILE=gcc -ffunction-sections -fdata-sections -D_REENTRANT   -DU_ATTRIBUTE_DEPRECATED= -DUCONFIG_NO_BREAK_ITERATION -DUCONFIG_NO_COLLATION -DUCONFIG_NO_FORMATTING -DUCONFIG_NO_TRANSLITERATION -DUCONFIG_NO_FILE_IO -Wall -std=c99 -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings  -c
LIBFLAGS=-I/home/tk/MMDAI/icu4c-src/build-release/install-root/include -DPIC -fPIC
GENLIB=gcc -DUCONFIG_NO_BREAK_ITERATION -DUCONFIG_NO_COLLATION -DUCONFIG_NO_FORMATTING -DUCONFIG_NO_TRANSLITERATION -DUCONFIG_NO_FILE_IO -Wall -std=c99 -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings  -Wl,--gc-sections  -shared -Wl,-Bsymbolic
LDICUDTFLAGS=-nodefaultlibs -nostdlib
LD_SONAME=-Wl,-soname -Wl,
RPATH_FLAGS=
BIR_LDFLAGS=-Wl,-Bsymbolic
AR=ar
ARFLAGS=r
RANLIB=ranlib
INSTALL_CMD=/usr/bin/install -c
