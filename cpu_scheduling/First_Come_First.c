#include<stdio.h>
typedef struct {
    int arrT;
    int compT;
    int burstT;
    int tat;
    int wT;
}process;
process pr[50],temp;
int main(){
    int n,i,j,com=0;
    float avgTT,avgWT,tTT=0,tWT=0;
    printf("Enter the number of process : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the arrival time of p%d : ",i);
        scanf("%d",&pr[i].arrT);
        printf("Enter the burst time of p%d : ",i);
        scanf("%d",&pr[i].burstT);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(pr[j].arrT>pr[j+1].arrT){
                temp=pr[j];
                pr[j]=pr[j+1];
                pr[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        if(com<pr[i].arrT){
            com=pr[i].arrT;
        }
        pr[i].compT=pr[i].burstT+com;
        pr[i].tat=pr[i].compT-pr[i].arrT;
        pr[i].wT=pr[i].tat-pr[i].burstT;
        com=pr[i].compT;
    }
    printf("process\tarr\ttt\twt\n");
    for(i=0;i<n;i++){
        printf("p%d\t%d\t%d\t%d\n",i,pr[i].arrT,pr[i].tat,pr[i].wT);
        tTT+=pr[i].tat;
        tWT+=pr[i].wT;
    }
    avgTT=tTT/n;
    avgWT=tWT/n;
    printf("The average waiting time is : %.2f \n",avgWT);
    printf("The average turn around time is : %.2f \n",avgTT);
    return 0;
}