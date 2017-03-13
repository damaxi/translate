file(GLOB_RECURSE LIB_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

add_library(${PROJECT_NAME}-static STATIC ${LIB_SRCS})
add_library(${PROJECT_NAME} SHARED ${LIB_SRCS})
include_directories(
	${PROJECT_SOURCE_DIR}/include
)
#add_executable(${PROJECT_NAME} ${LIB_SRCS})

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME}-static Qt5::Core)

set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
