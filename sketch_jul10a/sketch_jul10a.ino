#define S0 D1
#define S1 D2
#define S2 D3
#define S3 D4
#define sensorOut D5

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Set frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {
  // Read red
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  int redFrequency = pulseIn(sensorOut, LOW);

  // Read green
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int greenFrequency = pulseIn(sensorOut, LOW);

  // Read blue
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int blueFrequency = pulseIn(sensorOut, LOW);

  // Read clear
  digitalWrite(S2, HIGH);
  digitalWrite(S3, LOW);
  int clearFrequency = pulseIn(sensorOut, LOW);

  Serial.print("R: ");
  Serial.print(redFrequency);
  Serial.print(" G: ");
  Serial.print(greenFrequency);
  Serial.print(" B: ");
  Serial.print(blueFrequency);
  Serial.print(" C: ");
  Serial.println(clearFrequency);

  delay(100);
}
