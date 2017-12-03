#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <ctime>
typedef unsigned int uint;

using namespace std;

int main() {
	static uint ende = 100000000;
	vector<uint> feld(ende);
	fstream file;
	uint i;
	clock_t start, end;
	start = clock();

	cout << sizeof(vector<uint>) << " " << vector<vector<uint> >().max_size() << " " << sizeof(uint)*8 << endl;
	for (i = 1; i < ende; i++) {
		feld[i] = i;
	}

	uint j = 2;
	while (j < (ende / 2)) {
		for (i = 2 * j; i < ende; i = i + j) {
			feld[i] = 0;

		}
		j++;
		while (feld[j] == 0) {
			j++;
		}
	}

	file.open("r:\\prime.txt", ios_base::out);
	for (i = 1; i < ende; i++) {
		if (feld[i]) {
			file << i << endl;
		}
	}
	file.close();
	end = clock();
	cout << (double)(end - start) / 1000 << "s" <<endl;
	system("pause");
	return 0;
}
