cmake_minimum_required (VERSION 3.8)

project ("beautiful_number")

add_executable (beautiful_number "beautiful_number.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET beautiful_number PROPERTY CXX_STANDARD 20)
endif()

