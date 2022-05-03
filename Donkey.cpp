#include "Quad.h"
#include "graphics.h"
#include "Donkey.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

Donkey::Donkey() {
    int sideLength = 8;
    int x = 100;
    int y = 100;
}

Donkey::Donkey(int sideLength, int x, int y) {
    this->sideLength = sideLength;
    this->x = x;
    this->y = y;
}

void Donkey::move(int deltaX, int deltaY) {
    x = deltaX;
    y = deltaY;
}

void Donkey::resize(unsigned int width, unsigned int height) {
    x = width;
    y = height;
}

void Donkey::draw() const {
    // Don't forget to set the color to the fill field
    int SIDE_LENGTH = sideLength;
    ifstream inFile("../scene.txt");
    inFile >> noskipws;
    int xCoord = x, yCoord = y;
    char letter;
    bool draw;
    while (inFile >> letter) {
        draw = true;
        switch(letter) {
            case 'r': glColor3f(1, 0, 0); break;//red
            case 'n' :glColor3f(.43, 1/2, 1/2); break;//brown
            case 'g': glColor3f(0, 1, 0); break;//green
            case 'b': glColor3f(0, 0, 0); break;//black
            case 'y': glColor3f(1, 1, 0); break;//yellow
            case 'm': glColor3f(1, 0, 1); break;//magenta
            case 'c': glColor3f(0, 1, 1); break;//cyan
            case 't': glColor3f(.5, .5, .5); break;//grey
            case 'l': glColor3f(.3, .3, .3); break;//darker gray
            case ' ': glColor3f(0.43, 0.32, 0.19); break;//dark brown background color

            default: // newline
                draw = false;
                xCoord = x;
                yCoord += SIDE_LENGTH;
        }
        if (draw) {
            glBegin(GL_QUADS);
            glVertex2i(xCoord, yCoord);
            glVertex2i(xCoord+SIDE_LENGTH, yCoord);
            glVertex2i(xCoord+SIDE_LENGTH, yCoord+SIDE_LENGTH);
            glVertex2i(xCoord, yCoord+SIDE_LENGTH);
            glEnd();
            xCoord += SIDE_LENGTH;
        }
    }
    inFile.close();
}