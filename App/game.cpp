#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int size = 4;
int game[::size][::size];
// '::size' means that it refers to the global 'size' 
int punkty = 0;
char input;

int sprawdzenie();
int czy_pusta_tablica();
void tekst();
void tekst_punkty();
void instrukcja();
void ekran_startowy();
void ekran_koncowy();
void generator_liczb();
void generator_kolejnych_liczb();
void przesuwanie_lewo();
void przesuwanie_prawo();
void przesuwanie_gora();
void przesuwanie_dol();
void wypisz_tablice();
void pusta_tablica();

int main()
{
    srand(time(NULL));
    input='r';
    while(input=='r')
    {
        system("cls");
        pusta_tablica();
        punkty=0;
        while(input!='b'&&input!='q')//uruchomienie programu
        {
            ekran_startowy();
            cin >> input;
            system("cls");
            switch (input)
            {
                case 'q':
                    //system("cls");
                    //ekran_koncowy();
                    break;
                case 'b':
                    system("cls");
                    generator_liczb();
                    wypisz_tablice();
                    break;
                default:
                    cout << "Wcisnij inny przycisk, aby kontynuwoac" << endl;
            }
        }
        system("cls");
        while(input!='q')//glowny program
        {
            instrukcja();
            cout << "OBECNA TABLICA\n" << endl;
            wypisz_tablice();
            tekst_punkty();
            cin >> input;
            system("cls");
            switch (input)
            {
            case 'q':
                //ekran_koncowy();
                break;
                //return 0;
            case 'w':   //ruch do gory
                przesuwanie_gora();
                break;
            case 's':   //ruch w dol
                przesuwanie_dol();
                break;
            case 'a':   //ruch w lewo
                przesuwanie_lewo();
                break;
            case 'd':   //ruch w prawo
                przesuwanie_prawo();
                break;
            default:
                //punkty -= 10;
                cout << "Wcisnij inny przycisk, aby grac"<< endl;//, otrzymujesz -10pkt" << endl;
                break;
            }
            if(input=='w'||input=='s'||input=='a'||input=='d')  //wykonuje tylko gdy zostal klikniety jeden z przyciskow wsad
            {
                if(czy_pusta_tablica())
                {
                    tekst();
                    continue;
                }
                generator_kolejnych_liczb();
                if(sprawdzenie())
                {
                    //system("cls");
                    //ekran_koncowy();
                    input='q';
                    //return 0;
                }
            }
        }
        system("cls");
        ekran_koncowy();
        cout << endl;
        cout << "Jesli chcesz zagrac jeszcze raz kliknij 'r'" << endl;
        cin >> input;
        switch(input)
        {
            case 'r':
                break;
            default:
                input='q';
        }
    }
    return 0;

}

int czy_pusta_tablica(){
    int ilosc=0;
    for ( int i = 0; i < ::size;  i++ )
        for ( int j = 0; j < ::size; j++ )
            if(game[i][j]!=0)
                ilosc++;
    if(ilosc==::size * ::size)
        return 1;
    return 0;
}

int sprawdzenie(){
    int MORE = ::size + 2;
    int nowy[::size + 2][::size + 2]; //nowa tablica, powiekszona o rozmiar z kazdej strony
    int ilosc=0;
    for ( int i = 0; i < MORE;  i++ )
        for ( int j = 0; j < MORE; j++ )
        {
            if(j==0||j==MORE-1||i==0||i==MORE-1)
                nowy[i][j]=1;
            else
                nowy[i][j]=game[i-1][j-1];
        }

    for ( int i = 1; i < MORE-1;  i++ )
    {
        for ( int j = 1; j < MORE-1; j++ )
        {
            int ob=nowy[i][j];
            if(ob==0)
                return 0;
            int a=nowy[i][j+1];
            int b=nowy[i][j-1];
            int c=nowy[i+1][j];
            int d=nowy[i-1][j];

            if(a!=0&&b!=0&&c!=0&&d!=0&&ob!=a&&ob!=b&&ob!=c&&ob!=d)
                ilosc++;
        }
    }
    if(ilosc==::size * ::size)
        return 1;
    return 0;
}

void tekst(){
    cout << "#########################" << endl;
    cout << "NIE MOZESZ SIE TAK RUSZYC" << endl;
    cout << "#########################\n" << endl;
}

void tekst_punkty(){
    cout << "\nPunkty: "<< punkty << endl;
}

