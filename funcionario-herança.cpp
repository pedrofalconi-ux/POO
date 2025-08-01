#include <iostream>
#include <string>

using namespace std;

class Funcionario {
protected:
    int matricula;
    string nome;
    float salario;

public:
    Funcionario() {
        this->matricula = 0;
        this->salario = 0.0;
    }

    void setNome(const string& n) {
        nome = n;
    }

    void setMatricula(int y) {
        if(y > 0){
            matricula = y;
        }
        else{
            cout << "Matrícula Inválida" << endl;
        }
    }
    void setSalario(float x) {
        if(x > 0){
           salario = x; 
        }
        else{
            cout << "Salário Inválido" << endl;
        }
    }
    virtual float getSalario(){
        return this->salario;
    }
    int getMatricula(){
        return this->matricula;
    }

   string getNome() {
        return nome;
    }
};

class Consultor : public Funcionario
{
public:
    float getSalario() override { //override, para sobrescrever a funcao getsalario da classe funcionario, e acrescentar 10%
        return this->salario * 1.10;
    }

    void exibir(){

        cout << getMatricula() << " - " << nome << " - R$ " << getSalario() << endl;

    }
};
    int main(){
        Funcionario f;
        Consultor c;

        int y;
        cin >> y;
        f.setMatricula(y);
        cin.ignore();
                
        string nome;
        getline(cin, nome);
        f.setNome(nome);

        int x;
        cin >> x;
        f.setSalario(x);
        cin.ignore();



        cin >> y;
        c.setMatricula(y);
        cin.ignore();

        getline(cin, nome);
        c.setNome(nome);

        cin >> x;
        c.setSalario(x);
        cin.ignore();




        cout << f.getMatricula() << " - " << f.getNome() << " - R$ " << f.getSalario() << endl;
        cout << c.getMatricula() << " - " << c.getNome() << " - R$ " << c.getSalario() << endl;

        return 0;
    }