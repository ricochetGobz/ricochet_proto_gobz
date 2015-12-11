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
    echo();
    
    // Methods
    void expand();
    void draw();
    int x;
    int y;
    int size ;
    ofColor color;
};

#endif /* echo_h */
