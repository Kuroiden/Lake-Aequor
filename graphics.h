#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <glut.h>
#include <cmath>

class gameGraphics {
public:
	float lakeColorR;
	float lakeColorG;
	float lakeColorB;

	bool areaToggle;

	void circle(float centerX, float centerY, float radius, int segments) {
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(centerX, centerY);
		for (int i = 0; i <= segments; i++) {
			float theta = 2.0f * 3.1415926f * float(i) / float(segments);
			float x = radius * cosf(theta);
			float y = radius * sinf(theta);
			glVertex2f(x + centerX, y + centerY);
		}
		glEnd();
	}

	void semicircle(float centerX, float centerY, float radius, int segments) {
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(centerX, centerY);
		for (int i = 0; i <= segments; i++) {
			float theta = 3.1415926f * float(i) / float(segments);
			float x = radius * cosf(theta);
			float y = radius * sinf(theta);
			glVertex2f(x + centerX, y + centerY);
		}
		glEnd();
	}

	void drawText(float r, float g, float b, float x, float y, const char* text);
	void drawTimerBar(float progress);
	void drawReelMeter(float progress);

	void gameBackground(float lakeColorR, float lakeColorG, float lakeColorB, bool areaToggle);
	void shop();
	void compendium(int pageChange);
	void catchScreen();

	void bobber();

	void rodDisplay(float r, float g, float b, float x, float y);
	void priceTag(float x, float y, const char* price);
	void soldSign(float x);
	void confirmationScreen(float x, const char* rod);
	void purchasefailedScreen();

	void credits();
};

#endif