#define xPin A1
#define yPin A0
#define bPin 7
#define relay 8
int prev_state=0;

void setup(){
    Serial.begin(9600);
    pinMode(bPin,INPUT_PULLUP);
    pinMode(relay,OUTPUT);
}

void loop(){
    int x=0,y=0,z=0;
    int sensitivity=10;
    int X=analogRead(xPin);
    int Y=analogRead(yPin);
    int B=digitalRead(bPin);

    if(X>=550){
        x=map(X,550,1023,0,-sensitivity);
    }
    if(X<=450){
        x=map(X,450,0,0,sensitivity);
    }
    if(Y>=550){
        y=map(Y,550,1023,0,sensitivity);
    }
    if(Y<=450){
        y=map(Y,450,0,0,-sensitivity);
    }

    if(B==1 && prev_state==0)
        z=1;
    else
        z=0;
    if(z==1)
        digitalWrite(relay,HIGH);
    else
        digitalWrite(relay,LOW);
        
    Serial.print(x);
    Serial.print(" ");
    Serial.print(y);
    Serial.print(" ");
    Serial.println(z);
    prev_state=B;
    delay(10);
}