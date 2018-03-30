#include<stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <sys/queue.h>
struct process {
    int ID;
    int arrivalTime;
    int CPUBurst;
    int startTime;
    int endTime;
    int tickets;
};

const char* getfield(char* line, int num)
{   
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return 0;
}


const int getNum(int n, int lottery[50],int sum){
     int temprange=0;
    int min =0;
    int max =0;
int el = (rand())%(sum+1);


for(int i=0;i<n;i++){
min =temprange+1;
max = temprange+lottery[i];
temprange=max;

if(el>=min && el<= max){
         
return i;
}
}
}
    





int main()

{
         srand(time(NULL)); 

    

int count,n,time,remain,flag=0,time_quantum;

int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];

char *inname = "Input2.in";
    FILE *infile;
    char line_buffer[500]; 
    int line_number;

    infile = fopen(inname, "r");
    if (!infile) {
        printf("Couldn't open file %s for reading.\n", inname);
        return 0;
    }
    printf("Opened file %s for reading.\n", inname);

    line_number = 0;
    char buf [50];
    char s2 [50];
    int z =0;
    int k = 0;

int burst [10];
    while (fgets(line_buffer, sizeof(line_buffer), infile)) {
    
            
        ++line_number;
        /* note that the newline is in the buffer */
        printf("%4d: %s \n", line_number, line_buffer);
        sprintf(s2,"%s",getfield(line_buffer,3));

        
    //     for(int x =0; x<4;x++){
    //    buf[x]= s1[x];
    //     }
    if ( z >= 2){
        burst[k] = atoi(s2);
        k++;
        }
                    // printf("Field 3 would be %s\n", s2);
                    z++;
            // printf("Field 3 would be %c\n", buf[line_number]);
            

    }
n = line_number-2;
remain=n;
struct process pall[100];
int l = 2;
 char line1[128];
    char line2[128];

FILE *f;

    f = fopen("Input2.in", "r");
    if (!f) {
       printf("error");
    } else {
        fscanf(f, "%127[^\n]\n%127[^\n] ", line1, line2);
        // fscanf(f, "%127[^\n]\n%127[^\n] ", line3, line4);
        // fscanf(f, "%127[^\n]\n%127[^\n] ", line5, line6);


        // printf("1:%s\n", line1);
        // printf("2:%s\n", line2);
        // printf("3:%s\n", line3);
        // printf("4:%s\n", line4);
        //  printf("5:%s\n", line5);
        // printf("6:%s\n", line6);
        
        sscanf(line1,"%d",&time_quantum);
        // sscanf(line2,"%d",&totalTickets);

    }


    ///////////////////////////////////////////


char *innname = "Input2.in";
    FILE *innfile;
    char linee_buffer[500]; 
    int linee_number;

    innfile = fopen(innname, "r");
    if (!innfile) {
        printf("Couldn't open file %s for reading.\n", innname);
        return 0;
    }
    printf("Opened file %s for reading.\n", innname);

    linee_number = 0;
    char ss2 [50];
    int zz =0;
    int kk = 0;
int sum=0;
int lottery [10];
    while (fgets(linee_buffer, sizeof(linee_buffer), innfile)) {
    
            
        ++linee_number;
        /* note that the newline is in the buffer */
        sprintf(ss2,"%s",getfield(linee_buffer,4));

        
    //     for(int x =0; x<4;x++){
    //    buf[x]= s1[x];
    //     }
    if ( zz >= 2){
        lottery[kk] = atoi(ss2);
        sum +=lottery[kk];
        kk++;
        }
                    // printf("Field 3 would be %s\n", s2);
                    zz++;
            // printf("Field 3 would be %c\n", buf[line_number]);
            

    }

    ////////////////////////////////////////////




int temprange =0;
for(count=0;count<n;count++)
{
    bt [count] = burst[count];

// printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1);


rt[count]=bt[count];
pall[count].ID=count+1;
pall[count].arrivalTime= 0;
pall[count].CPUBurst= bt[count];
pall[count].startTime=0;
l++;
}



FILE *ff = fopen("OUTPUT2-LOTTERY.txt", "w");

// printf("Enter Time Quantum:\t");

// scanf("%d",&time_quantum);

// printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");

for(time=0;remain!=0;count=0)
{
    
    
    count = getNum(n,lottery,sum);

    
    // printf("%d",count);
// rtt [count] = bt[count];





if(rt[count]<=time_quantum && rt[count]>0)

{
 fprintf(ff,"Time :%d P%d entering quantum \n",time,pall[count].ID);

time+=rt[count];

rt[count]=0;

flag=1;

}

else if(rt[count]>0)

{
 fprintf(ff,"Time :%d P%d entering quantum \n",time,pall[count].ID);

rt[count]-=time_quantum;

time+=time_quantum;
flag=1;


}

if(rt[count]==0 && flag==1)

{

remain--;

fprintf(ff,"P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);

wait_time+=time-at[count]-bt[count];

turnaround_time+=time-at[count];

flag=0;
rt[count]=-1;

}

if(count==n-1)

count=0;

else if(at[count+1]<=time)

count++;

else

count=0;

}

fprintf(ff,"\nAverage Waiting Time= %f\n",wait_time*1.0/n);

fprintf(ff,"Avg Turnaround Time = %f\n",turnaround_time*1.0/n);
// printf("%d \n",pall[0].CPUBurst);
// printf("%d \n",burst[2]);

return 0;

}