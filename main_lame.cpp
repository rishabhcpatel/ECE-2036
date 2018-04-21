#include "mbed.h"
#include "uLCD_4DGL.h"
#include "PinDetect.h"
#include "Speaker.h"
#include "MMA8452.h"
#define ALIEN_HEIGHT 8 
#define ALIEN_WIDTH 11

#include <vector>
#include <iterator>
#include <algorithm>


#include <stdio.h>
#include <stdlib.h>

#include "lame.h"
#define _ 0x000000
#define X 0xF39C12
#define Y 0x0000FF  
#define V 0xF39C12 

#define EARTH_HEIGHT 20 
#define EARTH_WIDTH 20

#define G 0x07E0 
#define B 0x001F

int EarthEmpty_sprite[EARTH_HEIGHT * EARTH_WIDTH] = {
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_, 
    _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_,_ 
    
};
int Earth_sprite[EARTH_HEIGHT * EARTH_WIDTH] = {
    B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,
    B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B, 
    B,B,B,B,B,B,G,B,B,B,B,B,B,B,B,B,B,B,B,B, 
    B,B,B,B,B,B,G,G,G,B,B,B,G,G,B,B,B,B,B,B, 
    B,B,B,B,B,B,B,G,G,G,G,G,G,B,B,B,B,B,B,B, 
    B,B,B,B,B,B,B,B,G,G,G,G,G,B,B,B,B,B,B,B, 
    B,B,B,B,B,B,B,B,B,G,G,G,B,B,B,B,B,B,B,B, 
    B,B,B,B,B,B,B,B,G,G,G,G,G,G,B,B,B,B,B,B, 
    B,B,B,B,B,B,B,G,G,G,G,G,G,G,G,B,B,B,B,B, 
    B,B,B,B,B,B,G,G,G,G,G,G,G,G,G,G,G,B,B,B, 
    B,B,B,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,B,B, 
    B,B,B,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G, 
    B,B,B,B,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,B, 
    B,G,B,B,B,G,G,G,G,G,G,G,G,G,G,G,G,G,G,B, 
    B,B,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,B,B, 
    B,B,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,B,B, 
    B,B,B,B,G,G,G,G,G,G,G,G,G,G,G,G,G,B,B,B, 
    B,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,B,B,B, 
    B,B,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,B,B,B, 
    B,B,B,B,G,G,G,G,G,G,G,G,G,G,G,G,B,B,B,B 
    
};

int alienEmpty_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_,
    _,_,_,_,_,_,_,_,_,_,_
};

int alienBattleShip_sprite[6*15] = {
 _,_,_,_,V,V,V,V,V,V,V,_,_,_,_,
 _,_,_,V,V,V,V,V,V,V,V,V,V,_,_,
 _,_,V,V,V,V,V,V,V,V,V,V,V,_,_,
 _,V,V,V,V,V,V,V,V,V,V,V,V,V,_,
 V,_,_,V,V,V,_,_,_,V,V,V,_,_,V,
 _,_,V,V,V,_,_,_,_,_,V,V,V,_,_
};

int alienBattleShipEmpty_sprite[6*15] = {
 _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,_,_,_,_,
};

Serial pc(USBTX,USBRX);
MMA8452 acc(p28, p27, 40000);


using namespace std;
Timer timer; 
time_t startTime;
uLCD_4DGL uLCD(p9, p10, p11);
Speaker mySpeaker(p21);
PinDetect pbLeft(p22);
PinDetect pbShoot(p23);
PinDetect pbRight(p24);

//Declare Global Var
static bool moving = false;    // whether spaceship is moving
static bool heading = false;   // the heading of the bullet
static bool shoot = false;     // is you are shooting or not
static bool contact =  true;   // whether contact is made with alien

//initialize the size of the bullet and spaceship
static int s1 = 60;
static int s2 = 120;
static int b1 = 68;
static int b2 = 112;
//place holder for updating size if needed
static int placeHolder = 57;

//------------------------------------------------------------------------------

vector <AlienBaseClass*> aliens(6);
void pbLeft_hit_callback(void)
{    
    heading = false;
    moving = true;
}
void pbShoot_hit_callback (void)
{
    if (!shoot) {
        b1 = s1 + 5;
    }
    shoot = true;
} 
void pbRight_hit_callback (void)
{
    heading = true;
    moving = true;
}

