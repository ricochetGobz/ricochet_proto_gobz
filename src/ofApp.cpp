#include "ofApp.h"

//--------------------------------------------------------------
bool shouldRemove(echo &p){
    
    if(p.size > 500 )return true;
    else return false;
}


void ofApp::setup(){
    ofBackground(0, 0, 0);
   
    /// Graphisme init  ///
    
    ofSetCircleResolution(60);
    /// SOUND INIT ////
    //sounds.push_back(*new ofSoundPlayer);
    vector< ofSoundPlayer>::iterator itSounds = sounds.begin();

    
    ///// CUBE INIT ////
    /* Pushback, pour entrer un objet dans mon tableaux d'objet "cube".     */
    for(int i = 0 ; i< 6; i++){
        cube.push_back(*new ricochetCube(ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), i));
        cube[i].loadSound("./sounds/note_" + std::to_string(i+1) +".wav");
    }
}

//--------------------------------------------------------------
void ofApp::createEcho(ricochetCube _cube, int _cubeParent){
    echo newEcho = *new echo(_cube.pos, _cube.cubeId);
    _cube.play();
    newEcho.parent = _cubeParent;
    echoTab.push_back(newEcho);
}

//--------------------------------------------------------------
void ofApp::update(){
     ofRemove(echoTab,shouldRemove);
    
   
    for (int i=0; i < echoTab.size(); i++) {
        echoTab[i].expand();
        
        for(vector<ricochetCube>::iterator it = cube.begin(); it != cube.end(); ++it){
            if(echoTab[i].parent == it - cube.begin() || echoTab[i].fromCube == it - cube.begin()) continue;
             
            if(echoTab[i].hitCube((*it).pos)){
                echoTab.erase(echoTab.begin() + i);
                createEcho((*it), echoTab[i].fromCube);
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    /* Ici on parcour le tableaux sans iterrateur */
    for (int i=0; i < cube.size(); i++) {
        cube[i].draw();
    }
    for (int i=0; i < echoTab.size(); i++) {
        echoTab[i].draw();
    }
    
    ofFill();
//    ofSetColor(200,0,0);
//    ofDrawRectangle(ofGetWidth()/4,ofGetHeight()/4,50,50);
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
    for(vector<ricochetCube>::iterator it = cube.begin(); it != cube.end(); ++it) {
        
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
    for(vector<ricochetCube>::iterator it = cube.begin(); it != cube.end(); ++it){
        
        if((*it).pointIsInside(ofPoint(x, y))) {
            cout << " Cube Clicked" << endl;
            createEcho((*it), -1);
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
