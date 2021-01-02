#define forward_val 200       // Change this value to change senstivity for forward direction    
#define backward_val 200      // Change this value to change senstivity for backward direction   
#define left_val 200          // Change this value to change senstivity for left direction      
#define right_val 200         // Change this value to change senstivity for right direction    

int GroundPin = A4; //Set Analog pin 4 as GND
int VCCPin = A5; //Set Analog pin 5 as VCC
int x_Pin   = A3; //X axis input
int y_Pin   = A2; //Y axis input
int z_Pin   = A1; //Z axis input(not used)


//Output pins to be connected to 10, 11, 12, 13 of Decoder IC
int w1=10,w2=11,w3=12,w4=13; 


//Variabes for storing x,y,z coordinates
long x; 
long y; 
long z; 



void setup()
{
  Serial.begin(9600);
  pinMode(w1,OUTPUT);
  pinMode(w2,OUTPUT);
  pinMode(w3,OUTPUT);
  pinMode(w4,OUTPUT);
  pinMode(GroundPin, OUTPUT);
  pinMode(VCCPin, OUTPUT);
  digitalWrite(GroundPin, LOW); //Set A4 pin LOW
  digitalWrite(VCCPin, HIGH); //Set A5 pin HIGH
}






void loop()
{
   //Reading x,y,z coordinates
  x = analogRead(x_Pin); //Reading x,y,z coordinates
  y = analogRead(y_Pin); 
  z = analogRead(z_Pin); 
  
   // Change the value for adjusting sensitivity
    if(x<forward_val)       
      forward();
    else if(x>backward_val) 
      backward();
    else if(y>right_val) 
      right();
    else if(y<left_val) 
      left();
    else
      stop_();
}


void stop_()
{
  Serial.println("");
  Serial.println("STOP");
  digitalWrite(w1,LOW);
  digitalWrite(w2,LOW);
  digitalWrite(w3,LOW);
  digitalWrite(w4,LOW);
}




void forward()
{
  Serial.println("");
  Serial.println("Forward");
  digitalWrite(w1,HIGH);
  digitalWrite(w2,LOW);
  digitalWrite(w3,HIGH);
  digitalWrite(w4,LOW);
}




void backward()
{
  Serial.println("");
  Serial.println("Backward");
  digitalWrite(w1,LOW);
  digitalWrite(w2,HIGH);
  digitalWrite(w3,LOW);
  digitalWrite(w4,HIGH);
}




void left()
{
  Serial.println("");
  Serial.println("Left");
  digitalWrite(w1,LOW);
  digitalWrite(w2,HIGH);
  digitalWrite(w3,HIGH);
  digitalWrite(w4,LOW);
}




void right()
{
  Serial.println("");
  Serial.println("Right");
  digitalWrite(w1,HIGH);
  digitalWrite(w2,LOW);
  digitalWrite(w3,LOW);
  digitalWrite(w4,HIGH);
}