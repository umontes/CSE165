#include <iostream>
#include <math.h>
#include <vector>
#include "Rect.h"

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif


using namespace std;


// Store the width and height of the window
int width = 640, height = 640;

Rect p;
vector<Rect*> rects;
vector<char> taken;

//-------------------------------------------------------
// A function to draw the scene
//-------------------------------------------------------
void appDrawScene() {
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// draws the white grid in between the squares
	glColor3f(1,1,1);
	glBegin(GL_LINES);

	glVertex2f(-0.33, 1);
	glVertex2f(-0.33, -1);

	glVertex2f(0.33, 1);
	glVertex2f(0.33, -1);

	glVertex2f(-1, 0.33);
	glVertex2f(1, 0.33);

	glVertex2f(-1, -0.33);
	glVertex2f(1, -0.33);

	glEnd();

	// draws the rects from the beginning of main function
	for (int i = 0; i < rects.size(); i++){
		rects[i]->draw();
	}

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

//-------------------------------------------------------
// A function to convert window coordinates to scene
// We use it when a mouse event is handled
// Arguments: 	
//	x, y - the coordinates to be updated
//-------------------------------------------------------
void windowToScene(float& x, float& y) {
	x = (2.0f*(x / float(width))) - 1.0f;
	y = 1.0f - (2.0f*(y / float(height)));
}

//-------------------------------------------------------
// A function to handle window resizing
// Called every time the window is resized
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appReshapeFunc(int w, int h) {
	// Window size has changed
	width = w;
	height = h;

	double scale, center;
	double winXmin, winXmax, winYmin, winYmax;

	// Define x-axis and y-axis range
	const double appXmin = -1.0;
	const double appXmax = 1.0;
	const double appYmin = -1.0;
	const double appYmax = 1.0;

	// Define that OpenGL should use the whole window for rendering
	glViewport(0, 0, w, h);

	// Set up the projection matrix using a orthographic projection that will
	// maintain the aspect ratio of the scene no matter the aspect ratio of
	// the window, and also set the min/max coordinates to be the disered ones
	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;

	if ((appXmax - appXmin) / w < (appYmax - appYmin) / h) {
		scale = ((appYmax - appYmin) / h) / ((appXmax - appXmin) / w);
		center = (appXmax + appXmin) / 2;
		winXmin = center - (center - appXmin)*scale;
		winXmax = center + (appXmax - center)*scale;
		winYmin = appYmin;
		winYmax = appYmax;
	}
	else {
		scale = ((appXmax - appXmin) / w) / ((appYmax - appYmin) / h);
		center = (appYmax + appYmin) / 2;
		winYmin = center - (center - appYmin)*scale;
		winYmax = center + (appYmax - center)*scale;
		winXmin = appXmin;
		winXmax = appXmax;
	}

	// Now we use glOrtho to set up our viewing frustum
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(winXmin, winXmax, winYmin, winYmax, -1, 1);
}


//-------------------------------------------------------
// A function to handle mouse clicks
// Called every time the mouse button goes up or down
// Arguments: 	
//	b    - mouse button that was clicked, left or right
//	s 	 - state, either mouse-up or mouse-down
//	x, y - coordinates of the mouse when click occured
//-------------------------------------------------------
void appMouseFunc(int b, int s, int x, int y) {
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	// Your code here...

	// checks if the square was clicked
	for (int i = 0; i < rects.size(); i++){
			if (b == 0 && rects[i]->contains(mx,my) && taken[i] == '0'){
				rects[i]->select_x();
				taken[i] = 'X';

				if (taken[0] == 'X' && taken[1] == 'X' && taken[2] == 'X'){
					cout << "X wins!" << endl;
					exit(0);
				}
				else if (taken[3] == 'X' && taken[4] == 'X' && taken[5] == 'X'){
					cout << "X wins!" << endl;
					exit(0);
				}
				else if (taken[6] == 'X' && taken[7] == 'X' && taken[8] == 'X'){
					cout << "X wins!" << endl;
					exit(0);
				}
				else if (taken[0] == 'X' && taken[3] == 'X' && taken[6] == 'X') {
					cout << "X wins!" << endl;
					exit(0);
				}
				else if (taken[1] == 'X' && taken[4] == 'X' && taken[7] == 'X') {
					cout << "X wins!" << endl;
					exit(0);
				}
				else if (taken[2] == 'X' && taken[5] == 'X' && taken[8] == 'X') {
					cout << "X wins!" << endl;
					exit(0);
				}
				else if (taken[0] == 'X' && taken[4] == 'X' && taken[8] == 'X') {
					cout << "X wins!" << endl;
					exit(0);
				}
				else if (taken[2] == 'X' && taken[4] == 'X' && taken[6] == 'X') {
					cout << "X wins!" << endl;
					exit(0);
				}
				else if (taken[0] != '0' && taken[1] != '0' && taken[2] != '0' && taken[3] != '0' && taken[4] != '0' && taken[5] != '0' && taken[6] != '0' && taken[7] != '0' && taken[8] != '0'){
					cout << "Tie!";
					exit(0);
				}

				break;
			}
			else if (b == 2 && rects[i]->contains(mx,my) && taken[i] == '0'){
				rects[i]->select_o();
				taken[i] = 'O';

				if (taken[0] == 'O' && taken[1] == 'O' && taken[2] == 'O'){
					cout << "O wins!" << endl;
					exit(0);
				}
				else if (taken[3] == 'O' && taken[4] == 'O' && taken[5] == 'O'){
					cout << "O wins!" << endl;
					exit(0);
				}
				else if (taken[6] == 'O' && taken[7] == 'O' && taken[8] == 'O'){
					cout << "O wins!" << endl;
					exit(0);
				}
				else if (taken[0] == 'O' && taken[3] == 'O' && taken[6] == 'O') {
					cout << "O wins!" << endl;
					exit(0);
				}
				else if (taken[1] == 'O' && taken[4] == 'O' && taken[7] == 'O') {
					cout << "O wins!" << endl;
					exit(0);
				}
				else if (taken[2] == 'O' && taken[5] == 'O' && taken[8] == 'O') {
					cout << "O wins!" << endl;
					exit(0);
				}
				else if (taken[0] == 'O' && taken[4] == 'O' && taken[8] == 'O') {
					cout << "O wins!" << endl;
					exit(0);
				}
				else if (taken[2] == 'O' && taken[4] == 'O' && taken[6] == 'O') {
					cout << "O wins!" << endl;
					exit(0);
				}
				else if (taken[0] != '0' && taken[1] != '0' && taken[2] != '0' && taken[3] != '0' && taken[4] != '0' && taken[5] != '0' && taken[6] != '0' && taken[7] != '0' && taken[8] != '0'){
					cout << "Tie!";
					exit(0);
				}

				break;
			}
	}

	// Redraw the scene by calling appDrawScene above
	// so that the point we added above will get painted
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle mouse dragging
// Called every time mouse moves while button held down
// Arguments: 	
//	x, y - current coordinates of the mouse
//-------------------------------------------------------
void appMotionFunc(int x, int y) {
	// Convert from Window to Scene coordinates
	float mx = (float)x;
	float my = (float)y;

	windowToScene(mx, my);

	// Your code here...

	// Again, we redraw the scene
	glutPostRedisplay();
}

//-------------------------------------------------------
// A function to handle keyboard events
// Called every time a key is pressed on the keyboard
// Arguments: 	
//	key  - the key that was pressed
//	x, y - coordinates of the mouse when key is pressed
//-------------------------------------------------------
void appKeyboardFunc(unsigned char key, int x, int y) {
	// Define what should happen for a given key press 
	switch (key) {	
		// Escape was pressed. Quit the program
	case 27:
		exit(0);
		break;
		// More cases here if you need...
	}
	// After all the state changes, redraw the scene
	glutPostRedisplay();
}

void appKeyboardUpFunc(unsigned char key, int x, int y) {

}

void idle(){

}


int main(int argc, char** argv) {

	for (int i = 0; i < 9; i++){
		taken.push_back('0');
	}

	rects.push_back(new Rect(-1, 1, 0.665, 0.665));
	rects.push_back(new Rect(-0.33, 1, 0.665, 0.665));
	rects.push_back(new Rect(0.33, 1, 0.665, 0.665));

	rects.push_back(new Rect(-1, 0.33, 0.665, 0.665));
	rects.push_back(new Rect(-0.33, 0.33, 0.665, 0.665));
	rects.push_back(new Rect(0.33, 0.33, 0.665, 0.665));

	rects.push_back(new Rect(-1, -0.33, 0.665, 0.665));
	rects.push_back(new Rect(-0.33, -0.33, 0.665, 0.665));
	rects.push_back(new Rect(0.33, -0.33, 0.665, 0.665));

	cout << "Left click for X" << endl;
	cout << "Right click for O" << endl;

	// char opponent;
	// cout << "Type 'AI' if you would like to play against the computer" << endl;
	// cin >> opponent;

	// if (opponent == 'AI' || opponent == 'ai'){
		
	// }

	// TEXT(GLUT_BITMAP_HELVETICA_12, "Left Click for X", 100, 160);

	// Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

	// Setup window position, size, and title
	glutInitWindowPosition(20, 60);
	// Start with a slightly smaller window (bug in macOS Catalina)
	glutInitWindowSize(width-1, height-1);

	// Create the window
	glutCreateWindow("CSE165 OpenGL Demo");

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);


	// Set callback for drawing the scene
	glutDisplayFunc(appDrawScene);

	// Set callback for resizing th window
	glutReshapeFunc(appReshapeFunc);

	// Set callback to handle mouse clicks
	glutMouseFunc(appMouseFunc);

	// Set callback to handle mouse dragging
	glutMotionFunc(appMotionFunc);

	// Set callback to handle keyboad events
	glutKeyboardFunc(appKeyboardFunc);

	// This gets triggered when we release a keyboard key
	glutKeyboardUpFunc(appKeyboardUpFunc);
    
	// Resize your window to the desired size (bug in macOS Catalina)
    glutReshapeWindow(width, height);

	// Set the idle function. It gets called repeatedly all the time
	glutIdleFunc(idle);

	// Start the main loop
	glutMainLoop();
}
