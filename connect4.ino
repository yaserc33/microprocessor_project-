#include <FastLED.h>

#define num_led 64
#define led_pin 6

//Input Button 
const int numOfInputs = 5;
const int inputPins[numOfInputs] = {12,11,10,9,8};
// up 12 , down 11 , right 10 , left 9 ,  ok 8 
int inputState[numOfInputs];
int lastInputState[numOfInputs] = {LOW,LOW,LOW,LOW,LOW};
bool inputFlags[numOfInputs] = {LOW,LOW,LOW,LOW,LOW};
long lastDebounceTime[numOfInputs] = {0,0,0,0,0};
long debounceDelay = 5;
int inputCounters[numOfInputs];

//led 
CRGB leds[num_led];

//virtual board for connect 4 game
int connect4_board[48];

// plyers turn flags 
int P = 1;

//  current connect4_location
int connect4_loc = 4;


//flag to force arduino to wite for input
int waite_to_press = 0;


void setup() {

  for (int i = 0; i < numOfInputs; i++) {
    pinMode(inputPins[i], INPUT_PULLUP);
  }

  FastLED.addLeds < WS2812B, led_pin > (leds, num_led);
  FastLED.setBrightness(10);
  Serial.begin(9600);
}



void loop() {
  leds[8]  =CRGB::White ;
  leds[9]  =CRGB::White ;
  leds[10] =CRGB::White ;
  leds[11] =CRGB::White ;
  leds[12] =CRGB::White ;
  leds[13] =CRGB::White ;
  leds[14] =CRGB::White ;
  leds[15] =CRGB::White ;
 FastLED.show();

//p1 turn
  while (P == 1) {
    C4_check_win();
    C4_live_blink(connect4_loc,P);
    waite_to_press = 0;
    while (waite_to_press == 0) {
    C4_Input_handel();
   } C4_refresh_led();
  }
//p2 turn
 while (P == 2) {
    C4_check_win();
    C4_live_blink(connect4_loc,P);
    waite_to_press = 0;
    while (waite_to_press == 0) {
    C4_Input_handel();
    }C4_refresh_led();
  }

}

// to refresh led  for first row after player turn end 
void C4_refresh_led(){
  
  for (int i = 0; i < 8; i++) {
        if (connect4_board[i] == 1) {
          C4_hard(i,0, 1);
          FastLED.show();
        }
        if (connect4_board[i] == 2) {
          C4_hard(i,0, 2);
          FastLED.show();
        }
  }
}

// fix change on led matrix 
void C4_hard(int x, int row,int player) {
  if (player == 1) {
    leds[x+row+16]= CRGB::Yellow;
    FastLED.show();
  } else if (player == 2) {
    leds[x+row+16]= 0x153355;
    FastLED.show();
  }
}

//live blink on led matrix
void C4_live_blink(int x, int p) {
  if (p == 1) {
      leds[0] = CRGB::Yellow;
      leds[1] = CRGB::Yellow;
      leds[2] = CRGB::Yellow;
      leds[3] = CRGB::Yellow;
      leds[4] = CRGB::Yellow;
      leds[5] = CRGB::Yellow;
      leds[6] = CRGB::Yellow;
      leds[7] = CRGB::Yellow;
      leds[x+16] = CRGB::Yellow;
      FastLED.show();
      delay(200);
      leds[x+16] = CRGB::Black;
      
    
  }
  if (p == 2) {
      leds[0] =0x153355;
      leds[1] =0x153355;
      leds[2] =0x153355;
      leds[3] =0x153355;
      leds[4] =0x153355;
      leds[5] =0x153355;
      leds[6] =0x153355;
      leds[7] =0x153355;
      leds[x+16] =0x153355;
      FastLED.show();
      delay(200);
      leds[x+16] = CRGB::Black;
      


  }
}

// deal with input signal
void C4_Input_handel() {

  ///setInputFlags
  for (int i = 0; i < numOfInputs; i++) {
    int reading = digitalRead(inputPins[i]);
    if (reading != lastInputState[i]) {
      lastDebounceTime[i] = millis();
    }
    if ((millis() - lastDebounceTime[i]) > debounceDelay) {
      if (reading != inputState[i]) {
        inputState[i] = reading;
        if (inputState[i] == HIGH) {
          inputFlags[i] = HIGH;
        }
      }
    }
    lastInputState[i] = reading;
  }

  //resolveInputFlags
  for (int i = 0; i < numOfInputs; i++) {
    if (inputFlags[i] == HIGH) {
      C4_inputAction(i);
      inputFlags[i] = LOW;
      inputCounters[i]++;
    }
  }
}
//action when button pressed
void C4_inputAction(int input) {

  //right
  if (input == 2 && inputCounters[2] != 0) {

    if ( connect4_loc == 7) {
      connect4_loc = 0;
     
    } else {
        connect4_loc = connect4_loc + 1;
      }
    waite_to_press = 1;
  }
  //left
  if (input == 3 && inputCounters[3] != 0) {

    if (connect4_loc == 0 ) {
      connect4_loc = 7;
      
    } else {
      connect4_loc = connect4_loc - 1; 
      }
    waite_to_press = 1;
   
  }
  //ok  
  if (input == 4 && inputCounters[4] != 0) {
    C4_link_virtual_board();
    waite_to_press = 1;
  }

}

