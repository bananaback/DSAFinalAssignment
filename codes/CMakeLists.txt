list(APPEND COMMON_SOURCES 
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/animation.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/astar.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/astarboi.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/bullet.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/button.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/calculator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/coin.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/collectableitem.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/credit.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/effect.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/enemy.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/explosioneffect1.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/explosioneffect2.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/game.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/gameobject.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/gameover.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/gameplay.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/gamestate.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/mainmenu.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/map.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/player.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/resourceallocator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/setting.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/utility.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/wall.cpp
    )

add_library(CoreGame ${COMMON_SOURCES})

target_include_directories(CoreGame
    PUBLIC "${SFML_SOURCE_DIR}/include"
    PUBLIC "${PROJECT_SOURCE_DIR}"
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/sources
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/headers
    
)


