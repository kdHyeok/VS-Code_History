#include <stdio.h>
#define SWAP(x,y,t)  ((t)=(x),(x)=(y),(y)=(t)) //y,t,x

void printArray(int arr[], int n, char *str)
{
    int i;
    printf("%s = ", str);
    for ( i = 0; i < n; i++){
        printf("%3d", arr[i]);
    }
    printf("\n");
}
void printStep(int arr[], int n, int val)
{
    int i;
    printf("  step %2d = ", val);
    for ( i = 0; i < n; i++){
        printf("%3d", arr[i]);
    }
    printf("\n");
}
void selection_sort(int list[], int n)
{
    int i, j, least, tmp;
    for ( i = 0; i < n-1; i++){
        least = i;
        for ( j = i+1; j < n; j++){
            if(list[j]<list[least]) least = j;
        }
        SWAP(list[i],list[least],tmp);
        printStep(list, n, i+1);
    } 
}
//===================================================== -선택정렬
void insertion_sort (int list[], int n)
{
    int i, j, key;
    for (i=1; i<n; i++){
        key = list[i];
        for (j=i-1; j>=0 && list[j] > key; j--){
            list[j+1] = list[j];
        }
        list[j+1] = key;
        printStep(list, n, i);
    }
}
//======================================================== -삽입정렬
void bubble_sort(int list[], int n)
{
    int i, j, bChanged, tmp;
    for (i=n-1; i>0; i--){
        bChanged = 0;
        for (j=0; j < i; j++){
            if (list[j]>list[j+1]){
                SWAP(list[j],list[j+1],tmp);
                bChanged = 1;
            }
        }
        if(!bChanged) break;
        printStep(list, n, n-i);
    }
}
//========================================= -버블정렬
void insertion_sort_fn(int list[], int n, int (*sort)(int x, int y))
{
    int i, j, key;
    for (i=1; i<n; i++){
        key = list[i];
        for (j=i-1; j>=0 && sort(list[j], key)< 0; j--){
            list[j+1] = list[j];
        }
        list[j+1] = key;
        printStep(list, n, i);
    }
}
int ascend(int x, int y) { return y - x; }
int descend(int x, int y) { return x - y; }
void main()
{
    int list1[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7};
    int list2[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7};
    int list3[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7};
    int list4[9] = { 5, 3, 8, 4, 9, 1, 6, 2, 7};
    printArray(list1, 9, "Original ");
    insertion_sort_fn(list1, 9, descend);
    printArray(list1, 9, "Insertion-De ");
    printArray(list2, 9, "\n\nOriginal ");
    insertion_sort_fn(list2, 9, ascend);
    printArray(list2, 9, "Insertion-As ");
    printf("\n======================================");
    printArray(list3, 9, "\n\nOriginal ");
    selection_sort(list3, 9);
    printArray(list3, 9, "Selection ");
    printArray(list4, 9, "\n\nOriginal ");
    bubble_sort(list4, 9);
    printArray(list4, 9, "Bubble ");
}