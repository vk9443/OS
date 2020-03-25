#include<stdio.h> 
int main() 
{ 
  int count,n;
  int time=0;
  printf("\n\nEnter the Total number of Process:\t "); 
  scanf("%d",&n);
  int waiting_time,turn_around_time,arrival_time[n],burst_time[n],rt[n],t[n];
  for(count=0;count<n;count++) 
  { 
    printf("\nEnter Arrival Time Process %d :",count+1); 
    scanf("%d",&arrival_time[count]); 
    if(arrival_time[count] == 0)
    {
    	printf("\nplease enter the arival time greater than 0\n");
    	scanf("%d",&arrival_time[count]); 
	}
	printf("\nEnter Burst Time for Process %d :",count+1); 
    scanf("%d",&burst_time[count]); 
    rt[count]=burst_time[count]; 
  } 
	printf("\n\n TIME TO SHIFT FROM ONE PROCESS TO OTHER = 2\n\n");
  printf("\n\nProcess\t  Arrival Time  |  Burst Time   |Turnaround Time|Waiting Time\n\n"); 



 int i,flag=0;
 
for(count=0;count<n;count++)
{	
int a;
int min=100,min2=100;
for(i=0;i<n;i++){
	if(time!=0){
	if(rt[i]<=min && rt[i]!=0 && arrival_time[i]<=time){
		a=i;
		min=rt[i];
	}
}
else{
	 if(arrival_time[i]<=min){
		a=i;
		min=arrival_time[i];
	}
}
}
if(time==0){

for(i=0;i<n;i++){
if (min==arrival_time[i])
flag++;
}
}
if(flag>1){
for(i=0;i<n;i++){

	if(arrival_time[i]<=min && rt[i]<=min2){
		a=i;
		min=arrival_time[i];
		min2=rt[i];
	}
	flag=0;
}
}
if(arrival_time[a]>time){
	time=arrival_time[a]+rt[a];
	rt[a]=0;
	t[a]=time;
}
else{

time=time+rt[a]	;
	rt[a]=0;
	t[a]=time;
}
}

float avg_wt,avg_tat;
float tot_wt=0,tot_tat=0;
int a;

for (count=0;count<n;count++){ 
	if(count == 0)
	{
		a=0;
	}
	else
	{
		a=2;
	}
      printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",count+1,arrival_time[count],burst_time[count],t[count]-arrival_time[count],(t[count]+a)-arrival_time[count]-burst_time[count]);
	  tot_wt = tot_wt + (t[count]+a)-arrival_time[count]-burst_time[count] ;
	   tot_tat = tot_tat + t[count]-arrival_time[count];
      waiting_time+=time-arrival_time[count]-burst_time[count]; 
      turn_around_time+=time-arrival_time[count]; 
      
}
avg_wt = tot_wt / n;
avg_tat = tot_tat / n;

printf(" \n\nAverage waiting time : %f",avg_wt);
printf("\n\nAverage turn_arounf time : %f",avg_tat);

}
