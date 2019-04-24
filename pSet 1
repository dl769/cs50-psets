//Problem set - 1 - mario
#include<cs50.h>
#include <stdio.h>

int check();
int createpyramids();

int main(void)
{
    int height;
    
    do{

    printf("Height: ");
    scanf("%d",&height);
        
    }while(check(height)!=1);

    createpyramids(height);
}

int check(int height){

    if(height>=1&&height<=8){

    return 1;

    }else return 0;

 }

int createpyramids(int x){

    for(int i=1;i<=x;i++){

       for(int a=x;a>i;a--) printf(" ");
       for(int a=1;a<i+1;a++) printf("#");
       printf("  ");
       for(int a=1;a<i+1;a++) printf("#");
       printf("\n");
    }
return 0;
}
