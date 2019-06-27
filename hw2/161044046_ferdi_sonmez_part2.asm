DRIVER:
 load r1,0xB0 ; baslangýc adresi
 load r2,0xD0 ;baslangýc adresi
 
 BASLA:

 move r8,r1
 load r0,0
 load r9,1
 load r3,1 ; SAYAC	

 BOYUT:

 load r4,[r8]
 addi r8,r8,r9
 addi r3,r3,r9
 jmpEQ r4=r0,BASLA1
 jmp BOYUT

BASLA1:

 move r9,r2 
 load r8,0 ; SAYAC
 load r7,1
 load r6,-1
 addi r4,r3,r1 ; ÝLK ADRESi OKU
 addi r4,r4,r6 ; AZALT
 move r0,r3

DEPO:

 load r5,[r4] ; DATA ADRESÝNÝ OKU 
 addi r4,r4,r6 ; DONGU ICIN AZALT
 addi r8,r8,r7 ; SAYAC+1
 store r5,[r2]
 addi r2,r2,r7
 jmpLE r8<=r0,DEPO ; BOYUT ÝLE SAYAC KARSILASTIR
 
DEVAM:

load r8,0 ;SAYAC SIFIRLA
load rf,10 ;EKRAN TEMIZLE


BASTIR: 

 load ra,[r9]
 move rf,ra
 addi r9,r9,r7
 addi r8,r8,r7
 jmpLE r8<=r0,BASTIR
  

halt 

org 0xB0
db "test",0