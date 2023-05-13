cmake_minimum_required(VERSION 3.24)
project(Game_RPG_CoverOfTheNight)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_64/lib/cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Game_RPG_CoverOfTheNight GameObject.cpp GameObject.h MovableObject.cpp MovableObject.h Creature.h Creature.cpp main.cpp model.cpp model.h GameWindow.cpp GameWindow.h Hero.h Hero.cpp)
target_link_libraries(Game_RPG_CoverOfTheNight
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
