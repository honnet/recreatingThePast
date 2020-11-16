#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void inline traceLines(float time, float period){
    int width = 750;
    int height = 550;

    for (int i = 0; i < height; i+= 9){

        ofPolyline line;
        for (int j = 0; j < width; j++){

            float amplitude = 45 * (ofNoise(0.01 * i,
                                            0.01 * j,
                                            3*time) - 0.5);

            amplitude *= period * period; // make it breath

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

    float factor = 0.8;
    ofScale(-factor, -factor, factor);
    ofRotateY(10);
    ofRotateX(75);

    float time = ofGetElapsedTimeMillis() / 1000.;
    float period = sin(3 * time);
    static float prevPeriod = 0;

    traceLines(time, period);
    cam.end();

    // screenshot code:
    if (period <= 0) {
        static int cnt = 0;
        std::string padded_cnt = to_string(cnt);
        if (cnt < 10)
            padded_cnt = std::string("00").append( to_string(cnt) );
        else if (cnt < 100)
            padded_cnt = std::string("0").append( to_string(cnt) );

        static ofImage screenshot;
        screenshot.grabScreen(0, 0, ofGetWindowWidth(),ofGetWindowHeight());
        if (cnt > 0)
            screenshot.save("screenshot" + padded_cnt + ".png");
        cnt++;
    }

    if (prevPeriod < 0  &&  period >= 0)
        std::exit(0);

    prevPeriod = period;
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
