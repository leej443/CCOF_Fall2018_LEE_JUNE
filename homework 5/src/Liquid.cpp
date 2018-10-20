#include "Liquid.hpp"
//--------------------------------------------------------------
void Liquid::setup(float _x, float _y, float _w, float _h, float _c){
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    c = _c;
}

//--------------------------------------------------------------
void Liquid::draw(){
    ofSetColor(0,30);
//    ofDrawRectangle(x, y, w, h);
}
