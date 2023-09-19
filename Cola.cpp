#include <iostream>
using namespace std;

template <typename T>
class ColaEstatica {
private:
	int capacidad;
	int fin;
	T vector[100];

public:
	ColaEstatica(int capacidad);
	bool esVacia();
	bool esLlena();
	void encolar(T elemento);
	void desencolar();
	void obtenerFrente();
	void mostrarCola();
};

template <typename T>
ColaEstatica <T>::ColaEstatica(int capacidad)
{
	this->capacidad = capacidad;
	fin = 1;
}

template <typename T>
bool ColaEstatica <T>::esVacia()
{
	if (fin == -1)
		return true;
	return false;
}

template <typename T>
bool ColaEstatica <T>::esLlena()
{
	if (fin == capacidad - 1)
		return true;
	return false;
}

template <typename T>
void ColaEstatica <T>::encolar(T elemento)
{
	if (!esLlena()) {
		fin++;
		vector[fin] = elemento;
	}
	else
	{
		cout << "La cola esta LLENA!";
	}
}

template <typename T>
void ColaEstatica <T>::desencolar()
{
	if (!esVacia()) {
		for (int i = 1; i <= fin; i++)
			vector[i - 1] = vector[i];
		fin--;
	}
	else
		cout << "La cola esta VACIA!";
}

template <typename T>
void ColaEstatica <T>::obtenerFrente()
{
	if (esVacia()) {
		cout << "La cola esta VACIA!";
	}
	else
		cout << vector[0];
}

template <typename T>
void ColaEstatica <T>::mostrarCola() {
	if (!esVacia())
	{
		for (int i = 0; i <= fin; i++)
		{
			cout << vector[i] << " ";
		}
	}
	else
		cout << "La cola esta VACIA!" << endl;
}

int main() {
	bool mantener = true;
	int opcion, elemento;

	ColaEstatica<int> c1(100);
	c1.desencolar();
	c1.desencolar();

	do {
		cout << endl;
		cout << "---------- MENU - COLA ----------" << endl;
		cout << "Ingrese la opcion que desea usar\n" << endl;
		cout << "1) ENCOLAR" << endl;
		cout << "2) DESENCOLAR" << endl;
		cout << "3) MOSTRAR EL FRENTE" << endl;
		cout << "4) MOSTRAR LA COLA" << endl;
		cout << "5) SALIR DEL MENU\n" << endl;
		cout << "OPCION ELEGIDA: ";
		cin >> opcion;

		system("cls");

		switch (opcion)
		{
		case 1:
			cout << "\nIngrese el elemento que se insertara a la cola: ";
			cin >> elemento;
			c1.encolar(elemento);
			cout << endl;
			break;
		case 2:
			c1.desencolar();
			break;
		case 3:
			cout << "El frente es: ";
			c1.obtenerFrente();
			break;
		case 4:
			cout << "La cola es: ";
			c1.mostrarCola();
			break;
		case 5:
			mantener = false;
			break;
		default:
			cout << "Elija una opcion del menu del 1 al 5" << endl;
			break;
		}
	} while (mantener);

	return 0;
}
