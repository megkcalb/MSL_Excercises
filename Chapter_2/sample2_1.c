#include<stdio.h>
unsigned getbits(int ,int ,int );
int main(){
    int x=12;
  printf("%d",getbits(x,4,3));
   
  
    return 0;
}
 unsigned getbits(int x,int p,int n){
     return (x >> (p+1 - n)) && ~(~0 << n);
 }
