#ifndef Liquid_hpp
#define Liquid_hpp

#include "ofMain.h"

class Liquid {
    
public:
    void setup(float _x, float _y, float _w, float _h, float _c);
    void draw();
    void mousePressed(int x, int y, int button);
    float x,y,w,h;
    float c;
};

#endif /* Liquid_hpp */
