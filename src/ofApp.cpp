#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    ofBackground(0);
    
    gui.setup();
    gui.add(speedFactorSlider.setup("speed", 1.0, -1.0, 1.0));
    gui.add(walkersCountSlider.setup("walkers", 100, 0, 500));
    gui.add(colorHueSlider.setup("hue", 110, 0,255));
    gui.add(colorSatSlider.setup("sat", 200, 0, 255));
    gui.add(colorBrightnessSlider.setup("brightness", 255, 0, 255));
    gui.add(colorAlphaSlider.setup("alpha", 200, 0, 255));
    gui.add(colorRandomnessSlider.setup("randomness", 50, 0, 255));
}

//--------------------------------------------------------------
void ofApp::update(){
    for (auto it = walkers.begin(); it != walkers.end(); it++){
        it->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (auto it = walkers.begin(); it != walkers.end(); it++){
        it->draw();
    }
    gui.draw();
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
    walkers.clear();
    for (int i = 0; i < walkersCountSlider; i++){
        walkers.push_back(Walker(ofGetWidth(), ofGetHeight(), x, y, ofColor::fromHsb((colorHueSlider + (int) ofRandom(colorRandomnessSlider)) % 255, colorSatSlider, colorBrightnessSlider, colorAlphaSlider), speedFactorSlider));
    }
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
