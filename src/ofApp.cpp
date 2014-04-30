#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    jaOn.loadImage("images/jaOn.jpg");
    jaOff.loadImage("images/jaOff.jpg");
    ofSetFrameRate(30);
    //ofSetBackgroundAuto(false);
    
    
    for (int j = 0; j < 4; j++) {
        speed[j] = ofRandom(0.2, 2);
        for (int i = 0; i < 12; i++) {
            steps[(i*4)+j].set(j*256, i*70, 256, 70);
            bStepMode[(i*4)+j] = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    


}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int j = 0; j < 4; j++) {
        
        for (int i = 0; i < 12; i++) {
            
            if (bStepMode[(i*4)+j]){
                jaOn.draw(steps[(i*4)+j]);
            }
            else{
                jaOff.draw(steps[(i*4)+j]);
            }
            
            steps[(i*4)+j].y -= speed[j];
            
            if (steps[(i*4)+j].y < -70){
                bStepMode[(i*4)+j] = false;
                steps[(i*4)+j].y += 840;
            }
        }
    
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
    
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 12; i++) {
            if(steps[(i*4)+j].inside(x, y)){
                bStepMode[(i*4)+j] = !bStepMode[(i*4)+j];
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
