#include <stdio.h>

double find_remainder(double whose_remainder)
{
	double multiplied ;
	int t = 0;
	double remainder ;
	multiplied = whose_remainder * 100000;
	do
	{
		remainder = multiplied - (100000*t);
		t = t + 1 ;
	}while(remainder >= 100000);
	t = 0;
	remainder = remainder /100000;
	return remainder;
}

double calculate_zellers(double year,double m,double q)
{
	double zellers,zellers_result,processed_m;
	int k,j,t;
	do
	{
		k = year - (100 * t) ;
					t = t + 1 ;
	}while(k >= 100);
				
	t = 0;
	j = (year - k)/100;
	processed_m = ((13*(m + 1))/5);
	processed_m = processed_m - find_remainder(processed_m);
	zellers = (q + processed_m + k + (k/4) + (j/4) + (5 * j)) ;
	do
	{
		zellers_result = zellers - (7 * t) ;
		t = t + 1 ;
	}while(zellers_result >= 7);
	t = 0;
	return zellers_result;
}

int find_how_many(double processing_year,double endyear)
{
	int how_many_year;
	double m,q,year;
	m = 0 ;
	q = 0 ;
	year = 0 ;
	do
	{
		processing_year = processing_year + 1.0;
		if(calculate_zellers(processing_year,m,q) == calculate_zellers(year,m,q))
		{
			how_many_year = how_many_year + 1;
		}
		else
		{
			how_many_year = how_many_year ;
		}
					
	}while(processing_year != (endyear - 2));
	return how_many_year;
}

int main()
{	
	double q,m,year;
	double tofindleapyear ;
	double endyear ;
	int how_many_years = 0;
	int t = 0 ;
	double z ;
	printf("Enter date [year month day]: \n");
	scanf("%lf %lf %lf",&year,&m,&q);
	if (find_remainder(year) == 0 && find_remainder(q) == 0 && find_remainder(m) == 0)
	{
		if(m == 1 && q <= 31 && q >= 1)
		{	
			m = m +12;
			year = year - 1;
			printf("Enter end year: \n");
			scanf("%lf",&endyear);
			if(find_remainder(endyear) == 0)
			{
				z = calculate_zellers(year,m,q);
				how_many_years = find_how_many(year,endyear);
				year = year + 2 ;	
				if(z == 0)
				{	
					printf("It's a Saturday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 1)
				{	
					printf("It's a Sunday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 2)
				{	
					printf("It's a Monday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 3)
				{	
					printf("It's a Tuesday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 4)
				{	
					printf("It's a Wendesday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 5)
				{	
					printf("It's a Thursday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 6)
				{	
					printf("It's a Friday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
			}
			else
			{
				printf("Invalid date.\n");
				return 1;
			}
		}
		else if(m == 2)
		{
			t = 0 ;
			do
			{
				tofindleapyear = year - 4 * t ;
				t = t + 1 ;
			}while(tofindleapyear >= 4);
			if(tofindleapyear == 0 && q <= 29 && q >= 1)
			{	
				m = m + 12;
				year = year - 1;
				printf("Enter end year: \n");
				scanf("%lf",&endyear);
				if(find_remainder(endyear) == 0)
				{
					z = calculate_zellers(year,m,q);
					how_many_years = find_how_many(year,endyear);
					year = year + 2 ;
					if(z == 0)
					{	
						printf("It's a Saturday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 1)
					{	
						printf("It's a Sunday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 2)
					{	
						printf("It's a Monday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 3)
					{	
						printf("It's a Tuesday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 4)
					{	
						printf("It's a Wendesday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 5)
					{	
						printf("It's a Thursday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 6)
					{	
						printf("It's a Friday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
				}
				else
				{
					printf("Invalid date.\n");
					return 1;
				}
			}
			else if(tofindleapyear != 0 && q <= 28 && q >= 1)
			{
				m = m + 12;
				year = year - 1;
				printf("Enter end year: \n");
				scanf("%lf",&endyear);
				if(find_remainder(endyear) == 0)
				{
					z = calculate_zellers(year,m,q);
					how_many_years = find_how_many(year,endyear);
					year = year + 1;
					if(z == 0)
					{	
						printf("It's a Saturday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 1)
					{	
						printf("It's a Sunday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 2)
					{	
						printf("It's a Monday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 3)
					{	
						printf("It's a Tuesday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 4)
					{	
						printf("It's a Wendesday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 5)
					{	
						printf("It's a Thursday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
					else if(z == 6)
					{	
						printf("It's a Friday.\n");
						printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
					}
				}
				else
				{
					printf("Invalid date.\n");
					return 1;
				}
			}
			else 
			{
				printf("Invalid date.\n");
				return 1;
			}
		}
		else if((m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)&& q <= 31 && q >= 1 )
		{	
			printf("Enter end year: \n");
			scanf("%lf",&endyear);
			if(find_remainder(endyear) == 0)
			{
				z = calculate_zellers(year,m,q);
				how_many_years = find_how_many(year,endyear);
				year = year + 1;
				if(z == 0)
				{	
					printf("It's a Saturday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 1)
				{	
					printf("It's a Sunday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 2)
				{	
					printf("It's a Monday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 3)
				{	
					printf("It's a Tuesday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 4)
				{	
					printf("It's a Wendesday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 5)
				{	
					printf("It's a Thursday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 6)
				{	
					printf("It's a Friday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
			}
			else
			{
				printf("Invalid date.\n");
				return 1;
			}
		}
		else if((m == 4 || m == 6 || m == 9 || m == 11) && q <= 30 && q >= 1)
		{	
			printf("Enter end year: \n");
			scanf("%lf",&endyear);
			if(find_remainder(endyear) == 0)
			{
				z = calculate_zellers(year,m,q);
				how_many_years = find_how_many(year,endyear);
				year = year + 1;
				if(z == 0)
				{	
					printf("It's a Saturday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 1)
				{	
					printf("It's a Sunday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 2)
				{	
					printf("It's a Monday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 3)
				{	
					printf("It's a Tuesday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 4)
				{	
					printf("It's a Wendesday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 5)
				{	
					printf("It's a Thursday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
				else if(z == 6)
				{	
					printf("It's a Friday.\n");
					printf("Same day-and-month on same weekday between %.0lf and %.0lf: %d\n",year,endyear,how_many_years);
				}
			}
			else
			{
				printf("Invalid date.\n");
				return 1;
			}
		}
		else
		{
			printf("Invalid date.\n");
			return 1;
		}
	}
	else 
	{
		printf("Invalid date.\n");
		return 1;
	}
	return 0;
}