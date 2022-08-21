#!/bin/bash
#Author: David Hu
#Date: 2022-08

# Exit on error
set -e

OPTION=$1

if [ ! -e "./build" ];then
  mkdir build
  echo "create build/"
fi

echo "start cmake build"
cd ./build
cmake ..
make

OPTION_VAL_INSTALL="install"
if [ ${OPTION} == ${OPTION_VAL_INSTALL} ];then
  if [ ! -e "./install" ];then
    cd ..
    mkdir install
    echo "create install/"
  fi
  cd ./build
  make install
fi


