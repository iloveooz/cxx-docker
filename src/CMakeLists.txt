cmake_minimum_required(VERSION 3.2)
project(cxx_docker)

# будем использовать c++17
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# будем использовать Boost.program_options в качестве статической библиотеки
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${BOOST_INCLUDE_DIR})

# исполняемый файл
add_executable(cxx_docker main.cpp main_world.hxx)
target_link_libraries(cxx_docker ${Boost_LIBRARIES})

# включаем CTest
enable_testing()

# в качестве фреймворка для тестирования используем GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# исполняемый файл тестов
add_executable(cxx_docker_test test.cxx main_world.hxx)
target_link_libraries(cxx_docker_test ${GTEST_LIBRARIES} pthread)

# добавим этот файл в тестовый набор CTest
add_test(NAME CxxDockerTest COMMAND cxx_docker_test)