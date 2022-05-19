#include <FastLED.h>

#define num_led 64
#define led_pin 6

//Input Button 
const int numOfInputs = 5;
const int inputpins[numOfInputs] = {12,11,10,9,8};
// up 12 , down 11 , right 10 , left 9 ,  ok 8 
int inputState[numOfInputs];
int lastInputState[numOfInputs] = {LOW,LOW,LOW,LOW,LOW};
bool inputFlags[numOfInputs] = {LOW,LOW,LOW,LOW,LOW};
long lastDebounceTime[numOfInputs] = {0,0,0,0,0};
long debounceDelay = 5;
int inputCounters[numOfInputs];

//led 
CRGB leds[num_led];

//virtual board
int tic_board[9] = {0,0,0,0,0,0,0,0,0};

//virtual board for connect 4 game
int connect4_board[48];

// for menu
int menu=1;
int menu_waite_to_press = 0;
int menu_inputState[numOfInputs];
int menu_lastInputState[numOfInputs] = {LOW,LOW,LOW,LOW,LOW};
bool menu_inputFlags[numOfInputs] = {LOW,LOW,LOW,LOW,LOW};
long menu_lastDebounceTime[numOfInputs] = {0,0,0,0,0};
int menu_inputCounters[numOfInputs];

// plyers turn flags 
int p = 1;

//  current tic_location
int tic_loc = 4;

//  current connect4_location
int connect4_loc = 4;

//flag to force arduino to wite for input
int waite_to_press = 0;

void setup() {

  for (int i = 0; i < numOfInputs; i++) {
    pinMode(inputpins[i], INPUT_PULLUP);
  }

  FastLED.addLeds < WS2812B, led_pin > (leds, num_led);
  FastLED.setBrightness(5);
}


void loop() {
menu_waite_to_press=0;
            
if(menu==1){
      fill_solid(leds, num_led, CRGB::Black);
      leds[25] = CRGB::White;
      leds[33] = CRGB::White;
      leds[32] = CRGB::White;
      leds[41] = CRGB::White;
    
      leds[20] = CRGB::Green;
      leds[22] = CRGB::Green;
      leds[27] = CRGB::Green;
      leds[28] = CRGB::Green;
      leds[29] = CRGB::Green;
      leds[30] = CRGB::Green;
      leds[31] = CRGB::Green;
      leds[36] = CRGB::Green;
      leds[38] = CRGB::Green;
      leds[43] = CRGB::Green;
      leds[44] = CRGB::Green;
      leds[45] = CRGB::Green;
      leds[46] = CRGB::Green;
      leds[47] = CRGB::Green;
      leds[52] = CRGB::Green;
      leds[54] = CRGB::Green;
      FastLED.show();
      delay(100);
      leds[20] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[29] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[31] = CRGB::Blue;
      leds[36] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[43] = CRGB::Blue;
      leds[44] = CRGB::Blue;
      leds[45] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[47] = CRGB::Blue;
      leds[52] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      FastLED.show();
      delay(100);
      
      leds[20] = CRGB::Green;
      leds[22] = CRGB::Green;
      leds[27] = CRGB::Green;
      leds[28] = CRGB::Green;
      leds[29] = CRGB::Green;
      leds[30] = CRGB::Green;
      leds[31] = CRGB::Green;
      leds[36] = CRGB::Green;
      leds[38] = CRGB::Green;
      leds[43] = CRGB::Green;
      leds[44] = CRGB::Green;
      leds[45] = CRGB::Green;
      leds[46] = CRGB::Green;
      leds[47] = CRGB::Green;
      leds[52] = CRGB::Green;
      leds[54] = CRGB::Green;
      FastLED.show();
      delay(100);
      leds[20] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[29] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[31] = CRGB::Blue;
      leds[36] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[43] = CRGB::Blue;
      leds[44] = CRGB::Blue;
      leds[45] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[47] = CRGB::Blue;
      leds[52] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      FastLED.show();
      delay(100);
      
      leds[20] = CRGB::Green;
      leds[22] = CRGB::Green;
      leds[27] = CRGB::Green;
      leds[28] = CRGB::Green;
      leds[29] = CRGB::Green;
      leds[30] = CRGB::Green;
      leds[31] = CRGB::Green;
      leds[36] = CRGB::Green;
      leds[38] = CRGB::Green;
      leds[43] = CRGB::Green;
      leds[44] = CRGB::Green;
      leds[45] = CRGB::Green;
      leds[46] = CRGB::Green;
      leds[47] = CRGB::Green;
      leds[52] = CRGB::Green;
      leds[54] = CRGB::Green;
      FastLED.show();
      delay(100);
      leds[20] = CRGB::Blue;
      leds[22] = CRGB::Blue;
      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[29] = CRGB::Blue;
      leds[30] = CRGB::Blue;
      leds[31] = CRGB::Blue;
      leds[36] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[43] = CRGB::Blue;
      leds[44] = CRGB::Blue;
      leds[45] = CRGB::Blue;
      leds[46] = CRGB::Blue;
      leds[47] = CRGB::Blue;
      leds[52] = CRGB::Blue;
      leds[54] = CRGB::Blue;
      FastLED.show();
      delay(100);
}else if(menu==2) {
      fill_solid(leds, num_led, CRGB::Black);

      leds[30] = CRGB::White;
      leds[38] = CRGB::White;
      leds[39] = CRGB::White;
      leds[46] = CRGB::White; 

      leds[24] = CRGB::White;
      leds[25] = CRGB::White;
      leds[26] = CRGB::White;
      leds[27] = CRGB::White;  
      leds[28] = CRGB::White;
      FastLED.show();
      delay(100);
      leds[58] = CRGB::Yellow;
      FastLED.show();
      delay(200);
      leds[59] =0x153355;
      FastLED.show();
      delay(200);
      leds[51] = CRGB::Yellow;
      FastLED.show();
      delay(200);
      leds[50] =0x153355;
      FastLED.show();
      delay(200);
      leds[57] = CRGB::Yellow;
      FastLED.show();
      delay(200);
      leds[43] =0x153355;
      FastLED.show();
      delay(200);
   }
while (menu_waite_to_press == 0) {
      menu_Input_handel();
    }
}


