#include "graphics.h"/*

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
}*/

// Draw UI elements
void gameGraphics::drawText(float r, float g, float b, float x, float y, const char* text) {
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void gameGraphics::drawTimerBar(float progress) {
    glColor3f(0.0f, 1.0f, 0.0f); // Green timer bar
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, 0.8f);
    glVertex2f(progress / 1.25f - 0.8f, 0.8f);
    glVertex2f(progress / 1.25f - 0.8f, 0.75f);
    glVertex2f(-0.8f, 0.75f);
    glEnd();
}

void gameGraphics::drawReelMeter(float progress) {
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow reel meter
    glBegin(GL_QUADS);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(progress / 1.25f - 0.8f, -0.8f);
    glVertex2f(progress / 1.25f - 0.8f, -0.75f);
    glVertex2f(-0.8f, -0.75f);
    glEnd();
}

void gameGraphics::bobber() {
    glColor3f(1.0f, 0.0f, 0.0f);
    circle(0.0f, 0.0f, 0.2f, 10);
}

void gameGraphics::gameBackground(float waterR, float waterG, float waterB, bool isInAreaA) {
    // Water
    glColor3f(waterR, waterG, waterB);

    glBegin(GL_QUADS);
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), -1.0f);
    glVertex2f((GLUT_WINDOW_WIDTH / 2), -1.0f);
    glVertex2f((GLUT_WINDOW_WIDTH / 2), 0.3f);
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), 0.3f);
    glEnd();

    if (isInAreaA == true) {
        // Mountain
        glColor3f(0.42f, 0.53f, 0.60f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.75, 0.9f);
        glVertex2f(-0.25, 0.3f);
        glVertex2f(1.25, 0.3f);
        glEnd();

        // Trees
        glColor3f(0.155f, 0.393f, 0.318f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.965, 0.55f);
        glVertex2f(-1.05, 0.3f);
        glVertex2f(-0.905, 0.3f);
        glEnd();

        glColor3f(0.155f, 0.393f, 0.318f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.775, 0.55f);
        glVertex2f(-0.85, 0.3f);
        glVertex2f(-0.675, 0.3f);
        glEnd();

        glColor3f(0.155f, 0.393f, 0.318f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.55, 0.5f);
        glVertex2f(-0.625, 0.3f);
        glVertex2f(-0.475, 0.3f);
        glEnd();

        glColor3f(0.155f, 0.393f, 0.318f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.475, 0.45f);
        glVertex2f(-0.525, 0.3f);
        glVertex2f(-0.425, 0.3f);
        glEnd();

        glColor3f(0.155f, 0.393f, 0.318f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.32, 0.4f);
        glVertex2f(-0.365, 0.3f);
        glVertex2f(-0.295, 0.3f);
        glEnd();

        glColor3f(0.00f, 0.27f, 0.13f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.875, 0.6f);
        glVertex2f(-0.975, 0.3f);
        glVertex2f(-0.775, 0.3f);
        glEnd();

        glColor3f(0.00f, 0.27f, 0.13f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.65, 0.7f);
        glVertex2f(-0.75, 0.3f);
        glVertex2f(-0.55, 0.3f);
        glEnd();

        glColor3f(0.00f, 0.27f, 0.13f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.4, 0.5f);
        glVertex2f(-0.45, 0.3f);
        glVertex2f(-0.35, 0.3f);
        glEnd();

        glColor3f(0.00f, 0.27f, 0.13f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.65, 0.5f);
        glVertex2f(0.7, 0.3f);
        glVertex2f(0.6, 0.3f);
        glEnd();

        glColor3f(0.00f, 0.27f, 0.13f);
        glBegin(GL_TRIANGLES);
        glVertex2f(0.8, 0.7f);
        glVertex2f(0.7, 0.3f);
        glVertex2f(0.9, 0.3f);
        glEnd();
    }
    else {
        // Mountain
        glColor3f(0.42f, 0.53f, 0.60f);
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.75, 0.9f);
        glVertex2f(-2.25, 0.3f);
        glVertex2f(-0.25, 0.3f);
        glEnd();
    }

    // Land
    glColor3f(0.18f, 0.46f, 0.20f);
    glBegin(GL_QUADS);
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), 0.3f);
    glVertex2f((GLUT_WINDOW_WIDTH / 2), 0.3f);
    glVertex2f((GLUT_WINDOW_WIDTH / 2), 0.2f);
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), 0.2f);
    glEnd();

    // Boat
    
}

