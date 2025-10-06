#include "dominios.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <stdexcept>

// ---------------------- Nome

void Nome::validar(const string &nome) const {
  if (nome.length() < 5 || nome.length() > 20) {
    throw invalid_argument("Nome deve ter entre 5 e 20 caracteres. ");
  };

  if (isspace(nome.front() || isspace(nome.back()))) {
    throw invalid_argument("Nome não pode começar ou terminar com espaços");
  };

  bool esperandoMaiuscula = true;
  for (size_t i = 0; i < nome.length(); i++) {
    if (!isalpha(nome[i]) && !isspace(nome[i])) {
      throw invalid_argument("Nome deve conter apenas letras e espaços.");
    };
    if (i > 0 && isspace(nome[i - 1]) && isspace(nome[i])) {
      throw invalid_argument("Nome não pode conter espaços duplicados. ");
    }

    if (esperandoMaiuscula) {
      if (!isupper(nome[i])) {
        throw invalid_argument(
            "A primeira letra de cada termo deve ser maiúscula. ");
      }
      esperandoMaiuscula = false;
    } else {
      if (isupper(nome[i])) {
        throw invalid_argument(
            "Apenas a primeira letra de cada termo deve ser maiúscula. ");
      }
    }

    if (isspace(nome[i])) {
      esperandoMaiuscula = true;
    };
  };
}

void Nome::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
};

string Nome::getValor() const { return this->valor; };

// ---------------------- Capacidade

void Capacidade::validar(int valor) const {

};

void Capacidade::setValor(int valor) {
  validar(valor);
  this->valor = valor;
};

int Capacidade::getValor() const { return this->valor; };

// ---------------------- Cartao

void Cartao::validar(const string &numero) const {}

void Cartao::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
};

string Cartao::getValor() const { return this->valor; };

// ---------------------- Codigo

void Codigo::validar(const string &valor) const {

};

void Codigo::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
};

string Codigo::getValor() const { return this->valor; };

// ---------------------- Data

void Data::validar(const string &valor) const {

};

void Data::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
};

string Data::getValor() const { return this->valor; };

// ---------------------- Dinheiro

void Dinheiro::validar(int valor) const {

};

void Dinheiro::setValor(int valor) {
  validar(valor);
  this->valor = valor;
};

int Dinheiro::getValor() const { return this->valor; }

// ---------------------- Email

void Email::validar(const string &valor) const {

};

void Email::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
};

string Email::getValor() const { return this->valor; }

// ---------------------- Endereco

void Endereco::validar(const string &valor) const {

};

void Endereco::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
}

string Endereco::getValor() const { return this->valor; }

// ---------------------- Numero

void Numero::validar(int valor) const {

};

void Numero::setValor(int valor) {
  validar(valor);
  this->valor = valor;
};

int Numero::getValor() const { return this->valor; }

// ---------------------- Ramal

void Ramal::validar(int valor) const {}

void Ramal::setValor(int valor) {
  validar(valor);
  this->valor = valor;
};

int Ramal::getValor() const { return this->valor; }

// ---------------------- Senha

void Senha::validar(const string &valor) const {

};

void Senha::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
}

string Senha::getValor() const { return this->valor; }
// ---------------------- Telefone

void Telefone::validar(const string &valor) const {

};

void Telefone::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
};

string Telefone::getValor() const { return this->valor; }
