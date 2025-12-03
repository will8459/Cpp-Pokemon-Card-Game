cmake_minimum_required(VERSION 4.0)
project(tp1)

set(CMAKE_CXX_STANDARD 17)

add_executable(tp1 main.cpp
        Card.cpp
        Card.h
        PokemonCard.cpp
        PokemonCard.h
        EnergyCard.cpp
        EnergyCard.h
        TrainerCard.cpp
        TrainerCard.h
        Player.cpp
        Player.h)
