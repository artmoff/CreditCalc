#include <iostream>
#include <cmath>

using std::cin;
using std::cout;


int main() {
	setlocale(LC_ALL, "Russian");

	double summ = 0, srok = 0, procent = 0;
	int type = 0;
	bool choice = false;

	cout << "������� ����� �������: ";

	cin >> summ;
	cout << "������� ���� ������� (� �������): ";
	cin >> srok;
	cout << "������� ������� ���������� ������ (��� ����� %): ";
	cin >> procent;
	cout << "�������� ��� �������: " << "\n" << "1 - �����������" << "\n" << "2 - ������������������" << "\n";
	cin >> type;

	procent = procent / 12 /100;


	if (type == 1) {
		double platej = ((procent * pow((1 + procent), srok) / (pow((1 + procent), srok) - 1))) * summ;
		double pereplata = (platej * srok) - summ;
		double obsh_viplata = pereplata + summ;
		cout << "����������� ������: " << platej << "\n" << "���������: " << pereplata << "\n" << "����� �������: " << obsh_viplata << "\n";

	}

	else if (type == 2) {

		double platej_m = summ / srok, proc_ost = 0, summ_proc = 0;

		for (int i = 0, x = 0; x <= srok; i++, x++) {

			proc_ost = (((summ - (platej_m * i)) * procent));
			cout << x << " �����." << " ������: " << platej_m << " �������� �� �������:" << proc_ost << "\n";
			summ_proc = summ_proc + proc_ost;
		}
		cout << "����� ���������: " << summ + summ_proc;
	}

	else {
		cout << "������� ������ ��� �������!";
	}
	return 0;
}

