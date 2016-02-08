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
    void moveTo(ofPoint _pos);
    void clicked(ofPoint _pos);
    void loadSound(string soundPath);
    void play();
    void draw();
    int id;
    int faceId;
    ofPoint pos;
    ofColor color;
    ofSoundPlayer cubeSound;
};

#endif /* ricochetCube_h */
