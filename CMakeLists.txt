cmake_minimum_required(VERSION 2.8.3)
project(earcut_hpp_test)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED
  roscpp)

#find_package(Boost REQUIRED COMPONENTS system)

catkin_package(
  #INCLUDE_DIRS include
  #LIBRARIES earcut_hpp_test
  #CATKIN_DEPENDS
)

include_directories(
  #include
  earcut/include/mapbox/
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/earcut_hpp_test.cpp
# )

add_executable(earcut_sample src/earcut.cpp)
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}

# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )
