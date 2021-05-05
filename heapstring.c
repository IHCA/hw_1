#include"heapstring.h"
#include<sys/time.h>
#include<stdio.h>
#include<string.h>
char *arr[1000000];
int main(){
    struct  timeval start;
    struct  timeval end;
    unsigned  long diff;
    char input[128];
    int j, i=0;
    while(scanf("%s",input)!=EOF){
        arr[i]=strdup(input);
        i++;
    }
    gettimeofday(&start, NULL);
    myheap(arr,i);
    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("Sorting performance %ld us (equal %f sec)\n", diff, diff / 1000000.0);
    /*for(j=0;j<i-1;j++){
        printf("%s ",arr[j]);
    }
    printf("%s\n",arr[i-1]);*/
}
void myheap(char*arr[],int number){
    int i;
    char tmp[128];
    for(i=number/2-1;i>=0;i--){
        myheapadjust(arr,i, number);
    }
    for(i=number-1;i>1;i--){
        strcpy(tmp, arr[0]);
        strcpy(arr[0], arr[i]);
        strcpy(arr[i], tmp);
        myheapadjust(arr,0, i-1);
    }
    strcpy(tmp, arr[0]);
    strcpy(arr[0], arr[1]);
    strcpy(arr[1], tmp);
}
void myheapadjust(char*arr[],int root, int number){
    int left=root*2+1;
    int right=root*2+2;
    int key;
    char*tmp;
    if(left<number&&(strcmp(arr[left],arr[root])>0))key=left;
    else key=root;
    if(right<number&&(strcmp(arr[right],arr[key])>0))key=right;
    if(key!=root){
        tmp= arr[root];
        arr[root]= arr[key];
        arr[key]= tmp;
        myheapadjust(arr,key,number);
    }
}
