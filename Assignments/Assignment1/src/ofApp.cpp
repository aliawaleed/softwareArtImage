#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    //// set screen size
    ofSetWindowShape(1200, 900);
    ofSetWindowPosition(20, 20);
    width = ofGetWidth();
    height = ofGetHeight();
    ////for screenshots
    cnt = 0;

    //// Gui setup
    themes.setName("Themes");
    themes.add(forest.set("forest", false));
    themes.add(ocean.set("ocean", false));
    themes.add(desert.set("desert", false));

    forest_array[0] = ofVec3f(52, 98, 63);
    forest_array[1] = ofVec3f(93, 66, 31);
    forest_array[2] = ofVec3f(118, 137, 72);
    forest_array[3] = ofVec3f(96, 119, 68);
    forest_array[4] = ofVec3f(30, 47, 35);

    ocean_array[0] = ofVec3f(91, 185, 199);
    ocean_array[1] = ofVec3f(4, 115, 133);
    ocean_array[2] = ofVec3f(119, 197, 209);
    ocean_array[3] = ofVec3f(100, 195, 209);
    ocean_array[4] = ofVec3f(35, 173, 194);

    desert_array[0] = ofVec3f(239, 180, 50);
    desert_array[1] = ofVec3f(240, 191, 83);
    desert_array[2] = ofVec3f(241, 202, 115);
    desert_array[3] = ofVec3f(242, 212, 148);
    desert_array[4] = ofVec3f(243, 223, 180);

    //// To control the shapes
    controls.setName("Change Location");
    controls.add(nShapes.set("no. of shapes", 10, 5, 20));
    changeLoc();

    //// add parameter groups to GUI
    all.add(themes);
    all.add(controls);
    gui.setup(all);
}

//--------------------------------------------------------------
void ofApp::update() {

}

void ofApp::changeLoc() {
    for (int i = 0; i < 20; i++) {
        x[i] = ofRandomWidth();
        y[i] = ofRandomHeight();
        w[i] = ofRandomWidth() / 4;
    }
}

void ofApp::drawTriangle(int a, int b, int c) {
    int t1 = a;
    int t2 = a - c / 2;
    int t3 = a + c / 2;
    int n1 = b + c;
    int n2 = b - c / 2;
    int n3 = b - c / 2;
    ofDrawTriangle(t1, n1, t2, n2, t3, n3);
}
//--------------------------------------------------------------
void ofApp::draw() {
    ofSetBackgroundColor(250, 250, 240);

    int j = 0;
    int count = 0;
    if (nShapesprev != nShapes) {
        changeLoc();
    }

    for (int i = 0; i < nShapes; i++) {
        if (count % 5 == 0) {
            j = i;
        }

        if (forest) {
            ofSetColor(forest_array[i - j].x, forest_array[i - j].y, forest_array[i - j].z, 200);
            ocean = false;
            desert = false;
        }
        else if (ocean) {
            ofSetColor(ocean_array[i - j].x, ocean_array[i - j].y, ocean_array[i - j].z, 200);
            forest = false;
            desert = false;
        }
        else if (desert) {
            ofSetColor(desert_array[i - j].x, desert_array[i - j].y, desert_array[i - j].z, 200);
            forest = false;
            ocean = false;
        }
        else {
            ofSetColor(50, 50, 50, 200);
        }

        ofSetCircleResolution(50);
        int a = 3;
        int n = nShapes % a;
        int b = x[i];
        int c = y[i];
        int d = w[i];

        ofSetRectMode(OF_RECTMODE_CENTER);

        ofLog() << "shape: " << shape;

        if (shape == 1) {
            ofDrawRectangle(b, c, d, d);
        }
        else if (shape == 2) {
            drawTriangle(b, c, d);
        }
        else {
            ofDrawCircle(b, c, d);
        }
        count++;
    }
    ofSetColor(0, 0, 0, 190);
    ofDrawBitmapString("Press SPACE to Change Shape", 0.0, height - 20.0);
    ofDrawBitmapString("Press 's' to take a screenshot", 0.0, height - 10.0);

    gui.draw();

    //
    forestprev = forest;
    oceanprev = oceanprev;
    desertprev = desert;
    //
    nShapesprev = nShapes;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    //to take a screenshot
    if (key == ' ') {
        shape = (shape + 1) % 3;
    }
    if (key == 's') {
        imageScreenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        imageScreenshot.save("screenshot" + ofToString(cnt) + ".png");
        cnt++;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
