//
// Created by Maya Griffith on 5/3/22.
//

#ifndef FINAL_PROJECT_CPLEFKA_MGRIFF13_TAIL_H
#define FINAL_PROJECT_CPLEFKA_MGRIFF13_TAIL_H


class Tail {
protected:
    unsigned int sideLength;
    unsigned int x;
    unsigned int y;
public:
    //constructors
    Tail();
    Tail(int sideLength, int x, int y);

    int getX() const;
    int getY() const;

    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;

};

#endif //FINAL_PROJECT_CPLEFKA_MGRIFF13_TAIL_H
