cmake_minimum_required(VERSION 2.8.3)
project(step_voice)

find_package(catkin REQUIRED COMPONENTS
roscpp
rospy
std_msgs
roslib
step_voice_libs
)

link_directories(/usr/local/lib)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES pionier
  CATKIN_DEPENDS step_voice_libs
#  DEPENDS system_lib
)

include_directories(include ${catkin_INCLUDE_DIRS} ${step_voice_libs_INCLUDE_DIRS})

## Declare a cpp library
add_library(step_voice src/voice.cpp
)
 target_link_libraries(step_voice
  ${catkin_LIBRARIES}
)


## Declare a cpp executable
add_executable(step_voice_node src/voice_node.cpp)


## Specify libraries to link a library or executable target against
 target_link_libraries(step_voice_node
  ${catkin_LIBRARIES} step_voice
 )
