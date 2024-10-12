cmake_minimum_required(VERSION 3.24)
project(3_sem)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_int_0 test_int_queue_0.cpp int_queue.cpp int_queue.h)
add_executable(test_int test_int_queue.cpp int_queue.cpp int_queue.h)
add_executable(test_template test_queue_0.cpp queue.hpp queue.h)
add_executable(test_tmp tmp.cpp)