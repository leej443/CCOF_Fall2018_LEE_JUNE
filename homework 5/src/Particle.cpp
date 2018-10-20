#include "Particle.hpp"

//--------------------------------------------------------------
void Particle::setup(){
    mass = ofRandom(1, 15);
    loc.set(ofRandom(200), ofRandom(200));
    vel.set(ofRandom(10), ofRandom(10));
    acc.set(10, 100);
}

//--------------------------------------------------------------
void Particle::applyForce(ofPoint _f){
    acc += _f/mass;
}

//--------------------------------------------------------------
void Particle::addGravityForce(float _g){
    ofPoint gravity;
    gravity.set(0, _g * mass);
    
    applyForce(gravity);
}

//--------------------------------------------------------------
void Particle::addDragForce(Liquid _l){
    float speed = vel.length()/2;
    float dragMagnitude = _l.c * speed * speed;
    
    ofPoint dragDirection = vel;
    dragDirection *= -1;
    dragDirection.normalize();
    
    ofPoint dragForce = dragMagnitude * dragDirection;
    
    applyForce(dragForce);
}

//--------------------------------------------------------------
bool Particle::insideWater(Liquid _l){
    if(loc.x > _l.x
       && loc.x < _l.x + _l.w
       && loc.y/2 > _l.y
       && loc.y/2 < _l.y + _l.h
       )
    {
        return true;
    } else {
        return false;
    }
}

//--------------------------------------------------------------
void Particle::update(){
    checkEdges();
    
    vel += acc;
    loc += vel;
    
    acc.set(0, 0);
}

//--------------------------------------------------------------
void Particle::draw(){
    ofSetColor(ofRandom(20,200), ofRandom(5,100), ofRandom(20,150), 30);
    ofDrawCircle(loc.x, loc.y, mass * 20);
}

//--------------------------------------------------------------
void Particle::checkEdges(){
    if(loc.x > ofGetWindowWidth()/2){
        loc.x = ofGetWindowWidth()/2;
        vel.x *= -0.05;
    } else if(loc.x < 0){
        loc.x = 0;
        vel.x *= 0.15;
    }
    
    if(loc.y > ofGetWindowHeight()/2){
        loc.y = ofGetWindowHeight()/2;
        vel.y *= 0.07;
    }
    
   
}
