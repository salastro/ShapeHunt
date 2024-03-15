#include "window_utils.h"

void ClearWindow(window& w) {
	w.SetPen(WHITE);
	w.SetBrush(WHITE);
	w.DrawRectangle(0, 0, w.GetWidth(), w.GetHeight());
}

void DrawMenu(window& w, const string itemsMenu[], int itemsCount, int itemSize) {
	// Draw menu item one image at a time

	for (int i = 0; i < itemsCount; i++)
		w.DrawImage(itemsMenu[i], i * itemSize, 0, itemSize, itemSize);

	// Draw a line under the toolbar
	w.SetPen(RED, 3);
	w.DrawLine(0, itemSize, w.GetWidth(), itemSize);
}
