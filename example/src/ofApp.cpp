#include "ofApp.h"
#include "open3d/Open3D.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//
        open3d::utility::LogInfo("Skiped for unit test.");
//
        auto sphere = open3d::geometry::TriangleMesh::CreateSphere(1.0);
//        sphere->ComputeVertexNormals();
//        sphere->PaintUniformColor({0.0, 1.0, 0.0});
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
