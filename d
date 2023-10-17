#!/bin/sh

set -e
if [ -n "$1" ]; then
    PARAL=$1
else
    PARAL=8
fi

rm -rf ./build
mkdir -p ./build/xel
mkdir -p ./build/lib3rd
mkdir -p ./build/app

if [ ! -d logs ];then
mkdir logs
fi

# cd build/lib3rd
# cmake -DCMAKE_BUILD_TYPE=Debug -Wno-dev ../../lib3rd
# make -j ${PARAL}
# make test
# make install
# cd ../..

cd build/xel
cmake -DCMAKE_BUILD_TYPE=Debug -DX_OPTION_STATIC=true -Wno-dev ../../CppSample
make -j ${PARAL}
make test
make install
cd ../..

cd build/app
cmake -DCMAKE_BUILD_TYPE=Debug -DX_OPTION_STATIC=true -Wno-dev ../../Hammer
make -j ${PARAL}
make test
make install
cd ../..