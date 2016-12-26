PROJECT(OrigamiSystem)
cmake_minimum_required(VERSION 3.0)

## 実行ファイルの出力ディレクトリの設定
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

## ライブラリファイルの出力ディレクトリの設定
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
link_directories(${CMAKE_SOURCE_DIR}/lib)


## GLFW
include_directories(${CMAKE_SOURCE_DIR}/vendor/glfw/include)
add_subdirectory(vendor/glfw)


## imgui
SET(IMGUI_DIRECTORY ${CMAKE_SOURCE_DIR}/vendor/imgui)
include_directories(${IMGUI_DIRECTORY})
include_directories(${IMGUI_DIRECTORY}/examples/opengl_example)
SET(IMGUI_SOURCES
	${IMGUI_DIRECTORY}/imgui.cpp
	${IMGUI_DIRECTORY}/imgui_draw.cpp
	${IMGUI_DIRECTORY}/examples/opengl_example/imgui_impl_glfw.cpp
)


## プロジェクトに含むソースコードのトラッキング
SET(Include_Folder ${CMAKE_SOURCE_DIR}/include/origami_system/)
SET(Src_Folder ${CMAKE_SOURCE_DIR}/src/)


FILE(GLOB_RECURSE origami_sources
	${Include_Folder}/sheet.hpp
	${Src_Folder}/sheet.cpp
)

FILE(GLOB_RECURSE gui_files
	${Include_Folder}gui/*.hpp
	${Src_Folder}gui/*.cpp
)

FILE(GLOB_RECURSE geometry_files
	${Include_Folder}/geometry/*.hpp
	${Src_Folder}/geometry/*.cpp
)


## IDEの表示における階層の設定
SOURCE_GROUP(gui\\ FILES src/main.cpp ${IMGUI_SOURCES} ${gui_files})
SOURCE_GROUP(simulation FILES ${origami_sources})
SOURCE_GROUP(geometry FILES ${geometry_files})

# インクルードフォルダを相対パスの検索対象に設定する
IF(WIN32)
add_definitions("/I${CMAKE_SOURCE_DIR}/include")
ELSE()
add_definitions("-I ${CMAKE_SOURCE_DIR}/include")
ENDIF()

# ここからC++11を有効にする
add_definitions("-Wall -std=c++11")

add_executable(origami src/main.cpp
	${origami_sources}
	${gui_files}
	${geometry_files}
	${IMGUI_SOURCES}
)

## Macでコンパイルするのに必要なOpenGLのFramework
IF (APPLE)
find_library(COCOA_FRAMEWORK Cocoa)
find_library(IOKIT_FRAMEWORK IOKit)
find_library(CORE_FOUNDATION_FRAMEWORK CoreFoundation)
find_library(CORE_VIDEO_FRAMEWORK CoreVideo)
find_library(OPENGL_FRAMEWORK OpenGL)
ENDIF()

target_link_libraries(origami
	glfw3
	${COCOA_FRAMEWORK}
	${IOKIT_FRAMEWORK}
	${CORE_FOUNDATION_FRAMEWORK}
	${CORE_VIDEO_FRAMEWORK}
	${OPENGL_FRAMEWORK}
)