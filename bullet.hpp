#pragma once
#include <fstream>
#include <string>
#include "ofImage.h"
#include "ofMain.h"

using namespace std;

class Bullet : public ofRectangle{
public:
    ofImage bullet_image;
    float speed;
    bool visible;
//// Methods
    Bullet();
    void set(int x_in,int y_in);
    void print(string label);
    void p_update();
//    void e_update();
    void draw();
};
