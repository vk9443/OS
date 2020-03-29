/*
Consider a scheduler which schedules the job by considering the arrival time of the
processes where arrival time if given as 0 is discarded or displayed as error. The scheduler
implements the shortest job first scheduling policy, but checks the queue of the processes after
the every process terminates and time taken for checking and arranging the process according to
the shortest job is 2 time unit. Compute the waiting time, turnaround time and average waiting
time and turnaround time of the processes. Also compute the total time taken by the processor to
compute all the jobs.
The inputs for the number of requirements, arrival time and burst time should be provided by the
user.
Consider the following units for reference.
Process Arrival time Burst Time
1 0 6
2 3 2
3 5 1
4 9 7
5 10 5
6 12 3
7 14 4
8 16 5
9 17 7
10 19 2
Develop a scheduler which submits the processes to the processor in the defined scenario, and
compute the scheduler performance by providing the waiting time for process, turnaround time
for process and average waiting time and turnaround time.

*/
#include<stdio.h>
#include<stdlib.h>
struct process
{
    int process_no;
    int p_arrival;
    int process_burst;

};
struct result
{
    int final_pno;
    int waiting_time;
    int turnaround_time;
};
int main()
{
printf("\n\n\t\t\t\t\t*PROBLEM STATEMENT*\n");
printf("\n\t\t3. Consider a scheduler which schedules the job by considering the arrival time of the \n\tprocesses where arrival time if given as 0 is discarded or displayed as error. The scheduler \n\timplements the shortest job first scheduling policy, but checks the queue of the processes after \n\tthe every process terminates and time taken for checking and arranging the process according \n\tto the shortest job is 2 time unit. Compute the waiting time, turnaround time and average waiting \n\ttime and turnaround time of the processes. Also compute the total time taken by the processor \n\tto compute all the jobs.");
	printf("\n\n");
	system ("PAUSE"); 
	
	system("cls");
	struct process prc_obj[30];
	struct result res[30];
	int i,n,j,choice1,choice2,pos,min,pro_exec,time=0,end,k,flag,ideal_time;
X: Y:	printf("Enter the no. of processes-");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		printf("\n\t For Process P%d\n",i);
		prc_obj[i].process_no=i;
		printf("\t\tEnter Arrival Time:");
		scanf("%d",&prc_obj[i].p_arrival);
		printf("\t\tEnter Burst Time:");
		scanf("%d",&prc_obj[i].process_burst);

	}
	printf("\n\tPress 1 to proceed to result or press 2 to re-enter the details ");
	scanf("%d",&choice1);
	if(choice1==2){
		
			system("cls");
			goto X;
	}time!=0;
	for(i=1;i<=n;i++)
	{
		if(prc_obj[i].p_arrival==0)
        {
            printf("\t\tProcess- %d Discared! Incorrect arrival time provided.",i);
            for(j=i;j<n;j++)
            {
                prc_obj[j]=prc_obj[j+1];
            }
            time=prc_obj[i].p_arrival; 
            n--;
            i--;
        }
        if(prc_obj[i].p_arrival<time )
        {
            time=prc_obj[i].p_arrival;
        }
	}
	end = n;
	min=0;
	k=1;
	while(n>0)
	{
	    pro_exec=prc_obj[1].process_burst;
	    ideal_time=time+2;
	    flag=0;
		for(j=1;j<=n;j++)
		{

			if(pro_exec>=prc_obj[j].process_burst && prc_obj[j].p_arrival<=time)
			{
				pro_exec = prc_obj[j].process_burst;
				pos=j;
				flag=1;
			}
			if(ideal_time>time && ideal_time>prc_obj[j].p_arrival && prc_obj[j].p_arrival!=time)
            {
                ideal_time=prc_obj[j].p_arrival;
            }
		}
		if(flag==1)
        {
            if(pos==1)
            {
                res[k].waiting_time=time-prc_obj[pos].p_arrival;
                time = time + pro_exec;
                res[k].turnaround_time=time-prc_obj[pos].p_arrival;
            }
            else
            {
                res[k].waiting_time=time-prc_obj[pos].p_arrival+2;
                time = time + pro_exec;
                res[k].turnaround_time=time-prc_obj[pos].p_arrival+2;
            }//*vk*
            res[k].final_pno=prc_obj[pos].process_no;
            for(i=pos;i<n;i++)
            {
               prc_obj[i]=prc_obj[i+1];
            }
            n--;
            k++;

        }
        else //CPU ideal time
        {
            time = ideal_time;
        }

        }
        system("cls");
        printf("\n\n==================================================================================================================\n");
        printf("Order of execution of processes are:\n");
        for(i=1;i<=end;i++)
        {
        printf(" P%d-->",res[i].final_pno);	
		}
		printf("FINISH");
		printf("\n\n==================================================================================================================\n");
         printf("\n\n\n\t ====================================================================");
            printf("\n\t *  PROCESS   :   WAITING TIME   :   TURNAROUND TIME");
        for(i=1;i<=end;i++)
        {
            printf("\n\t *  P%d        :    %d             :         %d      ",res[i].final_pno,res[i].waiting_time,res[i].turnaround_time);

        }
printf("\n\t ====================================================================");

	float sum2=0;
float sum1=0;
	for(i=1;i<=end;i++)
	{
		sum2=sum2+res[i].turnaround_time;}
		float average_tat=sum2/end;
		printf("\n\tAverage Turn around time is: %f",average_tat);
		for(i=1;i<=end;i++)
	{
		sum1=sum1+res[i].waiting_time;}
		float average_wt=sum1/end;
			printf("\n\tAverage Waiting time is: %f",average_wt);
		printf("\n\tPress 1 to calculate again or press 2 to exit: ");
	scanf("%d",&choice1);
	if(choice1==1){
		
			system("cls");
			goto Y;
	}
		
    return 0;
}
/* Coded by Vinod Kumar */
