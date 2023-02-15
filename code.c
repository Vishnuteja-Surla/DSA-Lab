#include<stdio.h>
int main()
{   
    int day, month, year, temp1=0, temp2=0, temp3=0, temp4=0, days, rem;
    printf("enter date:(dd)");
    scanf("%d",&day);
    printf("enter month:(mm)");
    scanf("%d",&month);
    printf("enter year:(yyyy)");
    scanf("%d",&year);
    printf("Given input date is %d/%d/%d\n",day,month,year);
    rem=year%4;
    temp1=(year-rem);
    temp2=(temp1/4);
    temp4=(temp1/100);
    temp3=(temp1-temp2-1);
    days=(365*temp3)+(366*temp2)+(365*rem)-1;
    if(month==1)
    {
        days=days+day;
    }
    else if(month=2)
    {
        days=days+31+day;
    }
    else if(month==3)
    {
        if(rem==0)
        {
            days=days+31+29+day;
        }
        else
        {
            days=days+31+28+day;
        }
    }
    else if(month==4)
    {
        if(rem==0)
        {
            days=days+31+29+day+31;
        }
        else
        {
            days=days+31+28+day+31;
        }
        
    }
    else if(month==5)
    {
        if(rem==0)
        {
            days=days+31+29+day+31+30;
        }
        else
        {
            days=days+31+28+day+31+30;
        }
        
    }
    else if(month==6)
    {
        if(rem==0)
        {
            days=days+31+29+day+31+30+31;
        }
        else
        {
            days=days+31+28+day+31+30+31;
        }
    }
    else if(month==7)
    {
        if(rem==0)
        {
            days=days+31+29+day+31+30+31+30;
        }
        else
        {
            days=days+31+28+day+31+30+31+30;
        }
    }
    else if(month==8)
    {
        if(rem==0)
        {
            days=days+31+29+day+31+30+31+30+31;
        }
        else
        {
            days=days+31+28+day+31+30+31+30+31;
        }
        
    }
    else if(month==9)
    {
        if(rem==0)
        {
            days=days+31+29+day+31+30+31+30+31+31;
        }
        else
        {
            days=days+31+28+day+31+30+31+30+31+31;
        }
        
    }
    else if(month==10)
    {
        if(rem==0)
        {
            days=days+31+29+day+31+30+31+30+31+31+30;
        }
        else
        {
            days=days+31+28+day+31+30+31+30+31+31+30;
        }
        
    }
    else if(month==11)
    {
        if(rem==0)
        {
            days=days+31+29+day+31+30+31+30+31+31+30+31;
        }
        else
        {
            days=days+31+28+day+31+30+31+30+31+31+30+31;
        }
        
    }
    else if(month==12)
    {
        if(rem==0)
        {
            days=days+31+29+day+31+30+31+30+31+31+30+31+30;
        }
        else
        {
            days=days+31+28+day+31+30+31+30+31+31+30+31+30;
        }
        
    }
    days=days-temp4;
    days=days%7;
    if(days==0)
    {
        printf("Saturday");
    }
    else if(days==1)
    {
        printf("Sunday");
    }
    else if(days==2)
    {
        printf("Monday");
    }
    else if(days==3)
    {
        printf("Tuesday");
    }
    else if(days==4)
    {
        printf("Wednesday");
    }
    else if(days==5)
    {
        printf("Thursday");
    }
    else if(days==6)
    {
        printf("Friday");
    }
    return(0);
}