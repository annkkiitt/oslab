//Disk scheduling 
#include <stdio.h>
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

    int seekCount=0;
    for(int i=0;i<n;i++){
        seekCount += abs(seq[i] - initial);
        initial = seq[i];
    }
    printf("Seek Count is : %d ",seekCount);
}