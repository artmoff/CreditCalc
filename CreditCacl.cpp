#include <iostream>
#include <cmath>

using std::cin;
using std::cout;


int main() {
	setlocale(LC_ALL, "Russian");

	double summ = 0, srok = 0, procent = 0;
	int type = 0;
	bool choice = false;

	cout << "Введите сумму кредита: ";

	cin >> summ;
	cout << "Введите срок кредита (в месяцах): ";
	cin >> srok;
	cout << "Введите годовую процентную ставку (без знака %): ";
	cin >> procent;
	cout << "Выберите тип кредита: " << "\n" << "1 - аннуитетный" << "\n" << "2 - дифференцированный" << "\n";
	cin >> type;

	procent = procent / 12 /100;


	if (type == 1) {
		double platej = ((procent * pow((1 + procent), srok) / (pow((1 + procent), srok) - 1))) * summ;
		double pereplata = (platej * srok) - summ;
		double obsh_viplata = pereplata + summ;
		cout << "Ежемесячный платеж: " << platej << "\n" << "Переплата: " << pereplata << "\n" << "Общая выплата: " << obsh_viplata << "\n";

	}

	else if (type == 2) {

		double platej_m = summ / srok, proc_ost = 0, summ_proc = 0;

		for (int i = 0, x = 0; x <= srok; i++, x++) {

			proc_ost = (((summ - (platej_m * i)) * procent));
			cout << x << " месяц." << " Платеж: " << platej_m << " Проценты по кредиту:" << proc_ost << "\n";
			summ_proc = summ_proc + proc_ost;
		}
		cout << "Всего выплачено: " << summ + summ_proc;
	}

	else {
		cout << "Неверно выбран тип кредита!";
	}
	return 0;
}

