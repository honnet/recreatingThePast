#include "ofApp.h"
#include "data.h"

//--------------------------------------------------------------
void ofApp::setup(){

    walkData.setup();
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    vector < ofPoint > pts = walkData.get3dDataForFrame( (int)(ofGetFrameNum()) % walkData.nFrames);
    static vector < ofPoint > pts_old = pts;

    //----------------------------- 3d
    cam.begin();
    //cam.enableOrtho();
    ofScale(4, 4, 4);
    ofRotateYDeg(45);

    for (int i = 0; i < pts.size(); i++){
        ofPoint diff = pts[i] - pts_old[i];
        ofPoint projection = pts[i] + 2*diff;

        ofSetColor(255);

        int select = ofMap(mouseX, 0,ofGetWindowWidth(), 0,pts.size()-2);
        if ( i != 7 && i != 15 && i != 19 && i != pts.size()-1 ) {
            ofDrawLine(pts[i], pts[i+1]);
        }

        ofDrawSphere(pts[i], 3 );

        ofSetColor(255,0,0);

        ofDrawLine(pts[i], projection);
        ofDrawSphere(projection, 3 );

        ofDrawSphere(pts_old[i], 3 );
    }
    pts_old = pts; // keep a copy

    cam.end();

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
