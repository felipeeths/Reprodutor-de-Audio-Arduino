/* Algoritmo de reprodução de Audio no arduino
  Desenvolvido por Felipe Ferreira.
  Componentes utilizadados: Arduino
                            Shield Ethernet = para utilizar o cartão SD
                            1 Led
                            2 Botões
                            Saida de Audio
                            2 Resistores de 10k
                            1 de 220k -> LED

*/

#include <SimpleSDAudio.h>

const int StartPortuguese = 8;
const int StartEnglish = 6;
const int StartEspanish = 5;
const int Stop = 7;
const int Led = 13;
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

void setup() {

  Serial.begin(9600);
  pinMode(Led, OUTPUT);
}

void loop() {
  buttonState1 = digitalRead(StartPortuguese);
  buttonState2 = digitalRead(StartEnglish);
  buttonState3 = digitalRead(StartEspanish);
     
  if(buttonState1 == HIGH){ //portugues
    SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
    SdPlay.setFile("roda2.afm");
    SdPlay.play();
    while(!SdPlay.isStopped()){
      buttonState4 = digitalRead(Stop);
      if(buttonState4 == HIGH){
        SdPlay.stop();
        buttonState1 = LOW;
        break;
      }
    }
    SdPlay.deInit();
  }
  if(buttonState2 == HIGH){ //english
    SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
    SdPlay.setFile("roda1e1.afm");
    SdPlay.play();
    while(!SdPlay.isStopped()){
      buttonState4 = digitalRead(Stop);
      if(buttonState4 == HIGH){
        SdPlay.stop();
        buttonState2 = LOW;
        break;
      }
    }
    SdPlay.deInit();
  }
    if(buttonState3 == HIGH){ //spanish
    SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);
    SdPlay.setFile("roda3.afm");
    SdPlay.play();
    while(!SdPlay.isStopped()){
      buttonState4 = digitalRead(Stop);
      if(buttonState4 == HIGH){
        SdPlay.stop();
        buttonState3 = LOW;
        break;
      }
    }
    SdPlay.deInit();
  }
}                               
