PROJECT(OrigamiSystem)
cmake_minimum_required(VERSION 3.0)

## 実行ファイルの出力ディレクトリの設定
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

## ライブラリファイルの出力ディレクトリの設定
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
link_directories(${CMAKE_SOURCE_DIR}/lib)

## eigen
include_directories(${CMAKE_SOURCE_DIR}/vendor/eigen/)


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
# includeフォルダとsrcフォルダにあるファイルのみを対象にする
FILE(GLOB_RECURSE ALL_FILES
	RELATIVE ${CMAKE_SOURCE_DIR}
 	include/*.hpp src/*.cpp)

## ディレクトリ構成を保持したままビルドシステムを構築するマクロ
foreach(FILE ${ALL_FILES})
  get_filename_component(PARENT_DIR "${FILE}" PATH)
  # skip src or include and changes /'s to \\'s
  string(REGEX REPLACE "(\\./)?(src|include)/?" "" GROUP "${PARENT_DIR}")
  string(REPLACE "/" "\\" GROUP "${GROUP}")

  # group into "Source Files" and "Header Files"
  if ("${FILE}" MATCHES ".*\\.cpp")
    set(GROUP "Source Files\\${GROUP}")
  elseif("${FILE}" MATCHES ".*\\.h")
    set(GROUP "Header Files\\${GROUP}")
  endif()

  source_group("${GROUP}" FILES "${FILE}")
endforeach()



# インクルードフォルダを相対パスの検索対象に設定する
IF(WIN32)
add_definitions("/I${CMAKE_SOURCE_DIR}/include")
ELSE()
add_definitions("-I ${CMAKE_SOURCE_DIR}/include")
ENDIF()

# ここからC++11を有効にする
add_definitions("-Wall -std=c++11")

add_executable(origami src/main.cpp
	${ALL_FILES}
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