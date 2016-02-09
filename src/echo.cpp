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
    ofDrawCircle(pos.x +25, pos.y +25, size);
}

//--------------------------------------------------------------
void echo::expand(){
    size += 4;
}

//--------------------------------------------------------------
bool echo::checkCubeCollision(ofPoint _cubePos){    
    float _dist = ofDist( pos.x, pos.y, _cubePos.x+25, _cubePos.y+25);
    cout << _dist << endl;
    if(size >= _dist){
        return true;
    }
    
    return false;
}