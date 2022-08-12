//INITIALIZING PINS
const int redPin = 3; 
const int greenPin = 4; 
const int yellowPin = 5;
const int echoPin = 7;
const int trigPin = 6;

int distance;
// CODE THAT DOESN'T CHANGE GOES HERE
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
}


//CODE THAT REPEATS ITSELF 
void loop(){
  sendPing();
  int duration = pulseIn(echoPin, HIGH)//returns how long the echo pin was on HIGH state
  distance = 0.034 * duration/2
  distance = clamp(distance, 0, 50); //CLAMPING DISTANCE SINCE US LOOSES ACCURACY AT DISTANCES > 50 CM
  printToScreen(distance);
  //CONDITIONAL STATEMENTS
  if (distance >= 0 && distance <= 15){
    Red(255);
    Green(0);
    Yellow(0);
  }
  else if (distance >= 16 && distance < 33){
    Red(0);
    Yellow(255);
    Green(0);
  }
  else if (distance >= 33 && distance <= 50){
    Red(0);
    Yellow(0);
    Green(255);
  }
}



//color coding functions
void Red(int VAL){
  analogWrite(redPin, VAL);
  analogWrite(greenPin, 0);
  analogWrite(yellowPin, 0);
  
}
void Green(int VAL){
  analogWrite(redPin, 0);
  analogWrite(greenPin, VAL);
  analogWrite(yellowPin, 0);
}
void Yellow(int VAL){
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(yellowPin, 0);
}
//SENDING PING FROM US
void sendPing(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
}

// CLAMPING READINGS FROM US SENSOR
int clamp(int VAL, int min, int max){
  if (VAL <= min){
    VAL = min;
    return VAL;
  }
  else if (VAL >= max){
    VAL = max;
    return VAL}
    else{return VAL}
  
}
void printToScreen(int TARGET){
  Serial.print(TARGET);
  Serial.println(" cm");
