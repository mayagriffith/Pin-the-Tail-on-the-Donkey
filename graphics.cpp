#include "graphics.h"
#include "Button.h"
#include "Donkey.h"
#include "Tail.h"
#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
using namespace std;

GLdouble width, height;
int wd;
int numTries = 0;
int maxTries = 10;
bool gameWon = false;
Button spawn({1, 0, 0}, {100, 100}, 100, 50, "Spawn");
Button tutorial({.45,.97,.46},{160,400}, 250,150,"Tutorial");
Button easy({.23,.54,.24},{415,400}, 250,150,"Easy");
Button medium({.141,.35,.149},{160,555}, 250,150,"Medium");
Button hard({.023,.19,.029},{415,555}, 250,150,"Hard");
Quad hide({0.43, 0.32, 1},{300,450},600,775);//fill blue in to .19 when done with testing
enum screen {open, tutorialScreen,easyScreen, mediumScreen, hardScreen};
screen screenStatus = open;
Donkey geraldTut(6, 180, 250);
Donkey gerald(6, 100, 100);
Tail geraldTail(6,425,333);
Tail geraldTutTail(6, 425, 333);

int dist = 0;
int p=0;

void init() {
    width = 600;
    height = 800;
    srand(time(0));
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.43f, 0.32f, 0.19f, 1.0f); // Green and opaque
}

void initUser() {
    //user is the tail
    //create tail
    //switch screens for each level?
    //user.setSize(20.0,20.0);
    //
    //user.setColor(white);

    // centered in the top left corner of the graphics window
    //user.setCenter(0,0);

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
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );

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
        glColor3f(1, 1, 1);
        string label = "~ Your goal is to place the tail on the donkey that is randomly hidden on the screen somewhere";
        glRasterPos2i(75,105);
        for (const char &letter : label) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }
        glColor3f(1, 1, 1);
        label = "                     ~ The harder the difficulty, the less tries you have to find the donkey ";
        glRasterPos2i(75,120);
        for (const char &letter : label) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }
        label = "                 ~ This tutorial shows how you can place the tail on the donkey to win the game ";
        glRasterPos2i(75,135);
        for (const char &letter : label) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }
        label= "                                         ~ Press 'b' to return to the home screen ";
        glRasterPos2i(75,150);
        glColor3f(1, 1, 1);
        for (const char &letter : label) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }
        if (gameWon==false) {
            geraldTut.draw();
            geraldTutTail.draw();
        }
        else {
            geraldTut.drawFullDonkey();
        }

        glFlush();
    }

    if (screenStatus == easyScreen){
        if (gameWon==false){
            string label = "The donkey is hidden somewhere random on the screen, click and and find it. You have unlimited tries!";
            glColor3f(1, 1, 1);
            glRasterPos2i(100,30);
            for (const char &letter : label) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            string distanceScore = "Your distance is:" + to_string(dist-0) + " pixels";
            glRasterPos2i(100,20);
            for (const char &letter : distanceScore) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
           // hide.draw();
            //gerald.draw();
            geraldTail.draw();
            //hide.move(300,425);
        }
        else{
            glColor3f(1, 1, 1);
            glRasterPos2i(25,50);
            string label = "You won and found the donkey! It took you "+ to_string(numTries)  + " tries to find it!";
            glRasterPos2i(150,30);
            glColor3f(1, 1, 1);
            for (const char &letter : label) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            gerald.drawFullDonkey();
            hide.move(10000,10000);
        }
        glFlush();
    }

    if (screenStatus == mediumScreen){
        if (gameWon==false){
            string label = "The donkey is hidden somewhere random on the screen, you have "+ to_string(maxTries - numTries)  + " more tries to find it! ";
            glColor3f(1, 1, 1);
            glRasterPos2i(100,30);
            for (const char &letter : label) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            string distanceScore = "Your distance is:" + to_string(dist-0) + " pixels";
            glRasterPos2i(100,20);
            for (const char &letter : distanceScore) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
           // hide.draw();
            //gerald.draw();
            geraldTail.draw();
            //hide.move(300,425);
        }
        else{
            glColor3f(1, 1, 1);
            glRasterPos2i(25,50);
            string label = "You won and found the donkey! It took you "+ to_string(numTries)  + " tries to find it!";
            glRasterPos2i(150,30);
            glColor3f(1, 1, 1);
            for (const char &letter : label) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            gerald.drawFullDonkey();
            hide.move(10000,10000);
        }
        glFlush();
    }

    if (screenStatus == hardScreen){
        if (gameWon==false){
            string label = "The donkey is hidden somewhere random on the screen, you have "+ to_string(maxTries - numTries)  + " more tries to find it! ";
            glColor3f(1, 1, 1);
            glRasterPos2i(100,30);
            for (const char &letter : label) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            string distanceScore = "Your distance is: " + to_string(dist-0) + " pixels";
            glRasterPos2i(100,20);
            for (const char &letter : distanceScore) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
           // hide.draw();
            //gerald.draw();
            geraldTail.draw();
            //hide.move(300,425);
        }
        else{
            glColor3f(1, 1, 1);
            glRasterPos2i(25,50);
            string label = "You won and found the donkey! It took you "+ to_string(numTries)  + " tries to find it!";
            glRasterPos2i(150,30);
            glColor3f(1, 1, 1);
            for (const char &letter : label) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            gerald.drawFullDonkey();
            hide.move(10000,10000);
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
    if (key == 'b'){
        screenStatus = open;
        gameWon = false;
        numTries = 0;
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_UP:
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

    if (screenStatus == tutorialScreen){
        geraldTutTail.move(x,y);
    }
    if (screenStatus == easyScreen){
        geraldTail.move(x,y);
        maxTries = 10;
    }

    if (screenStatus == mediumScreen){
        geraldTail.move(x,y);
    }
    if (screenStatus == hardScreen){
        geraldTail.move(x,y);
    }

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    //If it is the opening screen go to the corresponding screen of the user button click
    if(screenStatus == open){
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && tutorial.isOverlapping(x,y)){
            screenStatus = tutorialScreen;
        }
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && easy.isOverlapping(x,y)){
            screenStatus = easyScreen;
            gerald.move(rand()%int(320),rand()%int(550)+30);
        }
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && medium.isOverlapping(x,y)){
            screenStatus = mediumScreen;
            gerald.move(rand()%int(320),rand()%int(550)+30);
            maxTries = 5;
        }
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && hard.isOverlapping(x,y)){
            screenStatus = hardScreen;
            gerald.move(rand()%int(320),rand()%int(550)+30);
            maxTries = 3;
        }
    }
    if (screenStatus == tutorialScreen){
        //donkey is overlapping method instead
        if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN && gerald.userOverlappingDonkey(x,y)){
            gameWon= true;
        }
    }
    else if (screenStatus == easyScreen) {
        //donkey is overlapping method instead
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (gerald.userOverlappingDonkey(x, y)){
                gameWon = true;
            }
                numTries++;
                dist = gerald.calculateDistance(x,y);


        }
    }
    else if (screenStatus == mediumScreen) {
        //donkey is overlapping method instead
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gerald.userOverlappingDonkey(x, y)) {
            gameWon = true;
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            dist = gerald.calculateDistance(x,y);
            numTries++;
        }

    }
    else if (screenStatus == hardScreen) {
        //donkey is overlapping method instead
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gerald.userOverlappingDonkey(x, y)) {
            gameWon = true;
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            dist = gerald.calculateDistance(x,y);
            numTries++;
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

