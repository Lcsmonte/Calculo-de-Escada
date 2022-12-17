#pragma once
#include <iostream>

class DATA16
{

public:

	double S_Height;
	int N_degree;		// using int to widen the number, then its possible to keep the value of the H_degree above 16. 
	double H_degree;
	double B_degree;
	double Blondel = 63;
	double COMPLEMENT_Blondel = 64 - Blondel;

public:

	DATA16(double Altura_escada)
	{
		S_Height = Altura_escada;

		N_degree = S_Height / 16;

		H_degree = S_Height /N_degree;

		B_degree = 63 - H_degree * 2;
	}
};

class DATA17
{

public:

	double S_Height;
	int N_degree;		// using int to widen the number, then its possible to keep the value of the H_degree above 16. 
	double H_degree;
	double B_degree;
	double Blondel = 63;

public:

	DATA17(double Altura_escada)
	{
		S_Height = Altura_escada;

		N_degree = (S_Height / 16) - 1; // -1 para reduzir a quantidade de degraus

		H_degree = S_Height / N_degree;

		B_degree = 64 - H_degree * 2;
	}

};

