#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{float n[100000];float Total=0,Square=0;
float K1=0,K2=0,K3=0,L=0,s1=0,s2=0;
FILE *fptr;
char f[]= "data_190020002.csv";
fptr = fopen(f,"r");
for(int i=0;i<100000;i++)
{fscanf(fptr,"%f", &n[i]);
 Total+=n[i];}
for(int i=0;i<100000;i++)
{Square+=pow(n[i],2);}
float avg=Total/100000;
float variance=Square/100000-avg*avg;
K1=(avg*avg)/(variance-3);
L=10*K1/avg;
K2=(avg*avg*0.859)/(3.141*(variance-3));
s1=(0.798)*(avg/(10*K2));
K3=(avg*avg*(3.141-2))/(2*(variance-3));
s2=(1.253)*(avg/(10*K3));
printf("Mean of Z=%.3f\nVariance of Z=%.3f\n",avg,variance);
printf("Case 1: Exponential distribution\nK = %.3f\nL=%.3f\n",K1,L);
printf("Case 2: Rayleigh distribution\nK = %.3f\ns = %.3f\n",K2,s1);
printf("Case 3: Half-normal distribution\nK = %.3f\ns = %.3f\n",K3,s2);
return 0;
}
