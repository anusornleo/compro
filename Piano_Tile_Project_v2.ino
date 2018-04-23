#include <Servo.h>

// call the all of LDR
int ldr0 = 0;
int ldr1 = 1;
int ldr2 = 2;
int ldr3 = 3;

// call all of servo
Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;

// call all of button
const int  button_start_game = 5;
const int  button_start_encryp = 6;
const int  button_stop_all = 7;

//state of button
int start_game = 0;
int start_encryp = 0;

// call othor varable
/*int a = 0; // count the encrypt to 3
int t_encrytp = 950; // delay for encrypt
int data[3]; //
int input[3]; //
int num = 0; //
int let[27][3] = {{1,2,1},{1,2,3},{1,2,4},{1,3,1},
                  {1,3,2},{1,3,4},{1,4,1},{1,4,2},
                  {1,4,3},{2,1,2},{2,1,3},{2,1,4},
                  {2,3,1},{2,3,2},{2,3,4},{2,4,1},
                  {2,4,2},{2,4,3},{3,1,2},{3,1,3},
                  {3,1,4},{3,2,1},{3,2,3},{3,2,4},
                  {4,1,2},{4,1,3},{4,1,4}};
char letter[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
/*=========================================================================*/

void setup()
{
  // call port servo
  servo0.attach(8);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  
  // set Default servo
  servo0.write(65);
  servo1.write(68);
  servo2.write(100);
  servo3.write(90);
  
  // set button as input
  pinMode(button_start_game, INPUT);
  pinMode(button_start_encryp, INPUT);
  pinMode(button_stop_all, INPUT);
}
/*============================================================================*/
void loop()
{
  // when you press putton [set the button]
  if (digitalRead(button_start_game) == HIGH){
    if (start_game == 0){
      start_game = 1;
    }
  }
  else if (digitalRead(button_start_encryp) == HIGH){
    if (start_encryp = 0){
      start_encryp = 1;
    }
  }
  //this button can stop all mode
  else if (digitalRead(button_stop_all) == HIGH){
    if (start_game == 1 || start_encryp == 1){
      start_game = 0;
      start_encryp = 0;
    }
  }
  //mode game
  if (start_game == 1){
    game_mode();
  }
  else if (start_encryp == 1){
    encryp_mode();
  }
  else if (start_game == 0 || start_encryp == 0){
    wait_mode();
  }
}
/*===========================================================================*/

// Game Mode
void game_mode()
{
  servo0.write(65);
  servo1.write(68);
  servo2.write(100);
  servo3.write(90);
  if (analogRead(ldr0) > 500){
    servo0.write(78);
    delay(150);
    servo0.write(65);
    delay(150);
    /*if (analogRead(ldr0) <= 400){
      servo0.write(110);
      delay(200);
    }*/
  }
  
  else if  (analogRead(ldr1) > 500){
    servo1.write(57);
    delay(150);
    servo1.write(68);
    delay(150);
    /*if (analogRead(ldr1) <= 400){
      servo1.write(68);
      delay(200);
    }*/
  }
  
  else if (analogRead(ldr2) > 500){
    servo2.write(117);
    delay(150);
    servo2.write(100);
    delay(150);
    /*if (analogRead(ldr2) <= 440){
      servo2.write(100);
      delay(200);
    }*/
  }
  else if (analogRead(ldr3) > 500){
    servo3.write(72);
    delay(150);
    servo3.write(90);
    delay(150);
    /*if (analogRead(ldr3) <= 500){
      servo3.write(90);
      delay(200);
    }*/
  }
}
/*=============================================================================*/
void encryp_mode(){
  int a = 0; // count the encrypt to 3
  int t_encrytp = 950; // delay for encrypt
  int data[3]; //
  int input[3]; //
  int num = 0; //
  int let[27][3] = {{1,2,1},{1,2,3},{1,2,4},{1,3,1},
                    {1,3,2},{1,3,4},{1,4,1},{1,4,2},
                    {1,4,3},{2,1,2},{2,1,3},{2,1,4},
                    {2,3,1},{2,3,2},{2,3,4},{2,4,1},
                    {2,4,2},{2,4,3},{3,1,2},{3,1,3},
                    {3,1,4},{3,2,1},{3,2,3},{3,2,4},
                    {4,1,2},{4,1,3},{4,1,4}};
  char letter[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
  a = a+1;
  if (analogRead(ldr0) > 500){
    data[a] = 1;
    delay(t_encrytp);
  }
  else if (analogRead(ldr1) > 500){
    data[a] = 2;
    delay(t_encrytp);
  }
  else if (analogRead(ldr2) > 500){
    data[a] = 3;
    delay(t_encrytp);
  }
  else if (analogRead(ldr3) > 500){
    data[a] = 4;
    delay(t_encrytp);
  }
  if (a == 3){
    for (int i=0;i<26;i++){
      int count = 0;
      for (int j=0;j<3;j++){
        if (data[j] == let[i][j]){
          count += 1;
        }
      }
      if (count == 3){
        printf("%c",letter[num]);
      }
      else{
        num+=1;
      }
    }
  }
}
/*===========================================================================*/
void wait_mode(){
  servo0.write(65);
  servo1.write(68);
  servo2.write(100);
  servo3.write(90);
}

