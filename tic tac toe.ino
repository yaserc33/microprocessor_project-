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

//virtual board
int tic_board[9] = {0,0,0,0,0,0,0,0,0};

// plyers turn flags 
int p = 1;

//  current tic_location
int tic_loc = 4;

//flag to force arduino to wite for input
int waite_to_press = 0;

void setup() {

  for (int i = 0; i < numOfInputs; i++) {
    pinMode(inputPins[i], INPUT_PULLUP);
  }

  FastLED.addLeds < WS2812B, led_pin > (leds, num_led);
  FastLED.setBrightness(10);
}

void loop() {
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