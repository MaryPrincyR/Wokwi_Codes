//Connect FOUR 7-Segment Displays to 4 individual ports
//Display a clock (Min & Sec only).

#include "register.h"
#include "functions.h"

#define SEC_LOWER_LIMIT 00
#define SEC_UPPER_LIMIT 59

#define MIN_LOWER_LIMIT 00
#define MIN_UPPER_LIMIT 59

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

  int i, k;
  volatile long j = 0;
  int digits[5];

  while (1)
  {
    for (i = MIN_LOWER_LIMIT; i <= MIN_UPPER_LIMIT; i++)
    {
      for ( k = SEC_LOWER_LIMIT; k <= SEC_UPPER_LIMIT; k++)
      {
        int digits[] = {(int)(k % 10), //ones digit of seconds
                        (int)(k / 10), //tens degit of seconds
                        (int)(i % 10), //ones digit of minutes
                        (int)(i / 10) //tens degit of minutes
                       };
        *outc = display(digits[0]);
        *outa = display(digits[1]);
        *outk = display_with_dp(digits[2]);
        *outf = display(digits[3]);
        for (j = 0; j < 625000; j++);//delay for the display
      }
    }
  }
}
