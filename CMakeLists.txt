cmake_minimum_required(VERSION 3.21)
project(TestLocationLocalforCpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(TestLocationLocalforCpp
        main.cpp
        Chapter2Listings.cpp Chapter2Listings.h
        Chapter2Exercises.cpp Chapter2Exercises.h
        Chapter3Listings.cpp Chapter3Listings.h
        Chapter3Exercises.cpp Chapter3Exercises.h
        Chapter4Listings.cpp Chapter4Listings.h
        Chapter4Exercises.cpp Chapter4Exercises.h
        Chapter5Listings.cpp Chapter5Listings.h Chapter5Exercises.cpp Chapter5Exercises.h)
