#include<stdio.h>
int main()
{
    int flag=0,use,Q[50],WaitingTime[50],tt[50],updated_k[50],ArivalTime[50];
    int c_ArivalTime[50],Bursttime[50];
    int c_Bursttime[50],priority[50],c_priority[50],i;
    int array[50]={0},n,sum=0,m=0,count=0,k=1000;
    float Average_Turn_Around_Time=0;float Average_Waiting_Time=0;
    
    printf("*******Priority Scheduling Algorithm********\n");
    printf("\nENTER THE NO OF PROCESS:");
    scanf("%d",&n);
    char P_Name[10]={0,},first[10];
   

    for(i=0;i<n;i++)
    {
        printf("\nProcess ID : ");
        fflush(stdin);
        scanf("%c",&P_Name[i]);
        getchar();
        printf("\nArival Time of process %c :",P_Name[i]);
        scanf("%d",&ArivalTime[i]);
        c_ArivalTime[i]=ArivalTime[i];
        printf("\nBurst Time of process %c :",P_Name[i]);
        scanf("%d",&Bursttime[i]);
        sum=sum+Bursttime[i];
        c_Bursttime[i]=Bursttime[i];
        printf("\nEnter Priority for process  %c :",P_Name[i]);
        scanf("%d",&priority[i]);
        c_priority[i]=priority[i];
    }
         for(i=0;i<n;i++)
       {
         if(ArivalTime[i]<k)
         {
            k=ArivalTime[i];
         }
       }
    
    int Minimum;
    int Minimum_prio_index=-1;
    while(count<n)
    {
        Minimum=100;
        for(i=0;i<n;i++)
        {
            if((ArivalTime[i]<=k)&&(array[i]!=2))
            {  
              array[i]=1;   
            }
        }
        if(flag==0)
        {
            for(i=0;i<n;i++)
            {
                if(array[i]==1)
                { 
                    if(priority[i]<Minimum)
                    {       
                        Minimum=priority[i];
                        Minimum_prio_index=i;
                        if(k==0)
                        {
                            use=Minimum_prio_index;
                        }
                        
                    }
                }
            }
        }
        if(flag==1)
        {
            flag=0;
        }
       
        if(Minimum_prio_index>=0)
        {
            if(Minimum_prio_index==use)
            {
                k++;
                Bursttime[Minimum_prio_index]=Bursttime[Minimum_prio_index]-1;
            }
            else
            {
                k+=2;
                flag=1;
                use=Minimum_prio_index;
                continue;   
            }
            
            if(Bursttime[Minimum_prio_index]<=0)
            {
                array[Minimum_prio_index]=2;
                first[m]=P_Name[Minimum_prio_index];
                updated_k[m]=k;
                m++;
                count++;     
            }
            
        }
        if(Minimum_prio_index==-1)
            k++;
        use=Minimum_prio_index;
        Minimum_prio_index=-1;
    }
    
    for(i=0;i<n;i++)
    {
        for(m=0;m<n;m++)
        {
            if(P_Name[i]==first[m])
            {
                Q[i]=updated_k[m];
            }
        }
        
    }
    
    for(i=0;i<n;i++)
    {
        tt[i]=Q[i]-c_ArivalTime[i];
        Average_Turn_Around_Time=Average_Turn_Around_Time+tt[i];
    }
    for(i=0;i<n;i++)
    {
        WaitingTime[i]=tt[i]-c_Bursttime[i];
        Average_Waiting_Time=Average_Waiting_Time+WaitingTime[i];
    }

     //Showing the result Here
     
    printf("\nPID\t ArivalT \tBurstt \t   WaitingTime \t Turn AroundTime");
    for(i=0;i<n;i++)
    {
        
        printf("\n %c\t %d \t          %d \t          %d \t            %d",P_Name[i],c_ArivalTime[i],c_Bursttime[i],WaitingTime[i],tt[i]);
    }
    printf("\nAverage TurnAround Time = %.1f",Average_Turn_Around_Time/n);
    printf("\nAverage  Waiting Time   = %.1f",Average_Waiting_Time/n);
}
