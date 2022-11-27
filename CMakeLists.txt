cmake_minimum_required(VERSION 3.10)

set(ProjectName TheShooting)
# set the project name and version
project("${ProjectName}" VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

# set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -pedantic -target x86_64-apple-darwin20.3.0" )


# configure a header file to pass some of the CMake settings
# to the source code
# configure_file(Config.h.in Config.h)
add_subdirectory(codes)
add_subdirectory(assets)

# add the SFML library
list(APPEND EXTRA_LIBS 
            sfml-window
            sfml-graphics
            sfml-audio
            CoreGame
    )
list(APPEND EXTRA_INCLUDES 
    "${PROJECT_SOURCE_DIR}/codes"
    "${PROJECT_SOURCE_DIR}/codes/headers"
    "${PROJECT_SOURCE_DIR}/codes/sources"
    )


# add the executable
add_executable("${ProjectName}" main.cpp)
# target_compile_options (main.cpp.o PRIVATE "-v")

target_link_libraries("${ProjectName}" PUBLIC ${EXTRA_LIBS})

target_include_directories("${ProjectName}" 
    PUBLIC "${PROJECT_SOURCE_DIR}"
    PUBLIC ${EXTRA_INCLUDES}
    )
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories("${ProjectName}" 
                            PUBLIC "${PROJECT_BINARY_DIR}"
                           )
