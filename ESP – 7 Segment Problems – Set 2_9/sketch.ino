//Initially display 9. When switch 1 is pressed start displaying 9 to 0continuously.
// When switch 2 is pressed stop display.

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
  int num = 9;
  *outf = display(num);//initially display 9

  while (1)
  {
    if (read_switch(ink, 0))//check if switch 1 is pressed
    {
      for (j = 0; j < 12000; j++); //a delay for switch debouncing
      while (1)
      {
        num = (num - 1) % 10;//display 9 to 0 continuosly
        *outf = display(num);
        //before the delay for display ,check if switch2 is pressed so that it
        // is detected instantaneosly.
        if (read_switch(ink, 1))//if switch 2 is pressed break the loop and stop display
        {
          for (j = 0; j < 12000; j++); //a delay for switch debouncing
          break;
        }
        for (j = 0; j < 200000; j++);//delay for the display
        if (num == 0) //whenever the value of num becomes 0 set the value of num to 10
          num = 10;
      }
    }
  }
  return 0;
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

/*The function `read_switch(ink, 0)` is likely designed to take a pointer as its
  first argument. If `ink` is declared as a pointer that points to a PORT in a
  microcontroller, then you would pass `ink` directly to the function.
  This allows the function to access and manipulate the PORT that `ink` points to.
  If you were to pass `*ink` to the function instead (as in `read_switch(*ink, 0)`),
  you would be passing the value that `ink` points to, not the pointer itself.
  This is called "dereferencing" the pointer. In this case, the function would
  receive a copy of the value of the PORT, not a reference to the PORT itself.
  Any changes that the function makes to this copy would not affect the original
  PORT.So, if you want the function to be able to access or modify the original
  PORT, you should pass `ink`, not `*ink`, to the function. This is a common
  practice in C programming when working with functions that need to modify their
  arguments or when dealing with large data structures (like arrays or complex
  structures) where passing a copy of the entire structure would be inefficient
  . In your case, it allows the `read_switch` function to read the state of a
   specific switch connected to the microcontroller's PORT that `ink` points to.*/
