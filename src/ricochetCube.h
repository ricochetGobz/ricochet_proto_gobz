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
    ricochetCube(ofPoint _pos, int _id);
    
    // Methods
    void draw();
    void moveTo(ofPoint _pos);
    void loadSound(string soundPath);
    void play();
    bool pointIsInside(ofPoint _pointPos);
    ofPoint getPos();
    int cubeId;
    int faceId;
    int size = 50;
    ofPoint pos;
    ofColor color;
    ofSoundPlayer cubeSound;
};

#endif /* ricochetCube_h */
