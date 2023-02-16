!#/bin/bash

cmake -B cmake/
cd cmake/
make
cp ./MySecurity ../MySecurity
