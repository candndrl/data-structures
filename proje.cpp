#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream> 
#include <Windows.h>
#include<time.h>
struct node{
	int sayi;
	struct node *next;
};

struct node *iter=NULL,*iter2=NULL,*iter3=NULL,*iter4=NULL,*root=NULL,*root2=NULL;
int size=0,size2=0;

void push(int sayi){
    if(iter==NULL){
    	iter = (node * ) malloc(sizeof(node));
        iter->next=NULL;
    }
    iter->sayi = sayi;
    node * yeni = (node * )malloc(sizeof(node));
    yeni->next = iter;
    iter=yeni;
}

void push2(int sayi){
    if(iter2==NULL){
    	iter2 = (node * ) malloc(sizeof(node));
        iter2->next=NULL;
    }
    iter2->sayi = sayi;
    node * yeni = (node * )malloc(sizeof(node));
    yeni->next = iter2;
    iter2=yeni;
}

void push3(int sayi){
    if(iter3==NULL){
    	iter3 = (node * ) malloc(sizeof(node));
        iter3->next=NULL;
    }
    iter3->sayi = sayi;
    node * yeni = (node * )malloc(sizeof(node));
    yeni->next = iter3;
    iter3=yeni;
}

void push4(int sayi){
    if(iter4==NULL){
    	iter4 = (node * ) malloc(sizeof(node));
        iter4->next=NULL;
    }
    iter4->sayi = sayi;
    node * yeni = (node * )malloc(sizeof(node));
    yeni->next = iter4;
    iter4=yeni;
}

void enqueue(int sayi){
     if(size==0){
                 root = (node*)malloc(sizeof(node));
                 root->sayi=sayi;            
                 root->next = NULL;
                 size++;
     }
     else{    
          node * temp=(node*)malloc(sizeof(node));
          temp->sayi=sayi;
          temp->next=root;
          size++;
          root=temp;
     }
}

void enqueue2(int sayi){
     if(size2==0){
                 root2 = (node*)malloc(sizeof(node));
                 root2->sayi=sayi;            
                 root2->next = NULL;
                 size2++;
     }
     else{    
          node * temp=(node*)malloc(sizeof(node));
          temp->sayi=sayi;
          temp->next=root;
          size2++;
          root2=temp;
     }
}

int pop(){
	int result = iter->next->sayi;
	node *temp = iter;
	iter=iter->next;
	free(temp);
	return result;   
}

int pop2(){
	int result2 = iter2->next->sayi;
	node *temp2 = iter2;
	iter2=iter2->next;
	free(temp2);
	return result2;   
}

void printStack(){
	FILE *koordinat;
	koordinat=fopen("koordinat.txt","w");
    printf("\n");
    node *temp = iter3;
    node *temp2 = iter4;
	temp=temp->next;
	temp2=temp2->next;
	printf("\n\n\t\t     ---------------------------------------\n");
	printf("\t\t\t           KOORDINATLAR\n");
	printf("\t\t     ---------------------------------------\n");
	fprintf(koordinat,"KOORDINATLAR\n");
    while(temp2->next!=NULL && temp->next!=NULL){
    	
    	printf("\t\t    *\t    Satir:%d ",temp->sayi);
        printf("Sutun:%d ",temp2->sayi);
        fprintf(koordinat,"Satir:%d ",temp->sayi);
        fprintf(koordinat,"Sutun:%d\n",temp2->sayi);
        if(temp->next->next!=NULL){
        	if(temp->sayi+2==temp->next->sayi)printf("0 Geldi \t    *\n");
    		else if(temp2->sayi+2==temp2->next->sayi)printf("1 Geldi \t    *\n");
    		else printf("2 Geldi \t    *\n");
		}
        else printf(" Oyun Bitti  *\n");
        temp=temp->next;
        temp2=temp2->next;
    }
    printf("\t\t     ---------------------------------------\n");
    fclose(koordinat);
}

void pushters(){
	node *temp = iter;
    node *temp2 = iter2;
    while(temp!=NULL && temp2!=NULL){
        push3(temp->sayi);
    	push4(temp2->sayi);
    	temp2=temp2->next;
    	temp=temp->next;
    }
}

