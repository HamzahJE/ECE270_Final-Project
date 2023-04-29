#pragma once
#include "ofMain.h"
#include "ofSoundPlayer.h"

#include "button.hpp"
#include "stars.hpp"
#include "player.hpp"
#include "enemy.hpp"
//#include "bullet.hpp"
#define N_STARS 1000
#define N_MAX 10000
#define NUM_ENEMYS_X 10 //ten rows
#define NUM_ENEMYS_Y 5 //five columns

class ofApp : public ofBaseApp{

	public:
    ofSoundPlayer start;
    Stars stars[N_STARS];
    Player myPlayer;
    Enemy enemy;
    Enemy enemys[NUM_ENEMYS_X][NUM_ENEMYS_Y];

    Button startButton;
    Button logoButton;
    int lastButtonPressTime=0;
    int lastSpacePressTime=0;
    int startTime;
    int killCount;
    int lastTime;
    int elapsedTime;
    int gameStatus; //0=main 1=play 2=end screen
    int enemy_col;
    int enemy_row;
    int enemyCount;
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
