cmake_minimum_required(VERSION 3.17)

set(CMAKE_GENERATOR_PLATFORM win32)

project(simon)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_MIXER_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${SDL_GAME_ENGINE_INCLUDE_DIR}
)

add_executable(simon
    main.cpp
    colors.h
    colors.cpp
    scenes/game.h
    scenes/game.cpp
    scenes/game/board.h
    scenes/game/board.cpp
    scenes/game/color_button.h
    scenes/game/color_button.cpp
    scenes/game/game_manager.h
    scenes/game/game_manager.cpp
    scenes/game/score_manager.h
    scenes/game/score_manager.cpp
)

source_group(main FILES
    main.cpp
    colors.h
    colors.cpp
)

source_group(scenes FILES
    scenes/game.h
    scenes/game.cpp
)

source_group(scenes/game FILES
    scenes/game/board.h
    scenes/game/board.cpp
    scenes/game/color_button.h
    scenes/game/color_button.cpp
    scenes/game/game_manager.h
    scenes/game/game_manager.cpp
    scenes/game/score_manager.h
    scenes/game/score_manager.cpp
)

file(COPY fonts DESTINATION ${CMAKE_BINARY_DIR}/)
file(COPY sounds DESTINATION ${CMAKE_BINARY_DIR}/)

target_link_libraries(simon ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_MIXER_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${SDL_GAME_ENGINE_LIBRARIES}
)