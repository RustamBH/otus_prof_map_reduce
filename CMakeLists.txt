cmake_minimum_required(VERSION 3.5)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

#--------------------------------------------------------------------------------------------------
# variables
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(PROJECT_NAME MapReduce)
set(TEST_NAME UnitTest)

#--------------------------------------------------------------------------------------------------
# project
project(${LIB_NAME} VERSION ${PROJECT_VESRION})

#--------------------------------------------------------------------------------------------------
# builds
add_executable(${PROJECT_NAME}
	${SRC_DIR}/mapper.cpp
)

add_executable(${TEST_NAME} 
	${TEST_DIR}/tests.cpp
)

# properties
set_target_properties(${LIB_NAME} ${BIN_NAME}
	PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)

#--------------------------------------------------------------------------------------------------
# gtest
#
find_package(GTest REQUIRED)

# add src to the include directories for the test target
target_include_directories(${TEST_NAME} 
	PRIVATE
	${SRC_DIR}
	${GTEST_INCLUDE_DIRS}
	${GTEST_LIBRARY} 
	${GTEST_INCLUDE_DIR}
	${GTEST_MAIN_LIBRARY}
)

# link test target against gtest libraries
target_link_libraries(${TEST_NAME} 
	PRIVATE
	GTest::gtest 
	GTest::gtest_main 
	#GTest::gmock 
	#GTest::gmock_main
)


#--------------------------------------------------------------------------------------------------
# deb pkg
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")	
	
set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

#--------------------------------------------------------------------------------------------------
# testing
enable_testing()
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
