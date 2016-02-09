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
    echo(ofPoint _pos);
    
    // Methods
    void expand();
    void draw();
    bool checkCubeCollision(ofPoint _cubePos);
    
    // Vars
    int size = 5;
    ofPoint pos;
    ofColor color;
};

#endif /* echo_h */
