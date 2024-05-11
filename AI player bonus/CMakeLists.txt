cmake_minimum_required(VERSION 3.25)
project(AI_player_bonus)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AI_player_bonus
        main.cpp
        XO_Board.cpp
        XO_Classes.h
        XO_ComputerPlayer.cpp
        XO_GameManager.cpp
        XO_Player.cpp)