void beginInst()
{ 
    int screenHeight[6];
    int numArray[6];
    for (int i = 0; i < aliens.size(); i++) {
        int temp = (rand()%5) + 1;
        numArray[i] = temp;
        uLCD.printf("%d",numArray[i]);
        screenHeight[i] = rand()%117 + 1;
    }
    for (int i = 0; i < aliens.size(); i++)
    {
        if(numArray[i] == 1)
        {
            aliens[i] = new AlienBob(screenHeight[i], 10 + (i*10));
            aliens[i] -> draw(uLCD);
        }
        if(numArray[i] == 2)
        {
            aliens[i] = new AlienAlice(screenHeight[i], 10 + (i*10));
            aliens[i] -> draw(uLCD);
        }
        if(numArray[i] == 3)
        {
            aliens[i] = new AlienSpida(screenHeight[i], 10 + (i*10));
            aliens[i] -> draw(uLCD);
        }
        if(numArray[i] == 4)
        {
            aliens[i] = new AlienBat(screenHeight[i], 10 + (i*10));
            aliens[i] -> draw(uLCD);
        }
        if(numArray[i] == 5)
        {
            aliens[i] = new AlienSuper(screenHeight[i], 10 + (i*10));
            aliens[i] -> draw(uLCD);
        }
        if(numArray[i] == 6)
        {
            aliens[i] = new AlienFlash(screenHeight[i], 10 + (i*10));
            aliens[i] -> draw(uLCD);
        }
        
    }
    /*
    aliens[0] = new AlienBob(screenHeight[0], 20);
    aliens[1] = new AlienAlice(screenHeight[1], 30);
    aliens[2] = new AlienSpida(screenHeight[2], 40);
    aliens[3] = new AlienBat(screenHeight[3], 50);
    aliens[4] = new AlienSuper(screenHeight[4], 60);
    aliens[5] = new AlienFlash(screenHeight[5], 70);
 
    aliens[0] -> draw(uLCD);
    aliens[1] -> draw(uLCD);
    aliens[2] -> draw(uLCD);
    aliens[3] -> draw(uLCD);
    aliens[4] -> draw(uLCD);
    aliens[5] -> draw(uLCD);  */
 
    uLCD.filled_rectangle(s1,s2,s1+15,s2+4, X);

}

void draw()
{
   int offsetx = 110;
   int offsety = 63;
   double factor = 50;
   
   double x = 0, y = 0, z = 0;
    
   //set parameters -- use these and don't change
   acc.setBitDepth(MMA8452::BIT_DEPTH_12);
   acc.setDynamicRange(MMA8452::DYNAMIC_RANGE_4G);
   acc.setDataRate(MMA8452::RATE_100);
   
   while(1) 
   {
      
      uLCD.BLIT(-1*y*factor+offsety, -1*x*factor+offsetx, EARTH_WIDTH, EARTH_HEIGHT, EarthEmpty_sprite);
      if(!acc.isXYZReady()) 
      {
         wait(0.01);
      }
      else
      {       
      acc.readXYZGravity(&x,&y,&z); //notice this is passed by reference use pointers                 
      uLCD.BLIT(-1*y*factor+offsety, -1*x*factor+offsetx, EARTH_WIDTH, EARTH_HEIGHT, Earth_sprite);
      // You can uncomment this line to see the values coming off the MMA8452           
      //uLCD.printf("\n(%.2f,%.2f,%.2f)  \n", x,y,z);             
      }             
    }
}

void playMusic(){
    PwmOut buzzer(p21);
    BusOut led(LED1,LED2,LED3,LED4);    
    float frequency[] = {262,0,262,0,262,0,349,0,523,0,466,0,440,0,392,0,698,0,523,0,466,0,440,0,392,0,698,0,523,0,466,0,440,0,466,0,392,0,/**/};
    float beat[] = {.3,0,.3,0,.3,0,2,0,2,0,.3,0,.3,0,.3,0,2,0,1,0,.3,0,.3,0,.3,0,2,0,1,0,.3,0,.3,0,.3,0,2,0/**/};
    float frequency2[] = {262,0,262,0,294,0,294,0,466,0,440,0,392,0,349,0,349,0,392,0,440,0,392,0,294,0,330,0,523,0,523,0,698,0,622,0,554,0,523,0,466,0,415,0,392,0,349,0,523,0};
    float beat2[] = {.75,0,.25,0,1.5,0,.5,0,.5,0,.5,0,.5,0,.5,0,.3,0,.3,0,.3,0,1,0,.5,0,1,0,.75,0,.25,0,1,0,.5,0,1,0,.5,0,1,0,.5,0,1,0,.5,0,4,0};
    
    uLCD.printf("\n\n\n     WELCOME "); 
    uLCD.printf("\n      TO THE ");
    uLCD.printf("\n LAME Attack Game!");
    uLCD.printf("\n\n    It's Your ");  
    uLCD.printf("\n     turn to ");
    uLCD.printf("\n    Protect the");
    uLCD.printf("\n      PLANET!");
    uLCD.printf("\n    GOOD LUCK ");  
        for(int i=0; i<= 37;i++)
        {
            buzzer.period(2/(frequency[i]));
            buzzer = 0.5;
            
            wait(0.4*beat[i]); 
            if(beat[i]==0)
            {wait(.05);}
          
        }
        
        for(int i=0; i<= 49;i++)
        {
            buzzer.period(2/(frequency2[i]));
            buzzer = 0.5;
            
            wait(0.4*beat2[i]); 
            if(beat2[i]==0)
            {wait(.05);}
          
        }
        uLCD.cls();
}

