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
    void moveTo(int _x, int _y);
    void clicked(int _x, int _y );
    void draw();
    int posX;
    int posY;
    ofColor color;
};

#endif /* ricochetCube_h */
