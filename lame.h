// Base Class
class AlienBaseClass
{
public:
    AlienBaseClass(int, int);
    //pure virtual
    virtual void draw(uLCD_4DGL&) = 0;
    virtual void update(uLCD_4DGL&) = 0;  
    int getDx();
    int getDy();
    void setDx(int);
    void setDy(int);
    void Direction(int);        
    int Head();    
private:     
    int Dx;
    int Dy;
    int Speed;
};

// Derived class AlienBob
class AlienBob:public AlienBaseClass
{
 
public:
    AlienBob(int , int );     
    virtual void draw(uLCD_4DGL&); 
    virtual void update(uLCD_4DGL&);
    void setPos(int ); 
    int getPos(); 
private:
    int Orient;
};
 
class AlienAlice:public AlienBaseClass
{
public:
    AlienAlice(int , int ); 
    virtual void draw(uLCD_4DGL&); 
    virtual void update(uLCD_4DGL&);
};
 
class AlienSpida:public AlienBaseClass
{ 
public: 
    AlienSpida(int , int ); 
    virtual void draw(uLCD_4DGL&); 
    virtual void update(uLCD_4DGL&);
};
//------------------------------------------------------------------------------
class AlienBat:public AlienBaseClass
{ 
public: 
    AlienBat(int , int ); 
    virtual void draw(uLCD_4DGL&); 
    virtual void update(uLCD_4DGL&);
};
class AlienSuper:public AlienBaseClass
{ 
public: 
    AlienSuper(int , int ); 
    virtual void draw(uLCD_4DGL&); 
    virtual void update(uLCD_4DGL&);
};
//------------------------------------------------------------------------------
class AlienFlash:public AlienBaseClass
{ 
public: 
    AlienFlash(int , int ); 
    virtual void draw(uLCD_4DGL&); 
    virtual void update(uLCD_4DGL&);
};

 