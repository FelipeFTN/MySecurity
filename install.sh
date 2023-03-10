#!/bin/bash

if command -v cmake > /dev/null 2>&1; then
  echo "-- Initiating MySecurity build"
else
  echo "error: cmake is not installed!"
  echo "please install cmake on your machine or try installing with Makefile."
  exit 127
fi

cmake -B cmake/
cd cmake/
make
cp ./MySecurity ../MySecurity
