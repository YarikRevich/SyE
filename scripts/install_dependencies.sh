#!/bin/bash 

#Install dependencies 

if [[ $OSTYPE != 'darwin'* ]]; then 
    apt-get update;
    apt-get install git;
    apt-get install cmake;
    apt-get install make;
    apt-get install wget;
fi


echo -e "\033[32mDependencies are installed\033[0m"

cd ../;
mkdir -p vendor;
cd vendor;

#Functions for dependencies install

function install_yaml_cpp (){
    git clone https://github.com/jbeder/yaml-cpp.git yaml-cpp && cd yaml-cpp

    mkdir build
    cd build

    cmake .. && make && make install
    cd ../../
}

function install_boost (){
    wget https://boostorg.jfrog.io/artifactory/main/release/1.76.0/source/boost_1_76_0.tar.gz -P boost
    cd boost
    tar -xf boost_1_76_0.tar.gz
    cd boost_1_76_0
    ./bootstrap.sh && ./b2 && ./b2 install
    cd ../../
}

function install_google_test (){
    git clone https://github.com/google/googletest.git google_test && cd google_test
    mkdir tmp
    cd tmp
    cmake .. && make && make install
}

install_yaml_cpp
install_boost
install_google_test







