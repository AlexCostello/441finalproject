cmake_minimum_required(VERSION 2.8.12.1)

PROJECT(finalproject)
SET(VTK_DIR /path/to/VTK6.3.0)
SET(CMAKE_BUILD_TYPE Debug)


find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

add_executable(finalproject finalproject)

if(VTK_LIBRARIES)
    target_link_libraries(finalproject ${VTK_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
else()
    target_link_libraries(finalproject vtkHybrid)
endif()

