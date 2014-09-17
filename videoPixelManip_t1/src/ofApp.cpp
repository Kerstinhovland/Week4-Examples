#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //video.loadMovie("perlinBox_s8_HiCon.mov");     //load movie file
    //video.loadMovie("perlinBox_s8_HiCon.mov");      //load movie file
    grabber.listDevices();              //list the present video devices
    grabber.setDeviceID(0);             //set the device to be used for capture. default is 0, unless you have multiple devices conencted.
    
    grabber.initGrabber(640, 480);      //set the size of our grabber
    
    
    ofSetWindowShape(grabber.getWidth(), grabber.getHeight());      //set the window size to be the width and height of the grabber
    video.play();                                   //play movie
    
   // ofSetWindowShape(video.getWidth(), video.getHeight());      //set the window size to the size of the video
    cout<<"WINDOW SIZE = "<<ofGetWidth()<<","<<ofGetHeight()<<endl;
    
   // video.setLoopState(OF_LOOP_PALINDROME);     //set the video to ping pong back and forth
    
}

//--------------------------------------------------------------
void ofApp::update(){
   // video.update();//update to the next frame of video
    grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,200,0);
    
    ofEnableAlphaBlending();    //turn on alpha blending to enable transparency
    
    ofSetColor(255,255,255,255);            //Set the color to 255 to ensure video is drawn at 100% brightness. Currently being done using brightness and alpha, can also use full RGBA parameters.
    video.draw(0,0);            //draw the video
    
    ofPixels &pixels = grabber.getPixelsRef();    //get the reference of the pixel array of our movie
    
    int w = pixels.getWidth();  //set w to the width of pixels ref
    int h = pixels.getHeight(); //set h to the height of pixels ref
    
    for (int x=0; x<w; x++) {                           //iterate through the width of the pixel array reference
        
        ofSetLineWidth(1);
        
        ofColor color = pixels.getColor(x,0);           //create a color and set it to the referenced value at x,0, so only using top line of video
        
        ofSetColor(color,200);                          //set the alpha to 200 so overlays over our video
        color.setHueAngle(color.getHueAngle()-40);      //shift our hue color back by 40 degrees to get a pinkish color
        ofSetColor(color);                              //set the color again since changes have been made
        
        ofLine(x,0,x,h);                                //draw a single pixel line from top to bottom with the set color
    }
    
    for (int y=0; y<h; y+=3) {                           //iterate through the width of the pixel array reference
        ofColor color = pixels.getColor(y,0);           //create a color and set it to the referenced value at x,0, so only using top line of video
        
        ofSetColor(color,200);                          //set the alpha to 200 so overlays over our video
        color.setHueAngle(color.getHueAngle()+10);      //shift our hue color back by 40 degrees to get a pinkish color
        ofSetColor(color);                              //set the color again since changes have been made
        
        ofSetLineWidth(1.2);
        ofLine(ofRandom(0,w/2),y,ofRandom(w/2,w),y);    //draw a single pixel line from left to right with starting points randomly in 1st half of screen and wnd half of screen with the set color
    }
    
    //draw a bitmapped string on screen using the default oF typeface.
    //ofToString converts a number to a string
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"FPS", 10, ofGetHeight()-10);
    
    ofDisableAlphaBlending();   //disable alpha blending
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
