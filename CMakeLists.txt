cmake_minimum_required(VERSION 3.30)

project(pomo++ VERSION 0.1.0 LANGUAGES CXX)
set(PROJECT_DESCRIPTION "A TUI pomodoro timer written in C++.")
set(PROJECT_LICENSE "MIT License")
set(PROJECT_HOMEPAGE_URL "https://github.com/hammadmajid/pomo++")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_executable(pomo++ src/main.cpp)
