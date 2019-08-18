

   #define RED 10                   // Define Digital Pin Number 10 as RED of Nano for Red Alert (stop) LED 
   #define GREEN 9                  // Define Digital Pin Number 9 as GREEN of Nano for Green Alert (go/move) LED 
   #define BUZZER 8                 // Define Digital Pin Number 8 as BUZZER of Nano for Sound (Alert)  


   const int trigPin = 3;           // Fixed Digital Pin Number 3 for sonar trig  
   const int echoPin = 2 ;          // Fixed Digital Pin Number 2 for sonar echo
   const int ButtonPin = 5;         // Fixed Digital Pin Number 5 as a pushbutton pin
   
   long duration;      // time duration for sonar 
   int distance;       // distance calculation for sonar
   int sound =1000;    // sound level

   // variables will change
   int ButtonState = 0;  // variable for reading the pushbutton status


    void setup()
  {
    
     pinMode(trigPin, OUTPUT);      // Sets the trigPinas an Output
     pinMode(echoPin, INPUT);      // Sets the echoPinas an Input
     pinMode(RED,OUTPUT);          // sets the digital pin as output
     pinMode(GREEN,OUTPUT);        // sets the digital pin as output
 
     pinMode(BUZZER, OUTPUT);

     pinMode(ButtonPin, INPUT);     // Read the state of the pushbutton value

     
     Serial.begin(9600);         // Begins Serial Communication

     
  }


    void loop()
  {
    
    digitalWrite(trigPin, LOW);    // Clears the trigPin
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);   // sets the trigPinon HIGH state for 10 micro seconds 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);     // Reads the echoPin, returns the sound wave travel time in microseconds 
    distance = duration*0.034/2;           // Calculating the distance

    ButtonState = digitalRead(ButtonPin);
  

     
    
  
        if (distance >= 0 &&  distance <=50 )
       {
      
          digitalWrite(RED, HIGH); // Sets the RED LED on
          digitalWrite(GREEN, LOW); // Sets the GREEN LED off
          sound = 1000 ;

          tone(BUZZER, sound); 
        
          Serial.print("Distance : ");
          Serial.print(distance);
          Serial.println(" cm");
          Serial.println("Obstacle.Please Stop\n");
        
          delay(150);
          noTone(BUZZER);

        }


       else
      {
      
         
          digitalWrite(RED, LOW);     // Sets the RED LED Off 
          noTone(BUZZER);


            if (ButtonState == HIGH) 
           {
              digitalWrite(RED, HIGH);          // Turn RED LED On
              digitalWrite(GREEN, LOW);         // Sets the GREEN LED Off
        
              sound = 1500 ;

              tone(BUZZER, sound); 
              delay(120);

              Serial.println("SWITCH ON");
         
              Serial.print("Distance : ");
              Serial.print(distance);
              Serial.println(" cm");
              Serial.println("Excuse me,give me space and stop Please.\n");
         
              noTone(BUZZER);
        
            }

             else 
            {

                digitalWrite(GREEN, HIGH);  // Sets the GREEN LED On
                digitalWrite(RED, LOW);     // Sets the RED LED Off
                delay(500);

                sound = 200 ;
                tone(BUZZER, sound);
               
                digitalWrite(GREEN, LOW);  // Sets the GREEN LED Off

                Serial.println("SWITCH OFF");
       
                Serial.print("Distance : ");
                Serial.print(distance);
                Serial.println(" cm");
                Serial.println("Go Ahead\n");
      
                noTone(BUZZER);
        
             }
      
    }
   
    delay(1000);

    
}
