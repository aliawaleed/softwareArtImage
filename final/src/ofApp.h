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
    
    //for the piano audios
    ofSoundPlayer sound1;
    ofSoundPlayer sound2;
    ofSoundPlayer sound3;
    ofSoundPlayer sound4;
    ofSoundPlayer sound5;
    ofSoundPlayer sound6;
    ofSoundPlayer sound7;
    ofSoundPlayer sound8;
    ofSoundPlayer sound9;
    ofSoundPlayer sound10;
    
    //for the drums audios
    ofSoundPlayer dsound1;
    ofSoundPlayer dsound2;
    ofSoundPlayer dsound3;
    ofSoundPlayer dsound4;
    ofSoundPlayer dsound5;
    ofSoundPlayer dsound6;
    ofSoundPlayer dsound7;
    ofSoundPlayer dsound8;
    ofSoundPlayer dsound9;
    ofSoundPlayer dsound10;

    //for the screen displays
    int mode;
    int screenWidth;
    int screenHeight;
    float homeRadius;
    ofVideoGrabber webcam; //to use the laptop camera
    ofColor color;
    float brightness;
    float radius;
    
    // back button
    ofImage back;
    ofImage backBlack;
    ofImage buttons;
    
    // font for home screen
    ofTrueTypeFont titleFont;
    ofTrueTypeFont themes;
};
