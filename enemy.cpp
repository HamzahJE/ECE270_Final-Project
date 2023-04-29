#include "enemy.hpp"
#include "ofImage.h"
Enemy::Enemy(){
    enemy_image.loadImage("enemy_image.png");
    width = enemy_image.getWidth();
    height = enemy_image.getHeight();
    alive=true;
}

Enemy::Enemy(int x_in,int y_in){
    x=x_in;
    y=y_in;
    enemy_image.loadImage("enemy_image.png");
    width = enemy_image.getWidth();
    height = enemy_image.getHeight();
    speed=5;
    alive=true;
}

void Enemy::update() {
    x += speed;
    if (x<= 0 ||  x>= ofGetWidth())  speed = -speed;
}


void Enemy::kill() {
    alive = false;
}

bool Enemy::isAlive() {
    return alive;
}

void Enemy::print(string label){
    cout << "\nEnemy Object: " << label;
    cout << "\nx: " << x;
    cout << "\ny: " << y;
}

void Enemy::draw(){
    ofSetColor(255, 255, 255,255);
    enemy_image.draw(x,y,20);
    
}
void Enemy::flipDirection(){
    speed *= -1;
}

//void Enemy::shoot(){
//    if (alive){
//        bullet.set(x+(width/2),y-(height/2));
//        bullet.draw();
//    }
//}
