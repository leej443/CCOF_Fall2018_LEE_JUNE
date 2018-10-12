//
//  Particle.hpp
//  EasingAttractor
//
//  Created by June Lee on 2018-10-05.
//

#ifndef Particle_hpp
#define Particle_hpp

#pragma once

#include "ofMain.h"

class Particle{
    
public:
    void init(ofPoint _pos);
    void updateParticle(ofPoint _attractor);
    void drawParticle();
    

    ofPoint pos;
    ofPoint vel;
    ofPoint pct;
    
    float dist;
    bool activated;
    
    float brightness;
    
    
 
};


#endif /* Particle_hpp */
