#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"


class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    
    ofxAssimpModelLoader model;
    string curFileInfo;
    
    ofEasyCam cam;
    float cameraOrbit;
    ofLight light;
    
    ofMesh mesh;
    vector<ofVec3f> offsets;
    
    ofPoint loc;
    ofPoint vel;
    ofPoint acc;
    ofPoint pos;
    
    float r;
    float maxSpeed;
    float maxForce;
    
    float angle;
    float radius;
    float bornTime;
    float color;
    
    
    
    
};

