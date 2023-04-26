 #include <Servo.h>
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Servo doorLock; // create servo object to control the door lock
int lockPosition = 0; // initialize the lock position to unlocked
void setup() {
 doorLock.attach(10); // attach the servo to digital pin 10
 doorLock.write(lockPosition); // move the servo to the unlocked position
 Serial.begin(9600); // start the serial monitor
}
void loop() {
 char key = keypad.getKey(); // get the key pressed on the keypad
if (key == 'A') { // if the A key is pressed, lock the door
 lockPosition = 90; // set the lock position to locked
 doorLock.write(lockPosition); // move the servo to the locked position
 Serial.println("Door locked");
 }
 if (key == 'B') { // if the B key is pressed, unlock the door
 lockPosition = 0; // set the lock position to unlocked
 doorLock.write(lockPosition); // move the servo to the unlocked position
 Serial.println("Door unlocked");
 }
}
