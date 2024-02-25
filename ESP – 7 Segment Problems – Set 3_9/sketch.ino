//Connect FOUR 7-Segment Displays to 4 individual ports
//Display the two-digit prime numbers in loop

#include "register.h"
#include "functions.h"

#define LOWER_LIMIT 10
#define UPPER_LIMIT 99

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
  int isPrime;
  volatile long j = 0;
  int digits[4];

  while (1)
  {
    for (i = LOWER_LIMIT; i <= UPPER_LIMIT; i++)
    {
      isPrime = 1;//assume every number is prime
      //check if i is prime or not
      for (k = 2; k < i; k++)
      {
        if (i % k == 0)
        {
          isPrime = 0; //i is not prime
          break;
        }
      }
      if (isPrime) //if number is prime display it.
      {
        int digits[4] = {(int)(i % 10), //ones digit
                         (int)(i  / 10), //tens degit
                        };

        *outc = display(digits[0]);//ones
        *outa = display(digits[1]);//tens
        for (j = 0; j < 500000; j++);//delay for the display
      }
    }
  }
}
