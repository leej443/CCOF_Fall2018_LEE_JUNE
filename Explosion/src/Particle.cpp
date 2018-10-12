//
//  Particle.cpp
//  EasingAttractor
//
//  Created by June Lee on 2018-10-05.
//

#include "Particle.hpp"
void Particle::init(ofPoint _pos){
    pos.set(_pos.x, _pos.y);

    float velMin = 0.0001;
    float velMax = 0.002;
    float randomVel = ofRandom(velMin, velMax);
    vel.set(randomVel, randomVel);
    activated = false;
    brightness = 70;
}

//everytime updateparticle is called, you will be passing something
void Particle::updateParticle(ofPoint _attractor){
    dist = ofDist(pos.x, pos.y, _attractor.x, _attractor.y);
//    cout<<dist<<endl;
    if(dist<100){
        activated = true;
    }
    
    if(activated){
    
        pct += vel;
        
        //float: (1-pct.x) * currentPos.x + pct.x * dest.x;
        //float: (1-pct.y) * currentPos.y + pct.y * dest.y;
        //ofPoint:(1-pct) * currentPos + pct * dest;
        pos = (ofPoint(1,1) - pct) * pos + pct * _attractor;
        
        if(brightness<253){
            brightness += 2;
        }
    }
    
}

void Particle::drawParticle(){
    ofSetColor(255);
    ofDrawCircle(pos,1);
}
