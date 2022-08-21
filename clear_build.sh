#!/bin/bash
#Author: David Hu
#Date: 2022-08
set -e

if [ -e "./build" ];then
  rm -rf build/
  echo "del build/"
fi

if [ -e "./install" ];then
  rm -rf install/
  echo "del install/" 
fi

if [[ ! -e "./build" && ! -e "./install" ]];then
  echo "del is ok....."
fi
