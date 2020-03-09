#ifndef SOLUCION_H_
#define SOLUCION_H_

#include<vector>
#include <utility>
#include<iostream>
#include <vector>

using namespace std;

class Solucion {
public:
	Solucion();
	virtual ~Solucion();

	virtual void resolver();
	virtual void mezcla(pair<Solucion*,Solucion*>);
	virtual Solucion* getInstance();
	virtual void setValor(vector<int> v);
protected:
	vector<int> v_;
	int pivote_;
};

#endif /* SOLUCION_H_ */
