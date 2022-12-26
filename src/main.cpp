#include <Arduino.h>

//acknowledgement : Technoskill
int IR1 = 4;//Sensor Kiri
int IR2 = 3;//Sensor Kanan

// Motor A - Roda Kiri
int enA = 10;
int in1 = 9;
int in2 = 8;
// Motor B - Roda Kanan
int enB = 5;
int in3 = 6;
int in4 = 7;

void forward(){
    // Menggerakkan kedua motor maju
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite (enA, 200);
    analogWrite (enB, 200);
}

void turnRight() {
    // Membelokkan robot ke kanan
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite (enA, 200);
    analogWrite (enB, 150);
    delay(100);
}

void turnLeft() {
    // Membelokkan robot ke kiri
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite (enA, 150);
    analogWrite (enB, 200);
    delay(100);
}

void stop() {
    // Menghentikan kedua motor
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite (enA, 0);
    analogWrite (enB, 0);
}

// Menjalankan program sekali
void setup() {
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(IR1, INPUT);
    pinMode(IR2, INPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}
// Menjalankan program secara berulang-ulang
void loop() {
    int readIR1 = digitalRead(IR1);
    int readIR2 = digitalRead(IR2);

    // Jika kedua sensor tidak mendeteksi permukaan hitam
    if(readIR1 == HIGH && readIR2 == HIGH) {
        forward();
    }
        // Jika sensor kanan mendeteksi permukaan hitam
    else if(readIR1 == HIGH && readIR2 == LOW) {
        turnRight();
    }
        // Jika sensor kiri mendeteksi permukaan hitam
    else if(readIR1 == LOW && readIR2 == HIGH) {
        turnLeft();
    }
    else { // Jika sensor kiri dan kanan mendeteksi permukaan hitam
        stop();
    }
}