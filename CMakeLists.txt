cmake_minimum_required(VERSION 3.21)
project(TestLocationLocalforCpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(TestLocationLocalforCpp
        main.cpp
        Chapter2.cpp Chapter2.h
        Chapter2_My_Solutions.cpp Chapter2_My_Solutions.h
        Chapter3Listings.cpp Chapter3Listings.h
        Chapter3Exercises.cpp Chapter3Exercises.h
        Chapter4Listings.cpp Chapter4Listings.h
        Chapter4Exercises.cpp Chapter4Exercises.h)
