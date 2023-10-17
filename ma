#!/bin/sh
set -e
if [ -n "$1" ]; then
    PARAL=$1
else
    PARAL=4
fi

cd build/app
rm -f ./bin/*
rm -f ./.local/bin/*
make -j ${PARAL}
make test
make install
cd ../..
