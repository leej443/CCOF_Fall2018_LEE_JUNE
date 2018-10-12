//
//  Attractor.hpp
//  Explosion
//
//  Created by June Lee on 2018-10-05.
//

#ifndef Attractor_hpp
#define Attractor_hpp

#include "ofMain.h"


class Attractor {
    
public:
    void setup(ofPoint _pos, float _radius, float _angle, float _vel);
    void update(float _updatedRadius);
    void draw();
    
    ofPoint pos;
    float radius;
    float angle;
    float vel;
    float _updatedRadius;
    
};

#endif /* Attractor_hpp */
