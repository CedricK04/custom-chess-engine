#include <iostream>
#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"

// Function to decode the board and render it
int CreateGraphicalBoard(Board board) {
    sf::RenderWindow window(sf::VideoMode(1920, 1200), "Chess Board");
    sf::View boardView(sf::FloatRect(0, 0, 800, 800)); // Fixed logical size for the board

    // Limit framerate and enable vertical synchronization
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    // Load textures for pieces
    sf::Texture textures[12];  // 6 piece types x 2 colors
    const std::string pieceNames[] = {
        "white-king.png", "white-pawn.png", "white-knight.png",
        "white-bishop.png", "white-rook.png", "white-queen.png",
        "black-king.png", "black-pawn.png", "black-knight.png",
        "black-bishop.png", "black-rook.png", "black-queen.png"
    };

    for (int i = 0; i < 12; i++) {
        if (!textures[i].loadFromFile("C:/Repositories/custom-chess-engine/images/" + pieceNames[i])) {
            std::cout << "Failed to load: " << pieceNames[i] << std::endl;
            return EXIT_FAILURE;
        }
    }

    // Create sprites for pieces
    sf::Sprite sprites[12];
    for (int i = 0; i < 12; i++) {
        sprites[i].setTexture(textures[i]);
        sprites[i].setScale(1.25f, 1.25f);
    }

    const float squareSize = 100.0f;

    // Function to update the view and maintain aspect ratio
    auto updateView = [&window, &boardView]() {
        float windowWidth = window.getSize().x;
        float windowHeight = window.getSize().y;
        float aspectRatio = windowWidth / windowHeight;

        if (aspectRatio > 1.0f) {
            // Window is wider than it is tall: add bars on the sides
            float viewportWidth = 1.0f / aspectRatio;
            boardView.setViewport(sf::FloatRect((1.0f - viewportWidth) / 2.0f, 0.0f, viewportWidth, 1.0f));
        } else {
            // Window is taller than it is wide: add bars on the top and bottom
            float viewportHeight = aspectRatio;
            boardView.setViewport(sf::FloatRect(0.0f, (1.0f - viewportHeight) / 2.0f, 1.0f, viewportHeight));
        }

        window.setView(boardView);
    };

    updateView();

    bool needsRedraw = true; // Dirty flag to track if the screen needs to be redrawn

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized) {
                updateView();
                needsRedraw = true; // Mark the screen for redrawing
            }

            // Add game-specific events here, e.g., piece movement, etc.
            // If game state changes, set needsRedraw = true;
        }

        if (needsRedraw) {
            window.clear(sf::Color::Black);

            // Draw chessboard grid
            for (int row = 0; row < 8; row++) {
                for (int col = 0; col < 8; col++) {
                    sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
                    square.setPosition(col * squareSize, row * squareSize);

                    if ((row + col) % 2 == 0)
                        square.setFillColor(sf::Color(240, 217, 181)); // Light square
                    else
                        square.setFillColor(sf::Color(181, 136, 99)); // Dark square

                    window.draw(square);
                }
            }

            // Decode board and draw pieces
            for (int i = 0; i < 32; i++) {
                uint8_t byte = board.board[i];

                for (int nibbleIdx = 0; nibbleIdx < 2; nibbleIdx++) {
                    uint8_t nibble = nibbleIdx == 0 ? byte >> 4 : byte & 0b1111;

                    bool isWhite = (nibble & 0b1000) == 0b0000;
                    uint8_t piece = nibble & 0b0111;

                    if (piece != NONE) {
                        int pieceIndex = piece - 1 + (!isWhite ? 6 : 0);

                        int squareIndex = i * 2 + nibbleIdx;
                        int row = squareIndex / 8;
                        int col = squareIndex % 8;

                        sf::Sprite& sprite = sprites[pieceIndex];
                        sprite.setPosition(col * squareSize + (squareSize - sprite.getGlobalBounds().width) / 2,
                                           row * squareSize + (squareSize - sprite.getGlobalBounds().height) / 2);

                        window.draw(sprite);
                    }
                }
            }

            window.display();
            needsRedraw = false; // Clear the dirty flag after redrawing
        }
    }

    return EXIT_SUCCESS;
}