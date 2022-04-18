#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // starting positions for the sun
    posX = - 100;
    posY = (ofGetHeight()/4)*3;
    
    //initial sun r,g,b
    r = 242;
    g = 232;
    b = 158;
    
    // for background
    firstBgColor = ofColor(0,28,124);
    secondBgColor = ofColor(252,156,84);
    ofBackground(firstBgColor);
    drawBgColor = firstBgColor;
    radius = 70;
    // when to change color
    firstChangeTime = 1;
    secondChangeTime = 10;
    thirdChangeTime = 19;
    
    cnt = 0;
}
//--------------------------------------------------------------
void ofApp::update(){
    float animationTime = ofGetElapsedTimef();

    // Pause before first change
    if (animationTime < firstChangeTime) {
        drawBgColor = firstBgColor;
                
    } else if (animationTime < secondChangeTime) {
        // How many seconds since the start of the change?
        float timeSinceFirst = animationTime - firstChangeTime;
        
        // How far (as a percentage) are we to the next change?
        float percentageToSecond = timeSinceFirst / (secondChangeTime - firstChangeTime);
        
        drawBgColor = firstBgColor.getLerped(secondBgColor, percentageToSecond);
        
    } else if (animationTime < thirdChangeTime) {
        // How many seconds since the start of the change?
        float timeSinceSecond = animationTime - secondChangeTime;
        
        // How far (as a percentage) are we to the next change?
        float percentageToThird = timeSinceSecond / (thirdChangeTime - secondChangeTime);
        
        // Interpolate the color based on the percentage through the animation
        drawBgColor = secondBgColor.getLerped(ofColor(0,28,124), percentageToThird);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // set background color based on change in time
    ofBackground(drawBgColor);
    
    // when the sun exits the screen, reset
    if (posX >= ofGetWidth() + 100) {
        cnt++;
        posX = -100;
        posY = (ofGetHeight()/4)*3;
        // add the elapsed time to the initial start times
        firstChangeTime += cnt*ofGetElapsedTimef();
        secondChangeTime += cnt*ofGetElapsedTimef();
        thirdChangeTime += cnt*ofGetElapsedTimef();
        //initial sun r,g,b
        r = 242;
        g = 232;
        b = 158;
    }
    // if the sun reaches the center, move it downwards
    if (posX >= (ofGetWidth()/2)) {
        posY += 0.7;
        // sun color
        ofSetColor(r, g -= 0.1, b -=0.1);
    }
    else{
        posY -= 0.7;
        // sun color
        ofSetColor(r, g -= 0.2, b -=0.2);
    }
    posX += 1.5;
    ofDrawCircle(posX, posY, radius);
    
    // for the grass
    ofSetColor(10, 88, 62);
    ofDrawRectangle(0, (ofGetHeight()/4)*3, ofGetWidth(), ofGetHeight() - (ofGetHeight()/4)*3);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
