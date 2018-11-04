int estado = 0;
int salida = 0;
boolean bandera = false;

int estadoAnterior = 0;

void setup() {
  pinMode(8, INPUT);  //Aqui configuramos el pin 8 del arduino como entrada (boton)
  pinMode(2, OUTPUT); //Aqui configuramos el pin 4 del arduuino como salida (led 1)
  pinMode(4, OUTPUT); //Aqui configuramos el pin 5 del arduuino como salida (led 2)
}

void loop() {
  estado = digitalRead(8); //Aqui la funcion digitalRead(8) es el escuchador de evento que lee el estado del boton,(la mayor parte del tiempo lo que lee es un LOW porque el boton no esta oprimido, cuando lea un HIGH es porque el boton se oprimio).

  if((estado == HIGH) && (estadoAnterior == LOW)){ //Aqui basicamente pregunta si el boton se oprimio, (si la variable estado es igual a HIGH)
    salida = 1 - salida;
    bandera = true;
    delay(25);
  }
    estadoAnterior = estado;

  if(salida == 1){ //si la variable salida es igual a 1  entonces switcheamos
    digitalWrite(2, HIGH); // led 1 encendido
    digitalWrite(4, LOW); // led 2 apagado
  }

  else if((salida == 0) && (bandera == true)){ //si la variable salida es igual a 0 Y la variable bandera es igual a true  entonces switcheamos.
    digitalWrite(4, HIGH); //led 1 apagado
    digitalWrite(2, LOW); //led 2 encendido
  }

  
}
