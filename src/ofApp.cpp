#include "ofApp.h"

//--------------------------------------------------------------
bool shouldRemove(echo &p){
    
    if(p.size > 500 )return true;
    else return false;
}
bool hitTest(echo &p, vector<ricochetCube>& r ){
    for(vector<ricochetCube>::iterator it = r.begin(); it != r.end(); ++it){
        float _dist = ofDist( p.pos.x, p.pos.y,(*it).pos.x+25, (*it).pos.y+25);
        ricochetCube currentCube = *it;
        if(p.size >= _dist && p.fromCube != it - r.begin()){
            cout << _dist << endl;
            return true;
        }
    }
    return false;
}

void ofApp::setup(){
    ofBackground(0, 0,0);
   
    /// Graphisme init  ///
    
    ofSetCircleResolution(60);
    /// SOUND INIT ////
    //sounds.push_back(*new ofSoundPlayer);
    vector< ofSoundPlayer>::iterator itSounds = sounds.begin();

    
    
    ///// CUBE INIT ////
    /* Pushback, pour entrer un objet dans mon tableaux d'objet "cube".     */
    for(int i = 0 ; i< 10; i++){
        cube.push_back(*new ricochetCube());
    }
    
    vector<ricochetCube>::iterator myCubes = cube.begin();
   
    
    
    /* un iterateur, c'est un pointeur qui pointe vers un ricochetCube dans le tableau cube */
   itCube = cube.begin();
    for(int i = 0 ; i< 10; i++){
         cube[i].moveTo(ofPoint( ofRandom(ofGetWidth()), ofRandom(ofGetHeight())));
    }
   
}

//--------------------------------------------------------------
void ofApp::update(){
     ofRemove(echoTab,shouldRemove);
    
   
 
    for (int i=0; i < echoTab.size(); i++) {
        echoTab[i].expand();
        
        if(hitTest(echoTab[i], cube)){
            echoTab.erase(echoTab.begin() + i);
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
    ofSetColor(200,0,0);
    ofDrawRectangle(ofGetWidth()/4,ofGetHeight()/4,50,50);
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
    

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    /* ici on peut utiliser un iterrateur dans une boucle for pour pointer vers tout les objet du tableau cube */
    /*  L'avantage des iterateurs si j'ai bien compris, c'est de pointŽ directement sans avoir ˆ assigner un int pour aller retrouvŽ la value,
     du coup c'est plus rapide */
    for(vector<ricochetCube>::iterator it = cube.begin(); it != cube.end(); ++it){
        // (*it).clicked(ofPoint(x,y));
        //cout << (*it).id  << endl ;
        float _dist = ofDist( (*it).pos.x+25, (*it).pos.y+25, x, y);
        if(_dist < 20.0){
            ofDrawRectangle((*it).pos,60,60);
            echo newEcho = *new echo((*it).pos);
            newEcho.fromCube = it - cube.begin();
            echoTab.push_back(newEcho);
            cout << _dist << endl;
            cout << " Cube Clicked" << endl;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
