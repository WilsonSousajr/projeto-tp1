#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Classe Pessoa
class Pessoa {
private:
    string nome;
    string email;

public:
    Pessoa(const string& nome, const string& email) {
        if (nome.empty()) throw invalid_argument("Nome nao pode ser vazio.");
        if (email.find('@') == string::npos) throw invalid_argument("Email invalido.");
        this->nome = nome;
        this->email = email;
    }

    string getNome() const { return nome; }
    string getEmail() const { return email; }

    void setNome(const string& nome) {
        if (nome.empty()) throw invalid_argument("Nome nao pode ser vazio.");
        this->nome = nome;
    }

    void setEmail(const string& email) {
        if (email.find('@') == string::npos) throw invalid_argument("Email invalido.");
        this->email = email;
    }
};

// Classe Hospede
class Hospede : public Pessoa {
private:
    string endereco;
    string cartao;

public:
    Hospede(const string& nome, const string& email, const string& cartao)
        : Pessoa(nome, email) {
        setCartao(cartao);
    }

    string getEndereco() const { return endereco; }
    string getCartao() const { return cartao; }

    void setEndereco(const string& endereco) {
        if (endereco.empty()) throw invalid_argument("Endereco nao pode ser vazio.");
        this->endereco = endereco;
    }

    void setCartao(const string& cartao) {
        if (cartao.size() != 16) throw invalid_argument("Cartao deve ter 16 digitos.");
        this->cartao = cartao;
    }
};

// Classe Hotel
class Hotel {
private:
    string nome;
    string cidade;

public:
    Hotel(const string& nome, const string& cidade) {
        setNome(nome);
        setCidade(cidade);
    }

    string getNome() const { return nome; }
    string getCidade() const { return cidade; }

    void setNome(const string& nome) {
        if (nome.empty()) throw invalid_argument("Nome do hotel nao pode ser vazio.");
        this->nome = nome;
    }

    void setCidade(const string& cidade) {
        if (cidade.empty()) throw invalid_argument("Cidade nao pode ser vazia.");
        this->cidade = cidade;
    }
};

// Classe Quarto
class Quarto {
private:
    int numero;
    int capacidade;
    double diaria;

public:
    Quarto(int numero, int capacidade, double diaria) {
        setNumero(numero);
        setCapacidade(capacidade);
        setDiaria(diaria);
    }

    int getNumero() const { return numero; }
    int getCapacidade() const { return capacidade; }
    double getDiaria() const { return diaria; }

    void setNumero(int numero) {
        if (numero <= 0) throw invalid_argument("Numero de quarto invalido.");
        this->numero = numero;
    }

    void setCapacidade(int capacidade) {
        if (capacidade < 1 || capacidade > 4)
            throw invalid_argument("Capacidade deve ser entre 1 e 4.");
        this->capacidade = capacidade;
    }

    void setDiaria(double diaria) {
        if (diaria <= 0) throw invalid_argument("Valor da diaria invalido.");
        this->diaria = diaria;
    }
};

// Classe Reserva
class Reserva {
private:
    Hospede hospede;
    Quarto quarto;
    int dias;

public:
    Reserva(const Hospede& hospede, const Quarto& quarto, int dias)
        : hospede(hospede), quarto(quarto) {
        setDias(dias);
    }

    Hospede getHospede() const { return hospede; }
    Quarto getQuarto() const { return quarto; }
    int getDias() const { return dias; }

    void setDias(int dias) {
        if (dias <= 0) throw invalid_argument("Quantidade de dias invalida.");
        this->dias = dias;
    }

    double calcularTotal() const {
        return dias * quarto.getDiaria();
    }
};

// Função principal
int main() {
    try {
        Hospede hospede("Cassio", "cassio@email.com", "1234567890123456");
        hospede.setEndereco("Rua das Flores, 123");

        Hotel hotel("Hotel Bom Sono", "Brasilia");

        Quarto quarto(101, 2, 150.0);

        Reserva reserva(hospede, quarto, 3);

        cout << "Hospede: " << hospede.getNome() << endl;
        cout << "Hotel: " << hotel.getNome() << " - " << hotel.getCidade() << endl;
        cout << "Quarto: " << quarto.getNumero() << " (Capacidade: "
             << quarto.getCapacidade() << ")" << endl;
        cout << "Dias: " << reserva.getDias() << endl;
        cout << "Total: R$ " << reserva.calcularTotal() << endl;

    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}
