#! /bin/bash

cd `dirname $0`/platform/mac

if [ ! -d cmake-build-debug ]; then
	mkdir cmake-build-debug
fi

cmake --build cmake-build-debug --target GSEngine_test -- -j 9

if [ $? -eq 0 ]; then
  ./cmake-build-debug/output/GSEngine_test
fi
