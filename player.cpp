#include "player.hpp"
#include "ofImage.h"

Player::Player(){
    x = ofGetWidth() / 2; // Center player horizontally
    y = ofGetHeight() - 100; // Set player at bottom of screen
    width = 50;
    height = 50;
    player_image.loadImage("player_image.png");
}

void Player::print(string label){
    cout << "\nPlayer Object: " << label;
    cout << "\nx: " << x;
    cout << "\ny: " << y;
}



void Player::draw(){
    player_image.draw(x,y,50,50);
}
void Player::shoot(){
    bullet.draw();
}
