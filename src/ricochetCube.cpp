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
ricochetCube::ricochetCube(){
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    size = 50;
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

void ricochetCube::clicked(ofPoint _pos){
    

}
void ricochetCube::play(){
    cubeSound.play();
    

}

bool ricochetCube::pointIsInside(ofPoint p){
    
    float _dist = ofDist(pos.x+(size/2), pos.y+(size/2), p.x, p.y);
    if(_dist < size/2){
        return true;
    }
    return false;
}