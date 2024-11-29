#include <glut.h>
#include <glfw3.h>
#include <cstdlib>
#include <ctime>
#include <string>

#include "engine.h"
#include "graphics.h"
#include "fish.h"

using namespace std;

gameGraphics load;
fish spawn;


float fishBounceX, fishBounceY = -0.8f;
float boundsXL = -1.0f, boundsXR = 1.0f, boundsYB = -0.8f, boundsYT = 0.8;

float waterR = 0.30f, waterG = 0.65f, waterB = 0.70f;
bool isInAreaA = true;
bool showCatchScreen = false;
float meterFill = 0.1f;
int fishBite;

bool isCompendiumOpen = false;
int pageNum = 1;

bool isShopOpen = false;
int rodPrice = 0;
bool confirm = false;
bool showPurchaseFailed = false;
string rodType;
float rodTypeX;

bool isCreditsOpen = false;

bool lvl2Upgrade = false;
bool lvl3Upgrade = false;
bool lvl4Upgrade = false;
bool lvl5Upgrade = false;
bool lvl6Upgrade = false;

int fishID[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
string fishName[20] = {
    "Carp", "Milkfish", "Tilapia", "Trout", "Catfish", "Goldfish", "Janitor fish", "Betta", "Gold fish","Koi",
    "Anchovy", "Bass", "Cod", "Mackarel", "Clownfish", "Pufferfish", "Tuna", "Oarfish", "Sacabambaspis", "Shark"
};

bool carpCaught = false; bool bangusCaught = false; bool tilapiaCaught = false; bool troutCaught = false;
bool catfishCaught = false; bool goldfishCaught = false; bool janitorfishCaught = false; bool bettaCaught = false;
bool aufishCaught = false; bool koiCaught = false;

bool anchovyCaught = false; bool bassCaught = false; bool codCaught = false; bool mackarelCaught = false;
bool clownfishCaught = false; bool pufferfishCaught = false; bool tunaCaught = false; bool oarfishCaught = false;
bool sacabambaspisCaught = false; bool sharkCaught = false;

// Game state variables
bool isWaiting = false;    // Is the player waiting for a fish to bite?
bool fishBiting = false;   // Is a fish currently biting?
int score = 0;             // Player's score
double earnings;
double cash = 0;
float timer = 1.0f;        // Timer for reeling (in seconds)
float reelMeter = 0.0f;    // Progress bar for reeling
float fishX, fishY;        // Fish position
float fishColor[3];        // Fish color (RGB)

// Generate random float
float randomFloat(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

// Generate a random fish
void spawnFish() {
    fishX = randomFloat(-0.7f, 0.7f);
    fishY = randomFloat(-0.3f, 0.0f);
}

// Draw a fish
void drawFish(float x, float y, float size) {
    glColor4f(0.0f, 0.0f, 0.0f, 0.2f);
    glBegin(GL_POLYGON); // Fish body
    for (int i = 0; i < 360; i += 30) {
        float angle = i * 3.14159f / 180.0f;
        glVertex2f(x + cos(angle) * size, y + sin(angle) * size);
    }
    glEnd();

    glBegin(GL_TRIANGLES); // Fish tail
    glVertex2f(x - size, y);
    glVertex2f(x - size * 1.5f, y + size / 2);
    glVertex2f(x - size * 1.5f, y - size / 2);
    glEnd();
}

void openShop() {
    load.shop();

    if (!lvl2Upgrade) {
        load.rodDisplay(0.37f, 0.19f, 0.09f, -0.6, 0.1);
        load.priceTag(-0.6, 0.0f, ("$" + std::to_string(5)).c_str());
        load.priceTag(-0.6, 0.9f, ("" + std::to_string(1)).c_str());
    }
    else load.soldSign(-0.6);

    if (!lvl3Upgrade) {
        load.rodDisplay(0.63f, 0.63f, 0.63f, -0.3, 0.1);
        load.priceTag(-0.3, 0.0f, ("$" + std::to_string(25)).c_str());
        load.priceTag(-0.3, 0.9f, ("" + std::to_string(2)).c_str());
    }
    else load.soldSign(-0.3);

    if (!lvl4Upgrade) {
        load.rodDisplay(0.42f, 0.83f, 0.97f, 0.0, 0.1);
        load.priceTag(0.0, 0.0f, ("$" + std::to_string(60)).c_str());
        load.priceTag(0.0, 0.9f, ("" + std::to_string(3)).c_str());
    }
    else load.soldSign(0.0);

    if (!lvl5Upgrade) {
        load.rodDisplay(0.97f, 0.23f, 0.17f, 0.3, 0.1);
        load.priceTag(0.3, 0.0f, ("$" + std::to_string(150)).c_str());
        load.priceTag(0.3, 0.9f, ("" + std::to_string(4)).c_str());
    }
    else load.soldSign(0.3);

    if (!lvl6Upgrade) {
        load.rodDisplay(0.83f, 0.69f, 0.22f, 0.6, 0.1);
        load.priceTag(0.6, 0.0f, ("$" + std::to_string(300)).c_str());
        load.priceTag(0.6, 0.9f, ("" + std::to_string(5)).c_str());
    }
    else load.soldSign(0.6);

    glutPostRedisplay();
}

void fishCompendium() {
    load.compendium(pageNum);

    if (pageNum == 1) {
        if (carpCaught) spawn.carp(0.5f, 0.75f, 0.3f);
        if (bangusCaught) spawn.bangus(0.5f, 0.45f, 0.3f);
        if (tilapiaCaught) spawn.tilapia(0.5f, 0.75f, 0.1f);
        if (troutCaught) spawn.trout(0.5f, 0.45f, 0.1f);
        if (catfishCaught) spawn.catfish(0.5f, 0.75f, 0.1f);
    }
    if (pageNum == 2) {
        if (bassCaught) spawn.bass(0.5f, 0.45f, 0.3f);
        if (codCaught) spawn.cod(0.5f, 0.75f, 0.1f);
    }

    glutPostRedisplay();
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    load.gameBackground(waterR, waterG, waterB, isInAreaA);

    // UI: Score, Timer, Reel Meter
    load.drawText(1.0f, 1.0f, 1.0f, -0.9f, -0.9f, ("Total Fish Caught: " + std::to_string(score)).c_str());
    if (fishBiting) {
        load.drawTimerBar(timer / 5.0f);  // Show timer bar when fish is biting
        load.drawReelMeter(reelMeter);    // Show reel meter
    }

    // Feedback Text
    if (isWaiting) load.drawText(1.0f, 1.0f, 1.0f, -0.2f, 0.0f, "Waiting...");
    if (fishBiting) load.drawText(1.0f, 1.0f, 1.0f, -0.2f, 0.0f, "Click to reel!");

    // Draw fish
    if (fishBiting) drawFish(fishX, fishY, 0.05f);

    if (showCatchScreen) {
        string aOrAn;
        if (fishBite - 1 == 10 || fishBite - 1 == 17) aOrAn = "an ";
        else aOrAn = "a ";

        load.catchScreen();

        switch (fishBite) {
        case 1:
            spawn.carp(1.0f, -0.3f, 0.0f);
            if (!carpCaught) carpCaught = true;
            break;
        case 2:
            spawn.bangus(0.8f, 0.4f, fishBounceY);
            if (!bangusCaught) bangusCaught = true;
            break;
        case 3:
            spawn.tilapia(1.4f, 0.4f, 0.25f);
            if (!tilapiaCaught) tilapiaCaught = true;
            break;
        case 4:
            spawn.trout(1.0f, -0.3f, 0.0f);
            if (!troutCaught) troutCaught = true;
            break;
        case 5:
            spawn.catfish(1.5f, 0.5f, 0.25f);
            if (!catfishCaught) catfishCaught = true;
            break;
        case 6:
            spawn.goldfish(1.0f, -0.3f, 0.0f);
            if (!goldfishCaught) goldfishCaught = true;
            break;
        case 7:
            spawn.janitorFish(1.0f, -0.3f, 0.0f);
            if (!janitorfishCaught) janitorfishCaught = true;
            break;
        case 8:
            spawn.betta(1.0f, -0.3f, 0.0f);
            if (!bettaCaught) bettaCaught = true;
            break;
        case 9:
            spawn.AUfish(1.0f, -0.3f, 0.0f);
            if (!aufishCaught) aufishCaught = true;
            break;
        case 10:
            spawn.koi(1.0f, -0.3f, 0.0f);
            if (!koiCaught) koiCaught = true;
            break;
        case 11:
            spawn.anchovy(1.0f, -0.3f, 0.0f);
            if (!anchovyCaught) anchovyCaught = true;
            break;
        case 12:
            spawn.bass(1.0f, -0.3f, 0.0f);
            if (!bassCaught) bassCaught = true;
            break;
        case 13:
            spawn.cod(1.0f, -0.3f, 0.0f);
            if (!codCaught) codCaught = true;
            break;
        case 14:
            spawn.mackarel(1.0f, -0.3f, 0.0f);
            if (!mackarelCaught) mackarelCaught = true;
            break;
        case 15:
            spawn.clownfish(1.0f, -0.3f, 0.0f);
            if (!clownfishCaught) clownfishCaught = true;
            break;
        case 16:
            spawn.pufferfish(1.0f, -0.3f, 0.0f);
            if (!pufferfishCaught) pufferfishCaught = true;
            break;
        case 17:
            spawn.tuna(1.0f, -0.3f, 0.0f);
            if (!tunaCaught) tunaCaught = true;
            break;
        case 18:
            spawn.oarfish(1.0f, -0.3f, 0.0f);
            if (!oarfishCaught) oarfishCaught = true;
            break;
        case 19:
            spawn.sacabambaspis(1.0f, -0.3f, 0.0f);
            if (!sacabambaspisCaught) sacabambaspisCaught = true;
            break;
        case 20:
            spawn.shark(1.0f, -0.3f, 0.0f);
            if (!sharkCaught) sharkCaught = true;
            break;
        }

        load.drawText(1.0f, 1.0f, 1.0f, -0.3f, 0.6f, ("You caught " + aOrAn + fishName[fishBite - 1] + "!").c_str());
    }

    if (isShopOpen) {
        openShop();
    }

    if (confirm) {
        load.confirmationScreen(rodTypeX, rodType.c_str());
    }

    if (showPurchaseFailed) {
        load.purchasefailedScreen();
    }

    // player money
    load.drawText(0.0f, 0.33f, 0.80f, -0.9f, 0.85f, ("Money Earned: $" + std::to_string(cash)).c_str());

    if (isCompendiumOpen) fishCompendium();
    if (isCreditsOpen) load.credits();

    glutSwapBuffers();
}

// Adds new entry to compendium after first catch
void addEntry(int fishCaught) {
    switch (fishCaught) {
    case 1:
        if (!carpCaught) carpCaught = true;
        earnings = 2.00;

        break;
    case 2:
        if (!bangusCaught) bangusCaught = true;
        earnings = 3.0;

        break;
    case 3:
        if (!tilapiaCaught) tilapiaCaught = true;
        earnings = 0.75;

        break;
    case 4:
        if (!troutCaught) troutCaught = true;
        earnings = 1.75;

        break;
    case 5:
        if (!catfishCaught) catfishCaught = true;
        earnings = 1.50;

        break;
    case 6:
        if (!goldfishCaught) goldfishCaught = true;
        earnings = 2.00;

        break;
    case 7:
        if (!janitorfishCaught) janitorfishCaught = true;
        earnings = 2.50;

        break;
    case 8:
        if (!bettaCaught) bettaCaught = true;
        earnings = 10.00;

        break;
    case 9:
        if (!aufishCaught) aufishCaught = true;
        earnings = 25.00;

        break;
    case 10:
        if (!koiCaught) koiCaught = true;
        earnings = 12.00;

        break;
    case 11:
        if (!anchovyCaught) anchovyCaught = true;
        earnings = 0.10;

        break;
    case 12:
        if (!bassCaught) bassCaught = true;
        earnings = 1.00;

        break;
    case 13:
        if (!codCaught) codCaught = true;
        earnings = 1.50;

        break;
    case 14:
        if (!mackarelCaught) mackarelCaught = true;
        earnings = 0.80;

        break;
    case 15:
        if (!clownfishCaught) clownfishCaught = true;
        earnings = 3.00;

        break;
    case 16:
        if (!pufferfishCaught) pufferfishCaught = true;
        earnings = 12.00;

        break;
    case 17:
        if (!tunaCaught) tunaCaught = true;
        earnings = 5.00;

        break;
    case 18:
        if (!oarfishCaught) oarfishCaught = true;
        earnings = 50.00;

        break;
    case 19:
        if (!sacabambaspisCaught) sacabambaspisCaught = true;
        earnings = 80.00;

        break;
    case 20:
        if (!sharkCaught) sharkCaught = true;
        earnings = 35.00;

        break;
    }
}

// Apply reel meter multiplier upon upgrade
void rodUpgrade() {
    if (lvl2Upgrade) {
        meterFill = 0.2f;
    }
    if (lvl3Upgrade) {
        meterFill = 0.3f;
    }
    if (lvl4Upgrade) {
        meterFill = 0.4f;
    }
    if (lvl5Upgrade) {
        meterFill = 0.5f;
    }
    if (lvl6Upgrade) {
        meterFill = 0.6f;
    }
}

int purchaseFailed() {
    if (cash < rodPrice) return 1;
    else return 0;
}

// Mouse callback
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && !isCompendiumOpen && !isShopOpen && !isCreditsOpen) {
        rodUpgrade();

        if (fishBiting) { // If fish is biting, click to reel in
            reelMeter += meterFill; // Increase reel meter on each click
            if (reelMeter >= 2.0f) { // Full reel meter = fish caught
                fishBiting = false;

                addEntry(fishBite);

                showCatchScreen = true;

                score++; // Increase score
                cash = cash + earnings;

                printf("Fish caught! Score: %d\n", score); // Debug info
            }
        }
        else if (showCatchScreen) {
            showCatchScreen = false;
        }
        else if (!isWaiting && !fishBiting) { // If not waiting, cast the line
            isWaiting = true;
            fishBite = 2;
            //fishBite = spawn.randFish(isInAreaA);

            printf("Casting... #%d\n", fishBite); // Debug info
            glutTimerFunc(randomFloat(2000, 5000), [](int) { // Fish bites after random delay
                isWaiting = false;
                fishBiting = true;
                timer = 10.0f; // 5 seconds to reel in
                reelMeter = 0.0f; // Reset reel meter
                spawnFish(); // Spawn a fish
                }, 0);
        }
        else if (showPurchaseFailed) {
            showPurchaseFailed = false;
        }
        glutPostRedisplay();
    }
}

