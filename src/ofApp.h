#pragma once

#include "ofMain.h"
#include "ricochetCube.h"
#include "echo.h"

class ofApp : public ofBaseApp{

    /* Le .h sert à déclarer les variables appelé dans le .CPP */
	public:
		void setup();
		void update();
		void draw();
    
        void createEcho(vector<ricochetCube>::iterator cubeIt);

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

    /* VECTOR  = Tableau d'objet , en l'occurence ici ce sont des ricochetCube. */
    vector<ricochetCube> cube;
    vector<ricochetCube>::iterator itCube ;
    int nCube;
    
    /*Pareil pour mon tableaux d'echo */
    vector<echo> echoTab;
    int nEcho;
    
    /* AUDIO PART */
    
    vector<ofSoundPlayer> sounds;
    
    private:
    
    
		
};
