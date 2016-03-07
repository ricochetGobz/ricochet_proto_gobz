#pragma once

#include "ofMain.h"
#include "ricochetCube.h"
#include "echoContainer.h"

class ofApp : public ofBaseApp{

    /* Le .h sert à déclarer les variables appelé dans le .CPP */
	public:

    
    private:
        // VAR
        int cubeDragged;
        int nCube = 8;
        bool mouseDown = false;
        bool mouseMove = false;
        bool bSetupArduino = false;
        ofArduino ard;
        ofSerial serial;
        int motorValue = 0;
    
        float * fftSmoothed;
        int nBandsToGet;
    
        /* VECTOR = Tableau d'objets */
        vector<ricochetCube> cubes;
        vector<echoContainer> echoContainers;
    
        /* AUDIO PART */
        vector<ofSoundPlayer> sounds;
    
        // METHOD
        void setup();
        void setupArduino();
        void update();
        void updateArduino();
        void draw();
        float translateSoundFrequency();
    
        void createEchoContainer(ricochetCube _cube);
    
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
};