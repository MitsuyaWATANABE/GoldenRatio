//
//  GoldenRatio.cpp
//  GoldenRatio
//
//  Created by Mitsuya.WATANABE on 2014/08/21.
//
//

#include "ofxGoldenRatio.h"

ofxGoldenRatio::ofxGoldenRatio() {
    direction = VectorDirectionLB2RT;
    ofEnableAlphaBlending();
    targetColor  = ofColor(255,0,0);
    showSpiralLines = false;
}

ofxGoldenRatio::~ofxGoldenRatio() {
}

void ofxGoldenRatio::drawFigure(float startPosX, float startPosY, float length, float division) {
    // Directionを初期化
    direction = VectorDirectionLB2RT;
    
    float count = 0;
    float radius = 1 / pow(kGoldenRatio, count + 1) * length;
    float xPos = startPosX;
    float yPos = sin(kTheta) * radius + startPosY;
    float alpha = 0.0;
    float minColVal = 50.0;
    float maxColVal = 200.0;
    
    ofPushMatrix();
    for (int i = 0; i < division; i++) {
        startPosX = xPos;
        startPosY = yPos;
        getPosition(&xPos, &yPos, radius);
        ofTranslate(startPosX, startPosY);
        ofFill();
        alpha = ofMap(i, 0.0, division, minColVal, maxColVal, true);
        ofSetColor(targetColor, alpha);
        drawSquare(xPos, yPos, xPos);
        
        if (showSpiralLines) {
            ofSetColor(255, 255, 255);
            ofLine(0.0, 0.0, xPos, yPos);
        }
        
        if (i == division - 1) {
            // 長方形を描画
            ofSetColor(targetColor, 255.0);
            float nextW = 1.0 / pow(kGoldenRatio, count + 2) * length;
            nextW = cos(kTheta) * nextW;
            float nextH = xPos;
            drawOblong(xPos, yPos, nextW, nextH);
        }
        
        count++;
        
        // NOTE: 正方形の1辺は黄金比のベキ乗分の1ごとに小さくなっていく
        radius = 1.0 / pow(kGoldenRatio, count + 1) * length;
        direction = nextDirection();
    }
    ofPopMatrix();
}

/**
 長方形を描画
 */
static void drawOblong(float xPos, float yPos, float nextW, float nextH) {
    switch (direction) {
        case VectorDirectionLB2RT:
            ofRect(xPos, yPos, nextW, nextH);
            break;
        case VectorDirectionLT2RB:
            xPos -= xPos;
            ofRect(xPos, yPos, nextH, nextW);
            break;
        case VectorDirectionRT2LB:
            xPos -= nextW;
            ofRect(xPos, yPos, nextW, nextH);
            break;
        case VectorDirectionRB2LT:
            yPos -= nextW;
            xPos -= nextH;
            ofRect(xPos, yPos, nextH, nextW);
            break;            
        default:
            break;
    }

}

/**
    正方形を描画
 */
static void drawSquare(float x, float y, float length) {
    
    switch (direction) {
        case VectorDirectionLB2RT:
            x -= length;
            break;
        case VectorDirectionLT2RB:
            x -= length;
            y -= length;
            break;
        case VectorDirectionRT2LB:
            x -= length;
            break;
        case VectorDirectionRB2LT:
            x -= length;
            y -= length;
            
            break;
            
        default:
            break;
    }
    ofRect(x, y, length, length);
}

/**
 *  座標を更新
 *  NOTE: 黄金比で分割する座標位置をセットする
 */
static void getPosition(float *xPos, float *yPos, float radius) {
    switch (direction) {
        case VectorDirectionLB2RT:
            *xPos = cos(kTheta) * radius;
            *yPos = -sin(kTheta) * radius;
            break;
        case VectorDirectionLT2RB:
            *xPos = cos(kTheta) * radius;
            *yPos = sin(kTheta) * radius;
            break;
        case VectorDirectionRT2LB:
            *xPos = -cos(kTheta) * radius;
            *yPos = sin(kTheta) * radius;
            break;
        case VectorDirectionRB2LT:
            *xPos = -cos(kTheta) * radius;
            *yPos = -sin(kTheta) * radius;
            break;
            
        default:
            break;
    }
}

/**
 *  渦巻きの方向を更新 (右回りのみ実装)
 */
static VectorDirection nextDirection() {
    //    if (spiral == SpiralDirectionRight) {
    VectorDirection nextVDirection;
    
    switch (direction) {
        case VectorDirectionLB2RT:
            nextVDirection = VectorDirectionLT2RB;
            break;
        case VectorDirectionLT2RB:
            nextVDirection = VectorDirectionRT2LB;
            break;
        case VectorDirectionRT2LB:
            nextVDirection = VectorDirectionRB2LT;
            break;
        case VectorDirectionRB2LT:
            nextVDirection = VectorDirectionLB2RT;
            break;
    }
    //    }
    
    return nextVDirection;
}
