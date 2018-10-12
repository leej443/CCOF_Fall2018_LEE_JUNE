#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(50);
    radius = 100;
    
    ofSetFrameRate(60);
    
    rMin = 5;
    rMax = 200;

    // each attractor/loop has multiple particles
    
    for(int i = 0; i < SEGMENT; i++){
        //360/SEGMENT - 90
        //initialize attractor
        float angle = ofDegToRad((360/SEGMENT) * i);
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        
        Attractor a;
        a.setup(ofPoint(ofGetWindowWidth()/2 + x, ofGetWindowHeight()/2 + y), radius, angle, 0.01);
        attractors.push_back(a);
        
        //initialize particles following attractor
        for(int t = 0; t < TAIL; t++){
            
            Particle p;
            p.init(a.pos);
            particles.push_back(p);
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
//    radius += 0.01;
    if(rPct > 1){
        rPct = 1;
        rPctVel *= -1;
    }
    
    if(rPct < 0){
        rPct = 0;
        rPctVel *= -1;
    }
    
    rPct += rPctVel;
    float rPctOut = powf(rPct, 3);
    radius = (1-rPctOut) * rMin + rPctOut * rMax;
    
    for (int i = 0; i<attractors.size(); i++){
        attractors[i].update(radius);
        
        for(int t = TAIL * i; t < TAIL * i + TAIL; t++){
             particles[t].updateParticle(attractors[i].pos);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i<attractors.size(); i++){
        attractors[i].draw();
        for(int t = TAIL * i; t < TAIL * i + TAIL; t++){
            
            particles[t].drawParticle();
        }
    }

}

//--------------------------------------------------------------