void gameGraphics::shop() {
    // Wall
    glColor3f(1.00f, 0.84f, 0.48f);

    glBegin(GL_QUADS);
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), -(GLUT_WINDOW_HEIGHT / 2));
    glVertex2f((GLUT_WINDOW_WIDTH / 2), -(GLUT_WINDOW_HEIGHT / 2));
    glVertex2f((GLUT_WINDOW_WIDTH / 2), (GLUT_WINDOW_HEIGHT / 2));
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), (GLUT_WINDOW_HEIGHT / 2));
    glEnd();

    // Floor
    glColor3f(0.46f, 0.32f, 0.21f);

    glBegin(GL_QUADS);
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), -1.0f);
    glVertex2f((GLUT_WINDOW_WIDTH / 2), -1.0f);
    glVertex2f((GLUT_WINDOW_WIDTH / 2), -0.5f);
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), -0.5f);
    glEnd();

    // Rod Stand
    glColor3f(0.28f, 0.38f, 0.56f);

    glBegin(GL_QUADS);
    glVertex2f(-0.7, -0.7f);
    glVertex2f(0.7, -0.7f);
    glVertex2f(0.7, 0.0f);
    glVertex2f(-0.7, 0.0f);
    glEnd();

    glColor3f(0.35f, 0.47f, 0.68f);

    glBegin(GL_QUADS);
    glVertex2f(-0.7, -0.25f);
    glVertex2f(0.7, -0.25f);
    glVertex2f(0.7, -0.3f);
    glVertex2f(-0.7, -0.3f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.7, -0.6f);
    glVertex2f(0.7, -0.6f);
    glVertex2f(0.7, -0.65f);
    glVertex2f(-0.7, -0.65f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.75, -0.75f);
    glVertex2f(-0.7, -0.75f);
    glVertex2f(-0.7, 0.0f);
    glVertex2f(-0.75, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.75, -0.75f);
    glVertex2f(0.7, -0.75f);
    glVertex2f(0.7, 0.0f);
    glVertex2f(0.75, 0.0f);
    glEnd();

}

void gameGraphics::compendium(int pageNum) {
    float pageLength = 0.65f;
    float coverLength = 0.7f;

    // Cover
    glColor3f(0.11f, 0.23f, 0.11f);

    glBegin(GL_QUADS);
    glVertex2f(-(coverLength * 1.17f), coverLength);
    glVertex2f((coverLength * 1.17f), coverLength);
    glVertex2f((coverLength * 1.17f), -coverLength);
    glVertex2f(-(coverLength * 1.17f), -coverLength);
    glEnd();

    // Pages
    switch (pageNum) {
    case 1:
        glColor3f(0.91f, 0.82f, 0.64f);
        break;

    case 2:
        glColor3f(0.96f, 0.87f, 0.67f);
        break;
    }
        

    glBegin(GL_QUADS);
    glVertex2f(-(pageLength * 1.2f), pageLength);
    glVertex2f(0.0f, pageLength);
    glVertex2f(0.0f, -pageLength);
    glVertex2f(-(pageLength * 1.2f), -pageLength);
    glEnd();
    
    switch (pageNum) {
    case 1:
        glColor3f(0.96f, 0.87f, 0.67f);
        break;

    case 2:
        glColor3f(0.91f, 0.82f, 0.64f);
        break;
    }

    glBegin(GL_QUADS);
    glVertex2f(0.0f, pageLength);
    glVertex2f((pageLength * 1.2f), pageLength);
    glVertex2f((pageLength * 1.2f), -pageLength);
    glVertex2f(0.0f, -pageLength);
    glEnd();
}

void gameGraphics::catchScreen() {
    glColor4f(0.07f, 0.07f, 0.07f, 0.0f);

    glBegin(GL_QUADS);
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), -(GLUT_WINDOW_HEIGHT / 2));
    glVertex2f((GLUT_WINDOW_WIDTH / 2), -(GLUT_WINDOW_HEIGHT / 2));
    glVertex2f((GLUT_WINDOW_WIDTH / 2), (GLUT_WINDOW_HEIGHT / 2));
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), (GLUT_WINDOW_HEIGHT / 2));
    glEnd();
}

void gameGraphics::rodDisplay(float r, float g, float b, float x, float y) {
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(-0.015 + x, 0.5f + y);
    glVertex2f(0.0 + x, 0.5f + y);
    glVertex2f(0.0 + x, -0.7f + y);
    glVertex2f(-0.015 + x, -0.7f + y);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(-0.01 + x, 0.5f + y);
    glVertex2f(0.01 + x, 0.5f + y);
    glVertex2f(0.01 + x, -0.7f + y);
    glVertex2f(-0.01 + x, -0.7f + y);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.015 + x, -0.3f + y);
    glVertex2f(0.015 + x, -0.3f + y);
    glVertex2f(0.015 + x, -0.7f + y);
    glVertex2f(-0.015 + x, -0.7f + y);
    glEnd();

    /*glColor3f(0.57f, 0.57f, 0.57f);
    circle(0.0f + x, 0.0f + y, 0.02f, 10);

    glColor3f(0.32f, 0.32f, 0.32f);
    circle(0.015f + x, 0.0f + y, 0.001f, 10);*/
}

