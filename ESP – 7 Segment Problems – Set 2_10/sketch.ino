//Get a 4 digit number from user.Press the switch Sequentially (Example 1256)
//Add the sum of them the sum is more than 1 digit then add them again
//and show the sum on display.

int read_switch(volatile char *ink, int switch_number);
int display(int num);
void setup()
{
  //7segment display is connected to PORTF
  //switches are connected to port k.

  volatile char *dirf = (char*)0x30;//DDRF – Port F Data Direction Register
  volatile char *dirk = (char*)0x107;//DDRK – Port K Data Direction Register
  volatile char *outf = (char*)0x31;//PORTF – Port F Data Register
  volatile char *ink = (char*)0x106;// PINK – Port K Input Pins Address

  *dirf = 0xFF;//set PORT F as o/p port .
  *dirk = 0x00;//set PORT K as i/p port .

  volatile long  j;
  int i, sum = 0, count = 0, temp, num;

  while (1)
  {
l1: for (i = 0; i < 8; i++)
    {
      if (read_switch(ink, i)) //check if switch  is pressed
      {
        *outf = display(i);//display the switch number being pressed
        for (j = 0; j < 300000; j++);
        sum = sum + i;
        count = count + 1;
        if (count == 4)// to make sure 4 digits are entered
        {
          if (sum > 9)//if sum is >9 add the digits and display sum
          {
            temp = sum;
            num = temp % 10;
            temp = temp / 10;
            sum = num + temp;
          }
          *outf = display(sum);//display sum
          sum = 0;//clear the sum to store new values
          count = 0;//clear the count value
          goto l1;// goto l1 to read new switch numbers
        }
      }
    }
  }
}

int display(int num)
{
  long int x;
  long seven_segment[] = {0x3F,//0
                          0x06,//1
                          0x5B,//2
                          0x4F,//3
                          0x66,//4
                          0x6D,//5
                          0x7D,//6
                          0x07,//7
                          0x7F,//8
                          0x67//9
                         };
  x = seven_segment[num];
  return x;
}

int read_switch(volatile char*ink, int switch_number)
{
  return (*ink & (1 << switch_number)) != 0;
  /* 1 << switch_number: This operation shifts the number 1 to the left by
    switch_number bits. This creates a value that has all bits set to 0,
    except for the one at the position switch_number.
    ink & (1 << switch_number): This operation performs a bitwise AND between
    the value of *ink and the result of the shift operation. If the bit at the
    position switch_number in *ink is set, this operation will return a
    non-zero value. Otherwise, it will return 0.
    (*ink & (1 << switch_number)) != 0: This operation checks if the result of
    the bitwise AND operation is not equal to zero.
    So, this expression will return:
    true (or 1 in C/C++) if the bit at the position switch_number in *ink is set.
    false (or 0 in C/C++) if that bit is not set.*/
}