//--------------------------for tic tac toe game------------------//
void tic_game(){
 
 while(true){
  leds[2] = 0Xd1f5c9;
  leds[5] = 0Xd1f5c9;
  leds[13] = 0Xd1f5c9;
  leds[10] = 0Xd1f5c9;
  leds[16] = 0Xd1f5c9;
  leds[17] = 0Xd1f5c9;
  leds[18] = 0Xd1f5c9;
  leds[19] = 0Xd1f5c9;
  leds[20] = 0Xd1f5c9;
  leds[21] = 0Xd1f5c9;
  leds[22] = 0Xd1f5c9;
  leds[23] = 0Xd1f5c9;
  leds[29] = 0Xd1f5c9;
  leds[34] = 0Xd1f5c9;
  leds[26] = 0Xd1f5c9;
  leds[37] = 0Xd1f5c9;
  leds[47] = 0Xd1f5c9;
  leds[46] = 0Xd1f5c9;
  leds[45] = 0Xd1f5c9;
  leds[44] = 0Xd1f5c9;
  leds[43] = 0Xd1f5c9;
  leds[42] = 0Xd1f5c9;
  leds[41] = 0Xd1f5c9;
  leds[40] = 0Xd1f5c9;
  leds[50] = 0Xd1f5c9;
  leds[53] = 0Xd1f5c9;
  leds[61] = 0Xd1f5c9;
  leds[58] = 0Xd1f5c9;
  FastLED.show();
  //p1 turn
  while (p == 1) {
    tic_check_win();
    tic_live_blink(tic_loc, 1);
    waite_to_press = 0;
    while (waite_to_press == 0) {
      tic_Input_handel();
      for (int i = 0; i < tic_board; i++) {
        if (tic_board[i] == 1) {
          tic_hard(i, 1);
        }
        if (tic_board[i] == 2) {
          tic_hard(i, 2);
        }

      }
      FastLED.show();

    } 
     }
  //p2 turn
  while (p == 2) {
    tic_check_win();
    tic_live_blink(tic_loc, 2);
    waite_to_press = 0;
    while (waite_to_press == 0) {
      tic_Input_handel();
      for (int i = 0; i < tic_board; i++) {
        if (tic_board[i] == 1) {
          tic_hard(i, 1);
        }
        if (tic_board[i] == 2) {
          tic_hard(i, 2);
        }

      }
      FastLED.show();

    }
  }
 }  
}
 
