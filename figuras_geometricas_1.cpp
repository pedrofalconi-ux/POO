#include <iostream>
#include <string>
using namespace std;

class FigurasGeometricas {
public:
    FigurasGeometricas(string t) : tipo(t) {}
    virtual void lerAtributosArea() = 0;
    virtual float calcular_area() = 0;
    string getNome() { return tipo; }
protected:
    string tipo;
};

class Quadrado : public FigurasGeometricas {
public:
    Quadrado() : FigurasGeometricas("Quadrado"), l(0) {}
    void lerAtributosArea() override {
        cin >> l;
    }
    float calcular_area() override {
        return l * l;
    }
private:
    float l;
};

class Retangulo : public FigurasGeometricas {
public:
    Retangulo() : FigurasGeometricas("Retangulo"), b(0), h(0) {}
    void lerAtributosArea() override {
        cin >> b >> h;
    }
    float calcular_area() override {
        return b * h;
    }
private:
    float b, h;
};

class Triangulo : public FigurasGeometricas {
public:
    Triangulo() : FigurasGeometricas("Triangulo"), b(0), h(0) {}
    void lerAtributosArea() override {
        cin >> b >> h;
    }
    float calcular_area() override {
        return (b * h) / 2;
    }
private:
    float b, h;
};

class Circulo : public FigurasGeometricas {
public:
    Circulo() : FigurasGeometricas("Circulo"), r(0) {}
    void lerAtributosArea() override {
        cin >> r;
    }
    float calcular_area() override {
        return 3.14f * r * r;
    }
private:
    float r;
};

int main() {
    int N = 0;
    cin >> N;
    FigurasGeometricas* figuras[N];
    for (int i = 0; i < N; i++) {
        int tipo;
        cin >> tipo;
        switch (tipo) {
            case 1:
                figuras[i] = new Quadrado();
                break;
            case 2:
                figuras[i] = new Retangulo();
                break;
            case 3:
                figuras[i] = new Triangulo();
                break;
            case 4:
                figuras[i] = new Circulo();
                break;
            default:
                cerr << "Tipo de figura invalido!" << endl;
                i--;
                continue;
        }
        figuras[i]->lerAtributosArea();
    }
    for (int i = 0; i < N; i++) {
        cout << figuras[i]->getNome() << " de area " << figuras[i]->calcular_area() << endl;
        delete figuras[i];
    }
    return 0;
}