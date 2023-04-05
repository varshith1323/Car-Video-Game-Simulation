#ifndef GAME_H
#define GAME_H

#include "Car.h"

class Game
{
    private:
    vector<Car *> carsList;
    int left, right, up, down, numOfCars;

    public:
    Game(int l,int r,int t,int b,int numCars);
    void addCar(Car *carObj);
    string strip(string &inpt);
    string advance(int stepsK, int timesN);

};

#endif