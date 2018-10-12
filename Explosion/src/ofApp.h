#pragma once

#include "ofMain.h"
#include "Attractor.hpp"
#include "Particle.hpp"

#define SEGMENT 6
#define TAIL 40

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    vector<Attractor> attractors;
    vector<Particle> particles;
    
    float radius;
 
    float rMin;
    float rMax;
    
    float rPct = 0;
    float rPctVel = 0.005;
    
};
