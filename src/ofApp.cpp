#include "ofApp.h"


bool shouldRemove(echoContainer &c) {
    if(c.echoes.size() == 0) {
        return true;
    }
    return false;
}

//--------------------------------------------------------------

void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    /// Graphisme init  ///
    ofSetCircleResolution(60);
    
    /// SOUND INIT ////
    //sounds.push_back(*new ofSoundPlayer);
    vector< ofSoundPlayer>::iterator itSounds = sounds.begin();
    
    ///// CUBE INIT ////
    /* Pushback, pour entrer un objet dans mon tableaux d'objet "cube".     */
    for(int i = 0; i < nCube; i++) {
        cubes.push_back(*new ricochetCube(ofPoint(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), i));
        cubes[i].loadSound("./sounds/note_" + std::to_string((i%6)+1) +".mp3");
    }
    
    // TEMPS //
    ///// ARDUINO INIT ////
    
    // serial
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    
    int baud = 9600;
    serial.setup(0, 9600);
    
//    // arduino
//    ard.connect("cu.usbmodem1411", 57600);
//    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
}

//--------------------------------------------------------------
void ofApp::setupArduino() {
    
    cout << "SETUP ARDUINO" << endl;
    
//    // remove listener because we don't need it anymore
//    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
//    // this is where you setup all the pins and pin modes, etc
//    ard.sendDigitalPinMode(9, ARD_PWM);
//    bSetupArduino = true;
    
}


//--------------------------------------------------------------
void ofApp::createEchoContainer(ricochetCube _cube){
    
    echoContainer newEchoContainer = *new echoContainer(_cube);
    _cube.play();
    
    echoContainers.push_back(newEchoContainer);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofRemove(echoContainers, shouldRemove);
   
    for (vector<echoContainer>::iterator itWave = echoContainers.begin(); itWave != echoContainers.end(); ++itWave) {
        (*itWave).update();
        
        for(vector<ricochetCube>::iterator it = cubes.begin(); it != cubes.end(); ++it){
            (*itWave).checkEchoCollision((*it));
        }
    }
    
    updateArduino();
}
//--------------------------------------------------------------
void ofApp::updateArduino(){
    motorValue = (150 + (100 * sin( ofGetElapsedTimef() * 3.14 )));
    
    //With ofSerial
    serial.writeByte(motorValue);

//    // With ofArduino
//    if(bSetupArduino) {
//        ard.update();
//        ard.sendPwm(9, 255, true);
//    } else if(ard.isArduinoReady()) {
//        setupArduino();
//    }
  }

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(vector<ricochetCube>::iterator it = cubes.begin(); it != cubes.end(); ++it){
        (*it).draw();
    }
    
    for (vector<echoContainer>::iterator it = echoContainers.begin(); it != echoContainers.end(); ++it) {
        (*it).draw();
    }
    
    if(cubeDragged > 0 && mouseDown){
        cubes[cubeDragged].contactZoneShowed = true;
    }
    
    ofFill();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:
            break;
        case OF_KEY_DOWN:
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
//    for(vector<ricochetCube>::iterator it = cubes.begin(); it != cubes.end(); ++it) {
    
        if(mouseDown) {
            mouseMove = true;
            cout << " Cube Draged" << endl;
            cubes[cubeDragged].moveTo(ofPoint(x, y));
        }
//    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for(vector<ricochetCube>::iterator it = cubes.begin(); it != cubes.end(); ++it) {
        
        if((*it).pointIsInside(ofPoint(x, y))) {
            cout << " Cube Draged" << endl;
            (*it).moveTo(ofPoint(x, y));
            mouseDown = true;
            cubeDragged = (*it).cubeId;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    /* ici on peut utiliser un iterrateur dans une boucle for pour pointer vers tout les objet du tableau cube */
    /*  L'avantage des iterateurs si j'ai bien compris, c'est de pointŽ directement sans avoir ˆ assigner un int pour aller retrouvŽ la value,
     du coup c'est plus rapide */
//    for(vector<ricochetCube>::iterator it = cubes.begin(); it != cubes.end(); ++it){
    
        if(mouseDown) {
            cout << " Cube Clicked" << endl;
            
            if(!mouseMove) createEchoContainer(cubes[cubeDragged]);
            mouseDown = false;
            mouseMove = false;
            
            // Init contactZone
            cubes[cubeDragged].contactZoneShowed = false;
            cubeDragged = -1;
        }
//    }
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
