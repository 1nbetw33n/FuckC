cmake_minimum_required(VERSION 3.21)
project(ProgC C)

set(CMAKE_C_STANDARD 23)

add_executable(ProgC Old_Exercises/exercise1.c Old_Exercises/exercise1.c test.c Old_Exercises/exercise2.c Old_Exercises/exercise1.h Old_Exercises/mathemat.c Old_Exercises/mathemat.h FoolingAroundWithSums.c Old_Exercises/Exercise3.c Old_Exercises/Exercise3.h QUIZZES/Quiz2.c Old_Exercises/Exercise4.c Old_Exercises/ArrayList.h Old_Exercises/ArrayList.c UTILITY/List.c UTILITY/List.h QUIZZES/MIDTERM.c Exercises/main.c Exercises/1/ex1.c Exercises/1/ex1.h Exercises/1/ex2.c Exercises/1/ex2.h)

target_link_libraries(ProgC m)



