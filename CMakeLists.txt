cmake_minimum_required(VERSION 3.9)
project(TUM)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(TUM ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(TUM pthread)
TARGET_LINK_LIBRARIES(TUM stdc++fs)
TARGET_LINK_LIBRARIES(TUM sfml-system)
TARGET_LINK_LIBRARIES(TUM sfml-audio)
TARGET_LINK_LIBRARIES(TUM sfml-graphics)
TARGET_LINK_LIBRARIES(TUM sfml-window)
TARGET_LINK_LIBRARIES(TUM sfml-network)
TARGET_LINK_LIBRARIES(TUM Box2D)
TARGET_LINK_LIBRARIES(TUM m)
TARGET_LINK_LIBRARIES(TUM tgui)


install(DIRECTORY art
        USE_SOURCE_PERMISSIONS
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        )

install(DIRECTORY json
        USE_SOURCE_PERMISSIONS
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        )

install(TARGETS TUM
        DESTINATION ${CMAKE_INSTALL_PREFIX}
        )
