#ifndef SERVICOS_HPP_INCLUDED
#define SERVICOS_HPP_INCLUDED

/**
 * @file servicos.hpp
 * @brief Declaração das classes de serviço e contêineres de dados.
 *
 * Este arquivo contém as declarações das classes que implementam a lógica de
 * negócio (Controladoras) e as classes responsáveis pelo armazenamento em
 * memória (Contêineres).
 */

#include "../interfaces.hpp"
#include <map>

// ---------- CONTÊINERES DE DADOS ----------

/**
 * @class ContainerGerente
 * @brief Armazena e gerencia os objetos Gerente em memória.
 *
 * Utiliza um std::map com o email do gerente como chave.
 */
class ContainerGerente {
private:
  map<string, Gerente> gerentes;

public:
  void inserir(const Gerente &gerente);
  void remover(const string &email);
  Gerente pesquisar(const string &email);
  void atualizar(const Gerente &gerente);
  bool existe(const string &email);
};

/**
 * @class ContainerHospede
 * @brief Armazena e gerencia os objetos Hospede em memória.
 */
class ContainerHospede {
private:
  map<string, Hospede> hospedes;

public:
  void inserir(const Hospede &hospede);
  void remover(const string &email);
  Hospede pesquisar(const string &email);
  void atualizar(const Hospede &hospede);
  list<Hospede> listarTodos();
};

/**
 * @class ContainerHotel
 * @brief Armazena e gerencia os objetos Hotel em memória.
 */
class ContainerHotel {
private:
  map<string, Hotel> hoteis;

public:
  void inserir(const Hotel &hotel);
  void remover(const string &nome);
  Hotel pesquisar(const string &nome);
  void atualizar(const Hotel &hotel);
  list<Hotel> listarTodos();
};

/**
 * @class ContainerQuarto
 * @brief Armazena e gerencia os objetos Quarto em memória.
 */
class ContainerQuarto {
private:
  map<int, Quarto> quartos;

public:
  void inserir(const Quarto &quarto);
  void remover(int numero);
  Quarto pesquisar(int numero);
  void atualizar(const Quarto &quarto);
  list<Quarto> listarTodos();
};

/**
 * @class ContainerReserva
 * @brief Armazena e gerencia os objetos Reserva em memória.
 */
class ContainerReserva {
private:
  map<string, Reserva> reservas;

public:
  void inserir(const Reserva &reserva);
  void remover(const string &codigo);
  Reserva pesquisar(const string &codigo);
  void atualizar(const Reserva &reserva);
  list<Reserva> listarTodos();
};

// ---------- CONTROLADORAS DE SERVIÇO ----------

/**
 * @class CntrServicoAutenticacao
 * @brief Implementação concreta do serviço de autenticação.
 */
class CntrServicoAutenticacao : public IServicoAutenticacao {
public:
  bool autenticar(const Email &email, const Senha &senha) override;
};

/**
 * @class CntrServicoGerente
 * @brief Implementação concreta dos serviços de Gerente.
 */
class CntrServicoGerente : public IServicoGerente {
public:
  bool cadastrar(const Gerente &gerente) override;
  Gerente consultar(const Email &email) override;
  bool editar(const Gerente &gerente) override;
  bool descadastrar(const Email &email) override;
};

/**
 * @class CntrServicoHospede
 * @brief Implementação concreta dos serviços de Hóspede.
 */
class CntrServicoHospede : public IServicoHospede {
public:
  bool cadastrar(const Hospede &hospede) override;
  Hospede consultar(const Email &email) override;
  bool editar(const Hospede &hospede) override;
  bool descadastrar(const Email &email) override;
  list<Hospede> listar() override;
};

/**
 * @class CntrServicoHotel
 * @brief Implementação concreta dos serviços de Hotel.
 */
class CntrServicoHotel : public IServicoHotel {
public:
  bool cadastrar(const Hotel &hotel) override;
  Hotel consultar(const Nome &nome) override;
  bool editar(const Hotel &hotel) override;
  bool descadastrar(const Nome &nome) override;
  list<Hotel> listar() override;
};

/**
 * @class CntrServicoQuarto
 * @brief Implementação concreta dos serviços de Quarto.
 */
class CntrServicoQuarto : public IServicoQuarto {
public:
  bool cadastrar(const Quarto &quarto) override;
  Quarto consultar(const Numero &numero) override;
  bool editar(const Quarto &quarto) override;
  bool descadastrar(const Numero &numero) override;
  list<Quarto> listar() override;
};

/**
 * @class CntrServicoReserva
 * @brief Implementação concreta dos serviços de Reserva.
 */
class CntrServicoReserva : public IServicoReserva {
public:
  bool cadastrar(const Reserva &reserva) override;
  Reserva consultar(const Codigo &codigo) override;
  bool editar(const Reserva &reserva) override;
  bool descadastrar(const Codigo &codigo) override;
  list<Reserva> listar() override;
};

#endif // SERVICOS_HPP_INCLUDED
