/*
 * Interface LDR with NodeMCU
 * By TheCircuit
 * https://www.instructables.com/id/Auto-LED-Using-LDR-With-NodeMCU/
 */
#define ledPin  5  //D1----GPIO5
#define ldrPin  A0

void setup() {

Serial.begin(115200);

pinMode(ledPin, OUTPUT);

pinMode(ldrPin, INPUT);

}

void loop() {
 // faz a leitura analogical do pino 0:
int ldrStatus = analogRead(ldrPin);
 // faz a leitura analogical do pino 0:
int sensorValue = analogRead(ldrPin);
// Converte a leitura analógica (que vai de 0 - 1023) para um valor de tensão (0 - 5V):
float voltage = sensorValue * (5.0 / 1023.0);

 //----valor ajustado conforme a luz do dia e noite
 //---valor da tensao durante o dia foi de +- 3.0v (560) a noite foi 4.2v (870)

 //---VALOR DO LDR ANOTA DURANTE A NOITE DEPOIS DAS 19HS---830 analog RAW
if (ldrStatus >=800) {
   delay(200000); // APROXIMADAMENTE 3 MINUTOS DE ESPARA PARA ACENDER A LAMPADA
digitalWrite(ledPin, HIGH);

//----------DESCOMENTAR PARA VISUALIZAR NO MONITOR SERIAL
/*
Serial.println("VALOR---A0");
Serial.println(ldrStatus);
Serial.println("VALOR--VOLTS----A0");
 // escreve o valor de tensão via comunicação serial:
Serial.println(voltage);
 delay(1000);
Serial.println("NOITE, RELAY LIGADO");
*/
}


else 
{

digitalWrite(ledPin, LOW);
//----------DESCOMENTAR PARA VISUALIZAR NO MONITOR SERIAL
/*
Serial.println(ldrStatus);
Serial.println("VALOR--VOLTS----A0");
 // escreve o valor de tensão via comunicação serial:
Serial.println(voltage);
 delay(1000);
Serial.println("DIA---RELAY DESLIGADO");
*/
}

}
