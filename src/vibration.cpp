//
//  vibration.cpp
//  ricochet_proto_echo
//
//  Created by Boulay Jérémie on 09/03/2016.
//
//

#include "vibration.h"

//--------------------------------------------------------------
vibration::vibration(int _x, int _y){
    color.set(202, 230, 238);
    posx = _x;
    posy = _y;
}

//--------------------------------------------------------------
void vibration::draw(){
    ofFill();
    ofSetColor(color);
    ofDrawCircle(posx, posy, (2 + v));
}

//--------------------------------------------------------------
void vibration::update(int _vibration){
    v = _vibration;
}