//
// Created by Maya Griffith on 5/2/22.
//

#ifndef FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H
#define FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H


struct color {
    double red;
    double green;
    double blue;
};

struct point {
    int x;
    int y;
};

class Donkey {
protected:
    point center;
    unsigned int width;
    unsigned int height;
public:
    //constructors
    Donkey();
    Quad(point center, unsigned int width, unsigned int height);

    //getters setters
    int getCenterX() const;
    int getLeftX() const;
    int getRightX() const;
    int getCenterY() const;
    int getTopY() const;
    int getBottomY() const;
    point getCenter() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;



};


#endif //FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H
