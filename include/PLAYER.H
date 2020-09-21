#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include"OBJECT.H"

class Player : public Object
{

    public:
    Player();

    ///Clocks
    sf::Clock clockJump;
    sf::Clock clockRotation;

    ///Graph & audio
    sf::SoundBuffer buffer;
    sf::Sound sound;
    bool soundPlayed = false;

    float CircleRadius = 50 ;
    float CircleX = 50 ;
    float CircleY = LINEPOSITION - CircleRadius;
    sf::CircleShape Forme{CircleRadius};
    sf::Texture texture;

    ///Actions
    void Update();
    void Event();
    void Rotation();
    void Jump() ;
        ///Jump
        bool bJump = false;
        float ts = 2.0;
        float a = ts/2;
        float b = a*a;
        float JumpHeight = 300 ;
        float L = CircleY - JumpHeight ;

};

#endif // PLAYER_H
