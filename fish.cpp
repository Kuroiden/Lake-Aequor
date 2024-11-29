/* Original code by Juliana Ambos, Nivron Dela Cruz, Cloe Gorgonio, & Jermaine Malinis */
/* Modified by Cloe Gorgonio */

#include "fish.h"

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
void fish::bangus(float scale, float x, float y) {
    //fins
    glColor3f(0.4, 0.4, 0.4);//top fins
    glBegin(GL_TRIANGLES);//back back fin
    glVertex2f((0.5f * scale) - x, (0.125f * scale) - y);
    glVertex2f((0.6f * scale) - x, (0.0f * scale) - y);
    glVertex2f((0.6f * scale) - x, (0.25f * scale) - y);
    glEnd();

    glBegin(GL_TRIANGLES);//back fin
    glVertex2f((0.2f * scale) - x, (0.125f * scale) - y);
    glVertex2f((0.3f * scale) - x, (0.025f * scale) - y);
    glVertex2f((0.3f * scale) - x, (0.225f * scale) - y);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((0.35f * scale) - x, (0.05f * scale) - y);  // Bottom left corner
    glVertex2f((0.45f * scale) - x, (0.075f * scale) - y);  // Bottom right corner
    glVertex2f((0.45f * scale) - x, (0.1f * scale) - y);  // Top right corner
    glVertex2f((0.35f * scale) - x, (0.125f * scale) - y);  // Top left corner
    glEnd();

    //body
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f((0.05f * scale) - x, (0.1f * scale) - y);  // Bottom left corner
    glVertex2f((0.2f * scale) - x, (0.05f * scale) - y);  // Bottom right corner
    glVertex2f((0.2f * scale) - x, (0.2f * scale) - y);  // Top right corner
    glVertex2f((0.05f * scale) - x, (0.15f * scale) - y);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((0.2f * scale) - x, (0.05f * scale) - y);  // Bottom left corner
    glVertex2f((0.25f * scale) - x, (0.05f * scale) - y);  // Bottom right corner
    glVertex2f((0.25f * scale) - x, (0.2f * scale) - y);  // Top right corner
    glVertex2f((0.2f * scale) - x, (0.2f * scale) - y);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((0.25f * scale) - x, (0.05f * scale) - y);  // Bottom left corner
    glVertex2f((0.55f * scale) - x, (0.1f * scale) - y);  // Bottom right corner
    glVertex2f((0.55f * scale) - x, (0.15f * scale) - y);  // Top right corner
    glVertex2f((0.25f * scale) - x, (0.2f * scale) - y);  // Top left corner
    glEnd();

    glColor3f(0.6, 0.6, 0.4);
    glBegin(GL_QUADS);
    glVertex2f((0.05f * scale) - x, (0.1f * scale) - y);  // Bottom left corner
    glVertex2f((0.125f * scale) - x, (0.075f * scale) - y);  // Bottom right corner
    glVertex2f((0.125f * scale) - x, (0.175f * scale) - y);  // Top right corner
    glVertex2f((0.05f * scale) - x, (0.15f * scale) - y);  // Top left corner
    glEnd();

    //face
    //eyes
    glColor3f(1.0, 1.0, 1.0);
    circle((0.1f * scale) - x, (0.15f * scale) - y, 0.012f * scale, 10);

    glColor3f(0.0, 0.0, 0.0);
    circle((0.1f * scale) - x, (0.15f * scale) - y, 0.01f * scale, 10);
}
void fish::betta(float scale, float x, float y) {}
void fish::carp(float scale, float x, float y) {
    //fins

    glColor3f(0.5, 0.3, 0.0);//top fins
    glBegin(GL_TRIANGLES);//back back fin
    glVertex2f(0.4f, 0.125f);
    glVertex2f(0.5f, 0.05f);
    glVertex2f(0.5f, 0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);//back fin
    glVertex2f(0.35f, 0.05f);
    glVertex2f(0.4f, 0.05f);
    glVertex2f(0.4f, 0.025f);
    glEnd();

    glBegin(GL_TRIANGLES);//back fin
    glVertex2f(0.2f, 0.05f);
    glVertex2f(0.25f, 0.05f);
    glVertex2f(0.25f, 0.025f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.2f, 0.175f);  // Bottom left corner
    glVertex2f(0.375f, 0.15f);  // Bottom right corner
    glVertex2f(0.4f, 0.2f);  // Top right corner
    glVertex2f(0.225f, 0.225f);  // Top left corner
    glEnd();

    //body
    glColor3f(0.7, 0.5, 0.0);
    glBegin(GL_TRIANGLES);//head
    glVertex2f(0.5f, 0.15f);
    glVertex2f(0.125f, 0.05f);
    glVertex2f(0.2f, 0.2f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.125f, 0.05f);  // Bottom left corner
    glVertex2f(0.4f, 0.05f);  // Bottom right corner
    glVertex2f(0.4f, 0.175f);  // Top right corner
    glVertex2f(0.2f, 0.2f);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.4f, 0.05f);  // Bottom left corner
    glVertex2f(0.45f, 0.1f);  // Bottom right corner
    glVertex2f(0.45f, 0.15f);  // Top right corner
    glVertex2f(0.4f, 0.175f);  // Top left corner
    glEnd();

    //face
    //eyes
    glColor3f(1.0, 1.0, 1.0);
    circle(0.1f, 0.15f, 0.012f, 10);

    glColor3f(0.0, 0.0, 0.0);
    circle(0.1f, 0.15f, 0.01f, 10);
}
void fish::catfish(float scale, float x, float y) { // Original by Nivron Dela Cruz
    // tail fin
    glColor3f(0.5, 0.25, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f((0.45f * scale) - x, (0.15f * scale) - y);
    glVertex2f((0.55f * scale) - x, (0.075f * scale) - y);
    glVertex2f((0.55f * scale) - x, (0.225f * scale) - y);
    glEnd();

    //body
    glColor3f(1.0, 0.5, 0.0);//body
    circle((0.15f * scale) - x, (0.15f * scale) - y, 0.1f * scale, 100);
    glBegin(GL_QUADS);
    glVertex2f((0.15f * scale) - x, (0.05f * scale) - y);  // Bottom left corner
    glVertex2f((0.4f * scale) - x, (0.05f * scale) - y);  // Bottom right corner
    glVertex2f((0.4f * scale) - x, (0.25f * scale) - y);  // Top right corner
    glVertex2f((0.15f * scale) - x, (0.25f * scale) - y);  // Top left corner
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f((0.4f * scale) - x, (0.05f * scale) - y);  // Bottom left corner
    glVertex2f((0.5f * scale) - x, (0.125f * scale) - y);  // Bottom right corner
    glVertex2f((0.5f * scale) - x, (0.175f * scale) - y);  // Top right corner
    glVertex2f((0.4f * scale) - x, (0.25f * scale) - y);  // Top left corner
    glEnd();

    //top fins
    glColor3f(0.5, 0.25, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f((0.075f * scale) - x, (0.2f * scale) - y);
    glVertex2f((0.075f * scale) - x, (0.3f * scale) - y);
    glVertex2f((0.1f * scale) - x, (0.225f * scale) - y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f((0.175f * scale) - x, (0.2f * scale) - y);
    glVertex2f((0.175f * scale) - x, (0.3f * scale) - y);
    glVertex2f((0.15f * scale) - x, (0.225f * scale) - y);
    glEnd();

    //face
    //eyes
    glColor3f(1.0, 1.0, 1.0);
    circle((0.15f * scale) - x, (0.2f * scale) - y, 0.012f * scale, 10);
    circle((0.1f * scale) - x, (0.2f * scale) - y, 0.012f * scale, 10);

    glColor3f(0.0, 0.0, 0.0);
    circle((0.15f * scale) - x, (0.2f * scale) - y, 0.01f * scale, 10);
    circle((0.1f * scale) - x, (0.2f * scale) - y, 0.01f * scale, 10);

    //whiskers
    glBegin(GL_LINES);
    glVertex2f((0.075f * scale) - x, (0.125f * scale) - y);
    glVertex2f((0.175f * scale) - x, (0.175f * scale) - y);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f((0.075f * scale) - x, (0.175f * scale) - y);
    glVertex2f((0.175f * scale) - x, (0.125f * scale) - y);
    glEnd();

    glColor3f(0.5, 0.25, 0.0);
    glBegin(GL_LINES);
    glVertex2f((0.075f * scale) - x, (0.15f * scale) - y);
    glVertex2f((0.175f * scale) - x, (0.15f * scale) - y);
    glEnd();

    glColor3f(1.0, 0.4, 0.9);
    circle((0.125f * scale) - x, (0.15f * scale) - y, 0.01f * scale, 10);

    //stripes
    glColor3f(0.5, 0.25, 0.0);

    glBegin(GL_QUADS);
    glVertex2f((0.25f * scale) - x, (0.15f * scale) - y);  // Bottom left corner
    glVertex2f((0.275f * scale) - x, (0.15f * scale) - y);  // Bottom right corner
    glVertex2f((0.275f * scale) - x, (0.25f * scale) - y);  // Top right corner
    glVertex2f((0.25f * scale) - x, (0.25f * scale) - y);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((0.3f * scale) - x, (0.15f * scale) - y);  // Bottom left corner
    glVertex2f((0.325f * scale) - x, (0.15f * scale) - y);  // Bottom right corner
    glVertex2f((0.325f * scale) - x, (0.25f * scale) - y);  // Top right corner
    glVertex2f((0.3f * scale) - x, (0.25f * scale) - y);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((0.35f * scale) - x, (0.15f * scale) - y);  // Bottom left corner
    glVertex2f((0.375f * scale) - x, (0.15f * scale) - y);  // Bottom right corner
    glVertex2f((0.375f * scale) - x, (0.25f * scale) - y);  // Top right corner
    glVertex2f((0.35f * scale) - x, (0.25f * scale) - y);  // Top left corner
    glEnd();
}
void fish::goldfish(float scale, float x, float y) {
    //fins

    glColor3f(0.9, 0.5, 0.0);//top fins
    glBegin(GL_QUADS);
    glVertex2f(0.15f, 0.15f);  // Bottom left corner
    glVertex2f(0.25f, 0.125f);  // Bottom right corner
    glVertex2f(0.25f, 0.15f);  // Top right corner
    glVertex2f(0.15f, 0.175f);  // Top left corner
    glEnd();

    glBegin(GL_TRIANGLES);//lower fin
    glVertex2f(0.15f, 0.05f);
    glVertex2f(0.15f, 0.025f);
    glVertex2f(0.175f, 0.075f);
    glEnd();

    glBegin(GL_TRIANGLES);//back fin
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.3f, 0.05f);
    glVertex2f(0.3f, 0.15f);
    glEnd();

    //body
    glColor3f(1.0, 0.8, 0.0);//body
    glBegin(GL_QUADS);
    glVertex2f(0.05f, 0.075f);  // Bottom left corner
    glVertex2f(0.15f, 0.05f);  // Bottom right corner
    glVertex2f(0.15f, 0.15f);  // Top right corner
    glVertex2f(0.05f, 0.125f);  // Top left corner
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.15f, 0.05f);  // Bottom left corner
    glVertex2f(0.25f, 0.075f);  // Bottom right corner
    glVertex2f(0.025f, 0.125f);  // Top right corner
    glVertex2f(0.15f, 0.15f);  // Top left corner
    glEnd();

    //face
    //eyes
    glColor3f(1.0, 1.0, 1.0);
    circle(0.075f, 0.1f, 0.007f, 10);

    glColor3f(0.0, 0.0, 0.0);
    circle(0.075f, 0.1f, 0.005f, 10);
}
void fish::AUfish(float scale, float x, float y) {
    //fins

    glColor3f(1.0, 0.8, 0.0);//top fins
    glBegin(GL_QUADS);
    glVertex2f(0.15f, 0.25f);  // Bottom left corner
    glVertex2f(0.35f, 0.25f);  // Bottom right corner
    glVertex2f(0.4f, 0.35f);  // Top right corner
    glVertex2f(0.2f, 0.35f);  // Top left corner
    glEnd();

    glBegin(GL_TRIANGLES);//back fin
    glVertex2f(0.4f, 0.15f);
    glVertex2f(0.55f, 0.05f);
    glVertex2f(0.55f, 0.25f);
    glEnd();

    //body
    glColor3f(1.0, 1.0, 0.0);//body
    glBegin(GL_QUADS);
    glVertex2f(0.05f, 0.05f);  // Bottom left corner
    glVertex2f(0.45f, 0.05f);  // Bottom right corner
    glVertex2f(0.4f, 0.25f);  // Top right corner
    glVertex2f(0.1f, 0.25f);  // Top left corner
    glEnd();

    //face
    //eyes
    glColor3f(1.0, 1.0, 1.0);
    circle(0.1f, 0.1f, 0.012f, 10);

    glColor3f(0.0, 0.0, 0.0);
    circle(0.1f, 0.1f, 0.01f, 10);
}
/* FIX THIS */
void fish::janitorFish(float scale, float x, float y) {
    //face
        //eyes
    glColor3f(0.0, 0.0, 0.0);
    circle((0.1f * scale) - x, (0.15f * scale) - y, 0.01f * scale, 10);

    glColor3f(1.0, 1.0, 1.0);
    circle((0.1f * scale) - x, (0.15f * scale) - y, 0.012f * scale, 10);
    //body
    //teeth
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex2f((0.05f * scale) - x, (0.05f * scale) - y);  // Bottom left corner
    glVertex2f((0.075f * scale) - x, (0.05f * scale) - y);  // Bottom right corner
    glVertex2f((0.075f * scale) - x, (0.125f * scale) - y);  // Top right corner
    glVertex2f((0.05f * scale) - x, (0.125f * scale) - y);  // Top left corner
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f((0.1f * scale) - x, (0.025f * scale) - y);  // Bottom left corner
    glVertex2f((0.125f * scale) - x, (0.025f * scale) - y);  // Bottom right corner
    glVertex2f((0.125f * scale) - x, (0.1f * scale) - y);  // Top right corner
    glVertex2f((0.1f * scale) - x, (0.1f * scale) - y);  // Top left corner
    glEnd();

    glColor3f(0.1, 0.1, 0.1);//upper body
    glBegin(GL_QUADS);
    glVertex2f(50.0f, 100.0f);  // Bottom left corner
    glVertex2f(150.0f, 50.0f);  // Bottom right corner
    glVertex2f(150.0f, 200.0f);  // Top right corner
    glVertex2f(50.0f, 150.0f);  // Top left corner
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(150.0f, 50.0f);  // Bottom left corner
    glVertex2f(400.0f, 50.0f);  // Bottom right corner
    glVertex2f(400.0f, 200.0f);  // Top right corner
    glVertex2f(150.0f, 200.0f);  // Top left corner
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(400.0f, 50.0f);  // Bottom left corner
    glVertex2f(600.0f, 100.0f);  // Bottom right corner
    glVertex2f(600.0f, 150.0f);  // Top right corner
    glVertex2f(400.0f, 200.0f);  // Top left corner
    glEnd();

    //fins

    glColor3f(0.6, 0.4, 0.0);
    glBegin(GL_TRIANGLES);//back fins
    glVertex2f(550.0f, 125.0f);
    glVertex2f(650.0f, 50.0f);
    glVertex2f(650.0f, 200.0f);
    glEnd();
    glBegin(GL_QUADS);//top fin
    glVertex2f(250.0f, 200.0f);  // Bottom left corner
    glVertex2f(300.0f, 200.0f);  // Bottom right corner
    glVertex2f(400.0f, 300.0f);  // Top right corner
    glVertex2f(300.0f, 300.0f);  // Top left corner
    glEnd();
    glBegin(GL_QUADS);//right bottom fin
    glVertex2f(450.0f, 25.0f);  // Bottom left corner
    glVertex2f(525.0f, 50.0f);  // Bottom right corner
    glVertex2f(525.0f, 100.0f);  // Top right corner
    glVertex2f(450.0f, 100.0f);  // Top left corner
    glEnd();
    glBegin(GL_TRIANGLES);//middle bottom fin
    glVertex2f(250.0f, 0.0f);
    glVertex2f(250.0f, 50.0f);
    glVertex2f(300.0f, 50.0f);
    glEnd();
    glBegin(GL_TRIANGLES);//left bottom fin
    glVertex2f(150.0f, 0.0f);
    glVertex2f(150.0f, 50.0f);
    glVertex2f(200.0f, 50.0f);
    glEnd();
}
void fish::koi(float scale, float x, float y) {}
void fish::tilapia(float scale, float x, float y) {
    //fins

    glColor3f(0.0, 0.3, 0.6);//top fins
    glBegin(GL_TRIANGLES);//back back fin
    glVertex2f(0.4f, 0.175f);
    glVertex2f(0.5f, 0.1f);
    glVertex2f(0.5f, 0.25f);
    glEnd();

    glBegin(GL_TRIANGLES);//back fin
    glVertex2f(0.125f, 0.05f);
    glVertex2f(0.125f, 0.1f);
    glVertex2f(0.175f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.1f, 0.2f);  // Bottom left corner
    glVertex2f(0.4f, 0.2f);  // Bottom right corner
    glVertex2f(0.45f, 0.35f);  // Top right corner
    glVertex2f(0.15f, 0.3f);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.35f, 0.05f);  // Bottom left corner
    glVertex2f(0.4f, 0.05f);  // Bottom right corner
    glVertex2f(0.35f, 0.15f);  // Top right corner
    glVertex2f(0.3f, 0.15f);  // Top left corner
    glEnd();

    //body
    glColor3f(0.2, 0.5, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(0.05f, 0.15f);  // Bottom left corner
    glVertex2f(0.1f, 0.1f);  // Bottom right corner
    glVertex2f(0.1f, 0.25f);  // Top right corner
    glVertex2f(0.05f, 0.175f);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.1f, 0.1f);  // Bottom left corner
    glVertex2f(0.35f, 0.1f);  // Bottom right corner
    glVertex2f(0.35f, 0.25f);  // Top right corner
    glVertex2f(0.1f, 0.25f);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.35f, 0.1f);  // Bottom left corner
    glVertex2f(0.45f, 0.15f);  // Bottom right corner
    glVertex2f(0.45f, 0.2f);  // Top right corner
    glVertex2f(0.35f, 0.25f);  // Top left corner
    glEnd();

    //face
            //eyes
    glColor3f(1.0, 1.0, 1.0);
    circle(0.075f, 0.175f, 0.012f, 10);

    glColor3f(0.0, 0.0, 0.0);
    circle(0.075f, 0.175f, 0.01f, 10);
}
void fish::trout(float scale, float x, float y) {
    //fins

    glColor3f(0.4, 0.4, 0.4);//top fins
    glBegin(GL_TRIANGLES);//back back fin
    glVertex2f(0.5f, 0.125f);
    glVertex2f(0.6f, 0.05f);
    glVertex2f(0.6f, 0.2f);
    glEnd();

    glBegin(GL_TRIANGLES);//back fin
    glVertex2f(0.35f, 0.125f);
    glVertex2f(0.45f, 0.05f);
    glVertex2f(0.45f, 0.1f);
    glEnd();

    glBegin(GL_TRIANGLES);//back fin
    glVertex2f(0.25f, 0.2f);
    glVertex2f(0.3f, 0.225f);
    glVertex2f(0.3f, 0.175f);
    glEnd();

    //body
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex2f(0.05f, 0.1f);  // Bottom left corner
    glVertex2f(0.2f, 0.05f);  // Bottom right corner
    glVertex2f(0.2f, 0.2f);  // Top right corner
    glVertex2f(0.05f, 0.15f);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.2f, 0.05f);  // Bottom left corner
    glVertex2f(0.25f, 0.05f);  // Bottom right corner
    glVertex2f(0.25f, 0.2f);  // Top right corner
    glVertex2f(0.2f, 0.2f);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.25f, 0.05f);  // Bottom left corner
    glVertex2f(0.55f, 0.1f);  // Bottom right corner
    glVertex2f(0.55f, 0.15f);  // Top right corner
    glVertex2f(0.25f, 0.2f);  // Top left corner
    glEnd();

    //face
        //eyes
    glColor3f(1.0, 1.0, 1.0);
    circle(0.1f, 0.15f, 0.012f, 10);

    glColor3f(0.0, 0.0, 0.0);
    circle(0.1f, 0.15f, 0.01f, 10);
}

