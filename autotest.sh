#! /bin/bash

cd `dirname $0`/platform/mac

if [ ! -d cmake-build-debug ]; then
	mkdir cmake-build-debug
fi

cmake --build cmake-build-debug --target GSEngine_test -- -j 9
./cmake-build-debug/output/GSEngine_test --gtest_filter=* --gtest_color=no