void tic_hard(int x, int p) {
  if (p == 1) {
    if (x == 0) {
      leds[0] = CRGB::Blue;
      leds[1] = CRGB::Blue;
      leds[8] = CRGB::Blue;
      leds[9] = CRGB::Blue;
      FastLED.show();
    } else if (x == 1) {
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[12] = CRGB::Blue;
      leds[11] = CRGB::Blue;
      FastLED.show();
    } else if (x == 2) {
      leds[6] = CRGB::Blue;
      leds[7] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[15] = CRGB::Blue;
      FastLED.show();
    } else if (x == 3) {
      leds[24] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      leds[32] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      FastLED.show();
    } else if (x == 4) {
      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[35] = CRGB::Blue;
      leds[36] = CRGB::Blue;
      FastLED.show();
    } else if (x == 5) {
      leds[30] = CRGB::Blue;
      leds[31] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[39] = CRGB::Blue;
      FastLED.show();
    } else if (x == 6) {
      leds[48] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[56] = CRGB::Blue;
      leds[57] = CRGB::Blue;
      FastLED.show();
    } else if (x == 7) {
      leds[51] = CRGB::Blue;
      leds[52] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      FastLED.show();
    } else if (x == 8) {
      leds[54] = CRGB::Blue;
      leds[55] = CRGB::Blue;
      leds[62] = CRGB::Blue;
      leds[63] = CRGB::Blue;
      FastLED.show();
    }
  } else if (p == 2) {
    if (x == 0) {
      leds[0] = CRGB::Green;
      leds[1] = CRGB::Green;
      leds[8] = CRGB::Green;
      leds[9] = CRGB::Green;
      FastLED.show();
    } else if (x == 1) {
      leds[3] = CRGB::Green;
      leds[4] = CRGB::Green;
      leds[12] = CRGB::Green;
      leds[11] = CRGB::Green;
      FastLED.show();
    } else if (x == 2) {
      leds[6] = CRGB::Green;
      leds[7] = CRGB::Green;
      leds[14] = CRGB::Green;
      leds[15] = CRGB::Green;
      FastLED.show();
    } else if (x == 3) {
      leds[24] = CRGB::Green;
      leds[25] = CRGB::Green;
      leds[32] = CRGB::Green;
      leds[33] = CRGB::Green;
      FastLED.show();
    } else if (x == 4) {
      leds[27] = CRGB::Green;
      leds[28] = CRGB::Green;
      leds[35] = CRGB::Green;
      leds[36] = CRGB::Green;
      FastLED.show();
    } else if (x == 5) {
      leds[30] = CRGB::Green;
      leds[31] = CRGB::Green;
      leds[38] = CRGB::Green;
      leds[39] = CRGB::Green;
      FastLED.show();
    } else if (x == 6) {
      leds[48] = CRGB::Green;
      leds[49] = CRGB::Green;
      leds[56] = CRGB::Green;
      leds[57] = CRGB::Green;
      FastLED.show();
    } else if (x == 7) {
      leds[51] = CRGB::Green;
      leds[52] = CRGB::Green;
      leds[60] = CRGB::Green;
      leds[59] = CRGB::Green;
      FastLED.show();
    } else if (x == 8) {
      leds[54] = CRGB::Green;
      leds[55] = CRGB::Green;
      leds[62] = CRGB::Green;
      leds[63] = CRGB::Green;
      FastLED.show();
    }
  }
}

