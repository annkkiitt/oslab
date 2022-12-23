//Shortest seek time first
//Disk scheduling 
#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(){
    int n;
    printf("Enter the total size of sequence\n");
    scanf("%d",&n);
    int seq[n];

    printf("Enter the sequence\n");
    for(int i=0;i<n;i++)
        scanf("%d",&seq[i]);

    int initial;
    printf("Enter the initial count: ");
    scanf("%d",&initial);

    int completed[n];
    for(int i=0;i<n;i++){
        completed[i] = -1;
    }
    
    int seekCount = 0;
    
    for(int i=0;i<n;i++){
        int minimum = INT_MAX;
        int minIndex=-1;
        for(int j=0;j<n;j++){
            if(completed[j]==-1 && abs(seq[j]-initial) < minimum){
                minimum = seq[j];
                minIndex = j;
            }
        }

        completed[minIndex] = 1;
        seekCount += abs(minimum-initial);
        initial = minimum;
    }

    printf("%d",seekCount);
}