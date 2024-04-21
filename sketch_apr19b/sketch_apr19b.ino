/*#include <Servo.h>
#include <Stepper.h>*/

//Salidas  del ESP32 SOKET
int bebida1 = 11; 
int bebida2 = 10;
int bebida3 = 9;
int bebida4 = 46;
int bebida5 = 3;
int bebida6 = 8;
int bebida7 = 18;
int bebida8 = 17;
int pin5 = 5;

//VARIABLES UTILIZADAS
//Servo servoMotor;  //Servo motores utilizados 
int seleccion = 0; //variable para saber que se selecciona
bool enter = 0; //saber si se selecciono una opcion del menu

void setup() {
  
  //Declaracion de las salidas del soket como entradas
  Serial.begin(9600);
  pinMode(bebida1, INPUT);
  pinMode(bebida2, INPUT);
  pinMode(bebida3, INPUT);
  pinMode(bebida4, INPUT);
  pinMode(bebida5, INPUT);
  pinMode(bebida6, INPUT);
  pinMode(bebida7, INPUT);
  pinMode(bebida8, INPUT);
  pinMode(pin5, OUTPUT);

}

void loop() {


  while(enter == 0){

      if(bebida1 == 1){
        seleccion = 1;
        enter = !enter;
      }
      else if(bebida2 == 1){
        seleccion = 2;
        enter = !enter;
      }
      else if(bebida3 == 1){
        seleccion = 3;
        enter = !enter;
      }
      else if(bebida4 == 1){
        seleccion = 4;
        enter = !enter;
      }
      else if(bebida5 == 1){
        seleccion = 5;
        enter = !enter;
      }
      else if(bebida6 == 1){
        seleccion = 6;
        enter = !enter;
      }
      else if(bebida7 == 1){
        seleccion = 7;
        enter = !enter;
      }
      else if(bebida8 == 1){
        seleccion = 8;
        enter = !enter;
      }
      else{
        enter = false;
      }
  }


//  if(sensorbaso){

if(enter == 1){

  switch (seleccion) {
    case 1:
      Serial.println("Seleccionaste la opción 1");
      seleccion1(pin5);

      break;
    case 2:
      Serial.println("Seleccionaste la opción 2");
      break;
    case 3:
      Serial.println("Seleccionaste la opción 3");
      break;
    default:
      Serial.println("Opción no válida");
      break;
  }

}

}

void seleccion1(int pin5){

  digitalWrite(pin5, 1);
  delay(1000);
  digitalWrite(pin5, 0);
  delay(1000);
  digitalWrite(pin5, 1);
  delay(1000);
  digitalWrite(pin5, 0);
  delay(1000);
  digitalWrite(pin5, 1);
  delay(1000);
  digitalWrite(pin5, 0);
  delay(1000);
}
