#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
  
        // For screenshot
        ofImage imageScreenshot;
        int cnt;
    
        // For panel/sliders
        ofxPanel gui;
        
        ofParameterGroup all;
        ofParameter<ofColor> color;
        ofParameter<int> number;
      
        ofParameterGroup lineSliders;
        ofParameter<float> width;
        
        ofParameterGroup pointSliders;
        ofParameter<int> radius;
      
        ofParameterGroup mainGroup;
        
};
