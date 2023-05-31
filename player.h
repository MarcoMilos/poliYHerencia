// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#pragma once // compila la clase una sola vez

class Player
{
    // atributos privados de la clase
    int player = 1; // asignamos al valor por omision como el "player 1"
    int position = 1;

public:
    // Constructores
    Player() = default; // constructor por omision 
    Player(const int &, const int &);
    // Destructor
    ~Player();
    // Getter
    const int &getPlayer();
    const int &getPosition();
    // Setter
    void setPlayer(const int &);
    void setPosition(const int);
    // Metodo que imprime los jugadores
    void printPlayer();
};

// constructor que recibe un parametro
Player::Player(const int &player, const int &position)
{
    this->player = player;
    this->position = position;
}

// destructor
Player::~Player() {}

// getter de players
const int &Player::getPlayer()
{
    return player;
}
// getter de posicion
const int &Player::getPosition()
{
    return position;
}

// setter de players
void Player::setPlayer(const int &player)
{ // establecemos el nuevo valor de los players 
    this->player = player;
}
// setter de posicion
void Player::setPosition(int newPosition)
{ // indica la nueva posicion en la que estara el "player" despues de hacer su jugada y moverse las casillas que indico el dado
    position = newPosition;
}

// imprime en pantalla la cantidad de jugadores
void Player::printPlayer()
{
    std::cout << player << position <<"\n";
}