void tic_live_blink(int x, int p) {
  if (p == 1) {
    if (x == 0) {
      leds[0] = CRGB::Blue;
      leds[1] = CRGB::Blue;
      leds[8] = CRGB::Blue;
      leds[9] = CRGB::Blue;
      FastLED.show();
      delay(200);
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[8] = CRGB::Black;
      leds[9] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 1) {
      leds[3] = CRGB::Blue;
      leds[4] = CRGB::Blue;
      leds[12] = CRGB::Blue;
      leds[11] = CRGB::Blue;
      FastLED.show();
      delay(200);
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      leds[11] = CRGB::Black;
      leds[12] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 2) {
      leds[6] = CRGB::Blue;
      leds[7] = CRGB::Blue;
      leds[14] = CRGB::Blue;
      leds[15] = CRGB::Blue;
      FastLED.show();
      delay(200);
      leds[6] = CRGB::Black;
      leds[7] = CRGB::Black;
      leds[14] = CRGB::Black;
      leds[15] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 3) {
      leds[24] = CRGB::Blue;
      leds[25] = CRGB::Blue;
      leds[32] = CRGB::Blue;
      leds[33] = CRGB::Blue;
      FastLED.show();
      delay(200);
      leds[24] = CRGB::Black;
      leds[25] = CRGB::Black;
      leds[32] = CRGB::Black;
      leds[33] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 4) {
      leds[27] = CRGB::Blue;
      leds[28] = CRGB::Blue;
      leds[35] = CRGB::Blue;
      leds[36] = CRGB::Blue;
      FastLED.show();
      delay(200);
      leds[27] = CRGB::Black;
      leds[28] = CRGB::Black;
      leds[35] = CRGB::Black;
      leds[36] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 5) {
      leds[30] = CRGB::Blue;
      leds[31] = CRGB::Blue;
      leds[38] = CRGB::Blue;
      leds[39] = CRGB::Blue;
      FastLED.show();
      delay(200);
      leds[30] = CRGB::Black;
      leds[31] = CRGB::Black;
      leds[38] = CRGB::Black;
      leds[39] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 6) {
      leds[48] = CRGB::Blue;
      leds[49] = CRGB::Blue;
      leds[56] = CRGB::Blue;
      leds[57] = CRGB::Blue;
      FastLED.show();
      delay(200);
      leds[48] = CRGB::Black;
      leds[49] = CRGB::Black;
      leds[56] = CRGB::Black;
      leds[57] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 7) {
      leds[51] = CRGB::Blue;
      leds[52] = CRGB::Blue;
      leds[60] = CRGB::Blue;
      leds[59] = CRGB::Blue;
      FastLED.show();
      delay(200);
      leds[51] = CRGB::Black;
      leds[52] = CRGB::Black;
      leds[60] = CRGB::Black;
      leds[59] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 8) {
      leds[54] = CRGB::Blue;
      leds[55] = CRGB::Blue;
      leds[62] = CRGB::Blue;
      leds[63] = CRGB::Blue;
      FastLED.show();
      delay(200);
      leds[54] = CRGB::Black;
      leds[55] = CRGB::Black;
      leds[62] = CRGB::Black;
      leds[63] = CRGB::Black;
      FastLED.show();
      delay(200);
    }
  }
  if (p == 2) {
    if (x == 0) {
      leds[0] = CRGB::Green;
      leds[1] = CRGB::Green;
      leds[8] = CRGB::Green;
      leds[9] = CRGB::Green;
      FastLED.show();
      delay(200);
      leds[0] = CRGB::Black;
      leds[1] = CRGB::Black;
      leds[8] = CRGB::Black;
      leds[9] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 1) {
      leds[3] = CRGB::Green;
      leds[4] = CRGB::Green;
      leds[12] = CRGB::Green;
      leds[11] = CRGB::Green;
      FastLED.show();
      delay(200);
      leds[3] = CRGB::Black;
      leds[4] = CRGB::Black;
      leds[11] = CRGB::Black;
      leds[12] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 2) {
      leds[6] = CRGB::Green;
      leds[7] = CRGB::Green;
      leds[14] = CRGB::Green;
      leds[15] = CRGB::Green;
      FastLED.show();
      delay(200);
      leds[6] = CRGB::Black;
      leds[7] = CRGB::Black;
      leds[14] = CRGB::Black;
      leds[15] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 3) {
      leds[24] = CRGB::Green;
      leds[25] = CRGB::Green;
      leds[32] = CRGB::Green;
      leds[33] = CRGB::Green;
      FastLED.show();
      delay(200);
      leds[24] = CRGB::Black;
      leds[25] = CRGB::Black;
      leds[32] = CRGB::Black;
      leds[33] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 4) {
      leds[27] = CRGB::Green;
      leds[28] = CRGB::Green;
      leds[35] = CRGB::Green;
      leds[36] = CRGB::Green;
      FastLED.show();
      delay(200);
      leds[27] = CRGB::Black;
      leds[28] = CRGB::Black;
      leds[35] = CRGB::Black;
      leds[36] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 5) {
      leds[30] = CRGB::Green;
      leds[31] = CRGB::Green;
      leds[38] = CRGB::Green;
      leds[39] = CRGB::Green;
      FastLED.show();
      delay(200);
      leds[30] = CRGB::Black;
      leds[31] = CRGB::Black;
      leds[38] = CRGB::Black;
      leds[39] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 6) {
      leds[48] = CRGB::Green;
      leds[49] = CRGB::Green;
      leds[56] = CRGB::Green;
      leds[57] = CRGB::Green;
      FastLED.show();
      delay(200);
      leds[48] = CRGB::Black;
      leds[49] = CRGB::Black;
      leds[56] = CRGB::Black;
      leds[57] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 7) {
      leds[51] = CRGB::Green;
      leds[52] = CRGB::Green;
      leds[60] = CRGB::Green;
      leds[59] = CRGB::Green;
      FastLED.show();
      delay(200);
      leds[51] = CRGB::Black;
      leds[52] = CRGB::Black;
      leds[60] = CRGB::Black;
      leds[59] = CRGB::Black;
      FastLED.show();
      delay(200);
    } else if (x == 8) {
      leds[54] = CRGB::Green;
      leds[55] = CRGB::Green;
      leds[62] = CRGB::Green;
      leds[63] = CRGB::Green;
      FastLED.show();
      delay(200);
      leds[54] = CRGB::Black;
      leds[55] = CRGB::Black;
      leds[62] = CRGB::Black;
      leds[63] = CRGB::Black;
      FastLED.show();
      delay(200);
    }

  }
}

