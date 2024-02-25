//Connect FOUR 7-Segment Displays to 4 individual ports
//Display 0000 to 9999 in loop with delay

#include "register.h"
#include "functions.h"

#define LOWER_LIMIT 0
#define UPPER_LIMIT 9999

void setup()
{
  /* Display 3 is connected to PORTF.
    Display 2 is connected to PORTK.
    Display 1 is connected to PORTA.
    Display 0 is connected to PORTC.*/

  *dirf = 0xFF;//set PORT F as o/p port .
  *dirk = 0xFF;//set PORT K as o/p port .
  *dira = 0xFF;//set PORT F as o/p port .
  *dirc = 0xFF;//set PORT K as o/p port .

  int i = 0;
  volatile long j = 0;
  int digits[5];

  while (1)
  {
    for (i = LOWER_LIMIT; i <= UPPER_LIMIT; i++)
    {
      int digits[] = {(int)(i  % 10), //ones digit
                      (int)(i  / 10) % 10, //tens degit
                      (int)(i  / 100)  % 10, //hundreds digit
                      (int)(i  / 1000) //thousands digit
                     };
      *outc = display(digits[0]);
      *outa = display(digits[1]);
      *outk = display(digits[2]);
      *outf = display(digits[3]);
      for (j = 0; j < 150000; j++);//delay for the display
    }
  }
}

