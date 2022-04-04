#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    lineSliders.setName("Lines");
    lineSliders.add(width.set("width", 0.5, 0.5, 5));
    pointSliders.setName("Points");
    pointSliders.add(radius.set("radius", 1, 10, 15)); //for points
    pointSliders.add(number.set("number", 5, 3, 20)); //for points
    colors.setName("Colors");
    colors.add(color.set("R,G,B", ofColor(100, 130, 160), ofColor(0, 0, 0), ofColor(255, 255, 255)));
    mainGroup.add(colors);
    mainGroup.add(lineSliders);
    mainGroup.add(pointSliders);
    gui.setup(mainGroup);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(10);
    ofSetColor(color->r, color->g, color->b);
    ofSetLineWidth(width);
    
    for (int i = 1; i < number; i++) {
        for (int j = 1; j < number; j++) {
            ofDrawCircle((ofGetWidth()/number) * i, (ofGetHeight()/number) * j, radius);
            ofDrawLine((ofGetWidth()/number) * i, (ofGetHeight()/number) * j, ofGetWidth()/2,ofGetHeight()/2);
        }
    }
    
    gui.draw();
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
