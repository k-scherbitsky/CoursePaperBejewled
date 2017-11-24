cmake_minimum_required(VERSION 3.8)
project(CourseWork)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp BasicFunc/basicFigures.cpp BasicFunc/basicFigures.h)
add_executable(CourseWork ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}  ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})