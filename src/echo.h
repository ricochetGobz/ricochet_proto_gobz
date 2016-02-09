//
//  echo.h
//  ricochet_proto_echo
//
//  Created by Arthur Robert on 10/12/15.
//
//

#ifndef echo_h
#define echo_h
#include "ofMain.h"

class echo{
public:
    // Constructor
    echo(ofPoint _pos, int _fromCube);
    
    // Methods
    void expand();
    void draw();
    bool hitCube(ofPoint cubePos);
    ofPoint pos;
    int fromCube;
    int parent;
    int size ;
    ofColor color;
    
};

#endif /* echo_h */
