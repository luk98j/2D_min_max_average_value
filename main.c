#include <stdio.h>
#include <stdlib.h>

int column_statistics(const int *ptr, int width, int height, int column_id,int* max, int* min, float *avg);
int row_statistics(const int *ptr, int width, int height, int row_id, int* max,int* min, float *avg);

int main()
{
    int const size = 5;
    int tab[size][size];
    int max = 0;
    int min = 0;
    int scan;
    float avg = 0;
    int *ptr_tab = &tab[0][0];
    int *ptr_max = &max;
    int *ptr_min = &min;
    float *ptr_avg = &avg;
    printf("Podaj liczby\n");
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
       scan = scanf("%d",ptr_tab+size*i+j);
        if(scan==0){
            printf("Incorrect input");
            return 1;
            break;
        }
        if(scan-(int)scan !=0){
            printf("Incorrect input");
            return 1;
            break;
        }

        }

    }


    for (int i=0; i<size; i++)
    {

    int fun = column_statistics(ptr_tab,size,size,i, ptr_max, ptr_min, ptr_avg);
    if(fun == 1){
         printf("Incorrect input");
        return 1;
        break;
    }if(fun == 0){
    printf("%d %d %.2f\n",*ptr_min,*ptr_max12 21,*ptr_avg);
    }

    }

     for (int j=0; j<size; j++)
    {
    int fun = row_statistics(ptr_tab,size,size,j, ptr_max, ptr_min, ptr_avg);
    if(fun == 1){
         printf("Incorrect input");
        return 1;
        break;
    }if(fun == 0){
    printf("%d %d %.2f\n",*ptr_min,*ptr_max,*ptr_avg);
    }

    }

    return 0;
}

int column_statistics(const int *ptr, int width, int height, int column_id,int* max, int* min, float* avg)
{

    if (ptr == NULL){
        return 1;
    }
    if(column_id<0)
        {
            return 1;
        }

    if(height<1)return 1;
    if(width<1)return 1;
    if(avg == NULL)return 1;
    if(max == NULL)return 1;
    if(min == NULL)return 1;
    if(width<=column_id)return 1;
    *max= *(ptr+column_id);
    for(int j=0 ; j<height; j++)
    {
        if(*max <  *(ptr+width*j+column_id))
        {
            *max =  *(ptr+width*j+column_id);
        }
    }


    *min = *(ptr+column_id);
   for(int i=0 ; i<height; i++)
    {
        if(*min > *(ptr+width*i+column_id))
        {
            *min =  *(ptr+width*i+column_id);
        }
    }

    float sum = 0;
    float srednia=0;

    if(height!=0){
    for(int k = 0;k<height;k++){
        sum += *(ptr+width*k+column_id);
    }
    srednia = sum/height;
    *avg = srednia;
    }
    return 0;


}

int row_statistics(const int *ptr, int width, int height, int row_id, int* max,int* min, float *avg)
{

     if (ptr == NULL){
        return 1;
    }
    if(row_id<0)
        {
            return 1;
        }

    if(height<1)return 1;
    if(width<1)return 1;
    if(avg == NULL)return 1;
    if(max == NULL)return 1;
    if(min == NULL)return 1;
    if(width<=row_id)return 1;
     *max= *(ptr+row_id*width);
    for(int j=0 ; j<width; j++)
    {
        if(*max <  *(ptr+width*row_id+j))
        {
            *max =  *(ptr+width*row_id+j);
        }
    }

    *min = *(ptr+row_id*width);

   for(int i=0 ; i<width; i++)
    {
        if(*min > *(ptr+width*row_id+i))
        {
            *min =  *(ptr+width*row_id+i);
        }
    }

    float sum = 0;
    float srednia = 0;
    if(width!=0){
    for(int k = 0;k<width;k++){
        sum += *(ptr+width*row_id+k);
    }
    srednia = sum/width;
    *avg = srednia;
    }

    return 0;

}

