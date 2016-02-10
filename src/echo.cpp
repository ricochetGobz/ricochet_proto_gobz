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
    size += expandIncrement;
}

bool echo::souldRemoved() {
    return (size > maxSize);
}

//--------------------------------------------------------------
bool echo::checkCubeCollision(ofPoint _cubePos){    
    float _dist = ofDist( pos.x, pos.y, _cubePos.x, _cubePos.y);
    
    cout << _dist << endl;
    
    if(size >= _dist){
        return true;
    }
    
    return false;
}