enable_testing ()

include (CTest)

add_executable(gofishtest memorytests.c playtests.c main.c)

set_property(TARGET gofishtest PROPERTY C_STANDARD 11)

target_link_libraries(gofishtest PRIVATE gofishlib)

target_include_directories(
  gofishtest PRIVATE
  ${PROJECT_SOURCE_DIR}/gofishlib/header
)

add_test(NAME gofishtest COMMAND gofishtest)
