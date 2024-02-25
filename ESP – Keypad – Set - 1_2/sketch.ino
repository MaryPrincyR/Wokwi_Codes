//Press 4 digits and display that Number.
//Ex: 1234,6754, 9870, etc

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

  *outa = 0xFF; // turn off all segments initially

  char key;
  volatile long k = 0;
  int index, i = 0, j = 0;
  char arr[4] = {0};
  int segments[4] = {0x0E, 0x0D, 0x0B, 0x07}; // Array to store the segment selection values
  while (1)
  {
    if ((key = read_keypad()) != 'N')
    {
      delay(300);  // use delay after reading a valid input
    }
    if (key >= '0' && key <= '9') // If a numeric key is pressed
    {
      if (i == 4) // If four values have already been read
      {
        *outa = 0xFF; // Turn off all segments
        for (j = 0; j < 4; j++)
          arr[j] = 'N'; // Reset the array

        i = 0; // Reset the index
      }
      arr[i] = key; // Store the key
      i++; // Move to the next position
    }

    for (j = 0; j < 4; j++)
    {
      if (arr[j] != 'N') // If a key has been pressed
      {
        index = arr[j] - '0';   // Convert the key to an index
        *outc = display(index); // Display the digit on the selected segment
        *outa = segments[j];    // Select the corresponding segment
        *outa = 0x0F;           // Turn off all segments
      }
    }
  }
}