/* ADJUST FOR SIZE */
void fish::anchovy(float scale, float x, float y) {
    // Set color to light gray for the fish body
    glColor3f(0.8f, 0.8f, 0.8f);

    // Draw the fish body (a simple elongated rectangle)
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f, 0.1f);  // Top left
    glVertex2f(0.6f, 0.1f);  // Top right
    glVertex2f(0.6f, -0.1f); // Bottom right
    glVertex2f(-0.6f, -0.1f); // Bottom left
    glEnd();

    // Set color to light blue for the fish tail
    glColor3f(0.5f, 0.7f, 1.0f);

    // Draw the fish tail (a triangle)
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6f, 0.1f);   // Left top corner
    glVertex2f(-0.8f, 0.3f);   // Tail upper point
    glVertex2f(-0.8f, -0.3f);  // Tail lower point
    glEnd();

    // Set color to black for the fish's eye
    glColor3f(0.0f, 0.0f, 0.0f);

    // Draw the fish's eye (a small circle)
    glBegin(GL_POLYGON);
    float angle;
    int num_segments = 30;
    for (int i = 0; i < num_segments; i++) {
        angle = 2 * 3.14159f * i / num_segments;
        glVertex2f(0.2f + 0.05f * cos(angle), 0.05f + 0.05f * sin(angle));
    }
    glEnd();
}
void fish::bass(float scale, float x, float y) {
    //fins
    glColor3f(0.6, 0.8, 0.6);
    glBegin(GL_QUADS);
    glVertex2f((0.55f * scale) - x, (0.1f * scale) - y);  // Bottom left corner
    glVertex2f((0.6f * scale) - x, (0.075f * scale) - y);  // Bottom right corner
    glVertex2f((0.6f * scale) - x, (0.175f * scale) - y);  // Top right corner
    glVertex2f((0.55f * scale) - x, (0.15f * scale) - y);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((0.15f * scale) - x, (0.2f * scale) - y);  // Bottom left corner
    glVertex2f((0.3f * scale) - x, (0.2f * scale) - y);  // Bottom right corner
    glVertex2f((0.25f * scale) - x, (0.225f * scale) - y);  // Top right corner
    glVertex2f((0.2f * scale) - x, (0.225f * scale) - y);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((0.275f * scale) - x, (0.2f * scale) - y);  // Bottom left corner
    glVertex2f((0.4f * scale) - x, (0.2f * scale) - y);  // Bottom right corner
    glVertex2f((0.425f * scale) - x, (0.25f * scale) - y);  // Top right corner
    glVertex2f((0.3f * scale) - x, (0.25f * scale) - y);  // Top left corner
    glEnd();

    //body
    glColor3f(1.0, 0.7, 0.7);
    circle((0.1f * scale) - x, (0.1f * scale) - y, 0.051f * scale, 10);

    glColor3f(0.6, 0.8, 0.6);//front fins
    glBegin(GL_TRIANGLES);
    glVertex2f((0.255f * scale) - x, (0.125f * scale) - y);
    glVertex2f((0.275f * scale) - x, (0.125f * scale) - y);
    glVertex2f((0.25f * scale) - x, (0.075f * scale) - y);
    glEnd();

    glColor3f(0.4, 0.8, 0.5);
    circle((0.1f * scale) - x, (0.1f * scale) - y, 0.055f * scale, 10);

    glBegin(GL_QUADS);
    glVertex2f((0.1f * scale) - x, (0.1f * scale) - y);  // Bottom left corner
    glVertex2f((0.15f * scale) - x, (0.05f * scale) - y);  // Bottom right corner
    glVertex2f((0.15f * scale) - x, (0.2f * scale) - y);  // Top right corner
    glVertex2f((0.1f * scale) - x, (0.15f * scale) - y);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((0.15f * scale) - x, (0.05f * scale) - y);  // Bottom left corner
    glVertex2f((0.4f * scale) - x, (0.05f * scale) - y);  // Bottom right corner
    glVertex2f((0.4f * scale) - x, (0.2f * scale) - y);  // Top right corner
    glVertex2f((0.15f * scale) - x, (0.2f * scale) - y);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((0.4f * scale) - x, (0.05f * scale) - y);  // Bottom left corner
    glVertex2f((0.5f * scale) - x, (0.1f * scale) - y);  // Bottom right corner
    glVertex2f((0.5f * scale) - x, (0.15f * scale) - y);  // Top right corner
    glVertex2f((0.4f * scale) - x, (0.2f * scale) - y);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((0.5f * scale) - x, (0.1f * scale) - y);  // Bottom left corner
    glVertex2f((0.55f * scale) - x, (0.1f * scale) - y);  // Bottom right corner
    glVertex2f((0.55f * scale) - x, (0.15f * scale) - y);  // Top right corner
    glVertex2f((0.5f * scale) - x, (0.15f * scale) - y);  // Top left corner
    glEnd();

    //face
        //eyes
    glColor3f(0.0, 0.0, 0.0);
    circle((0.15f * scale) - x, (0.175f * scale) - y, 0.01f * scale, 10);

    glColor3f(1.0, 1.0, 1.0);
    circle((0.15f * scale) - x, (0.175f * scale) - y, 0.012f * scale, 10);
}
void fish::clownfish(float scale, float x, float y) {}
void fish::cod(float scale, float x, float y) {
    //fins

    glColor3f(0.4, 0.3, 0.0);//top fins
    glBegin(GL_TRIANGLES);//back back fin
    glVertex2f((0.4f * scale) - x, (0.1f * scale) - y);
    glVertex2f((0.45f * scale) - x, (0.05f * scale) - y);
    glVertex2f((0.45f * scale) - x, (0.15f * scale) - y);
    glEnd();

    glBegin(GL_TRIANGLES);//back fin
    glVertex2f((0.325f * scale) - x, (0.1f * scale) - y);
    glVertex2f((0.375f * scale) - x, (0.05f * scale) - y);
    glVertex2f((0.375f * scale) - x, (0.15f * scale) - y);
    glEnd();

    glBegin(GL_TRIANGLES);//middle fin
    glVertex2f((0.2f * scale) - x, (0.1f * scale) - y);
    glVertex2f((0.3f * scale) - x, 0.0f - y);
    glVertex2f((0.3f * scale) - x, (0.2f * scale) - y);
    glEnd();

    glBegin(GL_TRIANGLES);//top fin
    glVertex2f((0.15f * scale) - x, (0.15f * scale) - y);
    glVertex2f((0.2f * scale) - x, (0.15f * scale) - y);
    glVertex2f((0.2f * scale) - x, (0.2f * scale) - y);
    glEnd();

    glBegin(GL_TRIANGLES);//bottom fin
    glVertex2f((0.1f * scale) - x, (0.075f * scale) - y);
    glVertex2f((0.125f * scale) - x, (0.075f * scale) - y);
    glVertex2f((0.125f * scale) - x, (0.025f * scale) - y);
    glEnd();

    //body
    glColor3f(0.5, 0.4, 0.0);//top body
    glBegin(GL_QUADS);
    glVertex2f((0.05f * scale) - x, (0.1f * scale) - y);  // Bottom left corner
    glVertex2f((0.15f * scale) - x, (0.1f * scale) - y);  // Bottom right corner
    glVertex2f((0.15f * scale) - x, (0.15f * scale) - y);  // Top right corner
    glVertex2f((0.05f * scale) - x, (0.125f * scale) - y);  // Top left corner
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f((0.15f * scale) - x, (0.1f * scale) - y);  // Bottom left corner
    glVertex2f((0.45f * scale) - x, (0.1f * scale) - y);  // Bottom right corner
    glVertex2f((0.3f * scale) - x, (0.15f * scale) - y);  // Top right corner
    glVertex2f((0.15f * scale) - x, (0.15f * scale) - y);  // Top left corner
    glEnd();

    glColor3f(1.0, 1.0, 1.0);//bottom body
    glBegin(GL_QUADS);
    glVertex2f((0.05f * scale) - x, (0.075f * scale) - y);  // Bottom left corner
    glVertex2f((0.15f * scale) - x, (0.05f * scale) - y);  // Bottom right corner
    glVertex2f((0.15f * scale) - x, (0.1f * scale) - y);  // Top right corner
    glVertex2f((0.05f * scale) - x, (0.1f * scale) - y);  // Top left corner
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f((0.15f * scale) - x, (0.05f * scale) - y);  // Bottom left corner
    glVertex2f((0.3f * scale) - x, (0.05f * scale) - y);  // Bottom right corner
    glVertex2f((0.45f * scale) - x, (0.1f * scale) - y);  // Top right corner
    glVertex2f((0.15f * scale) - x, (0.1f * scale) - y);  // Top left corner
    glEnd();

    //face
    //eyes
    glColor3f(0.0, 0.0, 0.0);
    circle((0.075f * scale) - x, (0.11f * scale) - y, 0.01f * scale, 10);

    glColor3f(1.0, 1.0, 1.0);
    circle((0.075f * scale) - x, (0.11f * scale) - y, 0.012f *scale, 10);
}
/* ADJUST FOR SIZE */
void fish::mackarel(float scale, float x, float y) {
    // Set color to light blue for the mackerel body
    glColor3f(0.3f, 0.5f, 0.8f);

    // Draw the mackerel body (an elongated ellipse-like shape)
    glBegin(GL_POLYGON);
    glVertex2f(-0.7f, 0.2f);   // Top left of the body
    glVertex2f(0.7f, 0.2f);   // Top right of the body
    glVertex2f(0.6f, 0.0f);   // Midpoint of the bottom
    glVertex2f(0.0f, -0.15f); // Slight tapering toward tail
    glVertex2f(-0.6f, 0.0f);   // Midpoint of the left bottom
    glEnd();

    // Set color to darker blue for the mackerel stripes
    glColor3f(0.1f, 0.3f, 0.6f);

    // Draw vertical stripes on the mackerel's back
    glBegin(GL_LINES);
    for (float x = -0.6f; x <= 0.6f; x += 0.2f) {
        glVertex2f(x, 0.2f);  // Start at the top of the body
        glVertex2f(x + 0.1f, 0.05f);  // Diagonal down to the middle
    }
    glEnd();

    // Set color to darker blue for the mackerel tail
    glColor3f(0.2f, 0.4f, 0.6f);

    // Draw the forked tail
    glBegin(GL_TRIANGLES);
    glVertex2f(0.7f, 0.1f);   // Upper fork
    glVertex2f(0.9f, 0.3f);   // Tip of the upper tail
    glVertex2f(0.9f, 0.0f);   // Bottom of upper fork
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.7f, -0.1f);  // Lower fork
    glVertex2f(0.9f, -0.3f);  // Tip of the lower tail
    glVertex2f(0.9f, 0.0f);   // Top of lower fork
    glEnd();

    // Set color to white for the mackerel belly
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw the white belly as a long thin strip
    glBegin(GL_POLYGON);
    glVertex2f(-0.7f, 0.0f);  // Left bottom edge of the body
    glVertex2f(0.7f, 0.0f);  // Right bottom edge of the body
    glVertex2f(0.6f, -0.05f); // Slight bottom taper near tail
    glVertex2f(-0.6f, -0.05f); // Matching taper on left
    glEnd();

    // Set color to black for the mackerel's eye
    glColor3f(0.0f, 0.0f, 0.0f);

    // Draw the eye as a small circle
    glBegin(GL_POLYGON);
    float angle;
    int num_segments = 30;
    for (int i = 0; i < num_segments; i++) {
        angle = 2 * 3.14159f * i / num_segments;
        glVertex2f(-0.5f + 0.05f * cos(angle), 0.1f + 0.05f * sin(angle));
    }
    glEnd();
}
void fish::oarfish(float scale, float x, float y) {
    //face
//eyes
    glColor3f(0.0, 0.0, 0.0);
    circle((0.075f * scale) - x, (0.125f * scale) - y, 0.01f * scale, 10);

    glColor3f(1.0, 1.0, 1.0);
    circle((0.075f * scale) - x, (0.125f * scale) - y, .012f * scale, 10);

    //body
    glColor3f(1.0, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex2f((0.05f * scale) - x, (0.15f * scale) - y);  // Bottom left corner
    glVertex2f((0.5f * scale) - x, (0.15f * scale) - y);  // Bottom right corner
    glVertex2f((0.5f * scale) - x, (0.175f * scale) - y);  // Top right corner
    glVertex2f((0.05f * scale) - x, (0.175f * scale) - y);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((0.05f * scale) - x, (0.175f * scale) - y);  // Bottom left corner
    glVertex2f((0.1f * scale) - x, (0.175f * scale) - y);  // Bottom right corner
    glVertex2f((0.125f * scale) - x, (0.275f * scale) - y);  // Top right corner
    glVertex2f((0.075f * scale) - x, (0.275f * scale) - y);  // Top left corner
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f((0.5f * scale) - x, (0.15f * scale) - y);
    glVertex2f((0.5f * scale) - x, (0.175f * scale) - y);
    glVertex2f((0.575f * scale) - x, (0.15f * scale) - y);
    glEnd();

    glColor3f(0.4, 0.6, 0.7);
    glBegin(GL_QUADS);
    glVertex2f((0.05f * scale) - x, (0.05f * scale) - y);  // Bottom left corner
    glVertex2f((0.5f * scale) - x, (0.05f * scale) - y);  // Bottom right corner
    glVertex2f((0.5f * scale) - x, (0.15f * scale) - y);  // Top right corner
    glVertex2f((0.05f * scale) - x, (0.15f * scale) - y);  // Top left corner
    glEnd();
    circle((0.07f * scale) - x, (0.1f * scale) - y, 0.053f * scale, 10);

    //fins
    glBegin(GL_TRIANGLES);
    glVertex2f((0.5f * scale) - x, (0.05f * scale) - y);
    glVertex2f((0.5f * scale) - x, (0.15f * scale) - y);
    glVertex2f((0.575f * scale) - x, (0.15f * scale) - y);
    glEnd();
}
void fish::pufferfish(float scale, float x, float y) {
    //face
            //eyes
    glColor3f(0.0, 0.0, 0.0);
    circle((0.1f * scale) - x, (0.275f * scale) - y, 0.01f * scale, 10);

    glColor3f(1.0, 1.0, 1.0);
    circle((0.1f * scale) - x, (0.275f * scale) - y, 0.012f * scale, 10);
    //body

    glColor3f(0.2, 0.1, 0.0);//top fins
    glBegin(GL_TRIANGLES);
    glVertex2f((0.3f * scale) - x, (0.2f * scale) - y);
    glVertex2f((0.4f * scale) - x, (0.125f * scale) - y);
    glVertex2f((0.4f * scale) - x, (0.275f * scale) - y);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);//mouth
    circle((0.075f * scale) - x, (0.2f * scale) - y, 0.02f * scale, 20);

    glColor3f(0.7, 0.5, 0.0);//upper body
    semicircle((0.2f * scale) - x, (0.2f * scale) - y, 0.15f * scale, 100);
    glColor3f(1.0, 1.0, 1.0);//lower body
    circle((0.2f * scale) - x, (0.2f * scale) - y, 0.15f * scale, 100);


    //fins

    glColor3f(0.2, 0.1, 0.0);//top fins
    glBegin(GL_QUADS);
    glVertex2f((0.2f * scale) - x, (0.3f * scale) - y);  // Bottom left corner
    glVertex2f((0.25f * scale) - x, (0.3f * scale) - y);  // Bottom right corner
    glVertex2f((0.3f * scale) - x, (0.375f * scale) - y);  // Top right corner
    glVertex2f((0.25f * scale) - x, (0.375f * scale) - y);  // Top left corner
    glEnd();
}
void fish::sacabambaspis(float scale, float x, float y) {
    //face
    //eyes
    glColor3f(0.0, 0.0, 0.0);
    circle((0.13f * scale) - x, (0.24f * scale) - y, 0.01f * scale, 10);//left eye
    circle((0.17f * scale) - x, (0.24f * scale) - y, 0.01f * scale, 10);//right eye

    glColor3f(1.0, 1.0, 1.0);
    circle((0.13f * scale) - x, (0.24f * scale) - y, 0.012f * scale, 10);//left eye
    circle((0.17f * scale) - x, (0.24f * scale) - y, 0.012f * scale, 10);//right eye

    //mouth
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f((0.12f * scale) - x, (0.22f * scale) - y);
    glVertex2f((0.18f * scale) - x, (0.22f * scale) - y);
    glVertex2f((0.15f * scale) - x, (0.205f * scale) - y);
    glEnd();


    //body
    glColor3f(0.5, 0.5, 0.5);
    semicircle((0.2f * scale) - x, (0.225f * scale) - y, 0.1f * scale, 5); // top part of the sacabambaspis
    semicircle((0.26f * scale) - x, (0.225f * scale) - y, 0.1f * scale, 5); // top part of the sacabambaspis
    semicircle((0.32f * scale) - x, (0.225f * scale) - y, 0.1f * scale, 5); // top part of the sacabambaspis

    glColor3f(1.0, 1.0, 1.0);
    circle((0.2f * scale) - x, (0.225f * scale) - y, 0.1f * scale, 10); // bottom part of the sacabambaspis
    circle((0.26f * scale) - x, (0.225f * scale) - y, 0.1f * scale, 10); // bottom part of the sacabambaspis
    circle(320.0f, 225.0f, 100.0f, 10); // bottom part of the sacabambaspis

    //fins
    glColor3f(0.5, 0.5, 0.5);//top fin
    glBegin(GL_TRIANGLES);
    glVertex2f((0.4f * scale) - x, (0.25f * scale) - y);
    glVertex2f((0.45f * scale) - x, (0.25f * scale) - y);
    glVertex2f((0.45f * scale) - x, (0.3f * scale) - y);
    glEnd();

    //bottom fin
    glBegin(GL_TRIANGLES);
    glVertex2f((0.4f * scale) - x, (0.25f * scale) - y);
    glVertex2f((0.45f * scale) - x, (0.25f * scale) - y);
    glVertex2f((0.45f * scale) - x, (0.2f * scale) - y);
    glEnd();

}
/* ADJUST FOR SIZE */
void fish::shark(float scale, float x, float y) {
    // Set color to gray for the shark's body
    glColor3f(0.5f, 0.5f, 0.5f);

    // Draw the shark body (an elongated shape)
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f, 0.2f);   // Top left of body
    glVertex2f(0.6f, 0.2f);   // Top right of body
    glVertex2f(0.4f, -0.2f);  // Bottom right of body
    glVertex2f(-0.4f, -0.2f);  // Bottom left of body
    glEnd();

    // Dorsal fin
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.1f, 0.2f);   // Left
    glVertex2f(-0.05f, 0.4f);   // Top
    glVertex2f(0.1f, 0.2f);  // Right
    glEnd();

    // Set color to dark gray for the shark's tail
    glColor3f(0.3f, 0.3f, 0.3f);

    // Draw the shark tail (triangle shape)
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6f, 0.2f);   // Left top of body
    glVertex2f(-0.8f, 0.4f);   // Tail upper point
    glVertex2f(-0.8f, -0.4f);  // Tail lower point
    glEnd();

    // Set color to white for the shark's belly
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw the shark belly (smaller polygon)
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -0.15f);
    glVertex2f(0.5f, -0.15f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(-0.3f, -0.2f);
    glEnd();

    // Set color to black for the shark's eye
    glColor3f(0.0f, 0.0f, 0.0f);

    // Draw the shark's eye (small circle)
    glBegin(GL_POLYGON);
    float angle;
    int num_segments = 30;
    for (int i = 0; i < num_segments; i++) {
        angle = 2 * 3.14159f * i / num_segments;
        glVertex2f(0.3f + 0.05f * cos(angle), 0.1f + 0.05f * sin(angle));
    }
    glEnd();

    // Set color to white for the shark's teeth (small triangles)
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw shark teeth (triangles)
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, -0.05f);  // First tooth top
    glVertex2f(0.25f, -0.1f);  // First tooth bottom left
    glVertex2f(0.3f, -0.05f);  // First tooth bottom right
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, -0.1f);  // Second tooth top
    glVertex2f(0.25f, -0.15f);  // Second tooth bottom left
    glVertex2f(0.3f, -0.1f);  // Second tooth bottom right
    glEnd();
}
/* ADJUST FOR SIZE */
void fish::tuna(float scale, float x, float y) {
    //face
    //eyes
    glColor3f(0.0, 0.0, 0.0);
    circle(110.0f, 160.0f, 10.0f, 10);

    glColor3f(1.0, 1.0, 1.0);
    circle(110.0f, 160.0f, 12.0f, 10);

    //hair
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(110.0f, 190.0f);  // Bottom left corner
    glVertex2f(160.0f, 190.0f);  // Bottom right corner
    glVertex2f(160.0f, 210.0f);  // Top right corner
    glVertex2f(110.0f, 210.0f);  // Top left corner
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(160.0f, 190.0f);  // Bottom left corner
    glVertex2f(175.0f, 165.0f);  // Bottom right corner
    glVertex2f(190.0f, 210.0f);  // Top right corner
    glVertex2f(160.0f, 210.0f);  // Top left corner
    glEnd();

    circle(195.0f, 195.0f, 15.0f, 10);
    circle(195.0f, 175.0f, 15.0f, 10);
    circle(195.0f, 150.0f, 15.0f, 10);
    circle(195.0f, 125.0f, 15.0f, 10);
    circle(195.0f, 100.0f, 15.0f, 10);

    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_TRIANGLES);
    glVertex2f(180.0f, 87.0f);
    glVertex2f(210.0f, 87.0f);
    glVertex2f(195.0f, 65.0f);
    glEnd();

    //body
    glColor3f(0.4, 0.4, 0.4);//front fins
    glBegin(GL_TRIANGLES);
    glVertex2f(225.0f, 200.0f);
    glVertex2f(325.0f, 200.0f);
    glVertex2f(275.0f, 225.0f);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(100.0f, 50.0f);  // Bottom left corner
    glVertex2f(350.0f, 50.0f);  // Bottom right corner
    glVertex2f(500.0f, 125.0f);  // Top right corner
    glVertex2f(50.0f, 125.0f);  // Top left corner
    glEnd();
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(50.0f, 125.0f);  // Bottom left corner
    glVertex2f(500.0f, 125.0f);  // Bottom right corner
    glVertex2f(350.0f, 200.0f);  // Top right corner
    glVertex2f(100.0f, 200.0f);  // Top left corner
    glEnd();

    //fins

    glColor3f(0.4, 0.4, 0.4);//top fins
    glBegin(GL_TRIANGLES);
    glVertex2f(225.0f, 200.0f);
    glVertex2f(325.0f, 200.0f);
    glVertex2f(275.0f, 225.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(500.0f, 125.0f);  // Bottom left corner
    glVertex2f(550.0f, 75.0f);  // Bottom right corner
    glVertex2f(525.0f, 125.0f);  // Top right corner
    glVertex2f(550.0f, 175.0f);  // Top left corner
    glEnd();
}