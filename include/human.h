#ifndef humanh
#define humanh

#include <iostream>
#include <string>

using namespace std;

class person {
private:
	string nome;
	string address;
	string telefone;
public:
	person(string n, string e, string t): nome(n), address(e), telefone(t) {}
	/*person(string n, string e, string t) {
		nome = n;
		address = e;
		telefone = t;
	}
	person(string n, string e, string t) {
		this->nome = n;
		this->address = e;
		this->telefone = t;
	}
	*/
	virtual ~person() {}

	string getNome() { return nome; }
	string getAddress() { return address; }
	string getTelefone() { return telefone; }

	void setNome(string n) { nome = n; }
	void setAddress(string e) { address = e; }
	void setTelefone(string t) { telefone = t; }

};

class supplier : public person {
private:
	int credito;
	int divida;
public:
	supplier(string n, string e, string t, int c, int d) : person(n, e, t), credito(c), divida(d) {}

	int getCredito() { return credito; }
	int getDivida() { return divida; }
	int getSaldo() { return credito - divida; }

	void setCredito(int c) { credito = c; }
	void setDivida(int d) { divida = d; }

};

class employee : public person {
private:
	int codigoSetor;
	int salarioBase;
	float imposto;
public:
	employee(string n, string e, string t, int cod, int sal, float imp) : person(n, e, t), codigoSetor(cod), salarioBase(sal), imposto(imp) {}

	int getCodigoSetor() { return codigoSetor; }
	int getSalarioBase() { return salarioBase; }
	float getImposto() { return imposto; }

	void setCodigoSetor(int cod) { codigoSetor = cod; }
	void setSalarioBase(int sal) { salarioBase = sal; }
	void setImposto(float imp) { imposto = imp; }

	virtual float calcularSalario() {
		float salarioLiquido = salarioBase - (imposto / 100 * salarioBase);
		return salarioLiquido;
	}
};

class admin : public employee {
private:
	int ajudaDeCusto;
public:
	admin(string n, string e, string t, int cod, int sal, float imp, int help) : employee(n, e, t, cod, sal, imp), ajudaDeCusto(help) {}

	int getAjudaDeCusto() const { return ajudaDeCusto; }
	void setAjudaDeCusto(int help) { ajudaDeCusto = help; }

	float calcularSalario() override {
		float salarioLiquido = employee::calcularSalario() + ajudaDeCusto;
		return salarioLiquido;
	}
};

class worker : public employee {
private:
	int valorProducao;
	int comissao;
public:
	worker(string n, string e, string t, int cod, int sal, float imp, int valorProd, int comm) : employee(n, e, t, cod, sal, imp), valorProducao(valorProd), comissao(comm) {}

	int getValorProducao() { return valorProducao; }
	int getComissao() { return comissao; }

	void setValorProducao(int valorProd) { valorProducao = valorProd; }
	void setComissao(int comm) { comissao = comm; }

	float calcularSalario() override {
		float salarioLiquido = employee::calcularSalario() + (valorProducao * comissao / 100);
		return salarioLiquido;
	}
};

class seller : public employee {
private:
	int valorVendas;
	int comissao;
public:
	seller(string n, string e, string t, int cod, int sal, float imp, int valorVend, int comm) : employee(n, e, t, cod, sal, imp), valorVendas(valorVend), comissao(comm) {}
	
	int getValorVendas() { return valorVendas; }
	int getComissao() { return comissao; }

	void setValorVendas(int valorVend) { valorVendas = valorVend; }
	void setComissao(int comm) { comissao = comm; }

	float calcularSalario() override {
		float salarioLiquido = employee::calcularSalario() + (valorVendas * comissao / 100);
		return salarioLiquido;
	}
};

#endif
