cmake_minimum_required(VERSION 3.1)

project(SevenZipCBinding VERSION 1.0 LANGUAGES CXX)


add_library(7z SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(7z PROPERTIES
    IMPORTED_IMPLIB "C:/Users/susch/source/repos/SevenZipCBindings/base/CPP/7zip/Bundles/Format7zF/x64/7z.lib"
  IMPORTED_LOCATION "C:/Users/susch/source/repos/SevenZipCBindings/base/CPP/7zip/Bundles/Format7zF/x64/7z.dll"
)

if (MSVC)
    add_compile_options(-D_UNICODE -Gr -nologo -c -Fox64/ -W4 -WX -EHsc -Gy -GF -GR- -GS- -Zc:forScope -Zc:wchar_t -MP4 -D_LZMA_DEC_OPT )
    add_link_options(-OPT:REF -OPT:ICF /LARGEADDRESSAWARE -DLL)
else()
    add_compile_options( -fno-omit-frame-pointer)
    add_link_options( -fno-omit-frame-pointer)
endif()
add_compile_options( -DUNICODE  -D_REENTRANT -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE )
add_link_options(-DUNICODE -D_UNICODE -D_REENTRANT -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE )


add_library(SevenZipCBinding SHARED src/binding.cpp src/binding.h src/wrappers.cpp src/wrappers.h  src/hardcoded_guids.cpp)

target_include_directories(SevenZipCBinding PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/base/CPP)

target_link_libraries(SevenZipCBinding 7z)