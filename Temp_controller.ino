double tempC=0;

///create constants for the three analog input pins
const int redPot = 0; 
const int greenPot = 1; 
const int bluePot = 2;

//create constants for the three RGB pulse width pins 
const int redPin = 5; 
const int greenPin = 6; 
const int bluePin = 9;

//create variables to store the red, green and blue values
int redVal; int greenVal; int blueVal;

void setup() {
  pinMode(redPin,OUTPUT); 
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT); 
  Serial.begin(9600);
}

void loop() {

  tempC = analogRead(A0);
  tempC = tempC * 0.48828125;

  double tempF= (tempC * 9/5) + 32;
  
  Serial.print("Temperature : ");  Serial.print(tempC); Serial.print(" C ,");
  Serial.print( tempF);Serial.println(" F "); 
  delay(2000);

//read the three analog input pins and store their value to the color variables 
  redVal = analogRead(redPot); 
  greenVal = analogRead(greenPot); 
  blueVal = analogRead(bluePot);

 // use the analogWrite() function to write the color values to their respective 
 // RGB pins. 
 analogWrite(redPin, redVal); 
 analogWrite(greenPin, greenVal);
 analogWrite(bluePin, blueVal); 

  if (tempC < 16) // cold 
  {  
   digitalWrite(bluePin,HIGH);
  }
  else if (tempC < 20) // Normal temp
  {
  digitalWrite(greenPin,HIGH); 
  }
  else if (tempC < 24) // min. hot
  {
  digitalWrite(redPin,HIGH);
  } 
  else if (tempC < 28) // getting hot
  {
  digitalWrite(bluePin,LOW); 
  } 
  else if (tempC >= 28 && tempC <= 45) // pretty hot 
  {
  digitalWrite(redPin,LOW);
  }
  else // too hot 
  {
   digitalWrite(bluePin,LOW);
   digitalWrite(greenPin,HIGH);
   digitalWrite(redPin,LOW);
  }
}
