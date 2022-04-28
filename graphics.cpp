#include "graphics.h"
#include "Button.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

GLdouble width, height;
int wd;
int numTries;
int maxTries;
Button spawn({1, 0, 0}, {100, 100}, 100, 50, "Spawn");
Button tutorial({.43,.32,.19},{160,400}, 250,150,"Tutorial");
Button easy({.43,.32,.19},{415,400}, 250,150,"Easy");
Button medium({.43,.32,.19},{160,555}, 250,150,"Medium");
Button hard({.43,.32,.19},{415,555}, 250,150,"Hard");
vector<Quad> confetti;
enum screen {open, tutorialScreen,easyScreen, mediumScreen, hardScreen, close};
screen screenStatus = open;

void spawnConfetti() {
    confetti.push_back(Quad({rand() % 10 / 10.0, rand() % 10 / 10.0, rand() % 10 / 10.0}, {rand() % (int)width, rand() % (int)height}, 10, 10));
}

void init() {
    width = 600;
    height = 800;
    srand(time(0));
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.8f, 0.0f, 1.0f); // Green and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, 2*width, 2* height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */

    if (screenStatus == open){
        tutorial.draw();
        easy.draw();
        medium.draw();
        hard.draw();
        string label = "Welcome to pin the tail on the Donkey!";
        glRasterPos2i(175,175);
        glColor3f(1, 1, 1);
        for (const char &letter : label) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }

        glFlush();
    }
    if (screenStatus == tutorialScreen){
        spawn.draw();

    }

    if (screenStatus == easyScreen){
        spawn.draw();

    }

    if (screenStatus == mediumScreen){
        spawn.draw();

    }

    if (screenStatus == hardScreen){
        spawn.draw();

    }

    if (screenStatus == close){
        string label = "Good job you spawned 100 confetti!";
        glRasterPos2i(150,100);
        for (const char &letter : label) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);

        }
        glFlush();
    }
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    if (key == 's'){
        screenStatus = tutorialScreen;
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            spawn.move(0,2);
            break;
        case GLUT_KEY_LEFT:
            spawn.move(-2,0);
            break;
        case GLUT_KEY_RIGHT:
            spawn.move(2,0);
            break;
        case GLUT_KEY_UP:
            spawn.move(0,-2);
            break;
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {
    //If the Button is overlapping with the (x, y) coordinate passed in, call the hover method. Otherwise, call the release method.
    if ((spawn.getLeftX()<x&&spawn.getRightX()>x)&&(spawn.getTopY()<y&&spawn.getBottomY()>y)){
        spawn.hover();
    }
    else{
        spawn.release();
    }
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    //If the left button is down and the cursor is overlapping with the Button, call the pressDown method. Otherwise, call the release method.
    if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN && spawn.isOverlapping(x,y)){
        spawn.pressDown();
    }
    else{
        spawn.release();
    }

    //If the left button is up and the cursor is overlapping with the Button, call spawnConfetti.
    if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && spawn.isOverlapping(x,y)){
        spawnConfetti();
    }

    if(screenStatus == open){
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && tutorial.isOverlapping(x,y)){
            screenStatus = tutorialScreen;
        }
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && easy.isOverlapping(x,y)){
            screenStatus = easyScreen;
        }
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && medium.isOverlapping(x,y)){
            screenStatus = mediumScreen;
        }
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && hard.isOverlapping(x,y)){
            screenStatus = hardScreen;
        }
    }

    glutPostRedisplay();
}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Pin The Tail On The Donkey!" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}

