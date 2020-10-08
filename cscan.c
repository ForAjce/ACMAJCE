#include<stdio.h>
#include<stdlib.h>
int main()
{
            int queue[20],n,head,i,j,k,seek=0,max,diff,temp,q1[20],q2[20],a[20],t1=0,t2=0;
            float avg;
            printf("Enter the max range of disk\n");
            scanf("%d",&max);
            printf("Enter the initial head position\n");
            scanf("%d",&head);
            printf("Enter the size of queue request\n");
            scanf("%d",&n);
            printf("Enter the queue of disk positions to be read\n");
            for(i=1;i<=n;i++)
            {
                        scanf("%d",&temp);
                        if(temp>=head)
                        {
                                    q1[t1]=temp;
                                    t1++;
                        }
                        else
                        {
                                    q2[t2]=temp;
                                    t2++;
                        }
            }
            for(i=0;i<t1-1;i++)
            {
                        for(j=i+1;j<t1;j++)
                        {
                                    if(q1[i]>q1[j])
                                    {
                                                temp=q1[i];
                                                q1[i]=q1[j];
                                                q1[j]=temp;
                                    }
                        }
            }
            for(i=0;i<t2-1;i++)
            {
                        for(j=i+1;j<t2;j++)
                        {
                                    if(q2[i]>q2[j])
                                    {
                                                temp=q2[i];
                                                q2[i]=q2[j];
                                                q2[j]=temp;
                                    }
                        }
            }
            for(i=1,j=0;j<t1;i++,j++)
            queue[i]=q1[j];
            queue[i]=max-1;
            queue[i+1]=0;
            for(i=t1+3,j=0;j<t2;i++,j++)
            queue[i]=q2[j];
            queue[0]=head;
            printf("\nRequests are in the order:\n");
            for(j=0;j<=n+1;j++)
            {
                        diff=abs(queue[j+1]-queue[j]);
                        seek+=diff;
                        a[j]=queue[j+1];
            }
            printf("%d\t",head);
            for(i=0; i<=n+1; i++)
                printf("%d\t",a[i]);
            printf("\nTotal seek time= %d\n",seek);
            avg=seek/(float)n;
            printf("Average seek time= %f\n",avg);
            return 0;
}
