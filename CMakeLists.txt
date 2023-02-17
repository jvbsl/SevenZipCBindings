cmake_minimum_required(VERSION 3.1)

project(SevenZipCBinding VERSION 1.0 LANGUAGES CXX)


add_library(7z SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(7z PROPERTIES
  IMPORTED_LOCATION "/usr/lib/7z.so"
)
add_compile_options( -fno-omit-frame-pointer -Wall  -DUNICODE  -DABI_LINUX -D_REENTRANT -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE )
add_link_options( -fno-omit-frame-pointer  -DUNICODE -D_UNICODE -DABI_LINUX -D_REENTRANT -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE )

add_library(SevenZipCBinding SHARED src/binding.cpp src/binding.h src/wrappers.cpp src/wrappers.h)

target_include_directories(SevenZipCBinding PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/base/CPP)

target_link_libraries(SevenZipCBinding 7z)