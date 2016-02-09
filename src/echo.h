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
    echo(ofPoint _pos, vector<int> _cubeAlereadyTouched);
    
    // Methods
    void expand();
    void draw();
    bool hitCubeNeverToutched(ofPoint cubePos, int _cubeId);
    
    // Vars
    bool hitEnabled = true;
    int size = 5;
    ofPoint pos;
    ofColor color;
    vector<int> cubesTouched;
};

#endif /* echo_h */
