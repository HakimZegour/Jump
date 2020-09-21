#include "Obstacle.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


Obstacle::Obstacle(){

    Forme.setFillColor(sf::Color::Blue);
    Forme.setPosition(WIDTH, ObstacleY);

}


void Obstacle::Move(){
    sf::Time clockObstacleTime = clockObstacle.getElapsedTime();
    float fClock = clockObstacleTime.asSeconds() ;

    float distance = Speed * fClock ;
    Forme.setPosition(WIDTH - distance , ObstacleY);
    Position = Forme.getPosition().x ;
}

void Obstacle::Update(){

    Move();
    if(Position < 0) {
        Delete = true ;
    }
}

