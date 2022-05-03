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
    point getCenter() const;

    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    color getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setColor(double red, double green, double blue);
    void setColor(color fill);
    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;
};

#endif //FINAL_PROJECT_CPLEFKA_MGRIFF13_QUAD_H
