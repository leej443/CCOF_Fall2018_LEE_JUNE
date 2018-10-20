#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Liquid.hpp"

#define TOTALNUM 100

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void mousePressed(int x, int y, int button);
    
    vector<Particle> particles;
    Liquid liquid;
};
