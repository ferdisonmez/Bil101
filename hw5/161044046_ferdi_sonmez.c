#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#define YUZ 1000
typedef struct{					/* new type defined    */
	int id;
	char name[YUZ];
	char srname[YUZ];
	char mail[YUZ];
}kisi;
void temiz(char x[]){			/* \ n The symbol has been cleared    */
	int i=0;
	while(x[i]!='\0'){
		if(x[i]=='\n'){
			x[i]='\0';
			break;
		}
		i++;
	}	
	 
}
void bosluk(char arr[],kisi *nesne,FILE *output,int hx){			
	int i=0,j=0,k=0,m=0,a=0,l=0,r=0,n=0,s=0,d1=0;	             /*variables definened*/
	char karakter[YUZ];
	temiz(arr);	
	while(arr[i]!='\0'){
		while(arr[i]!=' ' && arr[i]!='\0'){			        /*character sequence divided into sections   */
			i++;
			if(arr[i]==' ' || arr[i]=='\0'){
				a=0;
				karakter[0]=0;						
				while(j<i){
					if(arr[j]==' '){
						j++;
					}
					karakter[a]=arr[j];										
					j++;
					a++;										
				}	
				karakter[a]='\0';
				k=0,r=0,n=0,s=0;
					for(l=0;karakter[l]!='\0';l++){				     /* conditions have been checked  */
						if(karakter[l]>=65 && karakter[l]<=90){							
							k++;
						}
						else if(karakter[l]>=48 && karakter[l]<=57){						
							r++;
						}
						else if(karakter[l]==64 || karakter[l]==46){						
							n++;
						}
						else if(karakter[l]>=97 &&karakter[l]<=122){
							s++;
						}
					}					
				  	if(k>=2){
				  			nesne[hx].srname[0]=0;							/* Provided conditions copied */
				  		strcpy(nesne[hx].srname,karakter);
					}
					else if(n>=1){
						nesne[hx].mail[0]=0;	
						strcpy(nesne[hx].mail,karakter);
					}
					else if(s>=2){
						nesne[hx].name[0]=0;	
						strcpy(nesne[hx].name,karakter);
						
					}	
					else if(r>3){	
						sscanf(karakter,"%d",&d1);
						nesne[hx].id=d1;											
					}															
			}										
		}		
		if(arr[i]==' ')
		i++;
 	} 
 																								
}
int main(){
	FILE *input,*output;
	int i=0,b=0,j=0,h=0;
	int c,d;
	kisi gecici;
	char str[YUZ],ar[YUZ],*a,op[1],temp[YUZ];
	input=fopen("hw4_disordered_people.txt","r");	    /* files opened */
	output=fopen("orderedFile.txt","w");
	do{	
	a=fgets(ar,YUZ,input);
	if(a=='\0'){		
		break;
	} 
	j++;
	}while(a!='\0');
	fclose(input);
	kisi *nesne=(kisi*)malloc(sizeof(kisi)*j);
	input=fopen("hw4_disordered_people.txt","r");
	do{	
	a=fgets(str,YUZ,input);
	if(a=='\0'){		
		break;
	} 			
	bosluk(str,nesne,output,i);
	i++;
	}while(a!='\0');
	printf("Give a sort metric(I=ID N=NAME S=SIRNAME M=MAİL)\n");
	scanf("%s",op);
 	if(op[0]==73 || op[0]==105){	//ID
 		for(c=0;c<j-1;c++){
 			for(d=c+1;d<j;d++){
 				if(nesne[c].id>nesne[d].id){
 					gecici=nesne[c];
 					nesne[c]=nesne[d];
 					nesne[d]=gecici;
 				}
 			}
 		}
 		for (i = 0; i <j; ++i)
 		{
 			fprintf(output,"%d %s %s %s\n",nesne[i].id,nesne[i].name,nesne[i].srname,nesne[i].mail);
 		}	
	}
	else if(op[0]==78 || op[0]==110){	 //name	
		for(c=0;c<j-1;c++){
 			for(d=c+1;d<j;d++){
 				if(strcmp(nesne[c].name,nesne[d].name)>0){
 					gecici=nesne[c];
 					nesne[c]=nesne[d];
 					nesne[d]=gecici;
 				}
 			}
 		}
 		for (i = 0; i <j; ++i)
 		{
 			fprintf(output,"%s %d %s %s\n",nesne[i].name,nesne[i].id,nesne[i].srname,nesne[i].mail);
 		}

	}
	else if(op[0]==83 || op[0]==115){   //srname
		
		for(c=0;c<j-1;c++){
 			for(d=c+1;d<j;d++){
 				if(strcmp(nesne[c].srname,nesne[d].srname)>0){
 					gecici=nesne[c];
 					nesne[c]=nesne[d];
 					nesne[d]=gecici;
 				}

 			}

 		}

 		for (i = 0; i <j; ++i)
 		{
 			fprintf(output,"%s %d %s %s\n",nesne[i].srname,nesne[i].id,nesne[i].name,nesne[i].mail);
 		}

	}
	else if(op[0]==77 || op[0]==109){    //maill
		for(c=0;c<j-1;c++){
 			for(d=c+1;d<j;d++){
 				if(strcmp(nesne[c].mail,nesne[d].mail)>0){
 					gecici=nesne[c];
 					nesne[c]=nesne[d];
 					nesne[d]=gecici;
 				}

 			}

 		}

 		for (i = 0; i <j; ++i)
 		{
 			fprintf(output,"%s %d %s %s\n",nesne[i].mail,nesne[i].id,nesne[i].name,nesne[i].srname);
 		}			

	}
free(nesne);
fclose(input);
fclose(output);		
	return 0;	
}
