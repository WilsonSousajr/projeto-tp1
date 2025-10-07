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

  if (isspace(nome.front()) || isspace(nome.back())) {
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
  if (valor < 1 || valor > 4) {
    throw invalid_argument("Capacidade deve ser 1, 2, 3 ou 4.");
  }
};

void Capacidade::setValor(int valor) {
  validar(valor);
  this->valor = valor;
};

int Capacidade::getValor() const { return this->valor; };

// ---------------------- Cartao

void Cartao::validar(const string &numero) const {
  if (numero.size() != 16) {
    throw invalid_argument("Cartao deve conter 16 digitos.");
  }
  if (!all_of(numero.begin(), numero.end(), ::isdigit)) {
    throw invalid_argument("Cartao deve conter apenas digitos.");
  }
  // Algoritmo de Luhn
  int soma = 0;
  bool duplica = false;
  for (int i = (int)numero.size() - 1; i >= 0; --i) {
    int d = numero[i] - '0';
    if (duplica) {
      d *= 2;
      if (d > 9)
        d -= 9;
    }
    soma += d;
    duplica = !duplica;
  }
  if (soma % 10 != 0) {
    throw invalid_argument("Cartao invalido (Luhn falhou).");
  }
};

void Cartao::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
};

string Cartao::getValor() const { return this->valor; };

// ---------------------- Codigo

void Codigo::validar(const string &valor) const {
  if (valor.size() != 10) {
    throw invalid_argument("Codigo deve ter 10 caracteres.");
  }
  for (char c : valor) {
    if (!(islower(c) || isdigit(c))) {
      throw invalid_argument(
          "Codigo deve conter apenas letras minusculas ou digitos.");
    }
  }
};

void Codigo::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
};

string Codigo::getValor() const { return this->valor; };

// ---------------------- Data

void Data::validar(const string &valor) const {
  // Formato esperado: D-MMM-YYYY ou DD-MMM-YYYY
  size_t firstDash = valor.find('-');
  size_t secondDash =
      valor.find('-', firstDash == string::npos ? 0 : firstDash + 1);
  if (firstDash == string::npos || secondDash == string::npos ||
      secondDash == valor.size() - 1) {
    throw invalid_argument("Data formato invalido. Use DD-MMM-YYYY.");
  }
  string diaStr = valor.substr(0, firstDash);
  string mesStr = valor.substr(firstDash + 1, secondDash - firstDash - 1);
  string anoStr = valor.substr(secondDash + 1);

  if (diaStr.empty() || mesStr.size() != 3 || anoStr.size() != 4) {
    throw invalid_argument("Data formato invalido.");
  }
  // Dia
  if (!all_of(diaStr.begin(), diaStr.end(), ::isdigit)) {
    throw invalid_argument("Dia invalido.");
  }
  int dia = stoi(diaStr);
  if (dia < 1 || dia > 31) {
    throw invalid_argument("Dia fora do intervalo 1-31.");
  }
  // Mes
  static const string mesesValidos[] = {"JAN", "FEV", "MAR", "ABR",
                                        "MAI", "JUN", "JUL", "AGO",
                                        "SET", "OUT", "NOV", "DEZ"};
  bool mesOk = false;
  int mesNumero = -1;
  for (int i = 0; i < 12; ++i) {
    if (mesStr == mesesValidos[i]) {
      mesOk = true;
      mesNumero = i + 1;
      break;
    }
  }
  if (!mesOk) {
    throw invalid_argument("Mes invalido.");
  }
  // Ano
  if (!all_of(anoStr.begin(), anoStr.end(), ::isdigit)) {
    throw invalid_argument("Ano invalido.");
  }
  int ano = stoi(anoStr);
  if (ano < 2000 || ano > 2999) {
    throw invalid_argument("Ano deve estar entre 2000 e 2999.");
  }
  auto isLeap = [&](int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
  };
  int diasNoMes;
  switch (mesNumero) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    diasNoMes = 31;
    break;
  case 4:
  case 6:
  case 9:
  case 11:
    diasNoMes = 30;
    break;
  case 2:
    diasNoMes = isLeap(ano) ? 29 : 28;
    break;
  default:
    diasNoMes = 31;
  }
  if (dia > diasNoMes) {
    throw invalid_argument("Dia invalido para o mes/ano informado.");
  }
};

void Data::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
};

