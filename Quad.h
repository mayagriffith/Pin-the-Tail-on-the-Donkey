#ifndef FINAL_PROJECT_CPLEFKA_MGRIFF13_QUAD_H
#define FINAL_PROJECT_CPLEFKA_MGRIFF13_QUAD_H

//struct for colors
struct color {
    double red;
    double green;
    double blue;
};

//struct for a point
struct point {
    int x;
    int y;
};

class Quad {
protected:
    color fill;
    point center;
    unsigned int width;
    unsigned int height;

public:
    /*
     * Default Constructor
     * Requires: nothing
     * Modifies: color fill, point center, int width, height
     * Effects: sets fill to black, centers at 0,0, width of 50, height of 50
     */
    Quad();

    /*
    * Requires: nothing
    * Modifies: color fill, point center, int width, height
    * Effects: sets fill to parameter, centers at parameter, width of parameter, height of parameter
    */
    Quad(color fill, point center, unsigned int width, unsigned int height);

    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns int as center coordinate of Quad
   */
    int getCenterX() const;
    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns int as LeftX coordinate of Quad
   */
    int getLeftX() const;
    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns int as rightX coordinate of Quad
   */
    int getRightX() const;
    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns int as centerY coordinate of Quad
   */
    int getCenterY() const;
    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns int as TopY coordinate of Quad
   */
    int getTopY() const;
    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns int as BottomY coordinate of Quad
   */
    int getBottomY() const;
    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns a point (x and y) as center coordinate of Quad
   */
    point getCenter() const;

    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns double as how much red
   */
    double getRed() const;
    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns double of how much green
   */
    double getGreen() const;
    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns double of how much blue
   */
    double getBlue() const;
    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns the color of the Quad
   */
    color getFill() const;



    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns int as center coordinate of Quad
   */
    unsigned int getWidth() const;

    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: returns int as center coordinate of Quad
   */
    unsigned int getHeight() const;

    /*
   * Requires: 3 doubles, red green and blue
   * Modifies: the color of the quad
   * Effects: changes color
   */
    void setColor(double red, double green, double blue);
    /*
   * Requires: 1 color
   * Modifies: the color of the quad
   * Effects: changes color
   */
    void setColor(color fill);
    /*
   * Requires: int x and y
   * Modifies: the position of the quad
   * Effects: moves the quad
   */
    void move(int deltaX, int deltaY);
    /*
   * Requires: int width, int height
   * Modifies: the size of quad
   * Effects: changes size
   */
    void resize(unsigned int width, unsigned int height);

    /*
   * Requires: nothing
   * Modifies: nothing
   * Effects: draws the quad
   */
    virtual void draw() const;
};

#endif //FINAL_PROJECT_CPLEFKA_MGRIFF13_QUAD_H
