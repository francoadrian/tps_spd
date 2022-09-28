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
int segundosAntes = millis()-1;
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
    delayConMillis(50);
    }
  }

    //led 1 se prende por segundo
    encenderLed(4, 2, 0, cronometro);
    //led 2 se prende cada 2 segundos
    encenderLed(5, 4, 1, cronometro);
    //led 3 cada 4 segs
    encenderLed(6, 8, 3, cronometro);
    //led 4 cada 8 segs
    encenderLed(7, 16, 7, cronometro);
    //led 5 cada 16 segs
    encenderLed(8, 32, 15, cronometro);
    //led 6 cada 32 segs
    encenderLed(9, 64, 31, cronometro);
    //led 7 cada 64 segs
    encenderLed(10, 128, 63, cronometro);
    //led 8 cada 128 segs
    encenderLed(11, 256, 127, cronometro);
    //led 9 cada 256 segs
    encenderLed(12, 512, 255, cronometro);
    //led 10 cada 512 segs
    encenderLed(13, 1024, 511, cronometro);

  estadoBotonAnterior = botonAhora;

  delayConMillis(50);
}


/**
 * @fn void encenderLed(int, int, int, int)
 * @brief enciende el led indicado con la frecuencia correspondiente al resultado del resto entre el cronómetro y el número parametrizado
 * 
 * @param numeroLed numero de led a encender o apagar
 * @param resto	numero al que calcular el resto
 * @param menorA numero que define cuándo, tras calcular el resto, se encenderá o apagará el led
 * @param cronometro variable de cronometro a la que se le calcula el resto
 */
void encenderLed(int numeroLed, int resto, int menorA, int cronometro){
	  if(cronometro % resto > menorA){
	      digitalWrite(numeroLed, HIGH);
	    }else{
	      digitalWrite(numeroLed, LOW);
	    }
  }

/**
 * @fn void delayConMillis(int)
 * @brief permite generar un delay pero utilizando la función millis en su lugar
 * 
 * @param cantidad tiempo de delay en milisegundos 
 */
void delayConMillis(int cantidad){
	   int millisUno = millis();
	   int millisDos = millisUno;
	   while(millisDos-millisUno < 50){
	    	millisDos=millis();
		}
}
