//IMT2021078
#include "Car.h"
#include "Spinner.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

    Spinner::Spinner(int posX,int posY,string dir,int leftNum,int rightNum,int topNum,int bottomNum)  : Car(leftNum,rightNum,topNum,bottomNum)
    {
        initx=posX;
        inity=posY;
        initdir=dir;
    }

    string Spinner::move(int K, int N)
    {
        steps=K*N;

        //maintaining lists where the directions are all in cyclic order(if car is moving right, it hits the wall and goes down and then if it hits the bottom bound, it goes left and so on)

        finalx=initx;
        finaly=inity;
        finaldir=initdir;

        while(steps>0)
        {
            //cout<<"For loop start";
                //cout<<"dirlist2[ispin] "<<dirList2[iSpin];
                if(finaldir=="left")
                {

                    limit=finalx-leftNum;
                    if(steps<=limit)
                    {
                        //finaly has previous y coordinate already
                        finalx=finalx-steps;
                        resultStr=to_string(finalx)+" "+to_string(finaly)+"\n";
                        return(resultStr);

                    }
                    else
                    {
                        finalx=leftNum; //if number of steps remaining are more than the limit, we move the car till the bound of the grid in that direction first and then continue the iteration. in the next iteration, the direction changes as per the direction elements in the list above
                        //finaly=inity; is already the assigned value of finaly
                        steps=steps-limit;
                        finaldir="up";
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
                        finaldir="right";
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
                        finaldir="down";
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
                        finaldir="left";
                    }
                }
                
            //cout<<"for loop end";
        }
        return NULL;
    }
