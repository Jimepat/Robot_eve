#include <Arduino.h>

// Bluetooth  
#define led_1 13 //No hace falta conectar otro 
#define led_2 12 //Enciende el Buz 

void setup() {
  pinMode(led_1,OUTPUT);  
  pinMode(led_2,OUTPUT);  
  // Inicializar comunicación serial con PC
  Serial.begin(9600);
  Serial.println("Inicializando módulo HC-10...");

  // Inicializar comunicación serial con módulo HC-10 usando Serial1
  Serial1.begin(9600);
  delay(1000);
  Serial.println("Módulo HC-10 listo para comunicarse.");
}

void loop() {
  // Enviar datos desde Serial Monitor al módulo Bluetooth
  if (Serial.available()) {
    char data = Serial.read();
    Serial1.write(data);
  }

  // Leer datos desde el módulo Bluetooth y enviarlos al Serial Monitor
  if (Serial1.available()) {
    char data = Serial1.read();
    if(data == 'a')
    {
        digitalWrite(led_1,HIGH);
    }
    if(data == 'b')
    {
        digitalWrite(led_1,LOW);
    }
    Serial.write(data);
  }
}
