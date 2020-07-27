

const int  button_pin = 2;
const int  led_pin=5;
int  led_State= LOW;

void setup(){
  
pinMode(button_pin, INPUT);
pinMode(led_pin,OUTPUT);
attachInterrupt(digitalPinToInterrupt(button_pin),blink,FALLING);
  
}


void loop()
{
  delay(1000000);
}


void blink(){
led_State= !led_State;
digitalWrite(led_pin, led_State);
}
