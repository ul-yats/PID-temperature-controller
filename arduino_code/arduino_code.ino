const float Tr = 298.15;
const float B = 3455.0; 
float T;
const int thisPin = 11;
void setup() {
Serial.begin(9600);
pinMode(thisPin, OUTPUT);  
}
void loop() {
  float u0;
  u0 = analogRead(A0)*5.0/1023;
  float u1;
  u1 = analogRead(A1)*5.0/1023;
  float r;
  r=u0*10000/(u1-u0);;
  T = (Tr*B/(log(r/10000)*Tr+B))-273.15;
  Serial.print(u0);
  Serial.print('\t');
  Serial.println(u1);
  Serial.print(r);
  Serial.print('\t');
  Serial.println(T);
  analogWrite(thisPin, pid(2,0.2,0.2,15.0));
  delay(500);
} 
float pid (float kP, float kI, float kD, float T1){
  float err = T - T1;
  float preverr = 0;
  float P = err;
  float I = 0;
  I = I + err*kI;
  float D = kD*(err - preverr);
  preverr = err;
  float Out = P+I+D;
  Out = map(Out, 0, 125, 0, 255);
  return Out;
}
