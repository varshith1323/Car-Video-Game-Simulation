//IMT2021078
#include "Game.h"
#include "Car.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;




    //constructor
    Game::Game(int l,int r,int t,int b,int numCars)
    {
        left=l;
        right=r;
        up=t;
        down=b;
        numOfCars=numCars;
    }

    

    void Game::addCar(Car *carObj)
    {
        carsList.push_back(carObj);
        for(vector<Car *>::iterator car = carsList.begin(); car != carsList.end(); ++car)//iterating through the list of objects
        {
             //maintaining a string of the result 
        }
    }

    
    

    string Game::strip(string &inpt) //to remove trailing spaces
    {
      //  auto start_it = inpt.begin();
        //auto end_it = inpt.rbegin();
        //while (isspace(*start_it))
          //  ++start_it;
        //while (isspace(*end_it))
          //  ++end_it;
        //return string(start_it, end_it.base());
        return inpt;
    }

    

    string Game::advance(int stepsK, int timesN)
    {
        string finalResult="";
        for(vector<Car *>::iterator car = carsList.begin(); car != carsList.end(); ++car)//iterating through the list of objects
        {
            finalResult=finalResult+(*car)->move(stepsK,timesN); //maintaining a string of the result 
        }
        finalResult=strip(finalResult); //to remove trailing spaces 
        return finalResult;
        
    }





 