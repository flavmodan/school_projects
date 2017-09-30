#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>

#define M 3 // Marimea turnului

using namespace std;

int sol_conter = 0;

struct cube
{
	int length;
	string color;
};

vector<cube> cubes = {{7, "red"},{4, "blue"},{3, "green"},{5, "green"},{2, "purple"},{1, "purple"}, {8, "blue"}};

void print(cube tower[M]) {
	for (int i = 0; i < M; i++)
		cout << tower[i].length << " - " << tower[i].color << endl;
	cout << endl;
}

bool check(cube tower[M]) {
	for (int i = 0; i < M - 1; i++)
		if (tower[i].length < tower[i + 1].length || tower[i].color == tower[i + 1].color)
			return false;
	return true;
}

void bkt(cube tower[M], int pos = 0) {
	for (int i = 0; i < cubes.size(); i++) {
		tower[pos] = cubes[i];
		if (pos != M - 1)
			bkt(tower, pos + 1);
		else if (check(tower)) {
			sol_conter++;
			print(tower);
		}
	}
}

int main(int argc, char* argv[]) {
	cube tower[M];
	sort(cubes.begin(), cubes.end(), [](cube a, cube b) { return a.length > b.length; }); // ca sa fie afisate in ordine descrescatoare

	bkt(tower);
	cout << "Number of solutions: " << sol_conter << endl;
	system("pause");
}
