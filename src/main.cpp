/**
 * @file main.cpp
 * @brief Ponto de entrada principal da aplicação.
 *
 * Responsável por instanciar as camadas, injetar as dependências e iniciar
 * o fluxo de execução na camada de apresentação.
 */

#include "apresentacao/apresentacao.hpp"
#include "servicos/servicos.hpp"

int main() {
  // Instanciar controladoras da camada de apresentação
  CntrApresentacaoControle cntrApresentacaoControle;

  // Instanciar controladoras da camada de serviço
  CntrServicoAutenticacao cntrServicoAutenticacao;
  CntrServicoGerente cntrServicoGerente;
  CntrServicoHospede cntrServicoHospede;
  CntrServicoHotel cntrServicoHotel;
  CntrServicoQuarto cntrServicoQuarto;
  CntrServicoReserva cntrServicoReserva;

  // Injetar dependências (ligar apresentação com serviço)
  cntrApresentacaoControle.setCntrServicoAutenticacao(
      &cntrServicoAutenticacao);
  cntrApresentacaoControle.setCntrServicoGerente(&cntrServicoGerente);
  cntrApresentacaoControle.setCntrServicoHospede(&cntrServicoHospede);
  cntrApresentacaoControle.setCntrServicoHotel(&cntrServicoHotel);
  cntrApresentacaoControle.setCntrServicoQuarto(&cntrServicoQuarto);
  cntrApresentacaoControle.setCntrServicoReserva(&cntrServicoReserva);

  // Iniciar a execução do sistema
  cntrApresentacaoControle.executar();

  return 0;
}
