#include "DrawShapes.h"

/* Reference points + size always draws a full rectangle, as such, all shapes
should fit inside to make further position calculations easier.
AKA:
- The reference point is the top left corner of the shape.
- The size is the width and height (hit box) of the shape. */

void DrawCar(window& w, color c, int rx, int ry, int size) {
	w.SetPen(c); w.SetBrush(c);
	// Draw body
	w.DrawRectangle(rx, ry + size / 2, rx + size, ry + size * 7 / 8);

	// Wheels color
	color cWheels = color(85 - c.ucRed, 85 - c.ucGreen, 85 - c.ucBlue);
	w.SetPen(cWheels); w.SetBrush(cWheels);

	// Draw wheels
	w.DrawCircle(rx + size / 4, ry + size * 7 / 8, size / 8);
	w.DrawCircle(rx + size * 3 / 4, ry + size * 7 / 8, size / 8);

	// Top color
	color cTop = color(255 - c.ucRed, 255 - c.ucGreen, 255 - c.ucBlue);
	w.SetPen(cTop); w.SetBrush(cTop);

	// Draw top: rectangle in the center and two triangles on the sides
	w.DrawRectangle(rx + size / 4, ry + size / 4, rx + size * 3 / 4, ry + size / 2);
	w.DrawTriangle(rx, ry + size / 2, rx + size / 4, ry + size / 4, rx + size / 4, ry + size / 2);
	w.DrawTriangle(rx + size * 3 / 4, ry + size / 4, rx + size, ry + size / 2, rx + size * 3 / 4, ry + size / 2);

	// Windows color
	color cWindows = color(170 - c.ucRed, 170 - c.ucGreen, 170 - c.ucBlue);
	w.SetPen(cWindows); w.SetBrush(cWindows);

	// Draw windows
	w.DrawRectangle(rx + size / 8, ry + size * 2 / 5, rx + size * 3 / 8, ry + size * 4 / 6);
	w.DrawRectangle(rx + size * 5 / 8, ry + size * 2 / 5, rx + size * 7 / 8, ry + size * 4 / 6);
}

void DrawHouse(window& w, color c, int rx, int ry, int size) {
	w.SetPen(c); w.SetBrush(c);
	// 2/3 of the size is the height of the house
	w.DrawRectangle(rx, ry + size / 3, rx + size, ry + size);

	// Roof color
	color cInverted = color(255 - c.ucRed, 255 - c.ucGreen, 255 - c.ucBlue);
	w.SetPen(cInverted); w.SetBrush(cInverted);

	// Draw roof
	w.DrawTriangle(rx, ry + size / 3, rx + size, ry + size / 3, rx + size / 2, ry);
}

void DrawCloud(window& w, color c, int rx, int ry, int size) {
	w.SetPen(c); w.SetBrush(c);
	// Draw cloud
	w.DrawCircle(rx + size / 2, ry + size / 2, size / 4);
	w.DrawCircle(rx + size - size/4, ry + size / 2, size / 4);
	w.DrawCircle(rx - size / 4 + size / 2, ry + size / 2, size / 4);
	w.DrawCircle(rx + size / 8 + size / 2, ry - size / 8 + size / 2, size / 4);
	w.DrawCircle(rx - size / 8 + size / 2, ry - size / 8 + size / 2, size / 4);
}