cmake_minimum_required(VERSION 3.8)
project(CourseWork)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp
        BasicFunc/BasicFunc.cpp
        BasicFunc/BasicFunc.h
        Figures/Figures.cpp
        Figures/Figures.h
        Menu/Menu.cpp
        Menu/Menu.h
        Score/Score.cpp
        Score/Score.h
        CONSTANTS.h
        Structs.h
        Music/Music.cpp
        Music/Music.h
        Music/Music.cpp
        Music/Music.h)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(CourseWork ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(CourseWork ${SFML_LIBRARIES})
endif ()

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
