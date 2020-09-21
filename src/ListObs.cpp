#include "ListObs.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Obstacle.h"

bool ListObs::ToDelete(Obstacle a)
{
    return a.Delete;
}

void ListObs::AddObstacle()
{
    auto haie = Obstacle{};
    ListObstacles.push_back(haie);
    clockObstacles.restart();
}
/*
void ListObs::DeleteObstacle()
{
    auto finTableau = std::remove_if(std::begin(ListObstacles), std::end(ListObstacles), ToDelete) ;
    ListObstacles.erase( finTableau , std::end(ListObstacles) ) ;

}
*/

void ListObs::Update()
{
    sf::Time timeObstacles = clockObstacles.getElapsedTime() ;
    float tObstacles = timeObstacles.asSeconds();
    if(tObstacles > T){
        AddObstacle() ;
        clockObstacles.restart();
    }
/*
    if(ListObstacles.size() > 0){
        for(int i = 0 ; i < ListObstacles.size() ; i++){ ListObstacles[i].Update(); }
        if(ListObstacles[0].Position < 0){ DeleteObstacle();  }
    }
    */
}


void ListObs::Display(sf::RenderWindow& fenetre)
{
    if(ListObstacles.size() > 0){
        for(int i = 0 ; i < ListObstacles.size() ; i++) { fenetre.draw(ListObstacles[i].Forme);}
    }
}


