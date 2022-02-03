#! /bin/bash

cd `dirname $0`/platform/mac

if [ ! -d cmake-build-debug ]; then
	mkdir cmake-build-debug
fi

cd cmake-build-debug
cmake ..