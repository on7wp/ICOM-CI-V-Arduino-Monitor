/********************************************************

Description: CI-V monitor by ON7WP

********************************************************/

 

#include <LiquidCrystal.h>
#include <SoftwareSerial.h> // for comms to IC7000
#define BAUD_RATE 9600     // CI-V speed
#define TRX_address (0x34)  // HEX $34 = Icom IC-R7100
//#define TRX_address ((byte)00)  // $00: Icom universal address (works for all radios).

// serial connection CI-V
// RX = Icom radio to Arduino  : to pin 2 via resistor 4k7
// TX = Arduino to Icom radio  : to pin 3 via diode 1N4148, with pull up 10k to Vcc (5V) on tip of 3.5 mm connector

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // select the pins used on the LCD panel (using LCD keypad shield)
SoftwareSerial mySerial = SoftwareSerial(2, 3); // (RX, TX)

int readCounter; // counts the number of bytes received from the radio
int byte3;
int byte4;
int byte5;
int byte6;
int byte7;
int byte8;
int byte9;
int byte10;
int byte11;
int byte12;

void setup(){

lcd.begin(16, 2); // start the library

  pinMode(13, OUTPUT); digitalWrite(13, LOW); // force LED (pin 13) to turn off.
  pinMode(2, INPUT);  // CI-V serial communication from radio
  pinMode(3, OUTPUT); // CI-V serial communication to radio
  
  mySerial.begin(BAUD_RATE);
  mySerial.listen();  
  while (mySerial.available()) mySerial.read(); 

  lcd.setCursor(0, 0);             // set the LCD cursor position
  lcd.print("waiting for CI-V");
  lcd.setCursor(0, 1);             // set the LCD cursor position
  lcd.print(" ON7WP Analyser");
  delay(1000);                     // display startup screen
  lcd.clear();                     // clear the LCD 
}
void loop(){

                                   // state to be decoded:
                                   // $1C  $00 $01 is Transmit On 
                                   // $1C  $00 $00 is Transmit Off   

                                   // now read info from radio
  int nbChar = mySerial.available();  
  if (nbChar > 0) {
     lcd.clear(); // clear the LCD
     lcd.setCursor(8,1);
     lcd.print("bytes:");
     lcd.setCursor(14,1); // set the LCD cursor position
     lcd.print(nbChar);
      for (int readCounter = 0; readCounter < nbChar ; readCounter++) {
      int byteread = mySerial.read();

// first two bytest are start bytes, not interesting
// next two bytes are "to" and "from" ID's so also not interesting
// so we start with the fourth byte value into an integer 000-255

      if (readCounter == 3){
          lcd.setCursor(0,0); // set the LCD cursor position
          byte3=(byteread);
          lcd.print(byte3);

           lcd.setCursor(0,1); // set the LCD cursor position
           lcd.print(byte3);                           // print again for debug reasons: THIS IS NOT WORKING !!!!
           if (byte3==001){digitalWrite(13, LOW);}     //This also not working
           if (byte3==000){digitalWrite(13, HIGH);} 

          
          }
      if (readCounter == 4){
          lcd.setCursor(0,0); // set the LCD cursor position
          lcd.print(byteread);
          byte4=(byteread);
          }
      if (readCounter == 5){
          lcd.setCursor(3,0); // set the LCD cursor position
          lcd.print(byteread);
          byte5=(byteread);
          }
      if (readCounter == 6){
          lcd.setCursor(6,0); // set the LCD cursor position
          lcd.print(byteread);
          byte6=(byteread);
          }
      if (readCounter == 7){
          lcd.setCursor(9,0); // set the LCD cursor position
          lcd.print(byteread);
          byte7=(byteread);
          }
      if (readCounter == 8){
          lcd.setCursor(12,0); // set the LCD cursor position
          lcd.print(byteread);
          byte8=(byteread);
          }
      if (readCounter == 9){
          lcd.setCursor(0,1); // set the LCD cursor position
          lcd.print(byteread);
          byte9=(byteread);
          }
     if (readCounter == 10){
          lcd.setCursor(3,1); // set the LCD cursor position
          lcd.print(byteread);
          byte10=(byteread);
         }
      if (readCounter == 11){
          lcd.setCursor(6,1); // set the LCD cursor position
          lcd.print(byteread);
          byte11=(byteread);
          }
      if (readCounter == 12){
          lcd.setCursor(9,1); // set the LCD cursor position
          lcd.print(byteread);
          byte12=(byteread);
          }
      }
    }
  } 
