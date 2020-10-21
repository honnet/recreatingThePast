#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sprites.load("./sprites.png"); // see in ./bin/data

	int h = sprites.getHeight();
    photo.cropFrom(sprites, h*3,0, h,h);
    photo.resize(100, 100);

    sprites.resize(diameter*sprite_num, diameter);
	h = sprites.getHeight();
    for (int i = 0; i < sprite_num; i++) {
        sprite[i].cropFrom(sprites, h*i,0, h,h);
    }

	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    static ofImage crop;
    int speed = ofMap(mouseX, 0, ofGetWidth(), 0, 10);
    int offset = (speed * ofGetElapsedTimeMillis()/100 -1) % sprite_num;

	int w = photo.getWidth();
	int h = photo.getHeight();
	for(int y = 0; y < h; y++) {
		for(int x = 0; x < w; x++) {

			ofColor cur = photo.getColor(x, y);
			int id = (sprite_num - 1) * (1 - cur.getBrightness() / 255.0);
            id = (id + offset) % sprite_num;

            sprite[id].draw(x*diameter, y*diameter);
		}
	}
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
