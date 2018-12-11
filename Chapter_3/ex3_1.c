#include <stdio.h>
int binSearch(int,int[],int);
int main(void) {
	int arr[]={3,4,5,6,7,8};
	int s = 12;
	int len = sizeof(arr)/sizeof(arr[0]);
	binSearch(len,arr,s);
	
	return 0;
}
int binSearch(int len,int arr[],int s){
	int low = 0;
	int high = len - 1;
	int mid = (low+high)/2;
	while(low<=high && s !=arr[mid]){
		if(s < arr[mid])
		     high = mid - 1;
		else
		     low = mid + 1;
		 mid = (low+high)/2;
	}
	if(s == arr[mid])
	    printf("%d is found at %d postion",s,mid+1);
	else
	    printf("\n Not found in the list\n");
	return 0;
}
