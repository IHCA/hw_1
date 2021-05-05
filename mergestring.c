#include<sys/time.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"mergestring.h"
int main(){
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;
    char *arr[1000000] = {NULL};
    int input, j, i=0;
    char buf[8192];
    while(fgets(buf, 8192, stdin) != NULL) {
        arr[i++] = strdup(buf);
    }
    int len = i;
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
    for (int i = 0 ; i < len; i++) {
        free(arr[i]);
    }
}
void mergesort(char* arr[], int left, int right){
    if(left<right){
        int mid = (left+right)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
void merge(char* arr[], int left, int mid, int right){
    int lenA = mid-left+1;
    int lenB = right-mid;
    char **A = malloc(sizeof(char*) * lenA), **B = malloc(sizeof(char*) * lenB);
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
        if(strcmp(A[i],B[j])<0){
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
    free(A); free(B);
}

