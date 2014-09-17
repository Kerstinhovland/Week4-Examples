#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    grabber.listDevices();              //list the present video devices
    grabber.setDeviceID(0);             //set the device to be used for capture. default is 0, unless you have multiple devices conencted.
    
    grabber.initGrabber(640, 480);      //set the size of our grabber

    
    ofSetWindowShape(grabber.getWidth(), grabber.getHeight());      //set the window size to be the width and height of the grabber
    
    sound.loadSound("k-longecho-16.aif");
    sound.setVolume(1);
    sound.setLoop(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();       //decode the next frame if available
    ofSoundUpdate();  // Get the next sample in the audio file
    
    
    /*
    if(grabber.isFrameNew()){       //check to see if there is a new frame of video
        unsigned char* grabberPixels = grabber.getPixels();     //take the position/RGB data and place in an unsigned char array
     
    }
     */
}

//--------------------------------------------------------------
void ofApp::draw(){
    grabber.draw(0, 0);     //draw the video to the screen
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key== 's'){
        sound.setSpeed(0);
        sound.unloadSound();
       
    }
    else if (key == 'p'); {
        sound.loadSound("k-longecho-16.aif");
        sound.setVolume(1);
        sound.setPan(-1);
        sound.setSpeed(.5);
        sound.play();
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
