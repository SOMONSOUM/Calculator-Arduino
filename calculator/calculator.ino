/*
 * កូដនេះ ប្រើសម្រាប់បង្កើតម៉ាស៊ីនគិតលេខធម្មតាមួយ ដើម្បីចូលរួមកម្មវិធីសាលាមេតូឌីស្ទកម្ពុជា
 * បើមានបញ្ហាក្នុងការយកកូដនេះទៅប្រើប្រាស់ អ្នកត្រូវបន្ថែម Library
*/

#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4; // 4 ជួរដេក
const byte COLS = 4; // 4 ជួរឈរ

// កំណត់ Keypad
char keys[ROWS][COLS] = {

  {'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}

};

byte rowPins[ROWS] = { 0, 1, 2, 3 };// ភ្ជាប់ keypad ROW0, ROW1, ROW2 and ROW3 ទៅជើងនៃ Arduino.
byte colPins[COLS] = { 4, 5, 6, 7 }; // ភ្ជាប់ keypad COL0, COL1 and COL2 ទៅជើងនៃ Arduino.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //  បង្កើត Keypad

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; //ជើងដែលត្រូវបានប្រើលើ LCD ដើម្បីភ្ជាប់ទៅ Arduino
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 long Num1,Num2,Number;
 char key,action;
 boolean result = false;
 
void setup() {
  lcd.begin(16, 2); //យើងកំពុងប្រើ LCD 16*2
  lcd.print("Calculator"); //បង្ហាញពាក្យថា Calculator
  lcd.setCursor(0, 1);   // កំណត់ឲ្យ cursor បង្ហាញនូវជួរឈរទី0, បន្ទាត់ទី1
  lcd.print("MSC Science Fair"); //បង្ហាញអក្សរលើ LCD

  delay(2000); //រងចាំដើម្បីបង្ហាញពត៌មាន
  lcd.clear(); //បន្ទាប់មកលុបវាចេញ
}

void loop() {
  
  key = kpd.getKey(); //ផ្ទុកតម្លៃនៃការចុចទៅក្នុងអក្សរមួយ
  
  if (key!=NO_KEY)
  DetectButtons();
  
  if (result==true)
  CalculateResult();
  
  DisplayResult();   
}

void DetectButtons()
{ 
    lcd.clear(); //បន្ទាប់មកលុបវាចេញ
    if (key=='*') //បើ Cancel ប៊ូតុងត្រូវបានចុច
    {Serial.println ("Button Cancel"); Number=Num1=Num2=0; result=false;}
    
     if (key == '1') //បើសិនប៊ូតុងលេខ 1 ត្រូវបានចុច
    {
      Serial.println ("Button 1"); 
      if (Number==0)
      Number=1;
    else
      Number = (Number*10) + 1; //ចុចពីរដង
    }
    
     if (key == '4') //If Button 4 is pressed
    {Serial.println ("Button 4"); 
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4; //ចុចពីរដង
    }
    
     if (key == '7') //If Button 7 is pressed
    {Serial.println ("Button 7");
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7; //ចុចពីរដង
    } 
  

    if (key == '0')
    {Serial.println ("Button 0"); //Button 0 is Pressed
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //ចុចពីរដង
    }
    
     if (key == '2') //Button 2 is Pressed
    {Serial.println ("Button 2"); 
     if (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; //Pressed twice
    }
    
     if (key == '5')
    {Serial.println ("Button 5"); 
     if (Number==0)
    Number=5;
    else
    Number = (Number*10) + 5; //Pressed twice
    }
    
     if (key == '8')
    {Serial.println ("Button 8"); 
     if (Number==0)
    Number=8;
    else
    Number = (Number*10) + 8; //Pressed twice
    }   
  

    if (key == '#')
    {Serial.println ("Button Equal"); 
    Num2=Number;
    result = true;
    }
    
     if (key == '3')
    {Serial.println ("Button 3"); 
     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3; //Pressed twice
    }
    
     if (key == '6')
    {Serial.println ("Button 6"); 
    if (Number==0)
    Number=6;
    else
    Number = (Number*10) + 6; //Pressed twice
    }
    
     if (key == '9')
    {Serial.println ("Button 9");
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; //Pressed twice
    }  

      if (key == 'A' || key == 'B' || key == 'C' || key == 'D') //Detecting Buttons on Column 4
  {
    Num1 = Number;    
    Number =0;
    if (key == 'A')
    {Serial.println ("Addition"); action = '+';}
     if (key == 'B')
    {Serial.println ("Subtraction"); action = '-'; }
     if (key == 'C')
    {Serial.println ("Multiplication"); action = '*';}
     if (key == 'D')
    {Serial.println ("Devesion"); action = '/';}  

    delay(100);
  }
  
}

void CalculateResult()
{
  if (action=='+')
    Number = Num1+Num2;

  if (action=='-')
    Number = Num1-Num2;

  if (action=='*')
    Number = Num1*Num2;

  if (action=='/')
    Number = Num1/Num2; 
}

void DisplayResult()
{
  lcd.setCursor(0, 0);   // set the cursor to column 0, line 1
  lcd.print(Num1); lcd.print(action); lcd.print(Num2); 
  
  if (result==true)
  {lcd.print(" ="); lcd.print(Number);} //Display the result
  
  lcd.setCursor(0, 1); // set the cursor to column 0, line 1
  lcd.print(Number); //Display the result
}
