//Perform three Digit Addition.
//Ex: 161 + 656 = 817, 659 + 765 = 1424

/*
  The row pins of keypad is connected to PORTF and the column pins of keypad
  are connected to PORTK.The DIG1,DIG2,DIG3 and DIG4 pins  of the display
  are connected to PORTA and A,B,C,D,E,F,G,DP are connected to PORTC.
*/

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
  int index, i = 0, j = 0, sum = 0, k = 0, result = 0;
  char arr[4] = {0};
  int number[2] = {0};
  int segments[4] = {0x0E, 0x0D, 0x0B, 0x07}; // Array to store the segment selection values
  bool star_pressed = false;
  while (1)
  {
    if ((key = read_keypad()) != 'N')
    {
      delay(300);  // use delay after reading a valid input

      if (key >= '0' && key <= '9') // If a numeric key is pressed
      {
        arr[i] = key - '0'; // convert the key to integer and store the value in an array
        i++; // Move to the next position
        if (i == 3) // If three values have already been read
        {
          number[k] = (arr[0] * 100) + (arr[1] * 10) + arr[2]; // Store the three-digit number in an array
          k++;
        }
      }

      else if (key == '*') // If '*' is pressed
      {
        star_pressed = true;
        arr[0] = arr[1] = arr[2] = 'N'; // Reset the array
        i = 0; // Reset the index
      }
    }

    for (j = 0; j < i; j++)
    {
      if (arr[j] != 'N') // If a key has been pressed
      {
        index = arr[j] ;   // Convert the key to an index
        *outc = display(index); // Display the digit on the selected segment
        *outa = segments[j];    // Select the corresponding segment
        *outa = 0x0F;           // Turn off all segments
      }
    }
    while ((star_pressed) && (k == 2))
    {
      sum = number[0] + number[1]; //find the sum of the two nos.

      int thousands_digit = sum / 1000;
      int hundreds_digit = (sum / 100) % 10;
      int tens_digit = (sum % 100) / 10;
      int ones_digit = sum  % 10;

      *outc = display(thousands_digit); // Display the thousands digit on the selected segment
      *outa = segments[0];    // Select the corresponding segment for tens digit
      *outa = 0x0F;

      *outc = display(hundreds_digit); // Display the hundreds digit on the selected segment
      *outa = segments[1];    // Select the corresponding segment for tens digit
      *outa = 0x0F;

      *outc = display(tens_digit); // Display the tens digit on the selected segment
      *outa = segments[2];    // Select the corresponding segment for tens digit
      *outa = 0x0F;

      *outc = display(ones_digit); // Display the ones digit on the selected segment
      *outa = segments[3];    // Select the corresponding segment for ones digit
      *outa = 0x0F;

      if (((key = read_keypad()) != 'N') && (key == 'C'))
      {
        i = 0; // Reset the index
        k = 0;
        star_pressed = false;//Reset star_pressed to its initial value to start over again
      }
    }
  }
}
