#ifndef ENTIDADES_H
#define ENTIDADES_H

#include <string>
#include <stdexcept>

using namespace std;

// Constantes
const int CAPACIDADE_MIN = 1;
const int CAPACIDADE_MAX = 10;

// Classe Pessoa
class Pessoa {
protected:
    string nome;
    string email;
public:
    Pessoa(const string& nome, const string& email);

    string getNome() const;
    void setNome(const string& nome);

    string getEmail() const;
    void setEmail(const string& email);
};

// Classe Gerente (herda Pessoa)
class Gerente : public Pessoa {
private:
    string matricula;
public:
    Gerente(const string& nome, const string& email, const string& matricula);

    string getMatricula() const;
    void setMatricula(const string& matricula);
};

// Classe Hospede (herda Pessoa)

class Hospede : public Pessoa {
private:
    string cartaoCredito;
public:
    Hospede(const string& nome, const string& email, const string& cartaoCredito);

    string getCartaoCredito() const;
    void setCartaoCredito(const string& cartaoCredito);
};

// Classe Quarto

class Quarto {
private:
    int numero;
    int capacidade;
    double precoDiaria;
public:
    Quarto(int numero, int capacidade, double precoDiaria);

    int getNumero() const;
    void setNumero(int numero);

    int getCapacidade() const;
    void setCapacidade(int capacidade);

    double getPrecoDiaria() const;
    void setPrecoDiaria(double precoDiaria);
};

// Classe Hotel

class Hotel {
private:
    string nome;
    string cidade;
public:
    Hotel(const string& nome, const string& cidade);

    string getNome() const;
    void setNome(const string& nome);

    string getCidade() const;
    void setCidade(const string& cidade);
};

// Classe Reserva
class Reserva {
private:
    Hospede hospede;
    Quarto quarto;
    int dias;
public:
    Reserva(const Hospede& hospede, const Quarto& quarto, int dias);

    Hospede getHospede() const;
    Quarto getQuarto() const;
    int getDias() const;
    void setDias(int dias);
};

#endif
