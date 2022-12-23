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

    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(seq[i]>seq[j]){
                int temp = seq[i];
                seq[i] = seq[j];
                seq[j] = temp;
            }
        }
    }

    int seekCount = 0;

    seekCount = abs(seq[n-1] - initial) + abs(seq[n-1] - seq[0]);
    printf("%d",seekCount);
}