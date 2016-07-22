/*

 Simple Serial String Parsing
 
 The circuit:
 * LED attached from digital pin 9 to ground.
 
 Created 11 March 2011
 By SJB
 
 http://www.dyadica.co.uk/journal/simple-serial-string-parsing
 
 Based upon code found by Tom Igoe at:
 
 http://www.arduino.cc/en/Tutorial/SerialEvent
 
 and
 
 http://arduino.cc/en/Tutorial/Fading
 
  
 This example code is in the public domain.
 
 */
 
// Example function A
void FunctionA(char *prop)
{
  // Output the data
  Serial.print("FunctionA: ");
  Serial.print(prop); 
  // Data already contains "\n"
}

// Example function B
void FunctionB(char *prop)
{
  // Convert prop to int
  int val = atoi(prop);
  Serial.print("FunctionB: ");
  Serial.print(val); 
  // Output new line
  Serial.println();
  // Set value of pin 9 to val
  analogWrite(9, val);
}

// Example function A1
void FunctionA1(char *prop, char *prod)
{
  // Convert property to int
  int pp = atoi(prop);  
  // Convert period to int
  int pd = atoi(prod);
  
  // Output the data
  Serial.print("A1: Set property: ");
  Serial.print(pp);
  Serial.print(" for a period of: ");
  Serial.print(pd);
  // Output new line
  Serial.println();
}
