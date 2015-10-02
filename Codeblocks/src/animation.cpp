#include "animation.h"

animation::animation(SDL_Surface *sprite,SDL_Window *window,int xstart,int ystart,int spriteWidth,int spriteheight,int nbFrame)
: m_sprite(sprite),m_window(window),m_xstart(xstart),m_ystart(ystart),m_spriteWidth(spriteWidth),m_spriteheight(spriteheight),m_nbFrame(nbFrame),m_frameRate(6),m_x(0),m_y(0),m_lastFrameNb(0)
{

}

animation::~animation()
{
    //dtor
}
