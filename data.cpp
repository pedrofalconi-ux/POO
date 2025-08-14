#include <iostream>

struct Data {
    int dia;
    int mes;
    int ano;
};

int comparaDatas(Data d1, Data d2) {
    if (d1.ano < d2.ano) {
        return 1;
    } else if (d1.ano > d2.ano) {
        return -1;
    } else {
        if (d1.mes < d2.mes) {
            return 1;
        } else if (d1.mes > d2.mes) {
            return -1;
        } else {
            if (d1.dia < d2.dia) {
                return 1;
            } else if (d1.dia > d2.dia) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

int main() {
    Data dataPessoa1, dataPessoa2;

    std::cin >> dataPessoa1.dia;
    std::cin >> dataPessoa1.mes;
    std::cin >> dataPessoa1.ano;

    std::cin >> dataPessoa2.dia;
    std::cin >> dataPessoa2.mes;
    std::cin >> dataPessoa2.ano;

    int resultadoComparacao = comparaDatas(dataPessoa1, dataPessoa2);

    if (resultadoComparacao == 1) {
        std::cout << "Pessoa 1 é mais velha" << std::endl;
    } else if (resultadoComparacao == -1) {
        std::cout << "Pessoa 2 é mais velha" << std::endl;
    } else {
        std::cout << "Pessoas são da mesma idade" << std::endl;
    }

    return 0;
}