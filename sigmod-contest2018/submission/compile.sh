#!/bin/bash

DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )

cd $DIR
mkdir -p build/release
cd build/release
#export CC=/usr/local/bin/gcc
#export CXX=/usr/local/bin/g++
cmake -DCMAKE_BUILD_TYPE=Release -DFORCE_TESTS=OFF ../..
#make -j8
make -j5
