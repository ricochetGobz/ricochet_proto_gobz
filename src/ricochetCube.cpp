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

//--------------------------------------------------------------
ricochetCube::ricochetCube(ofPoint _pos, int _id){
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    pos = _pos;
    cubeId = _id;
}

//--------------------------------------------------------------
void ricochetCube::draw(){
    ofFill();
    ofSetColor(100,250,100);
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
}

//--------------------------------------------------------------
void ricochetCube::moveTo(ofPoint _pos){
    pos = ofPoint( _pos.x, _pos.y);
    cout << " Cube Moved" << endl;
}

//--------------------------------------------------------------
void ricochetCube::play(){
    cubeSound.play();
}

//--------------------------------------------------------------
bool ricochetCube::pointIsInside(ofPoint pointPos){
    
    float _dist = ofDist(pos.x, pos.y, pointPos.x, pointPos.y);
    if(_dist < size/2){
        return true;
    }
    return false;
}