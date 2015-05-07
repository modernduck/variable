#include <FastSPI_LED2.h>
#include <LiquidCrystal.h>
#define SPEAKER 10
#define SW 2
#define BRIGHTNESS 255
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 	// initialize LCD library
CRGB leds[1];
//1 ). Declare variable here!
float abc;
boolean kupo;
int button, knob, light, rtemp;
//float temp;
void setup() {
  pinMode(SW, INPUT);
  pinMode(SPEAKER, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  //uncomment if going to use LED
  /*
    LEDS.setBrightness(BRIGHTNESS);    
    //update PIN at A! 
    LEDS.addLeds<WS2811, A1, RGB>(leds, 1);
    LEDS.show();
  */
  //2.) Setup here
  //------- START SETUP -----------------------
   abc = 0;
   kupo = true;
  
  //------- END OF SETUP -----------------------
}

void loop() {
  //------- START CODE-----------------------
  //uncomment to get stuff from input
  button = digitalRead(2);
  //knob = analogRead(A3);
  //light = analogRead(A4);
  //rtemp = analogRead(A5);
  //uncomment to convert rtemp to temparature (temp);
  //temp = ((float(rtemp) * 0.25) - 25.51); 
  //3) Main Code
  

  if(button == false)
  {
    kupo = !kupo;
    delay(500);
  }
  digitalWrite(11, kupo);
  if(kupo)
  {
      abc = abc + 0.01;
    lcd.print(abc);
    delay(10);
    lcd.clear();
  }else
  {
     lcd.print(abc); 
     delay(100);
    lcd.clear();
  }
  
  
  //SNIPPET
  //tone(SPEAKER, 300);
  //noTone(SPEAKER);
  //use color led
  /*
    leds[0] = CRGB::Blue;
    LEDS.show();
  */
  
  
  //------- END OF MAIN CODE -----------------------
}
