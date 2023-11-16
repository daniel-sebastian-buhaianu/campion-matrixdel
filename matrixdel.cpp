#include <fstream>
#define MAX_LINII 101
#define MAX_COLOANE 101
using namespace std;
int matrice[MAX_LINII][MAX_COLOANE];
int liniaInitiala[MAX_LINII], coloanaInitiala[MAX_COLOANE];
int nrLinii, nrColoane;
void stergeLinia(int);
void stergeColoana(int);
int main()
{
	int i, j, nrLiniiDeSters, nrColoaneDeSters;
	ifstream fin("matrixdel.in");
	fin >> nrLinii >> nrColoane;
	for (j = 1; j <= nrColoane; j++)
		coloanaInitiala[j] = j;
	for (i = 1; i <= nrLinii; i++)
	{
		liniaInitiala[i] = i;
		for (j = 1; j <= nrColoane; j++)
			fin >> matrice[i][j];
	}
	fin >> nrLiniiDeSters;
	while (nrLiniiDeSters > 0)
	{
		fin >> i;
		stergeLinia(i);
		nrLiniiDeSters--;
	}
	fin >> nrColoaneDeSters;
	while (nrColoaneDeSters > 0)
	{
		fin >> j;
		stergeColoana(j);
		nrColoaneDeSters--;
	}
	fin.close();
	ofstream fout("matrixdel.out");
	for (i = 1; i <= nrLinii; i++)
	{
		for (j = 1; j <= nrColoane; j++)
			fout << matrice[i][j] << ' ';
		fout << '\n';
	}
	fout.close();
	return 0;
}
void stergeColoana(int nrColoana)
{
	for (int j = coloanaInitiala[nrColoana]; j < nrColoane; j++)
	{
		coloanaInitiala[j+1] = j;
		for (int i = 1; i <= nrLinii; i++)
			matrice[i][j+1] = matrice[i][j];
	}
	nrColoane--;
	coloanaInitiala[nrColoana] = 0;
}
void stergeLinia(int nrLinie)
{
	for (int i = liniaInitiala[nrLinie]; i < nrLinii; i++)
	{
		liniaInitiala[i+1] = i;
		for (int j = 1; j <= nrColoane; j++)
			matrice[i][j] = matrice[i+1][j];
	}
	nrLinii--;
	liniaInitiala[nrLinie] = 0;
}
