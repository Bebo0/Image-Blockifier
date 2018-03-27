cmake_minimum_required(VERSION 3.9)
project(pa3)

set(CMAKE_CXX_STANDARD 11)

add_executable(pa3
        cs221util/lodepng/lodepng.cpp
        cs221util/lodepng/lodepng.h
        cs221util/PNG.cpp
        cs221util/PNG.h
        cs221util/RGBAPixel.cpp
        cs221util/RGBAPixel.h
        images/given-prunedremb95.png
        images/given-prunedrosa95.png
        images/given-prunedstanleytotem95.png
        images/given-prunedubctotem95.png
        images/remb.png
        images/rosa.png
        images/stanley-totem-poles.png
        images/ubc-totem-poles.png
        lodepng.o
        main.cpp
        main.o
        Makefile
        pa3
        PNG.o
        RGBAPixel.o
        stats.cpp
        stats.h
        stats.o
        twoDtree.cpp
        twoDtree.h
        twoDtree.o)
