cmake_minimum_required(VERSION 4.0)
project(tp_Zoo)

set(CMAKE_CXX_STANDARD 20)

add_executable(tp_Zoo main.cpp
        Animal.cpp
        Animal.h
        Mammal.cpp
        Mammal.h
        Bird.cpp
        Bird.h
        Reptile.cpp
        Reptile.h
        Zoo.cpp
        Zoo.h
        KNN.h
        KNNDouble.cpp
        KNNDouble.h
        KNNString.cpp
        KNNString.h)