void gameGraphics::priceTag(float x, float y, const char* price) {
    glColor3f(0.95f, 0.92f, 0.87f);
    glBegin(GL_QUADS);
    glVertex2f(-(0.2 / 2) + x, -0.1f + y);
    glVertex2f((0.2 / 2) + x, -0.1f + y);
    glVertex2f((0.2 / 2) + x, -0.25f + y);
    glVertex2f(-(0.2 / 2) + x, -0.25f + y);
    glEnd();

    drawText(0.0f, 0.0f, 0.0f, -0.05f + x, -0.2f + y, price);
}

void gameGraphics::soldSign(float x) {
    glColor3f(0.89f, 0.11f, 0.11f);
    glBegin(GL_QUADS);
    glVertex2f(-(0.2 / 2) + x, -0.1f);
    glVertex2f((0.2 / 2) + x, -0.1f);
    glVertex2f((0.2 / 2) + x, -0.25f);
    glVertex2f(-(0.2 / 2) + x, -0.25f);
    glEnd();

    drawText(1.0f, 1.0f, 1.0f, -0.075f + x, -0.2f, "SOLD");
}

void gameGraphics::confirmationScreen(float x, const char* rod) {
    glColor4f(0.07f, 0.07f, 0.07f, 0.75f);

    glBegin(GL_QUADS);
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), -(GLUT_WINDOW_HEIGHT / 2));
    glVertex2f((GLUT_WINDOW_WIDTH / 2), -(GLUT_WINDOW_HEIGHT / 2));
    glVertex2f((GLUT_WINDOW_WIDTH / 2), (GLUT_WINDOW_HEIGHT / 2));
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), (GLUT_WINDOW_HEIGHT / 2));
    glEnd();

    drawText(1.0f, 1.0f, 1.0f, -0.425f, 0.2f, "Are you sure you want to upgrade to a");
    drawText(1.0f, 1.0f, 1.0f, -0.075f + x, 0.1f, rod);
    drawText(1.0f, 1.0f, 1.0f, -0.27f, -0.2f, "Z = Confirm | X = Cancel");
    
}

void gameGraphics::purchasefailedScreen() {
    glColor4f(0.07f, 0.07f, 0.07f, 0.75f);

    glBegin(GL_QUADS);
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), -(GLUT_WINDOW_HEIGHT / 2));
    glVertex2f((GLUT_WINDOW_WIDTH / 2), -(GLUT_WINDOW_HEIGHT / 2));
    glVertex2f((GLUT_WINDOW_WIDTH / 2), (GLUT_WINDOW_HEIGHT / 2));
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), (GLUT_WINDOW_HEIGHT / 2));
    glEnd();

    drawText(1.0f, 1.0f, 1.0f, -0.575f, 0.2f, "Sorry, you don't have enough to buy this rod.");

}

void gameGraphics::credits() {
    glColor4f(0.13f, 0.12f, 0.27f, 0.9f);

    glBegin(GL_QUADS);
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), -(GLUT_WINDOW_HEIGHT / 2));
    glVertex2f((GLUT_WINDOW_WIDTH / 2), -(GLUT_WINDOW_HEIGHT / 2));
    glVertex2f((GLUT_WINDOW_WIDTH / 2), (GLUT_WINDOW_HEIGHT / 2));
    glVertex2f(-(GLUT_WINDOW_WIDTH / 2), (GLUT_WINDOW_HEIGHT / 2));
    glEnd();

    drawText(1.0f, 1.0f, 1.0f, -0.625f, 0.5f, "Lake Aequor");
    drawText(1.0f, 1.0f, 1.0f, -0.625f, 0.3f, "Submitted by:");
    drawText(1.0f, 1.0f, 1.0f, -0.625f, 0.2f, "Juliana Ambos");
    drawText(1.0f, 1.0f, 1.0f, -0.625f, 0.1f, "Nivron Dela Cruz");
    drawText(1.0f, 1.0f, 1.0f, -0.625f, 0.0f, "Cloe Gorgonio");
    drawText(1.0f, 1.0f, 1.0f, -0.625f, -0.1f, "Jermaine Malinis");
    drawText(1.0f, 1.0f, 1.0f, -0.625f, -0.3f, "GDV21");
    drawText(1.0f, 1.0f, 1.0f, -0.625f, -0.5f, "Finals project for APPLYPHY2, GAMENGIN, & GRAPHICS");
}