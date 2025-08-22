#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Classe base abstrata
class Imovel {
protected:
    double valor;
    int tipo;
    string disponibilidade;

public:
    // Construtor para a classe base
    Imovel(int tipo) : tipo(tipo) {}

    // Destrutor virtual para garantir a limpeza correta
    virtual ~Imovel() {}

    // Método para ler atributos comuns (valor e disponibilidade)
    void lerAtributosBase() {
        cin >> valor;
        cin >> ws; // Consome o caractere de nova linha
        getline(cin, disponibilidade);
    }

    // Métodos virtuais puros (abstratos)
    virtual void lerAtributos() = 0;
    virtual void exibeAtributos() = 0;

    // Método getNome() conforme a especificação
    string getNome() const {
        switch (tipo) {
            case 1: return "Casa";
            case 2: return "Apartamento";
            case 3: return "Terreno";
            default: return "Indefinido";
        }
    }
};

// Classe Terreno
class Terreno : public Imovel {
private:
    double area_terreno;

public:
    // Construtor que chama o construtor da super classe com o tipo correto
    Terreno() : Imovel(3) {}

    void lerAtributos() override {
        lerAtributosBase();
        cin >> area_terreno;
    }

    void exibeAtributos() override {
        cout << getNome() << " para " << disponibilidade << ", R$ " << fixed << setprecision(0) << valor << ". "
             << area_terreno << "m2 de área de terreno." << endl;
    }
};

// Classe Casa
class Casa : public Imovel {
private:
    int num_pavimentos;
    int num_quartos;
    double area_terreno;
    double area_construida;

public:
    // Construtor que chama o construtor da super classe com o tipo correto
    Casa() : Imovel(1) {}

    void lerAtributos() override {
        lerAtributosBase();
        cin >> num_pavimentos >> num_quartos >> area_terreno >> area_construida;
    }

    void exibeAtributos() override {
        cout << getNome() << " para " << disponibilidade << ", R$ " << fixed << setprecision(0) << valor << ". "
             << num_pavimentos << " pavimentos, " << num_quartos << " quartos, "
             << area_terreno << "m2 de área de terreno e " << area_construida << "m2 de área construída." << endl;
    }
};

// Classe Apartamento
class Apartamento : public Imovel {
private:
    double area;
    int num_quartos;
    int andar;
    double valor_condominio;
    int num_vagas;

public:
    // Construtor que chama o construtor da super classe com o tipo correto
    Apartamento() : Imovel(2) {}

    void lerAtributos() override {
        lerAtributosBase();
        cin >> area >> num_quartos >> andar >> valor_condominio >> num_vagas;
    }

    void exibeAtributos() override {
        cout << getNome() << " para " << disponibilidade << ", R$ " << fixed << setprecision(0) << valor << ". "
             << area << "m2 de área, " << num_quartos << " quartos, "
             << andar << " andar(es), " << fixed << setprecision(0) << valor_condominio << " de condomínio, "
             << num_vagas << " vaga(s) de garagem." << endl;
    }
};

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int tipo;
        cin >> tipo;

        Imovel* imovel = nullptr;
        
        switch (tipo) {
            case 1:
                imovel = new Casa();
                break;
            case 2:
                imovel = new Apartamento();
                break;
            case 3:
                imovel = new Terreno();
                break;
            default:
                break;
        }

        if (imovel) {
            imovel->lerAtributos();
            imovel->exibeAtributos();
            delete imovel;
        }
    }

    return 0;
}