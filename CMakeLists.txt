cmake_minimum_required(VERSION 2.6)
project(NeuronNet)
set(CMAKE_CXX_FLAGS "-W -Wall -Wextra -std=c++11")

if(NOT CMAKE_BUILD_TYPE)
 set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "" FORCE)
endif(NOT CMAKE_BUILD_TYPE)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -W -Wall -Wextra")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
option(test "Build tests." ON)
include_directories("/usr/local/include" ${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)
add_executable(NeuronNet src/main.cpp src/random.cpp src/neuron.cpp src/simulation.cpp src/network.cpp)

if (test)
 enable_testing()
 find_package(GTest)
 if (NOT GTEST_FOUND)
 	SET(GTEST_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include)
 	SET(GTEST_BOTH_LIBRARIES libgtest.a libgtest_main.a)
 endif(NOT GTEST_FOUND)
 include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/src)
 add_executable(testNN src/test_main.cpp src/random.cpp src/simulation.cpp src/neuron.cpp src/network.cpp)
 target_link_libraries(testNN ${GTEST_BOTH_LIBRARIES} pthread)
 add_test(NeuronNet testNN)
endif(test)


find_package(Doxygen) 
if (DOXYGEN_FOUND)
add_custom_target(doc 
		${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile 
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)



