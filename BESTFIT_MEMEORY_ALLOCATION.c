#include<stdio.h>
//Showing which reference is best to fit.
int allocateadd(int references[],int s,int n){
    int index = -1;
    for(int i=0;i<n;i++){
        if(references[i]>s && references[i]!=0){
            index = references[i];
            references[i] = 0;
            return index;
        }
    }
    return index;
}

int main(){
    int n;
    printf("Enter number of memory block or chunks");  //How many reference are there
    scanf("%d",&n);
    int references[n];
    printf("Enter the chunks "); //Size of each reference
    for(int i=0;i<n;i++){
        scanf("%d",&references[i]);
    }
    printf("Enter the number of process request  "); // How many process are requesting for memory
    int a;
    scanf("%d",&a);
    int allo[a];
    printf("Enter all process request "); //How much memory size is requested by each process 
    for(int i=0;i<a;i++){
        scanf("%d",&allo[i]);
    }
    // Using only External Fragmentation
    // Best Fit
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(references[j]>references[j+1]){
                int a = references[j];
                references[j] = references[j+1];
                references[j+1] = a;
            }
        }
    }
    for(int i=0;i<a;i++){
        int s = allo[i];
        int p = allocateadd(references,s,n);
        if(p==-1){
            printf("Memory Chunk is not available for %d\n",s); //Whether for each process request is available or not
        }else{
            printf("Memory Chunk of %d is allocated to %d\n",p,s);
        }
    }
}