// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#include <vector>
#include "person.h"
#pragma once 

class Player : public Person // establecemos que la clase "Player" hereda de forma publica a la clase "Person"
{
    // atributos de clase
    int player;
    int position;
    
    public:
        // constructores
        Player() = default; // construtctor por omision
        Player(const std::string &name) : Person(name) {}; // establecemos un constructor que conecte la clase "Player" con la "Person"
        Player(const int &player, const int &position) : player(player), position(position) {};

        // destructor
        ~Player();

        // setters
        void setPlayer(int player);
        void setPosition(int position);

        // getters
        const int getPlayer();
        const int getPosition();
};

Player::~Player() {}

const int Player::getPlayer()
{
    return player;
}

void Player::setPlayer(int player)
{
    this->player = player; // establecemos el nuevo nombre del jugador
}

const int Player::getPosition()
{
    return position;
}

void Player::setPosition(int newPosition)
{
    position = newPosition; // imprime la nueva posicion del jugador
}