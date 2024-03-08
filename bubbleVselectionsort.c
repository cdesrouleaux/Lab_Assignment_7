#include <stdio.h>

#define SZ 9

void swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

// swap the smallest value to the front of the array until entire array is in numerical order
void selection_sort(int arr1[], int arr2[], int *r)
{
    int t1_count=0,t2_count=0, small1, small2;

    for(int l1=0; l1 < SZ-1; l1++)
    {
        small1 = l1;
        for(int i1 = l1+1; i1<SZ; i1++)
        {
            if(arr1[i1] < arr1[small1])
            {
                small1 = i1;
                t1_count++;
            }
        }
        swap(&arr1[l1], &arr1[small1]);
    }
    
    for(int l2=0; l2 < SZ-1; l2++)
    {
        small2 = l2;
        for(int i2 = l2+1; i2<SZ; i2++)
        {
            if(arr2[i2] < arr2[small2])
            {
                small2 = i2;
                t2_count++;
            }
        }
        swap(&arr2[l2], &arr2[small2]);
    }

    r[0] = t1_count;
    r[1] = t2_count;
}


// brute force swap the adjacent values until the entire array is in numerical order
void bubble_sort(int arr1[], int arr2[], int *r)
{
    int t21_count=0, t22_count=0;

    for(int l=0; l < SZ-1; l++)
    {
        for(int i=0; i < SZ-l-1; i++)
        {
            if(arr1[i]>arr1[i+1])
            {
                swap(&arr1[i], &arr1[i+1]);
                t21_count++;
            }
            if(arr2[i]>arr2[i+1])
            {
                swap(&arr2[i], &arr2[i+1]);
                t22_count++;
            }
        }       
    }

    r[0] = t21_count;
    r[1] = t22_count;
}


int main()
{
    int array1[SZ] = {97,16,45,63,13,22,7,58,72}; // same 1
    int array11[SZ] = {97,16,45,63,13,22,7,58,72}; // same 1
    int array2[SZ] = {90,80,70,60,50,40,30,20,10}; // same 2
    int array22[SZ] = {90,80,70,60,50,40,30,20,10}; // same 2
    int r1[2], r2[2];
    
    selection_sort(array1, array2, r1);
    bubble_sort(array11, array22, r2);

    printf("\narray 1 selection sort: \ntotal # of swaps: %d\n", r1[0]);
    for(int i1=0; i1 < SZ; i1++)
        printf("%d\t", array1[i1]);
    
    printf("\narray 2 selection sort:\n");
    printf("total # of swaps: %d\n", r1[1]);
    for(int i2=0; i2 < SZ; i2++)
        printf("%d\t", array2[i2]);

    printf("\narray 1 bubble sort:\n");
    printf("total # of swaps: %d\n", r2[0]);
    for(int i3=0; i3 < SZ; i3++)
        printf("%d\t", array11[i3]);

    printf("\narray 2 bubble sort:\n");
    printf("total # of swaps: %d\n", r2[1]);
    for(int i4=0; i4 < SZ; i4++)
        printf("%d\t", array22[i4]);

}