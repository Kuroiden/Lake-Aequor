#ifndef ENGINE_H
#define ENGINE_H

#include "graphics.h"
//add other header files here
#include "gameobject.h"

//This is a function that will only run once during the initialization of the engine
void Initialize();
//This function will run every frame
void Update();
//This function is responsible for initializing the actual engine itself
void PrepareEngine(int *argc, char** argv);
#endif