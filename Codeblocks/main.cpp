#include <SDL2/SDL.h>
#include "animation.h"
#include <iostream>

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 780

int main(int argc, char *argv[])
{
    // Variables

    SDL_Window *window;
    SDL_Event event;
    SDL_Surface *spriteMario = NULL;
    const Uint8 *KeyState = SDL_GetKeyboardState(NULL);
    bool end = false;


    // Window

    window = SDL_CreateWindow("My Mario", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    if(!window)
    {
        std::cout << "SDL Error : " << SDL_GetError() << std::endl;
        return -1;
    }

    //surfaces loading
    spriteMario=SDL_LoadBMP("sprite/mario/spritemario.bmp");
    SDL_SetColorKey(spriteMario,1,SDL_MapRGB(spriteMario->format,129,129,129));

    animation pasGauche(spriteMario,window,145,1,62,95,4);
    animation pasDroit(spriteMario,window,144,98,62,95,4);
    animation chute(spriteMario,window,-7,209,94,93,5);
    chute.Sety(200);



    // Event loop

    while(!end)
    {
        SDL_PollEvent(&event);

        if(event.window.event == SDL_WINDOWEVENT_CLOSE)
            end = true;


        SDL_FillRect(SDL_GetWindowSurface(window),NULL,SDL_MapRGB(SDL_GetWindowSurface(window)->format,129,129,129));

        if (KeyState[SDL_SCANCODE_RIGHT]){

        if (pasDroit.Getx() < WINDOW_WIDTH){
            pasDroit.Setx(pasDroit.Getx()+1);
            pasGauche.Setx(pasDroit.Getx()+1);
        }else{
            pasDroit.Setx(0);
            pasGauche.Setx(0);
        }

        if(pasDroit.GetlastFrameNb() <4 ){
            pasDroit.nextFrame();
        }else if (pasGauche.GetlastFrameNb() < 4){
            pasGauche.nextFrame();
        }else{
            pasDroit.SetlastFrameNb(0);
            pasGauche.SetlastFrameNb(0);
            pasDroit.nextFrame();
        }
        }

        if(KeyState[SDL_SCANCODE_LEFT]){
        if (pasDroit.Getx() > 0){
            pasDroit.Setx(pasDroit.Getx()-1);
            pasGauche.Setx(pasDroit.Getx()-1);
        }else{
            pasDroit.Setx(WINDOW_WIDTH);
            pasGauche.Setx(WINDOW_WIDTH);
        }

        if(pasDroit.GetlastFrameNb() <4 ){
            pasDroit.nextFrame();
        }else if (pasGauche.GetlastFrameNb() < 4){
            pasGauche.nextFrame();
        }else{
            pasDroit.SetlastFrameNb(0);
            pasGauche.SetlastFrameNb(0);
            pasDroit.nextFrame();
        }
        }
        if(KeyState[SDL_SCANCODE_DOWN]){
        if (pasDroit.Gety() < WINDOW_HEIGHT){
            pasDroit.Sety(pasDroit.Gety()+1);
            pasGauche.Sety(pasDroit.Gety()+1);
        }else{
            pasDroit.Sety(0);
            pasGauche.Sety(0);
        }

        if(pasDroit.GetlastFrameNb() <4 ){
            pasDroit.nextFrame();
        }else if (pasGauche.GetlastFrameNb() < 4){
            pasGauche.nextFrame();
        }else{
            pasDroit.SetlastFrameNb(0);
            pasGauche.SetlastFrameNb(0);
            pasDroit.nextFrame();
        }
        }

        if (KeyState[SDL_SCANCODE_SPACE]){
            chute.nextFrame();
        }

        SDL_UpdateWindowSurface(window);

    }
    SDL_FreeSurface(spriteMario);

    return 0;
}
