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
    
    //
    dim = 0;
    
    // width and height
    w = ofGetWidth();
    h = ofGetHeight();
    
    // to control movement
    center = false;
    started = false;
    
    // to slide curtains
    curtainY = 20;
    
    // for background
    firstBgColor = ofColor(0,28,124);
    secondBgColor = ofColor(252,156,84);
    ofBackground(firstBgColor);
    drawBgColor = firstBgColor;
    radius = 70;
    // when to change color
    firstChangeTime = 1;
    secondChangeTime = 10;
    thirdChangeTime = 18;
    
    cnt = 0;
    
    couch.load("images/couch.png");
    tree.load("images/tree.png");
    frame.load("images/frame.png");
    lamp.load("images/lamp.png");
}
//--------------------------------------------------------------
void ofApp::update(){
    float animationTime = ofGetElapsedTimef();

    // Pause before first change
    if (animationTime < firstChangeTime) {
        drawBgColor = firstBgColor;
                
    } else if (animationTime < secondChangeTime) {
        float timeSinceFirst = animationTime - firstChangeTime;
        float percentageToSecond = timeSinceFirst / (secondChangeTime - firstChangeTime);
        
        // transition into color
        drawBgColor = firstBgColor.getLerped(secondBgColor, percentageToSecond);
        
    } else if (animationTime < thirdChangeTime) {
        float timeSinceSecond = animationTime - secondChangeTime;
        float percentageToThird = timeSinceSecond / (thirdChangeTime - secondChangeTime);
        drawBgColor = secondBgColor.getLerped(firstBgColor, percentageToThird);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    // set background color based on change in time
    ofBackground(drawBgColor);
    
    // when the sun exits the screen, reset
    if (posX >= w + 100) {
        center = false;
        started = true;
        cnt++;
        posX = -100;
        posY = (h/4)*3;
        // add the elapsed time to the initial start times
        firstChangeTime += ofGetElapsedTimef()/cnt;
        secondChangeTime += ofGetElapsedTimef()/cnt;
        thirdChangeTime += ofGetElapsedTimef()/cnt;
        //initial sun r,g,b
        r = 242;
        g = 232;
        b = 158;
    }
    // if the sun reaches the center, move it downwards
    if (posX >= (w/2)) {
        center = true;
        posY += 0.7;
        dim += 0.3;
        if(curtainY < (h/8)*4 + 20){
            curtainY += 1;
        }
        // sun color
        ofSetColor(r, g -= 0.1, b -=0.1);
    }
    else{
        posY -= 0.7;
        if (started == true){
            dim -= 0.3;
            if(curtainY > 20){
                curtainY -= 1;
            }
        }
        // sun color
        ofSetColor(r, g -= 0.2, b -=0.2);
    }
    posX += 1.5;
    ofDrawCircle(posX, posY, radius);
    
    // for the center of the window
    ofSetColor(235);
    ofDrawRectangle((w/2)-10, 0, 20, h);
    ofDrawRectangle(0, ((h/8)*3)-10, w, 20);
    
    // for the walls
    ofSetColor(180);
    // top
    ofDrawRectangle(0, 0, w, (h/8));
    // bottom
    ofDrawRectangle(0, (h/8)*5, w, (h/8)*3);
    // left side
    ofDrawRectangle(0, 0, w/4, h);
    // right side
    ofDrawRectangle((w/4)*3, 0, w/4, h);
    
    // wall/ground separation
    ofSetColor(60);
    ofDrawLine(0, ofGetHeight()/8*7, ofGetWidth(), ofGetHeight()/8*7);

    //lamp stand
    ofSetColor(30);
    ofDrawRectangle((w/8)*7 + 2.5, ((h/8)*3), 15, ((h/8)*5) - 70);
    ofDrawRectangle((w/8)*7 - 40, h - 70, 95, 10);
    
    // to change bulb color
    if (center == true){
        ofSetColor(255,255,153);
    }
    else{
        ofSetColor(230);
    }
    //bulb
    ofDrawEllipse(((w/8)*7) + 10,((h/8)*3) + 5,40,60);
    
    //lamp cover
    ofSetColor(50);
    lamp.draw((w/11)*9, (h/5), w/8, w/8);
    
    // blinds
    ofSetColor(0);
    ofDrawRectangle(w/4, h/9 + 10, (w/4)*2, curtainY);
    
    ofSetColor(112, 76, 47); //filter
    couch.draw(w/6, (h/8)*4 + 20, w/3*2, h/3*2 + 20);
    tree.draw(0, h/2 - 80, w/4, h/1.5);
    
    ofSetColor(162, 126, 97);
    frame.draw(10, h/12, w/4.5, w/4.5);
    
    ofSetColor(0, dim);
    ofDrawRectangle(0, 0, w, h);
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