string Data::getValor() const { return this->valor; };

// ---------------------- Dinheiro

void Dinheiro::validar(int valor) const {
  // Valor em centavos: intervalo 1 (0,01) a 100000000 (1.000.000,00)
  if (valor < 1 || valor > 100000000) {
    throw invalid_argument("Dinheiro deve estar entre 0,01 e 1.000.000,00.");
  }
};

void Dinheiro::setValor(int valor) {
  validar(valor);
  this->valor = valor;
};

int Dinheiro::getValor() const { return this->valor; }

// ---------------------- Email

void Email::validar(const string &valor) const {
  // Split local@dominio
  size_t at = valor.find('@');
  if (at == string::npos || at == 0 || at == valor.size() - 1) {
    throw invalid_argument("Email deve conter parte-local@dominio.");
  }
  string local = valor.substr(0, at);
  string dominio = valor.substr(at + 1);

  if (local.size() > 64) {
    throw invalid_argument("Parte local excede 64 caracteres.");
  }
  if (dominio.size() > 255) {
    throw invalid_argument("Dominio excede 255 caracteres.");
  }

  auto ehLetra = [](char c) { return c >= 'a' && c <= 'z'; };
  auto ehDigito = [](char c) { return isdigit(static_cast<unsigned char>(c)); };

  // Validar local
  if (local.front() == '.' || local.front() == '-' || local.back() == '.' ||
      local.back() == '-') {
    throw invalid_argument(
        "Parte local nao pode iniciar ou terminar com ponto ou hifen.");
  }
  for (size_t i = 0; i < local.size(); ++i) {
    char c = local[i];
    if (!(ehLetra(c) || ehDigito(c) || c == '.' || c == '-')) {
      throw invalid_argument("Parte local contem caracter invalido.");
    }
    if ((c == '.' || c == '-')) {
      if (i + 1 >= local.size() ||
          !(ehLetra(local[i + 1]) || ehDigito(local[i + 1]))) {
        throw invalid_argument(
            "Ponto ou hifen deve ser seguido de letra(s) ou digito(s).");
      }
    }
  }

  // Validar dominio
  size_t start = 0;
  bool temParte = false;
  while (start < dominio.size()) {
    size_t ponto = dominio.find('.', start);
    size_t end = (ponto == string::npos) ? dominio.size() : ponto;
    if (end == start) {
      throw invalid_argument("Dominio possui parte vazia.");
    }
    string parte = dominio.substr(start, end - start);
    if (parte.front() == '-' || parte.back() == '-') {
      throw invalid_argument(
          "Parte do dominio nao pode comecar ou terminar com hifen.");
    }
    for (char c : parte) {
      if (!(ehLetra(c) || ehDigito(c) || c == '-')) {
        throw invalid_argument("Dominio contem caracter invalido.");
      }
    }
    temParte = true;
    if (ponto == string::npos)
      break;
    start = ponto + 1;
  }
  if (!temParte) {
    throw invalid_argument("Dominio invalido.");
  }
};

void Email::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
};

string Email::getValor() const { return this->valor; }

// ---------------------- Endereco

void Endereco::validar(const string &valor) const {
  if (valor.size() < 5 || valor.size() > 30) {
    throw invalid_argument("Endereco deve ter entre 5 e 30 caracteres.");
  }
  auto ehLetra = [](char c) { return isalpha(static_cast<unsigned char>(c)); };
  auto ehDigito = [](char c) { return isdigit(static_cast<unsigned char>(c)); };

  char primeiro = valor.front();
  char ultimo = valor.back();
  if (primeiro == ',' || primeiro == '.' ||
      isspace(static_cast<unsigned char>(primeiro)) || ultimo == ',' ||
      ultimo == '.' || isspace(static_cast<unsigned char>(ultimo))) {
    throw invalid_argument(
        "Endereco nao pode comecar ou terminar com virgula, ponto ou espaco.");
  }

  for (size_t i = 0; i < valor.size(); ++i) {
    char c = valor[i];
    if (!(ehLetra(c) || ehDigito(c) || c == ',' || c == '.' ||
          isspace(static_cast<unsigned char>(c)))) {
      throw invalid_argument("Endereco contem caracter invalido.");
    }
    if (c == ',') {
      if (i + 1 >= valor.size()) {
        throw invalid_argument("Virgula final invalida.");
      }
      char prox = valor[i + 1];
      if (prox == ',' || prox == '.') {
        throw invalid_argument(
            "Virgula nao pode ser seguida de virgula ou ponto.");
      }
    } else if (c == '.') {
      if (i + 1 >= valor.size()) {
        throw invalid_argument("Ponto final invalido.");
      }
      char prox = valor[i + 1];
      if (prox == ',' || prox == '.') {
        throw invalid_argument(
            "Ponto nao pode ser seguido de virgula ou ponto.");
      }
    } else if (isspace(static_cast<unsigned char>(c))) {
      if (i + 1 >= valor.size()) {
        throw invalid_argument("Espaco final invalido.");
      }
      char prox = valor[i + 1];
      if (!(ehLetra(prox) || ehDigito(prox))) {
        throw invalid_argument("Espaco deve ser seguido de letra ou digito.");
      }
    }
  }
};

