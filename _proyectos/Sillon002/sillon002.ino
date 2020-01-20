#define ON HIGH                 // Cambiar para logica positiva/negativa
#define OF LOW                  // Cambiar para logica positiva/negativa
#define PS LOW                  // Cambiar para logica positiva/negativa
#define PN HIGH                  // Cambiar para logica positiva/negativa

/*
Que solo funcione 1 cosa a la vez de las que consumen mucho, hecho casi todos los casos
Tiempo de bacha y valor
Posicion cero, salida paciente

Los limites de carrera para seguridad
Efecto rebote en los botones. hecho parcialmente.
El agua carga por un tiempo determinado
  Que se pueda modificar el tiempo
  que se pueda frenar.
que cuente las vueltas
  y las tome como limite de carrera
al menos 3 memorias para la posicion del sillon

*/

// Constantes para definir los pines
// Tener en cuenta que los pines fisicos no se corresponden con los digitales y cambian segun el modelo del arduino
// P. Ej. Nano = I/O digital 4 = patafísica 7
const int inRespaldoAtras = 9; //Pulsador fisico 1 (izq a der)
const int inRespaldoAdelante = 8; //Pulsador fisico 2 
const int inAsientoArriba = 7; //Pulsador fisico
const int inAsientoAbajo = 6; //Pulsador fisico
const int inLampara = 5; //Pulsador fisico
const int inVaso = 4; //Pulsador fisico
const int inBacha = 3; //Pulsador fisico
const int inPaciente0 = 2; //Pulsador fisico
const int ouRespaldoAtras = A0; //Direccion izquireda
const int ouRespaldoAdelante = A1; //Direccion derecha
const int ouAsientoArriba = A2;  
const int ouAsientoAbajo = A3;  
const int ouLampara = A4;  
const int ouVaso = A5;  
const int ouBacha = A6;  
const int ouPaciente0 = 13;  

int valorPulsador = 0;  //variable intermedia para verificar si se oprimio un pulsador
bool estadoLampara = OF ; //Estado de la iluminacion
int valorSalida;  //variable axiliar 
//bool algunPulsadorActivo = flase;  //variable axiliar

//Definiciones para el manejo del vaso
unsigned long T_ControlVaso=0;      // Para controlar el tiempo consumido
unsigned long T_ControlBacha=0;      // Para controlar el tiempo consumido
unsigned long T_ApagarVaso=5000;    // Tiempo de funcionamiento
unsigned long T_ApagarBacha=15000;    // Tiempo de funcionamiento
bool EstadoPinVaso=PN; //Pulsador sin presionar           
bool EstadoPinBacha=PN; //Pulsador sin presionar           
bool AnteriorEstadoPinVaso=PN; //Pulsador sin presionar
bool AnteriorEstadoPinBacha=PN; //Pulsador sin presionar

void setup() {
  // Define los pines de entrada
  pinMode(inRespaldoAtras, INPUT_PULLUP); //Define 
  pinMode(inRespaldoAdelante, INPUT_PULLUP); 
  pinMode(inAsientoArriba, INPUT_PULLUP); 
  pinMode(inAsientoAbajo, INPUT_PULLUP); 
  pinMode(inLampara, INPUT_PULLUP); 
  pinMode(inVaso, INPUT_PULLUP); 
  pinMode(inBacha, INPUT_PULLUP); 
  pinMode(inPaciente0, INPUT_PULLUP); 
  // Definir los pines de salida
  pinMode(ouRespaldoAtras, OUTPUT);
  pinMode(ouRespaldoAdelante, OUTPUT);
  pinMode(ouAsientoArriba, OUTPUT);
  pinMode(ouAsientoAbajo, OUTPUT);
  pinMode(ouLampara, OUTPUT);
  pinMode(ouVaso, OUTPUT);
  pinMode(ouBacha, OUTPUT);
  //pinMode(ouPaciente0, OUTPUT); Este no es una salida espcifica es una combinacion de otras salidas
  // incializar estados necesarios
  digitalWrite(ouLampara , LOW) ; // Apagamos Luz al comenzar
}

void loop() {
  VerificarPulsadorRespaldoAtras();
  VerificarPulsadorRespaldoAdelante();
  VerificarPulsadorAsientoArriba();
  VerificarPulsadorAsientoAbajo();
  VerificarPulsadorLampara();
  VerificarPulsadorVaso();
  VerificarPulsadorBacha();
  //VerificarPulsadorPaciente0(); A relaizar luego

}

