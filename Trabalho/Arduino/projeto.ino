#include <LiquidCrystal.h>
#define NEXT 12
#define CONFIRM 13

const int rs = 7; // Pino RS (Register Select)
const int en = 6; // Pino EN (Enable)
const int d4 = 5;  // Pino D4
const int d5 = 4;  // Pino D5
const int d6 = 3;  // Pino D6
const int d7 = 2;  // Pino D7

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String letras = "aeiou";
String msg = "";

typedef enum{
   INICIAL,
   DISPOSITIVO
}POSSIVEIS_TELAS;

struct Tela {
   String msg_linha_1;
   String msg_linha_2;
   int escolha;
};

void setup() {
   lcd.begin(16, 2); 
   lcd.clear();      
   lcd.setCursor(0, 0);
   lcd.print("Hello World"); 
   lcd.setCursor(0, 1);
   lcd.print("Arduino");

   pinMode(NEXT, INPUT);
   pinMode(CONFIRM, INPUT);
}

void updateTela(struct Tela fonte)
{
   lcd.clear();      
   lcd.setCursor(0, 0);
   lcd.print(fonte.msg_linha_1); 
   lcd.setCursor(0, 1);
   lcd.print(fonte.msg_linha_2);
}

// void maquinaEstados()
// {
//    switch (menu)
//    {
//    case INICIAL:
//       atual.msg_linha_1 = "Escolha:";
//       atual.msg_linha_2 = "( ) PC - ( ) Ino";
//       break;
   
//    default:
//       atual.msg_linha_1 = "Voce escolheu:";
//       atual.msg_linha_2 = "";
//       break;
//    }
// }

void loop() {
   POSSIVEIS_TELAS menu = INICIAL;
   static int idx_letra = 0;
   static int idx_cursor = 0;
   static bool mudou = true;
   static bool mudou_confirm = true;
   static struct Tela atual = {"MSG:", (String)letras[idx_letra], 0};

   updateTela(atual);

   if (digitalRead(NEXT) && mudou)
   {
      atual.msg_linha_2 = letras[idx_letra ++];
      mudou = false;

      if (idx_letra == 4)
      {
         idx_letra = 0;
      }
   }
   else if (digitalRead(NEXT) == LOW)
   {
      mudou = true;
   }

   if (digitalRead(CONFIRM) && mudou_confirm)
   {
      idx_cursor++;
      mudou_confirm = false;
   }
   else if (digitalRead(CONFIRM) == LOW)
   {
      mudou_confirm = true;
   }

   delay(50);
}