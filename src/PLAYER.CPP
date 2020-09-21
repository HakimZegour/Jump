#include "Player.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>



Player::Player(){

    if (!buffer.loadFromFile("SoundJump2.wav")){  std::cout << "Probleme audio jump" << std::endl; }
    sound.setBuffer(buffer);

    if (!texture.loadFromFile("smiley3.png")){ std::cout<< "Erreur image" ; }
    texture.setSmooth(true);
    Forme.setTexture(&texture);
    Forme.setOrigin(sf::Vector2f(CircleRadius, CircleRadius));
    Forme.setPosition(CircleX, CircleY);
}

void Player::Event(){

    if(bJump == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        bJump = true ;
        clockJump.restart();
    }

}

void Player::Update(){

    if(bJump){ Jump();}
    Rotation();

}

void Player::Jump(){

    if ( sound.getStatus() != sf::Sound::Playing   &&   soundPlayed == false){
        sound.play();
        soundPlayed = true;
    }

    sf::Time timeJump = clockJump.getElapsedTime() ;
    float t = timeJump.asSeconds();

    if (t < ts){
        float posCircle = (L/b)*(t-a)*(t-a)+JumpHeight ;
        Forme.setPosition(CircleX, posCircle);
    }
    else{
        Forme.setPosition(CircleX, CircleY);
        bJump = false ;
        soundPlayed = false;
    }

}

void Player::Rotation(){

    sf::Time time = clockRotation.getElapsedTime() ;
    float t = time.asSeconds();
    Forme.rotate(t*180);
    clockRotation.restart();

}
