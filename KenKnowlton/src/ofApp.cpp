#include "ofApp.h"

void ofApp::initPics(){
 	photo.load("./photo.jpg"); // see in ./bin/data
    int size = 1000/diameter;
    photo.resize(size, size);

	sprites.load("./sprites.png"); // see in ./bin/data
    sprites.resize(diameter*sprite_num, diameter);
	int h = sprites.getHeight();
    for (int i = 0; i < sprite_num; i++) {
        sprite[i].cropFrom(sprites, h*i,0, h,h);
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    initPics();

	ofBackground(0);
}


//--------------------------------------------------------------
void ofApp::draw(){
    static ofImage crop;
    int threshold = ofMap(mouseX, 0, ofGetWidth(), 0, sprite_num);
    int offset = sprite_num - (ofGetElapsedTimeMillis()/100) % sprite_num;

	int w = photo.getWidth();
	int h = photo.getHeight();
	for(int y = 0; y < h; y++) {
		for(int x = 0; x < w; x++) {

			ofColor cur = photo.getColor(x, y);
			int id = (sprite_num - 1) * (1 - cur.getBrightness() / 255.0);

            if (id >= sprite_num - threshold)
                id = (id + offset) % sprite_num;

            sprite[id].draw(x*diameter, y*diameter);
		}
	}

    if (saveGif) {
        static ofImage screenshot;
        static int prev_offset = 0;
        if (prev_offset != offset) {
            prev_offset = offset;
            screenshot.grabScreen(0, 0, 1000,1000);
            screenshot.save("screenshot" + to_string(offset) + ".png");
            cout << "screenshot" + to_string(offset) + ".png" << endl;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    static int y_old = y;

    if (y_old != y){
        y_old  = y;
        diameter = ofMap(y, 0,ofGetWidth(), 10, 50);
        initPics();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's' || key == 'S')
        saveGif = !saveGif; // Toggle save mode
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
