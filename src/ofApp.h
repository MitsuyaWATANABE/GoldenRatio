#pragma once

#include "ofMain.h"
#include "ofxGoldenRatio.h"

class ofApp : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
    
        ofxGoldenRatio *goldenRatio;
        ofTrueTypeFont font;
        int shapeCount;
};
