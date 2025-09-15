#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void geraArquivo(string path, string data) {
    fstream fs;
    fs.open(path.c_str(), fstream::out);
    if (fs.is_open()) {
        fs.write(data.c_str(), data.size());
        fs.close();
    } else
        cout << "Nao foi possivel abrir o arquivo " << path;
}

void geraArquivos() {
    string data1 = "1\nJoao Pedro\n(83) 8888-8888\n"
                  "2\nMaria Teresa\n(83) 9999-9999\n000.000.000-00\n"
                  "2\nLuiz Pereira\n(83) 7777-7777\n111.111.111-11\n"
                  "1\nDenis Carlos\n(83) 5555-5555\n";
    string data2 = "2\nLuma Oliveira\n(83) 1111-1111\n222.222.222-22\n"
                  "2\nTercio Marquies\n(83) 2222-2222\n333.333.222-33\n"
                  "1\nJonas Luz\n(83) 3333-3333\n";
    geraArquivo("dados01.txt", data1);
    geraArquivo("dados02.txt", data2);
}

class Pessoa {
private:
    int tipo;
    string nome;
    string telefone;
    string cpf;

public:
    Pessoa(int tipo, string nome, string telefone, string cpf = "")
        : tipo(tipo), nome(nome), telefone(telefone), cpf(cpf) {}

    void exibir() {
        if (tipo == 1) {
            cout << nome << ", tel: " << telefone << endl;
        } else if (tipo == 2) {
            cout << nome << ", tel: " << telefone << ", CPF: " << cpf << endl;
        }
    }
};

int main() {
    geraArquivos(); // cria os arquivos de teste

    string nomeArquivo;
    getline(cin, nomeArquivo);

    ifstream file(nomeArquivo);
    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo " << nomeArquivo << endl;
        return 1;
    }

    vector<Pessoa> pessoas;
    while (!file.eof()) {
        int tipo;
        string nome, telefone, cpf;

        if (!(file >> tipo)) break;
        file.ignore(); // descarta \n

        getline(file, nome);
        getline(file, telefone);
        if (tipo == 2) {
            getline(file, cpf);
            pessoas.push_back(Pessoa(tipo, nome, telefone, cpf));
        } else {
            pessoas.push_back(Pessoa(tipo, nome, telefone));
        }
    }

    file.close();

    for (auto &p : pessoas) {
        p.exibir();
    }

    return 0;
}
