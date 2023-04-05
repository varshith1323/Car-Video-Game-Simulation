//IMT2021078
#include "Car.h"
#include "PingPong.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

    PingPong::PingPong(int posX,int posY,string dir,int leftNum,int rightNum,int topNum,int bottomNum)  : Car(leftNum,rightNum,topNum,bottomNum)
    {
        initx=posX;
        inity=posY;
        initdir=dir;
    }

    string PingPong::move(int K, int N)
    {
        steps=K*N;
        finalx=initx; //finalx and finaly refer to the coordinates after a certain movement
        finaly=inity;
        finaldir=initdir;
        while(steps>0)
        {
                if(finaldir=="left")
                {
                    limit=finalx-leftNum;
                    if(steps<=limit) //same logic as Lemon
                    {
                        //finaly has previous y coordinate already
                        finalx=finalx-steps;
                        resultStr=to_string(finalx)+" "+to_string(finaly)+"\n";
                        return(resultStr);

                    }
                    else
                    {
                        finalx=leftNum;
                        //finaly=inity; is already the assigned value of finaly
                        steps=steps-limit; //removing the steps covered till we reach the wall
                        finaldir="right"; //once it hits the wall, we rebound, i. e., if the current dir is left it becomes right and vice versa
                    }
                }
                else if(finaldir=="up")
                {
                    limit=finaly-topNum;
                    if(steps<=limit)
                    {
                        finaly=finaly-steps;
                        resultStr=to_string(finalx)+" "+to_string(finaly)+"\n";
                        return(resultStr);
                    }
                    else
                    {
                        finaly=topNum;
                        steps=steps-limit;
                        finaldir="down";
                    }
                }
                else if(finaldir=="right")
                {
                    limit=rightNum-finalx;
                    if(steps<=limit)
                    {
                        finalx=finalx+steps;
                        resultStr=to_string(finalx)+" "+to_string(finaly)+"\n";
                        return(resultStr);
                    }
                    else
                    {
                        finalx=rightNum;
                        steps=steps-limit;
                        finaldir="left";
                    }
                }
                else if(finaldir=="down")
                {
                    limit=bottomNum-finaly;
                    if(steps<=limit)
                    {
                        finaly=finaly+steps;
                        resultStr=to_string(finalx)+" "+to_string(finaly)+"\n";
                        return(resultStr);
                    }
                    else
                    {
                        finaly=bottomNum;
                        steps=steps-limit;
                        finaldir="up";
                    }
                }
        }
        return NULL;
       
    }
