#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Insumo {
protected:
    string nome;
    int tipoInsumo;

public:
    Insumo(string nome, int tipoInsumo = 0) : nome(nome), tipoInsumo(tipoInsumo) {}
    virtual ~Insumo() {
        cout << "Deletando Insumos" << endl;
    }
};

class Vacina : public Insumo {
private:
    string fabricante;
    string tipo;
    string dataValidade;

public:
    Vacina(string nome, string dataValidade, string fabricante, string tipo)
        : Insumo(nome, 1), fabricante(fabricante), tipo(tipo), dataValidade(dataValidade) {}

    ~Vacina() override {
        cout << "Deletando Vacina" << endl;
    }
};

class Medicamento : public Insumo {
private:
    string dosagem;
    string administracao;
    string disponibilidade;

public:
    Medicamento(string nome, string dosagem, string administracao, string disponibilidade)
        : Insumo(nome, 2), dosagem(dosagem), administracao(administracao), disponibilidade(disponibilidade) {}

    ~Medicamento() override {
        cout << "Deletando Medicamento" << endl;
    }
};

class EPI : public Insumo {
private:
    string descricao;
    string fabricante;
    string tipo;

public:
    EPI(string nome, string descricao, string fabricante, string tipo)
        : Insumo(nome, 3), descricao(descricao), fabricante(fabricante), tipo(tipo) {}

    ~EPI() override {
        cout << "Deletando EPI" << endl;
    }
};

class LocalController {
private:
    Insumo* insumosArr[3];
    vector<Insumo*> insumosVec;

public:
    LocalController() {
        for (int i = 0; i < 3; i++) insumosArr[i] = nullptr;
    }

    void addInsumoArr(Insumo* in, int index) {
        if (index >= 0 && index < 3) {
            insumosArr[index] = in;
        }
    }

    void addInsumoVec(Insumo* in) {
        insumosVec.push_back(in);
    }

    ~LocalController() {
        cout << "Deletando..." << endl;
        for (int i = 0; i < 3; i++) {
            if (insumosArr[i] != nullptr) {
                delete insumosArr[i];
                insumosArr[i] = nullptr;
            }
        }
        for (auto in : insumosVec) {
            delete in;
        }
        insumosVec.clear();
    }
};

int main() {
    string nome, fabricante, tipo, dataValidade, dosagem, administracao, disponibilidade, descricao;

    LocalController* local = new LocalController();

    getline(cin, nome);
    getline(cin, dataValidade);
    getline(cin, fabricante);
    getline(cin, tipo);
    Vacina* v1 = new Vacina(nome, dataValidade, fabricante, tipo);

    getline(cin, nome);
    getline(cin, dosagem);
    getline(cin, administracao);
    getline(cin, disponibilidade);
    Medicamento* m1 = new Medicamento(nome, dosagem, administracao, disponibilidade);

    getline(cin, nome);
    getline(cin, descricao);
    getline(cin, fabricante);
    getline(cin, tipo);
    EPI* e1 = new EPI(nome, descricao, fabricante, tipo);

    local->addInsumoArr(new Vacina("CoronaVac", "11/12/2021", "Sinovac", "Virus inativado"), 0);
    local->addInsumoArr(new Medicamento("Tylenol", "500", "1 comprimido", "capsulas"), 1);
    local->addInsumoArr(new EPI("Oculos de protecao", "Indeterminada", "3M", "Oculos"), 2);

    local->addInsumoVec(v1);
    local->addInsumoVec(m1);
    local->addInsumoVec(e1);

    delete local;

    return 0;
}
