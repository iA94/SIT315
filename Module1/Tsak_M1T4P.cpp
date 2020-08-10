volatile byte r,g,b = 0;
int ledpin =13;
void setup()
{
  Serial.begin(9600);
 //ports
  PCICR |= 0b00000111;
  PCMSK2 |= 0b10011100;
 //timer
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 62499;
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  TCCR1B |= (1<< WGM12);
  interrupts();
  
  pinMode(ledpin,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
}

void loop()
{
digitalWrite(12, r);
digitalWrite(10, g);
digitalWrite(11, b);
Serial.println("In the loop");
delay(1000);
}
ISR(TIMER1_COMPA_vect){
  digitalWrite(ledpin, digitalRead(ledpin)^1);
  Serial.println("Timer Interruption");
}

ISR(PCINT2_vect){
  r = PIND & B00010000;
  g = PIND & B00000100;
  b =PIND & B00001000;
  Serial.println("loop interrupted");
  
}