//MAIN START
int main()
{
    srand(time(NULL));
    float totalTime;
    uLCD.background_color(BLACK);
    uLCD.baudrate(300000); //3000000
    pbLeft.mode(PullUp);    
    pbShoot.mode(PullUp);
    pbRight.mode(PullUp);
    
    playMusic();
    
    wait(2.0);                      
    uLCD.cls();                  
 
    pbLeft.attach_deasserted(&pbLeft_hit_callback);
    pbLeft.setSampleFrequency();
    pbShoot.attach_deasserted(&pbShoot_hit_callback);
    pbShoot.setSampleFrequency();
    pbRight.attach_deasserted(&pbRight_hit_callback);        
    pbRight.setSampleFrequency();
    
    beginInst();
    timer.start();   
               
    while (aliens.size() > 0) 
    { 
        // loop through and draw all six aliens
        for (int i = 0; i < aliens.size(); i++) 
        {
            aliens[i] -> update(uLCD);
        }
        //if you shoot i.e. press the shoot button, execute the statements inside the if statement
        if (shoot) 
        {
            // draw out the bullet with a rectangle
            uLCD.filled_rectangle(b1, b2, b1 + 2, b2 +4, _);
            
            //for all six aliens check if the bullet hits the aliens.
            for (int i = 0; i < aliens.size(); i++) 
            {
                //The if condition checks is the bullet is in the region of the alien. If so, it replaces the alien with an empty sptite
                if ( (aliens[i]->getDx()- 4 <= b1) && (aliens[i]->getDy()- 8 <= b2) && (aliens[i]->getDx() + 15 >= b1 + 2) && (aliens[i]->getDy()+8 >= b2 - 8 )) 
                {                
                    
                    uLCD.BLIT(aliens[i]->getDx(),aliens[i]->getDy(), ALIEN_WIDTH, ALIEN_HEIGHT, alienEmpty_sprite);                    
                    shoot = false;
                    contact = true;
                    b2 = 115;
                    aliens.erase(aliens.begin()+i);                    
                    //free(aliens[i]);
                    mySpeaker.PlayNote(100.0, 0.25, 0.01);
                    placeHolder += placeHolder;
                } 
                
                //set the bound for when the bullet must be fired or not
                else if (b2 < 0) 
                {
                    shoot = false;
                    b2 = 115;
                }
            }
            //if the bullet is in correct region and fired move the bullet up until it hits an alien
            if (shoot && contact == true) 
            {
                b2 = b2 - 5; //5
                uLCD.filled_rectangle(b1, b2, b1 + 2, b2 + 4, RED);
                //missile(b1, b2, b1 + 2, b2 + 4);
            }
        }
        
        // is you are moving left or right redraw the rectangle and replace the old spot with a black rectangle
        if (moving) 
        {
            uLCD.filled_rectangle(s1,s2,s1+15,s2+4,_); 
            //uLCD.filled_rectangle(getAccY(),s2,getAccY()+15,s2+4,_);
            //uLCD.BLIT(s1, s2, 11, 5, alienEmpty_sprite);
            
            // this sets the bounds for which the spaceship must remain in
            if (heading) 
            {
                if (s1 + 26 > 128) 
                {
                    s1 = 128-10;
                } 
                else 
                {
                    s1 = s1 + 11;
                }
            } 
            else 
            {
                if (s1 - 11 < 0) 
                {
                    s1 = 0;
                } 
                else 
                {
                    s1 = s1 - 11;
                }
            }
            moving = false;
            uLCD.filled_rectangle(s1, s2, s1+15,s2+4,X);
            //uLCD.BLIT(s1, s2, 11, 5, alienEmpty_sprite);
        }
    }
    wait(1.0);
    // Stop the timer
    timer.stop();    
    // Read the time           
    totalTime = timer.read();
    //Clear and print ending screen
    uLCD.cls();
    uLCD.printf("\n\n\n  CONGRATULATIONS!");
    uLCD.printf("\n\n  You saved Earth\n\n in %.2f seconds.", totalTime);
    wait(2.0);
    draw();
    uLCD.reset();
}