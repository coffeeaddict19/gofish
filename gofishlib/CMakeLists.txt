if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(CONANFILE conanfile.txt
BASIC_SETUP CMAKE_TARGETS
BUILD missing
)

add_library (gofishlib SHARED
source/ExternalSymbols.cpp
source/Game.cpp
source/Card.cpp
source/Player.cpp
source/Deck.cpp
source/Books.cpp
source/CardPool.cpp
)

target_link_libraries(gofishlib PRIVATE CONAN_PKG::spdlog)

set_property(TARGET gofishlib PROPERTY CXX_STANDARD 11)

target_include_directories(
  gofishlib PRIVATE
  ${PROJECT_SOURCE_DIR}/gofishlib/header
)

set_target_properties(gofishlib PROPERTIES CXX_VISIBILITY_PRESET hidden)
