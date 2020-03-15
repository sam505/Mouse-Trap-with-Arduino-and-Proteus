#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int IR = 3;
int count = 0;
int countOne = 1;
int countTwo = 2;
int countThree = 3;
int countFour = 4;


void setup() {
   pinMode (IR, INPUT);
   pinMode (4,OUTPUT);
   pinMode (5,OUTPUT);
   pinMode (6,OUTPUT);
   pinMode (7,OUTPUT);

   // set up the LCD's number of columns and rows
  lcd.begin(16, 4);
  // Print a message to the LCD
  lcd.setCursor(0,0);
  lcd.print("MouseTrapProject");
  lcd.setCursor(0,2);
  lcd.print("Count: ");

}

void loop() {
  
  int state = digitalRead (IR);

  if (state == HIGH){
    lcd.setCursor (0, 1);
    lcd.print ("Object Detected!");
    count = count + 1;
    lcd.setCursor (8, 2);
    if (count == 0){
      lcd.setCursor (8, 2);
      lcd.print(0);
      }
    lcd.print (count);
    

    if (countOne == 1 or (count - countOne) % 4 == 0){
      digitalWrite (4,HIGH);
      digitalWrite (5,LOW);
      digitalWrite (6,LOW);
      digitalWrite (7,LOW);
      }
    if (count == 2 or (count - countTwo) % 4 == 0){
      
      digitalWrite (4,LOW);
      digitalWrite (5,HIGH);
      digitalWrite (6,LOW);
      digitalWrite (7,LOW);
      }
    if (count == 3 or (count - countThree) % 4 == 0){
      digitalWrite (4,LOW);
      digitalWrite (5,LOW);
      digitalWrite (6,HIGH);
      digitalWrite (7,LOW);
          }
    if (count == 4 or (count - countFour) % 4 == 0){
      digitalWrite (4,LOW);
      digitalWrite (5,LOW);
      digitalWrite (6,LOW);
      digitalWrite (7,HIGH); 
      }
    
      
    delay (1000);
    
   }

    else{
      lcd.setCursor (0, 1);
      lcd.print ("NoObjectDetected");
    
    
    }


}
