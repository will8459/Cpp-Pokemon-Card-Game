cmake_minimum_required(VERSION 4.0)
project(tp2_Series_Temporelles)

set(CMAKE_CXX_STANDARD 17)

add_executable(tp2_Series_Temporelles main.cpp
        TimeSeriesGenerator.cpp
        TimeSeriesGenerator.h
        GaussianGenerator.cpp
        GaussianGenerator.h
        StepGenerator.cpp
        StepGenerator.h
        SinWaveGenerator.cpp
        SinWaveGenerator.h
        TimeSeriesDataset.cpp
        TimeSeriesDataset.h
        Euclidean.cpp
        Euclidean.h
        DTW.cpp
        DTW.h
        KNN.cpp
        KNN.h)
