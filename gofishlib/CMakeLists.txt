add_library (gofishlib SHARED
ExternalSymbols.cpp
Game.cpp
ConsoleLogger.cpp
Card.cpp
Player.cpp
Deck.cpp
Books.cpp
CardPool.cpp
)

set_property(TARGET gofishlib PROPERTY CXX_STANDARD 11)
