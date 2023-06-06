// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#include <vector>
#include <string>
#include "board.h"
#include "tile.h"
#include "snake.h"
#include "ladder.h"
#include "dice.h"
#include "player.h"
#include "turn.h"
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
    int TRN = 60; // cantidad máximo de turnos
    char GM = 'A'; // Modalidad: 'A' <automático> / 'M' <manual>

    int turnCount = 0;
    bool end = false;

    Dice dice;
    std::vector<Player> players;
    public:
        // constructores
        Match(); // constructor por omision
        
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

    Tile * currentTile = currentBoard.getTiles_()[playing.getPosition()];
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
            std::cout << Turn(turnCount, playing.getPlayer(), rolled, currentTileType, playing.getPosition()) << std::endl;
        }
        else
        {
            std::cout << Turn(turnCount, playing.getPlayer(), rolled, 'N', 30) << std::endl;
            std::cout << "Player: " << playing.getPlayer() << " is the winner!!" << std::endl;
            end = true;
        }
    }
    else if(currentTileType == 'S')
    {
        std::cout << Turn(turnCount, playing.getPlayer(), rolled, currentTileType, playing + P) << std::endl;
        playing.setPosition(playing.getPosition() - P);
    }
    else
    {
        std::cout << Turn(turnCount, playing.getPlayer(), rolled, currentTileType, playing + R) << std::endl;
        playing.setPosition(playing.getPosition() + R);
    }

    turnCount++;
    if(turnCount >= TRN)
    {
        std::cout << "Exceeded the maximum number of turns!!" << std::endl;
        end = true;
    }
}

void Match::start()
{
    gameSetter();
    if(!validGame()) {return;}
    srand(time(NULL));
    Board board(T, S, L, P, R);
    for(int i = 0; i < PLRS; i++)
    {
        std::string username;
        std::cout << "Enter the name of the player " << i + 1 << ": " << std::endl;
        std::cin >> username;
        players.push_back(Player(username, i + 1));
    }

    if (GM == 'M')
    {
        char input;
        std::cout << "Welcome to the game!\nPlease enter C to continue next turn, or E to end the game: " << std::endl;
        while (!end)
        {
            std::cin >> input;
            while(input != 'C' && input != 'E')
            {
                std::cout << "Invalid option, please try pressing C to continue next turn or E to exit the game." << std::endl;
                std::cin >> input;
            }
            if(input == 'C')
            {
                playTurn(board);
            }
            else
            {
                std::cout << "Thanks for playing!!" << std::endl;
                break;
            }
        }
        std::cout << "--- GAME OVER ---" << std::endl;
    }
    else
    {
        while(!end)
        {
            playTurn(board);
        }
        std::cout << "--- GAME OVER ---" << std::endl;
        
    }
}