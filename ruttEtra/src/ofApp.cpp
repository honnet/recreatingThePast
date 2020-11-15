#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void inline traceLines(unsigned int offset, float time){
   int width = 750;
   int height = 550;

    for (int i = 0; i < height; i+= 9){

        ofPolyline line;
        for (int j = 0; j < width; j++){

            float amplitude = ofNoise(0.01 * i,
                                      0.01 * j,
                                      offset,
                                      time);

            amplitude = (amplitude + offset) * 60;

            line.addVertex(j - width/2,
                           i - height/2,
                           amplitude);
        }
        line.draw();
    }
}


void ofApp::draw(){

    cam.begin();
    cam.enableOrtho();

    ofScale(-2, -2, 2);
    ofTranslate(0,120,0);
    ofRotateY(10);
    ofRotateX(75);

    float time = ofGetElapsedTimeMillis() / 2000.;

    ofSetColor(255);
    traceLines(0, time);
    traceLines(3, time);
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