// link matrix led with connect4_board
void C4_link_virtual_board() {
    int  t=0;// parameter for  while loop 

  if (P == 1) {
    int last_row =40; 
    while(t==0){
      if ( connect4_board[last_row+connect4_loc] == 0 ){
        connect4_board[last_row + connect4_loc]=1;
        C4_hard(connect4_loc,last_row,P);
        P = 2; //  switch to second loop (player 2 turn)
        connect4_loc = 4;
        t = 1;
        }else {last_row = last_row - 8;} 
      }
  } else if (P == 2) {
    int  last_row=40;
    while(t==0){
      if (connect4_board[last_row+connect4_loc] == 0) {
        connect4_board[last_row+connect4_loc]=2;
        C4_hard(connect4_loc,last_row,P);
        P = 1; //  switch to first loop (player 1 turn)
        connect4_loc = 4;
        t = 1;
      } else{
          last_row = last_row - 8;
        }
    }
  }
}

// to check if Cborad full or not 
void C4_drow_check(){
  int z=1;
  for (int i = 0; i < 48; i++)
  {    
      if(connect4_board[i] == 0){
      z=0;
      break;
      }
  }
  if (z==1){
      while (true) {//drow
      leds[0] =CRGB::Yellow ;
      leds[1] =CRGB::Yellow ;
      leds[2] =CRGB::Yellow ;
      leds[3] =CRGB::Yellow ;
      leds[4] =CRGB::Yellow ;
      leds[5] =CRGB::Yellow ;
      leds[6] =CRGB::Yellow ;
      leds[7] =CRGB::Yellow ;
      leds[8] =CRGB::Yellow ;
      leds[9] =CRGB::Yellow ;
      leds[10] =CRGB::Yellow ;
      leds[11] =CRGB::Yellow ;
      leds[12] =CRGB::Yellow ;
      leds[13] =CRGB::Yellow ;
      leds[14] =CRGB::Yellow ;
      leds[15] =CRGB::Yellow ;
      FastLED.show();
      FastLED.show();
      delay(200);
      leds[0] =0x153355 ;
      leds[1] =0x153355 ;
      leds[2] =0x153355 ;
      leds[3] =0x153355 ;
      leds[4] =0x153355 ;
      leds[5] =0x153355 ;
      leds[6] =0x153355 ;
      leds[7] =0x153355 ;
      leds[8] =0x153355 ;
      leds[9] =0x153355 ;
      leds[10] =0x153355 ;
      leds[11] =0x153355 ;
      leds[12] =0x153355 ;
      leds[13] =0x153355 ;
      leds[14] =0x153355 ;
      leds[15] =0x153355 ;
      FastLED.show();
      delay(200);
    }
  }
}

