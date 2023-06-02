#include <SD.h>               // need to include the SD library
#define SD_ChipSelectPin 10   //pin10 for Arduino Pro Mini
#include <TMRpcm.h>           //  Lib to play wav file
#include <SPI.h>

#include <SoftwareSerial.h>
SoftwareSerial QA(6, 7);
#include <JRCCAR.h>
JRCCAR car(2, 3, 4, 5);

TMRpcm tmrpcm;  

int loopcycle = 1 ;
int runstate = 1;
int data;

void setup(){
  car.PinSetup();
  tmrpcm.speakerPin = 9; 
  Serial.begin(9600);
  QA.begin(9600);

  if (!SD.begin(SD_ChipSelectPin)) {  
    Serial.println("SD fail");  
    return; 
  }
  else{   
    Serial.println("SD ok");   
  }
  
  tmrpcm.volume(2); 
}

void loop(){

if (QA.available() > 0) {
     data = QA.read();
    Serial.println(data);
  }

  Serial.println(data);
  Serial.println(runstate);

  if(runstate == 1 && data == 8){

    car.forward();
    delay(2000);
    car.stop();

    tmrpcm.play("maingate.wav"); 
    while (tmrpcm.isPlaying()) {}

    delay(5000);
    runstate = 2;
    data = 0;
    
    
  }
    if(runstate == 2 && data == 8){
    car.forward();
    delay(2000);
    
        car.stop();

    tmrpcm.play("admin.wav"); 
    while (tmrpcm.isPlaying()) {}

    delay(5000);
        runstate = 3;
        data = 0;

    }
      if(runstate == 3 && data == 8){
    car.forward();
    delay(2000);
        car.stop();

    tmrpcm.play("hadi.wav"); 
    while (tmrpcm.isPlaying()) {}

    delay(5000);
      
    turnhadi();
            car.stop();

        runstate = 4;
        data = 0;

}      if(runstate == 4 && data == 8){


    car.forward();
    delay(2000);
        car.stop();

    tmrpcm.play("cafe.wav"); 
    while (tmrpcm.isPlaying()) {}

    delay(5000);
        runstate = 5;
        data = 0;

}
      if(runstate == 5 && data == 8){


    
    car.forward();
    delay(2000);
        car.stop();
            runstate = 0;
            data = 0;

      }

    if(data == 1)
    {
          tmrpcm.play("Q1ans.wav"); 
              while (tmrpcm.isPlaying()) {}

    }

     if(data == 2)
    {
          tmrpcm.play("Q2ans.wav"); 
              while (tmrpcm.isPlaying()) {}


    }

         if(data == 4)
    {
          tmrpcm.play("Q3ans.wav"); 
              while (tmrpcm.isPlaying()) {}


    }

         if(data == 3)
    {
          tmrpcm.play("Q4ans.wav"); 
              while (tmrpcm.isPlaying()) {}


    }

    


    data = 0;


}


void turnhadi()
{
  
      car.forward();
      delay(500);

      
      car.left();
      delay(500);

      car.forward();
      delay(500);

      car.left();
      delay(500);
        car.stop();


  
  
}
