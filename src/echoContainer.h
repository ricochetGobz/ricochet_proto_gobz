//
//  echoContainer.hpp
//  ricochet_proto_echo
//
//  Created by Boulay Jérémie on 09/02/2016.
//
//

#ifndef echoContainer_h
#define echoContainer_h

#include <stdio.h>
#include "ricochetCube.h"
#include "echo.h"

class echoContainer {
public:
    // Constructor
    echoContainer(ricochetCube _cube);
    
    // Methods
    void update();
    void draw();
    void createEcho(ricochetCube _cube);
    void checkEchoCollision(ricochetCube _cube);
    bool isAlreadyTouched(int _cubeId);
    
    // Vars
    vector<int> cubesTouched;
    vector<echo> echoes;
};

#endif /* echoContainer_hpp */
