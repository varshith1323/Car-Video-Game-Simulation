//IMT2021078
#include "Game.h"
#include "Car.h"
#include "Lemon.h"
#include "PingPong.h"
#include "Spinner.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;


int main()
{
        int l,r,t,b;
        cin>>l>>r>>t>>b;

        int numCars;
        cin>>numCars;
        Game gameObj(l,r,t,b,numCars);

        string carInfo,dir,carType;
        int posX,posY;
        for(int i=1;i<=numCars+1;i++)
        {
            if(i==1)
                continue; //to exclude running an empty string in the loop

            cin>>carType>>posX>>posY>>dir;

            if(carType=="Lemon")
            {
                //creating respective object using polymorphism and calling addCar method of Game class' object
                Car *carObj;
                carObj = new Lemon(posX,posY,dir,l,r,t,b);
                gameObj.addCar(carObj);
            }
            if(carType=="PingPong")
            {
                Car* carObj;
                carObj = new PingPong(posX,posY,dir,l,r,t,b);
                gameObj.addCar(carObj);
            }
            if(carType=="Spinner")
            {
                Car* carObj;
                carObj = new Spinner(posX,posY,dir,l,r,t,b);
                gameObj.addCar(carObj);
            }

        }

        int K,N;
        cin>>K>>N;

        cout<<gameObj.advance(K,N);
    
} 