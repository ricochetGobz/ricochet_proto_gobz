#pragma once

#include "ofMain.h"
#include "ricochetCube.h"
#include "echoContainer.h"
#include "vibration.h"

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
    
        /* VECTOR = Tableau d'objets */
        vector<ricochetCube> cubes;
        vector<echoContainer> echoContainers;
    
        /* AUDIO PART */
        float * fftSmoothed;
        int nBandsToGet = 512;

        vector<ofSoundPlayer> sounds;
    
        vector<vibration> vibrations;
    
//        vibration lowV = *new vibration(255,255);
//        vibration mediumV = *new vibration(510,255);
//        vibration hightV = *new vibration(765,255);
    
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