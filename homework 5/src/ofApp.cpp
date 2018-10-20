#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    ofSetCircleResolution(50);
    
    for(int i = 0; i<TOTALNUM; i++){
        Particle p;
        p.setup();
        particles.push_back(p);
    }
    
    liquid.setup(ofRandom(200),
                 ofRandom(200), ofRandom(200), ofRandom(200), .5);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofPoint wind;
    wind.set(0.01, 2);
    
    for(int i = 0; i<TOTALNUM; i++){
        particles[i].applyForce(wind);
        particles[i].addGravityForce(0.08);
        
        if(particles[i].insideWater(liquid)){
            particles[i].addDragForce(liquid);
        }
        
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i<TOTALNUM; i++){
        particles[i].draw();
    }
    
    liquid.draw();
}

void ofApp::mousePressed(int x, int y, int button){
    for(int i = 0; i<TOTALNUM; i++){
        particles[i].draw();
    }
    
    liquid.draw();
    
}
