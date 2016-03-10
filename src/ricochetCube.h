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
#include "vibration.h"

class ricochetCube{
    public:
        // Constructor
        ricochetCube(ofPoint _pos, int _id, vector<vibration>& _vibrations);

        // VARS
        int cubeId;
        bool contactZoneShowed = false;
        ofPoint pos;
    
        int lowV = 0;
        int mediumV = 0;
        int hightV = 0;
    
        vector<vibration>* vibrations;

        // METHODS
        void draw();
        void moveTo(ofPoint _pos);
        void play();
        void loadSound(string soundPath);
        bool pointIsInside(ofPoint _pointPos);

    private:
        // VARS
        int faceId;
        int size = 50;
        float contactArea = 180;

        ofColor color;
        ofSoundPlayer cubeSound;
    
        vector<ofColor> colors;

        // METHODS
};

#endif /* ricochetCube_h */
