/**
 * Basic Stuff:
 *  Plan on using an Adafruit LCD with keys backpack for the time being for the control interface.
 *  Use a loop like they do in the Adafruit Sous Viduino
 *   http://learn.adafruit.com/sous-vide-powered-by-arduino-the-sous-viduino/the-whole-enchilada
 *  use SerialEventX() to handle the input from the probes.
 *  Might have to use a custom one instead so that we can turn it off for the Calibration routines
 *  using SerialEvent() is called at the end of a loop() so I guess we could just do a if (_CALIBRATION_) in that block to bypass.
 *  That assumes that we can get the calibration routines worked in as well.  Might be a PITA depending on how it's done.
 *  Can you temporarily turn that off so you could do a 
/**
 * Serial 0 - TX=1 RX=0
 * Serial 1 - TX=18 RX=19
 * Serial 2 - TX=16 RX=17
 * Serial 3 - TX=14 RX=15
 */

String inputstring = "";
String sensorstring = "";
boolean input_stringcomplete = false;
boolean sensor_stringcomplete = false;

void setup(){
  Serial.begin(38400);
  Serial3.begin(38400);
  inputstring.reserve(5);


  sensorstring.reserve(30);
}

void serialEvent() {
  char inchar = (char)
  Serial.read();
  inputstring += inchar;
  if(inchar == '\r') {input_stringcomplete = true;}   
}

void serialEvent3(){
  char inchar = (char)Serial3.read();
  sensorstring += inchar;
  if(inchar == '\r') {sensor_stringcomplete = true;}
}  


void loop(){   //here we go....
  if (input_stringcomplete){
    Serial3.print(inputstring);
    inputstring = "";
    input_stringcomplete = false;
  }     

  if (sensor_stringcomplete){
    Serial.println(sensorstring);
    sensorstring = "";
    sensor_stringcomplete = false;
  }     
}