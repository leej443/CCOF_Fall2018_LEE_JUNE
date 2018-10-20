
#ifndef Particle_hpp
#define Particle_hpp

#include "ofMain.h"
#include "Liquid.hpp"

class Particle {
    
public:
    void setup();
    void update();
    void draw();
    
    void applyForce(ofPoint _f);
    void addGravityForce(float _g);
    
    void addDragForce(Liquid _l);
    
    void checkEdges();
    
    bool insideWater(Liquid _l);
    void mousePressed(int x, int y, int button);
    ofPoint loc;
    ofPoint vel;
    ofPoint acc;
    
    float mass;
    
};

#endif /* Particle_hpp */
