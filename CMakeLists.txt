cmake_minimum_required(VERSION 3.23)
project(work C)

set(CMAKE_C_STANDARD 99)

add_executable(work main.c)

add_executable(test test/test.c)
add_executable(prac01 chap07-Tree/prac01.c)
add_executable(prac-01 chap02-Structure-and-Recursion/prac-01.c chap05-Stack/prac01.c chap05-Stack/prac02.c)
add_executable(prac-02 chap01-Array-and-Pointer/prac-02.c)
add_executable(prac-03 chap01-Array-and-Pointer/prac-03.c)
add_executable(prac-04 chap01-Array-and-Pointer/prac-04.c)
add_executable(prac-05 chap01-Array-and-Pointer/prac-05.c)
add_executable(prac-06 chap01-Array-and-Pointer/prac-06.c)
add_executable(prac-07 chap01-Array-and-Pointer/prac-07.c)
add_executable(prac-08 chap01-Array-and-Pointer/prac-08.c)

add_executable(prac02 chap07-Tree/prac02.c)
add_executable(prac03 chap06-Queue-and-Deque/prac03.c)

add_executable(prac04 chap06-Queue-and-Deque/prac04.c)
add_executable(prac05 chap06-Queue-and-Deque/prac05.c)
add_executable(asg assignment/02/asg.c)
