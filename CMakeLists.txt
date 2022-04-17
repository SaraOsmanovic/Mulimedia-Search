cmake_minimum_required(VERSION 3.21)
project(Multimedia_Search)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(Multimedia_Search
        src/Book.cpp
        src/Book.h
        src/Books.cpp
        src/Books.h
        src/main.cpp
        src/Movie.cpp
        src/Movie.h
        src/Movies.cpp
        src/Movies.h
        src/Podcast.cpp
        src/Podcast.h
        src/Podcasts.cpp
        src/Podcasts.h)
