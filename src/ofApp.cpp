#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofBackground(50);
    ofSetVerticalSync(false);
    ofSetFrameRate(3000);
    ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetFrameNum()%(fadeLength+arraySize) == 0){
        makeRRT();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(ofGetFrameNum()%(fadeLength+arraySize) == 0){
        ofBackground(32,32,32);
    }
    int base = ofGetFrameNum()%(fadeLength+arraySize);
    for(int i = -fadeLength; i< 0; i++){
        float alpha = ofMap(i,-fadeLength,0,1,0);
        float radius = alpha*4+1;
        alpha = pow(alpha,7)*255;
        ofSetColor(255,255,100,alpha);
        int foo = base+i;
        if(foo>=arraySize){
            continue;
        }
        if(foo<0){
            continue;
        }
        node * n = &sortedNodes[foo];
        node * nn = (*n).getParent();
        ofSetLineWidth(radius);
        ofDrawLine((*nn).getX(), (*nn).getY(), (*n).getX(), (*n).getY());
        if((*n).isLeaf()){
            ofSetColor(200,50,0);
            ofDrawEllipse((*n).getX(), (*n).getY(), radius*2, radius*2);
            
        }
    }
 }

//--------------------------------------------------------------
void ofApp::makeRRT(){
    node randomNode;
    node *n, *p;
    
    randomNode = node(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    nodes[0] = randomNode;
    
    for(int i=1; i<arraySize; i++){
        randomNode = node(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        
        node * randomNodePtr = &randomNode;
        node * closestNodePtr = findClosest(randomNodePtr, i);
        if ( (*randomNodePtr).getPoint().squareDistance((*closestNodePtr).getPoint()) > 144 ){
            nodes[i] = computePoint(closestNodePtr, randomNodePtr);
            nodes[i].setParent(closestNodePtr);
            (*closestNodePtr).addChild(&nodes[i]);
        }else{
            i--;
        }
    }
    processRTTNodes();
}

//--------------------------------------------------------------
void ofApp::processRTTNodes(){
    sortCounter = 0;
    nodes[0].setParent(&nodes[0]);
    sortRTTNodes(&nodes[0],0);
    
}

//--------------------------------------------------------------
void ofApp::sortRTTNodes(node * n, int index){
    sortedNodes[sortCounter] = *n;
    node * thisNode = &sortedNodes[sortCounter];
    sortCounter ++;
    
    vector <node *> children = (*n).getChildren();
    
    for(int i=0; i < children.size(); i++){
        node child = *children.at(i);
        child.setParent(thisNode);
        sortRTTNodes(&child, 0);
    }
    if(children.size()==0){
        (*thisNode).setIsLeaf(true);
    }

}

//--------------------------------------------------------------
node * ofApp::findClosest(node * n, int counter){
    float closestDistance = 10000000;
    int closest = -1; ;

    for( int i=0; i < counter; i++){
        float thisDistance = nodes[i].getPoint().squareDistance((*n).getPoint());
        if (thisDistance < closestDistance){
            closestDistance = thisDistance;
            closest = i;
        }
    }
    return &nodes[closest];
}

//--------------------------------------------------------------
node ofApp::computePoint(node * closest, node * random){
    ofVec2f newPoint =  (*random).getPoint() - (*closest).getPoint();
    newPoint.normalize();
    newPoint *= 6;
    newPoint += (*closest).getPoint();
    
    return node(newPoint);
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



