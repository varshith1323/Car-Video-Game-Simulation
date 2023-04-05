//IMT2021078
#include "Car.h"
#include "Lemon.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;
    
    Lemon::Lemon(int posX,int posY,string dir,int leftNum,int rightNum,int topNum,int bottomNum) : Car(leftNum,rightNum,topNum,bottomNum)
    {
        initx=posX;
        inity=posY;
        initdir=dir;
    }
    
    string Lemon::move(int K, int N) 
    {
        steps=K*N;

        if(initdir=="left")
        {
            llimit=initx-leftNum; //distance between the left bound of the grid and the current position
            if(llimit<steps)
            {
                finalx=leftNum; //if the remaining steps are more than the limit, we just take the bound of the grid as final position as the car stops upon hitting a wall
            }

            else
            {
                finalx=initx-steps; //if the number of steps remaining are less than the limit, we just add/subtract those steps from the current position depending upon the direction
            }

            finaly=inity; //y-coordinate remains same in left/right movement
            resultStr=to_string(finalx)+" "+to_string(finaly)+"\n";
            return(resultStr);
        }


        if(initdir=="right")
        {
            rlimit=rightNum-initx;
            if(rlimit<steps)
            {
                finalx=rightNum;
            }

            else
            {
                finalx=initx+steps;
            }

            finaly=inity;
            resultStr=to_string(finalx)+" "+to_string(finaly)+"\n";
            return(resultStr);
        }

        if(initdir=="up")
        {
            tlimit=inity-topNum;
            if(tlimit<steps)
            {
                finaly=topNum;
            }

            else
            {
                finaly=inity-steps;
            }

            finalx=initx;
            resultStr=to_string(finalx)+" "+to_string(finaly)+"\n";
            return(resultStr);
        }

        if(initdir=="down")
        {
            blimit=bottomNum-inity;
            if(blimit<steps)
            {
                finaly=bottomNum;
            }

            else
            {
                finaly=inity+steps;
            }

            finalx=initx;
            resultStr=to_string(finalx)+" "+to_string(finaly)+"\n";
            return(resultStr);
        }

        return NULL;
    }
