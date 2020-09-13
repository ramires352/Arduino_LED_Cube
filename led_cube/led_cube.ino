int layers[] = {A0, A1, A2};
int leds[] = {10,9,8,7,6,5,4,3,2};

void allOn(){
    int i;
    for(i=0;i<3;i++){
        digitalWrite(layers[i], HIGH);
    }
    for(i=0;i<9;i++){
        digitalWrite(leds[i], HIGH);
    }
}

void allOff(){
    int i;
    for(i=0;i<3;i++){
        digitalWrite(layers[i], LOW);
    }
    for(i=0;i<9;i++){
        digitalWrite(leds[i], LOW);
    }
}

void led_on(int layer, int led){
    digitalWrite(layer, HIGH);
    digitalWrite(led, HIGH);
}

void led_off(int layer, int led){
    digitalWrite(layer, LOW);
    digitalWrite(led, LOW); 
}

void layer_on(int layer){
    int i;
    digitalWrite(layer, HIGH);
    for(i=0;i<9;i++){
        digitalWrite(leds[i], HIGH);
    }
}

void layer_off(int layer){
    int i;
    digitalWrite(layer, LOW);
    for(i=0;i<9;i++){
        digitalWrite(leds[i], LOW);
    }
}

void column_on(int column){
    if(column < 9){
        int i;
        for(i=0;i<3;i++){
            digitalWrite(layers[i], HIGH);
        }
        digitalWrite(leds[column], HIGH);
    }
}

void column_off(int column){
    if(column < 9){
        digitalWrite(leds[column], LOW);
    }
}

void test_all(){
    allOff();
    int i,j;

    for(i=0;i<3;i++){
        digitalWrite(layers[i], HIGH);

        for(j=0;j<9;j++){
            digitalWrite(leds[j], HIGH);
            delay(200);
            digitalWrite(leds[j], LOW);
        }
        digitalWrite(layers[i], LOW);
    }
}

void spiral_animation_upward_downward(){
    int order_par[] = {0,1,2,5,8,7,6,3,4};
    int order_impar[] = {4,3,6,7,8,5,2,1,0};

    int dly_time = 100;

    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<9;j++){

            if(i==2 && j==8){
                break;
            }

            if(i % 2 == 0){
                led_on(layers[i], leds[order_par[j]]);
                delay(dly_time);
                led_off(layers[i], leds[order_par[j]]);
            }
            else{
                led_on(layers[i], leds[order_impar[j]]);
                delay(dly_time);
                led_off(layers[i], leds[order_impar[j]]);
            }
        }
    }

    for(i=2;i>-1;i--){
        for(j=8;j>-1;j--){
            if(i==0 && j==0){
                break;
            }
            if(i % 2 == 0){
                led_on(layers[i], leds[order_par[j]]);
                delay(dly_time);
                led_off(layers[i], leds[order_par[j]]);
            }
            else{
                led_on(layers[i], leds[order_impar[j]]);
                delay(dly_time);
                led_off(layers[i], leds[order_impar[j]]);
            }
        }
    }
}

void plane_clockwise(){
    allOff();

    int dly_time = 180;

    column_on(1);
    column_on(4);
    column_on(7);
    delay(dly_time);
    allOff();

    column_on(2);
    column_on(4);
    column_on(6);
    delay(dly_time);
    allOff();

    column_on(3);
    column_on(4);
    column_on(5);
    delay(dly_time);
    allOff();

    column_on(0);
    column_on(4);
    column_on(8);
    delay(dly_time);
    allOff();
}

void plane_counterclockwise(){
    int dly_time = 180;
    allOff();

    column_on(0);
    column_on(4);
    column_on(8);
    delay(dly_time);
    allOff();

    column_on(3);
    column_on(4);
    column_on(5);
    delay(dly_time);
    allOff();

    column_on(2);
    column_on(4);
    column_on(6);
    delay(dly_time);
    allOff();

    column_on(1);
    column_on(4);
    column_on(7);
    delay(dly_time);
    allOff();
}

void plane_vertical_clockwise(){
    allOff();

    int dly_time = 180;

    column_on(0);
    column_on(1);
    column_on(2);
    delay(dly_time);
    allOff();

    column_on(3);
    column_on(4);
    column_on(5);
    delay(dly_time);
    allOff();

    column_on(6);
    column_on(7);
    column_on(8);
    delay(dly_time);
    allOff();

    column_on(2);
    column_on(5);
    column_on(8);
    delay(dly_time);
    allOff();

    column_on(1);
    column_on(4);
    column_on(7);
    delay(dly_time);
    allOff();

    column_on(0);
    column_on(3);
    column_on(6);
    delay(dly_time);
    allOff();

    column_on(6);
    column_on(7);
    column_on(8);
    delay(dly_time);
    allOff();

    column_on(3);
    column_on(4);
    column_on(5);
    delay(dly_time);
    allOff();

    column_on(0);
    column_on(1);
    column_on(2);
    delay(dly_time);
    allOff();

    column_on(0);
    column_on(3);
    column_on(6);
    delay(dly_time);
    allOff();

    column_on(1);
    column_on(4);
    column_on(7);
    delay(dly_time);
    allOff();

    column_on(2);
    column_on(5);
    column_on(8);
    delay(dly_time);
    allOff();
}

void random_single_led(){
    int dly_time = 100;
    long int randLayer = random(0,3);
    long int randLed = random(0,10);

    led_on(layers[randLayer], leds[randLed]);
    delay(dly_time);
    allOff();
}

void setup(){
    int i;
    for(i=0;i<3;i++){
        pinMode(layers[i], OUTPUT);
    }
    for(i=0;i<9;i++){
        pinMode(leds[i], OUTPUT);
    }

    randomSeed(analogRead(A7));

    allOff();
}


void loop(){
    // allOff();
    int i;

    for(i=0;i<1;i++){
        spiral_animation_upward_downward();
    }

    for(i=0;i<9;i++){
        plane_clockwise();
    }

    // for(i=0;i<20;i++){
    //     random_single_led();
    // }

    for(i=0;i<5;i++){
        plane_vertical_clockwise();
    }

    // spiral_animation_upward_downward();
    // plane_clockwise();
    // plane_vertical_clockwise();
    // random_single_led();
}