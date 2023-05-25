cmake_minimum_required(VERSION 3.24)
project(Game_RPG_CoverOfTheNight)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

file(GLOB_RECURSE SOURCES sources/*.cpp)
file(GLOB_RECURSE HEADERS includes/*.h)

add_executable(Game_RPG_CoverOfTheNight ${SOURCES} ${HEADERS} resources.qrc)

include_directories(Game_RPG_CoverOfTheNight includes includes/Objects resources)

target_link_libraries(Game_RPG_CoverOfTheNight
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
