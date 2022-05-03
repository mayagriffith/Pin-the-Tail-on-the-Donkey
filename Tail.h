//
// Created by Maya Griffith on 5/3/22.
//

#ifndef FINAL_PROJECT_CPLEFKA_MGRIFF13_TAIL_H
#define FINAL_PROJECT_CPLEFKA_MGRIFF13_TAIL_H


class Tail {

protected:
    point center;
    unsigned int width;
    unsigned int height;
public:
    //constructors
    Tail();
    Tail(point center, unsigned int width, unsigned int height);

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


#endif //FINAL_PROJECT_CPLEFKA_MGRIFF13_TAIL_H
