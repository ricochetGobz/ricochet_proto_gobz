//
//  vibration.h
//  ricochet_proto_echo
//
//  Created by Boulay Jérémie on 09/03/2016.
//
//

#ifndef vibration_h
#define vibration_h

#include "ofMain.h"

class vibration{
public:
    // Constructor
    vibration(int _x, int _y);
    
    // VARS
    
    
    // METHODS
    void draw();
    void update(int _vibration);
    
private:
    // VARS
    int v = 5;
    int posx;
    int posy;
    
    ofColor color;

    
    // METHODS
};


#endif /* vibration_h */
