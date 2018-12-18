
const int pin_pot = 0;
const int pin_led = 3;

int brightness = 0;
int step_size = 5; 

void setup() {
  Serial.begin(9600);
  pinMode(pin_led, OUTPUT);
}

void loop() {
//  int pot_val = analogRead(pin_pot);
//  
//  Serial.println(pot_val);

//  if (brightness <= 0 || brightness >= 255) {
//    step_size = -step_size;
//  }

  brightness += step_size;
  Serial.println(brightness);

  analogWrite(pin_led, brightness);
  
  if (brightness <= 0) {
    step_size = -step_size;
  } else if(brightness >= 255) {
    step_size = -step_size;
    delay(1000);
  }


  
  delay(10);
}
