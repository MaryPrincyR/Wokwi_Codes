//ESP – 7 Segment Problems – Set 1
//Do not forget to change the default common anode to common cathode type in diagram.json.

void setup() {
  // put your setup code here, to run once:
  volatile char *DIR_F = (char*)0x30;//DDRF – Port F Data Direction Register
  *DIR_F = 0xFF;// set PORT F as output register
}

void loop() {
  // put your main code here, to run repeatedly:
  volatile long int i;
  volatile char *OUT_F = (char*)0x31; // PORTF – Port F Data Register

  //Display 0 to 9 without decimal points
  /**OUT_F =0x3F;//0
    for(i=0;i<400000;i++);
    *OUT_F =0x30;//1
    for(i=0;i<400000;i++);
    *OUT_F =0x5B;//2
    for(i=0;i<400000;i++);
    *OUT_F =0x4F;//3
    for(i=0;i<400000;i++);
    *OUT_F =0x66;//4
    for(i=0;i<400000;i++);
    *OUT_F =0x6D;//5
    for(i=0;i<400000;i++);
    *OUT_F =0x7D;//6
    for(i=0;i<400000;i++);
    *OUT_F =0x07;//7
    for(i=0;i<400000;i++);
    *OUT_F =0x7F;//8
    for(i=0;i<400000;i++);
    *OUT_F =0x67;//9
    for(i=0;i<400000;i++);

    //Display 0 to 9 with decimal points
    *OUT_F =0xBF;//0
    for(i=0;i<400000;i++);
    *OUT_F =0xB0;//1
    for(i=0;i<400000;i++);
    *OUT_F =0xDB;//2
    for(i=0;i<400000;i++);
    *OUT_F =0xCF;//3
    for(i=0;i<400000;i++);
    *OUT_F =0xE6;//4
    for(i=0;i<400000;i++);
    *OUT_F =0xED;//5
    for(i=0;i<400000;i++);
    *OUT_F =0xFD;//6
    for(i=0;i<400000;i++);
    *OUT_F =0x87;//7
    for(i=0;i<400000;i++);
    *OUT_F =0xFF;//8
    for(i=0;i<400000;i++);
    *OUT_F =0xE7;//9
    for(i=0;i<400000;i++);

    //Display 9 to 0 with delay
    *OUT_F =0x67;//9
    for(i=0;i<400000;i++);
    *OUT_F =0x7F;//8
    for(i=0;i<400000;i++);
    *OUT_F =0x07;//7
    for(i=0;i<400000;i++);
    *OUT_F =0x7D;//6
    for(i=0;i<400000;i++);
    *OUT_F =0x6D;//5
    for(i=0;i<400000;i++);
    *OUT_F =0x66;//4
    for(i=0;i<400000;i++);
    *OUT_F =0x4F;//3
    for(i=0;i<400000;i++);
    *OUT_F =0x5B;//2
    for(i=0;i<400000;i++);
    *OUT_F =0x30;//1
    for(i=0;i<400000;i++);
    *OUT_F =0x3F;//0
    for(i=0;i<400000;i++);

    //Display odd numbers with delay
    *OUT_F =0x30;//1
    for(i=0;i<400000;i++);
    *OUT_F =0x4F;//3
    for(i=0;i<400000;i++);
    *OUT_F =0x6D;//5
    for(i=0;i<400000;i++);
    *OUT_F =0x07;//7
    for(i=0;i<400000;i++);
    *OUT_F =0x67;//9
    for(i=0;i<400000;i++);

    //Display even numbers with delay
    *OUT_F =0x3F;//0
    for(i=0;i<400000;i++);
    *OUT_F =0x5B;//2
    for(i=0;i<400000;i++);
    *OUT_F =0x66;//4
    for(i=0;i<400000;i++);
    *OUT_F =0x7D;//6
    for(i=0;i<400000;i++);
    *OUT_F =0x7F;//8
    for(i=0;i<400000;i++);

    //Display the possible alphabets ( A to Z)
    *OUT_F =0x77;//A
    for(i=0;i<400000;i++);
    *OUT_F =0x7F;//B
    for(i=0;i<400000;i++);
    *OUT_F =0x39;//C
    for(i=0;i<400000;i++);
    *OUT_F =0x79;//E
    for(i=0;i<400000;i++);
    *OUT_F =0x71;//F
    for(i=0;i<400000;i++);
    *OUT_F =0x7D;//G
    for(i=0;i<400000;i++);
    *OUT_F =0x76;//H
    for(i=0;i<400000;i++);
    *OUT_F =0x1E;//J
    for(i=0;i<400000;i++);
    *OUT_F =0x38;//L
    for(i=0;i<400000;i++);
    *OUT_F =0x3F;//O
    for(i=0;i<400000;i++);
    *OUT_F =0x73;//P
    for(i=0;i<400000;i++);
    *OUT_F =0x6D;//S
    for(i=0;i<400000;i++);
    *OUT_F =0x3E;//U
    for(i=0;i<400000;i++);
    *OUT_F =0x66;//Y
    for(i=0;i<400000;i++);

    //Display numbers in following order: 0,2,4,6,8,9,7,5,3,1
    *OUT_F =0x3F;//0
    for(i=0;i<400000;i++);
    *OUT_F =0x5B;//2
    for(i=0;i<400000;i++);
    *OUT_F =0x66;//4
    for(i=0;i<400000;i++);
    *OUT_F =0x7D;//6
    for(i=0;i<400000;i++);
    *OUT_F =0x7F;//8
    for(i=0;i<400000;i++);
    *OUT_F =0x67;//9
    for(i=0;i<400000;i++);
    *OUT_F =0x07;//7
    for(i=0;i<400000;i++);
    *OUT_F =0x6D;//5
    for(i=0;i<400000;i++);
    *OUT_F =0x4F;//3
    for(i=0;i<400000;i++);
    *OUT_F =0x30;//1
    for(i=0;i<400000;i++);

    //Display the single digit prime numbers
    *OUT_F =0x5B;//2
    for(i=0;i<400000;i++);
    *OUT_F =0x4F;//3
    for(i=0;i<400000;i++);
    *OUT_F =0x6D;//5
    for(i=0;i<400000;i++);
    *OUT_F =0x07;//7
    for(i=0;i<400000;i++);

    //Display last digit of a number. Assume any number.
    char num =45;
    num=num%10;
    if(num==0)
    *OUT_F =0x3F;//0
    else if(num==1)
    *OUT_F =0x30;//1
    else if(num==2)
    *OUT_F =0x5B;//2
    else if(num==3)
    *OUT_F =0x4F;//3
    else if(num==4)
    *OUT_F =0x66;//4
    else if(num==5)
    *OUT_F =0x6D;//5
    else if(num==6)
    *OUT_F =0x7D;//6
    else if(num==7)
    *OUT_F =0x07;//7
    else if(num==8)
    *OUT_F =0x7F;//8
    else if(num==9)
    *OUT_F =0x67;//9*/

  //Display first digit of a number. Assume any number.
  char num = 45;
  num = num / 10;
  if (num == 0)
    *OUT_F = 0x3F; //0
  else if (num == 1)
    *OUT_F = 0x30; //1
  else if (num == 2)
    *OUT_F = 0x5B; //2
  else if (num == 3)
    *OUT_F = 0x4F; //3
  else if (num == 4)
    *OUT_F = 0x66; //4
  else if (num == 5)
    *OUT_F = 0x6D; //5
  else if (num == 6)
    *OUT_F = 0x7D; //6
  else if (num == 7)
    *OUT_F = 0x07; //7
  else if (num == 8)
    *OUT_F = 0x7F; //8
  else if (num == 9)
    *OUT_F = 0x67; //9


}