// deal with input signal
void tic_Input_handel() {

  ///setInputFlags
  for (int i = 0; i < numOfInputs; i++) {
    int reading = digitalRead(inputpins[i]);
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
      tic_inputAction(i);
      inputFlags[i] = LOW;
      inputCounters[i]++;
    }
  }
}

//action when button pressed
void tic_inputAction(int input) {

  // up
  if (input == 0 && inputCounters[0] != 0) {

    if (tic_loc == 0 || tic_loc == 1 || tic_loc == 2) {
      tic_loc = tic_loc + 6;
      waite_to_press = 1;
    } else {
      tic_loc = tic_loc - 3;
      waite_to_press = 1;
    }
  }
  //down
  if (input == 1 && inputCounters[1] != 0) {

    if (tic_loc == 6 || tic_loc == 7 || tic_loc == 8) {
      tic_loc = tic_loc - 6;

    } else {
      tic_loc = tic_loc + 3;
      waite_to_press = 1;

    }
  }
  //right
  if (input == 2 && inputCounters[2] != 0) {

    if (tic_loc == 2 || tic_loc == 5 || tic_loc == 8) {
      tic_loc = tic_loc - 2;
      waite_to_press = 1;
    } else {
      tic_loc = tic_loc + 1;
      waite_to_press = 1;
    }
  }
  //left
  if (input == 3 && inputCounters[3] != 0) {

    if (tic_loc == 0 || tic_loc == 3 || tic_loc == 6) {
      tic_loc = tic_loc + 2;
      waite_to_press = 1;
    } else {
      tic_loc = tic_loc - 1;
      waite_to_press = 1;
    }
  }
  //ok  
  if (input == 4 && inputCounters[4] != 0) {
    tic_link_virtual_board();
    waite_to_press = 1;
  }

}

// link matrix led with tic_board
void tic_link_virtual_board() {
  if (p == 1) {
    tic_board[tic_loc] = 1;
    tic_hard(tic_loc, 1);
    p = 2;
    tic_loc = 4;
  } else if (p == 2) {
    tic_board[tic_loc] = 2;
    tic_hard(tic_loc, 2);
    p = 1;
    tic_loc = 4;
  }
}