void printqueue(){
     node  *temp,*temp2;
     temp=root;
     temp2=root2;
     system("CLS");
     printf("\n\n\n\t\t\t---------------------------------\n");
	printf("\t\t\t              KAZALAR\n");
	printf("\t\t\t---------------------------------\n");
     for(int i = 0;i<size;i++){
             printf("\t\t\t*\tSatir:%d Sutun:%d \t*\n",temp->sayi,temp2->sayi);
             temp=temp->next;
             temp2=temp2->next;
     }
     printf("\t\t\t---------------------------------\n");
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void sekil(int a,int b){
	node *temp = iter3;
    node *temp2 = iter4;
	temp=temp->next;
    temp2=temp2->next;
    temp2->sayi*=2;
    int anahtar=0;
    while(temp2->next!=NULL && temp->next!=NULL){
    	system("CLS");
    	system("color 02");
    	printf("\n\n\t");
    	for(int j=0;j<203;j++){
			printf("-");
		}
		printf("\n\t");
    	for(int j=0;j<203;j++){
			printf("-");
		}
		printf("\n");
    	for(int i=0;i<50-(temp->sayi+1);i++){
			printf("\t||");
			for(int j=0;j<100;j++){
				printf("_|");
			}
			printf("|\n");
		}
		printf("\t||");
		for(int i=0;i<temp2->sayi-1;i++){
   		 	printf("_|"); 	
		}
		printf("&");
		printf("|"); 
		for(int i=0;i<100-(temp2->sayi);i++){
    		printf("_|"); 	
		}
		printf("|\n");
		for(int i=0;i<temp->sayi;i++){
			printf("\t||");
			for(int j=0;j<100;j++){
				printf("_|");
			}
			printf("|\n");
		}
		printf("\t");
		for(int j=0;j<203;j++){
			printf("-");
		}
		printf("\n\t");
		for(int j=0;j<203;j++){
			printf("-");
		}
		delay(500);
		if(anahtar==0){
			system("CLS");
    		system("color 06");
    		printf("\n\n\t");
    		for(int j=0;j<203;j++){
				printf("-");
			}
			printf("\n\t");
    		for(int j=0;j<203;j++){
				printf("-");
			}
			printf("\n");
    		for(int i=0;i<50-(a+1);i++){
				printf("\t||");
				for(int j=0;j<100;j++){
					printf("_|");
				}
				printf("|\n");
			}
			printf("\t||");
			for(int i=0;i<b-1;i++){
   		 		printf("_|"); 	
			}
			printf("$");
			printf("|"); 
			for(int i=0;i<100-(b);i++){
    			printf("_|"); 	
			}
			printf("|\n");
			for(int i=0;i<a;i++){
				printf("\t||");
				for(int j=0;j<100;j++){
					printf("_|");
				}
				printf("|\n");
			}
			printf("\t");
			for(int j=0;j<203;j++){
				printf("-");
			}
			printf("\t");
			printf("\n\t");
			for(int j=0;j<203;j++){
				printf("-");
			}
			if(temp->sayi==a && temp2->sayi==b){
				system("CLS");
				system("color 5F");
				printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t------------------\n\t\t\t\t\t\t\t\t\t\tANAHTAR BULUNDU!!!\n\t\t\t\t\t\t\t\t\t\t------------------");
				anahtar=1;
			}
		}
		delay(500); 
		temp=temp->next;
  		temp2=temp2->next;
    }
}

int main() {
	system("color 5F");
	int rastgele,zar,a=0,b=0,anahtara,anahtarb,anahtarsayac=0,sonuckontrol=0;
	struct node *listsatir,*ilksatir,*listsutun,*ilksutun;
	srand((unsigned)time(NULL)); 
	listsatir=(struct node *)malloc(sizeof(struct node));
	ilksatir=listsatir;
	listsutun=(struct node *)malloc(sizeof(struct node));
	ilksutun=listsutun;
	for(int i=0;i<30;i++){
		listsatir->next=(struct node *)malloc(sizeof(struct node));
		listsatir->sayi=rand()%50;
		listsatir=listsatir->next;
		listsutun->next=(struct node *)malloc(sizeof(struct node));
		listsutun->sayi=rand()%100;
		listsutun=listsutun->next;
	}
	listsatir->next=NULL;
	listsatir=ilksatir;
	listsutun->next=NULL;
	listsutun=ilksutun;
	anahtara=rand()%50;
	anahtarb=rand()%100;
	printf("\n\n\t\t\t---------------------------------\n");
	printf("\t\t\t            ENGELLER\n");
	printf("\t\t\t---------------------------------\n");
	for(int i=0;i<30;i++){
		printf("\t\t\t*\tSatir:%d Sutun:%d \t*\n",listsatir->sayi,listsutun->sayi);
		listsatir=listsatir->next;
		listsutun=listsutun->next;
	}
	printf("\t\t\t---------------------------------\n\n");
	listsatir=ilksatir;
	listsutun=ilksutun;
	for(int i=0;i<30;i++){
		if(anahtara==listsatir->sayi && anahtarb==listsutun->sayi){
			anahtara=rand()%50;
			anahtarb=rand()%100;
		}
		listsatir=listsatir->next;
		listsutun=listsutun->next;
	}
	listsatir=ilksatir;
	listsutun=ilksutun;
	push(a);
	push2(b);
	while(1){
		if(anahtara<a && anahtarsayac==0)anahtara=a+rand()%50-a;
		if(anahtarb<b && anahtarsayac==0)anahtarb=b+rand()%100-b;
		zar=rand()%3;
		if(zar==0 && a<=50 && b<=100){
			a+=2;
			push(a);
			push2(b);
			if(a>50){
				enqueue(a);
				enqueue2(b);
				a-=2;
				pop();
				pop2();
			}
			if(a==anahtara && b==anahtarb)
				anahtarsayac=1;
			for(int i=0;i<30;i++){
				if(a==listsatir->sayi && b==listsutun->sayi){
					printf("\t\t\tSatir:%d Sutun:%d\n",a,b);
					printf("\t\t\tRobot Engele Carpti\n");
					enqueue(a);
					enqueue2(b);
					a-=2;
					pop();
					pop2();
					break;
				}
				listsatir=listsatir->next;
				listsutun=listsutun->next;
			}
			listsatir=ilksatir;
			listsutun=ilksutun;
		}
		else if(zar==1 && a<=50 && b<=100){
			b+=2;
			push(a);
			push2(b);
			if(b>100){
				enqueue(a);
				enqueue2(b);
				b-=2;
				pop();
				pop2();
			}
			if(a==anahtara && b==anahtarb)
				anahtarsayac=1;
			for(int i=0;i<30;i++){
				if(a==listsatir->sayi && b==listsutun->sayi){
					printf("\t\t\tSatir:%d Sutun:%d\n",a,b);
					printf("\t\t\tRobot Engele Carpti\n");
					enqueue(a);
					enqueue2(b);
					b-=2;
					pop();
					pop2();
					break;
				}
				listsatir=listsatir->next;
				listsutun=listsutun->next;
			}
			listsatir=ilksatir;
			listsutun=ilksutun;
		}
		else if(zar==2 && a<=50 && b<=100){
			a++;
			push(a);
			b++;
			push2(b);
			if(a>50 || b>100){
				enqueue(a);
				a--;
				pop();
				enqueue2(b);
				b--;
				pop2();
			}
			if(a==anahtara && b==anahtarb)
				anahtarsayac=1;
			for(int i=0;i<30;i++){
				if(a==listsatir->sayi && b==listsutun->sayi){
					printf("\t\t\tSatir:%d Sutun:%d\n",a,b);
					printf("\t\t\tRobot Engele Carpti\n");
					enqueue(a);
					a--;
					pop();
					enqueue2(b);
					b--;
					pop2();
					break;
				}
				listsatir=listsatir->next;
				listsutun=listsutun->next;
			}
			listsatir=ilksatir;
			listsutun=ilksutun;
		}
		if(a==50 && b==100 && anahtarsayac==0){
			sonuckontrol=0;
			break;
		}
		else if(a==50 && b==100 && anahtarsayac==1){
			sonuckontrol=1;
			break;
		}
	}
	printf("\n\n\t\t    ** Anahtar Satir:%d Sutun:%d'de Gizli **\n",anahtara,anahtarb);
	pushters();
	printStack();
	if(sonuckontrol==1){
		printf("\t\t\t\tOyunu Kazandiniz!!!\n");
		//PlaySound("Alkis.WAV", NULL, SND_FILENAME|SND_LOOP);
	}
	else{
		printf("\t\t\t\tOyunu Kaybettiniz!!!\n");
		//PlaySound("losing.WAV", NULL, SND_FILENAME|SND_LOOP);
	} 
	printf("\n\t      Robotun carptigi engeller ve yanlis yollar icin (e/E)\n");
	char d=getch();
	if(d=='e'||d=='E') printqueue();
	printf("\nRobotun yolu icin (e/E)\n");
	char c=getch();
	if(c=='e'||c=='E')	sekil(anahtara,anahtarb);
	return 0;
}
