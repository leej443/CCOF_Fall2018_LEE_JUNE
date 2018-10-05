#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    
    gui.add(radius.setup("radius", 140, 10, 500));
    gui.add(posX.setup("posX", 0, 0, 500));
    gui.add(posY.setup("posY", 30, 0, 500));
    gui.add(velFloat.setup("velFloat", 0, -1, 1));
    gui.add(age.setup("age", -10, -10, 10));
 
//    for(int i = 0; i < 10; i++){
//    particle p;
//    particles.push_back(p);
//    }
    
    for (int i = 0; i<10; i++){
        //preparing data
        particle p;
        p.pos.set (ofRandom(0,ofGetWindowWidth()), ofRandom(0,ofGetWindowHeight()));
        p.vel.set (ofRandom(-1,1), ofRandom(-1,1));
        p.radius = ofRandom(5,20);
        p.color = ofRandom(0xFFFFFF);
        
        //use data - put inside the vector
        particles.push_back(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
//    for(int i = 0; i<particles.size(); i++){
//        //particles[i].vel.set(velFloat);
//        
//        particles[i].pos += ofPoint(1,1);
//        
//        particles[i].color.a= ofMap(age, 0,1,255,0);
//        
//        if (age > 3){
//            particles.erase(particles.begin() + i);
//        }
//    }
    
    for(int i = 0; i<particles.size(); i++){
        particles[i].vel = ofPoint(ofRandom(0, velFloat));
        particles[i].pos += particles[i].vel;
        
        if (particles[i].pos.x > ofGetWindowWidth()-particles[i].radius) {
            particles[i].pos.x = ofGetWindowWidth() - particles[i].radius;
            particles[i].vel.x *= -1;
        }
        
        //left
        if (particles[i].pos.x < particles[i].radius) {
            particles[i].pos.x = particles[i].radius;
            particles[i].vel.x *= -1;
        }
        
        //bottom
        if (particles[i].pos.y > ofGetWindowWidth()-particles[i].radius) {
            particles[i].pos.y = ofGetWindowWidth() - particles[i].radius;
            particles[i].vel.y *= -1;
        }
        
        //top
        if (particles[i].pos.y < particles[i].radius) {
            particles[i].pos.y = particles[i].radius;
            particles[i].vel.y *= -1;
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i<particles.size(); i++){
        ofSetColor(particles[i].color);
        ofDrawCircle(particles[i].pos, radius);
    }
    
    gui.draw();
}
