cmake_minimum_required(VERSION 3.3)
project(TextEditor)
set(SOURCE_FILES main.cpp Terminal/RawMode.cpp Terminal/RawMode.h)

add_executable(TextEditor ${SOURCE_FILES})	
