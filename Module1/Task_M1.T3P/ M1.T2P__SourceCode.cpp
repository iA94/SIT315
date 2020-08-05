int S1=2;
int S2=3;
int red= 12;
int blue= 11;
int green= 10;
int State= LOW;
int State2= LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  
  
  attachInterrupt(digitalPinToInterrupt(S1),r,FALLING);
  attachInterrupt(digitalPinToInterrupt(S2),b,FALLING);
  


}

void loop()
{

Serial.println("In the loop");
delay(1000);
}

void r(){
 State= !State;
digitalWrite(red, State);
  }
void b(){
   State2= !State2;
digitalWrite(blue, State2);
}
  





