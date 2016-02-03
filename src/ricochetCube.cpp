//
//  ricochetCube.cpp
//  ricochet_proto_echo
//
//  Created by Arthur Robert on 10/12/15.
//
//

#include <stdio.h>
#include "ricochetCube.h"

ricochetCube::ricochetCube(){
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    
}

void ricochetCube::moveTo(int _x, int _y ){
    posX = _x;
    posY = _y;
    cout << " Cube Moved" << endl;
}

void ricochetCube::draw(){
    ofFill();
    ofSetColor(100,250,100);
    ofDrawRectangle(posX-25,posY-25,50,50);

}

void ricochetCube::clicked(int _x, int _y){
    if( _x  > posX -25 &&  _x  < posX + 25  ){
        if( _y  > posY -25 &&  _y  < posY + 25  ){
            ofDrawRectangle(posX-30,posY-30,60,60);
        }
    }
     cout << " Cube Clicked" << endl;
}