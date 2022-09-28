#define BTN_PAUSA 3
#define BTN_REINICIO 2

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(BTN_PAUSA, INPUT_PULLUP);	
  pinMode(BTN_REINICIO, INPUT_PULLUP);	
}

int segundos;
int cronometro = 0;
int estadoBotonAnterior = LOW;
int segundosAntes = -1;
int estadoCircuito;

void loop()
{
  segundos = millis()/1000;
  int botonAhora;
  botonAhora = digitalRead(BTN_PAUSA);
  if(botonAhora == 1 && estadoBotonAnterior == LOW){
    estadoCircuito = HIGH;
  }else{
    if(botonAhora == 1 && estadoCircuito == HIGH){
      estadoCircuito = LOW;
    }
  }
  
  if(digitalRead(BTN_REINICIO) == 1){
  cronometro = 0;
  }
  
  if(estadoCircuito == HIGH){
  if(segundos != segundosAntes){
    cronometro = cronometro + 1;
    segundosAntes = segundos;
	//delay(50);
    int millisUno = millis();
    int millisDos = millisUno;
    while(millisDos-millisUno < 500){
    	millisDos=millis();
    }
    }
  }
  
  //led 1 se prende por segundo
    if(cronometro % 2 == 1){
      digitalWrite(4, HIGH);
    }else{
      digitalWrite(4, LOW);
    }

    //led 2 se prende cada 2 segundos
    if(cronometro % 4 > 1){
      digitalWrite(5, HIGH);
    }else{
      digitalWrite(5, LOW);
    }

    //led 3 cada 4 segs
    if(cronometro % 8 > 3){
      digitalWrite(6, HIGH);
    }else{
      digitalWrite(6, LOW);
    }

    //led 4 cada 8 segs
    if(cronometro % 16 > 7){
      digitalWrite(7, HIGH);
    }else{
      digitalWrite(7, LOW);
    }

    //led 5 cada 16 segs
    if(cronometro % 32 > 15){
      digitalWrite(8, HIGH);
    }else{
      digitalWrite(8, LOW);
    }

    //led 6 cada 32 segs
    if(cronometro % 64 > 31){
      digitalWrite(9, HIGH);
    }else{
      digitalWrite(9, LOW);
    }

    //led 7 cada 64 segs
    if(cronometro % 128 > 63){
      digitalWrite(10, HIGH);
    }else{
      digitalWrite(10, LOW);
    }

    //led 8 cada 128 segs
    if(cronometro % 256 > 127){
      digitalWrite(11, HIGH);
    }else{
      digitalWrite(11, LOW);
    }  

    //led 9 cada 256 segs
    if(cronometro % 512 > 255){
      digitalWrite(12, HIGH);
    }else{
      digitalWrite(12, LOW);
    }

    //led 10 cada 512 segs
    if(cronometro % 1024 > 511){
      digitalWrite(13, HIGH);
    }else{
      digitalWrite(13, LOW);
    }
  
  estadoBotonAnterior = botonAhora;
  
  //delay(50);
   int millisUno = millis();
   int millisDos = millisUno;
   while(millisDos-millisUno < 50){
    	millisDos=millis();
	}
}
