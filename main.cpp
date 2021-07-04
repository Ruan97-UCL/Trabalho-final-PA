//Trabalho Final PA - Ruan Pardinho
#include <fstream>
#include <iostream>

using namespace std;

struct tComplexos {
	float real;
	float imag;
};

class No {
public:
	tComplexos valor;
	No *proximo;

	No(tComplexos elemento) {
		this->valor = elemento;
		this->proximo = NULL;
	}

	void definirProximo(No *end) {
		proximo = end;
	}

	tComplexos obterValor() {
		return valor;
	}

	float obterReal() {
		return valor.real;
	}

	float obterImag() {
		return valor.imag;
	}

	No *obterProximo() {
		return proximo;
	}
};

class Lista {
public:
	No *inicio;
	No *fim;

	Lista() {
		inicio = NULL;
		fim = NULL;
	}

	Lista(tComplexos n) {
		inicio = new No(n);
		fim = inicio;
	}

	virtual ~Lista() {
		delete inicio;
	}

	bool seVazia() {
		return (inicio == NULL);
	}

	void imprimirElementos() {
		cout << "ELEMENTOS DA LISTA" << endl;
		No *i = inicio;
		if (seVazia()) {
			cout << "Lista sem elementos!" << endl;
		} else {
			while (i) {
				cout << i->obterReal() << " " << i->obterImag() << endl;
				i = i->obterProximo();
			}
			cout << endl;
		}
	}

	void insereNoFim(tComplexos valor) {
		No *novo = new No(valor);

		if (seVazia()) {
			inicio = novo;
			fim = novo;
		} else {
			fim->definirProximo(novo);
			fim = novo;
		}
	}

	int tamanhoLista() {
		if (seVazia()) {
			return 0;
		}
		No *i = inicio;
		int tamanho = 0;

		do {
			i = i->obterProximo();
			tamanho++;
		} while (i);

		return tamanho;
	}

	void botaArquivo(tComplexos n) {
		No *i = inicio;
		ofstream poe;
		poe.open("COMPLEXOS.txt", ios::out);
		while (i) {
			poe << i->obterReal() << " " << i->obterImag() << endl;
			i = i->obterProximo();
		}
		poe.close();
	}
};
	void leArquivo(Lista* lista) {
		ifstream pega;
		tComplexos valor;
		
		pega.open("COMPLEXOS.txt", ios::in); 
		
			while (pega >> valor.real >> valor.imag) {
				lista->insereNoFim(valor);
			}
			
		pega.close();
	 }


int main() {
	tComplexos n;
	int s, quant;
	Lista *lista = new Lista;
  

	do {
		cout << "\nPressione 0 para gravar, 1 para ler, -1 para sair\n";
		cin >> s;
		if (s == 0) {
			cout << "\nInforme a quantidade de complexos: \n";
			cin >> quant;
			for (int i = 0; i < quant; i++) {
				cout << "\nInforme o complexo\n";
				cin >> n.real;
				cin >> n.imag;
				lista->insereNoFim(n);
			}
			lista->botaArquivo(n);
		}

		else if (s == 1) {
		  lista = new Lista;
			leArquivo(lista);
			lista->imprimirElementos();
		}
		
	} while (((s != 1) || (s != 2)) && (s != -1));
}