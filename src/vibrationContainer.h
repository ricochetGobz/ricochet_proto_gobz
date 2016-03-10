//
//  vibrationContainer.h
//  ricochet_proto_echo
//
//  Created by Boulay Jérémie on 10/03/2016.
//
//

#ifndef vibrationContainer_h
#define vibrationContainer_h

#include "ofMain.h"
#include "vibration.h"

class vibrationContainer {
public:
    // Constructor
    vibrationContainer();
    
    // VARS
    
    
    // METHODS
    void draw();
    void update();
    void setVibrations(int _low, int _medium, int _hight);
    
private:
    // VARS
    vibration lowV = *new vibration(255,255);
    vibration mediumV = *new vibration(255,255);
    vibration hightV = *new vibration(765,255);
    
    // METHODS
};

#endif /* vibrationContainer_h */
