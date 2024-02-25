//Press any switch & display that number.
//Ex: 1 - > 1, 2 ->2, … 8 -> 8,9 -> 9,0 -> 0.

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
}
void setup()
{
  *dirf = 0x0F; // Set first four pins of PORT F as o/p. KEYPAD row pins are connected to port f.
  *dirk = 0x00; // Set PORT K as i/p port. KEYPAD column pins are connected to port k.
  *dira = 0x0F; // Set first 4 pins of PORT A as o/p.
  *dirc = 0x0F; // Set first 4 pins of PORT C as o/p.

  char key;
  int index;
  while (1)
  {
    key = read_keypad();
    if (key >= '0' && key <= '9') // If a numeric key is pressed
    {
      index = key - '0';// Convert the key to an index
      *outa=0x0E;
      *outc = display(index);
    }
    else if (key >= 'A' && key <= 'D') // If a letter key is pressed
    {
      index = key - 'A' + 10;// Convert the key to an index
      *outa=0x0E;
      *outc = display(index);
    }
    else //if anything other than 0-9 or A-D is pressed display nothing
    {
      *outc = 0x00;
    }
    
  }
}
