#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>

using namespace std;

class Nome {
private:
  string valor;
  void validar(const string &valor) const;

public:
  void setValor(const string &valor);
  string getValor() const;
};

class Capacidade {
private:
  int valor;
  void validar(int valor) const;

public:
  void setValor(int valor);
  int getValor() const;
};

class Cartao {
private:
  string valor;
  void validar(const string &valor) const;

public:
  void setValor(const string &valor);
  string getValor() const;
};

class Codigo {
private:
  string valor;
  void validar(const string &valor) const;

public:
  void setValor(const string &valor);
  string getValor() const;
};

class Data {
private:
  string valor;
  void validar(const string &valor) const;

public:
  void setValor(const string &valor);
  string getValor() const;
};

class Dinheiro {
private:
  int valor;
  void validar(int valor) const;

public:
  void setValor(int valor);
  int getValor() const;
};

class Email {
private:
  string valor;
  void validar(const string &valor) const;

public:
  void setValor(const string &valor);
  string getValor() const;
};

class Endereco {
private:
  string valor;
  void validar(const string &valor) const;

public:
  void setValor(const string &valor);
  string getValor() const;
};

class Numero {
private:
  int valor;
  void validar(int valor) const;

public:
  void setValor(int valor);
  int getValor() const;
};

class Ramal {
private:
  int valor;
  void validar(int valor) const;

public:
  void setValor(int valor);
  int getValor() const;
};

class Senha {
private:
  string valor;
  void validar(const string &valor) const;

public:
  void setValor(const string &valor);
  string getValor() const;
};

class Telefone {
private:
  string valor;
  void validar(const string &valor) const;

public:
  void setValor(const string &valor);
  string getValor() const;
};

#endif
