/*Código de programação do veículo Rover
 * Autores: Arlênio Souza e Pablo Vieira
 * Disciplina: Microprocessadores e Sistemas Embarcados
 * Professor: Lucas Frederico Jardim Meloni
 * 26/08/2024
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

int vel = 255; //valor de velocidade


#include <Dabble.h> //biblioteca para utilização do gamepad do app Dabble
#include <AFMotor.h>//biblioteca para utilziação do Driver Controlador para 4 Motores DC (ponte H) L293D

//Motores conectados às saídas M3 e M4 DIANTEIROS
AF_DCMotor motor3(3);  // Motores frente esquerdo conectados à saída M3
AF_DCMotor motor4(4);  // Motores frente direito  conectados à saída M4

//Motores conectados às saídas M1 e M2 TRASEIROS
AF_DCMotor motor1(1);  // Motores frente esquerdo conectados à saída M1
AF_DCMotor motor2(2);  // Motores frente direito  conectados à saída M2
void setup() {
  Serial.begin(9600);      //Serial para o PC.
  Dabble.begin(9600);      //Serial para o módulo. 
}

void loop() {
  Dabble.processInput(); // Atualiza os dados do Gamepad   
  
  if (GamePad.isUpPressed()){//1ª camada de IF's ir P/FRENTE
      motor3.setSpeed(vel); 
      motor4.setSpeed(vel); 
      motor3.run(FORWARD); //frente esquerdo
      motor4.run(FORWARD); //frente direito
      motor1.setSpeed(vel); 
      motor2.setSpeed(vel);
      motor1.run(FORWARD); //atrás esquerdo
      motor2.run(FORWARD); //atrás direito
      }
  else {//fim da 1ª camada
    if (GamePad.isDownPressed()) {//2ª camada de IF's ir P/TRÁS
        motor3.setSpeed(vel); 
        motor4.setSpeed(vel); 
        motor3.run(BACKWARD); //frente esquerdo
        motor4.run(BACKWARD); //frente direito
        motor1.setSpeed(vel); 
        motor2.setSpeed(vel);
        motor1.run(BACKWARD); //atrás esquerdo
        motor2.run(BACKWARD); //atrás direito
        }
     else{//fim da 2ª camada
        if (GamePad.isRightPressed()) {//3ª camada de IF's ir P/ DIREITA
            motor3.setSpeed(vel); 
            motor4.setSpeed(vel); 
            motor3.run(FORWARD); //frente esquerdo
            motor4.run(BACKWARD); //frente direito
            motor1.setSpeed(vel); 
            motor2.setSpeed(vel);
            motor1.run(FORWARD); //atrás esquerdo
            motor2.run(BACKWARD); //atrás direito
            }
        else{//fim da 3ª camada
          if (GamePad.isLeftPressed()) {//4ª camada de IF's ir P/ ESQUERDA
              motor3.setSpeed(vel); 
              motor4.setSpeed(vel); 
              motor3.run(BACKWARD); //frente esquerdo
              motor4.run(FORWARD); //frente direito
              motor1.setSpeed(vel); 
              motor2.setSpeed(vel);
              motor1.run(BACKWARD); //atrás esquerdo
              motor2.run(FORWARD); //atrás direito
              }
           else{ //fim da 4ª camada
              if (GamePad.isCrossPressed()) {//5ª camada de IF's P/ SUBIR OBSTACULO 
                motor3.setSpeed(vel); 
                motor4.setSpeed(vel); 
                motor3.run(FORWARD); //frente esquerdo
                motor4.run(FORWARD); //frente direito
                motor1.setSpeed(vel/1.5); 
                motor2.setSpeed(vel/1.5);
                motor1.run(FORWARD); //atrás esquerdo
                motor2.run(FORWARD); //atrás direito
                }
              else{//fim da 5ª camada
                if (GamePad.isCirclePressed()) {//6ª camada de IF's P/ DESCER OBSTACULO 
                  motor3.setSpeed(vel); 
                  motor4.setSpeed(vel); 
                  motor3.run(BACKWARD); //frente esquerdo
                  motor4.run(BACKWARD); //frente direito
                  motor1.setSpeed(vel/1.5); 
                  motor2.setSpeed(vel/1.5);
                  motor1.run(BACKWARD); //atrás esquerdo
                  motor2.run(BACKWARD); //atrás direito
                  }
                  else{//fim da 6ª camada
                          motor3.run(RELEASE);
                          motor4.run(RELEASE);
                          motor1.run(RELEASE);
                          motor2.run(RELEASE);
                          delay(200);
                  }//6ª camada
                }//5ª camada
            }//4ª camada
        }//3ª camada
    }//2ª camada
  }//1ª camada
   
}//void loop
