//Page replacement algo
#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of page: ");
    scanf("%d",&n);

    int reference[n];
    printf("Enter the page number: ");
    for(int i=0;i<n;i++){
        scanf("%d",&reference[i]);
    }

    int f;
    printf("Enter the frame size: ");
    scanf("%d",&f);

    int frame[f];
    for(int i=0;i<f;i++){
        frame[i] = -1;
    }

    int j=0;
    int pageFault=0;

    printf("Reference\tFrames\n");
    for(int i=0;i<n;i++){
        printf("%d\t",reference[i]);
        int avail=0;
        for(int j=0;j<f;j++){
            if(reference[i]==frame[j]){
                avail=1;
            }
        }

        if(avail==0){
            frame[j] = reference[i];
            j= (j+1)%f;
            pageFault++;
            for(int k=0;k<f;k++){
                printf("%d ",frame[k]);
            }
        }
        printf("\n");        
    }

    printf("Page fault is : %d",pageFault);
    printf("Page hit : %d",n-pageFault);
    printf("Hit ratio: %f",(float)(n-pageFault)/n);

}