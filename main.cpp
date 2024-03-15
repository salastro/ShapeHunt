#include <iostream>
#include <sstream>
#include <cmath>
#include <ctime>

#include "CMUgraphicsLib\CMUgraphics.h"
#include "draw_composite_shapes.h"

void ClearWindow(window& w) {
	w.SetPen(WHITE);
	w.SetBrush(WHITE);
	w.DrawRectangle(0, 0, w.GetWidth(), w.GetHeight());
}

int main() {
	// Seed random number generator
	srand(time(0));

	// Create window
	const int WIDTH = 1000, HEIGHT = 700;
	int x = 50, y = 50;
	window mainWindow(WIDTH, HEIGHT, x, y);
	mainWindow.ChangeTitle("Shape Hunt");

	// Message
	mainWindow.SetPen(BLACK);
	mainWindow.SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	mainWindow.DrawString(5, 5, "Welcome!!!");

	// Keyboard input
	char keyboardCharacter;
	mainWindow.FlushKeyQueue();

	// Draw shapes
	int padding = 50, minSize = 25, maxSize = 100;
	int size, rx, ry;
	color shapeColor;

	// mainWindow.DrawRectangle(100, 100, 200, 200);
	// DrawCar(mainWindow, RED, 100, 100, 100);

	while (true) {
		// Get keyboard input
		mainWindow.GetKeyPress(keyboardCharacter);

		// Generate random shape
		shapeColor = color(rand() % 256, rand() % 256, rand() % 256);  // Random color bc why not ;)
		size = rand() % (maxSize - minSize) + minSize;
		rx = rand() % (WIDTH - size - padding) + padding / 3; // Divide by 3 because of edge issue
		ry = rand() % (HEIGHT - size - padding) + padding / 3; // Divide by 3 because of edge issue

		switch (keyboardCharacter) {
		case 'c':
			DrawCar(mainWindow, shapeColor, rx, ry, size);
			break;
		case 'h':
			DrawHouse(mainWindow, shapeColor, rx, ry, size);
			break;
		case 'l':
			DrawCloud(mainWindow, shapeColor, rx, ry, size);
			break;
		case 'i':
			DrawIceCream(mainWindow, shapeColor, rx, ry, size);
			break;
		case '[':
			ClearWindow(mainWindow);
			break;
		case 'q':
			exit(0);
			break;
		default:
			break;
		}
	}

	return 0;
}
