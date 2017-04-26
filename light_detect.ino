const int topLED = 9;
const int middleLED = 8;
const int bottomLED = 7;

const int buzzer = 6;

const int photoResistor = A0;

const int variance = 100;
const int lowLight = 600;
const int mediumLight = lowLight + variance;
const int brightLight = mediumLight + variance;

void setup() {
    pinMode(topLED, OUTPUT);
    pinMode(middleLED, OUTPUT);
    pinMode(bottomLED, OUTPUT);
    pinMode(buzzer, OUTPUT);

    Serial.begin(9600);
}

void loop() {

    int lightValue = analogRead(photoResistor);

    if (lightValue <= lowLight) {
        noTone(buzzer);
    }
    else {
        tone(buzzer, lightValue);
    }
    
    if (lightValue <= lowLight) {
        digitalWrite(topLED, HIGH);
        digitalWrite(middleLED, HIGH);
        digitalWrite(bottomLED, HIGH);
    }
    else if (lightValue > lowLight && lightValue <= mediumLight) {
        digitalWrite(topLED, LOW);
        digitalWrite(middleLED, HIGH);
        digitalWrite(bottomLED, HIGH);
    }
    else if (lightValue > mediumLight && lightValue <= brightLight) {
        digitalWrite(topLED, LOW);
        digitalWrite(middleLED, LOW);
        digitalWrite(bottomLED, HIGH);
    }
    else {
        digitalWrite(topLED, LOW);
        digitalWrite(middleLED, LOW);
        digitalWrite(bottomLED, LOW);
    
    }

}
