#include<stdio.h>

int main()

{

float u;    

printf("Enter the amount of units consumed by user is :");
scanf("%f",&u);
printf("Value is %f",u);
if(u>0 && u<=50)
printf("Your electric bill is %f  Rs", u*0.6);

else if(u>50 && u<=150)
printf("Your electric bill is %f Rs", u*0.9);

else if(u>150 && u<=250)
printf("Your electric bill is %f Rs", u*1.44);

else if(u>250)
printf("Your electric bill is %f Rs", u*1.8);

else if(u<0)

printf("Invalid input");
return 0;
}