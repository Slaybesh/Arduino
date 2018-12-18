# 1 "c:\\Users\\Huy\\Documents\\GitHub\\Arduino\\src\\potentiometer_delay.ino"
# 1 "c:\\Users\\Huy\\Documents\\GitHub\\Arduino\\src\\potentiometer_delay.ino"

const int pin_pot = 0;
const int pin_led = 3;

int brightness = 0;
int step = 0;
int step_dir = 1;

void setup() {
    Serial.begin(9600);
    pinMode(pin_led, 0x1);
}

void loop() {
    //  int pot_val = analogRead(pin_pot);
    //
    //  Serial.println(pot_val);

    //  if (brightness <= 0 || brightness >= 255) {
    //    step_size = -step_size;
    //  }


    step += step_dir;

    if (step <= 0) {
        step_dir = -step_dir;
        step = 0;
        delay(1000);
    }
    else if (step >= 10) {
        step_dir = -step_dir;
    }

    brightness = led_step(step);
    analogWrite(pin_led, brightness);

    Serial.println(brightness);
    Serial.println(step);

    delay(30);
}

int led_step(int step) {
    int value = 255 - pow(step, 2);
    if (value < 0) {
        value = 0;
    }
    return value;
}
