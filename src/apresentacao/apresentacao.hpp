#ifndef APRESENTACAO_HPP_INCLUDED
#define APRESENTACAO_HPP_INCLUDED

/**
 * @file apresentacao.hpp
 * @brief Declaração das classes de controle da camada de apresentação.
 *
 * Define as classes que gerenciam a interação com o usuário via console,
 * utilizando os serviços da camada de negócio através de suas interfaces.
 */

#include "../interfaces.hpp"

/**
 * @class CntrApresentacaoControle
 * @brief Controladora principal da camada de apresentação.
 *
 * Orquestra o fluxo de execução, como login e menu principal.
 */
class CntrApresentacaoControle {
private:
  IServicoAutenticacao *cntrServicoAutenticacao;
  IServicoGerente *cntrServicoGerente;
  IServicoHospede *cntrServicoHospede;
  IServicoHotel *cntrServicoHotel;
  IServicoQuarto *cntrServicoQuarto;
  IServicoReserva *cntrServicoReserva;

public:
  void executar();
  void setCntrServicoAutenticacao(IServicoAutenticacao *cntr);
  void setCntrServicoGerente(IServicoGerente *cntr);
  void setCntrServicoHospede(IServicoHospede *cntr);
  void setCntrServicoHotel(IServicoHotel *cntr);
  void setCntrServicoQuarto(IServicoQuarto *cntr);
  void setCntrServicoReserva(IServicoReserva *cntr);
};

/**
 * @class CntrApresentacaoGerente
 * @brief Controladora de apresentação para funcionalidades de Gerente.
 */
class CntrApresentacaoGerente {
private:
  IServicoGerente *cntrServicoGerente;

public:
  void executar(const Email &email); // Gerencia a própria conta
  void cadastrar();                  // Cadastra um novo gerente
  void setCntrServicoGerente(IServicoGerente *cntr);
};

/**
 * @class CntrApresentacaoPessoal
 * @brief Controladora de apresentação para Hóspedes, Hotéis, Quartos e
 * Reservas.
 */
class CntrApresentacaoPessoal {
private:
  IServicoHospede *cntrServicoHospede;
  IServicoHotel *cntrServicoHotel;
  IServicoQuarto *cntrServicoQuarto;
  IServicoReserva *cntrServicoReserva;

public:
  void executar();
  void setCntrServicoHospede(IServicoHospede *cntr);
  void setCntrServicoHotel(IServicoHotel *cntr);
  void setCntrServicoQuarto(IServicoQuarto *cntr);
  void setCntrServicoReserva(IServicoReserva *cntr);

private:
  void menuHospedes();
  void menuHoteis();
  void menuQuartos();
  void menuReservas();
};

#endif // APRESENTACAO_HPP_INCLUDED