void instrukcja(){
    cout << "-----------------------------------------------------" << endl;
    cout << "Poruszanie:" << endl;
    cout << "w - elementy przesuwaja sie do gory" << endl;
    cout << "s - elementy przesuwaja sie w dol" << endl;
    cout << "a - elementy przesuwaja sie w lewo" << endl;
    cout << "d - elementy przesuwaja sie w prawo\n" << endl;

    //cout << "Aby uzyskac wiecej informacji o mechanice kliknij 'i'" << endl;
    cout << "W kazdym momencie mozesz zakonczyc gre klikajac 'q'" << endl;
    cout << "-----------------------------------------------------" << endl;
}

void ekran_startowy(){
	cout << endl;
	cout << "                   Gra 2048" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Aby rozpoczac gre wcisnij 'b'" << endl;
	cout << "W kazdym momencie mozesz zakonczyc gre klikajac 'q'" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Wybierz przycisk: ";
}

void ekran_koncowy(){
    cout << endl;
	cout << "       KONIEC GRY" << endl;
	cout << "--------------------------" << endl;
	cout << "       TWOJ WYNIK" << endl;
	cout << "          " << punkty << endl;
	cout << "--------------------------" << endl;
	cout << "       TWOJA TABLICA\n";
	wypisz_tablice();
    cout << "--------------------------" << endl;
	//cout << endl;
	cout << "Zespol:" << endl;
	cout << "*Milena Smolka" << endl;
	cout << "*Kaja Dzielnicka:" << endl;
	cout << "*Kinga Wrona:" << endl;
	cout << "*Jakub Banach:" << endl;
	cout << "--------------------------" << endl;
}

void generator_liczb(){

    int x = rand() %16; //losowanie pierwszego miejsca
    int y = rand() %16; //losowanie drugiego miejsca
    while ( x == y)
        int y = rand() %16;

    int where = 0;
    for ( int i = 0; i < ::size;  i++ )
        for ( int j = 0; j < ::size; j++ )
        {
            if ( where == x || where == y )
            {
                int z = rand() %2;
                if ( z == 1 ) game[i][j] = 4;
                else game[i][j] = 2;
            }
            where++;
        }
}

void generator_kolejnych_liczb(){

    int pom=0; //zmienna pomocnicza - pomaga wyjsc z zagniezdzonej petli

    while(pom!=1)
    {
        int x = rand() %16; //losuje miejsce dla liczby w tablicy dwuwymiarowej
        int where = 0;  //ustawia zmienna na wartosc poczatku tablicy
        for ( int i = 0; i < ::size;  i++ )
        {
            if(pom!=1)
            {
                for ( int j = 0; j < ::size; j++ )
                {
                    if ( where == x) // x zgadza sie z wybranym elementem
                    {
                        if(game[i][j]==0) //jesli miejsce w tablicy jest puste
                        {
                            int z = rand() %2;  //generowanie jednej z dwoch liczb (2 lub 4)
                            if ( z == 1 ) game[i][j] = 4;
                            else game[i][j] = 2;
                            pom=1;
                            break;
                        }
                        else
                            break;
                    }
                    where++;
                }
            }
            else
                break;
        }
    }
}

void przesuwanie_lewo(){
    int SIZE = ::size;
    for(int i=0;i< SIZE;i++)    //wykonuje petle po 4 wierszach
    {
        int j=1;
        
        while(j< SIZE) //wykonuje petle po kolumnach
        {
            int ilosc=j-1;
            int pom=game[i][j-1]; //wartosc pierwszego elementu, rozpoczynajacego sie od j-tej kolumny

            while(pom==0&&ilosc<SIZE-1) //wykonuje dopoki pierwszy element bedzie rozny od zera lub skonczy sie warunek gdy caly wiersz to zera
            {
                for(int k=j;k<SIZE;k++)   //przesuwa elementy do lewej strony tablicy
                    game[i][k-1]=game[i][k];

                game[i][SIZE-1]=0;
                pom=game[i][j-1];   //przypisanie ponownej wartosci pierwszemu elementowi
                ilosc++;
            }

            int ilosc2=j;
            int pom2=game[i][j]; //wartosc drugiego elementu, rozpoczynajacego sie od j-tej kolumny
            while(pom2==0&&ilosc2<SIZE-1) //wykonuje dopoki drugi element bedzie rozny od zera lub skonczy sie warunek gdy caly wiersz to zera
            {
                for(int k=j;k<SIZE-1;k++)
                    game[i][k]=game[i][k+1];    //przesuwa elementy do lewej strony tablicy

                game[i][SIZE-1]=0;
                pom2=game[i][j];
                ilosc2++;

            }

            if(pom==pom2)   //porownuje dwa elementy
            {
                pom+=pom2;  //dodaje je do siebie gdy sa takie same
                punkty+=pom;    //dodawanie punktow
                game[i][j-1]=pom;   //przypisuje pierwszemu elementowi wartosc po dodaniu
                game[i][j]=0;   //zeruje drugi element przed kolejnym wykonaniem petli
            }
            else
                game[i][j-1]=pom;
            j++;
        }
    }
}

