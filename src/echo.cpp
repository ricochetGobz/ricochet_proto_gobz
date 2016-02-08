//
//  echo.cpp
//  ricochet_proto_echo
//
//  Created by Arthur Robert on 10/12/15.
//
//

#include <stdio.h>
#include "echo.h"

echo::echo(ofPoint _pos){
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    pos = _pos;
    size =5;
    
}
void echo::draw(){
    ofNoFill();
    ofDrawCircle(pos.x+25, pos.y+25, size);
    
}

void echo::expand(){
    size +=3;

}