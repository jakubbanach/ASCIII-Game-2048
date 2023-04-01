#include <bits/stdc++.h>

using namespace std;

int size;

int ** game = new int * [size];

char beging = 'a', moveg;

int rozmiar_tab()
{

    int rozmiar;
    cin >> rozmiar;
    if(n != 6 & rozmiar != 8 & rozmiar!= 10){
        if(rozmiar<3)
        {
          cout << "To jest za malo...." << endl;
          rozmiar_tab();
        }
        if(rozmiar > 11){
            cout << "No już nie przesadzaj." << endl;
            rozmiar_tab();
        }
        else if(rozmiar>10)
        {
            cout << "No chyba Ciebie pogrzalo...." << endl;
            rozmiar_tab();
        }

    }
     return rozmiar;
}

void ekran_startowy()
{
	cout << endl;
	cout << "                   Gra 2024" << endl;
	cout << "-----------------------------------------------------" << endl;
    cout <<"Wpisz rozmiar tablicy do gry:" << endl;
    cout <<"wybierz jeden z zalecanych rozmiarów: 6, 8, 10" << endl;
    size = rozmiar_tab();
	cout << "Aby rozpoczac gre wcisnij 's'" << endl;
	cout << "W kazdym momencie mozesz zakonczyc gre klikajac 'q'" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Wybierz przycisk: ";
}

void ekran_koncowy()
{
    system( "cls" );
    cout << endl;
	cout << "       KONIEC GRY" << endl;
	cout << "--------------------------" << endl;
	cout << "       TWOJ WYNIK" << endl;
	cout << "         ****" << endl;
	cout << "--------------------------" << endl;
	cout << "Zespol:" << endl;
	cout << "*Milena Smolka" << endl;
	cout << "*Kaja Dzielnicka:" << endl;
	cout << "*Kinga Wrona:" << endl;
	cout << "*Jakub Banach:" << endl;
	cout << "--------------------------" << endl;
}
int main()
{
    while ( true)
    {
        ekran_startowy();   //poczatek gry
        cin >> beging;

        for (int i = 0; i<size; i++)
        {
		    game[i] = new int [size];
        }


        if ( beging == 'q' )    //koniec gry
        {
            //cout << "Dzieki za gre!";
            ekran_koncowy();
            delete [] game;
            return 0;
        }
        if ( beging == 's' ) break;
        system( "cls" );
    }


// wypełniam jak na razie wszytkie pola 0
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            game[i][j] = 0;
            cout << " " << game[i][j] << " ";
        }

         cout << "\n";
    }


    system( "cls" );
    while ( true )
    {

        cout << "Aby grac uzywaj wsad" << endl << endl;

        for ( int i = 0; i < size;  i++ )
        {
            for ( int j = 0; j < size; j++ )
                cout << game[i][j] << " ";
            cout << endl;
        }
        cout << endl;

        cin >> moveg;
        if ( moveg == 'q' )
        {
            ekran_koncowy();
            delete [] game;
            return 0;
        }

        return 0;
    }

}
