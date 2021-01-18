cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

project(discpp-bot-boilerplate)

include(cmake/log.cmake)

if(WIN32)
	add_compile_definitions(_WIN32)

	if(MSVC)
		add_compile_options(/std:c++latest)
		log_debug("Using MSVC toolchain.")
	else()
		log_fatal("Unsupported toolchain.")
	endif()

elseif(UNIX)
	add_compile_definitions(_LINUX)
	add_compile_options(-std=c++2a)

	log_debug("Using GCC or Clang toolchain.")
endif()

# add vendored dependencies
add_subdirectory(vendor/discpp)

# add source code
add_subdirectory(source/)