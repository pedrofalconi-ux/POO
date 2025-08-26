#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Classe base
class Trabalhador {
protected:
    string nome;
    float salario;
public:
    Trabalhador(string n) : nome(n), salario(0) {} // Construtor inicia salário com 0

    void setNome(string n) { nome = n; }
    string getNome() { return nome; }

    void setSalario(float s) { salario = s; }
    float getSalario() { return salario; }

    virtual float calcularPagamentoSemanal() = 0; // Método virtual puro
};

// Trabalhador assalariado
class TrabalhadorAssalariado : public Trabalhador {
public:
    TrabalhadorAssalariado(string n, float s) : Trabalhador(n) {
        salario = s;
    }

    float calcularPagamentoSemanal() override {
        return salario / 4.0; // Semanal = salário mensal / 4
    }
};

// Trabalhador por hora
class TrabalhadorPorHora : public Trabalhador {
private:
    float valorDaHora;
    int horasSemanais;
public:
    TrabalhadorPorHora(string n, float v, int h) : Trabalhador(n), valorDaHora(v), horasSemanais(h) {}

    float calcularPagamentoSemanal() override {
        float pagamento = 0;
        if (horasSemanais <= 40) {
            pagamento = horasSemanais * valorDaHora;
        } else {
            int horasExtra = horasSemanais - 40;
            pagamento = 40 * valorDaHora + horasExtra * valorDaHora * 1.5;
        }
        salario = pagamento * 4; // Atualiza salário mensal estimado
        return pagamento;
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Limpar buffer após o número de trabalhadores
    vector<Trabalhador*> trabalhadores;

    for (int i = 0; i < N; i++) {
        int tipo;
        cin >> tipo;
        cin.ignore(); // Limpar buffer após o tipo

        if (tipo == 1) { // Assalariado
            string nome;
            float salario;
            getline(cin, nome);
            cin >> salario;
            cin.ignore(); // Limpar buffer
            trabalhadores.push_back(new TrabalhadorAssalariado(nome, salario));
        } else if (tipo == 2) { // Por hora
            string nome;
            float valorHora;
            int horasSemanais;
            getline(cin, nome);
            cin >> valorHora >> horasSemanais;
            cin.ignore(); // Limpar buffer
            trabalhadores.push_back(new TrabalhadorPorHora(nome, valorHora, horasSemanais));
        }
    }

    // Exibir resultados
    cout << fixed << setprecision(0);
    for (Trabalhador* t : trabalhadores) {
        float semanal = t->calcularPagamentoSemanal();
        cout << t->getNome() << " - Semanal: R$ " << semanal
             << " - Mensal: R$ " << t->getSalario() << endl;
    }
