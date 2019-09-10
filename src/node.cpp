//
//  node.cpp
//  rrt_01
//
//  Created by Hollier, Thomas X. -ND on 9/8/15.
//
//

#include "node.h"


node::node(ofVec2f p){
    init(p);
}

node::node(){
    init(ofVec2f(0,0));
}

node::node(float x, float y){
    init(ofVec2f(x, y));
}

void node::init(ofVec2f v){
    _point = v;
    setIsLeaf(false);
}

void node::test(){
    std::cout << "testing...";
}

float node::getX(){
    return _point.x;
}

float node::getY(){
    return _point.y;
}

ofVec2f node::getPoint(){
    return _point;
}

void node::addChild(node * n){
    _children.push_back(n);
}

void node::setParent(node * n){
    _parent = n;
}

node * node::getParent(){
    return  _parent;
}

vector<node *> node::getChildren(){
    return _children;
}

int node::getNumberOfChildren(){
    return _children.size();
}

void node::setIsFirst(bool b){
    isFirst = b;
}

void node::setIsLeaf(bool b){
    _isLeaf = b;
}

bool node::isLeaf(){
    return _isLeaf;
}
