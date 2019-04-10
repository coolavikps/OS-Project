#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,a[10],base=60,st[10];
    int totwt=0,totta=0,ft[19];
    float awt,ata;

   	printf("UNIX SCHEDULER");

    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and arrival time\n");
    for(i=0;i<n;i++)
    {
        printf("\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Arrival Time:");
        scanf("%d",&a[i]);
        p[i]=i+1;           //contains process number
    }
 printf("Process Number\t\t\t\tBurst Time\t\t\tArrival Time\n");
	for(i=0;i<n;i++){
	printf("    P[%d]\t\t\t\t   %d\t\t\t\t     %d\t\t\t\t\n",p[i],bt[i],a[i]);
	}
	
	for(i=0;i<n;i++){
	pr[i]=(bt[i]/2)+base;
	}
	
	
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
        
         temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }

    printf("\n\n\nProcess Number\t\t\t\tBurst Time\t\t\tArrival Time\t\t\tPriority\n");
	for(i=0;i<n;i++){
	printf("    P[%d]\t\t\t\t    %d\t\t\t\t     %d\t\t\t\t    %d\n",p[i],bt[i],a[i],pr[i]);
	}
	
	for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(pr[i]<pr[j])
            {
                temp=pr[i];
                pr[i]=pr[j];
                pr[j]=temp;
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
        for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            st[i]=a[i];
            wt[i]=st[i]-a[i];
            ft[i]=st[i]+bt[i];
            tat[i]=ft[i]-a[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-a[i];
            ft[i]=st[i]+bt[i];
            tat[i]=ft[i]-a[i];
        }
        totwt+=wt[i];
        totta+=tat[i];
    }
     awt=(float)totwt/n;
    ata=(float)totta/n;
    printf("\nProcess\tArrivaltime\tBursttime\tPriority\tWaitingtime\tTurnaround time");
    for(i=0; i<n; i++)
        printf("\nP[%d]\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",p[i],a[i],bt[i],pr[i],wt[i],tat[i]);
    printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);
    getch();
	
return 0;
}
 
