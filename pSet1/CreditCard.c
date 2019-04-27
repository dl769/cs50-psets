#include <stdio.h>
#include <stdlib.h>

int checkProvider();
int validateCard();

int main()
{
   unsigned long long cardNumber=0;

   do{

   fflush(stdin);
   printf("Number: ");

   }
   while(scanf("%llu",&cardNumber)!=1);   //As well it might be: while((scanf("%llu",&cardNumber)!=1)||checkProvider(cardNumber)==9) if it's not a number or none of providers matches it, ask again for it

   int returnedValue=checkProvider(cardNumber);

   if(returnedValue==1) printf("AMEX\n");
   if(returnedValue==2) printf("MASTERCARD\n");
   if(returnedValue==3) printf("VISA\n");
   if(returnedValue==0||9) printf("INVALID\n");


   return 0;
}
int checkProvider(unsigned long long x){

    if((x>340000000000000&&x<350000000000000)||(x>370000000000000&&x<380000000000000)){//America Express

    if(validateCard(7,8,x,1)==1) return 1;
    else return 0;
    }

    if(x>5100000000000000&&x<5600000000000000){ //Master Card

    if(validateCard(8,8,x,0)==1) return 2;
    else return 0;
    }

    if(x>4000000000000000&&x<5000000000000000){//visa16

    if(validateCard(8,8,x,0)==1) return 3;
    else return 0;
    }

    if((x>4000000000000&&x<5000000000000)){//visa13

    if(validateCard(8,8,x,1)==1) return 3;

    else return 0;
    }

    return 9;//none of them

}


int validateCard(int z, int y, unsigned long long number,int even){

int values[z]; int values2[y];
int i=z+y;
int d=0, e=0;

if(even==0){  //if number of digits on credit card isn't even it stores odd values in one array while even are stored in second.

    while (number > 0) {


        if(i%2!=0){

        values[d]=number%10;
        d++;

        }
        if(i%2==0) {

        values2[e]=number%10;
        e++;

        }

    number = number / 10;
    i--;

        }

    }
if(even==1){

    while (number > 0) {

        if(i%2==0){

        values[d]=number%10;
        d++;

        }

        if(i%2!=0) {

        values2[e]=number%10;
        e++;

        }

    number = number / 10;
    i--;

    }

}

int controlValue1=0,controlValue2=0,controlValue=0;

    for(int i=0;i<z;i++){

        if(values[i]>4){

        values[i]=values[i]*2-9;

        controlValue1=controlValue1+values[i];

        }

        else controlValue1=controlValue1+values[i]*2;
        
    }


    for(int i=0;i<y;i++){

        controlValue2=controlValue2+values2[i];

    }

    controlValue=controlValue1+controlValue2;

     if(controlValue%10==0){
            
            return 1; //true;
     
        }
                else  return 0;  //false

}
