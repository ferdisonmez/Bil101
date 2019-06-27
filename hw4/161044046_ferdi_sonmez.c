#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#define YUZ 1000
typedef struct{					/* new type defined    */
	char id[YUZ];
	char name[YUZ];
	char srname[YUZ];
	char mail[YUZ];
}kisi;
char *temiz(char x[]){			/* \ n The symbol has been cleared    */
	int i=0;
	while(x[i]!='\0'){
		
		if(x[i]=='\n'){
			x[i]='\0';	
		}
		i++;
	}	
	return x;
}
int bosluk(char arr[],FILE *output){
	int i=0,j=0,k=0,m=0,a=0,l=0,r=0,n=0,s=0,d1=0;	/*variables defined		*/
	char karakter[YUZ];
	kisi *nesne=(kisi*)malloc(sizeof(kisi));		/* yeni bir yer ayrýldý */
	while(arr[i]!='\0'){
		
		while(arr[i]!=' ' && arr[i]!='\0'){			/*character sequence divided into sections   */
			i++;
			if(arr[i]==' ' || arr[i]=='\0'){
				a=0;
				karakter[0]=0;						
				while(j<=i){
					
					karakter[a]=arr[j];										
					j++;
					a++;					
					karakter[a]='\0';			
				}			
				k=0,r=0,n=0,s=0;
					for(l=0;karakter[l]!='\0';l++){				/* conditions have been checked  */
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
				  	if(k>=2){								/* Provided conditions copied */
				  		strcpy(nesne->srname,karakter);
					}
					else if(n>=1){
						strcpy(nesne->mail,karakter);
					}
					else if(s>=2){
						strcpy(nesne->name,karakter);
					}	
					else if(r>1){						
						strcpy(nesne->id,karakter);	
						sscanf(nesne->id,"%d",&d1);			/* number read from character string   */		
					}															
			}										
		}		
		if(arr[i]==' ')
		i++;
 	} 	
	temiz(nesne->name);			/* \ n The symbol has been cleared    */
	temiz(nesne->mail);
	temiz(nesne->srname);	
 	fprintf(output,"%d ",d1);					/* printed to file   */
 	fprintf(output,"%s ",nesne->name );
 	fprintf(output,"%s ",nesne->srname );
 	fprintf(output,"%s\n",nesne->mail); 	
}
int main(){
	FILE *input,*output;
	int i=0,b=0;
	char str[YUZ],*a;
	input=fopen("hw4_disordered_people.txt","r");	/* files opened */
	output=fopen("output.txt","w");
	do{	
	a=fgets(str,YUZ,input);
	if(a=='\0'){		
		break;
	} 												/* dosya okundu   */
	bosluk(str,output);
	i++;
	}while(a!='\0');
				
	return 0;
}
