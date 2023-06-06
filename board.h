// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#include <cstdlib> // sirve para llamar a la funcion rand()
#include <vector>
#include "tile.h"
#include "snake.h"
#include "ladder.h"
#include "dice.h"
#pragma once // compila la clase una sola vez

class Board 
{
    // atributos de clase
    Dice dice;
    int tiles; // cantidad de casillas por omision
    int snakes; // cantidad de serpientes por omision
    int ladders; // cantidad de escaleras por omision
    int penalty; // cantidad de casillas de castigo por caer en casilla de tipo serpiente
    int reward; // cantidad de casillas de recompensa por caer en casilla de tipo escalera
    std::vector<Tile *> boardTiles;
    
    public:
        // constructores
        Board() = default; // constructor por omision
        Board(const int&, const int&, const int&, const int&, const int&); // v1 constructor por argumentos
        Board(const int&, const int&, const int&, const std::vector<Tile *>); // v2 constructor por argumentos

        // destructor
        ~Board();

        // setters
        void setTiles(int);
        void setSnakes(int);
        void setLadders(int);
        void setPenalty(int);
        void setReward(int);
        void setTiles_(std::vector<Tile *>);

        // getters
        int getTiles_();
        int getSnakes();
        int getLadders();
        int getReward();
        int getPenalty();
        std::vector<Tile *> getTiles();

};

Board::Board(const int& tiles, const int& snakes, const int& ladders, const int& penalty, const int& reward)
{
    this->tiles = tiles;
    this->snakes = snakes;
    this->ladders = ladders;
    this->penalty = penalty;
    this->reward = reward;
    srand(time(NULL));
    for(int i = 0; i < tiles; i++)
    {
        boardTiles.push_back(new Tile('N', i));
    }

    for(int i = 0; i < snakes; i++) 
    {
        int tile;
        do
        {
            tile = dice.customRoll(penalty, tiles - 1);
        } while (boardTiles[tile]->getType() == 'S' || boardTiles[tile]->getType() == 'L');
        boardTiles.erase(boardTiles.begin() + tile); // elimina la casilla normal
        boardTiles.insert(boardTiles.begin() + tile, new Snake('S', tile));
    }

    for(int i = 0; i < ladders; i++)
    {
        int tile;
        do
        {
            tile = dice.customRoll(1, tiles - reward - 1);
        } while (boardTiles[tile]->getType() == 'S' || boardTiles[tile]->getType() == 'L');
        boardTiles.erase(boardTiles.begin() + tile);
        boardTiles.insert(boardTiles.begin() + tile, new Ladder('L', tile));
    }
    
    for(int i = 0; i < tiles; i++)
    {
        boardTiles[i]->print();
    }

}

Board::Board(const int& tiles, const int& snakes, const int& ladders, const std::vector<Tile *> boardTiles)
{
    this->tiles = tiles;
    this->snakes = snakes;
    this->ladders = ladders;
    this->boardTiles = boardTiles;
}

Board::~Board(){}

int Board::getTiles_()
{
    return tiles;
}
int Board::getSnakes()
{
    return snakes;
}
int Board::getLadders()
{
    return ladders;
}
int Board::getPenalty()
{
    return penalty;
}
int Board::getReward()
{
    return reward;
}

std::vector<Tile *> Board::getTiles()
{
    return boardTiles;
}

void Board::setTiles(int tiles)
{
    this->tiles = tiles;
}
void Board::setTiles_(std::vector<Tile *> boardTiles)
{
    this->boardTiles = boardTiles;
}
void Board::setSnakes(int snakes)
{
    this->snakes = snakes;
}
void Board::setLadders(int ladders)
{
    this->ladders = ladders;
}
void Board::setPenalty(int penalty)
{
    this->penalty = penalty;
}
void Board::setReward(int reward)
{
    this->reward = reward;
}