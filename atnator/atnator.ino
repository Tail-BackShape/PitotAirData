void setup() {
  pinMode(A0, INPUT);
  Serial.begin(115200);
}

void loop() {
  int one, two, three, four, five, six, seven, eight, ave;
  analogReadResolution(12);

  one = analogRead(A0);
  delay(1);
  two = analogRead(A0);
  delay(1);
  three = analogRead(A0);
  delay(1);
  four = analogRead(A0);
  delay(1);
  five = analogRead(A0);
  delay(1);
  six = analogRead(A0);
  delay(1);
  seven = analogRead(A0);
  delay(1);
  eight = analogRead(A0);
  ave = (one + two + three + four + five + six + seven + eight) / 8;

  Serial.println(ave);

  delay(100);
}
