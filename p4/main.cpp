
#ifndef MAIN_
#define MAIN_

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include"framework/Framework.h"
#include"merge/mergeS.hpp"
#include"merge/mergeP.hpp"

using namespace std;


int main(int argc, char* argv[]){
	vector<int> v(argc - 1);

	if (argc < 2) {
		cout << "\nNúmero de parametros incorrecto. Encontrado " << argc-1 << " requerido 1."<< endl;
		exit(-1);
	} else {
		for (int i = 1; i < argc; i++) {
			v[i - 1] = atoi(argv[i]);
		}
	}

	Problema* problema = new mergeP(v);
	Solucion* solucion = new mergeS();
	Framework* framework = new Framework();

	framework->divideyVenceras(problema, solucion);
	cout << "\nResultado merge:" << endl;
	solucion->resolver();

};

#endif /* MAIN_ */
