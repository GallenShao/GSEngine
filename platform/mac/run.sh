#! /bin/bash

cd `dirname $0`
./build.sh

if [ $? -eq 0 ]; then
	./build/output/GSEngineMacOS;
fi;