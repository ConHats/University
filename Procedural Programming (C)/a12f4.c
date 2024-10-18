#include <stdio.h>
#include <math.h>


long Parag(int x);
double calculate_sinx(double x);

int main()
{
	double x,sinx;

    printf("Dwse to x se aktinia: ");
    scanf("%lf",&x);	// εδώ θελει %lf δλδ: long float για να διαβάζει double
    sinx=calculate_sinx(x);
    printf("sinx: %12.10f", sinx);
}

double calculate_sinx(double x)
{
    int j=1,i=1;		// εδώ το j να ξεκιναει απο 1 για να προσθετει τον πρωτο ορο (το x) και οχι να το αφαιρει
    double sinx=0,p;	// εβαλα το p για βελτιστοποιηση του υπολογισμου
    					// και το sinx που αθροιζει πρεπει να μηδενιζεται
    while(i<12)
    {
    	p=pow(x,i)/Parag(i);
        if(p<0.0001){
			i+=2;	// για να βγαινει σωστος πιο κατω ο αριθμος των βηματων
			break;
		}
        if(j%2!=0)
			sinx+=p;
		else
		    sinx-=p;
        i+=2;
        j++;
    }
    printf("n: %d\n",i-2);	// εδω τυπωνει την προηγουμενη τιμη του i
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


