#include <math.h>

int leds[6] = {11,10,9,6,5,3};
int led_len = sizeof(leds) / sizeof(leds[0]);
int MAX_BRIGHTNESS = 255;



void setup() {
    Serial.begin(9600);
    
    for(int i=0; i < led_len; i++) {
        Serial.println(leds[i]);
        pinMode(leds[i], OUTPUT);
    }
}

void loop() {
    // exit(0);
    wave();
}

void wave() {
    float steps = 1000;
    float length = 30;
    int delay_time = 10;

    float wave_pos = 0;
    for(float rad=0; rad<=2*PI; rad+=(2*PI/steps)) {

        for(int i_led=0; i_led<led_len; i_led++) {

            float sin_val = sin(rad + (2*PI/steps) * i_led * (steps / length));
            float shifted = (sin_val + 1) / 2;
            int pwm_val = log_converter(shifted);
            set_led(leds[i_led], pwm_val);

        // #region
            // Serial.print(sin_val);
            // Serial.print(", ");
            // Serial.print(shifted);
            // Serial.print(", ");
            // Serial.print(pwm_val);
            // Serial.println("");
        //#pragma endregion
        }
        // Serial.println("");
        // delay(delay_time);
    }

}

int log_converter(double linear) {
    double a = 0.33;
    int pwm_val = pow(MAX_BRIGHTNESS, linear) - 1;
    // int pwm_val = round(pow( (pow(MAX_BRIGHTNESS, a) * linear), 1/a));
    return pwm_val;
}

void set_led(int i_led, int val) {
    analogWrite(i_led, MAX_BRIGHTNESS - val);
}

void set_leds(int val) {
    for(int i=0; i < led_len; i++) {
        set_led(leds[i], val);
    }
}
