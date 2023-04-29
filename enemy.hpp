#include <fstream>
#include <string>
#include "ofImage.h"
#include "ofMain.h"
#include "bullet.hpp"
using namespace std;

class Enemy : public ofRectangle{
public:
  
    ofImage enemy_image;
//    Bullet bullet;
    bool alive;
    float speed;
    
//// Methods
    ///
    ///
    Enemy();
    Enemy(int x_in,int y_in);
    void update();
    void kill();
    bool isAlive();
    void print(string label);
    void draw();
    void flipDirection();
//    void shoot();

};
