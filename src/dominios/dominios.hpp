#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

/**
 * @file dominios.hpp
 * @brief Declaração das classes de domínio responsáveis por validação de dados.
 *
 * Cada domínio encapsula regras específicas e lança exceção (invalid_argument)
 * quando valores inválidos são atribuídos via setValor().
 */

#include <string>

using namespace std;

/**
 * @class Nome
 * @brief Domínio que representa um nome próprio entre 5 e 20 caracteres,
 *        com capitalização correta e sem espaços duplicados ou nas extremidades.
 */
class Nome {
private:
  string valor;
  void validar(const string &valor) const;
public:
  /** Define o valor validando-o. */
  void setValor(const string &valor);
  /** Retorna o valor atual do nome. */
  string getValor() const;
};

/**
 * @class Capacidade
 * @brief Domínio que representa capacidade numérica (1 a 4).
 */
class Capacidade {
private:
  int valor;
  void validar(int valor) const;
public:
  /** Define capacidade (1..4). */
  void setValor(int valor);
  /** Retorna a capacidade. */
  int getValor() const;
};

/**
 * @class Cartao
 * @brief Domínio que representa número de cartão com 16 dígitos validado por Luhn.
 */
class Cartao {
private:
  string valor;
  void validar(const string &valor) const;
public:
  /** Define número do cartão (16 dígitos + Luhn). */
  void setValor(const string &valor);
  /** Retorna número do cartão. */
  string getValor() const;
};

/**
 * @class Codigo
 * @brief Domínio de código com exatamente 10 caracteres (a-z ou dígito).
 */
class Codigo {
private:
  string valor;
  void validar(const string &valor) const;
public:
  /** Define código (10 chars alfanuméricos minúsculos). */
  void setValor(const string &valor);
  /** Retorna o código. */
  string getValor() const;
};

/**
 * @class Data
 * @brief Domínio de data no formato D[DD]-MMM-YYYY com meses PT-BR e ano 2000-2999.
 */
class Data {
private:
  string valor;
  void validar(const string &valor) const;
public:
  /** Define a data validando formato e consistência (inclui bissexto). */
  void setValor(const string &valor);
  /** Retorna a data original fornecida. */
  string getValor() const;
};

/**
 * @class Dinheiro
 * @brief Domínio monetário armazenado em centavos (1 a 100000000).
 */
class Dinheiro {
private:
  int valor;
  void validar(int valor) const;
public:
  /** Define o valor em centavos. */
  void setValor(int valor);
  /** Retorna o valor em centavos. */
  int getValor() const;
};

/**
 * @class Email
 * @brief Domínio que valida parte local e domínio conforme regras especificadas.
 */
class Email {
private:
  string valor;
  void validar(const string &valor) const;
public:
  /** Define email validando formato parte-local@dominio. */
  void setValor(const string &valor);
  /** Retorna o email. */
  string getValor() const;
};

/**
 * @class Endereco
 * @brief Domínio que valida endereço textual (5-30 chars) com regras de pontuação.
 */
class Endereco {
private:
  string valor;
  void validar(const string &valor) const;
public:
  /** Define o endereço. */
  void setValor(const string &valor);
  /** Retorna o endereço. */
  string getValor() const;
};

/**
 * @class Numero
 * @brief Domínio numérico (1..999).
 */
class Numero {
private:
  int valor;
  void validar(int valor) const;
public:
  /** Define número (1..999). */
  void setValor(int valor);
  /** Retorna número. */
  int getValor() const;
};

/**
 * @class Ramal
 * @brief Domínio que representa ramal (0..50).
 */
class Ramal {
private:
  int valor;
  void validar(int valor) const;
public:
  /** Define ramal (0..50). */
  void setValor(int valor);
  /** Retorna ramal. */
  int getValor() const;
};

/**
 * @class Senha
 * @brief Domínio de senha de 5 caracteres com restrições de sequência e composição.
 */
class Senha {
private:
  string valor;
  void validar(const string &valor) const;
public:
  /** Define a senha validando regras de composição. */
  void setValor(const string &valor);
  /** Retorna a senha. */
  string getValor() const;
};

/**
 * @class Telefone
 * @brief Domínio de telefone no formato +DDDDDDDDDDDDDD (14 dígitos após '+').
 */
class Telefone {
private:
  string valor;
  void validar(const string &valor) const;
public:
  /** Define telefone validando formato. */
  void setValor(const string &valor);
  /** Retorna telefone. */
  string getValor() const;
};

#endif
