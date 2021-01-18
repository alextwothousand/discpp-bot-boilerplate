project(src)

add_executable(src main.cpp main.hpp env.cpp env.hpp)

target_include_directories(src PUBLIC ${discpp_SOURCE_DIR}/include)
target_link_libraries(src PUBLIC discpp)