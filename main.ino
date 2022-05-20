int trig=10,echo=9,led_verde=4,led_azul=5,buzzer=7;
const int rele=6;
float t_espera,distancia;
boolean ban=false;

void setup(){
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(led_verde,OUTPUT);
pinMode(led_azul,OUTPUT);
pinMode(rele,OUTPUT);
} 

void alerta(){
tone(buzzer,200,200);
} 


void loop(){
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

t_espera=pulseIn(echo,HIGH);
distancia=(t_espera/2)/29.15;
Serial.print(distancia);
Serial.println(distancia);

if(distancia<=30){
digitalWrite(rele,HIGH);
digitalWrite(led_verde,HIGH);
digitalWrite(led_azul,LOW);
if(ban==false){
alerta();

} 
ban=true;
} else{
digitalWrite(rele,LOW);
digitalWrite(led_verde,LOW);
digitalWrite(led_azul,HIGH);
ban=false;
} 
delay(500);
} 
