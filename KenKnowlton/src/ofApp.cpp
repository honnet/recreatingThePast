#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sprites.load("./sprites.png"); // see in ./bin/data
	photo.load("./photo.png"); // see in ./bin/data
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    photo.resize(100, 100);
	int w = photo.getWidth();
	int h = photo.getHeight();
	float diameter = 10;
	for(int y = 0; y < h; y++) {
		for(int x = 0; x < w; x++) {
			ofColor cur = photo.getColor(x, y);
			float size = cur.getBrightness() / 255;
			ofDrawCircle(x * diameter,
                         y * diameter,
                         1 + size * diameter / 2);
		}
	}

    static ofImage crop;
    int id = (ofGetElapsedTimeMillis()/100) % 8;
    crop.cropFrom(sprites, 128*id,0, 128,128);
    crop.resize(32, 32);
  	crop.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
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
