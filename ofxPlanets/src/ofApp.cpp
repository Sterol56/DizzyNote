#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // This gets called once when we start our app

    // Make the app full screen
    ofSetFullscreen(false);
    
    // Turn on depth testing so rendering happens according to z-depth rather
    // than draw order.
    ofEnableDepthTest();
    
    // Black background
    ofBackground(0);
    
    // Set the size of our sphere "planets"
    sun.setRadius( 120.0 );
    earth.setRadius( 50.0 );
    moon.setRadius( 12.0 );
    
    // Initialize orbit rotation angles to zero
    sunRotationAngle = 0;
    earthOrbitAngle = 0;
    moonOrbitAngle = 0;}

//--------------------------------------------------------------
void ofApp::update(){
    // This gets called once for each graphical frame, right before draw()
    
    // Update orbit rotation angles -- larger increment == faster rotation.
    sunRotationAngle += 0.1;
    earthRotationAngle += 2.0;
    earthOrbitAngle += 0.5;
    moonOrbitAngle += 2.5;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // This gets called once for each graphical frame, right after update()
    // This is where you draw all the graphics
    
    ofPushMatrix(); // Save our state for later

        // Since our coordinates start in the top left, translate to the center.
        ofTranslate( ofGetWindowWidth()*0.5, ofGetWindowHeight()*0.5 );
        
        ofPushMatrix(); // Save center state
        
            ofRotateY( sunRotationAngle ); // Sun's rotation about its axis
            
            ofPushStyle(); // Save initial style state
                // Set the color of the sun
                ofSetColor(200, 150, 0);
                // Draw the sun (wireframe so we can see rotation)
                sun.drawWireframe();
            ofPopStyle(); // Back to initial style state
        
        ofPopMatrix(); // Back to center state
    
        // Rotate our axes and then translate, for Earth orbit
        ofRotateZ( earthOrbitAngle );
        ofTranslate(350, 0, 0);
    
        ofPushMatrix(); // Save Earth-centric state
            //ofRotateZ( earthRotationAngle ); // Rotate Earth about its own axis
            ofPushStyle();  // Save initial style state
                // Set the color of the Earth
                ofSetColor(256, 0, 0);
                // Draw the Earth (also wireframe so we can see rotation)
                earth.drawWireframe();
            ofPopStyle(); // Back to initial style state
        ofPopMatrix(); // Back to un-rotated Earth-centric state
    
        //// Recall that our axes are still centered about the Earth.
        //// Now do another rotate and translate, thus we rotate the moon about
        //// the Earth.
        //ofRotateY( moonOrbitAngle );
        //// ofRotateX( moonOrbitAngle ); // also rotate about the X direction?
        //ofTranslate(0, 0, 100); // and translate in the Z direction just for fun
        //
        //ofPushStyle();  // Save initial style state
        //    // Set the Moon color
        //    ofSetColor(256, 256, 256);
        //    // Draw the moon
        //    moon.drawWireframe();
        //ofPopStyle(); // Back to initial style state
    
    ofPopMatrix(); // Back to initial state at the top-left of our window.
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
