int tri=8;
int echo=9;
int d;
long duration;
void setup() {
  
  
  pinMode(10,INPUT_PULLUP);
  
  pinMode(tri,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(tri,0);
  delayMicroseconds(5);
  digitalWrite(tri,1);
  delayMicroseconds(10);
  digitalWrite(tri,0);
  duration=pulseIn(echo,1);
  d=(duration*0.0343)/2;
  Serial.print("dist is");
  Serial.println(d);
  if(d>30)
  {
    digitalWrite(6,1);
    digitalWrite(5,0);
    digitalWrite(4,0);
    digitalWrite(3,0);
    digitalWrite(2,0);
Serial.print("empty");

  }
  else{
    if(d<=30&&d>20)
    {
      digitalWrite(5,1);
      digitalWrite(4,1);
      Serial.print("L1");
      Serial.print("L2");
      

    }
    else{
      if(d<=20&&d>10)
      {
        digitalWrite(4,1);
        digitalWrite(3,1);
        digitalWrite(6,0);
        Serial.print("full");
        

      
      
      }
    }
  }
  delay(500);
}