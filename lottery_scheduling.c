#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	int n,i,j,k,temp=0,flag=0;
	int process[100];
	int burst[100],priority[100],pos,completed[100],pcompleted=0;
	int ctime=0,quantum=5,tbt=0;
	int z=0,lottery[100],ticket[100][100],q=0;

	printf("Enter Number Of Process: ");
	scanf("%d",&n);
    getchar();
	if(n<=0)
	{
		printf("Invalid number Of processes\n");
		exit(0);
	}

	for(i=0;i<n;i++)
	{
		process[i] = i;
		completed[i] = -1;
	}
	for(i=0;i<n;i++)
	{
		printf("\nEnter The Burst Time For Process %d:",process[i]);
		scanf("%d",&burst[i]);
        getchar();
		printf("Enter The Priority For Process %d(b/w 1 to %d): ",process[i],n);
		scanf("%d",&priority[i]);
        getchar();
	}
	
	//sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }
 
        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
 
        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;
 
        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;

        if(burst[i]<0)
		{
			flag = 1;
		}
    }
    
    if(flag==1)
    {
    	printf("Invalid burst time\n");
    	exit(0);
	}
    
    printf("\n |Priority |  Process   |  Burst |");
	
	for(i=0;i<n;i++)
	{
		printf("\n |   %d \t   |    %d    \t|   %d    |",priority[i],process[i],burst[i]);
		tbt = tbt + burst[i];
	}
	printf("\nQuantum time is %d sec\n",quantum);
	
	//assign one or more lottery numbers to each process
	int p=0,m_ticket=0;
	printf("\n\n\nPriority  process  Burst  Lottery  Tickets");
	for(i=0;i<n;i++)
	{
		lottery[i] = (burst[i]/quantum) + (n-priority[i]);
		for (z=0;z<lottery[i];z++) 
		{
            ticket[i][z] = p++;
            m_ticket = p;
        }
       
		printf("\n  %d\t    %d\t    %d \t    %d\t",priority[i],process[i],burst[i],lottery[i]);
		for(z=0;z<lottery[i];z++)
		{
            printf("  ::%d:: ",ticket[i][z]);
    	}   
	}
	
	while(ctime!=tbt)
	{   
		int winner = (rand()%m_ticket);
		for(i =0;i<n;i++)
		{   
			if(ticket[i][0] == -1)
			{
				continue;
			}		
			for(z=0;z<lottery[i];z++)
			{   
				if(ticket[i][z]==winner)
					q=i;
			}
		}
		printf("\n\n-------------------------------------");
		printf("<<<<   Winner: %d   >>>>",winner);
		printf("-------------------------------------\n");
		
			burst[q]-=quantum;
			
			if (burst[q]>0) 
			{
				ctime+=quantum;
			} 
			else 
			{
				ctime+=(burst[q]+quantum);
			}
			
			if(burst[q]<0) 
			{
					burst[q]=0;
			}
			if(burst[q] == 0)
			{   
				pcompleted++;
				completed[q] = q;
				for(i=0,j=0;j<lottery[q] && pcompleted != n;i++)
				{  
					if(completed[i] != -1)
					{   
						if(i == n-1)
						{
							i = -1;
						}
						continue;
					}
					lottery[i]++;
					ticket[i][lottery[i]-1] = ticket[q][j];
					ticket[q][j++] = -1;
					if(i == n - 1)
					{
						i = -1;
					}
				}
			}
			printf("\n\t\t\t\t  Process that is Running Is: %d",process[q]);
			printf("\n\t   (Total Time << Remaining Burst Time Of This Process << process ):  ( %d  <<  %d  <<  %d )\n",ctime,burst[q],process[q]);
		
		
		printf("\n\n\nPriority  process  Burst  Lottery  Tickets");
		for(i=0;i<n;i++)
		{
			printf("\n  %d\t    %d\t    %d \t    %d\t",priority[i],process[i],burst[i],lottery[i]);
			for(z=0;z<lottery[i];z++)
			{
				printf("  ::%d:: ",ticket[i][z]);
			}   
		}
		if(pcompleted == n)
					{   
						printf("All programs finished execution\n");
						exit(0);
					}
	}
	
}
