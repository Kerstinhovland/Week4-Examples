#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    video.loadMovie("LineWorld_v1_Part1_PhotoJPEG.mov");        //load our video. remember videos should be in /bin/data/
    //video.loadMovie("LineWorld_v1_Part1_HAP.mov");
    
    ofSetWindowShape(video.getWidth(), video.getHeight());      //set the window to match the size of our video using the .getHeight/Width methods available from the ofVideoPlayer object
    
    video.play();                                               //start playing the video
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();     //decode the next frame of video
}

//--------------------------------------------------------------
void ofApp::draw(){
    video.draw(0,0);    //draw the video with top corner at 0,0
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //if the space bar is pressed set the pause status of the video player to the opposite of it's current status
    //basically pause and play
    if (key == ' ') {
        video.setPaused(!video.isPaused());
        cout<<"VIDEO PAUSE IS "<<video.isPaused()<<" ON FRAME: "<<video.getCurrentFrame()<<endl;
    }
    
    if(key == 'l'){
        video.setLoopState(OF_LOOP_PALINDROME);     //if l key is pressed set the video to palindrone loop aka ping pong
        cout<<"LOOP STATE SET TO PALINDROME"<<endl;
    }
    
    if(key == 'k'){
        video.setLoopState(OF_LOOP_NORMAL);         //reset the loop to normal repeat back to 1st frame on end
        cout<<"LOOP STATE SET TO NORMAL"<<endl;
    }
    
    if (key == 's') {
        video.stop();       //if s is pressed stop video
    }
    
    if(key=='p'){
        video.setFrame(0);
        video.play();      //if p is pressed play video from beginning
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
    video.setSpeed(video.getSpeed()*1.01);              //increase the video speed by a scaler of 1.01
    cout<<"CURRENT SPEED IS = "<<video.getSpeed()<<endl;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    video.setFrame(ofRandom(0,video.getTotalNumFrames()-1));  //set the current frame to a random frame between 0 (start) and the total number of frames in the video
    cout<<"SETTING FRAME TO: "<<video.getCurrentFrame()<<endl;
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
