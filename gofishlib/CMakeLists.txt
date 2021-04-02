add_library (gofishlib SHARED
source/ExternalSymbols.cpp
source/Game.cpp
source/Card.cpp
source/Player.cpp
source/Deck.cpp
source/Books.cpp
source/CardPool.cpp
)

set_property(TARGET gofishlib PROPERTY CXX_STANDARD 11)

target_include_directories(
  gofishlib PRIVATE
  ${PROJECT_SOURCE_DIR}/gofishlib/header
)

set_target_properties(gofishlib PROPERTIES CXX_VISIBILITY_PRESET hidden)
