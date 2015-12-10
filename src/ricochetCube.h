//
//  ricochetCube.h
//  ricochet_proto_echo
//
//  Created by Arthur Robert on 10/12/15.
//
//

#ifndef ricochetCube_h
#define ricochetCube_h

#include "ofMain.h"

class ricochetCube{
public:
        // Constructor
    ricochetCube();
    
        // Methods
    void moveTo();
    void draw();
    int x;
    int y;
    ofColor color;
};

#endif /* ricochetCube_h */
