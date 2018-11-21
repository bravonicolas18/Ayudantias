#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* VENTA TICKET AVION */

using namespace std;

int fila=20, columna=6;
int f=0, c=0;

void LimpiarAsientos(int A[][6])
{
	for(f=0;f<fila;f++)
		for(c=0;c<columna;c++)
			A[f][c]=0; // Disponible
	cout<<"\n Avion inicializado con exito!\n\n";
}

void CargarAsientos(int A[][6])
{
	srand(time(NULL));
	for(f=0;f<fila;f++)
		for(c=0;c<columna;c++)
			A[f][c]=rand()%3;
	cout<<"\n Asientos cargados con exito!\n\n";
	system("pause");			
}

void MostrarAsientos(int A[][6])
{
	cout<<"\n * ASIENTOS AVION *\n\n";
	for(f=0;f<fila;f++)
	{
		for(c=0;c<columna;c++)
		{
			cout<<" "<<A[f][c];
			if(c==2)
				cout<<" -";
		}
		cout<<endl;	
	}	
	cout<<endl;
	system("pause");
}

void VenderPasaje(int A[][6])
{
	int f1=0,c1=0;
	cout<<"\n Ingrese asiento a VERDER:\n";
	cout<<" * Fila    : ";
	cin>>f1;
	cout<<" * Columna : ";
	cin>>c1;
	
	if(A[f1-1][c1-1]==0 || A[f1-1][c1-1]==1) // Disponible o Reservado		
	{
		A[f1-1][c1-1]=2; // Vendido
		cout<<" * Asiento vendido correctamente! \n\n";
	}
	else
		cout<<" * Asiento ya esta vendido!\n\n";	
	system("pause");
}

void ReservarPasaje(int A[][6])
{
	int f2=0,c2=0;
	cout<<"\n Ingrese asiento a RESERVAR:\n";
	cout<<" * Fila    : ";
	cin>>f2;
	cout<<" * Columna : ";
	cin>>c2;
	
	if(A[f2-1][c2-1]==0) // Disponible		
	{
		A[f2-1][c2-1]=1; // Reservado
		cout<<" * Asiento reservado correctamente!\n\n";
	}
	else
		cout<<" * Asiento ya esta vendido o reservado!\n\n";	
	system("pause");
}

void AnularPasaje(int A[][6])
{
	int f3=0,c3=0;
	cout<<"\n Ingrese asiento a ANULAR:\n";
	cout<<" * Fila    : ";
	cin>>f3;
	cout<<" * Columna : ";
	cin>>c3;
	
	if(A[f3-1][c3-1]==2 || A[f3-1][c3-1]==1) // Vendido o Reservado		
	{
		A[f3-1][c3-1]=0; // Disponible
		cout<<" * Asiento anulado correctamente! \n\n";
	}
	else
		cout<<" * Asiento ya esta disponible! \n\n";	
	system("pause");
}

void CalcularRecaudacion(int A[][6])
{
	int monto=0;
	long int total=0;
	cout<<"\n Ingrese valor ticket: $ ";
	cin>>monto;
	
	for(f=0;f<fila;f++)
		for(c=0;c<columna;c++)
		{
			if(A[f][c]==2) // Vendido
				total+=monto;
			else if(A[f][c]==1) // Reservado
				total+=(monto/2);
		}
	cout<<"\n * Total Recaudado: $ "<<total<<"\n\n";
	system("pause");
}

void Estadisticas(int A[][6])
{
	int cDi=0, cRe=0, cVe=0;
	for(f=0;f<fila;f++)
		for(c=0;c<columna;c++)
		{
			if(A[f][c]==0) // Disponible
				cDi++;
			else if(A[f][c]==1) // Reservado
				cRe++;
			else if(A[f][c]==2) // Vendido
				cVe++;
		}
	cout<<"\n * CANTIDAD ASIENTOS *\n";
	cout<<" - Vendidos   : "<<cVe<<endl;
	cout<<" - Reservado  : "<<cRe<<endl;
	cout<<" - Disponibles: "<<cDi<<endl<<endl;
	system("pause");
}

int main()
{
	int avion[20][6], op=0;
	LimpiarAsientos(avion);
	do{
		system("cls");
		cout<<"\n ::: VENTA TICKET AVION :::\n\n";
		cout<<" 1.- Inicializar Avion.\n";
		cout<<" 2.- Mostrar Asientos Avion.\n";
		cout<<" 3.- Cargar Asientos Avion.\n";
		cout<<" 4.- Vender Ticket.\n";
		cout<<" 5.- Reservar Ticket.\n";
		cout<<" 6.- Anular Ticket.\n";
		cout<<" 7.- Calcular Recaudacion.\n";
		cout<<" 8.- Estadistica.\n";
		cout<<" 9.- Salir.\n\n";
		cout<<" Ingrese opcion: ";
		cin>>op;
		system("cls");
		switch(op)
		{
			case 1:
				LimpiarAsientos(avion);
				system("pause");
				break;
			case 2:
				MostrarAsientos(avion);
				break;
			case 3:
				CargarAsientos(avion);
				break;
			case 4:
				VenderPasaje(avion);
				break;
			case 5:
				ReservarPasaje(avion);
				break;
			case 6:
				AnularPasaje(avion);
				break;
			case 7:
				CalcularRecaudacion(avion);
				break;
			case 8:
				Estadisticas(avion);
				break;
			case 9:
				cout<<"\n\n Hasta luego!\n\n";
				return 0;
				break;
			default:
				cout<<"\n\n Opcion ingresada no es valida!\n\n";
				break;
		}	
	}while(true);	
	
	system("pause");
	return 0;
}
