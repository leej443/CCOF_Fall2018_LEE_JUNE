#pragma once

#include "ofMain.h"
#include "Vehicle.hpp"
#include "VectorField.hpp"

#define TOTALNUM 200

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    VectorField vf;
    
    vector<Vehicle> objects;
};
