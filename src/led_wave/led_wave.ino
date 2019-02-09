
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
    fade_led();
}

void fade_led() {
    double steps = 100;
    int delay_time = 10;

    for(double i=0; i<=1; i+=(1/steps)) {
        int val = log_converter(i);
        set_leds(val);
        delay(delay_time);
    }
    delay(delay_time);
    Serial.println();
    for(double i=1; i>=0; i-=(1/steps)) {
        int val = log_converter(i);
        set_leds(val);
        delay(delay_time);
    }
    Serial.println();
}


int log_converter(double linear) {
    double a = 0.33;
    int pwm_val = pow(MAX_BRIGHTNESS, linear);
    // int pwm_val = round(pow( (pow(MAX_BRIGHTNESS, a) * linear), 1/a));
    Serial.print(linear);
    Serial.print(" ");
    Serial.println(pwm_val);
    return pwm_val;
}

void set_led(int i_led, int val) {
    analogWrite(i_led, 255 - val);
}

void set_leds(int val) {
    for(int i=0; i < led_len; i++) {
        set_led(leds[i], val);
    }
}

void v1() {
    for(int i=0; i < led_len; i++) {
        int i_clean = i - 2;
        int i_prev = i - 1;
        int i_next = i + 1;
        if(i_clean == -1) {
            i_clean = led_len - 1;
        }
        if(i_clean == -2) {
            i_clean = led_len - 2;
        }
        if(i_prev < 0) {
            i_prev = led_len - 1;
        }
        if(i_next >= led_len) {
            i_next = 0;
        }

        // Serial.println(leds[i]);
        // set_led(leds[i_clean], 0);
        // set_led(leds[i_prev], 1);
        // set_led(leds[i_next], 1);
        // set_led(leds[i], led_step(i));
        delay(80);
    }
}

// void apply_function_to_array(int arr, function) {
//         for(int i=0; i < sizeof(arr) / sizeof(arr[0]); i++) {
//         Serial.println(arr[i]);
//         function(arr[i], OUTPUT);
//     }
// }