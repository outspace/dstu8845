cmake_minimum_required(VERSION 2.6)
project(strumok)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3")

if (DIRTY)
  set(CMAKE_C_FLAGS_RELEASE "-O3 -std=c11 -mavx2 -mavx -msse -msse2 -msse3 -mfpmath=sse")
endif()	

set(STRUMOK ./strumok.c)

add_library(strumok SHARED ${STRUMOK})

add_executable(main ./main.c)
target_link_libraries(main strumok)
