void main()
{

  int a;
     TRISB = 0b00010000;           //RB4 as Input PIN (ECHO)

  TRISC = 0b00000000;
   PORTC=0x00;
  Delay_ms(3000);

  T1CON = 0x10;                 //Initialize Timer Module

  while(1)
  {
    TMR1H = 0;                  //Sets the Initial Value of Timer
    TMR1L = 0;                  //Sets the Initial Value of Timer
     PORTC=0x00;
    PORTB.F0 = 1;               //TRIGGER HIGH
    Delay_us(10);               //10uS Delay
    PORTB.F0 = 0;               //TRIGGER LOW

    while(!PORTB.F4);           //Waiting for Echo
    T1CON.F0 = 1;               //Timer Starts
    while(PORTB.F4);            //Waiting for Echo goes LOW
    T1CON.F0 = 0;              //Timer Stops

    a = (TMR1L | (TMR1H<<8));   //Reads Timer Value
    a = a/58.82;                //Converts Time to Distance
    a = a + 1;                  //Distance Calibration
    if(a>=0&&a<=50)
     {
    portc=0xff;
    }
else
{
portc=0x00;