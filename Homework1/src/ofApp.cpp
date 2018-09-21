#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    
    //(1-pct) x origin + pct x destination
    origin = ofPoint(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
 
    dest = ofPoint (ofGetWindowWidth(), ofGetWindowHeight());
    
    objectPos = origin;
    pct = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
   for(int i = 0; i<100; i++){
    //achieve 0.5 percent more of the journey per frame
    pct += .2;

    if(pct > 1) pct = 0;

//
//    // powf (float1, float2);
//    // float 1 (base percentage)
//    // float 2 (exponent)
//    float pctPowerOutput = powf(pct, 2);
//    objectPos = (1-pctPowerOutput) * origin + pctPowerOutput * dest;
}
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    for(int i = 0; i<500; i++){
        
//    float size = powf(ofRandom(0,4),3);
    float size = powf(ofRandom(1,700),sin(ofRandom(2,20)));
    
    ofDrawCircle(objectPos, size);
    ofSetColor(ofRandom(50,250), powf(pct,sin(ofRandom(2,20))), powf(ofRandom(1,20),2), ofRandom(0,40));
            
    if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)){
    ofSetColor(ofRandom(10,150), ofRandom(10,250), powf(ofRandom(10,100),2), ofRandom(0,40));
        }
    }
  

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
