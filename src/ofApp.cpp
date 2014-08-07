#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();
	ofDisableArbTex();
	ofEnableSmoothing();
	ofEnableAntiAliasing();
//	cam.setAutoDistance(true);
	cam.setDistance(5000);
	
	ofSetFrameRate(10);
	bcal=false;
	w=ofGetWindowWidth()/2;
	h=ofGetWindowHeight()/2;
	
	gui.setup("panel");
	gui.add(zooming.set("zooming",0,0,10));
	gui.add(center.set("center",ofVec2f(w*.5,h*.5),ofVec2f(0,0),ofVec2f(w,h)));
	
}

//--------------------------------------------------------------
void ofApp::update(){
	cam.setDistance(camdis);
}

//--------------------------------------------------------------
void ofApp::draw(){

	int fn = ofGetFrameNum();
	gui.draw();
	cam.begin();
	if (bcal) {
		isosurface.Draw(fn);
	}
	cam.end();
//	light.disable();
//	if (bcal) {
//		std::list<NSSolver::Domain>::iterator Itelator=ldm.begin();
//		for (int TS=0; TS<ldm.size(); TS++) {
//			int offset_w=50;
//			int offset_h=50;
//			int offset_x=50;
//			int offset_y=50;
//			ofVec2f Pconsole=ofVec2f(offset_w, h+offset_h);
//			ofDrawBitmapString("Time Step", Pconsole.x,Pconsole.y+TS*offset_y);
//			ofDrawBitmapString(ofToString(TS), Pconsole.x+10,Pconsole.y+TS*offset_y);
//			for (int i3 = 0; i3 < nssolver.N3; i3++) {
//				for (int i2 = 0; i2 < nssolver.N2; i2++) {
//					for (int i1 = 0; i1 < nssolver.N1; i1++) {
//						float foo = (float)Itelator->AC[i1][i2][i3].Q;
//						printf("TS=%d %d %d %d  %f\n", TS, i1, i2, i3, foo);
//							ofSetColor(0, 0, 0);
//						ofDrawBitmapString(ofToString(foo), Pconsole.x+i1*offset_x, Pconsole.y+TS*offset_y+i2*offset_y+10);
//					}
//				}
//			}
//			*Itelator++;
//		}
////		bcal=false;
//	}

	ofSetColor(255, 255, 255);
    ofDrawBitmapString("'c'key - run NSSolver", ofPoint(20, 20));

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key=='c') {
		nssolver.nssolver(ldm);
		isosurface.Cal(ldm);
		std::list<Vertices>::iterator Itelator=ldm.begin();
		N1 = isosurface.times * Itelator->N1;
		camdis=2*N1;
		bcal=true;
	}
	if (key==OF_KEY_DOWN) {
		camdis+=50;
	}
	if (key==OF_KEY_UP) {
		camdis-=50;
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
