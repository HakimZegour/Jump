#ifndef LISTOBS_H
#define LISTOBS_H
#include "Obstacle.h"
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

class ListObs
{
    public:

        vector<Obstacle> ListObstacles;

        sf::Clock clockObstacles ;

        float T = 2 ;

        bool ToDelete(Obstacle a) ;
        void AddObstacle();
        //void DeleteObstacle();
        void Update();
        void Display(sf::RenderWindow& fenetre);

    protected:

    private:

};

#endif // LISTOBS_H
