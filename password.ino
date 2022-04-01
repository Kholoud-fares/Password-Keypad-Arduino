/*code explain how to get a 4 digit password from keypad and compare it with the default if it is right will print 
  on serial monitor "accessed" if not will print "wrong"

  component used
  1- Arduino UNO
  2- Keypad
*/
//kholoud shaker

#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8}; //connect to the column pinouts of the keypad
char pass[6];
byte count=0;
String password="1234";
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup(){
  Serial.begin(9600);
}
  
void loop(){
//  char key = keypad.getKey();
  
 // if (key){
    Serial.println("enter the password");
    while(count<=3){
     int key = keypad.getKey();
     if (key){
       pass[count] = key;
       count++;
        }}
      Serial.println(pass);
     if (password == pass){
       Serial.println("accessed");
       
       }
     else{
      Serial.println("wrong password");
     }
       
  
}
