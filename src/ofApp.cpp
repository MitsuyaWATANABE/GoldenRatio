#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    goldenRatio = new ofxGoldenRatio;
    goldenRatio->targetColor = ofColor(255, 255, 255);
    goldenRatio->showSpiralLines = true;
    font.loadFont("futura_book.otf", 11);
    shapeCount = 10;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(0, 0, 0);
    goldenRatio->drawFigure(30.0, 150.0, 1200, shapeCount);
    
    ofSetColor(255, 255, 255);
    font.drawString("This is a sample for a figure using golden ratio.\n\nTyping \"s\" key switches to show or hide spiral line.", 30, 80);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    switch (key) {
        case '0':
            shapeCount = 10;
            break;
        case '1':
            shapeCount = 1;
            break;
        case '2':
            shapeCount = 2;
            break;
        case '3':
            shapeCount = 3;
            break;
        case '4':
            shapeCount = 4;
            break;
        case '5':
            shapeCount = 5;
            break;
        case '6':
            shapeCount = 6;
            break;
        case '7':
            shapeCount = 7;
            break;
        case '8':
            shapeCount = 8;
            break;
        case '9':
            shapeCount = 9;
            break;
        case 's':
            goldenRatio->showSpiralLines = !goldenRatio->showSpiralLines;
            break;
            
        default:
            shapeCount = 1;
            break;
    }
}
