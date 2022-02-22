cmake_minimum_required(VERSION 3.21)
project(TestLocationLocalforCpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(TestLocationLocalforCpp
        main.cpp
        Listings/Chapter2Listings.cpp Listings/Chapter2Listings.h
        Exercises/Chapter2Exercises.cpp Exercises/Chapter2Exercises.h
        Listings/Chapter3Listings.cpp Listings/Chapter3Listings.h
        Exercises/Chapter3Exercises.cpp Exercises/Chapter3Exercises.h
        Listings/Chapter4Listings.cpp Listings/Chapter4Listings.h
        Exercises/Chapter4Exercises.cpp Exercises/Chapter4Exercises.h
        Listings/Chapter5Listings.cpp Listings/Chapter5Listings.h
        Exercises/Chapter5Exercises.cpp Exercises/Chapter5Exercises.h
        Listings/Chapter6Listings.cpp Listings/Chapter6Listings.h)
