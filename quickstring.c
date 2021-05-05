#include<stdio.h>
#include<string.h>
#include <sys/time.h>
#include"quickstring.h"
int main(){
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;
    char *arr[1000000];
    int j, i=0;
    char input[128];
    while(scanf("%s",input)!=EOF){
        arr[i]=strdup(input);
        i++;
    }
    i--;
    gettimeofday(&start, NULL);
    myquicksort(arr, 0, i);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec; 
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);
    /*for(j=0; j<=i-1; j++){
        printf("%s ",arr[j]);
    }
    printf("%s\n",arr[j]);*/
}
int partition2(char *arr[], int left, int right){
    int i=left+1, j=right;
    char tmp[128];
    while(i<j){
        while((strcmp(arr[j],arr[left])>=0)&&i<j){
            j--;
        }
        while((strcmp(arr[left],arr[i])>0)&&i<j){
            i++;
        }
        strcpy(tmp,arr[i]);
        strcpy(arr[i],arr[j]);
        strcpy(arr[j],tmp);
    }
    if(strcmp(arr[left],arr[i])>0){
        strcpy(tmp,arr[left]);
        strcpy(arr[left],arr[i]);
        strcpy(arr[i],tmp);
    }
    return i;
}
void myquicksort(char *arr[], int left, int right){
    if(left<right){
        int div;
        div = partition2(arr, left, right);
        myquicksort(arr, left, div-1);
        myquicksort(arr, div, right);
    }
}
