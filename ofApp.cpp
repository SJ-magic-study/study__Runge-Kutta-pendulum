#include "ofApp.h"
#include <math.h>

#define PI 3.14159265398979


/******************************
******************************/
double ofApp::f1(double y1, double y2, double t)
{
	return y2;
}

/******************************
******************************/
double ofApp::f2(double y1, double y2, double t)
{
	return -g / Length * sin(y1);
}


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	
	Length = 400;
	theta_rad = 60 * PI / 180;
	omega = 0;
	g = 9.80 * 100; // speed adjustment
	pos_fix = ofPoint(512, 100);
}

//--------------------------------------------------------------
void ofApp::update(){
	/********************
	********************/
	float t = ofGetElapsedTimef();
	float dt = 1.0/60.0;
	
	/********************
	********************/
	double k_theta[4];
	double k_omega[4];
	
	k_theta[0] = f1(theta_rad, omega, t);
	k_omega[0] = f2(theta_rad, omega, t);
	
	k_theta[1] = f1(theta_rad + k_theta[0] * dt / 2.0, omega + k_omega[0] * dt / 2.0, t + dt / 2.0);
	k_omega[1] = f2(theta_rad + k_theta[0] * dt / 2.0, omega + k_omega[0] * dt / 2.0, t + dt / 2.0);
	
	k_theta[2] = f1(theta_rad + k_theta[1] * dt / 2.0, omega + k_omega[1] * dt / 2.0, t + dt / 2.0);
	k_omega[2] = f2(theta_rad + k_theta[1] * dt / 2.0, omega + k_omega[1] * dt / 2.0, t + dt / 2.0);

	k_theta[3] = f1(theta_rad + k_theta[2] * dt, omega + k_omega[2] * dt, t + dt);
	k_omega[3] = f2(theta_rad + k_theta[2] * dt, omega + k_omega[2] * dt, t + dt);
	
	
	/* */
	theta_rad	+= (k_theta[0] + 2.0 * k_theta[1] + 2.0 * k_theta[2] + k_theta[3]) * dt / 6.0;
	omega		+= (k_omega[0] + 2.0 * k_omega[1] + 2.0 * k_omega[2] + k_omega[3]) * dt / 6.0;
}

//--------------------------------------------------------------
void ofApp::draw(){
	/********************
	********************/
	ofPoint mass;
	mass.x = pos_fix.x + Length * sin(theta_rad);
	mass.y = pos_fix.y + Length * cos(theta_rad);
	
	/********************
	********************/
	ofBackground(255, 255, 255);
	
	ofSetColor(0, 0, 255);
	ofLine(pos_fix.x, pos_fix.y, mass.x, mass.y);
	
	/********************
	********************/
	ofSetColor(255, 0, 0);
	ofFill();
	ofCircle(mass.x, mass.y, 20);
	
	/********************
	********************/
	printf("%5.1f\r", theta_rad * 180 / PI);
	fflush(stdout);
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
