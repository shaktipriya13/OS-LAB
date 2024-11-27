#include<stdio.h>

struct block{
    int id,size,name;
};
struct process{
    int size;
    char name[20];
};

int main(){
    int np,nb;
    struct block b[10];
    struct process p[10];
    printf("Enter number of blocks:");
    scanf("%d",&nb);
    for(int i=0;i<nb;++i){
        printf("Enter size of block- %d:",i+1);
        scanf("%d",&b[i].size);
    }

    printf("Enter number of processes:%d",&np);
    scanf("%d",&np);
    for(int i=0;i<np;++i){
        printf("Enter id of Process:");
        scanf("%s",&p[i].name);
        printf("Enter the size of process:");
        scanf("%d",&p[i].size);
    }

    // first fit allotication
    



}