cmake_minimum_required(VERSION 4.2)
project(c_plus_plus)

set(CMAKE_CXX_STANDARD 14)

include_directories(Entities)

add_executable(c_plus_plus
        Entities/VehicleRecord.h
        st_c_r.cpp
        Entities/Owner.h
        Services/CarDatabase.h)
