#include "button.hpp"
#include "ofColor.h"
#include "ofImage.h"
#include "ofColor.h"

Button::Button(){
    logo_image.loadImage("logo_image.png");
    start_image.loadImage("start_image.png");
  
}

void Button::print(string label){
    cout <<"\nButton Object" << label;
    cout <<"\nx: " << x;
    cout <<"\ny: " << y;
    cout <<"\nWidth: " << width;
    cout <<"\nHeight: " << height;
}

void Button::drawLogo(int x_in, int y_in){
    ofSetColor(255, 255, 255, 255);
    height=logo_image.getHeight();
    width=logo_image.getWidth()+200;
    x=x_in-(width/2);
    y=y_in;
  
    logo_image.draw(x,y,width,height);
    
}

void Button::drawStart(int x_in, int y_in){
    ofSetColor(255, 255, 255, 255);
    height=start_image.getHeight()-50;
    width=start_image.getWidth()-50;
    x=x_in-(width/2);
    y=y_in-height-50;
    start_image.draw( x,y,width,height);
}

