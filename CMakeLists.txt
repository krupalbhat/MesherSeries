cmake_minimum_required(VERSION 3.27)


# Now simply link against gtest or gtest_main as needed. Eg
project(Square CXX)
set(CMAKE_CXX_STANDARD 20)


# add_subdirectory(third_party/faker-cxx)
#itadd_subdirectory(third_party/faker-cxx/deps/googletest)

add_executable(Square main.cpp)

# target_include_directories(example PUBLIC "./third_party/faker-cxx/include")

# target_link_libraries(example faker-cxx)
