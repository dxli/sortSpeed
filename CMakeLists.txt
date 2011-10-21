cmake_minimum_required(VERSION 2.6)
project(benchmarking)

#There are lots of scripts with cmake
#for finding external libraries.
#see /usr/local/share/cmake-2.6/Modules/Find*.cmake for more examples
#find_package(GLUT)
#find_package(OpenGL)
set(CMAKE_MODULE_PATH ".")
#find_package(Grace)
#set(CORELIBS ${GRACE_LIBRARY})
find_package(Boost)
set(CORELIBS ${BOOST_LIBRARY})
add_library(randomInit randomInit.cpp)
add_library(rs_vector rs_vector.cpp)
#add_library(flashgeom flashgeom.cpp)
#add_library(abc abc.cpp)
set(CORELIBS ${CORELIBS} randomInit rs_vector )


set(CMAKE_CXX_FLAGS "-O2 -march=native -fomit-frame-pointer -Wall")
set(PROGRAMS speedMatrix)
foreach(program ${PROGRAMS})
  add_executable(${program} ${program}.cpp)
  target_link_libraries(${program} ${CORELIBS} )
endforeach(program)

