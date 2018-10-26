
#ifndef Vehicle_hpp
#define Vehicle_hpp
#include <stdio.h>
#include "ofMain.h"

class Vehicle{
    
public:
    void setup();
    void update();
    void draw();
    
    //take force and apply to vehicle
    void applyForce(ofPoint f);
    
    //movement to change direction - torque
    void steeringForce(ofPoint target);
    
    void steeringWithArriveForce(ofPoint target);
    
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
    //    float pos;
    float color;
    //    vector<Particle> particles;
    
};

#endif /* Vehicle_hpp */
