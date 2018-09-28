#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    
    gui.add(radius.setup("radius", 140, 10, 500));
    
    gui.add(earthSize.setup("earthSize", 0, 0, 500));
    gui.add(moonSize.setup("moonSize", 0, 0, 500));
    
    gui.add(sunPosX.setup("sunPosX", 0, 0, 500));
    gui.add(sunPosY.setup("sunPosY", 30, 0, 500));
    
    
    
    gui.add(red.setup("red", 0, 0, 255));
    gui.add(green.setup("green", 60, 0, 255));
    gui.add(blue.setup("blue", 255, 0, 255));
    gui.add(transparency.setup("transparency",40, 40,100));
    
    
    gui.add(toggle.setup("toggle", true));
    gui.add(button.setup("button"));
            
    ofBackground(255);
    ofEnableSmoothing();
    ofSetCircleResolution(50);
    

//
    //Earth
    earthPos.set(0,0);
    earthSize = 20;
    radiusOfEarthMovement = 300;
    
    //Moon
    moonPos.set(0,0);
    moonSize = 5;
    radiusOfMoonMovement = earthSize + 10;
    
    //angle
    angle = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    //    SUN
    sunPos.set(sunPosX, sunPosY);
    
    //earth movement
    earthPos.x = sunPosX + cos(angle) * radiusOfEarthMovement;
    earthPos.y = sunPosY + sin(angle) * radiusOfEarthMovement;
    
    //moon movement
    //    ofPoint moonShouldBeOrbitingAroundThis;
    //    moonShouldBeOrbitingAroundThis.set(earthPos.x, earthPos.y);
    //
    
    moonPos.x = earthPos.x + cos(-(angle+30)) * radiusOfMoonMovement;
    moonPos.y = earthPos.y + sin(-(angle+30)) * radiusOfMoonMovement;
    
    
    //update angle by 1 degree per frame
    angle += ofDegToRad(1);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawCircle(sunPosX, sunPosY, radius);
    gui.draw();
    
    ofSetColor(red, green, blue, transparency);
    
    //Draw Earth
    ofDrawCircle(earthPos, earthSize);
    
    //Draw Moon
    ofDrawCircle(moonPos, moonSize);
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