/// GLUT idle callback to keep updating the animation
void update(int value) {
    glutPostRedisplay();  // Trigger the display function
    glutTimerFunc(16, update, 0);  // Call every 16 ms for ~60 FPS
}

// Setup the OpenGL context
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Set the background to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);  // 2D orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_DEPTH_TEST);  // Disable depth test to ensure rain is in front (always rendered in front)
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  // Enable alpha blending for transparency
}

// Idle callback (for timer countdown)
void idle() {
    if (fishBiting) {
        timer -= 0.0017f; // Decrease timer
        if (timer <= 0.0f) { // Timer runs out = fish escapes
            fishBiting = false;
            reelMeter = 0.0f; // Reset reel meter
            printf("Fish escaped!\n"); // Debug info
        }

        if (reelMeter > 0.0f) reelMeter -= 0.0003f;

        glutPostRedisplay();
    }

    if (showCatchScreen) {
        //fishBounceY = 1.5f;
        //fishBounceY = fishBounceY + 0.01f;

        if (fishBounceY != 0) {
            fishBounceY = fishBounceY + 0.01f;
            glutPostRedisplay();
        }
        else fishBounceY = fishBounceY;
        //if (fishBounceY < boundsYB) {
        //    fishBounceY = fishBounceY + 0.03f;
        //    //glutPostRedisplay();
        //}

        //if (fishBounceY > boundsYT) {
        //    fishBounceY = fishBounceY - 0.001f;
        //    //boundsYT = boundsYT - (boundsYT / 6);

        //}
        glutPostRedisplay();
    }
    if (!showCatchScreen) {
        fishBounceY = -1.5f;
        glutPostRedisplay();
    }
}

