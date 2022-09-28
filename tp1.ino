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
int estadoAntes = LOW;

void loop()
{
	segundos = millis()/1000;
  	int circuitoActivo = 0; // 0 = false 1 = true
  
  	int estadoAhora = digitalRead(BTN_PAUSA);  
	Serial.println(estadoAhora);
	if(estadoAhora == 1 && estadoAntes == LOW){
      circuitoActivo = 1;
    }
  	if(estadoAhora == 1 && estadoAntes == HIGH){
      circuitoActivo = 0;
    }
  	
  if(circuitoActivo == 1){
		if(segundos % 2 == 1){
			digitalWrite(4, HIGH);
        }else{
			digitalWrite(4, LOW);
		}
    }
	
  estadoAntes = estadoAhora;
  delay(50);
}
/* boton muestra 0, cuando lo pulso 
(mientras lo pulse) muestra 1*/

  
  
  
  
  
  
  
  
  
/*
  
*/