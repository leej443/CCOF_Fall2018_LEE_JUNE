//
//  Vehicle.cpp
//  00-Seek
//
//  Created by Qinzi Tan on 10/18/18.
//

#include "Vehicle.hpp"
//--------------------------------------------------------------
void Vehicle::setup(float _x, float _y){
    loc.set(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
//    loc.set(ofRandomWidth(), ofRandomHeight());
    vel.set(0, 0);
    acc.set(0, 0);
    
    r = ofRandom(-3,1);
 
    
    maxSpeed = ofRandom(.2,.5);
    maxForce = .2;
    
}

//--------------------------------------------------------------
void Vehicle::update(){
    vel += acc;
    vel.limit(maxSpeed);
    loc += vel;
    acc *= 0;
    
    float t = ofGetElapsedTimef();
    float noiseOutput = ofNoise(t * .5);
//    radius = ofMap(noiseOutput,
//                   0,
//                   1,
//                   70,
//                   10);
    
//    angle += ofDegToRad(1);
}

//---------------------    ----------------------------------------
void Vehicle::draw(){
    float angle = atan2(vel.y, vel.x);
    float heading2D = ofRadToDeg(angle) + 90;
     ofSetColor(255, ofRandom(2,8));
//    ofSetColor(ofRandom(100,250),ofRandom(100,200), ofRandom(0,170), ofRandom(2,10));
//        ofFill();
//
    ofPushMatrix();
    
    
    ofEnableAlphaBlending();
    ofPushMatrix();
    ofTranslate(loc.x, loc.y);
    ofRotateZDeg(heading2D);
    ofBeginShape();
    ofVertex(r, -r*2);
    ofVertex(-r, r*2);
    ofVertex(r, r*2);
    ofEndShape(true);
    ofPopMatrix();
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void Vehicle::applyForce(ofPoint force){
    acc += force;
}

void Vehicle::follow(VectorField vf){
    
    ofPoint desired = vf.getForce(loc / ofRandom(2,5));
    
    desired *= maxSpeed;
    
    ofPoint steer = desired - vel;
    steer.limit(maxForce);
    applyForce(steer);
}
