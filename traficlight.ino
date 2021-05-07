int GREEN = D2;
int RED = D5;
int BLUE = D3;

// Last time, we only needed to declare pins in the setup function.
// This time, we are also going to register our Particle function

void setup()
{

   // Here's the pin configuration, same as last time
   pinMode(GREEN, OUTPUT);
   pinMode(RED, OUTPUT);
   pinMode(BLUE, OUTPUT);

   // We are also going to declare a Particle.function so that we can turn the LED on and off from the cloud.
   Particle.function("led",ledToggle);
   // This is saying that when we ask the cloud for the function "led", it will employ the function ledToggle() from this app.

   // For good measure, let's also make sure both LEDs are off when we start:
   digitalWrite(GREEN, LOW);
   digitalWrite(RED, LOW);
   digitalWrite(BLUE, LOW);

}


void loop()
{
   // Nothing to do here
}
int ledToggle(String command) {
    if (command=="GREEN") {
        digitalWrite(GREEN,HIGH);
        digitalWrite(RED,LOW);
        digitalWrite(BLUE,LOW);
        return 1;
    }
    if (command=="RED") {
        digitalWrite(GREEN,LOW);
        digitalWrite(RED,HIGH);
        digitalWrite(BLUE,LOW);
        return 1;
    }
    if (command=="BLUE") {
        digitalWrite(GREEN,LOW);
        digitalWrite(RED,LOW);
        digitalWrite(BLUE,HIGH);
        return 1;
    }
    if (command=="OFF") {
        digitalWrite(GREEN,LOW);
        digitalWrite(RED,LOW);
        digitalWrite(BLUE,LOW);
        return 1;
    }
    else{
        return -1;
    }
}


