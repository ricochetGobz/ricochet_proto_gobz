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
ricochetCube::ricochetCube(ofPoint _pos){
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    size = 50;
    pos = _pos;
}
void ricochetCube::loadSound(string soundPath){
        cubeSound.load(soundPath);
}

void ricochetCube::moveTo(ofPoint _pos){
    pos = ofPoint( _pos.x - size/2, _pos.y - size/2);
    cout << " Cube Moved" << endl;
}

void ricochetCube::draw(){
    ofFill();
    ofSetColor(100,250,100);
    ofDrawRectangle(pos,size,size);

}

void ricochetCube::play(){
    cubeSound.play();
}

bool ricochetCube::pointIsInside(ofPoint pointPos){
    
    float _dist = ofDist(pos.x+(size/2), pos.y+(size/2), pointPos.x, pointPos.y);
    if(_dist < size/2){
        return true;
    }
    return false;
}