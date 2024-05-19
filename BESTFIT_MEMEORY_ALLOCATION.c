#include<stdio.h>
int allocateadd(int avai_add[],int s,int n){
    int index = -1;
    for(int i=0;i<n;i++){
        if(avai_add[i]>s && avai_add[i]!=0){
            index = avai_add[i];
            avai_add[i] = 0;
            return index;
        }
    }
    return index;
}

int main(){
    int n;
    printf("Enter number of memory block or chunks");
    scanf("%d",&n);
    int avai_add[n];
    printf("Enter the chunks ");
    for(int i=0;i<n;i++){
        scanf("%d",&avai_add[i]);
    }
    printf("Enter the number of process request  ");
    int a;
    scanf("%d",&a);
    int allo[a];
    printf("Enter all process request ");
    for(int i=0;i<a;i++){
        scanf("%d",&allo[i]);
    }
    // Using only External Fragmentation
    // Best Fit
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(avai_add[j]>avai_add[j+1]){
                int a = avai_add[j];
                avai_add[j] = avai_add[j+1];
                avai_add[j+1] = a;
            }
        }
    }
    for(int i=0;i<a;i++){
        int s = allo[i];
        int p = allocateadd(avai_add,s,n);
        if(p==-1){
            printf("Memory Chunk is not available for %d\n",s);
        }else{
            printf("Memory Chunk of %d is allocated to %d\n",p,s);
        }
    }
    printf("Thanks");
}