cmake_minimum_required(VERSION 3.21)
project(ProgC C)

set(CMAKE_C_STANDARD 23)

add_executable(ProgC Exercises/exercise1.c Exercises/exercise1.c test.c Exercises/exercise2.c Exercises/exercise1.h Exercises/mathemat.c Exercises/mathemat.h FoolingAroundWithSums.c Exercises/Exercise3.c Exercises/Exercise3.h QUIZZES/Quiz2.c Exercises/Exercise4.c Exercises/ArrayList.h Exercises/ArrayList.c UTILITY/List.c UTILITY/List.h QUIZZES/MIDTERM.c)

target_link_libraries(ProgC m)



