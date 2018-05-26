#include "uLCD_4DGL.h"
#include "sprites.h"
#include "lame.h"
#include <ctime>
uLCD_4DGL LCD(p9, p10, p11);
AlienBaseClass::AlienBaseClass(int Dx, int Dy)
{
    setDx(Dx);
    setDy(Dy);
    int num = rand()%2;
    Direction(num);
}
int AlienBaseClass::Head()
{
    return Speed;
}
void AlienBaseClass::setDx(int Dx)
{
    this -> Dx = Dx;
}
 
void AlienBaseClass::setDy(int Dy)
{
    this -> Dy = Dy;
}
void AlienBaseClass::Direction(int Speed)
{
    this -> Speed = Speed;
} 
int AlienBaseClass::getDx()
{
    return Dx;
} 
int AlienBaseClass::getDy()
{
    return Dy;
}
//------------------------------------------------------------------------------
AlienBob::AlienBob(int Dx, int Dy):AlienBaseClass(Dx, Dy)
{
    int num;
    num = rand()%2;
    setPos(num);
}
int AlienBob::getPos() 
{
    return Orient;
}
void AlienBob::setPos(int Orient) 
{
    this -> Orient = Orient;
}
void AlienBob::draw(uLCD_4DGL& uLCD) 
{
    if (getPos() == 0) 
    {
        uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH, ALIEN_HEIGHT, alienBobDown_sprite);
        setPos(1);
    } 
    else 
    {
        uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH, ALIEN_HEIGHT, alienBobUp_sprite);
        setPos(0);
    }
}
void AlienBob::update(uLCD_4DGL& uLCD) 
{
    uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH,ALIEN_HEIGHT, alienRemove_sprite);
    if (Head() == 0) 
    {
        if (getDx() - 5 <= 0 ) 
        {
            Direction(1);
            setDx(getDx() + 5);
        } 
        else 
        {
            setDx(getDx() - 5);
        }
        draw(uLCD);
    } 
    else 
    {
        if (getDx() + 5 + ALIEN_WIDTH >= 127) 
        {
            Direction(0);
            setDx(getDx() - 5);
        } 
        else 
        {
            setDx(getDx() + 5);
        }
        draw(uLCD);
    }
}
//------------------------------------------------------------------------------
AlienAlice::AlienAlice(int Dx, int Dy):AlienBaseClass(Dx, Dy) {}
void AlienAlice::draw(uLCD_4DGL& uLCD) 
{
    uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH, ALIEN_HEIGHT, alienAlice_sprite);
}
void AlienAlice::update(uLCD_4DGL& uLCD) 
{
    uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH,ALIEN_HEIGHT, alienRemove_sprite);
    if (Head() == 0) 
    {
        if (getDx() - 5 <= 0 ) 
        {
            Direction(1);
            setDx(getDx() + 5);
        } 
        else 
        {
            setDx(getDx() - 5);
        }
        draw(uLCD);
    } 
    else 
    {
        if (getDx() + ALIEN_WIDTH + 5 >= 127) 
        {
            Direction(0);
            setDx(getDx() - 5);
        } 
        else 
        {
            setDx(getDx() + 5);
        }
        draw(uLCD);
    }
}
//------------------------------------------------------------------------------
AlienSpida::AlienSpida(int Dx, int Dy):AlienBaseClass(Dx, Dy) {}
void AlienSpida::draw(uLCD_4DGL& uLCD) 
{
    uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH, ALIEN_HEIGHT, alienSpida_sprite);
} 
void AlienSpida::update(uLCD_4DGL& uLCD) 
{
    uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH,ALIEN_HEIGHT, alienRemove_sprite);
    if (Head() == 0) 
    {
        if (getDx() - 5 <= 0 ) 
        {
            Direction(1);
            setDx(getDx() + 5);
        } 
        else 
        {
             setDx(getDx() - 5);
        }
        draw(uLCD);
    } 
    else 
    {
        if (getDx() + ALIEN_WIDTH + 5>= 127) 
        {
            Direction(0);
            setDx(getDx() - 5);
        } 
        else 
        {
            setDx(getDx() + 5);
        }
        draw(uLCD);
    }
}
//------------------------------------------------------------------------------
AlienBat::AlienBat(int Dx, int Dy):AlienBaseClass(Dx, Dy) {}
void AlienBat::draw(uLCD_4DGL& uLCD) 
{
    uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH, ALIEN_HEIGHT, alienBat_sprite);
} 
void AlienBat::update(uLCD_4DGL& uLCD) 
{
    uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH,ALIEN_HEIGHT, alienRemove_sprite);
    if (Head() == 0) 
    {
        if (getDx() - 5 <= 0 ) 
        {
            Direction(1);
            setDx(getDx() + 5);
        } 
        else 
        {
             setDx(getDx() - 5);
        }
        draw(uLCD);
    } 
    else 
    {
        if (getDx() + ALIEN_WIDTH + 5>= 127) 
        {
            Direction(0);
            setDx(getDx() - 5);
        } 
        else 
        {
            setDx(getDx() + 5);
        }
        draw(uLCD);
    }
}
//------------------------------------------------------------------------------
AlienSuper::AlienSuper(int Dx, int Dy):AlienBaseClass(Dx, Dy) {}
void AlienSuper::draw(uLCD_4DGL& uLCD) 
{
    uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH, ALIEN_HEIGHT, alienSuper_sprite);
} 
void AlienSuper::update(uLCD_4DGL& uLCD) 
{
    uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH,ALIEN_HEIGHT, alienRemove_sprite);
    if (Head() == 0) 
    {
        if (getDx() - 5 <= 0 ) 
        {
            Direction(1);
            setDx(getDx() + 5);
        } 
        else 
        {
             setDx(getDx() - 5);
        }
        draw(uLCD);
    } 
    else 
    {
        if (getDx() + ALIEN_WIDTH + 5>= 127) 
        {
            Direction(0);
            setDx(getDx() - 5);
        } 
        else 
        {
            setDx(getDx() + 5);
        }
        draw(uLCD);
    }
}
//------------------------------------------------------------------------------
AlienFlash::AlienFlash(int Dx, int Dy):AlienBaseClass(Dx, Dy) {}
void AlienFlash::draw(uLCD_4DGL& uLCD) 
{
    uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH, ALIEN_HEIGHT, alienFlash_sprite);
} 
void AlienFlash::update(uLCD_4DGL& uLCD) 
{
    uLCD.BLIT(getDx(),getDy(), ALIEN_WIDTH,ALIEN_HEIGHT, alienRemove_sprite);
    if (Head() == 0) 
    {
        if (getDx() - 5 <= 0 ) 
        {
            Direction(1);
            setDx(getDx() + 5);
        } 
        else 
        {
             setDx(getDx() - 5);
        }
        draw(uLCD);
    } 
    else 
    {        
        if (getDx() + ALIEN_WIDTH + 5>= 127) 
        {
            Direction(0);
            setDx(getDx() - 5);
        } 
        else 
        {
            setDx(getDx() + 5);
        }
        draw(uLCD);
    }
}