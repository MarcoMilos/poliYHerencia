// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#include <vector>
#include <ctime> // Se incluye para generar una semilla unica para la funcion rand()
#include "board.h"
#include "dice.h"
#include "player.h"

class Match
{
    // atributos de clase
    int penalty; // establece las penalizaciones por caer en casilla serpiente
    int reward; // establece las recompensas por caer en casilla escalera
    int players; // establece la cantidad de jugadores en la partida
    int turns; // establece la cantidad de turnos maximos permitidos
    std::string gameType; // establece el tipo de juego <automatico> o <manual>
    std::vector<Player> playerList; // lista de jugadores

    // metodos privados 
    void setupPlayers();
    void playTurn(Player &player);
    void printWinner(Player &player);

    public:
        // constructores
        Match() = default; // constructor por omision
        
        // destructor
        ~Match();

        // starter
        void start();
};

Match::Match()
{ // establecemos los valores por omision en "0"
    penalty = 0;
    reward = 0;
    players = 0;
    turns = 0;
    gameType = "";
}

Match::~Match() {}

void Match::setupPlayers()
{
    std::string playerName;
    for (int i = 0; i < players; i++)
    {
        std::cout << "Enter the name of Player " << i + 1 << ": ";
        std::cin >> playerName;
        playerList.push_back(Player(playerName));
    }
}

void Match::playTurn(Player &player)
{
    int diceRoll = Dice::roll();
    int newPosition = player.getPosition() + diceRoll;
    Tile* currentTile = board.getTiles(newPosition);

    if (newPosition >= board.getTiles())
    {
        newPosition = board.getTiles() - 1;
        player.setPosition(newPosition);
        printWinner(player);
        return;
    }

    if (currentTile->getType() == 'S')
    {
        newPosition -= penalty;
    } else if (currentTile->getType() == 'L')
    {
        newPosition += reward;
    }

    player.setPosition(newPosition);
}

void Match::printWinner(Player &player)
{
    std::cout << "--- GAME OVER ---" << std::endl;
    std::cout << "Player: " << player.getName() << " is the winner!!" << std::endl;
}

void Match::start()
{
    srand(time(nullptr)); // generamos una semilla unica para la funcion rand()

    Board b0;
    b0.print();

    std::cout << "Indicate the amount of tiles you will be penalized with after falling on a snake tile: ";
    std::cin >> penalty;

    std::cout << "Indicate the amount of tiles you will be rewarded with after falling on a ladder tile: ";
    std::cin >> reward;

    std::cout << "Indicate the amount of players in the match: ";
    std::cin >> players;
    setupPlayers();

    std::cout << "Indicate the game type A <automatic> M <manual>: ";
    std::cin >> gameType;

    std::cout << "Starting game...." << std::endl;

    for (int i = 1; i <= players; i++)
    {
        playerList.push_back(Player(i, 1));
    }

    // selecciona si el juego comienza de manera automática o manual
    if (gameType == "M" or gameType == "m")
    {
        std::cout << "\nPress C to continue next turn, or E to end the game: " << std::endl;
        std::string input;
        std::cin >> input;

        while (input != "E") // Establecemos que -mientras la respuesta no sea "E" (exit)- el juego empiece/siga
        {
            Match m3;
            m3.playTurn();
        }  
    } else if (gameType == "A" or gameType == "a") {
        Match m3;
        m3.playTurn();
    }   
}

