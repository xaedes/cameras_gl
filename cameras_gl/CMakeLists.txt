cmake_minimum_required(VERSION 3.8)

set(PROJECT_NAME cameras_gl)
project( ${PROJECT_NAME} )

include("compiler_options.cmake")

add_library(
    ${PROJECT_NAME} 
    STATIC 
    # src/camera.cpp
    src/camera_projection_interface.cpp
    src/camera_view_interface.cpp
    src/first_person_view.cpp
    src/look_at_view.cpp
    src/orbital_view.cpp
    src/orthogonal_projection.cpp
    src/perspective_projection.cpp    
    src/symmetric_orthogonal_projection.cpp    
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

find_package(glm REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC glm::glm)

