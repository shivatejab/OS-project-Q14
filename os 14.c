#include<stdio.h>
int n;
struct process
{
	 char process_name;
      int arrival_time, burst_time, ct, waiting_time, turnaround_time, priority;
      int status;
}process_queue[10];
void Arrival_Time_Sorting()
{
      struct process temp;
      int i, j;
      for(i = 0; i < n - 1; i++)
      {
            for(j = i + 1; j < n; j++)
            {
                  if(process_queue[i].arrival_time > process_queue[j].arrival_time)
                  {
                        temp = process_queue[i];
                        process_queue[i] = process_queue[j];
                        process_queue[j] = temp;
                  }
            }
      }
}
int main()
{
	int i;
	  int time = 0, burst_time = 0, largest,a=0,b=0,x[10];
      char c;
      float wait_time = 0, turnaround_time = 0, average_waiting_time, average_turnaround_time;
	printf("enter the no. of processes\n");
scanf("%d",&n);
  for(i = 0, c = 'P'; i < n; i++, c++)
      {
            process_queue[i].process_name = c;
            printf("\nEnter Details For Process[%C]:\n", process_queue[i].process_name);
            printf("Enter Arrival Time:\t");
            scanf("%d", &process_queue[i].arrival_time );
            printf("Enter Burst Time:\t");
            scanf("%d", &process_queue[i].burst_time);x[i]=process_queue[i].burst_time;
            printf("Enter Priority:\t");
            scanf("%d", &process_queue[i].priority);
            process_queue[i].status = 0;
            burst_time = burst_time + process_queue[i].burst_time;
      }
      Arrival_Time_Sorting();  for(i=0;i<n;i++)
	  {
	  	x[i]=process_queue[i].burst_time;
	  }
	  process_queue[9].priority = -9999;
   for(time = process_queue[0].arrival_time; time <= burst_time+1;)
      {
      	 largest = 9;
      	for(i=0;i<n;i++)
      	{
      		
      
      		 if(process_queue[i].arrival_time <= time && process_queue[i].priority > process_queue[largest].priority && process_queue[i].status != 1)
                  {
                        largest = i;
                   
                  }
                if(process_queue[largest].burst_time==0 && process_queue[i].status != 1)
      		{
      			process_queue[i].status = 1;process_queue[largest].priority=0;
      			process_queue[largest].ct=time;
      			printf("the time is %d\n",process_queue[largest].ct);
			  i=-1;
      		
      		}
      	}
      	
      	time++;(process_queue[largest].burst_time)--;
      	

      
      }printf("\n*****************************************************\n");
      for(i=0;i<n;i++)
      {
      	process_queue[i].turnaround_time=(process_queue[i].ct)-(process_queue[i].arrival_time);a=a+process_queue[i].turnaround_time;
      	process_queue[i].waiting_time=(process_queue[i].turnaround_time)-(x[i]);b=b+process_queue[i].waiting_time;
      }    	printf("PNO\tAT\tCT\tTA\t\WTt\n");
      for(i=0;i<n;i++)
      {
  
      	printf("%c\t%d\t%d\t%d\t%d\n",
		  process_queue[i].process_name,
		  process_queue[i].arrival_time,
		  process_queue[i].ct,
		  process_queue[i].turnaround_time,
		  process_queue[i].waiting_time);
		  
      }
      printf("THE AVERAGE TURNAROUND TIME IS \t %d\n",a/n);
          printf("THE AVERAGE WAITING TIME IS \t %d\n",b/n);printf("\n*****************************************************\n");
}








