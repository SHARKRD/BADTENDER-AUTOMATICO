/*Pin 12 es para el led de acceso correcto
  Pin 13 es para el pin de acceso incorrecto
  pin 11 es para el control del servo motor
  del 9 al 2 es para el Kpad  de izquierda a derecha como mas significativo*/

#include <Keypad.h>     // importa libreria Keypad
#include <Servo.h>      //importa libreria del servo motor(Puerta)

/*******************************************************/
const byte FILAS = 4;     // define numero de filas
const byte COLUMNAS = 4;    // define numero de columnas
char keys[FILAS][COLUMNAS] = {    // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
/*******************************************************/

byte pinesFilas[FILAS] = {9,8,7,6};   // pines correspondientes a las filas
byte pinesColumnas[COLUMNAS] = {5,4,3,2}; // pines correspondientes a las columnas

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // crea objeto

char TECLA;       // almacena la tecla presionada
char CLAVE[7];        // almacena en un array 6 digitos ingresados
char CLAVE_MAESTRA[7] = "123456";
char CLAVE_MAESTRA_CERRADA[7] = "111111";   // almacena en un array la contraseña maestra
byte INDICE = 0;      // indice del array

/*******************************************************/
int verde = 12;
int rojo = 13;
Servo Puerta1;
Servo Puerta2; 
int Puerta_pin1 = 10;
int Puerta_pin2 = 11;
int abierta = 180;
int cerrada = 90;
  
/*******************************************************/  
void setup()
{
  Serial.begin(9600);
  pinMode(rojo,OUTPUT);
  Puerta1.attach(Puerta_pin1);       // inicializa comunicacion serie
  Puerta2.attach(Puerta_pin2);
  pinMode(verde,OUTPUT);//funcion del servo
  Puerta1.write(cerrada);
  Puerta2.write(cerrada);
  digitalWrite(rojo, 1);
  digitalWrite(verde, 0);
}
/*******************************************************/
void loop(){
  
  TECLA = teclado.getKey();   // obtiene tecla presionada y asigna a variable
  if (TECLA)        // comprueba que se haya presionado una tecla
  {
    CLAVE[INDICE] = TECLA;    // almacena en array la tecla presionada
    INDICE++;       // incrementa indice en uno
    Serial.print(TECLA);    // envia a monitor serial la tecla presionada
  }

  if(INDICE == 6)       // si ya se almacenaron los 6 digitos
  {
    if(!strcmp(CLAVE, CLAVE_MAESTRA)){   // compara clave ingresada con clave maestra
      Serial.println(" Correcta, *****Puerta Habilitada*****");  // imprime en monitor serial que es correcta la clave
      digitalWrite(verde,1);
      digitalWrite(rojo,0);
      Puerta1.write(abierta);
      Puerta2.write(abierta);

 
    }
    else if(!strcmp(CLAVE, CLAVE_MAESTRA_CERRADA)){   // compara clave ingresada con clave maestra
      Serial.println(" Correcta, *****Puerta INHABILITADA*****");  // imprime en monitor serial que es correcta la clave
      digitalWrite(verde,0);
      digitalWrite(rojo,1);
      Puerta1.write(cerrada);
      Puerta2.write(cerrada);
    }
    else{
      Serial.println(" Incorrecta");  // imprime en monitor serial que es incorrecta la clave
      digitalWrite(rojo,1);
      Puerta1.write(cerrada);
      Puerta2.write(cerrada);
      delay(1000);
      digitalWrite(rojo,0);
    }

    INDICE = 0;
  }
}


/*#include <Servo.h>

Servo Puerta; 
int Puerta_pin = 11;
int abierta = 0;
int cerrada = 180;


void setup() {

  Puerta.attach(Puerta_pin);   // put your setup code here, to run once:

}

void loop() {
    Puerta.write(abierta);  // put your main code here, to run repeatedly:
    delay(2000); 
    Puerta.write(cerrada);
    delay(2000); 
}*/