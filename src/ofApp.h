#pragma once

#include "ofMain.h"
#include "node.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
        void update();
		void draw();


        void makeRRT();
        void processRTTNodes();
        void sortRTTNodes(node * n, int index);

        void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    
    const static int arraySize = 6000;
    const static int fadeLength = 100;
    node nodes[arraySize];
    node sortedNodes[arraySize];
    int sortCounter;

    node * findClosest(node * n, int counter);
    node computePoint(node * closestNode, node * randomNode);

};
