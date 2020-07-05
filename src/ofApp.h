#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxImageSequenceRecorder.h"

class Walker {
public:
    Walker(float boundaryX, float boundaryY, float startX, float startY, ofColor color, float speedFactor){
        this->boundaryX = boundaryX;
        this->boundaryY = boundaryY;
        this->velocityX = ofRandom(-2, 2);
        this->velocityY = ofRandom(-2, 2);
        this->line.addVertex(startX, startY);
        this->lastX = startX;
        this->lastY = startY;
        this->color = color;
        this->speedFactor = speedFactor;
    }
    
    void update(){
        if (!isInBoundaries()){
            return;
        }
        
        if (ofGetFrameNum() % ((int) (1 / speedFactor)) == 0){
            velocityX += (ofNoise(lastX * 0.005, lastY * 0.005) - 0.5) * 2.0 ;
            velocityY += abs((ofNoise(lastY * 0.005, lastX * 0.005) - 0.5) * 2.0) ;
        }
        
        lastX += velocityX * speedFactor;
        lastY += velocityY * speedFactor;
        line.addVertex(lastX, lastY);
    }
    
    bool isInBoundaries(){
        return lastX > 0  && lastX < boundaryX && lastY > 0 && lastY < boundaryY;
    }
    
    void draw() {
        ofSetColor(color);
        line.draw();
    }
    
    
private:
    int boundaryX, boundaryY;
    float velocityX, velocityY;
    float lastX, lastY;
    ofColor color;
    ofPolyline line;
    float speedFactor;
};

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void exit();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    vector<Walker> walkers;
    
    ofxFloatSlider speedFactorSlider;
    ofxIntSlider walkersCountSlider;
    ofxIntSlider colorHueSlider;
    ofxIntSlider colorSatSlider;
    ofxIntSlider colorBrightnessSlider;
    ofxIntSlider colorAlphaSlider;
    ofxIntSlider colorRandomnessSlider;
    ofxPanel gui;
    
    // recording
    ofxImageSequenceRecorder recorder;
    ofImage screenCapture;
};



