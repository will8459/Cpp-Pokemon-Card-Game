cmake_minimum_required(VERSION 4.0)
project(tp1_Pokemon_Card)

set(CMAKE_CXX_STANDARD 17)

add_executable(tp1_Pokemon_Card main.cpp
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
