#!/bin/bash 

#Install dependencies 

if [[ $OSTYPE != 'darwin'* ]]; then 
    sudo apt-get update;
    sudo apt-get install git;
    sudo apt-get install cmake;
    sudo apt-get install make;
    sudo apt-get install wget;
fi


echo -e "\033[32mDependencies are installed\033[0m"

cd ../;
mkdir -p vendor;
cd vendor;

#Functions for dependencies install

function install_yaml_cpp (){
    wget https://github.com/jbeder/yaml-cpp/archive/refs/tags/yaml-cpp-0.6.0.tar.gz -P yaml-cpp
    cd yaml-cpp
    tar -xf yaml-cpp-0.6.0.tar.gz
    cd yaml-cpp-yaml-cpp-0.6.0

    mkdir build
    cd build

    sudo cmake .. && sudo make && sudo make install
    cd ../../../
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
    sudo cmake .. && sudo make && sudo make install
}

install_yaml_cpp
# install_boost
# install_google_test

touch .ignore_deps







