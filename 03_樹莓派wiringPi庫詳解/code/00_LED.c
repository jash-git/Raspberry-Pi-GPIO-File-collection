#include<iostream>
#include<cstdlib>
#include<wiringPi.h>   

const int LEDpin = 1;

int main()
{
      if(-1==wiringPiSetup())
      {
             cerr<<"setup error\n";
             exit(-1);
      }
      pinMode(LEDpin,OUTPUT);      


      for(size_t i=0;i<10;++i)
      {
                digitalWrite(LEDpin,HIGH); 
                delay(600);
                digitalWrite(LEDpin,LOW);
                delay(600);
   
      }
        
      cout<<"------------bye-------------"<<endl;
      return 0;   
}