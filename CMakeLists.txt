cmake_minimum_required(VERSION 3.24)

# Project

project(
		vstr

		VERSION 0.0.2
		LANGUAGES C
		HOMEPAGE_URL "https://cally72jhb.github.io/"
		DESCRIPTION "vstr - simple dynamic strings for c"
)

# Properties

set(CPACK_PACKAGE_NAME "vstr")
set(CPACK_PACKAGE_VENDOR "cally72jhb")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "vstr - simple dynamic strings for c")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "vstr")

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Executable

add_executable(
        vstr

		src/main.c
		src/vstr.h
)
