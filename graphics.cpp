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

//global variables
GLdouble width, height;
int wd;
//variables for tries and boolean for winning game
int numTries = 0;
int maxTries = 10;
bool gameWon = false;
//button declaration
Button tutorial({.45,.97,.46},{160,400}, 250,150,"Tutorial");
Button easy({.23,.54,.24},{415,400}, 250,150,"Easy");
Button medium({.141,.35,.149},{160,555}, 250,150,"Medium");
Button hard({.023,.19,.029},{415,555}, 250,150,"Hard");
Quad hide({0.43, 0.32, .19},{300,450},600,775);
//enum for displaying different screens
enum screen {open, tutorialScreen,easyScreen, mediumScreen, hardScreen};
screen screenStatus = open;
//Declaring Donkeys and Tails, one for the games and one for the tutorial
Donkey geraldTut(6, 180, 250);
Donkey gerald(6, 100, 100);
Tail geraldTail(6,425,333);
Tail geraldTutTail(6, 425, 333);
//global distance variable for displaying user's distance from the donkey
int dist = 0;

//Half screen sized window to play game
void init() {
    width = 600;
    height = 800;
    srand(time(0));
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.43f, 0.32f, 0.19f, 1.0f); // Dark brown background color
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

    //Display for opening screen with 4 button options to play
    if (screenStatus == open){
        //draw all four buttons
        tutorial.draw();
        easy.draw();
        medium.draw();
        hard.draw();
        //display opening text
        string label = "Welcome to pin the tail on the Donkey!";
        glRasterPos2i(195,175);
        glColor3f(1, 1, 1);
        for (const char &letter : label) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }
        //display text to quit program
        string label2 = "Press the esc key to quit";
        glRasterPos2i(225,790);
        for (const char &letter : label2) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
        }
        glFlush();
    }

    //Display for tutorial screen that allows the user to see where they can place the tail on the donkey
    if (screenStatus == tutorialScreen){
        //display text of the instructions to pin the tail
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
        //if the user clicks on the right spot and the game is won then draw full donkey, if not draw the donkey without a tail and the tail
        if (gameWon==false) {
            geraldTut.draw();
            geraldTutTail.draw();
        }
        else {
            geraldTut.drawFullDonkey();
        }
        glFlush();
    }

    //Display for the screen of the easy mode of the game
    if (screenStatus == easyScreen){
        //if the user has not clicked on the donkey display instructions and draw the tail
        if (gameWon==false){
            string label = "The donkey is hidden somewhere random on the screen, click and and find it. You have unlimited tries!";
            glColor3f(1, 1, 1);
            glRasterPos2i(50,30);
            for (const char &letter : label) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            string distanceScore = "Your distance is:" + to_string(dist-0) + " pixels";
            glRasterPos2i(240,45);
            for (const char &letter : distanceScore) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            geraldTail.draw();
        }
        //if the user has won the game display the winning text along with how many tries it took the user to find the donkey
        //as well as displaying the full donkey with it's tail
        else{
            glColor3f(1, 1, 1);
            glRasterPos2i(100,50);
            string label = "You won and found the donkey! It took you "+ to_string(numTries)  + " tries to find it!";
            glRasterPos2i(150,30);
            glColor3f(1, 1, 1);
            for (const char &letter : label) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            string label2 = "Press 'b' to return to the home screen";
            glRasterPos2i(220,43);
            glColor3f(1, 1, 1);
            for (const char &letter : label2) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            gerald.drawFullDonkey();
            hide.move(10000,10000);
        }
        glFlush();
    }

    //Display for the screen of the medium mode of the game
    if (screenStatus == mediumScreen){
        //if the user has not clicked on the donkey display instructions and draw the tail
        if (gameWon==false){
            string label = "The donkey is hidden somewhere random on the screen, you have "+ to_string(maxTries - numTries)  + " more tries to find it! ";
            glColor3f(1, 1, 1);
            glRasterPos2i(50,30);
            for (const char &letter : label) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            string distanceScore = "Your distance is:" + to_string(dist-0) + " pixels";
            glRasterPos2i(240,45);
            for (const char &letter : distanceScore) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            geraldTail.draw();
            //if the user reaches the max amount of tries set the gameWin bool to true in order to display the whole donkey
            if (numTries==maxTries){
                gameWon = true;
            }
        }
        else{
            //if the user has 'won' because the ran out of tries display losing message and draw the full donkey
            if (numTries==maxTries){
                string lostMessage = "You ran out of tries, here's the donkey! Press 'b' to return to the home screen";
                glRasterPos2i(120,45);
                for (const char &letter : lostMessage) {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
                }
                gerald.drawFullDonkey();
                hide.move(10000,10000);
            }
            // the user has won, displaying ending message with user's tries and display the full donkey
            else{
                glColor3f(1, 1, 1);
                glRasterPos2i(25,50);
                string label = "You won and found the donkey! It took you "+ to_string(numTries)  + " tries to find it!";
                glRasterPos2i(150,30);
                glColor3f(1, 1, 1);
                for (const char &letter : label) {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
                }
                string label2 = "Press 'b' to return to the home screen";
                glRasterPos2i(220,43);
                glColor3f(1, 1, 1);
                for (const char &letter : label2) {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
                }
                gerald.drawFullDonkey();
                hide.move(10000,10000);
            }
        }
        glFlush();
    }

    //Display for the screen of the hard mode of the game
    if (screenStatus == hardScreen){
        //if the user has not clicked on the donkey display instructions and draw the tail
        if (gameWon==false){
            string label = "The donkey is hidden somewhere random on the screen, you have "+ to_string(maxTries - numTries)  + " more tries to find it! ";
            glColor3f(1, 1, 1);
            glRasterPos2i(50,30);
            for (const char &letter : label) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            string distanceScore = "Your distance is: " + to_string(dist-0) + " pixels";
            glRasterPos2i(240,45);
            for (const char &letter : distanceScore) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
            }
            geraldTail.draw();
            //if the user reaches the max amount of tries set the gameWin bool to true in order to display the whole donkey
            if (numTries==maxTries){
                gameWon = true;
            }
        }
        else{
            //if the user has 'won' because the ran out of tries display losing message and draw the full donkey
            if(numTries==maxTries){
                string lostMessage = "You ran out of tries, here's the donkey! Press 'b' to return to the home screen";
                glRasterPos2i(120,45);
                for (const char &letter : lostMessage) {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
                }
                gerald.drawFullDonkey();
                hide.move(10000,10000);
            }
            // the user has won, displaying ending message with user's tries and display the full donkey
            else{
                glColor3f(1, 1, 1);
                glRasterPos2i(25,50);
                string label = "You won and found the donkey! It took you "+ to_string(numTries)  + " tries to find it!";
                glRasterPos2i(150,30);
                glColor3f(1, 1, 1);
                for (const char &letter : label) {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
                }
                string label2 = "Press 'b' to return to the home screen";
                glRasterPos2i(220,43);
                glColor3f(1, 1, 1);
                for (const char &letter : label2) {
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
                }
                gerald.drawFullDonkey();
                hide.move(10000,10000);
            }
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
    //if you want to go back to the open screen
    if (key == 'b'){
        //reset game status, numtries, and distance if the user goes back to the open screen
        screenStatus = open;
        gameWon = false;
        numTries = 0;
        dist = 0;
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
    //no matter the screen set the tail to move with the user's mouse position
    if (screenStatus == tutorialScreen){
        geraldTutTail.move(x,y);
    }
    if (screenStatus == easyScreen){
        geraldTail.move(x,y);
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
        //if click on tutorial screen button, go to tutorial
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && tutorial.isOverlapping(x,y)){
            screenStatus = tutorialScreen;
        }
        //if click on easy screen button, go to easy. Move gerald somewhere random on the screen.
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && easy.isOverlapping(x,y)){
            screenStatus = easyScreen;
            gerald.move(rand()%int(320),rand()%int(550)+30);
        }
        //if click on medium screen button, go to medium. Move gerald somewhere random on the screen.
        //max tries is 5 for medium game
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && medium.isOverlapping(x,y)){
            screenStatus = mediumScreen;
            gerald.move(rand()%int(320),rand()%int(550)+30);
            maxTries = 5;
        }
        //if click on hard screen button, go to hard. Move gerald somewhere random on the screen.
        //max tries is 3 for hard game
        if(button==GLUT_LEFT_BUTTON && state == GLUT_UP && hard.isOverlapping(x,y)){
            screenStatus = hardScreen;
            gerald.move(rand()%int(320),rand()%int(550)+30);
            maxTries = 3;
        }
    }
    if (screenStatus == tutorialScreen){
        //if user clicks on the coordinates of the donkey's butt area the game is won in the tutorial
        if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN && ((x<440&&x>390)&&(y<370&&y>310))){
            gameWon= true;
        }
    }
    else if (screenStatus == easyScreen) {
        //if the user clicks on the donkey
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            if (gerald.userOverlappingDonkey(x, y)){
                //game is won!
                gameWon = true;
            }
            else if (gameWon==false){
                //didn't click on the donkey so..
                numTries++;
                dist = gerald.calculateDistance(x,y);
            }
        }
    }
    else if (screenStatus == mediumScreen) {
        //if the user clicks on the donkey
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gerald.userOverlappingDonkey(x, y)) {
            //game is won!
            gameWon = true;
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gameWon==false) {
            //didn't click on the donkey so...
            dist = gerald.calculateDistance(x,y);
            numTries++;
        }

    }
    else if (screenStatus == hardScreen) {
        //if the user click on the donkey
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gerald.userOverlappingDonkey(x, y)) {
            //Game is won!
            gameWon = true;
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && gameWon==false) {
            //didn't click on the donkey so...
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