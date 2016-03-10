//
//  ricochetCube.cpp
//  ricochet_proto_echo
//
//  Created by Arthur Robert on 10/12/15.
//
//

#include <stdio.h>
#include "ricochetCube.h"
#include "echo.h"
#include "vibration.h"

//--------------------------------------------------------------
ricochetCube::ricochetCube(ofPoint _pos, int _id, vector<vibration>& _vibrations){
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    pos = _pos;
    cubeId = _id;
    vibrations = &_vibrations;
    
    colors.push_back(*new ofColor(143, 202, 217));
    colors.push_back(*new ofColor(193, 243, 221));
    colors.push_back(*new ofColor(236, 210, 234));
    colors.push_back(*new ofColor(129, 233, 158));
    colors.push_back(*new ofColor(229, 131, 217));
    colors.push_back(*new ofColor(89, 166, 212));
}

//--------------------------------------------------------------
void ricochetCube::draw(){
    ofFill();
    ofSetColor(colors[cubeId % 6]);
    ofPoint posMid;
    posMid.x = pos.x - size /2;
    posMid.y = pos.y - size/2;
    ofDrawRectangle(posMid,size,size);

    ofNoFill();
    if(contactZoneShowed){
        ofDrawCircle(pos.x, pos.y, contactArea);
    }
}

//--------------------------------------------------------------
void ricochetCube::loadSound(string soundPath){
    cubeSound.load(soundPath);
    int note = cubeId % 6;
    lowV = 255 - (note * 51);
    hightV = note * 51;
    
//    if(lowV > hightV)
//        mediumV = (cubeId % 3) * 51;
//    else
//        mediumV = 255 - ((cubeId % 3) * 51);
}

//--------------------------------------------------------------
void ricochetCube::moveTo(ofPoint _pos){
    pos = ofPoint( _pos.x, _pos.y);
    cout << " Cube Moved" << endl;
}

//--------------------------------------------------------------
void ricochetCube::play(){
    cubeSound.play();
    cout <<  "play" << endl;
    (*vibrations)[0].setVibration(lowV);
    (*vibrations)[1].setVibration(mediumV);
    (*vibrations)[2].setVibration(hightV);
}

//--------------------------------------------------------------
bool ricochetCube::pointIsInside(ofPoint pointPos){
    
    float _dist = ofDist(pos.x, pos.y, pointPos.x, pointPos.y);
    if(_dist < size/2){
        return true;
    }
    return false;
}