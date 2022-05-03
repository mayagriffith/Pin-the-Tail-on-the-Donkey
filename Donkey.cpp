#include "Quad.h"
#include "graphics.h"
#include "Donkey.h"

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

int Donkey::getCenterX() const {
    return center.x;
}

int Donkey::getLeftX() const {
    return center.x - (width / 2);
}

int Donkey::getRightX() const {
    return center.x + (width / 2);
}

int Donkey::getCenterY() const {
    return center.y;
}

int Donkey::getTopY() const {
    return center.y - (height / 2);
}

int Donkey::getBottomY() const {
    return center.y + (height / 2);
}

unsigned int Donkey::getWidth() const {
    return width;
}

unsigned int Donkey::getHeight() const {
    return height;
}

void Donkey::setColor(double red, double green, double blue) {
    fill = {red, green, blue};
}

void Donkey::setColor(color fill) {
    this->fill = fill;
}

void Donkey::move(int deltaX, int deltaY) {
    center.x += deltaX;
    center.y += deltaY;
}

void Donkey::resize(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
}

void Donkey::draw() const {
    // Don't forget to set the color to the fill field
    SIDE_LENGTH = sideLength;
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
            case ' ': glColor3f(1, 1, 1); break;//white?


            default: // newline
                draw = false;
                xCoord = 0;
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