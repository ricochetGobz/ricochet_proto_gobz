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

        // VARS
        vector<echo> echoes;

        // METHODS
        void checkEchoCollision(ricochetCube _cube);
        void update();
        void draw();

    private:
        // VARS
        vector<int> cubesTouched;
        /* temps */
        bool echoWithVel;

        // METHODS
        void createEcho(ricochetCube _cube);
        bool isAlreadyTouched(int _cubeId);
};

#endif /* echoContainer_hpp */
