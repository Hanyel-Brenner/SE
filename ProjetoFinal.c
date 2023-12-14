
sbit LCD_RS at RE2_bit;   // PINO 2 DO PORTD INTERLIGADO AO RS DO DISPLAY
sbit LCD_EN at RE1_bit;   // PINO 3 DO PORTD INTERLIGADO AO EN DO DISPLAY
sbit LCD_D7 at RD7_bit;  // PINO 7 DO PORTD INTERLIGADO AO D7 DO DISPLAY
sbit LCD_D6 at RD6_bit;  // PINO 6 DO PORTD INTERLIGADO AO D6 DO DISPLAY
sbit LCD_D5 at RD5_bit;  // PINO 5 DO PORTD INTERLIGADO AO D5 DO DISPLAY
sbit LCD_D4 at RD4_bit;  // PINO 4 DO PORTD INTERLIGADO AO D4 DO DISPLAY

// Selecionando direção de fluxo de dados dos pinos utilizados para a comunicação com display LCD
sbit LCD_RS_Direction at TRISE2_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 2 DO PORTD
sbit LCD_EN_Direction at TRISE1_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 3 DO PORTD
sbit LCD_D7_Direction at TRISD7_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 7 DO PORTD
sbit LCD_D6_Direction at TRISD6_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 6 DO PORTD
sbit LCD_D5_Direction at TRISD5_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 5 DO PORTD
sbit LCD_D4_Direction at TRISD4_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 4 DO PORTD

int Control = 0;
//UART1_Init(9600);



void main() {
char input;
int current = 0, previous = 0;
int isPressed = 0;
int counter = 0;
int pressedButton = -1;
Lcd_Init();                               //Inicializa módulo LCD
 Lcd_Cmd(_LCD_CURSOR_OFF);                 //Apaga cursor
 Lcd_Cmd(_LCD_CLEAR);
TRISB = 0;      //define portB como saida

TRISD.RD3 = 1;
TRISD.RD2 = 1;
TRISD.RD1 = 1;
TRISD.RD0 = 1;

PORTD.RD3 = 1;
PORTD.RD2 = 1;
PORTD.RD1 = 1;
PORTD.RD0 = 1;


   while(1){
      switch(Control){
         case 0:
         
            PORTB.RB2 = 0;  //habilita primeira coluna do teclado

            if(Button(&PORTD,3,50,0) && PORTB.RB2 ==0 && isPressed == 0){input = '3'; isPressed = 1; }
            if(Button(&PORTD,2,50,0) && PORTB.RB2 ==0 && isPressed == 0){input = '6'; isPressed = 1; }
            if(Button(&PORTD,1,50,0) && PORTB.RB2 ==0 && isPressed == 0){input = '9'; isPressed = 1; }

            PORTB.RB2 = 1;
            PORTB.RB1 = 0;  //habilita segunda coluna do teclado

            if(Button(&PORTD,3,50,0) && PORTB.RB1 ==0 && isPressed == 0){input = '2'; isPressed = 1; }
            if(Button(&PORTD,2,50,0) && PORTB.RB1 ==0 && isPressed == 0){input = '5'; isPressed = 1; }
            if(Button(&PORTD,1,50,0) && PORTB.RB1 ==0 && isPressed == 0){input = '8'; isPressed = 1; }
            if(Button(&PORTD,0,50,0) && PORTB.RB1 ==0 && isPressed == 0){input = '0'; isPressed = 1; }


            PORTB.RB1 = 1;
            PORTB.RB0 = 0;  //habilita terceira coluna do teclado
              if(Button(&PORTD,3,50,0) && PORTB.RB0 ==0 && isPressed == 0){input = '1'; isPressed = 1; }
              if(Button(&PORTD,2,50,0) && PORTB.RB0 ==0 && isPressed == 0){input = '4'; isPressed = 1; }
              if(Button(&PORTD,1,50,0) && PORTB.RB0 ==0 && isPressed == 0){input = '7'; isPressed = 1; }
            PORTB.RB0 = 1;


        break;
            }

              if(input == '0' ){lcd_out(2,1,"0"); }
              if(input == '1' ){lcd_out(2,1,"1"); }
              if(input == '2' ){lcd_out(2,1,"2"); }
              if(input == '3' ){lcd_out(2,1,"3"); }
              if(input == '4' ){lcd_out(2,1,"4"); }
              if(input == '5' ){lcd_out(2,1,"5"); }
              if(input == '6' ){lcd_out(2,1,"6"); }
              if(input == '7' ){lcd_out(2,1,"7"); }
              if(input == '8' ){lcd_out(2,1,"8"); }
              if(input == '9' ){lcd_out(2,1,"9"); }

              isPressed = 0;
      }





}
