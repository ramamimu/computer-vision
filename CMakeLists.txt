cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++14)

project(belajar)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

# add_executable(belajar src/main.cpp)
# add_executable(belajar src/master.cpp)
# add_executable(belajar src/program.cpp)
# add_executable(belajar src/polygon.cpp)
# add_executable(belajar src/image.cpp)
# add_executable(belajar src/trackbar3.cpp)
# add_executable(belajar src/trackbar2.cpp)
add_executable(belajar src/trackbar5.cpp)
# add_executable(belajar src/trackbar4.cpp)
# add_executable(belajar src/trackbar.cpp)
# add_executable(belajar src/core/mat.cpp)

target_link_libraries( belajar ${OpenCV_LIBS} )