// check for winer or drow
void C4_check_win() {
  int plz=0 ;
  for (int i = 0; i< 48; i++) {
  //p1 win 
        //row 
      if  (connect4_board[i] == 1 && connect4_board[i+1] == 1 && connect4_board[i+2] == 1 && connect4_board[i+3] == 1 ){
          if (i==7 || i==15 || i==23 || i==31 || i==39 ){
          continue ;
          }
          else if ( i+1== 7 ||  i+1==15 ||  i+1==23 ||  i+1==31 ||  i+1==39  ){
          continue ;
          }
          else if ( i+2 == 7 ||  i+2 ==15 ||  i+2 ==23 ||  i+2 ==31 ||  i+2 ==39 ){
          continue ;
          }else{plz=1;Serial.print("r1");}
        }
        //column
        else if  (connect4_board[i] == 1 && connect4_board[i+8] == 1 && connect4_board[i+16] == 1 && connect4_board[i+24] == 1 ){
           if (i==40 || i==41 || i==42 || i==43 || i==44 || i==45 || i==46 || i==47){
          continue ;
          }
          else if (i+8==40 || i+8==41 || i+8==42 || i+8==43 || i+8==44 || i+8==45 || i+8==46 || i+8==47){
          continue ;
          }
          else if (i+16==40 || i+16==41 || i+16==42 || i+16==43 || i+16==44 || i+16==45 || i+16==46 || i+16==47){
          continue ;
          }else{plz=1;Serial.print("c1");}
        }
        //diagnls
        //decrease diagnal
        else if  (connect4_board[i] == 1 && connect4_board[i+9] == 1 && connect4_board[i+18] == 1 && connect4_board[i+27] == 1 ){
          if (i==7 || i==15 || i==23 || i==31 || i==39 ){
          continue ;
          }
          else if ( i+9== 7 ||  i+9==15 ||  i+9==23 ||  i+9==31 ||  i+9==39  ){
          continue ;
          }
          else if ( i+18 == 7 ||  i+18 ==15 ||  i+18 ==23 ||  i+18 ==31 ||  i+18 ==39 ){
          continue ;
          }
          else{plz=1;Serial.print("d1");}
        }
        //increase diagnal
        else if  (connect4_board[i] == 1 && connect4_board[i+7] == 1 && connect4_board[i+14] == 1 && connect4_board[i+21] == 1 ){
          if (i==0 || i==8 || i==16 || i==24 || i==32 || i==40 ){
          continue ;
          }
          else if (i+7==0 || i+7==8 || i+7==16 || i+7==24 || i+7==32 || i+7==40 ){
          continue ;
          }
          else if (i+14==0 || i+14==8 || i+14==16 || i+14==24 || i+14==32 || i+14==40 ){
          continue ;
          }
          else{plz=1;Serial.print("i1");}
        }
    //p2 win 
        //row 
        else if (connect4_board[i] == 2 && connect4_board[i+1] == 2 && connect4_board[i+2] == 2 && connect4_board[i+3] == 2 ){
        if (i==7 || i==15 || i==23 || i==31 || i==39 ){
          continue ;
          }
          else if ( i+1== 7 ||  i+1==15 ||  i+1==23 ||  i+1==31 ||  i+1==39  ){
          continue ;
          }
          else if ( i+2 == 7 ||  i+2 ==15 ||  i+2 ==23 ||  i+2 ==31 ||  i+2 ==39 ){
          continue ;
          }
          else{plz=2;Serial.print("r2");}
        }
        //column
        else if  (connect4_board[i] == 2 && connect4_board[i+8] == 2 && connect4_board[i+16] == 2 && connect4_board[i+24] == 2 ){
         if (i==40 || i==41 || i==42 || i==43 || i==44 || i==45 || i==46 || i==47){
          continue ;
          }
          else if (i+8==40 || i+8==41 || i+8==42 || i+8==43 || i+8==44 || i+8==45 || i+8==46 || i+8==47){
          continue ;
          }
          else if (i+16==40 || i+16==41 || i+16==42 || i+16==43 || i+16==44 || i+16==45 || i+16==46 || i+16==47){
          continue ;
          }else{plz=1;Serial.print("c2");}
        }
           //diagnls
        //decrease diagnal
        else if  (connect4_board[i] == 2 && connect4_board[i+9] == 2 && connect4_board[i+18] == 2 && connect4_board[i+27] == 2 ){
          if (i==7 || i==15 || i==23 || i==31 || i==39 ){
          continue ;
          }
          else if ( i+9== 7 ||  i+9==15 ||  i+9==23 ||  i+9==31 ||  i+9==39  ){
          continue ;
          }
          else if ( i+18 == 7 ||  i+18 ==15 ||  i+18 ==23 ||  i+18 ==31 ||  i+18 ==39 ){
          continue ;
          }
          else{plz=2;Serial.print("d2");}
        }
        //increase diagnal
        else if  (connect4_board[i] == 2 && connect4_board[i+7] == 2 && connect4_board[i+14] == 2 && connect4_board[i+21] == 2 ){
          if (i==0 || i==8 || i==16 || i==24 || i==32 || i==40 ){
          continue ;
          }
          else if (i+7==0 || i+7==8 || i+7==16 || i+7==24 || i+7==32 || i+7==40 ){
          continue ;
          }
          else if (i+14==0 || i+14==8 || i+14==16 || i+14==24 || i+14==32 || i+14==40 ){
          continue ;
          }
          else{plz=2;Serial.print("i2");}
        }
  }

 //end game action
  if (plz == 1){//p1 win
      while (true) {
      for(int i =0;  i < 16; i++){
      leds[i] =CRGB::Black ;
      FastLED.show();
      delay(50);
      leds[i] = CRGB::Yellow;
      FastLED.show();
      delay(10);
  }
     }
    }else if (plz == 2){//p2 win
      while (true) {
        for(int i=0; i < 16; i++){
      leds[i] =CRGB::Black ;
      FastLED.show();
      delay(50);
      leds[i] = 0x153355;
      FastLED.show();
      delay(10);
        } 
      } 
     }
  //if drow
  C4_drow_check();
}