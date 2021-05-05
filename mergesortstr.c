#include<sys/time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char*arr[500010];
char*brr[500010];
char*line[1000010];
char*l[500010];
char*r[500010];
void merge(char *arr[],char*l[], int left,char*r[], int right);
void mergesort(char *arr[], int cnt);
int main(){
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;
    char input[105];
    int j, i=0, ii=0, k;
    for(k=0;k<500000;k++){
        scanf("%s",input);
        arr[k]=strdup(input);
    }
    for(k=0;k<500000;k++){
        scanf("%s",input);
        brr[k]=strdup(input);
    }
    gettimeofday(&start, NULL);
    mergesort(arr,500000);
    mergesort(brr,500000);
    merge(line,arr,500000,brr,500000);
    for(k=0;k<500000;k++){
        free(arr[k]);
        free(brr[k]);   
    }
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec; 
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);
}
void mergesort(char *arr[], int cnt){
    if(cnt<2){
        return;
    }
    int mid=cnt/2;
    for(int i=0;i<mid;i++){
        l[i]=strdup(arr[i]);
    }
    for(int i=mid;i<cnt;i++){
        r[i-mid]=strdup(arr[i]);
    }
    mergesort(l, mid);
    mergesort(r, cnt-mid);
    merge(arr,l, mid,r , cnt-mid);
}

void merge(char *arr[],char*l[], int left,char*r[], int right){
    int i=0,j=0,k=0;
    while(i<left&&j<right){
        if(strcmp(l[i],r[j])<0){
            arr[k]=l[i];
            i++;
            k++;
        }
        else{
            arr[k]=r[j];
            j++;
            k++;
        }
    }
    while(i<left){
        arr[k]=l[i];
        k++;
        i++;
    }
    while(j<right){
        arr[k]=r[j];
        k++;
        j++;
    }
}

