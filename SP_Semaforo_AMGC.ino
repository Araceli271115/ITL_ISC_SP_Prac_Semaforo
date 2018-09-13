/*Ingeniería en Sistemas Computacionales, Sistemas Programables, Araceli Marlen Guzmán Cáceres, Práctica Semáforo  para un cruce peatonal */
#define led_verde 13                //definimos las variables y los pines en los que se encuentran
#define led_amarillo 11
#define led_rojo 9
#define boton_1 7

void setup() {
  Serial.begin(9600);             //inicializar el puerto serie
  pinMode (led_verde, OUTPUT);    //pone al pin para el led verde en modo salida
  pinMode (led_amarillo, OUTPUT); //pone al pin para el led amarillo en modo salida
  pinMode (led_rojo, OUTPUT);     //pone al pin para el led rojo en modo salida
    pinMode (boton_1,INPUT);        //pone al pin para el boton en modo entrada
}
void loop() {
  digitalWrite(led_verde,HIGH);   //se aprende led Verde
   if(digitalRead(boton_1)==LOW){      //hasta que que el boton cambie a low
    digitalWrite(led_verde,LOW);    //se apaga led verde
    delay(1000);                                    //se da un tiempo de espera de transicion
    digitalWrite(led_amarillo,HIGH);      //se prende el led amarillo 
    delay(2000);                                       //se da un tiempo en el que el led amarillo estará encendido
    digitalWrite(led_amarillo,LOW);     //se apaga el led amarillo
    delay(2000);                                         //tiempo de espera de transicion entre led amarillo y rojo
    digitalWrite(led_rojo,HIGH);              //se enciende el led rojo 
    delay(4000);                                        //tiempo en el que el led rojo estara encendido
    digitalWrite(led_rojo,LOW);             //se apaga el led rojo
    delay(2000);
    
   }

}
