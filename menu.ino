#include <FastLED.h>

#define num_led 64
#define led_pin 6

//Input Button 
const int numOfInputs = 5;
const int inputPins[numOfInputs] = {12,11,10,9,8};
// up 12 , down 11 , right 10 , left 9 ,  ok 8 
int menu_inputState[numOfInputs];
int menu_lastInputState[numOfInputs] = {LOW,LOW,LOW,LOW,LOW};
bool menu_inputFlags[numOfInputs] = {LOW,LOW,LOW,LOW,LOW};
long menu_lastDebounceTime[numOfInputs] = {0,0,0,0,0};
int menu_inputCounters[numOfInputs];
long debounceDelay = 5;

//led 
CRGB leds[num_led];

//virtual board
int tic_board[9] = {0,0,0,0,0,0,0,0,0};

//virtual board for connect 4 game
int connect4_board[48];

// for menu
int menu=1;
int menu_waite_to_press = 0;

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
    pinMode(inputPins[i], INPUT_PULLUP);
  }

  FastLED.addLeds < WS2812B, led_pin > (leds, num_led);
  FastLED.setBrightness(10);
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

// deal with input signal
void menu_Input_handel() {

  ///setmenu_InputFlags
  for (int i = 0; i < numOfInputs; i++) {
    int reading = digitalRead(inputPins[i]);
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
           // tic_game();
             }
           if (menu==2){
            fill_solid(leds, num_led, CRGB::Black);
           // connect4_game();
             }

  }

}
