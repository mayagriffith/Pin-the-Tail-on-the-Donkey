#ifndef FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H
#define FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H


class Donkey {
protected:
    unsigned int sideLength;
    unsigned int x;
    unsigned int y;
    bool tail;
public:
    /*
     * Default Constructor
     * Requires: nothing
     * Modifies: int sideLength, int x, int y
     * Effects: sets sideLength to 8, x to 100 y to 100
     */
    Donkey();
    /*
     * Requires: int sideLength, int x, int y
     * Modifies: nothing
     * Effects: sets sideLength to parameter, x and y to parameter
     */
    Donkey(int sideLength, int x, int y, bool tail);

    int getX() const;
    int getY() const;

    /*
     * Requires: nothing
     * Modifies: X and Y
     * Effects: moves the Donkey
     */
    void move(int deltaX, int deltaY);

    /*
     * Requires: nothing
     * Modifies: X and Y
     * Effects: moves the Donkey
     */
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;
    void drawFullDonkey() const;

};


#endif //FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H
