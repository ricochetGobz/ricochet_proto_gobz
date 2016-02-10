//
//  echo.cpp
//  ricochet_proto_echo
//
//  Created by Arthur Robert on 10/12/15.
//
//

#include <stdio.h>
#include "echo.h"

//--------------------------------------------------------------
echo::echo(ofPoint _pos){
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    pos = _pos;
}

//--------------------------------------------------------------
void echo::draw(){
    ofNoFill();
    ofDrawCircle(pos.x, pos.y, size);
}

//--------------------------------------------------------------
void echo::expand(){
    
    expandForce = (sizeMax - size) * vel;
    size += expandForce;
    
    //size += 4;
}

bool echo::souldRemoved() {
    
    return (expandForce < 0.9);
    //return (size > sizeMax);
}

//--------------------------------------------------------------
bool echo::checkCubeCollision(ofPoint _cubePos){
    float _dist = ofDist( pos.x, pos.y, _cubePos.x, _cubePos.y);
    
    return (size >= _dist);
}