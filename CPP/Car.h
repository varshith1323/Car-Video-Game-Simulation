#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

class Car
{
    protected:
    int leftNum,rightNum,topNum,bottomNum;

    public:
    Car(int left,int right,int up,int down);
    virtual string move(int K, int N);

};

#endif