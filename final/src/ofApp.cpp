#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    screenWidth = ofGetWidth();
    screenHeight = ofGetHeight();
    homeRadius = 8;
    
    mode = 0;
    webcam.setup(1024,768); //width and height

    // loading in the audios for the piano/pastel
    sound1.load("a.wav");
    sound2.load("b.wav");
    sound3.load("c.wav");
    sound4.load("d.wav");
    sound5.load("e.wav");
    sound6.load("f.wav");
    sound7.load("g.wav");
    sound8.load("g#.wav");
    sound9.load("a#.wav");
    sound10.load("f#.wav");
    
    // loading in the audios for the drums/garbage
    dsound1.load("d0.wav");
    dsound2.load("d1.wav");
    dsound3.load("d2.wav");
    dsound4.load("d3.wav");
    dsound5.load("d4.wav");
    dsound6.load("d5.wav");
    dsound7.load("d6.wav");
    dsound8.load("d7.wav");
    dsound9.load("d8.wav");
    dsound10.load("d9.wav");
    
    // loading back button
    back.load("back.png");
    backBlack.load("backblack.png");
    buttons.load("button.png");
    
    // loading the title
    titleFont.load("Brannboll.ttf", 32);
    themes.load("alex.ttf", 32);
}

//--------------------------------------------------------------
void ofApp::update(){
    webcam.update(); //update the frame
    homeRadius -= 0.03;
    if (homeRadius <= 5) {
        homeRadius = 8;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    webcam.draw(0, 0, 320, 240); //starting point and width and height
    if (mode == 0) {
        ofBackground(0);
        for (int i = 12; i < screenWidth; i+= 24) {
            for (int j = 12; j < screenHeight; j+= 24) {
                ofSetColor(255);
                ofDrawCircle(i, j, homeRadius);
            }
        }
        
        ofSetColor(0);
        ofDrawRectangle(screenWidth/5, screenHeight/4, (screenWidth/5)*3, (screenHeight/4)*2);
        ofSetColor(255);
        titleFont.drawString("The Musical Mosaic!", screenWidth/4 + 40, screenHeight/2);
        
        buttons.draw(screenWidth/4 + 10, screenHeight/1.7, 200, 100);
        buttons.draw((screenWidth/4)*2 + 40, screenHeight/1.7, 200, 100);
        ofSetColor(0);
        themes.drawString("pastel", screenWidth/4 + 50 , screenHeight/1.5);
        themes.drawString("vivid", (screenWidth/4)*2 + 100, screenHeight/1.5);
    }

    // add circle every 16 pixels
    if(mode == 1){
        webcam.draw(0, 0); // specify the starting point on the screen
        for (int i = 8; i < screenWidth; i+= 16) {
          for (int j = 8; j < webcam.getHeight(); j+= 16) {
              color = webcam.getPixels().getColor(i, j);
              brightness = color.getBrightness();
              radius = ofMap(brightness, 0, 255, 0, 8);
              if(i < screenWidth/10){
                  ofSetColor(251, 248, 204);
                  if (radius < 0.5 and sound1.isPlaying() == 0){
                      sound1.play();
                  }
              }
              if ((screenWidth/10) < i and i < (screenWidth/10)*2){
                  ofSetColor(253, 228, 207);
                  if (radius < 0.5 and sound2.isPlaying() == 0){
                      sound2.play();
                  }
              }
              if ((screenWidth/10)*2 < i and i < (screenWidth/10)*3){
                  ofSetColor(255, 207, 210);
                  if (radius < 0.5 and sound3.isPlaying() == 0){
                      sound3.play();
                  }
              }
              if ((screenWidth/10)*3 < i and i < (screenWidth/10)*4){
                  ofSetColor(241, 192, 232);
                  if (radius < 0.5 and sound4.isPlaying() == 0){
                      sound4.play();
                  }
              }
              if ((screenWidth/10)*4 < i and i < (screenWidth/10)*5){
                  ofSetColor(207, 186, 240);
                  if (radius < 0.5 and sound5.isPlaying() == 0){
                      sound5.play();
                  }
              }
              if ((screenWidth/10)*5 < i and i < (screenWidth/10)*6){
                  ofSetColor(163, 196, 243);
                  if (radius < 0.5 and sound6.isPlaying() == 0){
                      sound6.play();
                  }
              }
              if ((screenWidth/10)*6 < i and i < (screenWidth/10)*7){
                  ofSetColor(144, 219, 244);
                  if (radius < 0.5 and sound7.isPlaying() == 0){
                      sound7.play();
                  }
              }
              if ((screenWidth/10)*7 < i and i < (screenWidth/10)*8){
                  ofSetColor(142, 236, 245);
                  if (radius < 0.5 and sound8.isPlaying() == 0){
                      sound8.play();
                  }
              }
              if ((screenWidth/10)*8 < i and i < (screenWidth/10)*9){
                  ofSetColor(152, 245, 225);
                  if (radius < 0.5 and sound9.isPlaying() == 0){
                      sound9.play();
                  }
              }
              if ((screenWidth/10)*9 < i and i < screenWidth){
                  ofSetColor(185, 251, 192);
                  if (radius < 0.5 and sound10.isPlaying() == 0){
                      sound10.play();
                  }
              }
            ofDrawCircle(i, j, radius);
          }
        }
        ofSetColor(255);
        backBlack.draw(0, 0, 60,60);
    }
    
    if (mode == 2) {
        webcam.draw(0, 0); // specify the starting point on the screen
        for (int i = 8; i < screenWidth; i+= 16) {
          for (int j = 8; j < webcam.getHeight(); j+= 16) {
              color = webcam.getPixels().getColor(i, j);
              brightness = color.getBrightness();
              radius = ofMap(brightness, 0, 255, 0, 8);
              if(i < screenWidth/10){
                  ofSetColor(0, 15, 20);
                  if (radius < 0.5 and dsound1.isPlaying() == 0){
                      dsound1.play();
                  }
              }
              if ((screenWidth/10) < i and i < (screenWidth/10)*2){
                  ofSetColor(0, 95, 115);
                  if (radius < 0.5 and dsound2.isPlaying() == 0){
                      dsound2.play();
                  }
              }
              if ((screenWidth/10)*2 < i and i < (screenWidth/10)*3){
                  ofSetColor(10, 147, 150);
                  if (radius < 0.5 and dsound3.isPlaying() == 0){
                      dsound3.play();
                  }
              }
              if ((screenWidth/10)*3 < i and i < (screenWidth/10)*4){
                  ofSetColor(148, 210, 189);
                  if (radius < 0.5 and dsound4.isPlaying() == 0){
                      dsound4.play();
                  }
              }
              if ((screenWidth/10)*4 < i and i < (screenWidth/10)*5){
                  ofSetColor(233, 216, 166);
                  if (radius < 0.5 and dsound5.isPlaying() == 0){
                      dsound5.play();
                  }
              }
              if ((screenWidth/10)*5 < i and i < (screenWidth/10)*6){
                  ofSetColor(238, 155, 0);
                  if (radius < 0.5 and dsound6.isPlaying() == 0){
                      dsound6.play();
                  }
              }
              if ((screenWidth/10)*6 < i and i < (screenWidth/10)*7){
                  ofSetColor(202, 103, 2);
                  if (radius < 0.5 and dsound7.isPlaying() == 0){
                      dsound7.play();
                  }
              }
              if ((screenWidth/10)*7 < i and i < (screenWidth/10)*8){
                  ofSetColor(187, 62, 3);
                  if (radius < 0.5 and dsound8.isPlaying() == 0){
                      dsound8.play();
                  }
              }
              if ((screenWidth/10)*8 < i and i < (screenWidth/10)*9){
                  ofSetColor(173, 32, 188);
                  if (radius < 0.5 and dsound9.isPlaying() == 0){
                      dsound9.play();
                  }
              }
              if ((screenWidth/10)*9 < i and i < screenWidth){
                  ofSetColor(155, 34, 38);
                  if (radius < 0.5 and dsound10.isPlaying() == 0){
                      dsound10.play();
                  }
              }
            ofDrawCircle(i, j, radius);
          }
        }
        ofSetColor(255);
        back.draw(0, 0, 60, 60);
    }
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
    if((x >= 0 && x <= 100) && (y >= 0 && 100)){
        if(mode == 1 || mode == 2){
            mode = 0;
        }
    }
    else if((x >= (screenWidth/4 + 10) && x <= screenWidth/4 + 210) && (y >= screenHeight/1.7 && screenHeight/1.7 + 100)){
        if(mode == 0){
            mode = 1;
        }
    }
    else if((x >= ((screenWidth/4)*2 + 40) && x <= (screenWidth/4)*2 + 240) && (y >= screenHeight/1.7 && screenHeight/1.7 + 100)){
        if (mode == 0) {
            mode = 2;
        }
    }
//    std::cout << "mode: " << mode << endl;
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
