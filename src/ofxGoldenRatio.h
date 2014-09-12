//
//  GoldenRatio.h
//  GoldenRatio
//
//  Created by Mitsuya.WATANABE on 2014/08/21.
//
//

#ifndef __GoldenRatio__GoldenRatio__
#define __GoldenRatio__GoldenRatio__

#include <iostream>

#endif /* defined(__GoldenRatio__GoldenRatio__) */

#pragma once

#include "ofMain.h"
// This is golden ratio (黄金比)
static const float kGoldenRatio = (1 + sqrt(5.0)) / 2;
static const float kAngle = 45.0;
static const float kTheta = (kAngle * PI / 180);

/**
 *  define for right spiral (Clockwise)
 */
typedef enum {
    VectorDirectionLB2RT = 0, // leftButtom to rightTop
    VectorDirectionLT2RB, // leftTop to rightBottom
    VectorDirectionRT2LB, // rightTop to leftBottom
    VectorDirectionRB2LT // rightButtom to leftTop
}VectorDirection;

typedef enum {
    SpiralDirectionRight,
    SpiralDirectionLeft
}SpiralDirection;

class ofxGoldenRatio : public ofBaseApp {
public:
    virtual ~ofxGoldenRatio();
    ofxGoldenRatio();
    void drawFigure(float startPosX, float startPosY, float length, float division);

    ofColor targetColor;
    bool showSpiralLines;
};

static VectorDirection direction;
static VectorDirection nextDirection();
static void getPosition(float *xPos, float *yPos, float radius);
static void drawSquare(float x, float y, float length);
static void drawOblong(float xPos, float yPos, float nextW, float nextH);