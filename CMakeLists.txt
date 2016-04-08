cmake_minimum_required (VERSION 2.8)
set(CMAKE_C_COMPILER "${CC}")
set(CMAKE_CXX_COMPILER "${CXX}")
set(CMAKE_Fortran_COMPILER "${FC}")
enable_language(C)
enable_language(CXX)
enable_language(Fortran)
message(STATUS "C       compiler is ${CMAKE_C_COMPILER} (${CMAKE_C_COMPILER_ID})")
message(STATUS "C++     compiler is ${CMAKE_CXX_COMPILER} (${CMAKE_CXX_COMPILER_ID})")
message(STATUS "Fortran compiler is ${CMAKE_Fortran_COMPILER}")

project (cppAndFortran)

add_executable (cppAndFortran cppAndFortran.cpp cppAndFortran.f90)
