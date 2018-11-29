#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <time.h>

using namespace std;

int f=0,c=0;

int ValoraPagar(int monto)
{
	int dig=0;
	dig=monto-((monto/10)*10);
	
	if(dig>=5 && dig<=9)
		monto=monto-dig+10;
	else if(dig>=1 && dig<=4)
		monto=monto-dig;
		
	return monto;	
}

void PagoDefinitivo(int monto,int formadepago)
{
	switch(formadepago)
	{
		case 1: // Efectivo
			cout<<"\n\n PAGO EFECTIVO";
			cout<<"\n Total a pagar: $ "<<ValoraPagar(monto);
			break;
		case 2: // Cheque
			cout<<"\n\n PAGO CHEQUE";
			cout<<"\n Total a pagar: $ "<<monto;
			break;
		case 3: // TCredito
			cout<<"\n\n PAGO T. CREDITO";
			cout<<"\n Total a pagar: $ "<<monto;
			break;
		case 4: // TDebito
			cout<<"\n\n PAGO T. DEBITO";
			cout<<"\n Total a pagar: $ "<<monto;
			break;
		default:
		{
			cout<<"\n Opcion ingrasado no valida.";
			system("pause");
		}
	}
	cout<<endl<<endl;
}

int main()
{
	int monto=0,formadepago=0;
	
	cout<<"\n\n Ingrese monto : $ ";
	cin>>monto;
	
	cout<<"\n EFECTIVO(1) * CHEQUE(2) * TCRED(3) * TDEB(4)\n";
	cout<<" Ingrese Forma de Pago : ";
	cin>>formadepago;
	
	PagoDefinitivo(monto,formadepago);
	
	system("pause");
	return 0;
}
