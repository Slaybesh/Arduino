# 1 "c:\\Users\\Huy\\Documents\\GitHub\\Arduino\\src\\potentiometer_delay\\potentiometer_delay.ino"
# 1 "c:\\Users\\Huy\\Documents\\GitHub\\Arduino\\src\\potentiometer_delay\\potentiometer_delay.ino"

const int pin_pot = 0;
const int pin_led = 3;

int brightness = 0;
int max_brightness = 200;
int step = 0;
int step_dir = 1;
double fade_speed;

void setup() {
    Serial.begin(9600);
    pinMode(pin_led, 0x1);

}

void loop() {
    // exit(0);

    double pot_val = analogRead(pin_pot);
    fade_speed = pot_val / 5000;
    // fade_speed = 0.2;
    Serial.println(pot_val);

    int steps = ceil(sqrt(max_brightness / fade_speed));
    // Serial.print("Steps: ");
    // Serial.println(steps);
    // Serial.print("speed: "); 
    // Serial.println(fade_speed);
    fade(fade_speed, steps);
    // delay(200);


}

void fade(double speed, int steps) {
    step += step_dir;

    brightness = led_step(step);
    analogWrite(pin_led, brightness);

    step_dir = change_fade_dir(&step, steps);

    // Serial.println(255 - brightness);
    // Serial.println(step);

    delay(15);
}

int led_step(int step) {
    int value = 255 - ((fade_speed * pow(step, 2))>=0?(long)((fade_speed * pow(step, 2))+0.5):(long)((fade_speed * pow(step, 2))-0.5));
    if (value < 0) {
        value = 0;
    }
    return value;
}

int change_fade_dir(int *step, int steps) {

    if (*step <= 0) {
        step_dir = -step_dir;
        *step = 0;
        // delay(1000);
        // Serial.println();
    }
    else if (*step >= steps) {
        // Serial.println(steps);
        step_dir = -step_dir;
    }
    return step_dir;
}
