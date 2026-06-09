#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(A0, A1, 10, 11, 12, 13);

const byte ROWS = 4, COLS = 4;
char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {6,7,8,9};
byte colPins[COLS] = {2,3,4,5};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int RED_LED = A4;
const int GREEN_LED = A3;
const String SECRET_CODE = "1234";
const int TIME_LIMIT = 30;

String enteredCode = "";
unsigned long startTime;
bool gameOver = false;
int lastSecond = -1;

void setup() {
lcd.begin(16, 2);
pinMode(RED_LED, OUTPUT);
pinMode(GREEN_LED, OUTPUT);
digitalWrite(RED_LED, HIGH);
digitalWrite(GREEN_LED, LOW);
startTime = millis();
lcd.print("BOMB ACTIVATED!");
lcd.setCursor(0, 1);
lcd.print("Enter code: ");
}

void loop() {
if (gameOver) return;

int remaining = TIME_LIMIT - (millis() - startTime) / 1000;

if (remaining != lastSecond) {
lastSecond = remaining;
lcd.setCursor(0, 0);
lcd.print("Time: ");
lcd.print(remaining);
lcd.print("s ");
}

if (remaining <= 0) {
explode();
return;
}

char key = keypad.getKey();
if (key) {
if (key == '#') {
checkCode();
} else if (key == '*') {
enteredCode = "";
lcd.setCursor(0, 1);
lcd.print("Enter code: ");
} else if (enteredCode.length() < 4) {
enteredCode += key;
lcd.setCursor(0, 1);
lcd.print(">" + enteredCode + " ");
}
}
}

void checkCode() {
if (enteredCode == SECRET_CODE) {
defused();
} else {
enteredCode = "";
digitalWrite(RED_LED, LOW);
delay(300);
digitalWrite(RED_LED, HIGH);
lcd.setCursor(0, 1);
lcd.print("WRONG! Retry ");
delay(800);
lcd.setCursor(0, 1);
lcd.print("Enter code: ");
}
}

void explode() {
gameOver = true;
digitalWrite(RED_LED, HIGH);
digitalWrite(GREEN_LED, LOW);
lcd.clear();
lcd.print("** BOOM! **");
lcd.setCursor(0, 1);
lcd.print("GAME OVER!");
}

void defused() {
gameOver = true;
digitalWrite(RED_LED, LOW);
digitalWrite(GREEN_LED, HIGH);
lcd.clear();
lcd.print("** DEFUSED! **");
lcd.setCursor(0, 1);
lcd.print("You win!");
}
