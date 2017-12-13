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
        CONSTANTS.h Structs.h Music/Music.cpp Music/Music.h Music/Music.cpp Music/Music.h)

add_executable(CourseWork ${SOURCE_FILES})

set(SFML_DIR "/home/konstantin/Documents/projects/univer/pl/CoursePaperBejeweled/SFML-2.4.2/share/SFML/cmake/Modules")
set(CMAKE_MODULE_PATH "/home/konstantin/Documents/projects/univer/pl/CoursePaperBejeweled/SFML-2.4.2/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}  ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