void tic_check_win() {

  //for player 1 
  if (tic_board[0] == 1 && tic_board[1] == 1 && tic_board[2] == 1) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Blue);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[3] == 1 && tic_board[4] == 1 && tic_board[5] == 1) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Blue);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[6] == 1 && tic_board[7] == 1 && tic_board[8] == 1) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Blue);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[0] == 1 && tic_board[4] == 1 && tic_board[8] == 1) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Blue);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[2] == 1 && tic_board[4] == 1 && tic_board[6] == 1) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Blue);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[2] == 1 && tic_board[5] == 1 && tic_board[8] == 1) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Blue);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[1] == 1 && tic_board[4] == 1 && tic_board[7] == 1) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Blue);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[0] == 1 && tic_board[3] == 1 && tic_board[6] == 1) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Blue);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  }

  //for player 2
  if (tic_board[0] == 2 && tic_board[1] == 2 && tic_board[2] == 2) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Green);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[3] == 2 && tic_board[4] == 2 && tic_board[5] == 2) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Green);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[6] == 2 && tic_board[7] == 2 && tic_board[8] == 2) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Green);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[0] == 2 && tic_board[4] == 2 && tic_board[8] == 2) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Green);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[2] == 2 && tic_board[4] == 2 && tic_board[6] == 2) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Green);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[2] == 2 && tic_board[5] == 2 && tic_board[8] == 2) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Green);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[1] == 2 && tic_board[4] == 2 && tic_board[7] == 2) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Green);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }
  } else if (tic_board[0] == 2 && tic_board[3] == 2 && tic_board[6] == 2) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Green);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Black);
      FastLED.show();
      delay(200);
    }

  }
  //check for drew
  if (tic_board[0] != 0 && tic_board[1] != 0 && tic_board[2] != 0 && tic_board[3] != 0 && tic_board[4] != 0 && tic_board[5] != 0 && tic_board[6] != 0 && tic_board[7] != 0 && tic_board[8] != 0) {
    while (true) {
      fill_solid(leds, num_led, CRGB::Blue);
      FastLED.show();
      delay(200);
      fill_solid(leds, num_led, CRGB::Green);
      FastLED.show();
      delay(200);
    }
  }
} 



//--------------------------for connect 4 game------------------//
void connect4_game(){
 while(true){
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
  while (p == 1) {
    C4_check_win();
    C4_live_blink(connect4_loc,p);
    waite_to_press = 0;
    while (waite_to_press == 0) {
    C4_Input_handel();
   } C4_refresh_led();
  }
 //p2 turn
 while (p == 2) {
    C4_check_win();
    C4_live_blink(connect4_loc,p);
    waite_to_press = 0;
    while (waite_to_press == 0) {
    C4_Input_handel();
    }C4_refresh_led();
  }
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
    int reading = digitalRead(inputpins[i]);
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

  if (p == 1) {
    int last_row =40; 
    while(t==0){
      if ( connect4_board[last_row+connect4_loc] == 0 ){
        connect4_board[last_row + connect4_loc]=1;
        C4_hard(connect4_loc,last_row,p);
        p = 2; //  switch to second loop (player 2 turn)
        connect4_loc = 4;
        t = 1;
        }else {last_row = last_row - 8;} 
      }
  } else if (p == 2) {
    int  last_row=40;
    while(t==0){
      if (connect4_board[last_row+connect4_loc] == 0) {
        connect4_board[last_row+connect4_loc]=2;
        C4_hard(connect4_loc,last_row,p);
        p = 1; //  switch to first loop (player 1 turn)
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

//-----------------for menu----------/
// deal with input signal
// deal with input signal
void menu_Input_handel() {

  ///setmenu_InputFlags
  for (int i = 0; i < numOfInputs; i++) {
    int reading = digitalRead(inputpins[i]);
    if (reading != menu_lastInputState[i]) {
      menu_lastDebounceTime[i] = millis();
    }
    if ((millis() - menu_lastDebounceTime[i]) > debounceDelay) {
      if (reading != menu_inputState[i]) {
        menu_inputState[i] = reading;
        if (menu_inputState[i] == HIGH) {
          menu_inputFlags[i] = HIGH;
        }
      }
    }
    menu_lastInputState[i] = reading;
  }

  //resolvemenu_InputFlags
  for (int i = 0; i < numOfInputs; i++) {
    if (menu_inputFlags[i] == HIGH) {
      menu_inputAction(i);
      menu_inputFlags[i] = LOW;
      menu_inputCounters[i]++;
    }
  }
}
//action when button pressed
void menu_inputAction(int input) {

  //right
  if (input == 2 && menu_inputCounters[2] != 0) {

    if ( menu == 1) {
      menu = 2;
     
    } else {
        menu=1;
      }
    menu_waite_to_press = 1;
  }
  //left
  if (input == 3 && menu_inputCounters[3] != 0) {

    if (menu == 2 ) {
      menu =1;
      
    } else {
              menu=2; 
      }
    menu_waite_to_press = 1;
   
  }
  //ok  
  if (input == 4 && menu_inputCounters[4] != 0) {
           if (menu==1){
            fill_solid(leds, num_led, CRGB::Black);
            tic_game();
             }
           if (menu==2){
            fill_solid(leds, num_led, CRGB::Black);
            connect4_game();
           }

  }

}




