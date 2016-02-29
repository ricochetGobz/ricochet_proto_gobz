//
//  echoContainer.cpp
//  ricochet_proto_echo
//
//  Created by Boulay Jérémie on 09/02/2016.
//
//

#include <stdio.h>
#include "echoContainer.h"
#include "ricochetCube.h"


echoContainer::echoContainer(ricochetCube _cube){
    createEcho(_cube);
}

//--------------------------------------------------------------
bool shouldRemove(echo &e){
    return e.souldRemoved();
}

//--------------------------------------------------------------
void echoContainer::update() {
    ofRemove(echoes, shouldRemove);
    
    for(vector<echo>::iterator it = echoes.begin(); it != echoes.end(); ++it){
        (*it).expand();
    }
}

//--------------------------------------------------------------
void echoContainer::draw() {
    for(vector<echo>::iterator it = echoes.begin(); it != echoes.end(); ++it){
        (*it).draw();
    }
}

//--------------------------------------------------------------
void echoContainer::createEcho(ricochetCube _cube) {
    // sauve le cube emmeteur comme cube touché
    cubesTouched.push_back(_cube.cubeId);
    _cube.play();
    
    echoes.push_back(*new echo(_cube.pos));
}

//--------------------------------------------------------------
void echoContainer::checkEchoCollision(ricochetCube _cube) {
    
    if(isAlreadyTouched(_cube.cubeId)) return;
    
    for(vector<echo>::iterator it = echoes.begin(); it != echoes.end(); ++it) {

        // Si l'éco
        // peut activer d'autres cubes encore
        if((*it).checkCubeCollision(_cube.pos)) {
            
            //echoTab.erase(echoTab.begin() + i);
            
            // Créer un écho avec la liste des cubes que cet écho à déjà touché
            createEcho(_cube);
            return;
        }
    }
}

//--------------------------------------------------------------
bool echoContainer::isAlreadyTouched(int _cubeId) {
    // Si le cube à déjà été touché
    if ( std::find(cubesTouched.begin(), cubesTouched.end(), _cubeId) != cubesTouched.end() ) {
        return true;
    }
    return false;
}