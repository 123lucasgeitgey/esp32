//ultrosonic distance
  float ultrasonicDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2.0;
  delay(10);
  return distance; }
//setup
  void setup() {
  Serial.begin(9600); 
  pinMode(2, OUTPUT);
  pinMode(15, INPUT);
  pinMode(33, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH); }
int randomturn;
int sendie;
//motor
  
  void moveit(){
  if (ultrasonicDistance(2, 15) > 30) {
    randomturn = random(0, 3 + 1);
    digitalWrite(26, LOW);
    digitalWrite(25, HIGH);
    analogWrite(33, 200);
    digitalWrite(12, HIGH);
    digitalWrite(14, LOW);
    analogWrite(13, 500);
  }
  if (ultrasonicDistance(2, 15) < 30) {
    if (randomturn == 1) {
      digitalWrite(26, LOW);
      digitalWrite(25, HIGH);
      analogWrite(33, 200);
      digitalWrite(12, LOW);
      digitalWrite(14, HIGH);
      analogWrite(13, 500);
      delay(2000);
    }
    if (randomturn == 2) {
      digitalWrite(26, HIGH);
      digitalWrite(25, LOW);
      analogWrite(33, 200);
      digitalWrite(12, HIGH);
      digitalWrite(14, LOW);
      analogWrite(13, 200);
      delay(2000);
    } }}
//sendie  
  void sendy(){
  sendie = sendie + 1;
  Serial.println(sendie); }
//loop
  void loop(){
    //sendie
      sendy();
 delay(100);
 moveit();
}
