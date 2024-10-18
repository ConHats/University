#include <stdio.h>
#include <math.h>


long Parag(int x);
double calculate_sinx(double x);

int main()
{
	double x,sinx;

    printf("Dwse to x se aktinia: ");
    scanf("%lf",&x);	// ��� ����� %lf ���: long float ��� �� �������� double
    sinx=calculate_sinx(x);
    printf("sinx: %12.10f", sinx);
}

double calculate_sinx(double x)
{
    int j=1,i=1;		// ��� �� j �� �������� ��� 1 ��� �� ��������� ��� ����� ��� (�� x) ��� ��� �� �� �������
    double sinx=0,p;	// ����� �� p ��� �������������� ��� �����������
    					// ��� �� sinx ��� �������� ������ �� �����������
    while(i<12)
    {
    	p=pow(x,i)/Parag(i);
        if(p<0.0001){
			i+=2;	// ��� �� ������� ������ ��� ���� � ������� ��� �������
			break;
		}
        if(j%2!=0)
			sinx+=p;
		else
		    sinx-=p;
        i+=2;
        j++;
    }
    printf("n: %d\n",i-2);	// ��� ������� ��� ����������� ���� ��� i
    return sinx;
}

long Parag(int x)
{
    long y=1;
    int i;
    for(i=1;i<=x;i++)
    {
        y=y*i;
    }
    return y;
}


