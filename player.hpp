#include <fstream>
#include <string>
#include "ofImage.h"
#include "ofMain.h"
#include "bullet.hpp"
using namespace std;

class Player : public ofRectangle{
public:
  
    ofImage player_image;
    Bullet bullet;
    
    
//  Methods
    Player();
    void print(string label);
    void draw();
    void shoot();
};
