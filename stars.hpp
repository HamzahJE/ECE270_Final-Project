#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ofColor.h>
#include "ofMain.h"
using namespace std;

class Stars{
public:
    int x;
    int y;
    int r;
    ofColor fillOff;
    ofColor fillOn;

    //    Methods
    Stars();
    void randSet();
    void print(string label);
    void draw();

};
