#include<reg51.h>

sbit PIR1=PX1^Y1
sbit PIR2=PX2^Y2

sbit LIGHT1=PX3^Y3
sbit LIGHT2=PX4^Y4

#define T55 1;  // Number of Iterations for 55 seconds
#define T5 1;  // Number of Iterations for 5 seconds

// Problem - T55/T5 iterations may notalways correspond to 55/5 seconds. It depends on the number of statements executed.
// Maximum Error Possible - 100%

void main()
{
	int status1,status2; // Three states - polling - 0,waiting for 55 seconds-1, polling for 5 seconds-2
	long int timer1,timer2; // holds number of iterations during one of the states



	while(1)
	{
		if(status1==0)
		{

			if(PIR1==0)
			{
				LIGHT1 = 0;
				status1 = 1;
				timer1 = 0;
			}
		}
		else if(status1==1)
		{
			timer1 ++;
			if(timer1==T55)
			{
				status1 = 2;
				timer1 = 0;
			}
		}
		else
		{
			timer1 ++;
			if(PIR1==0)
			{
				status1 = 1;
				timer1 = 0;
			}
			else if(timer1==T5)
			{
				LIGHT1 = 1;
				status1 = 0;
				timer1 = 0;
			}
		}

		if(status2==0)
		{

			if(PIR2==0)
			{
				LIGHT2 = 0;
				status2 = 1;
				timer2 = 0;
			}
		}
		else if(status2==1)
		{
			timer2 ++;
			if(timer2==T55)
			{
				status2 = 2;
				timer2 = 0;
			}
		}
		else
		{
			timer2++;
			if(PIR2==0)
			{
				status2 = 1;
				timer2 = 0;
			}
			else if(timer2==T5)
			{
				status2 = 0;
				timer2 = 0;
			}
		}

	}
}
