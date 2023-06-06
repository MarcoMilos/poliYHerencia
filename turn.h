// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#include <string>
#pragma once

class Turn
{
    // atributos de clase
    int turnCount;
    int playerCount;
    int playerSpawn; // Establece la casilla en la que aparece el jugador 
    int rolled;
    char tileType;
    int playerDespawn; // Establece la posicion final del jugador
    public:
        // constructores
        Turn() = default;
        Turn(const int& turnCount, const int& playerCount, const int& rolled, const char& tiletype, const int& playerDespawn) : turnCount(turnCount + 1), playerCount(playerCount), playerSpawn(playerDespawn - rolled + 1), rolled(rolled), tileType(tileType), playerDespawn(playerDespawn + 1) {}
        
        // destructor
        ~Turn();

        // setters
        void setTurnCount(int);
        void setPlayerCount(int);
        void setPlayerSpawn(int);
        void setRolled(int);
        void setTileType(char);
        void setPlayerDespawn(int);

        // getters
        int getTurnCount();
        int getPlayerCount();
        int getPlayerSpawn();
        int getRolled();
        char getTileType();
        int getPlayerDespawn();
};

Turn::~Turn() {}


void Turn::setTurnCount(int turnCount)
{
    this->turnCount = turnCount;
}
void Turn::setPlayerCount(int playerCount)
{
    this->playerCount = playerCount;
}
void Turn::setPlayerSpawn(int playerSpawn)
{
    this->playerSpawn = playerSpawn;
}
void Turn::setRolled(int rolled)
{
    this->rolled = rolled;
}
void Turn::setTileType(char tileType)
{
    this->tileType = tileType;
}
void Turn::setPlayerDespawn(int playerDespawn)
{
    this->playerDespawn = playerDespawn;
}


int Turn::getTurnCount()
{
    return turnCount;
}
int Turn::getPlayerCount()
{
    return playerCount;
}
int Turn::getPlayerSpawn()
{
    return playerSpawn;
}
int Turn::getRolled()
{
    return rolled;
}
char Turn::getTileType()
{
    return tileType;
}
int Turn::getPlayerDespawn()
{
    return playerDespawn;
}

std::ostream& operator<<(std::ostream&out, Turn turn)
{
    out << turn.getTurnCount() << " " << turn.getPlayerCount() << " " << turn.getPlayerSpawn() << " " << turn.getRolled() << " " << turn.getTileType() << " " << turn.getPlayerDespawn() << std::endl;
    return out;
}