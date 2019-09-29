#pragma once
class Carrera
{
public:
	int vliebre[70];
	int vtortuga[70];		
	int* pliebre = &vliebre[69];
	int* ptortuga = &vtortuga[69];
	int posliebre = 1;
	int postortuga = 1;
public:
	Carrera();
	~Carrera();
	
	void crearCarrera();
	void impCarrera(int r, int r2);
	void cambiarPosLiebre(int r);
	void cambiarPosTortuga(int r);
};

