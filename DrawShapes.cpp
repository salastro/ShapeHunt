#include "DrawShapes.h"

/* Reference points + size always draws a full rectangle, as such, all shapes
should fit inside to make further position calculations easier*/

void DrawHouse(window& w, color c, int rx, int ry, int size) {
	w.SetPen(c); w.SetBrush(c);
	// 2/3 of the size is the height of the house
	w.DrawRectangle(rx, ry + size / 3, rx + size, ry + size);

	// New color for the roof
	color cInverted = color(255 - c.ucRed, 255 - c.ucGreen, 255 - c.ucBlue);
	w.SetPen(cInverted); w.SetBrush(cInverted);

	// Draw roof
	w.DrawTriangle(rx, ry + size / 3, rx + size, ry + size / 3, rx + size / 2, ry);
}