#pragma once

#include "ofMain.h"
#include "particle.hpp"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    ofxPanel gui;
    ofxFloatSlider radius;
//    ofxFloatSlider vel;
    ofxFloatSlider velFloat;
    ofxFloatSlider age;
    
//  
//
    ofxFloatSlider posX;
    ofxFloatSlider posY;
 
   
    vector <particle> particles;
    
};
