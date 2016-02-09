//
//  echo.cpp
//  ricochet_proto_echo
//
//  Created by Arthur Robert on 10/12/15.
//
//

#include <stdio.h>
#include "echo.h"

echo::echo(ofPoint _pos, vector<int> _cubeAlereadyTouched){
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
    pos = _pos;
    
    // copie de la liste des cubes déjà touché par la vague d'écho
    cubesTouched.assign(_cubeAlereadyTouched.begin(), _cubeAlereadyTouched.end());
}

void echo::draw(){
    ofNoFill();
    ofDrawCircle(pos.x +25, pos.y +25, size);
}

void echo::expand(){
    size += 4;
}

bool echo::hitCubeNeverToutched(ofPoint cubePos, int _cubeId){
    
    // Si le cube à déjà été touché
    if ( std::find(cubesTouched.begin(), cubesTouched.end(), _cubeId) != cubesTouched.end() ) {
        return false;
    }
    
    float _dist = ofDist( pos.x, pos.y, cubePos.x  +25, cubePos.y +25);
    if(size >= _dist){

        // Sauv l'id du cube dans la liste des cubes touchés par l'écho
        cubesTouched.push_back(_cubeId);
        return true;
    }
    
    return false;
}