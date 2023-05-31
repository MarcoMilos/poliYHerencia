// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <cstdlib>
#include <string>
#include <iostream>
#include "dice.h"
#include "board.h"
#include "player.h"
#pragma once

class Match
{
    // atributos privados de la clase
    int currentPlayer = 1; // establece que el primero en jugar es el Player1
    int turnCount = 1; // establece la cuenta de turnos en 1 al iniciar el juego
    // metodos de la clase
    public:
        // constructores
        Match() = default; // constructor por omision
        Match(const int &, const int &);

        // destructor
        ~Match();

        // starter
        void start();
};

Match::Match(const int &currentPlayer, const int &turnCount)
{
    this->currentPlayer = currentPlayer; 
    this->turnCount = turnCount; 
}

Match::~Match(){}

void Match::start()
{
    Board b0;
    b0.print();
    // int tiles;
    // int snakes;
    // int ladders;
    int penalty;
    int reward;
    int players;
    int turns;
    std::string gameType;

    // solicito la cantidad de casillas, serpientes y escaleras desea tener el jugador en su partida
    // std::cout << "Indicate the amount of tiles you wish to have: ";
    // std::cin >> tiles;
    // std::cout << "Indicate the amount of snakes you wish to have: ";
    // std::cin >> snakes;
    // std::cout << "Indicate the amount of ladders you wish to have: ";
    // std::cin >> ladders;
    std::cout << "Indicate the amount of tiles you will be punished with after falling in a snake tile: ";
    std::cin >> penalty;
    std::cout << "Indicate the amount of tiles you will be rewarded with after falling in a ladder tile: ";
    std::cin >> reward;
    std::cout << "Indicate the amount of players in the match: ";
    std::cin >> players;
    std::cout << "Indicate the maximum amount of turns for the game: ";
    std::cin >> turns;
    std::cout << "Indicate the game type A <automatic>, M <manual>: ";
    std::cin >> gameType;

//     if (gameType == "A")
//     {
//         Player p0;
//         int diceResult = Dice::roll();

//         int currentPosition;
//         if (currentPlayer == 1)
//             p0.printPlayer();

//         char tileType; // Variable para declarar el tipo de casilla en la que pueden caer los jugadores
//         int nextPosition; // Variable para declarar la siguiente posición en la que estarán los jugadores tras tomar su turno

//         if (currentPosition + diceResult > tiles) // Declara que si la "posición actual" y el "resultado del dado" es MAYOR a 30, enviará el siguiente mensaje
//         {
//             std::cout << "Invalid move! Try Again." << std::endl;
//         }
//         // Se manda a desplegar el turno, jugador actual, posición actual, resultado del dado, tipo de casilla y siguiente posición:
//         std::cout << " " << turnCount << " " << currentPlayer << " " << currentPosition << " " << diceResult << " " << tileType << " " << nextPosition << std::endl;

//         currentPlayer = (currentPlayer == 1) ? 2 : 1;
//         turnCount++; // se suman los turnos conforme van pasando y participando cada jugador
//     }
}
