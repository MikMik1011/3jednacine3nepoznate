#include <iostream>
#include <cstring>

using namespace std;

int koeficijenti[3][4];


int saberiKoeficijente(unsigned char index1, unsigned char index2, unsigned char index3) {
    int vrati = (koeficijenti[index1 / 4] [index1 % 4]) * (koeficijenti[index2 / 4] [index2 % 4]) * (koeficijenti[index3 / 4] [index3 % 4]);
    if (vrati >= 0) cout << " + " << vrati;
    else cout << " " << vrati;
    return vrati;
}

void prikaziTablicu(char tipTablice[]) {
    if (strcasecmp(tipTablice, "D") == 0) {
        cout << "\nD =";
        for(unsigned char i = 0; i < 3; i++) {
            cout << "\n |";
            for(unsigned char x = 0; x < 5; x++) {
                if (x < 3) cout << "\t" << koeficijenti[i][x];
                else if (x == 3) cout <<  "\t|" << koeficijenti[i][0];
                else if (x == 4) cout << "\t" << koeficijenti[i][1];

            }
        }
    }

    if (strcasecmp(tipTablice, "Dx") == 0) {
        cout << "\nDx =";
        for(unsigned char i = 0; i < 3; i++) {
            cout << "\n |";
            for(unsigned char x = 0; x < 5; x++) {
                if (x == 0) cout << "\t" << koeficijenti[i][3];
                else if (x < 3) cout << "\t" << koeficijenti[i][x];
                else if (x == 3) cout <<  "\t|" << koeficijenti[i][3];
                else if (x == 4) cout << "\t" << koeficijenti[i][1];
            }
        }
    }

    if (strcasecmp(tipTablice, "Dy") == 0) {
        cout << "\nDy =";
        for(unsigned char i = 0; i < 3; i++) {
            cout << "\n |";
            for(unsigned char x = 0; x < 5; x++) {
                if (x == 1) cout << "\t" << koeficijenti[i][3];
                else if (x < 3) cout << "\t" << koeficijenti[i][x];
                else if (x == 3) cout <<  "\t|" << koeficijenti[i][0];
                else if (x == 4) cout << "\t" << koeficijenti[i][3];
            }
        }
    }

    if (strcasecmp(tipTablice, "Dz") == 0) {
        cout << "\nDz =";
        for(unsigned char i = 0; i < 3; i++) {
            cout << "\n |";
            for(unsigned char x = 0; x < 5; x++) {
                if (x == 2) cout << "\t" << koeficijenti[i][3];
                else if (x < 3) cout << "\t" << koeficijenti[i][x];
                else if (x == 3) cout <<  "\t|" << koeficijenti[i][0];
                else if (x == 4) cout << "\t" << koeficijenti[i][1];
            }
        }
    }

}

void kalkulator() {
    for(unsigned char i = 0; i < 3; i++) {
        cout << "\nFormula izgleda ovako: a" << i+1 << "x + b" << i+1 << "y + c" << i+1 << "z = t" << i+1 << endl;
        cout << "Unesite a" << i+1 << ", b" << i+1 << ", c" << i+1 << " i t" << i+1 << " tako sto cete ih unositi jedan po jedan, a zatim stisnuti dugme enter.\n";
        cout << "Ukoliko u jednacini imate minus, upisite ga kada budete unosili, npr. -2 \n";
        for(unsigned char x = 0; x < 4; x++) {
            cin >> koeficijenti[i][x];
        }
    }

    int D = 0;

    prikaziTablicu("D");

    cout << "\nD =";
    D = saberiKoeficijente(0, 5, 10) + saberiKoeficijente(1, 6, 8) + saberiKoeficijente(2, 4, 9) - saberiKoeficijente(8, 5, 2) - saberiKoeficijente(9, 6, 0) - saberiKoeficijente(10, 4, 1);
    cout << " = " << D << endl;
    if (D != 0) {

        int Dx= 0;

        prikaziTablicu("Dx");

        cout << "\nDx =";
        Dx = saberiKoeficijente(3, 5, 10) + saberiKoeficijente(1, 6, 11) + saberiKoeficijente(2, 7, 9) - saberiKoeficijente(11, 5, 2) - saberiKoeficijente(9, 6, 3) - saberiKoeficijente(10, 7, 1);
        cout << " = " <<  Dx << endl;

        int Dy = 0;

        prikaziTablicu("Dy");

        cout << "\nDy =";
        Dy = saberiKoeficijente(0, 7, 10) + saberiKoeficijente(3, 6, 8) + saberiKoeficijente(2, 4, 11) - saberiKoeficijente(8, 7, 2) - saberiKoeficijente(11, 6, 0) - saberiKoeficijente(10, 4, 3);
        cout << " = " <<  Dy << endl;

        int Dz = 0;

        prikaziTablicu("Dz");

        cout << "\nDz =";
        Dz = saberiKoeficijente(0, 5, 11) + saberiKoeficijente(1, 7, 8) + saberiKoeficijente(3, 4, 9) - saberiKoeficijente(8, 5, 3) - saberiKoeficijente(9, 7, 0) - saberiKoeficijente(11, 4, 1);
        cout << " = " <<  Dz << endl;

        int x, y, z;
        x = Dx / D;
        y = Dy / D;
        z = Dz / D;

        if( (koeficijenti[0][0] * x) + (koeficijenti[0][1] * y) + (koeficijenti[0][2] * z) == koeficijenti[0][3]){
        //if (Dx == 0 || Dy == 0 || Dz == 0){
            cout << "\nx = " << Dx << " / " << D << " = " << x << endl;
            cout << "\ny = " << Dy << " / " << D << "= " << y << endl;
            cout << "\nz = " << Dz << " / " << D << " = " << z << endl;
        }
        else cout << "\nOva linearna jednacina nema resenja jer nije tacna!";
    }

    else cout << "\nOva linearna jednacina ima beskonacno resenja!";

}

bool ponovi(){
    char ponavljanjeUnos[] = "da";
    bool vrati = false;
    cout << "\nDa li zelite ponovo da izracunate? Ako zelite napisite DA (case je nebitan): ";
    cin >> ponavljanjeUnos;
    if (strcasecmp(ponavljanjeUnos, "DA") == 0) vrati = true;
    else vrati = false;
    return vrati;
}

int main()
{   cout << "Dobro dosli u kalkulator za rizracunavanje 3 jednacine sa 3 nepoznate!\n";
    do {
        kalkulator();
    }
    while(ponovi() == true);

}
