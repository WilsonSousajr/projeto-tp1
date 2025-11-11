#ifndef INTERFACES_HPP_INCLUDED
#define INTERFACES_HPP_INCLUDED

/**
 * @file interfaces.hpp
 * @brief Declaração das interfaces para os módulos de serviço.
 *
 * Define as classes abstratas que servem como contratos para a camada de
 * apresentação. Cada interface corresponde a um conjunto de funcionalidades
 * de negócio.
 */

#include "entidades/entidades.hpp"
#include <list>
#include <string>

// Forward declaration to avoid circular dependency
class Gerente;
class Hospede;
class Hotel;
class Quarto;
class Reserva;

/**
 * @interface IServicoAutenticacao
 * @brief Interface para o serviço de autenticação.
 *
 * Define o método para autenticar um gerente no sistema.
 */
class IServicoAutenticacao {
public:
  /**
   * @brief Tenta autenticar um gerente.
   * @param email O email do gerente.
   * @param senha A senha do gerente.
   * @return true se a autenticação for bem-sucedida, false caso contrário.
   */
  virtual bool autenticar(const Email &email, const Senha &senha) = 0;
  virtual ~IServicoAutenticacao() {}
};

/**
 * @interface IServicoGerente
 * @brief Interface para os serviços relacionados à entidade Gerente.
 *
 * Define os métodos para gerenciar as contas dos gerentes.
 */
class IServicoGerente {
public:
  /**
   * @brief Cadastra um novo gerente no sistema.
   * @param gerente A entidade Gerente a ser cadastrada.
   * @return true se o cadastro for bem-sucedido.
   * @throw invalid_argument se o gerente já existir.
   */
  virtual bool cadastrar(const Gerente &gerente) = 0;

  /**
   * @brief Edita os dados de um gerente existente.
   * @param gerente A entidade Gerente com os dados atualizados.
   * @return true se a edição for bem-sucedida.
   * @throw invalid_argument se o gerente não for encontrado.
   */
  virtual bool editar(const Gerente &gerente) = 0;

  /**
   * @brief Remove um gerente do sistema.
   * @param email O email do gerente a ser removido.
   * @return true se a remoção for bem-sucedida.
   * @throw invalid_argument se o gerente não for encontrado.
   */
  virtual bool descadastrar(const Email &email) = 0;
  virtual ~IServicoGerente() {}
};

/**
 * @interface IServicoHospede
 * @brief Interface para os serviços relacionados à entidade Hóspede.
 */
class IServicoHospede {
public:
  virtual bool cadastrar(const Hospede &hospede) = 0;
  virtual Hospede consultar(const Email &email) = 0;
  virtual bool editar(const Hospede &hospede) = 0;
  virtual bool descadastrar(const Email &email) = 0;
  virtual list<Hospede> listar() = 0;
  virtual ~IServicoHospede() {}
};

/**
 * @interface IServicoHotel
 * @brief Interface para os serviços relacionados à entidade Hotel.
 */
class IServicoHotel {
public:
  virtual bool cadastrar(const Hotel &hotel) = 0;
  virtual Hotel consultar(const Nome &nome) = 0;
  virtual bool editar(const Hotel &hotel) = 0;
  virtual bool descadastrar(const Nome &nome) = 0;
  virtual list<Hotel> listar() = 0;
  virtual ~IServicoHotel() {}
};

/**
 * @interface IServicoQuarto
 * @brief Interface para os serviços relacionados à entidade Quarto.
 */
class IServicoQuarto {
public:
  virtual bool cadastrar(const Quarto &quarto) = 0;
  virtual Quarto consultar(const Numero &numero) = 0;
  virtual bool editar(const Quarto &quarto) = 0;
  virtual bool descadastrar(const Numero &numero) = 0;
  virtual list<Quarto> listar() = 0;
  virtual ~IServicoQuarto() {}
};

/**
 * @interface IServicoReserva
 * @brief Interface para os serviços relacionados à entidade Reserva.
 */
class IServicoReserva {
public:
  virtual bool cadastrar(const Reserva &reserva) = 0;
  virtual Reserva consultar(const Codigo &codigo) = 0;
  virtual bool editar(const Reserva &reserva) = 0;
  virtual bool descadastrar(const Codigo &codigo) = 0;
  virtual list<Reserva> listar() = 0;
  virtual ~IServicoReserva() {}
};

#endif // INTERFACES_HPP_INCLUDED
