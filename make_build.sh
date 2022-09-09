#!/bin/bash
mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TESTS=True
make