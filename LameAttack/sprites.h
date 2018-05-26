#define ALIEN_HEIGHT 8
#define ALIEN_WIDTH 11
 
//#define _ 0x000000 // BLACK
//#define X 0xFFFFFF // WHITE
//#define Y 0x0000FF  // Blue

#define _ 0x000000 //BLACK
#define X 0xFF0000 //RED
#define V 0x00FF00



//ALIEN BOB
int alienBobDown_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
 _,_,X,_,_,_,_,_,X,_,_,
 _,_,_,X,_,_,_,X,_,_,_,
 _,_,X,X,X,X,X,X,X,_,_,
 _,X,X,_,X,X,X,_,X,X,_,
 X,X,X,X,X,X,X,X,X,X,X,
 X,_,X,X,X,X,X,X,X,_,X,
 X,_,X,_,_,_,_,_,X,_,X,
 _,_,_,X,X,_,X,X,_,_,_,
};  
//ALIEN BOB
int alienBobUp_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
 _,_,X,_,_,_,_,_,X,_,_,
 X,_,_,X,_,_,_,X,_,_,X,
 X,_,X,X,X,X,X,X,X,_,X,
 X,X,X,_,X,X,X,_,X,X,X,
 X,X,X,X,X,X,X,X,X,X,X,
 _,_,X,X,X,X,X,X,X,_,_,
 _,_,X,_,_,_,_,_,X,_,_,
 _,X,_,_,_,_,_,_,_,X,_,
};
//ALIEN ALICE
int alienAlice_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
 _,_,_,_,X,X,X,_,_,_,_,
 _,X,X,X,X,X,X,X,X,X,_,
 X,X,X,X,X,X,X,X,X,X,X,
 X,X,X,_,_,X,_,_,X,X,X,
 X,X,X,X,X,X,X,X,X,X,X,
 _,_,_,X,X,_,X,X,_,_,_,
 _,_,X,X,_,_,_,X,X,_,_,
 X,X,_,_,_,X,_,_,_,X,X,
}; 
//ALIEN SPIDA
int alienSpida_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
 _,_,_,X,X,X,X,_,_,_,_,
 _,_,X,X,X,X,X,X,_,_,_,
 _,X,_,X,X,X,X,_,X,_,_,
 _,X,_,X,X,X,X,_,X,_,_,
 _,X,_,_,X,X,_,_,X,_,_,
 _,X,_,X,X,X,X,_,X,_,_,
 _,_,X,X,X,X,X,X,_,_,_,
 _,_,_,X,X,X,X,_,_,_,_,
};
//ALIEN BAT
int alienBat_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
 _,X,_,_,_,_,_,_,_,X,_,
 _,X,X,_,_,_,_,_,X,X,_,
 _,X,X,X,_,_,_,X,X,X,_,
 _,X,X,X,X,_,X,X,X,X,_,
 _,X,_,_,X,X,X,_,_,X,_,
 _,X,_,_,X,X,X,_,_,X,_,
 _,X,X,X,X,X,X,X,X,X,_,
 _,_,X,X,X,X,X,X,X,_,_,
};
//ALIEN SUPER
int alienSuper_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
 _,_,_,X,X,X,X,X,_,_,_,
 _,X,X,X,X,X,X,X,X,X,X,
 X,X,X,X,X,X,X,X,X,X,X,
 _,X,X,X,X,X,X,X,_,_,_,
 _,X,X,X,X,_,_,X,X,X,X,
 _,X,X,X,X,X,X,X,_,_,X,
 _,_,X,X,X,X,X,X,X,X,_,
 _,_,X,X,X,X,X,X,X,_,_
};
int alienFlash_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
 _,_,_,_,_,V,_,_,_,_,_,
 _,_,_,V,V,V,_,_,_,_,_,
 _,V,V,V,V,V,V,_,_,_,_,
 _,_,_,_,V,V,V,V,V,V,_,
 _,_,_,_,_,V,V,V,V,_,_,
 _,_,_,_,V,V,V,V,_,_,_,
 _,_,_,_,V,V,V,_,_,_,_,
 _,_,V,V,V,V,_,_,_,_,_,
};
//ALIEN RIP
int alienRemove_sprite[ALIEN_HEIGHT * ALIEN_WIDTH] = {
 _,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,
 _,_,_,_,_,_,_,_,_,_,_,
};