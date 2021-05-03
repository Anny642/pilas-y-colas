#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<thread>
#include<time.h>

using namespace std;

int num;

void caja1();
void caja2();
void caja3();
void caja4();

struct Nodo {
	int num;
	Nodo* siguiente;
};

//int* num_random(int* data) {
//	int *num = data;
//	srand(time(NULL));
//
//	for (int c = 1; c <= 200; c++) {
//		*num = 1 + rand() % (91 - 1);
//		cout << num << " ";
//	}
//}

void* procesoSeparado(void* data) {
	char* texto = (char*)data;
	struct timespec *tiempo;
	while (1) {
		printf("%s\n", texto);
		pthread_delay_np(tiempo);
	}
}

void Add(Nodo*&, int);
void Remove(Nodo*&);

void insertarPila(Nodo*&, int);
void sacarPila(Nodo*&);
bool cola_vacia(Nodo*);
Nodo* frente = NULL;
Nodo* fin = NULL;

int main(void) {
	int opc;

	cout << "Elija entre las opciones " << endl;
	cout << "--- caja 1" << endl;
	cout << "---caja 2" << endl;
	cout << "---caja 3" << endl;
	cout << "---caja 4" << endl;
	cout << "--salir" << endl;

	switch (opc) {
	case 1:
		caja1();
		break;
	case 2:
		caja2();
		break;
	case 3:
		caja3();
		break;
	case 4:
		caja4();
		break;
	case 0:
		break;
	}


	system("pause");
	return 0;
}

void caja1() {
	Nodo* pila = NULL;
	int valor = 0, contar = 0;

	char s;

	const char *mensaje1 = "Hilo 1";
	//const int* num = 0;

	pthread_t proceso1;
	
	pthread_create(&proceso1, NULL, procesoSeparado, (void*) mensaje1);
	pthread_join(proceso1, NULL);
	


	cout << "[" << num << "]: ";
	insertarPila(pila, num);


	cout << "-----------------------------------------------------" << pila->num << endl;
	cout << ------------------------------------------------------ - << endl;
	cout << ------------------------------------------------------ - << endl;

	do {
		cout << "Desea sacar un dato? (s/n): ";
		cin >> s;
		if (s == 's') {
			sacarPila(pila);
			if (pila == NULL) {
				cout << "La pila esta vacia" << endl;
				s = 'n';
			}
			else {
				cout << "-----------------------------------------------------" << pila->num << endl;
				cout << ------------------------------------------------------ - << endl;
				cout << ------------------------------------------------------ - << endl;

			}
		}

	} while ((s == 's'));
}

void caja2() {
	Nodo* pila = NULL;
	int valor = 0, contar = 0;

	char s;

	const char* mensaje1 = "Hilo 2";
	

	pthread_t proceso1;
	
	pthread_create(&proceso1, NULL, procesoSeparado, (void*)mensaje1);
	
	pthread_join(proceso1, NULL);


	cout << "[" << num << "]: ";
	insertarPila(pila, num);

	cout << "----------------------------------------------------" << pila->num << endl;
	cout << ------------------------------------------------------ - << endl;
	cout << ------------------------------------------------------ - << endl;

	do {
		cout << "Desea sacar un dato? (s/n): ";
		cin >> s;
		if (s == 's') {
			sacarPila(pila);
			if (pila == NULL) {
				cout << "La pila esta vacia" << endl;
				s = 'n';
			}
			else {
				cout << "--------------------------------------------------" << pila->num << endl;
				cout << ------------------------------------------------------ - << endl;
				cout << ------------------------------------------------------ - << endl;

			}
		}

	} while ((s == 's'));
}
void caja3() {
	Nodo* pila = NULL;
	int valor = 0, contar = 0;

	char s;

	const char* mensaje1 = "Hilo 3";
	

	pthread_t proceso1;
	
	pthread_create(&proceso1, NULL, procesoSeparado, (void*)mensaje1);
	//
	pthread_join(proceso1, NULL);
	//

	cout << "[" << num << "]: ";
	insertarPila(pila, num);

	cout << "----------------------------------------------------" << pila->num << endl;
	cout << ------------------------------------------------------ - << endl;
	cout << ------------------------------------------------------ - << endl;
	do {
		cout << "Desea sacar un dato? (s/n): ";
		cin >> s;
		if (s == 's') {
			sacarPila(pila);
			if (pila == NULL) {
				cout << "La pila esta vacia" << endl;
				s = 'n';
			}
			else {
				cout << "----------------------------------------------------" << pila->num << endl;
				cout << ------------------------------------------------------ - << endl;
				cout << ------------------------------------------------------ - << endl;
			}
		}

	} while ((s == 's'));
}

void caja4() {
	Nodo* pila = NULL;
	int valor = 0, contar = 0;

	char s;

	const char* mensaje1 = "Hilo 4";


	pthread_t proceso1;
	pthread_create(&proceso1, NULL, procesoSeparado, (void*)mensaje1);
	pthread_join(proceso1, NULL);

	cout << "[" << num << "]: ";
	insertarPila(pila, num);

	cout << "---------------------------------------------------" << pila->num << endl;
	cout << ------------------------------------------------------ - << endl;
	cout << ------------------------------------------------------ - << endl;
	do {
		cout << "Desea sacar un dato? (s/n): ";
		cin >> s;
		if (s == 's') {
			sacarPila(pila);
			if (pila == NULL) {
				cout << "La pila esta vacia" << endl;
				s = 'n';
			}
			else {
				cout << "---------------------------------------------------" << pila->num << endl;
				cout << ------------------------------------------------------ - << endl;
				cout << ------------------------------------------------------ - << endl;
			}
		}

	} while ((s == 's'));
}

void insertarPila(Nodo*& pila, int n) {
	Nodo* push = new Nodo;
	push->num = n;
	push->siguiente = pila;
	pila = push;

	cout << ------------------------------------------------------ - << endl;
	cout << "Elemento agregado a la pila" << endl;
}

void sacarPila(Nodo*& pila) {
	int n;
	Nodo* pop = pila;
	n = pop->num;
	pila = pop->siguiente;
	delete pop;
}

void Add(Nodo*& inicio, int n) {
	Nodo* add = new Nodo();
	add->num = n;
	add->siguiente = NULL;

	if (cola_vacia(frente)) {
		frente = add;
	}
	else {
		fin->siguiente = add;
	}
	fin = add;
	cout << ------------------------------------------------------ - << endl;
	cout << "elemento insertado a la cola" << endl;
}

bool cola_vacia(Nodo* frente) {
	return (frente == NULL) ? true : false;
}

void Remove(Nodo*& frente) {
	int n;
	n = frente->num;
	Nodo* cola = frente;
	if (frente == fin) {
		frente = NULL;
		fin = NULL;
	}
	else {
		frente = frente->siguiente;
	}
	delete cola;
}