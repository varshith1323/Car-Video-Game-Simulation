#ifndef PINGPONG_H
#define PINGPONG_H

#include "Car.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

class PingPong : public Car
{
    private:
    int initx,inity,finalx,finaly,limit,steps;
    string initdir, resultStr,finaldir;

    public:
    PingPong(int posX,int posY,string dir,int leftNum,int rightNum,int topNum,int bottomNum);
    virtual string move(int K, int N);
};

#endif