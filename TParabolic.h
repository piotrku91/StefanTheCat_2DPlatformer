#pragma once
#include <iostream>
#include <math.h>
#include <vector>

constexpr int MAX_POINTS=10;
constexpr int HALF_POINTS=MAX_POINTS/2;


   struct TPPoint
    {
    float x;
    float y;
    };

class TParabolic
{
    public:
    //std::vector <TPPoint> PPoint;
    TPPoint PPoint[MAX_POINTS];
    float ParameterA=-1;
    float XMultiplicator=2;

void Recalculate()
{
    std::cout << "---------------" <<std::endl;

    float YShift=ParameterA*pow(1*XMultiplicator-MAX_POINTS,2);// q - coordinate to Y to shift all points

for (int i=1; i<MAX_POINTS; i++)
{
PPoint[i].x=(i*XMultiplicator);
PPoint[i].y=ParameterA*pow(PPoint[i].x-MAX_POINTS,2) - YShift;

std::cout << "Punkt" << i;
std::cout << "- X: " << PPoint[i].x;
std::cout << " Y: " << PPoint[i].y <<std::endl;

};
std::cout << "---------------" <<std::endl;




};

    








};