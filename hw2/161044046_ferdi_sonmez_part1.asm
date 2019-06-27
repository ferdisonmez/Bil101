DRIVER:
load r1,0x60
load rd,DATA

BASLA:

 load r0,0 ; BASLA 0
 load rb,1 ; ARTIR +1
 load rE,0xFF ;AZALT -1
 load r7,[r1] ;
 load r3,[r1]
 jmpEQ r7=r0,SON1

 LOOP:
 
 load ra,1 ;SAYAC
 load r0,0 ;DEGER KONTROL
 load r6,0 
 addi r7,rE,r7 ; 1 AZALT
 jmpEQ r7=r0,SON2
 move r0,r7

LOOP_TOPLA:
 
  addi r6,r3,r6
  addi ra,ra,rb
  jmpLE ra<=r0,LOOP_TOPLA
  move r3,r6 ; KAYDET SONRA ATLA
         jmp LOOP ; 0 KADAR DEVAM ET

SON2:
 move r1,r3 ; R3 ->R1 TASI
 
load r0,0;
jmpEQ r1=r0,BASTIR
   

LOOP_HALT: 
 halt

BASTIR:
 load r0,0 ;KARSILASTIR

LOOP_PRINT:
 load rf,[rd]
 addi rd,rd,rb
 jmpEQ rf=r0,LOOP_HALT ; 0 ÝSE BITIT.
 jmp LOOP_PRINT

SON1: ; 0 ÝSE SONUC 1.

 load r1,1;
 jmp LOOP_HALT

DATA:
db "ekrana bastýramadým hocam",0


org 0x60
db 3 