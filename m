#!/bin/sh
set -e
if [ -n "$1" ]; then
    PARAL=$1
else
    PARAL=1
fi

# cd build/lib3rd
# make -j ${PARAL}
# make test
# make install
# cd ../..

cd build/xel
make -j ${PARAL}
make test
make install
cd ../..

cd build/app
rm -f ./bin/*
rm -f ./.local/bin/*
make -j ${PARAL}
make test
make install
cd ../..