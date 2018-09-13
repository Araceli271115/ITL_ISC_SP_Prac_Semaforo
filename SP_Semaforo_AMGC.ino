/*Ingeniería en Sistemas Computacionales, Sistemas Programables, Araceli Marlen Guzmán Cáceres, Práctica Semáforo  para un cruce peatonal */
#define led_verde 13                //definimos las variables y los pines en los que se encuentran
#define led_amarillo 11
#define led_rojo 9
#define led_verde_peaton 12
#define led_rojo_peaton 8
#define boton_1 7
#define pot_1 A8
#define bocina 2

int valor_pot=0;                    //inicializamos el valor del potenciometro en 0
boolean valor_boton_1=HIGH;          //inicializamos el boton como precionado

void setup() {
  Serial.begin(9600);             //inicializar el puerto serie
  pinMode (led_verde, OUTPUT);    //pone al pin para el led verde en modo salida
  pinMode (led_amarillo, OUTPUT); //pone al pin para el led amarillo en modo salida
  pinMode (led_rojo, OUTPUT);     //pone al pin para el led rojo en modo salida
  pinMode (boton_1,INPUT);        //pone al pin para el boton en modo entrada
}

void loop() {
     valor_pot=analogRead(pot_1);  //asigna a valor_pot el valor que se este leyendo del potenciometro
    digitalWrite(led_verde,HIGH);   //enciende el led verde
    digitalWrite(led_rojo_peaton,HIGH);
   while(digitalRead(boton_1)==LOW){   //asigana a valor_boton_1 como precionado mientras se pulse el boton
    valor_boton_1=LOW;
   }
    if(valor_boton_1==LOW){          //hasta que que el boton cambie a low
    digitalWrite(led_verde,LOW);           //se apaga led verde
    delay(1000);                           //se da un tiempo de espera de transicion
    digitalWrite(led_amarillo,HIGH);       //se prende el led amarillo 
    delay(2000);                           //se da un tiempo en el que el led amarillo estará encendido
    digitalWrite(led_amarillo,LOW);        //se apaga el led amarillo
    delay(2000);                           //tiempo de espera de transicion entre led amarillo y rojo
    tone(bocina,valor_pot*10);                //se prende el tono de la bocina  con una frecuencia que este pasando el potenciometro 
    digitalWrite(led_rojo,HIGH);           //se enciende el led rojo 
    digitalWrite(led_rojo_peaton,LOW);      //se apaga led rojo de peatones para que pueda prender el verde y cruzar
    digitalWrite(led_verde_peaton,HIGH);     //prende led verde para peatones
    
    delay(4000);                           //tiempo en el que el led rojo estara encendido
    digitalWrite(led_rojo,LOW);            //se apaga el led rojo
    digitalWrite(led_verde_peaton,LOW);     //se apaga el led verde para cruce de peatones
    noTone(bocina);                        //se apaga el tono de la bocina
    delay(2000);

      digitalWrite(led_verde,HIGH);           //Enciende el led verde para coches
      digitalWrite(led_rojo_peaton,HIGH);     //Enciende el led rojo de peatones
      delay(valor_pot*8);                    //tiempo de espera para que no pueda precionar el boton hasta que haya pasado un tiempo predeterminado
      valor_boton_1=HIGH;                     //cambia el valor del boton a no presionado
   }
  
  
   

}
