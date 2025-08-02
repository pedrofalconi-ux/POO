#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Funcionario {
private:
    string primeiroNome;
    string sobrenome;
    float salarioMensal;

public:
    Funcionario(string pNome, string sNome, float salario) {
        primeiroNome = pNome;
        sobrenome = sNome;
        if (salario > 0)
            salarioMensal = salario;
        else
            salarioMensal = 0;
    }

    string getPrimeiroNome() { return primeiroNome; }
    string getSobrenome() { return sobrenome; }
    float getSalarioMensal() { return salarioMensal; }

    void setPrimeiroNome(string nome) { primeiroNome = nome; }
    void setSobrenome(string nome) { sobrenome = nome; }
    void setSalarioMensal(float salario) {
        if (salario > 0)
            salarioMensal = salario;
        else
            salarioMensal = 0;
    }
    float getSalarioAnual() {
        return salarioMensal * 12;
    }
    void aumentaSalario(float percent) {
        salarioMensal += salarioMensal * percent;
    }
};

int main() {
    int N;
    cin >> N;

    vector<Funcionario> funcionarios;

    for (int i = 0; i < N; ++i) {
        string primeiro, sobrenome;
        float salario;
        cin >> primeiro >> sobrenome >> salario;
        Funcionario f(primeiro, sobrenome, salario);
        funcionarios.push_back(f);
    }

    for (auto& f : funcionarios) {
        cout << f.getPrimeiroNome() << " " << f.getSobrenome()
             << " - " << f.getSalarioMensal()
             << " - " << f.getSalarioAnual() << endl;
        f.aumentaSalario(0.1);
        cout << f.getSalarioAnual() << endl;
    }

    return 0;
}
