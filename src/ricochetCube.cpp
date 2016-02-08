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
void ricochetCube::(string soundPath){
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