#include "tile.h"
#include <gmock/gmock.h>
#include "gameBoard.h"

using namespace SlidingTiles;

TEST(Tile, ObjectCreation) {
    Tile tile;
}

TEST(Tile, outputDirectionStartRight) {
    Tile tile;
    tile.setTileType(TileType::StartRight);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::GoRight, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::GoRight, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::GoRight, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::GoRight, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::GoRight, newDirection);
}

TEST(Tile, outputDirectionStartLeft) {
    Tile tile;
    tile.setTileType(TileType::StartLeft);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::GoLeft, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::GoLeft, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::GoLeft, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::GoLeft, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::GoLeft, newDirection);
}

TEST(Tile, outputDirectionStartTop) {
    Tile tile;
    tile.setTileType(TileType::StartTop);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::GoUp, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::GoUp, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::GoUp, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::GoUp, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::GoUp, newDirection);
}

TEST(Tile, outputDirectionStartBottom) {
    Tile tile;
    tile.setTileType(TileType::StartBottom);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::GoDown, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::GoDown, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::GoDown, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::GoDown, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::GoDown, newDirection);
}

TEST(Tile, outputDirectionEndRight) {
    Tile tile;
    tile.setTileType(TileType::EndRight);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::Unknown, newDirection);
}

TEST(Tile, outputDirectionEndLeft) {
    Tile tile;
    tile.setTileType(TileType::EndLeft);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::Unknown, newDirection);
}

TEST(Tile, outputDirectionEndTop) {
    Tile tile;
    tile.setTileType(TileType::EndTop);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::Unknown, newDirection);
}

TEST(Tile, outputDirectionEndBottom) {
    Tile tile;
    tile.setTileType(TileType::EndBottom);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::Unknown, newDirection);
}

TEST(Tile, outputDirectionVertical) {
    Tile tile;
    tile.setTileType(TileType::Vertical);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::GoDown, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::GoUp, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::Unknown, newDirection);
}

TEST(Tile, outputDirectionHorizontal) {
    Tile tile;
    tile.setTileType(TileType::Horizontal);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::GoRight, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::GoLeft, newDirection);
}

TEST(Tile, outputDirectionBottomRight) {
    Tile tile;
    tile.setTileType(TileType::BottomRight);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::GoRight, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::GoDown, newDirection);
}

TEST(Tile, outputDirectionLeftTop) {
    Tile tile;
    tile.setTileType(TileType::LeftTop);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::GoLeft, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::GoUp, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::Unknown, newDirection);
}

TEST(Tile, outputDirectionLeftBottom) {
    Tile tile;
    tile.setTileType(TileType::LeftBottom);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::GoLeft, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::GoDown, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::Unknown, newDirection);
}

TEST(Tile, TopRight) {
    Tile tile;
    tile.setTileType(TileType::TopRight);
    Direction newDirection = tile.outputDirection(Direction::Unknown);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoDown);
    ASSERT_THAT(Direction::GoRight, newDirection);

    newDirection = tile.outputDirection(Direction::GoUp);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoRight);
    ASSERT_THAT(Direction::Unknown, newDirection);

    newDirection = tile.outputDirection(Direction::GoLeft);
    ASSERT_THAT(Direction::GoUp, newDirection);
}

TEST(Tile, setTileTypeChar) {
    Tile tile;

    tile.setTileType("-");
    ASSERT_EQ(TileType::Horizontal, tile.getTileType());

    tile.setTileType("|");
    ASSERT_EQ(TileType::Vertical, tile.getTileType());


    tile.setTileType("┐");
    ASSERT_EQ(TileType::LeftBottom, tile.getTileType());

    tile.setTileType("└");
    ASSERT_EQ(TileType::TopRight, tile.getTileType());

    tile.setTileType("┘");
    ASSERT_EQ(TileType::LeftTop, tile.getTileType());

    tile.setTileType("┌");
    ASSERT_EQ(TileType::BottomRight, tile.getTileType());


    tile.setTileType("├");
    ASSERT_EQ(TileType::StartRight, tile.getTileType());

    tile.setTileType("┤");
    ASSERT_EQ(TileType::StartLeft, tile.getTileType());

    tile.setTileType("┬");
    ASSERT_EQ(TileType::StartBottom, tile.getTileType());

    tile.setTileType("┴");
    ASSERT_EQ(TileType::StartTop, tile.getTileType());


    tile.setTileType("┣");
    ASSERT_EQ(TileType::EndRight, tile.getTileType());

    tile.setTileType("┫");
    ASSERT_EQ(TileType::EndLeft, tile.getTileType());

    tile.setTileType("┳");
    ASSERT_EQ(TileType::EndBottom, tile.getTileType());

    tile.setTileType("┻");
    ASSERT_EQ(TileType::EndTop, tile.getTileType());


    tile.setTileType(" ");
    ASSERT_EQ(TileType::Empty, tile.getTileType());
}

TEST(Tile, transition) {
    std::string game [GameBoard::boardSize][GameBoard::boardSize]{"├", "-", "-", "┐",
        "┣", "┐", " ", "|",
        "┌", "┘", " ", "|",
        "└", "-", "-", "┘"};
    GameBoard gameBoard;
    gameBoard.loadGame(game);
    Tile t = gameBoard.tiles[0][0];
    sf::Vector2i newPosition{1, 0};
    t.transition(newPosition);
    //bool result = t.transition(topLeftPostion);
    //ASSERT_TRUE(result) << "Transitioning should be possible first time\n";
    //result = t.transition(topLeftPostion);
    //ASSERT_FALSE(result) << "Transitioning should not be possible when transitioning in progress\n";
    ASSERT_EQ(t.getTilePosition().x, 1 );
    ASSERT_EQ(t.getTilePosition().y, 0 );
}