void Endereco::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
}

string Endereco::getValor() const { return this->valor; }

// ---------------------- Numero

void Numero::validar(int valor) const {
  if (valor < 1 || valor > 999) {
    throw invalid_argument("Numero deve estar entre 001 e 999.");
  }
};

void Numero::setValor(int valor) {
  validar(valor);
  this->valor = valor;
};

int Numero::getValor() const { return this->valor; }

// ---------------------- Ramal

void Ramal::validar(int valor) const {
  if (valor < 0 || valor > 50) {
    throw invalid_argument("Ramal deve estar entre 00 e 50.");
  }
}

void Ramal::setValor(int valor) {
  validar(valor);
  this->valor = valor;
};

int Ramal::getValor() const { return this->valor; }

// ---------------------- Senha

void Senha::validar(const string &valor) const {
  if (valor.size() != 5) {
    throw invalid_argument("Senha deve ter 5 caracteres.");
  }
  auto ehMinuscula = [](char c) { return c >= 'a' && c <= 'z'; };
  auto ehMaiuscula = [](char c) { return c >= 'A' && c <= 'Z'; };
  auto ehDigito = [](char c) { return isdigit(static_cast<unsigned char>(c)); };
  auto ehEspecial = [](char c) {
    switch (c) {
    case '!':
    case '"':
    case '#':
    case '$':
    case '%':
    case '&':
    case '?':
      return true;
    default:
      return false;
    }
  };
  bool temMin = false, temMai = false, temDig = false, temEsp = false;
  for (size_t i = 0; i < valor.size(); ++i) {
    char c = valor[i];
    if (!(ehMinuscula(c) || ehMaiuscula(c) || ehDigito(c) || ehEspecial(c))) {
      throw invalid_argument("Senha contem caracter invalido.");
    }
    if (i > 0) {
      char p = valor[i - 1];
      if ((ehMinuscula(p) || ehMaiuscula(p)) &&
          (ehMinuscula(c) || ehMaiuscula(c))) {
        throw invalid_argument("Letra nao pode ser seguida de letra.");
      }
      if (ehDigito(p) && ehDigito(c)) {
        throw invalid_argument("Digito nao pode ser seguido de digito.");
      }
    }
    if (ehMinuscula(c))
      temMin = true;
    if (ehMaiuscula(c))
      temMai = true;
    if (ehDigito(c))
      temDig = true;
    if (ehEspecial(c))
      temEsp = true;
  }
  if (!(temMin && temMai && temDig && temEsp)) {
    throw invalid_argument(
        "Senha deve conter minuscula, maiuscula, digito e especial.");
  }
};

void Senha::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
}

string Senha::getValor() const { return this->valor; }
// ---------------------- Telefone

void Telefone::validar(const string &valor) const {
  // Formato: + seguido de 14 digitos (total 15 caracteres).
  if (valor.size() != 15) {
    throw invalid_argument("Telefone deve ter 15 caracteres (+ e 14 digitos).");
  }
  if (valor.front() != '+') {
    throw invalid_argument("Telefone deve iniciar com '+'.");
  }
  for (size_t i = 1; i < valor.size(); ++i) {
    if (!isdigit(static_cast<unsigned char>(valor[i]))) {
      throw invalid_argument("Telefone deve conter apenas digitos apos '+'.");
    }
  }
};

void Telefone::setValor(const string &valor) {
  validar(valor);
  this->valor = valor;
};

string Telefone::getValor() const { return this->valor; }
