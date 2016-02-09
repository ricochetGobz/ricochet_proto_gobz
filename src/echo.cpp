//
//  echo.cpp
//  ricochet_proto_echo
//
//  Created by Arthur Robert on 10/12/15.
//
//

#include <stdio.h>
#include "echo.h"

echo::echo(ofPoint _pos, int _fromCube){
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    pos = _pos;
    fromCube = _fromCube;
    size = 5;
    
}
void echo::draw(){
    ofNoFill();
    ofDrawCircle(pos.x+25, pos.y+25, size);
    
}

void echo::expand(){
    size +=3;

}

bool echo::hitCube(ofPoint cubePos){
        float _dist = ofDist( pos.x, pos.y, cubePos.x+25, cubePos.y+25);
        if(size >= _dist){
            cout << _dist << endl;
            return true;
        }
        else return false;
}