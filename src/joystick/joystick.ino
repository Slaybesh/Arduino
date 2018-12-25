
const int pin_x = 0;
const int pin_y = 1;
const int pin_press = 2;



void setup() {
    Serial.begin(9600);
}

void loop() {
    // exit(0);

    int x = analogRead(pin_x);
    int y = analogRead(pin_y);
    int press = analogRead(pin_press);

    Serial.print("x: ");
    Serial.print(x);
    Serial.print("\ty: ");
    Serial.print(y);
    Serial.print("\tpress: ");
    Serial.print(press);
    Serial.print("\n");

    delay(10);
}