#include <stdio.h>
#include<string.h>
//int toLowerCase(char c);
int main()
{
    int arr[] = { 1, 3, 5, 8 ,11};
    int first = 0;
    int last = sizeof(arr)/sizeof(arr[0]);
    printf("%d", last);
    int middle = (first + last)/2;
    int search = 3;
    printf("asdkjf");
    while(first <= last){
    if(search < arr[middle])
        middle = middle - 1;
    else if(search > arr[middle + 1])
        middle = middle + 1;
    else if(search == arr[middle]){
        printf("%d found at %dth position",search, middle + 1);
     break;
    }
    else
        printf("\n not found in the list \n");
        
    
    
    middle = (first + last)/2;
    }
}
    
  
