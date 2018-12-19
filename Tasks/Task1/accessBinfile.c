#include<stdio.h>
/* our structure */

struct market_data {    /* structure includes the market data*/
      int id;
	  double val_x;
	  double val_y;
};

void accessbinFile(FILE *ptr,struct market_data );

int main()
{
   FILE *ptr;
   struct market_data market_data_init;

   ptr=fopen("structureData.bin","rb");      /* opening the file in binary read mode*/

   if (!ptr)
   {
      printf("Unable to open file!");     return 1;
   }
   else
   {
      accessBinFile(ptr,market_data_init);     /* accessing the file for getting the min,max count*/
   }
   fclose(ptr);                         /* closing the file pointer*/

   return 0;
}
void accessBinFile(FILE *ptr,struct market_data market_data_init){

    double max=0;
    double min=0;

    while(1)
    {
      fread(&market_data_init,sizeof(struct market_data),1,ptr);
      if(feof(ptr))                            /* looping through the end of the file */
        break;

      (max<market_data_init.val_x)?max = market_data_init.val_x:max;   /* getting the maximum value */

      (min>market_data_init.val_y)?min = market_data_init.val_y:min;   /* getting the minimum value */
    }

    printf("Total number of structures in this binary file = %d\n",market_data_init.id);
    printf("\n Highest value of X is == %lf",max);
    printf("\n Minimum value of Y is == %lf\n",min);

}
