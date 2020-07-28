volatile byte r,g,b = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  PCICR |= 0b00000111;
  PCMSK2 |= 0b10011100;
}

void loop()
{
digitalWrite(12, r);
digitalWrite(10, g);
digitalWrite(11, b);
Serial.println("In the loop");
delay(1000);
}

ISR(PCINT2_vect){
  r = PIND & B00010000;
  g = PIND & B00000100;
  b =PIND & B00001000;
  Serial.println("loop interrupted");
}