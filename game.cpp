#include "game.h"
#include "gameBoard.h"
#include <cmath>
#include "puzzleSolver.h"
#include <fstream>
#include <random> // random_shuffle, std::default_random_engine
#include <chrono> // std::chrono::system_clock
#include <sstream>




using namespace SlidingTiles;
using json = nlohmann::json;

namespace SlidingTiles {

    constexpr float Game::VICTORY_ROLL_TIME;

    Game::Game() {
        // read a JSON file
        const std::string CONFIG_FILENAME = "assets/sliding-tiles.json";
        std::ifstream in(CONFIG_FILENAME);
        if (! in) {
            std::cerr <<  "Could not read configuration file: "
                << CONFIG_FILENAME << std::endl;
        }
        json j;
        in >> j;
        levelsArray = j["levels"];
        loadLevel();

        gameView.setGameBoard(&gameBoard);

        json winnerSoundBitesArray = j["winnerSoundBites"];
        winnerSounds.loadSounds(winnerSoundBitesArray);

        json attitudeSoundBitesArray = j["attitudeSoundBites"];
        attitudeSounds.loadSounds(attitudeSoundBitesArray);

        levelLabel.setPosition(400, 120);
        movesLabel.setPosition(400, 150);
        parLabel.setPosition(400, 180);
        randomSfmlButton.setPosition(400, 230);
        nextSfmlButton.setPosition(400, 270);
        restartSfmlButton.setPosition(400, 310);
    }

    void Game::update(const float & dt) {
        // send update event to all the tiles
        for (int x = 0; x < GameBoard::boardSize; ++x)
            for (int y = 0; y < GameBoard::boardSize; ++y) {
                gameBoard.tiles[x][y].tileView.update(dt);
            }

        if (gameState == GameState::Playing) {
            std::vector<sf::Vector2i> solutionPath = gameBoard.isSolved();
            if (solutionPath.size() > 0) {
                gameBoard.setWinnerTiles(solutionPath);
                gameState = GameState::VictoryRolling;
                victoryRollingTime = VICTORY_ROLL_TIME;
                winnerSounds.playRandomSound();
            } else {
                gameBoard.clearWinnerTiles();
            }
        }
    }

    void Game::onRandomButtonClick() {
        doRandomGame();
    }

    void Game::onNextButtonClick() {
        doLevelUp();
    }

    void Game::onRestartButtonClick() {
        loadLevel();
        attitudeSounds.playRandomSound();
    }

    void Game::run() {
        sf::RenderWindow* window = RenderingSingleton::getInstance().getRenderWindow();

        while (window->isOpen()) {
            sf::Event event;
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window->close();
                else if (event.type == sf::Event::MouseButtonPressed) {
                    doMousePressed(sf::Vector2i{event.mouseButton.x, event.mouseButton.y});
                } else if (event.type == sf::Event::MouseButtonReleased) {
                    doMouseReleased(sf::Vector2i{event.mouseButton.x, event.mouseButton.y});
                } else if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode == 114) { //r
                        doRandomGame();
                    } else if (event.text.unicode == 112) { //p
                        gameBoard.printGame();
                    } else if (event.text.unicode == 110) { //n
                        doLevelUp();
                    } else
                        std::cout << "ASCII character typed: " << event.text.unicode << " --> " << static_cast<char> (event.text.unicode) << std::endl;
                }
            }

            sf::Time dt = deltaClock.restart();
            update(dt.asSeconds());
            gameView.render();
            if (gameState == GameState::VictoryRolling) {
                victoryRollingTime -= dt.asSeconds();
                if (victoryRollingTime < 0.0f) {
                    doLevelUp();
                    gameState = GameState::Playing;
                }
                // Load a sprite to display
                sf::Texture texture;
                texture.loadFromFile("assets/trophy.png");
                sf::Sprite sprite(texture);
                sprite.setPosition(10, 10);
                RenderingSingleton::getInstance().getRenderWindow()->draw(sprite);
            }
            levelLabel.render();
            movesLabel.render();
            parLabel.render();
            randomSfmlButton.render();
            nextSfmlButton.render();
            restartSfmlButton.render();
            window->display();
        }
    }

    void Game::doRandomGame() {
        int count{0};
        do {
            gameBoard.randomGame(1);
            PuzzleSolver puzzleSolver;
            MoveNode rootNode = puzzleSolver.getTree(gameBoard.serialiseGame(), 3);

            std::cout << "trying a game: " << ++count << "\n";
            int solutionDepth = puzzleSolver.hasASolution(rootNode);
            if (solutionDepth > -1) {
                std::cout << "Solution Depth: " << solutionDepth << "\n";
                count = -1;
            }
        } while (count > -1);
    }

    void Game::doMousePressed(const sf::Vector2i & mousePosition) {
        mousePositionPressed = mousePosition;
    }

    void Game::doMouseReleased(const sf::Vector2i & mousePosition) {
        if (nextSfmlButton.mouseReleased(mousePosition)) {
            onNextButtonClick();
        } else if (randomSfmlButton.mouseReleased(mousePosition)) {
            onRandomButtonClick();
        } else if (restartSfmlButton.mouseReleased(mousePosition)) {
            onRestartButtonClick();
        }
        sf::Vector2i movingTilePosition = RenderingSingleton::getInstance().findTile(mousePositionPressed);
        if (movingTilePosition.x == -1 || movingTilePosition.y == -1)
            return; // out of grid
        int deltaX = mousePosition.x - mousePositionPressed.x;
        int deltaY = mousePosition.y - mousePositionPressed.y;
        if (abs(deltaX) > 2 || abs(deltaY) > 2) {
            SlidingTiles::Tile movingTile = gameBoard.tiles[movingTilePosition.x][movingTilePosition.y];
            if (abs(deltaX) > abs(deltaY)) {
                // horizontal movement
                sf::Vector2i newPosition = sf::Vector2i(movingTilePosition.x + copysign(1, deltaX), movingTilePosition.y);
                if (deltaX > 0) {
                    gameBoard.slideTile(Move{movingTilePosition, Direction::GoRight});
                } else {
                    gameBoard.slideTile(Move{movingTilePosition, Direction::GoLeft});
                }
            } else {
                // vertical movement
                sf::Vector2i newPosition = sf::Vector2i(movingTilePosition.x, movingTilePosition.y + copysign(1, deltaY));
                //gameBoard.slideTile(movingTilePosition, newPosition);
                if (deltaY > 0) {
                    gameBoard.slideTile(Move{movingTilePosition, Direction::GoDown});
                } else {
                    gameBoard.slideTile(Move{movingTilePosition, Direction::GoUp});
                }

            }
        }
    }

    void Game::loadLevel() {
        std::ostringstream levelText;
        levelText << "Level: " << level;
        levelLabel.setText(levelText.str());

        std::ostringstream movesText;
        movesText << "Moves: " << moves;
        movesLabel.setText(movesText.str());


        std::ostringstream parText;
        parText << "Par: " << par;
        parLabel.setText(parText.str());

        json jsonLevel = levelsArray[level];
        std::string serializedGame = jsonLevel["SerializedGame"].get<std::string>();
        gameBoard.loadGame(serializedGame);
        gameState = GameState::Playing;
    }

    void Game::doLevelUp() {
        ++level;
        if (level >= levelsArray.size()) {
            level = 0;
        }
        loadLevel();
    }

}
