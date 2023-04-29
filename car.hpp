#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "obstacle.hpp"
using namespace std;

class Car {
public:
    int x;
    int y;
    
// Methods
    Car();
    void print(string label);
    void set(int x_in, int y_in);
    bool intersects(Obstacle other);
};
