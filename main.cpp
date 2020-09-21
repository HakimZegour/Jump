/*

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Obstacle.h"
#include "Player.h"

//#include "OBJECT.h"

using namespace std;

bool ToDelete(Obstacle a)
{
    return a.Delete;
}

int main()
{


    vector<Obstacle> ListObstacle;
    string a ;

    do {

        cin >> a ;

        if(a == "false"){
            auto obstacle1 = Obstacle{};
            ListObstacle.push_back(obstacle1);
            cout << ListObstacle.size() << endl;

        }else if (a == "true"){
            auto obstacle1 = Obstacle{};
            obstacle1.Delete = true;
            ListObstacle.push_back(obstacle1);
            cout << ListObstacle.size() << endl;
            cout << "   1 vrai"<< endl;

        }else if (a=="size"){
            cout << ListObstacle.size() << endl;

        }else if (a == "less"){
            auto finTableau = std::remove_if(std::begin(ListObstacle), std::end(ListObstacle), ToDelete) ;
            ListObstacle.erase( finTableau , std::end(ListObstacle) ) ;
            cout << ListObstacle.size() << endl;
        }

    }while (a != "exit");

    cout << ListObstacle.size() << endl;

    return 0;

}
*/


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "Obstacle.h"
#include "Player.h"
#include "ListObs.h"
using namespace std;

bool ToDelete(Obstacle a)
{
    return a.Delete;
}

int main()
{

    ///Pause
    bool Pause = false;

    ///Sounds
    sf::Music music;
    if (!music.openFromFile("SoundTrack2.wav")){ return -1;}
    music.play();

    ///Definitions
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    const int HEIGHT = 600 ;
    const int WIDTH = 600 ;
    const int LINEPOSITION = HEIGHT - 50;
    const int LINEWIDTH = 5 ;
    sf::RenderWindow window(sf::VideoMode(HEIGHT, WIDTH), "Game",sf::Style::Default, settings);

    ///Décors
    sf::RectangleShape fond(sf::Vector2f(HEIGHT, WIDTH));
    fond.setFillColor(sf::Color::White);

    sf::RectangleShape line(sf::Vector2f(WIDTH, LINEWIDTH));
    line.setFillColor(sf::Color::Blue);
    line.setPosition(0, LINEPOSITION);

    ///Objets
    auto boule = Player{} ;
    auto List = ListObs{} ;

    ///clocks
    //sf::Clock clockObstacles ;

    ///Programme
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
               window.close();
            }

            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P ){
                if(Pause == false) {
                    Pause= true;
                    fond.setFillColor(sf::Color::Red);
                }
                else{
                    Pause = false;
                    fond.setFillColor(sf::Color::White);
                }
            }
        }

        if(Pause == false){
            boule.Event();
            boule.Update();
            List.Update();

        }

        if(List.ListObstacles.size() > 0){
            if(List.ListObstacles[0].Position < 0){
                auto finTableau = std::remove_if(std::begin(List.ListObstacles), std::end(List.ListObstacles), ToDelete) ;
                List.ListObstacles.erase( finTableau , std::end(List.ListObstacles) ) ;
            }
        }

        ///Draw
        window.clear();
        window.draw(fond);
        window.draw(line);
        window.draw(boule.Forme);


        if(List.ListObstacles.size() > 0){
            for(int i = 0 ; i < List.ListObstacles.size() ; i++) { window.draw(List.ListObstacles[i].Forme);}
        }

        //List.Display(window);

        window.display();
    }

    return 0;
}


