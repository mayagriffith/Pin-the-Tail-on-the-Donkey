#ifndef FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H
#define FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H


class Donkey {
protected:
    unsigned int sideLength;
    unsigned int x;
    unsigned int y;
public:
    //constructors
    Donkey();
    Donkey(int sideLength, int x, int y);

    //getters setters
    int getCenterX() const;
    int getLeftX() const;
    int getRightX() const;
    int getCenterY() const;
    int getTopY() const;
    int getBottomY() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;

};


#endif //FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H
