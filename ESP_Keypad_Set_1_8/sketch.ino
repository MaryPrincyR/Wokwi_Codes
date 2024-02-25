//Perform any digit Multiplication. If the total exceeds 9999 then display “EEEE”.
//Ex: 25 x 40 = 1000, 1111 x 8 = 8888


/*The maximum input possible is 9999.If an input greater than 9999 is entered
  "EEEE" will be displayed indicating error. Also, if the product exceeds 9999,
  "EEEE" will be displayed. The input should be entered in this way, for example,
   674*1234. To display result press * again. To enter new inputs press 'C'.*/
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
    outf = (1 << row); // Activate one row at a time
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
  dirf = 0x0F; // Set first four pins of PORT F as o/p. KEYPAD row pins are connected to port f.
  dirk = 0x00; // Set PORT K as i/p port. KEYPAD column pins are connected to port k.
  dira = 0x0F; // Set first 4 pins of PORT A as o/p.
  dirc = 0xFF; // Set PORT C as o/p.

  outa = 0x0F; // turn off all segments initially

  char key;
  int index, i = 0, j = 0, k = 0;
  long int product = 0;
  char arr[5] = {0};
  long int number[2] = {0};
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

        if (i == 5)//check if more than 4 digits are entered, if so display"EEEE"
        {
          i = 0;//reset array index
          arr[0] = arr[1] = arr[2] = arr[3] = 'N'; // Reset the array

          for (j = 0; j < 4; j++)
          {
            outc = display(14); // Display E
            outa = segments[j]; // Select the corresponding segment
            outa = 0xFF;
          }
        }

      }

      else if (key == '*') // If '*' is pressed
      {
        star_pressed = true;

        switch (i)
        {
          case 4:
            number[k] = (arr[0] * 1000) + (arr[1] * 100) + (arr[2] * 10) + arr[3]; // Store the 4-digit number in an array
            k++;
            break;
          case 3:
            number[k] = (arr[0] * 100) + (arr[1] * 10) + arr[2]; // Store the 3-digit number in an array
            k++;
            break;
          case 2:
            number[k] = (arr[0] * 10) + arr[1]; // Store the 2-digit number in an array
            k++;
            break;
          case 1:
            number[k] = arr[0]; // Store the 1-digit number in an array
            k++;
            break;
        }

        arr[0] = arr[1] = arr[2] = arr[3] = 'N'; // Reset the array
        i = 0; // Reset the index

      }
    }

    for (j = 0; j < i; j++)
    {
      if (arr[j] != 'N') // If a key has been pressed
      {
        index = arr[j] ;   // Convert the key to an index
        outc = display(index); // Display the digit on the selected segment
        outa = segments[j];    // Select the corresponding segment
        outa = 0x0F;           // Turn off all segments
      }
    }
    while ((star_pressed) && (k == 2))//k==2 to check whether 2 nos. are entered
    {
      product = number[0] * number[1]; //find the product of the two nos.

      /*The maximum input can be 9999*9999 which calculates to 99980001.But
        maximum digits that can be displayed is upto thousands-digit. Therefore if the
        result exceeds 9999 'EEEE' will be displayed indicating error.*/

      int crores_digit = product / 10000000;
      int ten_lakhs_digit = (product % 10000000) / 1000000;
      int lakhs_digit = ((product % 10000000) / 100000) % 10;
      int ten_thousands_digit = (((product % 10000000) / 10000) % 100) % 10;
      int thousands_digit = ((product % 10000000) / 1000) % 10;
      int hundreds_digit = ((product % 10000000) % 1000) / 100;
      int tens_digit = (((product % 10000000) % 1000) % 100) / 10;
      int ones_digit = (((product % 10000000) % 1000) % 100) % 10;

      //if result exceeds 9999 display'EEEE'
      if ((crores_digit != 0) || (ten_lakhs_digit != 0) || (lakhs_digit != 0) || (ten_thousands_digit != 0))
      {
        for (j = 0; j < 4; j++)
        {
          *outc = display(14); // Display E
          *outa = segments[j]; // Select the corresponding segment
          *outa = 0x0F;
        }
      }

      else
      {
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
      }

      if (((key = read_keypad()) != 'N') && (key == 'C'))
      {
        i = 0; // Reset the index
        k = 0;
        star_pressed = false;//Reset star_pressed to its initial value to start over again
      }
    }
  }
}

