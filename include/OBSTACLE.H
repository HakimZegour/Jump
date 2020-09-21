#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include"OBJECT.H"

class Obstacle : public Object{

    public:
    Obstacle();

    ///Clocks
    sf::Clock clockObstacle;

    ///Graph
    int ObstacleHeight = 5;
    int ObstacleWidth = 100 ;
    int ObstacleY = LINEPOSITION - ObstacleWidth ;
    sf::RectangleShape Forme{sf::Vector2f(ObstacleHeight, ObstacleWidth)};

    ///Actions
    void Move() ;
    void Update();
    float Position ;
    float Speed = 100 ;

    bool Delete = false;

};

#endif // OBSTACLE_H_INCLUDED
