set(TEST_TARGET "tests")

if(NOT TARGET Catch)
	include(ExternalProject)
	set(FETCH_EXTERNAL_CATCH
		GIT_REPOSITORY https://github.com/philsquared/Catch)
	ExternalProject_Add(Catch-External
		PREFIX ${CMAKE_BINARY_DIR}/external/Catch
		${FETCH_EXTERNAL_CATCH}
		CONFIGURE_COMMAND ""
		BUILD_COMMAND ""
		INSTALL_COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/external/Catch/src/Catch-External/single_include/catch.hpp
											      ${CMAKE_BINARY_DIR}/external/Catch/include/catch.hpp
		)
		add_library(Catch INTERFACE)
		add_dependencies(Catch Catch-External)
		target_include_directories(Catch INTERFACE ${CMAKE_BINARY_DIR}/external/Catch/include)
endif()

file(GLOB_RECURSE TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
add_executable(${TEST_TARGET} ${TEST_SRCS})
target_include_directories(${TEST_TARGET} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${TEST_TARGET} ${PROJECT_NAME} Catch)
add_test (NAME TranslatorTests COMMAND ${TEST_TARGET})