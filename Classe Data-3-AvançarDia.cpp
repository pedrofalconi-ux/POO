#include <iostream>
#include <string>
#include <iomanip> // para std::setw e std::setfill
using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

    int getDiasMes(int m) {
        if (m == 2) return 28;
        else if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        else return 31;
    }

public:
    Data(int d, int m, int a) {
        bool invalido = false;

        if (m < 1 || m > 12) {
            cout << "Atributo mês Inválido" << endl;
            m = 1;
            invalido = true;
        }

        if (d < 1 || d > getDiasMes(m)) {
            cout << "Atributo dia Inválido" << endl;
            d = 1;
            invalido = true;
        }

        if (a < 1) {
            cout << "Atributo ano Inválido" << endl;
            a = 1;
            invalido = true;
        }

        dia = d;
        mes = m;
        ano = a;
    }

    string getDia() {
        return (dia < 10 ? "0" : "") + to_string(dia);
    }

    string getMes() {
        return (mes < 10 ? "0" : "") + to_string(mes);
    }

    string getAno() {
        return to_string(ano);
    }

    void setDia(int d) {
        if (d >= 1 && d <= getDiasMes(mes)) dia = d;
        else {
            cout << "Atributo dia Inválido" << endl;
            dia = 1;
        }
    }

    void setMes(int m) {
        if (m >= 1 && m <= 12) mes = m;
        else {
            cout << "Atributo mês Inválido" << endl;
            mes = 1;
        }
    }

    void setAno(int a) {
        if (a >= 1) ano = a;
        else {
            cout << "Atributo ano Inválido" << endl;
            ano = 1;
        }
    }

    void avancarDia() {
        dia++;
        if (dia > getDiasMes(mes)) {
            dia = 1;
            mes++;
            if (mes > 12) {
                mes = 1;
                ano++;
            }
        }
    }
};

int main() {
    int d, m, a, qtdDias;

    cin >> d >> m >> a;
    Data data(d, m, a);

    cin >> qtdDias;

    for (int i = 0; i < qtdDias; ++i) {
        data.avancarDia();
    }

    cout << data.getDia() << "/" << data.getMes() << "/" << data.getAno() << endl;

    return 0;
}

