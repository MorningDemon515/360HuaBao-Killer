cmake_minimum_required(VERSION 3.16)

project(360HuaBao-Killer)

add_compile_options(
                     -fexec-charset=GBK
                      -finput-charset=UTF-8
)

add_executable(360HuaBao-Killer 
                          source/Main.cpp
                          resources/resources.rc
)


