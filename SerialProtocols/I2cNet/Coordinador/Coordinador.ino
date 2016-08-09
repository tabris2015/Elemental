#include <Wire.h>
// --- variables para la lectura serial
char inData[100];
char *inParse[100];
String inString = "";
int index = 0;
char datos[4] = {0,0,0,0};
int completo = 0;
// ----------------------------------
// --- variables para el i2c
int esclavoAct = 9;

boolean stringComplete = false;
void setup() 
{
  delay(6000);
  Serial.begin(9600);
  Wire.begin();
}
void loop() 
{
  if (stringComplete) 
  {
    ParseSerialData();
    inString = "";    
    stringComplete = false; 
  } 
}
void ParseSerialData()
{
  // The data to be parsed
  char *p = inData;
  // Temp store for each data chunk
  char *str;   
  // Id ref for each chunk 
  int count = 0;
  // Loop through the data and seperate it into
  // chunks at each "," delimeter
  while ((str = strtok_r(p, ",", &p)) != NULL)
  { 
    // Add chunk to array  
    inParse[count] = str;
    // Increment data count
    count++;      
  }
  if(count == 3)
  {
    // Define value 1 as a function identifier
    char *func = inParse[0];
    // Define value 2 as a property value
    char *pos = inParse[1];
    // Define value 3 as a period
    char *vel = inParse[2];
    
    // Call the relevant identified function  
    switch(*func)
    {
      case 'M': MoverMotor(pos,vel); break;
      //case 'V': Vertical(pos,vel); break;
      
    }    
  }
  if(count == 2)
  {
    // Define value 1 as a function identifier
    char *func = inParse[0];
    // Define value 2 as a property value
    char *dir = inParse[1];
    // Call the relevant identified function  
    switch(*func)
    {
      case 'S': SelEsclavo(dir); break;
    }    
  }
  if(count == 1)
  {
    // Define value 1 as a function identifier
    char *func = inParse[0];
    // Call the relevant identified function  
    switch(*func)
    {
      case 'L': LeerSensor(); break;
    }    
  }
}
void serialEvent() // **
{
  // Read while we have data
  while (Serial.available() && stringComplete == false) 
  {
    // Read a character
    char inChar = Serial.read(); 
    // Store it in char array
    inData[index] = inChar; 
    // Increment where to write next
    index++;     
    // Also add it to string storage just
    // in case, not used yet :)
    inString += inChar;
    
    // Check for termination character
    if (inChar == '\n') 
    {
      // Reset the index
      index = 0;
      // Set completion of read to true
      stringComplete = true;
    }
  }
}

