// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#include <vector>
#include <ctime> // Se incluye para generar una semilla unica para la funcion rand()
#include "board.h"
#include "dice.h"
#include "player.h"
#pragma once

class Match
{
    // Valores "default"
    int T = 30; // cantidad de casillas (mínimo 5)
    int S = 6; // cantidad de serpientes
    int L = 4; // cantidad de escaleras
    int P = -3; // castigo por caer en casilla de tipo serpiente
    int R = 3; // premio por caer en casilla de tipo escalera
    int PLRS = 2; // cantidad de jugadores
    int TRN = 30; // cantidad máximo de turnos
    char GM = 'A'; // Modalidad: 'A' <automático> / 'M' <manual>

    int turnCount = 0;
    bool end = false;

    Dice dice;
    std::vector<Player> players;
    public:
        // constructores
        Match() = default; // constructor por omision
        
        // destructor
        ~Match();

        // starter
        void start();
        void gameSetter();
        bool validGame();
        void playTurn(Board);
};

Match::Match(){} // constructor por omision

Match::~Match(){}

void Match::gameSetter()
{
    std::cout << "Indicate the amount of tiles on the game: ";
    std::cin >> T;
    std::cout << "Indicate the amount of snakes on the game: ";
    std::cin >> S;
    std::cout << "Indicate the amount of ladders on the game: ";
    std::cin >> L;
    std::cout << "Indicate the amount of tiles you will be penalized with after falling on a snake tile: ";
    std::cin >> P;
    std::cout << "Indicate the amount of tiles you will be rewarded with after falling on a ladder tile: ";
    std::cin >> R;
    std::cout << "Indicate the amount of players in the match: ";
    std::cin >> PLRS;
    std::cout << "Indicate the maximum amount of turns: ";
    std::cin >> TRN;
    std::cout << "Indicate the game type A <automatic> M <manual>: ";
    std::cin >> GM;

    std::cout << "Starting game...." << std::endl;
}

bool Match::validGame()
{
    if((S + L) > (T - (P + R + 1))) // Nos aseguramos de que el número de casillas especiales no sea mayor al número de casillas disponibles 
    {
        std::cout << "Exceeded amount of special tiles. Please choose a smaller amount" << std::endl;
        return false;
    }
    else
    {
        std::cout << "Setting board" << std::endl;
        return true;
    }
}

void Match::playTurn(Board currentBoard)
{
    dice.roll();
    int rolled = dice.getNumber();
    Player &playing = players[turnCount%PLRS];

    playing.setPosition(playing.getPosition() + rolled);

    Tile * currentTile = currentBoard.getTiles()[playing.getPosition()];
    Tile & tileObjct = * currentTile;

    char currentTileType = 'N';

    if(playing.getPosition() < T)
    {
        currentTileType = tileObjct.getType();
    }

    if(currentTileType == 'N')
    {
        if(playing.getPosition() <= T)
        {
            
        }
    }
}
// Match::Match()
// { // establecemos los valores por omision en "0"
//     penalty = 0;
//     reward = 0;
//     players = 0;
//     turns = 0;
//     gameType = "";
//     Board board;
// }

// Match::~Match(){}

// void Match::setupPlayers()
// {
//     std::string playerName;
//     for (int i = 0; i < players; i++)
//     {
//         std::cout << "Enter the name of Player " << i + 1 << ": ";
//         std::cin >> playerName;
//         playerList.push_back(Player(playerName));
//     }
// }

// void Match::playTurn(Player &player)
// {
//     int diceRoll = Dice::roll();
//     int newPosition = player.getPosition() + diceRoll;
//     Tile* currentTile = board.getTiles(newPosition);

//     if (newPosition >= board.getTiles())
//     {
//         newPosition = board.getTiles() - 1;
//         player.setPosition(newPosition);
//         printWinner(player);
//         return;
//     }

//     if (currentTile->getType() == 'S')
//     {
//         newPosition -= penalty;
//     } else if (currentTile->getType() == 'L')
//     {
//         newPosition += reward;
//     }

//     player.setPosition(newPosition);
// }

// void Match::printWinner(Player &player)
// {
//     std::cout << "--- GAME OVER ---" << std::endl;
//     std::cout << "Player: " << player.getName() << " is the winner!!" << std::endl;
// }

// void Match::start()
// {
//     srand(time(nullptr)); // generamos una semilla unica para la funcion rand()

//     Board b0;
//     b0.print();

//     std::cout << "Indicate the amount of tiles you will be penalized with after falling on a snake tile: ";
//     std::cin >> penalty;

//     std::cout << "Indicate the amount of tiles you will be rewarded with after falling on a ladder tile: ";
//     std::cin >> reward;

//     std::cout << "Indicate the amount of players in the match: ";
//     std::cin >> players;
//     setupPlayers();

//     std::cout << "Indicate the game type A <automatic> M <manual>: ";
//     std::cin >> gameType;

//     std::cout << "Starting game...." << std::endl;

//     for (int i = 1; i <= players; i++)
//     {
//         playerList.push_back(Player(i, 1));
//     }

//     // selecciona si el juego comienza de manera automática o manual
//     if (gameType == "M" or gameType == "m")
//     {
//         std::cout << "\nPress C to continue next turn, or E to end the game: " << std::endl;
//         std::string input;
//         std::cin >> input;

//         while (input != "E") // Establecemos que -mientras la respuesta no sea "E" (exit)- el juego empiece/siga
//         {
//             Match m3;
//             m3.playTurn(playerList[0]);
//         }  
//     } else if (gameType == "A" or gameType == "a") {
//         Match m3;
//         m3.playTurn(playerList[0]);
//     }   
// }

