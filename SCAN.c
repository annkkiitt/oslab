//Disk scheduling 
#include <stdio.h>
#include <math.h>

int main(){
    int n;
    int track;
    printf("Enter the total number of tracks: ");
    scanf("%d",&track);
    printf("Enter the total size of sequence\n");
    scanf("%d",&n);
    int seq[n];

    printf("Enter the sequence\n");
    for(int i=0;i<n;i++)
        scanf("%d",&seq[i]);

    int initial;
    printf("Enter the initial count: ");
    scanf("%d",&initial);

    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(seq[i]>seq[j]){
                int temp = seq[i];
                seq[i] = seq[j];
                seq[j] = temp;
            }
        }
    }

    int ans =0;
    int order;
    int initalPre;

    int i;
    for(i=0;i<n;i++){
        if(seq[i] > initial){
            break;
        }
    }

    printf("Enter the order 1).Increasing order 2).Decreasing order\n");
    scanf("%d",&order);

    switch(order){
        case 1: {
             ans = abs(initial - track) + track + seq[i-1];
             break;
        }
        case 2: {
            ans = abs(initial-0) + seq[n-1];
            break;
        }
        default: return 0;
    }
    printf("Seek count is : %d",ans);

}
    