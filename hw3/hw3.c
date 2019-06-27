/* THIS PROGRAM SORTS ARRAY DEMONSTRATION PURPOSES */
/* GTU RULEZ */
#include<stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0


int PrintSelection(int selection){
 printf("Selected Menu item is:");
 printf("%d\n",selection);
 return 1;
 
}

int DisplayMenu(){
 int selection;
 printf("\e[2J"); // clears screen
 
 printf("%s","\e[5;31;47mWELCOME TO ADDING PROGRAM\e[0m\n");
 printf("%s","(1) Add two numbers\n");
 printf("%s","(2) Sort an array\n");
 printf("%s","(3) Subtract two numbers\n");
 printf("%s","(4) Divide numbers\n");
 printf("%s","(5) Summarize numbers with words\n");
 printf("%s","(6) Exponent two numbers x to the y\n");
 printf("%s","(0) quit\n");
 printf("Selection:");	
 scanf("%d",&selection);
 PrintSelection(selection);
 return selection;
}

int main(){
int number1, number2, sum,fark,bol,sayi,kalan;
char wanttoexit = FALSE;
char c;
int choice,birler,onlar,yuzler,binler,onbinler;
int i,j;
int myArray[100];
int max;
int pivot;
int temp,sonuc=1;

// main loop
while(wanttoexit == FALSE){

		
	choice = DisplayMenu();
	
	
	if(choice == 1){
		printf("Add two numbers\n");
		printf("%s","PLEASE  ENTER FIRST NUMBER\n");
		scanf("%d",&number1);
		printf("%s","PLEASE  ENTER SECOND NUMBER\n");
		scanf("%d",&number2);
		sum = number1 + number2;
		printf("The result is: ");
		printf("%d\n",sum);
		c=getchar();
		c=getchar();
	}
	if(choice == 2){
		printf("Sort an array\n\n");
		printf("%s","Enter numbers for array and 0 for end\n");
		for(i=0;i<100;i++){
			scanf("%d",&sayi);
			if(sayi == 0) break;
			myArray[i] = sayi;
			max = i ;
		}
		printf("Numbers are entered.. \n");
		printf("Now sorting.. ");
	    for(i=0;i<=max;i++){
	       for(j=0;j<max; j++){
	           if(myArray[j] > myArray[j+1]){
	           		temp = myArray[j];
	           		myArray[j]= myArray[j+1];
	           		myArray[j+1]=temp;
	           }
		    }
		    
		}
		printf("finished..\n ");
	    for(i=0;i<=max;i++){
	      printf("%d  ",myArray[i]);
	    }
	      printf("are the numbers.\n");
	        
		    
		c=getchar();
		c=getchar();
	}

	if(choice==3){
		printf("Subtract two numbers\n");
		printf("%s","PLEASE  ENTER FIRST NUMBER\n");
		scanf("%d",&number1);
		printf("%s","PLEASE  ENTER SECOND NUMBER\n");
		scanf("%d",&number2);
		fark=(number1-number2);
		printf("The result is: ");
		printf("%d\n",fark);
		c=getchar();
		c=getchar();


	}

	if(choice==4){
		printf("Divide numbers\n");
		printf("%s","PLEASE  ENTER FIRST NUMBER\n");
		scanf("%d",&number1);
		printf("%s","PLEASE  ENTER SECOND NUMBER\n");
		scanf("%d",&number2);
		while(number2==0){
			printf("lutfen baska sayi giriniz ifade belirsizdir\n");
			printf("%s","PLEASE  ENTER SECOND NUMBER\n");
			scanf("%d",&number2);

		}
		bol = number1/number2;
		printf("The result is: ");
		printf("%d\n",bol);
		c=getchar();
		c=getchar();


	}

	if (choice==5)
	{
		printf("Summarize numbers with words\n");
		printf("%s","PLEASE  ENTER NUMBER (0---99999)\n");
		scanf("%d",&sayi);
		if(sayi<0 || sayi>99999){
			while(sayi<0 || sayi>99999){

				printf("sayiyi kontrol ediniz\n");
				printf("sayiyi tekrar giriniz\n");
				scanf("%d",&sayi);
			}

		}
		temp=sayi;
		for(i=1;i<=5;i++){

			kalan=temp%10;
			temp/=10;
			if(i==1)
				birler=kalan;
			if(i==2)
				onlar=kalan;
			if(i==3)
				yuzler=kalan;
			if(i==4)
				binler=kalan;
			if(i==5)
				onbinler=kalan;
		}
	if(onbinler==0 && binler==0 && yuzler==0){   
		printf("(%dx10)+(%dx1)",onlar,birler);
	}

	else if(onbinler==0 && binler==0){
		printf("(%dx100)+(%dx10)+(%dx1)",yuzler,onlar,birler);
	}
	else if(onbinler==0){
		printf("(%dx1000)+(%dx100)+(%dx10)+(%dx1)",binler,yuzler,onlar,birler);
	}
	else
		printf("(%dx10000)+(%dx1000)+(%dx100)+(%dx10)+(%dx1x)",onbinler,binler,yuzler,onlar,birler);       

		c=getchar();
		c=getchar();


	}
	if(choice==6){
		printf("Exponent two numbers x to the y\n");
		printf("tabani girin:");
		scanf("%d",&number1);
		printf("ussu girin:");
		scanf("%d",&number2);

		for(i=1;i<=number2;i++){

			sonuc=sonuc*number1;
		}
		printf("The result is: ");
		printf("%d\n",sonuc );

		c=getchar();
		c=getchar();

	}


	if(choice == 0){
		wanttoexit = TRUE;
		printf("exiting...");
	}
} 

}
