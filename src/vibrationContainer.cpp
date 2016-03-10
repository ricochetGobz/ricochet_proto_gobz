//
//  vibrationContainer.cpp
//  ricochet_proto_echo
//
//  Created by Boulay Jérémie on 10/03/2016.
//
//

#include "vibrationContainer.h"


//--------------------------------------------------------------
vibrationContainer::vibrationContainer() {}

//--------------------------------------------------------------
void vibrationContainer::draw() {
    lowV.draw();
    mediumV.draw();
    hightV.draw();
}

//--------------------------------------------------------------
void vibrationContainer::update() {
    lowV.update();
    mediumV.update();
    hightV.update();
}


//--------------------------------------------------------------
void vibrationContainer::setVibrations(int _low, int _medium, int _hight){
    lowV.setVibration(_low);
    mediumV.setVibration(_medium);
    hightV.setVibration(_hight);
}