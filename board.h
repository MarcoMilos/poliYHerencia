// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#include <cstdlib> // sirve para llamar a la funcion rand()
#include <vector>
#include "tile.h"
#include "snake.h"
#include "ladder.h"
#pragma once // compila la clase una sola vez

class Board 
{
    // atributos de clase
    int tiles = 0; // cantidad de casillas por omision
    int snakes = 0; // cantidad de serpientes por omision
    int ladders = 0; // cantidad de escaleras por omision
    std::vector<Tile *> boardTiles;
    
    public:
        // constructores
        Board() = default; // constructor por omision
        Board(int tiles, int snakes, int ladders); // constructor por definicion

        // destructor
        ~Board();

        // setters
        void setTiles(int tiles);
        void setSnakes(int snakes);
        void setLadders(int ladders);

        // getters
        const int getTiles();
        const int getSnakes();
        const int getLadders();

        // metodo para crear el tablero
        void createBoard();

        // metodo para imprimir el tablero
        virtual void print();
};

Board::Board(int tiles, int snakes, int ladders) : tiles(tiles), snakes(snakes), ladders(ladders)
{
    createBoard();
}

Board::~Board()
{ 
    for (Tile* tile : boardTiles)
    {
        delete tile;
    }
}

void Board::setTiles(int tiles)
{
    this->tiles = tiles;
}

void Board::setSnakes(int snakes)
{
    this->snakes = snakes;
}

void Board::setLadders(int ladders)
{
    this->ladders = ladders;
}

const int Board::getTiles()
{
    return tiles;
}

const int Board::getSnakes()
{
    return snakes;
}

const int Board::getLadders()
{
    return ladders;
}

void Board::createBoard()
{
    // eliminar la configuracion previa del tablero
    boardTiles.clear();

    // creamos las casillas normales
    for (int i = 0; i < tiles; i++)
    {
        Tile* tile = new Tile(i, 'N');
        boardTiles.push_back(tile);
    }

    // creamos las casillas de tipo serpiente
    for (int i = 0; i < snakes; i++)
    {
        int randomTile = rand() % tiles;
        Tile* snake = new Snake(randomTile, 'S');
        boardTiles[randomTile] = snake;
    }

    // creamos las casillas de tipo escalera
    for (int i = 0; i < ladders; i++)
    {
        int randomTile = rand() % tiles;
        Tile* ladder = new Ladder(randomTile, 'L');
        boardTiles[randomTile] = ladder;
    }
}

void Board::print()
{
    std::cout << "Indicate the amount of tiles you wish to have: ";
    std::cin >> tiles;
    std::cout << "Indicate the amount of snakes you wish to have: ";
    std::cin >> snakes;
    std::cout << "Indicate the amount of ladders you wish to have: ";
    std::cin >> ladders;
    for (Tile* tile : boardTiles)
    {
        tile->print();
        std::cout << " ";
    }
    std::cout << std::endl;
}