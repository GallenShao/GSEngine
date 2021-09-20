#! /bin/bash

cd `dirname $0`/test

if [ ! -d cmake-build-debug ]; then
	mkdir cmake-build-debug
fi

cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
cd cmake-build-debug && ctest
