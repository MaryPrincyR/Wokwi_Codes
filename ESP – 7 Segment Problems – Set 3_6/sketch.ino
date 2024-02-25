//Connect FOUR 7-Segment Displays to 4 individual ports.
//Display 0.000 to 999.9 in loop with delay.

#include "register.h"
#include "functions.h"

#define LOWER_LIMIT1 0.000
#define UPPER_LIMIT1 9.999

#define LOWER_LIMIT2 10.00
#define UPPER_LIMIT2 99.99

#define LOWER_LIMIT3 100.0
#define UPPER_LIMIT3 999.9

void setup()
{
  /*Display 3 is connected to PORTF.
    Display 2 is connected to PORTK.
    Display 1 is connected to PORTA.
    Display 0 is connected to PORTC.*/

  *dirf = 0xFF;//set PORT F as o/p port .
  *dirk = 0xFF;//set PORT K as o/p port .
  *dira = 0xFF;//set PORT F as o/p port .
  *dirc = 0xFF;//set PORT K as o/p port .

  float i;
  volatile long j = 0;
  int digits[5];

  while (1)
  {
    for (i = LOWER_LIMIT1; i <= UPPER_LIMIT1; i = i + 0.001)
    {
      int digits[] = {(int)(i * 1000) % 10, //ones digit
                      (int)((i * 1000) / 10) % 10, //tens degit
                      (int)((i * 1000) / 100)  % 10, //hundreds digit
                      (int)(i * 1000) / 1000 //thousands digit
                     };
      *outc = display(digits[0]);
      *outa = display(digits[1]);
      *outk = display(digits[2]);
      *outf = display_with_dp(digits[3]);
      for (j = 0; j < 150000; j++);//delay for the display
    }

    for (i = LOWER_LIMIT2; i <= UPPER_LIMIT2; i = i + 0.01)
    {
      int digits[] = {(int)(i * 100) % 10, //ones digit
                      (int)((i * 100) / 10) % 10, //tens degit
                      (int)((i * 100) / 100)  % 10, //hundreds digit
                      (int)(i * 100) / 1000 //thousands digit
                     };
      *outc = display(digits[0]);
      *outa = display(digits[1]);
      *outk = display_with_dp(digits[2]);
      *outf = display(digits[3]);
      for (j = 0; j < 150000; j++);//delay for the display
    }

    for (i = LOWER_LIMIT3; i <= UPPER_LIMIT3; i = i + 0.1)
    {
      int digits[] = {(int)(i * 10) % 10, //ones digit
                      (int) ((i * 10) / 10) % 10, //tens degit
                      (int)((i * 10) / 100)  % 10, //hundreds digit
                      (int)(i * 10) / 1000 //thousands digit
                     };
      *outc = display(digits[0]);
      *outa = display_with_dp(digits[1]);
      *outk = display(digits[2]);
      *outf = display(digits[3]);
      for (j = 0; j < 150000; j++);//delay for the display
    }
  }
}

