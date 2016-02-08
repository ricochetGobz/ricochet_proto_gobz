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
    ofPoint pos;
    int size ;
    int fromCube;
    ofColor color;
};

#endif /* echo_h */