void VerificarPulsadorRespaldoAtras() {
  valorPulsador = digitalRead(inRespaldoAtras); //asignar estado del pulsador a una variable
  valorSalida   = ouRespaldoAtras;
   if (valorPulsador == PS) {
    if (digitalRead(ouRespaldoAdelante) == OF &&
          digitalRead(ouAsientoAbajo) == OF &&
          digitalRead(ouAsientoArriba) == OF){
      if (estadoLampara == ON) {
        digitalWrite(ouLampara, LOW); //apagar lampara porque estaba prendida
      }
      digitalWrite(valorSalida, HIGH);
    }
  }
  else {
    digitalWrite(valorSalida, LOW);
  }
}

void VerificarPulsadorRespaldoAdelante() {
  valorPulsador = digitalRead(inRespaldoAdelante); //asignar estado del pulsador a una variable
  valorSalida   = ouRespaldoAdelante;
   if (valorPulsador == PS) {
    if (digitalRead(ouRespaldoAtras) == OF &&
          digitalRead(ouAsientoAbajo) == OF &&
          digitalRead(ouAsientoArriba) == OF){
      if (estadoLampara == ON) {
        digitalWrite(ouLampara, LOW); //apagar lampara porque estaba prendida
      }
      digitalWrite(valorSalida, HIGH);
    }
  }
  else {
    digitalWrite(valorSalida, LOW);
  }
}

void VerificarPulsadorAsientoArriba() {
  valorPulsador = digitalRead(inAsientoArriba); //asignar estado del pulsador a una variable
  valorSalida   = ouAsientoArriba;
   if (valorPulsador == PS) {
    if (digitalRead(ouRespaldoAtras) == OF &&
          digitalRead(ouRespaldoAdelante) == OF &&
          digitalRead(ouAsientoAbajo) == OF){
      if (estadoLampara == ON) {
        digitalWrite(ouLampara, LOW); //apagar lampara porque estaba prendida
      }
      digitalWrite(valorSalida, HIGH);
    }
  }
  else {
    digitalWrite(valorSalida, LOW);
  }
}

void VerificarPulsadorAsientoAbajo() {
  valorPulsador = digitalRead(inAsientoAbajo); //asignar estado del pulsador a una variable
  valorSalida   = ouAsientoAbajo;
   if (valorPulsador == PS) {
    if (digitalRead(ouRespaldoAtras) == OF &&
          digitalRead(ouRespaldoAdelante) == OF &&
          digitalRead(ouAsientoArriba) == OF){
      if (estadoLampara == ON) {
        digitalWrite(ouLampara, LOW); //apagar lampara porque estaba prendida
      }
      digitalWrite(valorSalida, HIGH);
    }
  }
  else {
    digitalWrite(valorSalida, LOW);
  }
}

void VerificarPulsadorLampara() {
  bool  valor =  digitalRead(inLampara) ;  //leemos el botón pulsado: false  =  HIGH
  if ( valor == false)                    // esto es que han pulsado el botón
    {
      estadoLampara = ! estadoLampara ;                  // cambiamos el estado
      digitalWrite(ouLampara, estadoLampara) ;    // escribimos el nuevo valor
      delay(500) ; //Para suavizar el rebote
    }
  if (estadoLampara == ON){
    if (digitalRead(ouRespaldoAdelante) == OF &&
          digitalRead(ouRespaldoAtras) == OF &&
          digitalRead(ouAsientoAbajo) == OF &&
          digitalRead(ouAsientoArriba) == OF){
        digitalWrite(ouLampara, ON) ;
    }
  }
}

void VerificarPulsadorVaso() {
  EstadoPinVaso=digitalRead(inVaso);    // Leer pin
  if (AnteriorEstadoPinVaso != EstadoPinVaso)   // Estado ha variado?
  {
    T_ControlVaso=millis()+T_ApagarVaso;        // Valor de millis para apagar
    digitalWrite (ouVaso, ON);          // Encender         
  }
  AnteriorEstadoPinVaso=EstadoPinVaso;
  if (millis()>T_ControlVaso && T_ControlVaso>0)// Finalizo el tiempo y lo estamos controlando?
  {
    digitalWrite (ouVaso, OF);          // Apagar
    T_ControlVaso=0;                        // Dejamos de controlar
  }
}

void VerificarPulsadorBacha() {
  EstadoPinBacha=digitalRead(inBacha);    // Leer pin
  if (AnteriorEstadoPinBacha != EstadoPinBacha)   // Estado ha variado?
  {
    T_ControlBacha=millis()+T_ApagarBacha;        // Valor de millis para apagar
    digitalWrite (ouBacha, ON);          // Encender         
  }
  AnteriorEstadoPinBacha=EstadoPinBacha;
  if (millis()>T_ControlBacha && T_ControlBacha>0)// Finalizo el tiempo y lo estamos controlando?
  {
    digitalWrite (ouBacha, OF);          // Apagar
    T_ControlBacha=0;                        // Dejamos de controlar
  }
}

