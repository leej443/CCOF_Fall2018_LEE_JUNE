#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(200);
    ofSetVerticalSync(true);
    ofBackground(0);
    //    ofLight light;
    ofEnableAlphaBlending();
    glEnable(GL_DEPTH_TEST);
    
    //load the first model
    model.loadModel("dust_L.3ds", 50);
    curFileInfo = ".3ds";
    model.setRotation(0, 180, 1, 0, 0);
    model.setScale(10,10,10);
    
    //cam & light settings
    cam.setDistance(700);
    light.setPosition(200, 300, 500);
    cameraOrbit = 0;
    cam.setDistance(700);
    
    //load model to a ofMesh
    mesh = model.getMesh(0);
    
    int numVerts = mesh.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        offsets.push_back(ofVec3f(ofRandom(0,10000), ofRandom(0,10000), ofRandom(0,10000)));
    }
    
   
    r = 2;
    
    maxSpeed = 1;
    maxForce = 0.1;
    ofSetBackgroundAuto(false);
    radius = 2;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //vertex animation
    int numVerts = mesh.getNumVertices();
    
    
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);
        mesh.addColor(ofFloatColor(ofRandom(.1,1),ofRandom(0,.7),ofRandom(.1,1.0), ofRandom(0,.5)));
        
        //        mesh.addColor(ofFloatColor(ofRandom(.1,1),ofRandom(.5,.7),ofRandom(.1,1.0), ofRandom(0,.5)));
        //
        //        mesh.addColor(ofFloatColor(ofRandom(.2,.5),ofRandom(.2,.6),ofRandom(.7,1), ofRandom(0,.3)));
        
        
        
        float time = ofGetElapsedTimef();
        float timeScale = 0.5;
        float displacementScale = 0.0009;
        ofVec3f timeOffsets = offsets[i];
        
        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        mesh.setVertex(i, vert);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // so the model isn't see through.
    ofEnableDepthTest();
    
    light.enable();
    
    cam.begin();
    
    
    ofPushMatrix();
    ofTranslate(-625, -500);
    ofScale(600);
    
    
    //    mesh.drawVertices(); //point mode
    //    mesh.drawWireframe();
    mesh.drawFaces();
    ofPopMatrix();
    
    cam.end();
    light.disable();
    ofDisableDepthTest();
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a'){
        ofSetBackgroundAuto(true);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'a'){
        ofSetBackgroundAuto(false);
    }
}

