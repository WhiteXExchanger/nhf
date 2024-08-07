// animation.h
#pragma once
#include <chrono>
#include <string>

void clearScreen() {
    // For Windows
    #ifdef _WIN32
    system("CLS");
    #else
    // For macOS and Linux
    system("clear");
    #endif
}

std::string empty = {
    R"(
==================================#==========#
                # s #             |          |
                # c #             |          |
                # a #             |          |
                # n #             |          |
==================================#==========#
        |   piros   | |           |
        |   zold    | |           |
        +-----------+ |           |
                      \           /
                       \         /
                       /|||||||||\
                       |||||||||||
                       |||||||||||
                       |||||||||||
                       |||||||||||
                        \|||||||/
)"
};

std::string goodFrames[] = {
    R"(
=============================================
                # s #             |         |
    +-----+     # c #             |         |
    +-----+     # a #             |         |
                # n #             |         |
=============================================
        |   piros   | |           |
        ||||zold||||| |           |
        +-----------+ |           |
                      \           /
                       \         /
                       /|||||||||\
                       |||||||||||
                       |||||||||||
                       |||||||||||
                       |||||||||||
                        \|||||||/
)",
    R"(
=============================================
                # s #             |         |
                # c #   +-----+   |         |
                # a #   +-----+   |         |
                # n #             |         |
=============================================
        |   piros   | |           |
        ||||zold||||| |           |
        +-----------+ |           |
                      \           /
                       \         /
                       /|||||||||\
                       |||||||||||
                       |||||||||||
                       |||||||||||
                       |||||||||||
                        \|||||||/
)",
    R"(
=============================================
                # s #             |         |
                # c #             | +-----+ |
                # a #             | +-----+ |
                # n #             |         |
=============================================
        |   piros   | |           |
        ||||zold||||| |           |
        +-----------+ |           |
                      \           /
                       \         /
                       /|||||||||\
                       |||||||||||
                       |||||||||||
                       |||||||||||
                       |||||||||||
                        \|||||||/
)"
};

std::string badFrames[] = { 
    R"(
=============================================
                # s #             |         |
    +-----+     # c #             |         |
    +-----+     # a #             |         |
                # n #             |         |
=============================================
        ||||piros|||| |           |
        |   zold    | |           |
        +-----------+ |           |
                      \           /
                       \         /
                       /|||||||||\
                       |||||||||||
                       |||||||||||
                       |||||||||||
                       |||||||||||
                        \|||||||/
)",
    R"(
=============================================
                # s #             |         |
                # c #   +-----+   |         |
                # a #   +-----+   |         |
                # n #             |         |
=============================================
        ||||piros|||| |           |
        |   zold    | |           |
        +-----------+ |           |
                      \           /
                       \         /
                       /|||||||||\
                       |||||||||||
                       |||||||||||
                       |||||||||||
                       |||||||||||
                        \|||||||/
)",
    R"(
=============================================
                # s #             |         |
                # c #             |         |
                # a #             |         |
                # n #             |         |
=============================================
        ||||piros|||| |           |
        |   zold    | |  +-----+  |
        +-----------+ |  +-----+  |
                      \           /
                       \         /
                       /|||||||||\
                       |||||||||||
                       |||||||||||
                       |||||||||||
                       |||||||||||
                        \|||||||/
)"
};