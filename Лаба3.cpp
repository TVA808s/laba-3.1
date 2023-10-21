#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//ВВОДЫ
void inputN(int* masN, int kol) {
	for (int i = 0; i < kol; i++) {
		cin >> masN[i];
	}

}
void inputC(char* masC,int kol) {

	for (int i = 0; i < kol; i++) {
		cin >> masC[i];
	}
}

//ВЫВОДЫ
void outputN(int* masN, int kol) {
	for (int i = 0; i < kol; i++) {
		cout << masN[i]<<"  ";
	}
	cout << endl;
}
void outputC(char* masC,int kol) {
	for (int i = 0; i < kol; i++) {
		cout << masC[i]<<"  ";
	}
	cout << endl;
}
//ОСНОВА ТАК СКАЗАТЬ БАЗА
void first(int *masN, int kol) {
	inputN(masN,kol);
	//сортировка
	for (int m = 0; m < kol - 1; m++) {
		for (int j = 0; j < kol - m - 1; j++) {
			if (masN[j] > masN[j + 1]) {
				int temp = masN[j];
				masN[j] = masN[j + 1];
				masN[j + 1] = temp;
	}}}
	outputN(masN, kol);
}

void second(char *masC,int kol) {
	inputC(masC, kol);
	//сортировка подсчетом
	const int el = 26;
	int counter[el] = { 0 };
	int j = 0;
	for (int r = 0; r < kol; r++) {
		j = int(masC[r] - 'a');
		counter[j]++;
	}
	int r = 0;
	j = 0;
	while (j<=el) {
		if (counter[j] > 0) {
			masC[r] = char(int('a') + j);
			r++;
			counter[j]--;
		}
		else {
			j++;
		}}
	outputC(masC, kol);
}

void third(int *masN,int kol) {
	inputN(masN, kol);
}

int main() {
	cout << "Input number of a test\t";
	int op,kol;
	cin >> op;
	cout << "Input how many symbols you will use\t";
	cin >> kol;
	cout << endl << endl;
	//инициализируем
	char masC[1000];
	int masN[1000];
	char *c = &masC[0];
	int* n = &masN[0];
	//НАЧАЛО РАБОТЫ
	switch(op){
		case 1:
			first(n,kol);
			break;
		case 2:
			second(c,kol);
			break;
		case 3:
			third(n,kol);
			break;
		default:
			cout << "I dont know this operation, try again\n";
			main();
		}


}

