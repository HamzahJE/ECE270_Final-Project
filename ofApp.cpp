#include "ofApp.h"
int sample(int xmax, int xmin, int step, int x[]){
    int n;
    n =(xmax-xmin)/step +1;
    
    for (int i=0;i<n;i++){
        x[i]= xmin + (step *i);
    }
    return n;
}
void centeredArcadeText(string text,int fontSize,int lineNumber){
//    I added lineNumber so if I wanted to write more than one line of text over each other I would skip a the height of that line;
    ofTrueTypeFont arcadeFont;
    arcadeFont.load("arcadeFont.ttf", fontSize);
    float textWidth = arcadeFont.stringWidth(text);
    float textHeight = (arcadeFont.stringHeight(text) * lineNumber);
    float centerW=ofGetWidth()/2;
    float centerH=ofGetHeight()/2;
    ofSetColor(ofColor(220,215,215));
    arcadeFont.drawString(text, centerW - (textWidth/2) , centerH +textHeight*2 );
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(ofColor(7,11,52));
    ofSetFrameRate(60);
    start.load("start_music.mp3");
    gameStatus=0;
    killCount=0;
    enemyCount=NUM_ENEMYS_X*NUM_ENEMYS_Y;
    for (int i=0 ; i< N_STARS ; i++){
        stars[i].randSet();
        }
    for (int i = 0; i < NUM_ENEMYS_X; i++) {
        for (int j = 0; j < NUM_ENEMYS_Y; j++) {
            int x = i * (enemy.width + 10) + 50;
            int y = j * (enemy.height + 10) + 50;
            enemys[i][j] = Enemy(x,y);
        }
    }
    cout << "\n[0]" << enemys[0][0].x;
    cout << "\n[1]" << enemys[1][0].x;

}
//--------------------------------------------------------------
void ofApp::update(){

    if (gameStatus==1){
        float firstEnemyX;
        float lastEnemyX;
        firstEnemyX = (enemy.width + 10) + 50;
        lastEnemyX = (NUM_ENEMYS_X-1)*(enemy.width + 10) + 50;
        myPlayer.bullet.p_update();

        for (int i = 0; i < NUM_ENEMYS_X; i++) {
            for (int j = 0; j < NUM_ENEMYS_Y; j++) {
                if (firstEnemyX <= 50 || lastEnemyX >= ofGetWidth()-50) {
                    for (int a = 0; a < NUM_ENEMYS_X; a++) {
                        for (int b = 0; b < NUM_ENEMYS_Y; b++) {
                            enemys[a][b].flipDirection();
                        }
                    }
                }
                enemys[i][j].update();
//                enemys[i][j].bullet.e_update();
                firstEnemyX = enemys[0][0].x;
                lastEnemyX = enemys[NUM_ENEMYS_X - 1][0].x + enemy.width;
            
                if (enemys[i][j].intersects(myPlayer.bullet) && enemys[i][j].isAlive() && myPlayer.bullet.visible){
                    enemys[i][j].kill();
                    myPlayer.bullet.visible=false;
                    killCount++;
                    enemyCount--;
                }
                if (enemyCount==0){
                    gameStatus=2; //end screen
                    if (killCount==50) lastTime=elapsedTime;
                }
            }
                
            
        }

    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    if (gameStatus==0){
        //    Drawing Circles
        for (int i=0 ; i< N_STARS; i++){
            stars[i].draw();
        }
        startButton.drawStart(ofGetWidth()/2,ofGetHeight());
        logoButton.drawLogo(ofGetWidth()/2,100);
        string space = "Press SPACE or Press Mouse to Shoot";
        string mouse= "Use the Mouse to Move";
        string name= "By: Hamzah Jamal Eddin";
        
        centeredArcadeText(space, 16, 1);
        centeredArcadeText(mouse, 16, 2);
        centeredArcadeText(name, 16, 3);

    }
    
    if (gameStatus==1){
        int currentTime = ofGetElapsedTimeMillis();
        elapsedTime = currentTime - startTime;
        string elapsedTimeText = ofToString(elapsedTime / 1000) + " seconds";
        centeredArcadeText("Kill Count: "+ ofToString(killCount), 16, 1);
        centeredArcadeText("Beat Your Time", 25, 3);
        centeredArcadeText(elapsedTimeText, 24, 4);

        //    Drawing Circles
        for (int i=0 ; i< N_STARS; i++){
            stars[i].draw();
        }
        
        for (int i = 0; i < NUM_ENEMYS_X; i++) {
                for (int j = 0; j < NUM_ENEMYS_Y; j++) {
                    if (enemys[i][j].isAlive()) {
                        enemys[i][j].draw();

                    }
                }
            }
//        enemys[rand()%NUM_ENEMYS_X][rand()%NUM_ENEMYS_Y].shoot();

        myPlayer.shoot();
        myPlayer.draw();
   
    }
    if (gameStatus==2){
        //    Drawing Circles
        for (int i=0 ; i< N_STARS; i++){
            stars[i].draw();
        }
        startButton.drawStart(ofGetWidth()/2,ofGetHeight());
        logoButton.drawLogo(ofGetWidth()/2,100);
        string won = "You Won!";
        string time= "Ready to Beat your old Time of ";
        string again= "Want to Play Again?";
        
        centeredArcadeText(won, 16, 1);
        centeredArcadeText(time + ofToString(lastTime / 1000) + " seconds?", 16, 2);
        centeredArcadeText(again, 16, 3);
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (gameStatus==1){
        if (key==' '){
            int delay = 500;
            int currentTime = ofGetElapsedTimeMillis();
            if (currentTime > lastSpacePressTime + delay) {
                myPlayer.bullet.set(myPlayer.x+(myPlayer.getWidth()/2),myPlayer.y-(myPlayer.getHeight()/2));
                myPlayer.bullet.visible=true;
                lastSpacePressTime = currentTime;
            }
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
 
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    if (gameStatus==1){
            if ((x>(myPlayer.width/2)) && (x < ofGetWidth()-(myPlayer.width/2))){
            myPlayer.x=x-(myPlayer.width/2);
        }
    }

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (gameStatus==1){
        int delay = 500;
        int currentTime = ofGetElapsedTimeMillis();
        if (currentTime > lastButtonPressTime + delay) {
                myPlayer.bullet.set(myPlayer.x+(myPlayer.getWidth()/2),myPlayer.y-(myPlayer.getHeight()/2));
                myPlayer.bullet.visible=true;
            lastButtonPressTime = currentTime;
            }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (startButton.inside(x,y) && (gameStatus==0 || gameStatus==2) ) {
        startTime = ofGetElapsedTimeMillis();
        setup();
        gameStatus=1;
        start.play();
    }

}
//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
