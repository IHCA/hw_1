#include<sys/time.h>
#include<stdio.h>
#include"mergesort.h"
int main(){
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;
    int arr[1000000];
    int input, j, i=0;
    while(scanf("%d",&input)!=EOF){
        arr[i]=input;
        i++;
    }
    i--;
    gettimeofday(&start, NULL);
    mergesort(arr, 0, i);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec; 
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);
    /*for(j=0;j<i;j++){
        printf("%d ",arr[j]);
    }
    printf("%d\n",arr[j]);*/
}
void mergesort(int arr[], int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
void merge(int arr[], int left, int mid, int right){
    int lenA = mid-left+1;
    int lenB = right-mid;
    int A[lenA], B[lenB];
    int i, j, k;
    for(i=0;i<lenA;i++){
        A[i]=arr[left+i];
    }
    for(j =0;j<lenB;j++){
        B[j] = arr[mid+1+j];
    }
    i=j=0;
    k=left;
    while(i<lenA&&j<lenB){
        if(A[i]<B[j]){
            arr[k]=A[i];
            i++;
            k++;
        }
        else{
            arr[k]=B[j];
            j++;
            k++;
        }
    }
    while(i<lenA){
        arr[k]=A[i];
        k++;
        i++;
    }
    while(j<lenB){
        arr[k]=B[j];
        k++;
        j++;
    }
}

