#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>

using namespace std;
int pozX = 0;
int pozY = 0;

void dynamicArray(int** tabela, int kolumny, int wiersze)
{
		for (int i=0; i<wiersze ; ++i)
		{
			for (int j=0; j <kolumny ;j++)
			{
				tabela[j][i] = 0;
				
			}
		}
		pozX=0;
		pozY=0;
}
bool sprawdzGraniceMapyLewa()
{
	if((pozY == 0 ))
	{
		return false;
	}
	return true;
}
bool sprawdzGraniceMapyPrawa(int dimension)
{
	if((pozY == (dimension - 1)))
	{
		return false;
	}
	return true;
}
bool sprawdzGraniceMapyDol(int dimension)
{
	if((pozX == (dimension - 1)))
	{
		return false;
	}
	return true;
}
bool sprawdzGraniceMapyGora()
{
	if((pozX == 0))
	{
		return false;
	}
	return true;
}
void ruchWPrawo(int** tabela, int userColumns)
{
	if (tabela[pozX][pozY+1] == 1)
	{
		cout << "nie mozesz ruszyc sie w ta strone bo stoi tu kamien" << endl;
		return;
	}

	else if (tabela[pozX][pozY+1] == 0)
	{
		do {
			if (sprawdzGraniceMapyPrawa(userColumns))
			{
				pozY++;
				tabela[pozX][pozY] = {9};
				tabela[pozX][pozY-1] = {0};

				if (sprawdzGraniceMapyPrawa(userColumns))
				{
					if (tabela[pozX][pozY+1] == 1)
					{
						cout << "dotarles do kamienia prawo, gdzie idziesz teraz?" << endl;
						break;
					}
					else if (tabela[pozX][pozY+1] == 2)
					{
						cout << "brawo, dotarles do mety, goodjob" << endl;
						break;
					}
				}
			}
		} while (pozY<(userColumns -1));
	}
	else if (tabela[pozX][pozY+1] == 2)
	{

		cout << "brawo, dotarles do mety, goodjob" << endl;
		return;
	}

}
void ruchWPrawoAutomatyczny(int** tabela, int userColumns)
{
	if (tabela[pozX][pozY+1] == 1)
	{
		return;
	}

	else if (tabela[pozX][pozY+1] == 0)
	{
		do {
			if (sprawdzGraniceMapyPrawa(userColumns))
			{
				pozY++;
				tabela[pozX][pozY] = {9};
				tabela[pozX][pozY-1] = {0};

				if (sprawdzGraniceMapyPrawa(userColumns))
				{
					if (tabela[pozX][pozY+1] == 1)
					{
						break;
					}
					else if (tabela[pozX][pozY+1] == 2)
					{
						break;
					}
				}
			}
		} while (pozY<(userColumns -1));
	}
	else if (tabela[pozX][pozY+1] == 2)
	{
		return;
	}

}
void ruchWLewo(int** tabela)
{
	if (tabela[pozX][pozY-1] == 1)
	{
		cout << "nie mozesz ruszyc sie w ta strone bo stoi tu kamien" << endl;
		return;
	}

	else if (tabela[pozX][pozY-1] == 0)
	{
		do {
			if (sprawdzGraniceMapyLewa())
			{
				pozY--;
				tabela[pozX][pozY] = {9};
				tabela[pozX][pozY+1] = {0};
				if (sprawdzGraniceMapyLewa() == false)
				{
						cout << "dotarles do kranca mapy, tam nie idziemy" << endl;
					break;
				}
				else
				{
					if (tabela[pozX][pozY-1] == 1)
					{
						cout << "dotarles do kamienia lewo, gdzie idziesz teraz?" << endl;
						break;
					}
					else if (tabela[pozX][pozY-1] == 2)
					{
						cout << "brawo, dotarles do mety, goodjob" << endl;
						break;
					}
				}
			}
		} while (pozY>0);

	}
	else if (tabela[pozX][pozY-1] == 2)
	{

		cout << "brawo, dotarles do mety, goodjob" << endl;
		return;
	}
}
void ruchWLewoAutomatyczny(int** tabela)
{
	if (tabela[pozX][pozY-1] == 1)
	{
		return;
	}

	else if (tabela[pozX][pozY-1] == 0)
	{
		do {
			if (sprawdzGraniceMapyLewa())
			{
				pozY--;
				tabela[pozX][pozY] = {9};
				tabela[pozX][pozY+1] = {0};
				if (sprawdzGraniceMapyLewa() == false)
				{
					break;
				}
				else
				{
					if (tabela[pozX][pozY-1] == 1)
					{
						break;
					}
					else if (tabela[pozX][pozY-1] == 2)
					{
						break;
					}
				}
			}
		} while (pozY>0);

	}
	else if (tabela[pozX][pozY-1] == 2)
	{
		return;
	}
}
void ruchWDol (int** tabela, int userRows)
{
	if (tabela[pozX+1][pozY] == 1)
	{
		cout << "nie mozesz ruszyc sie w ta strone bo stoi tu kamien" << endl;
		return;
	}

	else if (tabela[pozX+1][pozY] == 0)
	{
		do {

			if (sprawdzGraniceMapyDol(userRows))
			{
				pozX++;

				tabela[pozX][pozY] = {9};
				tabela[pozX-1][pozY] = {0};
				if (sprawdzGraniceMapyDol(userRows))
				{
					if (tabela[pozX+1][pozY] == 1)
					{
						cout << "dotarles do kamienia dol, gdzie idziesz teraz?" << endl;
						break;
					}
					else if (tabela[pozX+1][pozY] == 2)
					{
						cout << "brawo, dotarles do mety, goodjob" << endl;
						break;
					}
				}

			}
		} while (pozX<(userRows -1));

	}
	else if (tabela[pozX+1][pozY] == 2)
	{
		cout << "brawo, dotarles do mety, goodjob" << endl;
		return;
	}
}
void ruchWDolAutomatyczny (int** tabela, int userRows)
{
	if (tabela[pozX+1][pozY] == 1)
	{
		return;
	}

	else if (tabela[pozX+1][pozY] == 0)
	{
		do {

			if (sprawdzGraniceMapyDol(userRows))
			{
				pozX++;

				tabela[pozX][pozY] = {9};
				tabela[pozX-1][pozY] = {0};
				if (sprawdzGraniceMapyDol(userRows))
				{
					if (tabela[pozX+1][pozY] == 1)
					{
						break;
					}
					else if (tabela[pozX+1][pozY] == 2)
					{
						break;
					}
				}

			}
		} while (pozX<(userRows -1));

	}
	else if (tabela[pozX+1][pozY] == 2)
	{
		return;
	}
}
void ruchWGore (int** tabela)
{
	if (tabela[pozX - 1][pozY] == 1)
	{
		cout << "nie mozesz ruszyc sie w ta strone bo stoi tu kamien" << endl;
		return;
	}

	else if (tabela[pozX - 1][pozY] == 0)
	{
		do
		{
			if (sprawdzGraniceMapyGora())
			{
				pozX--;
				tabela[pozX][pozY] = { 9 };
				tabela[pozX + 1][pozY] = { 0 };

				if (sprawdzGraniceMapyGora() == false)
				{
					cout << "dotarles do kranca mapy, tam nie idziemy" << endl;
					break;
				}
				else
				{
					if (tabela[pozX - 1][pozY] == 1)
					{
						cout << "dotarles do kamienia gora, gdzie idziesz teraz?"<< endl;
						break;
					}

					else if (tabela[pozX - 1][pozY] == 2)
					{
						cout << "brawo, dotarles do mety, goodjob" << endl;
						break;
					}
				}
			}
		} while (pozX > 0);
	}
	else if (tabela[pozX - 1][pozY] == 2)
	{
		cout << "brawo, dotarles do mety, goodjob" << endl;
		return;
	}
}
void ruchWGoreAutomatyczny (int** tabela)
{
	if (tabela[pozX - 1][pozY] == 1)
	{
		return;
	}

	else if (tabela[pozX - 1][pozY] == 0)
	{
		do
		{
			if (sprawdzGraniceMapyGora())
			{
				pozX--;
				tabela[pozX][pozY] = { 9 };
				tabela[pozX + 1][pozY] = { 0 };

				if (sprawdzGraniceMapyGora() == false)
				{
					break;
				}
				else
				{
					if (tabela[pozX - 1][pozY] == 1)
					{
						break;
					}

					else if (tabela[pozX - 1][pozY] == 2)
					{
						break;
					}
				}
			}
		} while (pozX > 0);
	}
	else if (tabela[pozX - 1][pozY] == 2)
	{
		return;
	}
}
void potwory()
{

	cout << "Chcesz wyjsc poza mape, tam sa potwory" << endl;
	return;

}
int losowanie1(int t)
{
	int kol;

	kol = rand() % t;

	return kol;
}
int losowanie2(int t)
{

	int wiersz;

	wiersz = rand() % t;

	return wiersz;
}
int main()
{

		int userColumns;
		int userRows;
		cout << "Witaj, gra polega na odnalezieniu wyjscia. Ty, jako gracz poruszasz siê liczb¹ 9 - twoim celem jest dostanie siê do numeru 2" << endl;
		cout << "Poruszasz siê za pomoc¹ WSAD odpowiednio w górê, dó³, lewo, prawo. Poprzez 0 mozesz swobodnie przechodzic, 1 cie zatrzymuje" << endl;
		cout << "Zalecana wielkosc mapy miesci sie pomiedzy 15 a 25, milej zabawy" << endl;
		cout << "podaj wartosc kolumn" << endl;
		cin >> userColumns ;
		cout << "podaj wartosc wierszy" << endl;
		cin >> userRows ;
		ponownyStart:

		int **tabela = new int*[userRows];
		for(int i = 0; i < userRows; ++i)
		{
			tabela[i] = new int[userColumns];
		}
		int **tabela2 = new int*[userRows];
				for(int i = 0; i < userRows; ++i)
				{
					tabela2[i] = new int[userColumns];
				}

		dynamicArray(tabela, userRows, userColumns);

	srand(time(0));

	losowanie1(userColumns);
	losowanie2(userRows);
	int kol;
	kol = rand() % userColumns;
	int wiersz;
	wiersz = rand() % userRows;

	tabela[kol][wiersz] = 2;
	tabela[0][0] = 9;

	int j;
	int k;
	int l;
	int nextMoveDirection = 0;
	int m = 0;
	int iterationNumber = 0;
	int zmienna;
	int failedTry;


	for (j = 0; j <= (userRows - 1 ); j++)
	{									// umieszczanie 2 i 9 w tabeli
		for (k = 0; k <= (userColumns - 1); k++)
		{
			if ((tabela[j][k] != 2) && (tabela[j][k] != 9))
			{

				if (tabela[j][k - 1] == 1 || tabela[j][k - 2] == 1)
				{
					zmienna = 0;
					m++;
				}
				else if ((tabela[j][k] != 2) && (tabela[j][k] != 9))
				{
					zmienna = rand() % 2;
				}

			}
			else
			{
				if (tabela[j][k] == 2)
				{
					zmienna = 2;
				}
				else
				{
					zmienna = 9;
				}
			}
			tabela[j][k] = zmienna;
			tabela2[j][k] = zmienna;
//			cout << tabela[j][k] << "     " << flush;

		}
//		cout << endl;
	}

	do
	{
		nextMoveDirection = rand () % 4;
//		cout << "p w tej iteracji wynios³o: " << nextMoveDirection << endl;
		if (nextMoveDirection==0)
		{
//			cout << "wywolal sie ruch w prawo " << endl;
			if (sprawdzGraniceMapyPrawa(userColumns))
			{
				ruchWPrawoAutomatyczny(tabela, userColumns);
			}
			else
			{
//				cout << "nie mozna ruszyc sie w prawo " << endl;
			}
		}

		if (nextMoveDirection==1)
		{
//			cout << "wywolal sie ruch w dol " << endl;
			if (sprawdzGraniceMapyDol(userRows))
			{
//				cout << "sprawdz dol" << endl;
				ruchWDolAutomatyczny(tabela, userRows);
			}
			else
			{
//				cout << "nie mozna ruszyc sie w dol " << endl;
			}

		}

		if (nextMoveDirection==2)
		{
	//		cout << "wywolal sie ruch w lewo " << endl;
			if (sprawdzGraniceMapyLewa())
			{
				ruchWLewoAutomatyczny(tabela);
			}
			else
			{
//				cout << "nie mozna ruszyc sie w lewo " << endl;
			}

		}
		if (nextMoveDirection==3)
		{
//			cout << "wywolal sie ruch w gore " << endl;
			if (sprawdzGraniceMapyGora())
			{
				ruchWGoreAutomatyczny(tabela);
			}
			else
			{
//				cout << "nie mozna ruszyc sie w gore " << endl;
			}

		}
//		if (iterationNumber>1996)
//		{
//			for (k = 0; k <= (userRows - 1); k++)
//			{														//wywolanie tablicy po ruchu
//				for (l = 0; l <= (userColumns - 1); l++)
//				{
//					cout << tabela[k][l] << "     " << flush;
//				}
//				cout << endl;
//			}
//			cout << endl;
//		}
//		cout << "pozX wynosi: "	<< pozX << endl;
//		cout << "pozY wynosi: "	<< pozY << endl;


		iterationNumber++;
		if ((pozX > 1 && pozX < (userRows - 1)) && (pozY > 1 && pozY < (userColumns -1)))
		{
			if (tabela[pozX][pozY+1] ==2 || tabela[pozX+1][pozY] == 2 || tabela[pozX][pozY-1] ==2 || tabela[pozX-1][pozY] == 2)
			{
				cout << "yupppi" << endl;
				break;
			}
		}

	} while (iterationNumber <= (userRows*userColumns*5));


	if (iterationNumber > (userRows*userColumns*5) || iterationNumber < (userRows*userColumns/2))
	{
		cout << "program nie znalaz³ rozwiazania lub bylo zbyt proste" << endl;
		cout << "losuje ponownie" << endl;
		iterationNumber = 0;
		failedTry++;
		cout << failedTry << endl;
		Sleep(1);
		for(int i = 0; i < userRows; i++)
				{
				    delete [] tabela[i];
					tabela[i] = NULL;
				}
					delete [] tabela;
					tabela = NULL;
		goto ponownyStart;
	}
	else
	{

		cout << "program znalazl rozwi¹zanie po " << iterationNumber << " probach " << endl;
		cout << "program musial stworzyc " << failedTry << "planszy" << endl;
		cout << "Dla przypomnienia: Jesteœ cyfrê 9, cyfra 2 to wyjœcie" << endl;
		cout << "Poruszasz siê za pomoc¹ WSAD odpowiednio w górê, dó³, lewo, prawo. Poprzez 0 mozesz swobodnie przechodzic, 1 cie zatrzymuje" << endl;
	}

	cout << endl;

	for (j = 0; j <= (userRows - 1 ); j++)
	{									// wywolanie po tym jak program znalazl rozwiazanie
		for (k = 0; k <= (userColumns - 1); k++)
		{
			cout << tabela2[j][k] << "     " << flush;
		}
		cout << endl;
	}
	pozX = 0;
	pozY = 0;

	do {
	//		cout << pozY << endl;   // wyswietlenie obecnej pozycji na Y
	//		cout << pozX << endl;   // wyswietlenie obecnej pozycji na X

			char ruch;
			cin >> ruch;

			switch (ruch)
			{
			case 'd':
				if (sprawdzGraniceMapyPrawa(userColumns))
				{
					ruchWPrawo(tabela2, userColumns);
				}
				else
					potwory();
				break;

			case 's':
				if (sprawdzGraniceMapyDol(userRows))
				{
					ruchWDol(tabela2, userRows);
				}
				else
					potwory();
				break;

			case 'a':
				if (sprawdzGraniceMapyLewa())
				{
					ruchWLewo(tabela2);
				}
				else
					potwory();
				break;

			case 'w':
				if (sprawdzGraniceMapyGora())
				{
					ruchWGore(tabela2);
				}
				else
					potwory();
				break;

			}

			for (j = 0; j <= (userRows - 1 ); j++)
				{									// wywolanie po tym jak program znalazl rozwiazanie
					for (k = 0; k <= (userColumns - 1); k++)
					{
						cout << tabela2[j][k] << "     " << flush;
					}
					cout << endl;
				}

		}while (tabela[pozX][pozY+1] !=2 || tabela[pozX+1][pozY] != 2 || tabela[pozX][pozY-1] !=2 || tabela[pozX-1][pozY] != 2);

	for(int i = 0; i < userRows; i++)
					{
					    delete [] tabela2[i];
						tabela2[i] = NULL;
					}
						delete [] tabela2;
						tabela2 = NULL;

			return 0;

	return 0;

}

