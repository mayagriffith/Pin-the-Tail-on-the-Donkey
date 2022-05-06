#ifndef FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H
#define FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H
#include "Tail.h"

class Donkey {
protected:
    unsigned int sideLength;
    unsigned int x;
    unsigned int y;
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
    Donkey(int sideLength, int x, int y);

    //getter for x coordinate
    int getX() const;
    //getter for y coordinate
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

    /*
     * Requires: x and y coordinate
     * Modifies: nothing
     * Effects: returns true if user is overlapping the donkey
     */
    bool userOverlappingDonkey(int x, int y) const;

    /*
   * Requires: x and y coordinate
   * Modifies: nothing
   * Effects: returns an int  of how far the coordinates are from the donkey.
   */
    int calculateDistance(int x, int y);

    /*
    * Requires:nothing
    * Modifies: nothing
    * Effects: draws the donkey without the tail
    */
    virtual void draw() const;

    /*
  * Requires:nothing
  * Modifies: nothing
  * Effects: draws the full donkey with the tail.
  */
    void drawFullDonkey() const;

};


#endif //FINAL_PROJECT_CPLEFKA_MGRIFF13_DONKEY_H
