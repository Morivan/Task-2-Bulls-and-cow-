#include <iostream>
#include <vector>
//Игра "Быки и коровы"

//Перевод количества чисел в максимальный разряд
int digit(int bin) {
	int g = 1;
	for (int i = 0; i < bin; i++) g = g * 10;
	return g;
}
//Вектор пользователя
std::vector <int> vctr_my(int bin, int num) {
	std::vector <int> your_vctr(12);
	for (int i = 0; i < bin; ++i) {
		your_vctr[i] = num / digit(bin - (1 + i)) % 10;
	}
	return your_vctr;
}
//Сгенерированный вектор
std::vector <int> vctr_random(int bin) {
	std::vector <int> vctr_pc(12);
	srand(time(NULL));
	for (int i = 0; i < bin; ++i) {
		vctr_pc[i] = rand() % 10;
		if (vctr_pc[0] == 0) vctr_pc[0] = rand() % 10;
		std::cout << vctr_pc[i];
	}
	return vctr_pc;
}
//Проверка вектора пользователя с генерированным вектором
int GG(std::vector <int> vctr_pc, std::vector <int> your_vctr, int bin, int num,int tries) {
	while (vctr_pc != your_vctr) {
		int bull = 0, cow = 0, c = bin;
		for (int i = 0; i < bin; i++) if (vctr_pc[i] == your_vctr[i]) bull++;
		for (int i = 0; i < bin; i++)
			for (int c = 0; c < bin; c++)
				if (vctr_pc[i] == your_vctr[c])
					cow++;
		std::cout << "\nbulls " << bull;
		std::cout << "\ncow " << cow - bull;
		std::cout << "\nEnter number:";
		std::cin >> num;
		std::vector <int> your_vctr = vctr_my(bin, num);
		if (vctr_pc == your_vctr) {
			std::cout << "\nIt took you " << tries << "tries\n";
			return 0;
		}
		tries++;
		if (GG(vctr_pc, your_vctr, bin, num, tries) == 0) return 0;
	}
}
// Главная функция
	int main() {
	int bin, num, tries = 2;
	std::cout << "Enter digit:";
	std::cin >> bin;
	std::vector <int> vctr_pc = vctr_random(bin);
	std::cout << "\nEnter number:";
	std::cin >> num;
	std::vector <int> your_vctr = vctr_my(bin, num);
	GG(vctr_pc, your_vctr, bin, num, tries);
	std::cout << "You win";
	return 0;
}