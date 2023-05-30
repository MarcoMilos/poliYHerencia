// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include "board.h"
#include "dice.h"
#include "match.h"

int main()
{
    int tiles;
    int snakes;
    int ladders;
    int penalty;
    int reward;
    int players;
    int turns;
    std::string gameType;

    // solicito la cantidad de casillas, serpientes y escaleras desea tener el jugador en su partida
    std::cout << "Indicate the amount of tiles you wish to have: ";
    std::cin >> tiles;
    std::cout << "Indicate the amount of snakes you wish to have: ";
    std::cin >> snakes;
    std::cout << "Indicate the amount of ladders you wish to have: ";
    std::cin >> ladders;
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

    // while (gameType != "M")
    // {
        
    // }
    
    
    return 0; // indica al compilador que el proceso termino con exito
}