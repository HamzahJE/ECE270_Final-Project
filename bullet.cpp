#include "bullet.hpp"
#include "ofImage.h"
  
Bullet::Bullet(){
    width = 10;
    height = 30;
    bullet_image.loadImage("bullet_image.png");
    speed=30;
    visible=false;
}

void Bullet::print(string label){
    cout << "\nBullet Object: " << label;
    cout << "\nx: " << x;
    cout << "\ny: " << y;
}

void Bullet::set(int x_in,int y_in){
    x=x_in;
    y=y_in;
}

void Bullet::p_update(){
    if (visible) y -= speed;
    if (y < 0) visible = false;
}
//void Bullet::e_update(){
//    visible=true;
//    y += speed;
//    if (y > ofGetHeight()) visible = false;
//}

void Bullet::draw(){
    if (visible){
          bullet_image.draw(x-(width/2), y,10,30);
    }
}

