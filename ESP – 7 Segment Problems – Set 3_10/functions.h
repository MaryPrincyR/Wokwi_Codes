// display function is used to display numbers 0 to 9 on a seven segment display
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

//display_with_dp() is used to display numbers 0 to 9 with dot pointer on a seven segment display
int display_with_dp(int num)
{
  long int x;
  long seven_segment[] = {0xBF, //0.
                          0x86,//1.
                          0xDB,//2.
                          0xCF,//3.
                          0xE6,//4.
                          0xED,//5.
                          0xFD,//6.
                          0x87,//7.
                          0xFF,//8.
                          0xE7,//9.
                         };
  x = seven_segment[num];
  return x;
}