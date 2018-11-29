#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <time.h>

using namespace std;

int f=0,c=0;

void LimpiarResultados(int J[][9])
{
	for(f=0;f<10;f++)
		for(c=0;c<9;c++)
			J[f][c]=0;	
}

void CargarResultados(int J[][9])
{
	srand(time(NULL));
	for(f=0;f<10;f++)
		for(c=0;c<9;c++)
			J[f][c]=rand()%3-1;	
}

void MostrarResultados(int J[][9])
{
	cout<<endl;
	for(f=0;f<10;f++)
	{
		for(c=0;c<9;c++)
		{
			cout<<J[f][c]<<"\t";
		}
		cout<<endl;
	}
}

void EstadisticasJuego(int J[][9])
{
	int cont=0, Mas=0, posMas=0, Men=9, posMen=0, cVict=0, cEmp=0, cDer=0;
	
	for(f=0;f<10;f++)
	{
		cont=0;
		for(c=0;c<9;c++)
		{
			if(J[f][c]==1)
				cont++;
		}
		if(cont>Mas)
		{
			Mas=cont;
			posMas=f;
		}		
	}
	cout<<"\n * Jugador con mas encuentros ganados: "<<posMas+1<<endl;			


	for(f=0;f<10;f++)
	{
		cont=0;
		for(c=0;c<9;c++)
		{
			if(J[f][c]==1)
				cont++;
		}
		if(cont<Men)
		{
			Men=cont;
			posMen=f;
		}		
	}
	cout<<"\n * Jugador con menos encuentros ganados: "<<posMen+1<<endl;			

	cout<<"\n * Porcentaje Victoria por Juego";
	for(c=0;c<9;c++)
	{
		cVict=0;
		for(f=0;f<10;f++)
		{
			if(J[f][c]==1)
				cVict++;
		}
		cout<<"\n   - Juego "<<c+1<<" : "<<std::setprecision(3)<<(cVict/10.0)*100<<"%";
	}
	cout<<endl;			
	
	cout<<"\n * Porcentaje Empates por Juego";
	for(c=0;c<9;c++)
	{
		cEmp=0;
		for(f=0;f<10;f++)
		{
			if(J[f][c]==0)
				cEmp++;
		}
		cout<<"\n   - Juego "<<c+1<<" : "<<std::setprecision(3)<<(cEmp/10.0)*100<<"%";
	}
	cout<<endl;			
	
	cout<<"\n * Porcentaje Derrota por Juego";
	for(c=0;c<9;c++)
	{
		cDer=0;
		for(f=0;f<10;f++)
		{
			if(J[f][c]==-1)
				cDer++;
		}
		cout<<"\n   - Juego "<<c+1<<" : "<<std::setprecision(3)<<(cDer/10.0)*100<<"%";
	}
	cout<<endl;			
}

int main()
{
	int Juegos[10][9];
	
	LimpiarResultados(Juegos);
	CargarResultados(Juegos);
	MostrarResultados(Juegos);
	EstadisticasJuego(Juegos);	
	cout<<endl;
	
	system("pause");
	return 0;
}
