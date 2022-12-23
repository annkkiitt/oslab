#include <stdio.h>

int main()
{
    int n,m;
    printf("Enter the number of process: ");
    scanf("%d",&n);

    printf("Enter the number of resouces: ");
    scanf("%d",&m);

    int allocation[n][m];
    printf("Enter the allocation matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&allocation[i][j]);
        }
    }

    int max[n][m];
    printf("Enter the max matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }

    int available[m];
    printf("Enter the available resouces: ");
    for(int i=0;i<m;i++)    scanf("%d",&available[i]);

    int remainingNeed[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            remainingNeed[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("Allocation      Max       Need\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",allocation[i][j]);
        }
        printf("\t");
        for(int j=0;j<m;j++){
            printf("%d ",max[i][j]);
        }
        printf("\t");
        for(int j=0;j<m;j++){
            printf("%d ",remainingNeed[i][j]);
        }
        printf("\n");
    }

    int finish[n],safeSequence[n];
    for(int i=0;i<n;i++)    finish[i] = 0;

    int ind=0;
    for(int k=0;k<n+1;k++){
        for(int i=0;i<n;i++){
            if(finish[i]==0){
                int flag=0;
                for(int j=0;j<m;j++){
                    if(remainingNeed[i][j] > available[j]){
                        flag=1;
                        break;
                    }
                }

                if(flag==0){
                    safeSequence[ind++] = i;
                    for(int k=0;k<m;k++){
                        available[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    int flag=1;
    for(int i=0;i<n;i++){
        if(finish[i]==0){
            flag=0;
            printf("The machine isn't in safe state");
            break;
        }
    }

    if(flag==1){
        printf("The safe sequence is : ");
        for(int i=0;i<n;i++){
            printf("P%d -> ",safeSequence[i]);
        }
    }
    

}