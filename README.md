<!-- **Editor which will make your life easier**
---

![](https://img.shields.io/github/commit-activity/m/YarikRevich/SyE)
![](https://img.shields.io/badge/Maintained%3F-yes-green.svg)
![](https://img.shields.io/github/license/Naereen/StrapDown.js.svg)

It's features are:

- It almost has nothing except of opportunity to write
- It has all the important things as syntax highlight and regexp selecting

**Instalation tutorial**

Go into the cloned repo
```
mkdir build

cd build
```

Then you have to gen Makefile by CMake

```
cmake ..
```

So, it's time to build 

```
cmake --build . #or make
```

To make it executable all around, install it

```
cmake --install .
```

Enjoy!👌 -->



# SyE

[![Build](https://github.com/YarikRevich/SyE/actions/workflows/build.yml/badge.svg)](https://github.com/YarikRevich/ResourceTracker/actions/workflows/build.yml)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![MacOS](https://img.shields.io/badge/MacOS-8773f5?style=for-the-badge&logo=macos&logoColor=black)
[![StandWithUkraine](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/badges/StandWithUkraine.svg)](https://github.com/vshymanskyy/StandWithUkraine/blob/main/docs/README.md)


## General Information

Media codec with the possibility of result representation.

![](./docs/detailed-design.png)

## Setup

### Prerequisites

In the case of the usage with MacOS operational systems it's important to remember to allow the usage of SDL2 library on your local machine using privacy settings. 

### Installation
All setup related operations are processed via **Makefile**(which operates **CMake** configurations) placed in the root directory.

In order to build the application into project local **bin** library it's required to execute the following command.
```shell
make build
```