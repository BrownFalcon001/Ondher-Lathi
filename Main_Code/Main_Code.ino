/*
 *  brownFalcon
 */
 
#define echoPin1 10 
#define trigPin1 11
#define echoPin2 8 
#define trigPin2 9
#define echoPin3 10 
#define trigPin3 11
#define buzzer 3
#define vibrator 5
#define analogWrite digitalWrite
#define fst(x, y, n) analogWrite(x, n);analogWrite(y, n);delay(200);analogWrite(x, 0);analogWrite(y, 0);delay(500)
#define trd(x, y, n) analogWrite(x, n);analogWrite(y, n);delay(100);analogWrite(x, 0);analogWrite(y, 0);delay(100);analogWrite(x, n);analogWrite(y, n);delay(100);analogWrite(x, 0);analogWrite(y, 0);delay(100);analogWrite(x, n);analogWrite(y, n);delay(100);analogWrite(x, 0);analogWrite(y, 0);delay(100);analogWrite(x, n);analogWrite(y, n);delay(200);analogWrite(x, 0);analogWrite(y, 0);delay(500)

long duration1, duration2, duration3; 
int distance1, distance2, distance3;

void setup() {
  pinMode(vibrator, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(buzzer, LOW);
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);
  delay(20);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  
  delay(20);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2;
  delay(20);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 * 0.034 / 2;

//  Serial.println(distance1);
//  Serial.print(" ");
//  Serial.print(distance2);
//  Serial.print(" ");
//  Serial.println(distance3);
  if(distance3 <=100) {
    fst(buzzer, vibrator, 120);
//    fst(vibrator, 150);
//    Serial.println(distance3);
  }
  
  else -if(distance1 <=100 ||distance2 <=100) {
    trd(buzzer, vibrator, 100);
//    trd(vibrator, 100);
  }
  
  
}
