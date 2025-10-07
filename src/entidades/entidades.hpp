#ifndef ENTIDADES_H
#define ENTIDADES_H

/**
 * @file entidades.hpp
 * @brief Declares entity classes that aggregate validated domain objects.
 *
 * Cada entidade é composta por atributos que são instâncias dos domínios
 * definidos em dominios.hpp, garantindo validação centralizada e consistente.
 */

#include "../dominios/dominios.hpp"
#include <stdexcept>
#include <string>

using namespace std;

/**
 * @class Pessoa
 * @brief Representa uma pessoa com nome e email válidos.
 *
 * Envolve os domínios Nome e Email para garantir as regras de validação
 * definidas para cada um deles.
 */
class Pessoa {
protected:
  Nome nome;   ///< Nome validado (domínio Nome).
  Email email; ///< Email validado (domínio Email).
public:
  /**
   * @brief Constrói uma Pessoa validando nome e email.
   * @param nome Valor textual para o nome (será validado pelo domínio Nome).
   * @param email Valor textual para o email (validado pelo domínio Email).
   * @throw invalid_argument se algum valor for inválido.
   */
  Pessoa(const string &nome, const string &email);

  /**
   * @brief Obtém o nome (string) da pessoa.
   * @return Nome em formato string.
   */
  string getNome() const;

  /**
   * @brief Define/atualiza o nome.
   * @param valor Nome a ser definido.
   * @throw invalid_argument se for inválido segundo o domínio Nome.
   */
  void setNome(const string &valor);

  /**
   * @brief Obtém o email (string) da pessoa.
   * @return Email em formato string.
   */
  string getEmail() const;

  /**
   * @brief Define/atualiza o email.
   * @param valor Email a ser definido.
   * @throw invalid_argument se inválido segundo o domínio Email.
   */
  void setEmail(const string &valor);
};

/**
 * @class Gerente
 * @brief Especialização de Pessoa com matrícula (código) válida.
 *
 * Usa o domínio Codigo para representar a matrícula.
 */
class Gerente : public Pessoa {
private:
  Codigo matricula; ///< Matrícula validada (domínio Codigo).
public:
  /**
   * @brief Constrói um Gerente validando nome, email e matrícula.
   */
  Gerente(const string &nome, const string &email, const string &matricula);

  /**
   * @brief Obtém a matrícula (string).
   */
  string getMatricula() const;

  /**
   * @brief Define/atualiza a matrícula.
   * @throw invalid_argument se inválida segundo domínio Codigo.
   */
  void setMatricula(const string &valor);
};

/**
 * @class Hospede
 * @brief Especialização de Pessoa com cartão de crédito válido.
 *
 * Usa o domínio Cartao (com validação Luhn).
 */
class Hospede : public Pessoa {
private:
  Cartao cartaoCredito; ///< Cartão de crédito validado.
public:
  /**
   * @brief Constrói um Hóspede validando nome, email e cartão.
   */
  Hospede(const string &nome, const string &email, const string &cartaoCredito);

  /**
   * @brief Obtém o número do cartão de crédito.
   */
  string getCartaoCredito() const;

  /**
   * @brief Define/atualiza o cartão de crédito.
   * @throw invalid_argument se inválido segundo domínio Cartao.
   */
  void setCartaoCredito(const string &valor);
};

/**
 * @class Quarto
 * @brief Representa um quarto de hotel.
 *
 * Atributos: número (Numero), capacidade (Capacidade) e preço da diária
 * (Dinheiro em centavos).
 */
class Quarto {
private:
  Numero numero;         ///< Número identificador do quarto.
  Capacidade capacidade; ///< Capacidade de hóspedes.
  Dinheiro precoDiaria;  ///< Preço da diária em centavos (domínio Dinheiro).
public:
  /**
   * @brief Constrói um Quarto validando atributos.
   * @param numero Valor 1..999.
   * @param capacidade Valor 1..4.
   * @param precoCentavos Valor em centavos (1 a 100000000).
   */
  Quarto(int numero, int capacidade, int precoCentavos);

  /**
   * @brief Obtém o número do quarto.
   */
  int getNumero() const;

  /**
   * @brief Define o número do quarto.
   * @throw invalid_argument se inválido segundo domínio Numero.
   */
  void setNumero(int valor);

  /**
   * @brief Obtém a capacidade do quarto.
   */
  int getCapacidade() const;

  /**
   * @brief Define a capacidade.
   * @throw invalid_argument se inválido segundo domínio Capacidade.
   */
  void setCapacidade(int valor);

  /**
   * @brief Obtém o preço da diária em centavos.
   */
  int getPrecoDiariaCentavos() const;

  /**
   * @brief Obtém o preço da diária em reais (double).
   */
  double getPrecoDiariaReais() const;

  /**
   * @brief Define o preço da diária (em centavos).
   * @throw invalid_argument se inválido segundo domínio Dinheiro.
   */
  void setPrecoDiaria(int centavos);
};

/**
 * @class Hotel
 * @brief Representa um hotel com nome e cidade válidos.
 *
 * Usa o domínio Nome tanto para o nome quanto para a cidade
 * (assumindo mesmas regras de capitalização).
 */
class Hotel {
private:
  Nome nome;   ///< Nome do hotel.
  Nome cidade; ///< Cidade onde está localizado.
public:
  /**
   * @brief Constrói um Hotel validando nome e cidade.
   */
  Hotel(const string &nome, const string &cidade);

  /**
   * @brief Obtém o nome do hotel.
   */
  string getNome() const;

  /**
   * @brief Define/atualiza o nome.
   */
  void setNome(const string &valor);

  /**
   * @brief Obtém a cidade do hotel.
   */
  string getCidade() const;

  /**
   * @brief Define/atualiza a cidade.
   */
  void setCidade(const string &valor);
};

/**
 * @class Reserva
 * @brief Representa uma reserva associando um hóspede a um quarto por N dias.
 *
 * Dias é representado pelo domínio Numero (1..999).
 */
class Reserva {
private:
  Hospede hospede; ///< Hóspede associado.
  Quarto quarto;   ///< Quarto reservado.
  Numero dias;     ///< Quantidade de dias.
public:
  /**
   * @brief Constrói uma Reserva validando todos os atributos.
   */
  Reserva(const Hospede &hospede, const Quarto &quarto, int dias);

  /**
   * @brief Obtém o hóspede.
   */
  Hospede getHospede() const;

  /**
   * @brief Obtém o quarto.
   */
  Quarto getQuarto() const;

  /**
   * @brief Obtém a quantidade de dias.
   */
  int getDias() const;

  /**
   * @brief Define a quantidade de dias.
   * @throw invalid_argument se inválido segundo domínio Numero.
   */
  void setDias(int valor);

  /**
   * @brief Calcula o total em centavos.
   * @return Valor total = dias * precoDiaria.
   */
  long calcularTotalCentavos() const;

  /**
   * @brief Calcula o total em reais (double).
   */
  double calcularTotalReais() const;
};

#endif
