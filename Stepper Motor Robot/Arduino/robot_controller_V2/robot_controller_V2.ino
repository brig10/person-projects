#include <IRremote.h>
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int sAddress = 0x69;
const int UP = 0x00;
const int DOWN = 0x01;
const int LEFT = 0x02;
const int RIGHT = 0x03;




void setup() {
  // put your setup code here, to run once:
  IrSender.begin(11, DISABLE_LED_FEEDBACK);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(8,1);
  lcd.print("ROBOT");
  lcd.setCursor(6,2);
  lcd.print("Press 'A'");
  lcd.setCursor(0,0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();
  if (customKey == 'A'){
    Menu();
  }
}

void FREE_MOVE(){
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("FREE MOVE");
  lcd.setCursor(3, 2);
  lcd.print("'D' to SCALE");
  while (1==1){
    char customKey = customKeypad.getKey();
    if (customKey == '2'){
      IrSender.sendNEC(sAddress, UP, 0);
    }

    if (customKey == '4'){
      IrSender.sendNEC(sAddress, LEFT, 0);
    }

    if (customKey == '6'){
      IrSender.sendNEC(sAddress, RIGHT, 0);
    }

    if (customKey == '8'){
      IrSender.sendNEC(sAddress, DOWN, 0);
    }

    if (customKey == '*'){
      Menu();
    }
    customKey = '?';
  }
}

void Menu(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("1: FREE_MOVE");
  lcd.setCursor(0,1);
  lcd.print("2: BOX");
  lcd.setCursor(0,2);
  lcd.print("3: MOVE_TO");
  lcd.setCursor(0,3);
  lcd.print("4: HOME");
  while (1==1){
    char customKey = customKeypad.getKey();
    if (customKey == '1'){
      FREE_MOVE();
    }

    if (customKey == '2'){
      lcd.setCursor(7,0);
      lcd.print("BOX...");
    }
  }
}
