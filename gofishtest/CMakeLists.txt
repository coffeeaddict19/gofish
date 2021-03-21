# add the executable
add_executable(gofishtest main.c)

set_property(TARGET gofishtest PROPERTY C_STANDARD 11)

target_link_libraries(gofishtest PRIVATE gofishlib)
