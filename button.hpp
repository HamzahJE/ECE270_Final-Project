#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ofColor.h>
#include <ofImage.h>
#include "ofMain.h"
using namespace std;

class Button : public ofRectangle{
public:
    ofImage start_image;
    ofImage logo_image;
    //    Methods
    Button();
    void print(string label);
    void drawLogo(int x_in, int y_in);
    void drawStart(int x_in, int y_in);

};
