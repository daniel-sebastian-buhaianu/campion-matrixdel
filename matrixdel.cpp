#include <fstream>
#define MAX_LINII 101
#define MAX_COLOANE 101
using namespace std;
int matrice[MAX_LINII][MAX_COLOANE], nrLinii, nrColoane;
bool linieStearsa[MAX_LINII], coloanaStearsa[MAX_COLOANE];
int main()
{
	int i, j, nrLiniiDeSters, nrColoaneDeSters;
	ifstream fin("matrixdel.in");
	fin >> nrLinii >> nrColoane;
	for (i = 1; i <= nrLinii; i++)
		for (j = 1; j <= nrColoane; j++)
			fin >> matrice[i][j];
	fin >> nrLiniiDeSters;
	while (nrLiniiDeSters > 0)
	{
		fin >> i;
		linieStearsa[i] = 1;
		nrLiniiDeSters--;
	}
	fin >> nrColoaneDeSters;
	while (nrColoaneDeSters > 0)
	{
		fin >> j;
		coloanaStearsa[j] = 1;
		nrColoaneDeSters--;
	}
	fin.close();
	ofstream fout("matrixdel.out");
	for (i = 1; i <= nrLinii; i++)
	{
		if (!linieStearsa[i])
		{
			for (j = 1; j <= nrColoane; j++)
				if (!coloanaStearsa[j])
					fout << matrice[i][j] << ' ';
			fout << '\n';
		}
	}
	fout.close();
	return 0;
}
