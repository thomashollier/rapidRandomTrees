//
//  node.h
//  rrt_01
//
//  Created by Hollier, Thomas X. -ND on 9/8/15.
//
//


//#ifndef __rrt_01__node__
//#define __rrt_01__node__

#include <stdio.h>
#include "ofMain.h"

class node{
    
private:
    ofVec2f _point;
    vector  <node *> _children;
    node * _parent;
    void init(ofVec2f v);
    bool _isLeaf;
    
public:
    node();
    node(float a, float b);
    node(ofVec2f p);
    void test();
    float getX();
    float getY();
    ofVec2f getPoint();
    void addChild(node * n);
    void setParent(node * n);
    node * getParent();
    vector<node *> getChildren();
    int getNumberOfChildren();
    void setIsFirst(bool b);
    bool isFirst;
    void setIsLeaf(bool b);
    bool isLeaf();
};

//#endif /* defined(__rrt_01__node__) */
