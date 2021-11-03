#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define num unsigned long long
// p = primo, g = base, x = exponente
// g ^ x (mod p) 
num exp_mod(num p, num g, num x)
{
	num temp = g, result;
	for (result = 1; x; x >>= 1) {
		if(x & 1)
			result = ((result % p) * (temp % p)) % p;
		temp = ((temp % p) * (temp % p)) % p;
	}

	return result;
}


num raiz_primitiva(num p)
{
	num raiz = 2;
	num x = 1;
	for (; raiz < p; raiz++) {
		for (x = 1; x < p - 1; x++)
			if (exp_mod(p, raiz, x) == 1) break;
		if (x == (p - 1)) return raiz;
	}
	return 0;
}

void pregunta_3() {
	num raiz = 6;
	num x = 1;
	for (; x < 100049; x++) {
		if (exp_mod(100049, raiz, x) == 2021)
			break;
	}

	cout << "g ^ x mod 100049 = 2021" << "\n";
	cout << "La solucion para x , es : " << x << "\n\n";
}


int main()
{
	num p = 1;
	do{
		cout << "Introduzca un primo: "; cin >> p;
		cout << "Su raiz primitiva es: " << raiz_primitiva(p);
		cout << "\n--------------\n";
	} while (p);
	

	//pregunta_3();
	return 0;
}