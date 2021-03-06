#pragma once

#include <SFML/Graphics.hpp>
#include "tile.h"
#include <string>
#include <vector>
#include "moveNode.h"
#include "solution.h"
#include "direction.h"
#include "gameBoard.h"

namespace SlidingTiles {

    /**
     * @brief A Puzzle Solver class
     */
    class PuzzleSolver {
    public:
        /**
         * @brief returns all moves that are possible on the current gameboard
         */
        std::experimental::optional<MoveNode> possibleMoves(MoveNode & parentNode);

        /**
         * @brief Adds the possibleMoves as MoveNodes to the supplied MoveNode
         * @param moveNode the node on which to Search and add the new Moves
         * @param levels how many levels deep to search 1 .. n
         */
        std::experimental::optional<MoveNode> addPossibleMoves(MoveNode & moveNode, const int levels);

        
        /**
         * @brief Builds the tree in the supplied gameBoard
         * @param gameBoard The GameBoard on which to build the tree
         * @param depth The depth to which the tree should be built
         */
        std::experimental::optional<MoveNode> buildTree(GameBoard & gameBoard, int depth);
        
        /**
         * @brief saves the solution to the supplied GameBoard
         * @param gameBoard the GameBoard to which the solution is to be saved
         */
        void saveSolution(GameBoard & gameBoard);
        
        /**
         * Generates a random playable game with a solution depth of Y 0
         * @param emptyTiles The number of empty tiles
         * @param maxDepth The maximum depth to search for 
         * @return the GameBoard of the playable game
         */
        GameBoard generateRandomGame(std::size_t emptyTiles, std::size_t maxDepth);
        
        /**
         * @brief generates a single playable Game and prints it
         * @param emptyTiles The number of empty tiles
         * @param maxDepth The maximum depth for a solution
         */
        void generateGame(std::size_t emptyTiles, std::size_t maxDepth);

        /**
         * @brief generates a series of games
         */
        void generateGames(std::size_t games);

    private:
        /**
         * @brief The number of tiles in each direction
         */
        static const int DEFAULT_DEPTH{3};
    };

} // namespace
