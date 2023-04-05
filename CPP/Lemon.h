#ifndef LEMON_H
#define LEMON_H

#include "Car.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

class Lemon : public Car
{
    private:
    int initx,inity,finalx,finaly,llimit,rlimit,tlimit,blimit,steps;
    string initdir,resultStr;

    public:
    Lemon(int posX,int posY,string dir,int leftNum,int rightNum,int topNum,int bottomNum);
    virtual string move(int K, int N) ;
};

#endif