#ifndef ANIMATION_H
#define ANIMATION_H
#include <SDL2/SDL.h>
#include <iostream>
#include "animation.h"

class animation
{
    public:
        /** Default constructor */
        animation(SDL_Surface *sprite,SDL_Window *window,int xstart,int ystart,int spriteWidth,int spriteheight,int nbFrame);
        /** Default destructor */
        virtual ~animation();
        /** Access m_sprite
         * \return The current value of m_sprite
         */
        //getter setter
        int GetframeRate() { return m_frameRate; }
        /** Set m_frameRate
         * \param val New value to set
         */
        void SetframeRate(int val) { m_frameRate = val; }
        /** Access m_window
         * \return The current value of m_window
         */
        int Getx(){ return m_x;}
        void Setx(int val) { m_x = val; }

        int Gety(){ return m_y;}
        void Sety(int val) { m_y = val; }

        int GetlastFrameNb(){ return m_lastFrameNb;}
        void SetlastFrameNb(int val) { m_lastFrameNb = val;}

        //animation Methods
        void firstFrame(){
            SDL_Rect dest = { m_x,m_y,0,0 };
            SDL_Rect srcrect = {m_xstart,m_ystart,m_spriteWidth,m_spriteheight};
            SDL_BlitSurface (m_sprite,&srcrect,SDL_GetWindowSurface(m_window),&dest);

            m_lastFrameNb = 1;
            m_lastFrameTime = SDL_GetTicks();
            }
        void nextFrame(){
            if (m_lastFrameNb == 0){
                firstFrame();
            }else if (m_lastFrameNb >= m_nbFrame){
                    firstFrame();
            }
            else {
                if ((SDL_GetTicks()-m_lastFrameTime) >((1/(float)m_frameRate)*1000)){
                    SDL_Rect dest = { m_x,m_y,0,0 };
                    SDL_Rect srcrect = {m_xstart+(m_lastFrameNb*m_spriteWidth),m_ystart,m_spriteWidth,m_spriteheight};
                    SDL_BlitSurface (m_sprite,&srcrect,SDL_GetWindowSurface(m_window),&dest);

                    m_lastFrameNb +=1;
                    m_lastFrameTime = SDL_GetTicks();
                }else{
                    SDL_Rect dest = { m_x,m_y,0,0 };
                    SDL_Rect srcrect = {m_xstart+(m_lastFrameNb*m_spriteWidth),m_ystart,m_spriteWidth,m_spriteheight};
                    SDL_BlitSurface (m_sprite,&srcrect,SDL_GetWindowSurface(m_window),&dest);
                }
            }
        }
        void start(){

        }

    protected:
    private:
        SDL_Surface * m_sprite; //!< Member variable "m_sprite"
        SDL_Window * m_window; //!< Member variable "m_window"
        int m_xstart; //!< Member variable "m_xstart"
        int m_ystart; //!< Member variable "m_ystart"
        int m_spriteWidth; //!< Member variable "m_spriteWidth"
        int m_spriteheight; //!< Member variable "m_spriteheight"
        int m_nbFrame; //!< Member variable "m_nbFrame"
        Uint32 m_frameRate; //!< Member variable "m_frameRate"
        int m_x;
        int m_y;
        Uint32 m_lastFrameTime;
        int m_lastFrameNb;
};

#endif // ANIMATION_H
