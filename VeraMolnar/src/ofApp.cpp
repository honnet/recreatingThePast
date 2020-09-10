#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    ofSetColor(0); // black lines
}

//--------------------------------------------------------------
void ofApp::draw(){
    static const int numOfColumns = 30;
    static const int h = ofGetHeight();
    static const int w = ofGetWidth();
    static const int step = w / numOfColumns;
    static const float angleRange = ofDegToRad(20);
    static const float angleOffset = ofDegToRad(35);

    for (int j = step; j < h; j += 2*step/3){
        for (int i = step/3; i < w-2*step/3; i += step/2){

            float thicknessPyramid = (i < w / 2)? i : w - i ;
            float offset = 20.0 * thicknessPyramid / float(w);
            float thickness = offset + ofRandom(0.2, 1.0);
            ofSetLineWidth(thickness);

            int x = cos(angleOffset + ofRandom(angleRange)) * step;
            int y = sin(angleOffset + ofRandom(angleRange)) * step;

            ofDrawLine(  i,     j,        // starting point
                         i + x, j - y  ); // ending point

            // draw circles to make round cap at lines ends:
            ofDrawCircle(i,     j,     thickness/2);
            ofDrawCircle(i + x, j - y, thickness/2);
        }
    }
}
