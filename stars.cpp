#include "stars.hpp"
#include "ofColor.h"
#include "ofApp.h"
Stars::Stars(){
    fillOn= ofColor(255,255,255,200);
    fillOff=ofColor(0,0,0,0);
};

void Stars::print(string label){
    cout <<"\nStar Object" << label;
    cout <<"\nx: " << x;
    cout <<"\ny: " << y;
    cout <<"\nr: " << r;
}

void Stars::randSet(){
    x=rand()% ofGetWidth();
    y=rand()% ofGetHeight();
    r=1+rand()%3;
}
void Stars::draw(){

    ofFill();
    ofSetColor(fillOn);
    ofDrawCircle(x, y, r);
    }

