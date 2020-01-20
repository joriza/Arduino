#define ON HIGH                 // Cambiar para logica positiva/negativa
#define OF LOW                  // Cambiar para logica positiva/negativa

/*
Que solo funcione 1 cosa a la vez de las que consumen mucho
Tiempo de bacha y valor
Posicion cero, salida paciente


Los limites de carrera para seguridad
Efecto rebote en los botones
El agua carga por un tiempo determinado, que se pueda frenar.
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
const int ouRespaldoAtras = A0; //Direccion izquireda
const int ouRespaldoAdelante = A1; //Direccion derecha
const int ouAsientoArriba = A2;  
const int ouAsientoAbajo = A3;  
const int ouLampara = A4;  
const int ouVaso = A5;  

int valorPulsador = 0;  //variable intermedia para verificar si se oprimio un pulsador
bool estadoLampara = false ; //Estado de la iluminacion

//Definiciones para el manejo del vaso
unsigned long T_Control=0;      // Para controlar el tiempo consumido
unsigned long T_Apagar=3000;    // Tiempo de funcionamiento
bool EstadoPin=true; //Pulsador sin presionar           
bool AnteriorEstadoPin=true; //Pulsador sin presionar

void setup() {
  // Define los pines de entrada
  pinMode(inRespaldoAtras, INPUT_PULLUP); //Define 
  pinMode(inRespaldoAdelante, INPUT_PULLUP); 
  pinMode(inAsientoArriba, INPUT_PULLUP); 
  pinMode(inAsientoAbajo, INPUT_PULLUP); 
  pinMode(inLampara, INPUT_PULLUP); 
  pinMode(inVaso, INPUT_PULLUP); 
  // Define los pines de salida
  pinMode(ouRespaldoAtras, OUTPUT);
  pinMode(ouRespaldoAdelante, OUTPUT);
  pinMode(ouAsientoArriba, OUTPUT);
  pinMode(ouAsientoAbajo, OUTPUT);
  pinMode(ouLampara, OUTPUT);
  pinMode(ouVaso, OUTPUT);
  // incializamos estados necesarios
  digitalWrite(ouLampara , LOW) ; // Apagamos Luz al comenzar
  //digitalWrite(inVaso , ON) ; // Apagamos el vaso al comenzar
}

void loop() {
  VerificarPulsadorRespaldoAtras();
  VerificarPulsadorRespaldoAdelante();
  VerificarPulsadorAsientoArriba();
  VerificarPulsadorAsientoAbajo();
  VerificarPulsadorLampara();
  VerificarPulsadorVaso();

}

void VerificarPulsadorRespaldoAtras() {
  valorPulsador = digitalRead(inRespaldoAtras); //asignar estado del pulsador a una variable
 
  if (valorPulsador == HIGH) {   // High No pulsado
    digitalWrite(ouRespaldoAtras, LOW);
    digitalWrite(ouLampara, estadoLampara); //restaurar estado de lampara
  }
  else {
    if (estadoLampara == true) {
      digitalWrite(ouLampara, LOW); //apagar lampara porque estaba prendida
    }
    digitalWrite(ouRespaldoAtras, HIGH);
  }
}

void VerificarPulsadorRespaldoAdelante() {

  if (digitalRead(inRespaldoAdelante) == HIGH) {
      digitalWrite(ouRespaldoAdelante, LOW);
  }
  else {
      digitalWrite(ouRespaldoAdelante, HIGH);
  }
}

void VerificarPulsadorAsientoArriba() {
  if (digitalRead(inAsientoArriba) == HIGH) {
      digitalWrite(ouAsientoArriba, LOW);
  }
  else {
      digitalWrite(ouAsientoArriba, HIGH);
  }
}

void VerificarPulsadorAsientoAbajo() {
  if (digitalRead(inAsientoAbajo) == HIGH) {
      digitalWrite(ouAsientoAbajo, LOW);
  }
  else {
      digitalWrite(ouAsientoAbajo, HIGH);
  }
}

void VerificarPulsadorLampara() {
  bool  valor =  digitalRead(inLampara) ;  //leemos el botón pulsado: false  =  HIGH
  if ( valor == false )                    // esto es que han pulsado el botón
    {
      estadoLampara = ! estadoLampara ;                  // cambiamos el estado
      digitalWrite(ouLampara, estadoLampara) ;    // escribimos el nuevo valor
      delay(500) ; //Para suavizar el rebote
    }
}

void VerificarPulsadorVaso() {
  EstadoPin=digitalRead(inVaso);    // Leer pin
  if (AnteriorEstadoPin != EstadoPin)   // Estado ha variado?
  {
    T_Control=millis()+T_Apagar;        // Valor de millis para apagar
    digitalWrite (ouVaso, ON);          // Encender         
  }
  AnteriorEstadoPin=EstadoPin;
  if (millis()>T_Control && T_Control>0)// Finalizo el tiempo y lo estamos controlando?
  {
    digitalWrite (ouVaso, OF);          // Apagar
    T_Control=0;                        // Dejamos de controlar
  }
}

