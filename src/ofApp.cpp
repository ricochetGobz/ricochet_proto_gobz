#include "ofApp.h"

//--------------------------------------------------------------
bool shouldRemove(echo &p){
    
    if(p.size > 200 )return true;
    return false;
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
void ofApp::createEcho(ricochetCube _cube, vector<int> _cubesTouched){
    // sauve le cube emmeteur comme cube touché
    _cubesTouched.push_back(_cube.cubeId);
    
    echo newEcho = *new echo(_cube.pos, _cubesTouched);
    _cube.play();
    echoTab.push_back(newEcho);
}

//--------------------------------------------------------------
void ofApp::update(){
     ofRemove(echoTab,shouldRemove);
    
   
    for (int i=0; i < echoTab.size(); i++) {
        echoTab[i].expand();
        
        for(vector<ricochetCube>::iterator it = cube.begin(); it != cube.end(); ++it){
            
            // Si l'éco
            // peut activer d'autres cubes encore
            // && touche un cube qu'il n'a pas déja touché
            if(echoTab[i].hitEnabled && echoTab[i].hitCubeNeverToutched((*it).pos, (*it).cubeId)) {
                
                //echoTab.erase(echoTab.begin() + i);
                echoTab[i].hitEnabled = false;
                
                // Créer un écho avec la liste des cubes que cet écho à déjà touché
                createEcho((*it), echoTab[i].cubesTouched);
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
    /*  L'avantage des iterateurs si j'ai bien compris, c'est de pointé directement sans avoir à assigner un int pour aller retrouvé la value,
     du coup c'est plus rapide */
    for(vector<ricochetCube>::iterator it = cube.begin(); it != cube.end(); ++it){
        
        if((*it).pointIsInside(ofPoint(x, y))) {
            cout << " Cube Clicked" << endl;
            
            // Nouvelle vague qui n'a touché aucun cube.
            vector<int> emptyCubeIdTouched;
            createEcho((*it), emptyCubeIdTouched);
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
