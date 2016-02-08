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
    ricochetCube(ofPoint _pos);
    
        // Methods
    void moveTo(ofPoint _pos);
    void loadSound(string soundPath);
    void play();
    void draw();
    bool pointIsInside(ofPoint _pointPos);
    int id;
    int faceId;
    int size;
    ofPoint pos;
    ofColor color;
    ofSoundPlayer cubeSound;
};

#endif /* ricochetCube_h */
