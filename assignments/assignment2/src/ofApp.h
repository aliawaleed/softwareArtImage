#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

    public:
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
    
    // to keep track of which cycle we are on
    int cnt;
    
    float posX;
    float posY;
    
    float r;
    float g;
    float b;
    
    float h;
    float w;
    
    float dim;
    
    float firstChangeTime;
    float secondChangeTime;
    float thirdChangeTime;
    
    float radius;
    ofColor firstBgColor;
    ofColor secondBgColor;
    ofColor sunColor;
    ofColor drawBgColor;
    
    Boolean center;
    Boolean started;
    
    float curtainY;
    ofImage couch;
    ofImage tree;
    ofImage frame;
    ofImage lamp;
};
