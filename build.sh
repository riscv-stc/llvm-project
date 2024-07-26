#!/bin/bash

LLVM_HOME=`pwd`
INSTALL=~/opt/riscv
TYPE=Release
THREAD=32
BUILD_ONLY=0
LLVM_DYLIB=On
BUILD_DIR=build
LOG=$LLVM_HOME/build/build.log
PROJECTS="clang;compiler-rt;lld;clang-tools-extra"
TOOL="Unix Makefiles"
#LINKER="gold"
#SECURITY_OPTION="-fPIE -pie -fstack-protector-all -Wl,-z,relro,-z,now,-z,noexecstack"

help() {
cat<<HELP

Usage: ./build.sh param

-b           Set build only, default is 0
-g           Set build type to Debug, default is Release
-h --help    Print parameter description
-j           Set therad number, default is 8
-l           Set path of log, default is ./build/build.log
-p --prefix  Set CMAKE_INSTALL_PREFIX, default is ~/opt/riscv
-n           use ninja to build

HELP
exit 0
}

build_install_llvm() {
if [ ! -d $BUILD_DIR ]; then
  mkdir $BUILD_DIR
fi

MAKE="make"
if [ "${TOOL}" = "Ninja" ]; then
  MAKE=ninja
fi

# Only use ld in centos.
if [[ `uname -a` =~ "centos" ]]; then
   LINKER=""
fi

# More cmake option reference https://llvm.org/docs/CMake.html
cd $BUILD_DIR && cmake -G "$TOOL"                                 \
                 -DCMAKE_INSTALL_PREFIX=$INSTALL                  \
                 -DCMAKE_BUILD_TYPE=$TYPE                         \
                 -DLLVM_OPTIMIZED_TABLEGEN=On                     \
                 -DLLVM_ENABLE_PROJECTS=$PROJECTS                 \
                 -DLLVM_TARGETS_TO_BUILD="X86;RISCV" ../llvm > $LOG 2>&1
if [ $? -ne 0 ] ; then
    echo "llvm cmake failed, exit!"
    cat $LOG
    exit 1
fi

$MAKE -j $THREAD VERBOSE=9 >> $LOG 2>&1
if [ $? -ne 0 ] ; then
    echo "llvm make failed, exit!"
    cat $LOG
    exit 1
fi

if [ $BUILD_ONLY -eq 1 ]; then
    echo "llvm build successful"
    exit 0
fi

$MAKE install >> $LOG 2>&1
if [ $? -ne 0 ] ; then
    echo "llvm make install failed, exit!"
    cat $LOG
    exit 1
fi

}

while [ -n "$1" ]
do
    case "$1" in
        -h|--help) help ;;
        -b) BUILD_ONLY="1" ;;
        -n) TOOL="Ninja" ;;
        -g) TYPE="Debug"
            LLVM_DYLIB=OFF
            BUILD_DIR=build_debug
            PROJECTS="clang;lld"
            LOG=$LLVM_HOME/$BUILD_DIR/build.log ;;
        -p|--prefix) INSTALL="$2"
            shift ;;
        -l) LOG="$2"
            shift ;;
        -j) THREAD="$2"
	    shift ;;
        *) echo "error: $1 is not an option"
           exit 1;;
    esac
    shift
done

echo "start to build llvm"
build_install_llvm
