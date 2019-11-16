// Elevator code

// Leds
int ledUp = 12;
int ledDown = 13;

// Motor
const int E1 = 11;
const int l1 = 10;
const int l2 = 9;

// Pulsadores
int pulsador1 = 1; // Sotano
int pulsador2 = 2; // Nivel 1
int pulsador3 = 3; // Nivel 2
int pulsador4 = 4; // Nivel 3

// Sensores
int sensor1 = 5;
int sensor2 = 6;
int sensor3 = 7;
int sensor4 = 8;

// Niveles
int colaNiveles [50] = {};
int pisoDefault= 1;
int pisoActual = 0;
int pisoLlamada = 0;
int contador = 0;

// Estado elevador
int estado1 = 0;
int estado2 = 0;
int estado3 = 0;
int estado4 = 0;

int estadoSensor1 = 0;
int estadoSensor2 = 0;
int estadoSensor3 = 0;
int estadoSensor4 = 0;

boolean isRight;

void setup() {
  pinMode(ledUp, OUTPUT);
  pinMode(ledDown, OUTPUT);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(E1, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
}

void loop() {
    estado1 = digitalRead(pulsador1);
    estado2 = digitalRead(pulsador2);
    estado3 = digitalRead(pulsador3);
    estado4 = digitalRead(pulsador4);

    estadoSensor1 = digitalRead(sensor1);
    estadoSensor2 = digitalRead(sensor2);
    estadoSensor3 = digitalRead(sensor3);
    estadoSensor4 = digitalRead(sensor4);

    if(estadoSensor1 == HIGH){
        pisoActual = 0;
    }

    if(estadoSensor2 == HIGH){
        pisoActual = 1;
    }

    if(estadoSensor3 == HIGH){
        pisoActual = 2;
    }

    if(estadoSensor4 == HIGH){
        pisoActual = 3;
    }

    if(pisoLlamada == pisoActual){
        stop();
    }

    if(estado1 == HIGH){
        pisoLlamada = 0;

        if(pisoActual > pisoLlamada){
            turnOnMotorRight();
            turnOnLedUp();
        }else if ( pisoActual < pisoLlamada ) {
            turnOnMotorLeft();
            turnOnLedDown();
        }
    }

    if(estado2 == HIGH){
        pisoLlamada = 1;

        if(pisoActual > pisoLlamada){
            turnOnMotorRight();
            turnOnLedUp();
        }else if ( pisoActual < pisoLlamada ) {
            turnOnMotorLeft();
            turnOnLedDown();
        }
    }

    if(estado3 == HIGH){
        pisoLlamada = 2;

        if(pisoActual > pisoLlamada){
            turnOnMotorRight();
            turnOnLedUp();
        }else if ( pisoActual < pisoLlamada ) {
            turnOnMotorLeft();
            turnOnLedDown();
        }
    }

    if(estado4 == HIGH){
        pisoLlamada = 3;

        if(pisoActual > pisoLlamada){
            turnOnMotorRight();
            turnOnLedUp();
        }else if ( pisoActual < pisoLlamada ) {
            turnOnMotorLeft();
            turnOnLedDown();
        }
    }
}

void turnOnMotorRight(){
    digitalWrite(E1, HIGH);
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
}

void turnOnMotorLeft(){
    digitalWrite(E1, HIGH);
    digitalWrite(l1, LOW);
    digitalWrite(l2, HIGH);
}

void turnOnLedUp(){
    delay(20);
    digitalWrite(ledUp, HIGH);
    digitalWrite(ledDown, LOW);
}

void turnOnLedDown(){
    delay(20);
    digitalWrite(ledUp,LOW);
    digitalWrite(ledDown,HIGH);
}

void stop(){
    digitalWrite(E1, LOW);
    digitalWrite(ledUp, HIGH);
    digitalWrite(ledDown, HIGH);
}