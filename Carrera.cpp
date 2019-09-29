#include "Carrera.h"

Carrera::Carrera() {
}

Carrera::~Carrera() {
}

void Carrera::crearCarrera() {
	for (int i = 0; i < 70; i++) {
		if (i == 69) {
			vliebre[i] = -1;
			vtortuga[i] = -1;
		}
		else if (i == 0) {
			vliebre[i] = 1;
			vtortuga[i] = 1;
		}
		else {
			vliebre[i] = 0;
			vtortuga[i] = 0;
		}
	}
}

void Carrera::cambiarPosLiebre(int r) {
	if ((1 < r || r == 1) && (r < 5 || r == 5)) {
		vliebre[posliebre - 1] = 0;
		posliebre += 3;
		vliebre[posliebre - 1] = 1;
	}
	else if ((6 < r || r == 6) && (r < 7 || r == 7)) {
		if (posliebre - 6 > 0) {
			vliebre[posliebre - 1] = 0;
			posliebre -= 6;
			vliebre[posliebre - 1] = 1;
		}
		else {
			vliebre[posliebre - 1] = 0;
			posliebre = 1;
			vliebre[posliebre - 1] = 1;
		}
	}
	else if ((8 < r || r == 8) && (r < 10 || r == 10)) {
		vliebre[posliebre - 1] = 0;
		posliebre += 1;
		vliebre[posliebre - 1] = 1;
	}
}

void Carrera::cambiarPosTortuga(int r) {
	if ((3 < r || r == 3) && (r < 4 || r == 4)) {
		if (postortuga + 9 < 70) {
			vtortuga[postortuga - 1] = 0;
			postortuga += 9;
			vtortuga[postortuga - 1] = 1;
		}
		else {
			vtortuga[postortuga - 1] = 0;
			postortuga = 70;
			vtortuga[postortuga - 1] = 1;
		}
	}
	else if (r == 5) {
		if (postortuga - 12 > 0) {
			vtortuga[postortuga - 1] = 0;
			postortuga -= 12;
			vtortuga[postortuga - 1] = 1;
		}
		else {
			vtortuga[postortuga - 1] = 0;
			postortuga = 1;
			vtortuga[postortuga - 1] = 1;
		}
	}
	else if ((6 < r || r == 6) && (r < 8 || r == 8)) {
		vtortuga[postortuga - 1] = 0;
		postortuga += 1;
		vtortuga[postortuga - 1] = 1;
	}
	else if ((9 < r || r == 9) && (r < 10 || r == 10)) {
		if (postortuga - 2 > 0) {
			vtortuga[postortuga - 1] = 0;
			postortuga -= 2;
			vtortuga[postortuga - 1] = 1;
		}
		else {
			vtortuga[postortuga - 1] = 0;
			postortuga = 1;
			vtortuga[postortuga - 1] = 1;
		}
	}
}


void Carrera::impCarrera(int r, int r2) {
		
	cambiarPosLiebre(r);
	cambiarPosTortuga(r2);
	///carreraImp(pliebre, ptortuga);
}
	