// Reshape callback
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboardToggle(unsigned char key, int x, int y) {
    // Swap fishing area
    if (key == 'a' && !isCompendiumOpen && !isShopOpen && !isCreditsOpen) {
        if (isInAreaA == true) {
            // Area A BG
            waterR = 0.30f;
            waterG = 0.65f;
            waterB = 0.70f;

            isInAreaA = false;
        }
        else {
            // Area B BG
            waterR = 0.29f;
            waterG = 0.78f;
            waterB = 0.81f;

            isInAreaA = true;
        }

        glutPostRedisplay();
    }

    // Open shop
    if (key == 's' && !isCreditsOpen) {
        if (isCompendiumOpen) {
            isCompendiumOpen = false;
        }

        if (!isShopOpen) {
            isShopOpen = true;
        }
        else {
            isShopOpen = false;
        }

        glutPostRedisplay();
    }

    if (key == '1' && isShopOpen) {
        rodPrice = 5;
        confirm = true;

        rodTypeX = -0.16;
        rodType = "wooden rod for $5?";

        glutPostRedisplay();
    }
    else if (key == '2' && isShopOpen) {
        rodPrice = 25;
        confirm = true;
        rodTypeX = -0.13;
        rodType = "steel rod for $25?";

        glutPostRedisplay();
    }
    else if (key == '3' && isShopOpen) {
        rodPrice = 60;
        confirm = true;

        rodTypeX = -0.13;
        rodType = "cool rod for $60?";

        glutPostRedisplay();
    }
    else if (key == '4' && isShopOpen) {
        rodPrice = 150;
        confirm = true;
        rodTypeX = -0.15;
        rodType = "strong rod for $150?";

        glutPostRedisplay();
    }
    else if (key == '5' && isShopOpen) {
        rodPrice = 300;
        confirm = true;
        rodTypeX = -0.19;
        rodType = "legendary rod for $300?";

        glutPostRedisplay();
    }

    if (key == 'z' && confirm) {
        confirm = false;
        if (purchaseFailed() == 1) showPurchaseFailed = true;
        else {
            cash = cash - rodPrice;

            switch (rodPrice) {
            case 5:
                lvl2Upgrade = true;
                break;
            case 25:
                lvl3Upgrade = true;
                break;
            case 60:
                lvl4Upgrade = true;
                break;
            case 150:
                lvl5Upgrade = true;
                break;
            case 300:
                lvl6Upgrade = true;
                break;
            }
        }

        glutPostRedisplay();
    }
    if (key == 'x' && confirm) confirm = false;

    // Open Fish Compendium <``><|
    if (key == 'd' && !isCreditsOpen) {
        if (!isCompendiumOpen) {
            isCompendiumOpen = true;
        }
        else {
            isCompendiumOpen = false;
        }

        glutPostRedisplay();
    }

    if (key == 'z' && isCompendiumOpen) {
        pageNum = 1;

        glutPostRedisplay();
    }

    if (key == 'x' && isCompendiumOpen) {
        pageNum = 2;

        glutPostRedisplay();
    }

    if (key == 'c') {
        if (!isCreditsOpen) {
            isCreditsOpen = true;
        }
        else {
            isCreditsOpen = false;
        }

        glutPostRedisplay();
    }
}

// Main function
int main(int argc, char** argv) {
    createWindow(&argc, argv);
    srand(static_cast<unsigned>(time(0))); // Seed random generator


    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboardToggle);

    glClearColor(0.62f, 0.76f, 0.88f, 1.0f); // Sky background

    glutMainLoop();
    return 0;
}
