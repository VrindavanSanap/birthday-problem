cmake_minimum_required(VERSION 3.10)

project(BirthdayProblem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(birthday_problem_analytical birthday_problem_analytical.cc)

add_executable(birthday_problem_numerical birthday_problem_numerical.cc)
