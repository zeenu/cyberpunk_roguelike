file(GLOB_RECURSE srcs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp *.h)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CURSES_INCLUDE_DIR}
)

add_executable(Roguelike
  ${srcs}
)

target_link_libraries(Roguelike
  ${CURSES_LIBRARIES}
)