void przesuwanie_prawo(){
    int SIZE = ::size;
    for(int i=0;i<SIZE;i++)
    {
        int j=SIZE-2;
        while(j>=0)
        {
            int ilosc=j+1;
            int pom=game[i][j+1];

            while(pom==0&&ilosc>0)
            {
                for(int k=j;k>=0;k--)
                    game[i][k+1]=game[i][k];

                game[i][0]=0;
                pom=game[i][j+1];
                ilosc--;
            }

            int ilosc2=j;
            int pom2=game[i][j];

            while(pom2==0&&ilosc2>0)
            {
                for(int k=j-1;k>=0;k--)
                    game[i][k+1]=game[i][k];

                game[i][0]=0;
                pom2=game[i][j];
                ilosc2--;
            }

            if(pom==pom2)
            {
                pom+=pom2;
                punkty+=pom;
                game[i][j+1]=pom;
                game[i][j]=0;
            }
            else
                game[i][j+1]=pom;

            j--;
        }
    }
}

void przesuwanie_gora(){
    int SIZE = ::size;
    for(int i=0;i<SIZE;i++)    //wykonuje petle po 4 kolumnach
    {
        int j=1;
        while(j<SIZE) //wykonuje petle po wierszach
        {
            int ilosc=j-1;
            int pom=game[j-1][i]; //wartosc pierwszego elementu, rozpoczynajacego sie od j-tego wiersza

            while(pom==0&&ilosc<SIZE-1) //wykonuje dopoki pierwszy element bedzie rozny od zera lub skonczy sie warunek gdy cala kolumna to zera
            {
                for(int k=j;k<SIZE;k++)   //przesuwa elementy do gornej czesci tablicy
                    game[k-1][i]=game[k][i];

                game[SIZE-1][i]=0;
                pom=game[j-1][i];   //przypisanie ponownej wartosci pierwszemu elementowi
                ilosc++;
            }

            int ilosc2=j;
            int pom2=game[j][i]; //wartosc drugiego elementu, rozpoczynajacego sie od j-tego wiersza
            while(pom2==0&&ilosc2<SIZE-1)
            {
                for(int k=j;k<SIZE-1;k++)    //wykonuje dopoki drugi element bedzie rozny od zera lub skonczy sie warunek gdy cala kolumna to zera
                    game[k][i]=game[k+1][i];    //przesuwa elementy do gornej strony tablicy

                game[SIZE-1][i]=0;
                pom2=game[j][i];
                ilosc2++;

            }

            if(pom==pom2)   //porownuje dwa elementy
            {
                pom+=pom2;  //dodaje je do siebie gdy sa takie same
                punkty+=pom;    //dodawanie punktow
                game[j-1][i]=pom;   //przypisuje pierwszemu elementowi wartosc po dodaniu
                game[j][i]=0;   //zeruje drugi element przed kolejnym wykonaniem petli
            }
            else
                game[j-1][i]=pom;
            j++;
        }
    }
}

void przesuwanie_dol(){
    int SIZE = ::size;
    for(int i=0;i<SIZE;i++)
    {
        int j=SIZE-2;
        while(j>=0)
        {
            int ilosc=j+1;
            int pom=game[j+1][i];
            while(pom==0&&ilosc>0)
            {
                for(int k=j;k>=0;k--)
                    game[k+1][i]=game[k][i];

                game[0][i]=0;
                pom=game[j+1][i];
                ilosc--;
            }

            int ilosc2=j;
            int pom2=game[j][i];
            while(pom2==0&&ilosc2>0)
            {
                for(int k=j-1;k>=0;k--)
                    game[k+1][i]=game[k][i];

                game[0][i]=0;
                pom2=game[j][i];
                ilosc2--;
            }

            if(pom==pom2)
            {
                pom+=pom2;
                punkty+=pom;
                game[j+1][i]=pom;
                game[j][i]=0;
            }
            else
                game[j+1][i]=pom;

            j--;
        }
    }
}

void wypisz_tablice(){
    for ( int i = 0; i < ::size;  i++ )
    {
        cout << "\t";
        for ( int j = 0; j < ::size; j++ )
            cout << game[i][j] << " ";
        cout << endl;
    }
}

void pusta_tablica(){
    for ( int i = 0; i < ::size;  i++ )
        for ( int j = 0; j < ::size; j++ )
            game[i][j]=0;
}
