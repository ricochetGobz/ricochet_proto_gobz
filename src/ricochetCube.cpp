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
    
}
void ricochetCube::loadSound(string soundPath){
        cubeSound.load(soundPath);
}

void ricochetCube::moveTo(ofPoint _pos){
    pos =_pos;
    cout << " Cube Moved" << endl;
}

void ricochetCube::draw(){
    ofFill();
    ofSetColor(100,250,100);
    ofDrawRectangle(pos,50,50);

}

void ricochetCube::clicked(ofPoint _pos){
    

}
void ricochetCube::play(){
    cubeSound.play();
    

}