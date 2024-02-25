// Perform Single Digit Addition
//Ex: 6 + 7 = 13, 9 + 4 = 13
//Instead of '+' use '*'. Enter,for instance, 2*3.
//to enter next input press 'C'.

/*
  The row pins of keypad is connected to PORTF and the column pins of keypad
  are connected to PORTK.The DIG1,DIG2,DIG3 and DIG4 pins  of the display
  are connected to PORTA and A,B,C,D,E,F,G,DP are connected to PORTC.*/

#include "register.h"
#include "functions.h"

#define ROWS 4
#define COLS 4

// Define keypad array globally
char keypad[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Function to read the keypad
char read_keypad()
{
  uint8_t row, column;
  for (row = 0; row < ROWS; row++)
  {
    *outf = (1 << row); // Activate one row at a time
    for (column = 0; column < COLS; column++)
    {
      if ((*ink & (1 << column))) // Check each column in the active row
      {
        return keypad[row][column];
      }
    }
  }
  return 'N';  // return N for no press
}


void setup()
{
  *dirf = 0x0F; // Set first four pins of PORT F as o/p. KEYPAD row pins are connected to port f.
  *dirk = 0x00; // Set PORT K as i/p port. KEYPAD column pins are connected to port k.
  *dira = 0x0F; // Set first 4 pins of PORT A as o/p.
  *dirc = 0xFF; // Set PORT C as o/p.

  *outa = 0x0F; // turn off all segments initially

  char key;
  int index, i = 0, j = 0, sum = 0;
  char arr[4] = {0};
  int segments[4] = {0x0E, 0x0D, 0x0B, 0x07}; // Array to store the segment selection values
  bool star_pressed = false;
  while (1)
  {
    if ((key = read_keypad()) != 'N')//check whether a valid input is entered
    {
      delay(300);  // use delay after reading a valid input

      if (key >= '0' && key <= '9') // If a numeric key is pressed
      {
        arr[i] = key - '0'; // Store the key as an integer
        i++; // Move to the next position
      }
      else if (key == '*') // If '*' is pressed
      {
        star_pressed = true;
      }
    }

    for (j = 0; j < i; j++)
    {
      index = arr[j];         // Convert the key to an index
      *outc = display(index); // Display the digit on the selected segment
      *outa = segments[0];    // segment 1 is selected
      if (j == 1)delay(400); //a small delay for the second input to be displayed for a while before result is displayed
      *outa = 0x0F;           // Turn off all segments after displaying each digit
    }
    while (star_pressed && i == 2) // If '*' has been pressed and two values have been read
    {

      sum = arr[0] + arr[1]; // find sum

      int tens_digit = sum / 10;
      int ones_digit = sum % 10;

      *outc = display(tens_digit); // Display the tens digit on the selected segment
      *outa = segments[0];    // Select the corresponding segment for tens digit
      *outa = 0x0F;

      *outc = display(ones_digit); // Display the ones digit on the selected segment
      *outa = segments[1];    // Select the corresponding segment for ones digit
      *outa = 0x0F;

      //after the result is displayed,check whether the next input is a valid
      //input and it is 'C'.
      if (((key = read_keypad()) != 'N') && (key == 'C'))
      {
        i = 0; // Reset the index
        star_pressed = false;//Reset start_pressed to its initial value to start over again
      }
    }
  }
}
