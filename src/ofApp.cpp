#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    /// Graphisme init  ///
    ofSetCircleResolution(60);
    
    /// SOUND INIT ////
    //sounds.push_back(*new ofSoundPlayer);
    vector< ofSoundPlayer>::iterator itSounds = sounds.begin();
    
    ///// CUBE INIT ////
    /* Pushback, pour entrer un objet dans mon tableaux d'objet "cube".     */
    for(int i = 0; i< nCube; i++){
        cubes.push_back(*new ricochetCube(ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), i));
        cubes[i].loadSound("./sounds/note_" + std::to_string(i+1) +".wav");
    }
}

//--------------------------------------------------------------
void ofApp::createEchoContainer(ricochetCube _cube){
    
    echoContainer newEchoContainer = *new echoContainer(_cube);
    _cube.play();
    
    echoContainers.push_back(newEchoContainer);
}

//--------------------------------------------------------------
void ofApp::update(){    
   
    for (int i=0; i < echoContainers.size(); i++) {
        echoContainers[i].update();
        
        for(vector<ricochetCube>::iterator it = cubes.begin(); it != cubes.end(); ++it){
            echoContainers[i].checkEchoCollision((*it));
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    /* Ici on parcour le tableaux sans iterrateur */
    for (int i=0; i < cubes.size(); i++) {
        cubes[i].draw();
    }
    for (int i=0; i < echoContainers.size(); i++) {
        echoContainers[i].draw();
    }
    
    ofFill();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    for(vector<ricochetCube>::iterator it = cubes.begin(); it != cubes.end(); ++it) {
        
        if((*it).pointIsInside(ofPoint(x, y))) {
            cout << " Cube Draged" << endl;
            (*it).moveTo(ofPoint(x, y));
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    /* ici on peut utiliser un iterrateur dans une boucle for pour pointer vers tout les objet du tableau cube */
    /*  L'avantage des iterateurs si j'ai bien compris, c'est de pointŽ directement sans avoir ˆ assigner un int pour aller retrouvŽ la value,
     du coup c'est plus rapide */
    for(vector<ricochetCube>::iterator it = cubes.begin(); it != cubes.end(); ++it){
        
        if((*it).pointIsInside(ofPoint(x, y))) {
            cout << " Cube Clicked" << endl;
            
            createEchoContainer((*it));
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
