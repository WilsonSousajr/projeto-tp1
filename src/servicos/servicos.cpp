/**
 * @file servicos.cpp
 * @brief Implementação das classes de serviço e contêineres de dados.
 */

#include "servicos.hpp"
#include <stdexcept>

// Instâncias globais dos contêineres para simular a persistência
static ContainerGerente containerGerente;
static ContainerHospede containerHospede;
static ContainerHotel containerHotel;
static ContainerQuarto containerQuarto;
static ContainerReserva containerReserva;

// ---------- IMPLEMENTAÇÃO DOS CONTÊINERES ----------

// ContainerGerente
void ContainerGerente::inserir(const Gerente &gerente) {
  if (existe(gerente.getEmail())) {
    throw invalid_argument("Gerente já cadastrado.");
  }
  gerentes.emplace(gerente.getEmail(), gerente);
}

void ContainerGerente::remover(const string &email) {
  if (!existe(email)) {
    throw invalid_argument("Gerente não encontrado.");
  }
  gerentes.erase(email);
}

Gerente ContainerGerente::pesquisar(const string &email) {
  if (!existe(email)) {
    throw invalid_argument("Gerente não encontrado.");
  }
  return gerentes.at(email);
}

void ContainerGerente::atualizar(const Gerente &gerente) {
  if (!existe(gerente.getEmail())) {
    throw invalid_argument("Gerente não encontrado.");
  }
  gerentes[gerente.getEmail()] = gerente;
}

bool ContainerGerente::existe(const string &email) {
  return gerentes.find(email) != gerentes.end();
}

// ContainerHospede
void ContainerHospede::inserir(const Hospede &hospede) {
  if (hospedes.count(hospede.getEmail())) {
    throw invalid_argument("Hóspede já cadastrado.");
  }
  hospedes.emplace(hospede.getEmail(), hospede);
}
void ContainerHospede::remover(const string &email) {
  if (!hospedes.count(email)) {
    throw invalid_argument("Hóspede não encontrado.");
  }
  hospedes.erase(email);
}
Hospede ContainerHospede::pesquisar(const string &email) {
  if (!hospedes.count(email)) {
    throw invalid_argument("Hóspede não encontrado.");
  }
  return hospedes.at(email);
}
void ContainerHospede::atualizar(const Hospede &hospede) {
  if (!hospedes.count(hospede.getEmail())) {
    throw invalid_argument("Hóspede não encontrado.");
  }
  hospedes[hospede.getEmail()] = hospede;
}
list<Hospede> ContainerHospede::listarTodos() {
  list<Hospede> lista;
  for (auto const &[key, val] : hospedes) {
    lista.push_back(val);
  }
  return lista;
}

// ContainerHotel
void ContainerHotel::inserir(const Hotel &hotel) {
  if (hoteis.count(hotel.getNome())) {
    throw invalid_argument("Hotel já cadastrado.");
  }
  hoteis.emplace(hotel.getNome(), hotel);
}
void ContainerHotel::remover(const string &nome) {
  if (!hoteis.count(nome)) {
    throw invalid_argument("Hotel não encontrado.");
  }
  hoteis.erase(nome);
}
Hotel ContainerHotel::pesquisar(const string &nome) {
  if (!hoteis.count(nome)) {
    throw invalid_argument("Hotel não encontrado.");
  }
  return hoteis.at(nome);
}
void ContainerHotel::atualizar(const Hotel &hotel) {
  if (!hoteis.count(hotel.getNome())) {
    throw invalid_argument("Hotel não encontrado.");
  }
  hoteis[hotel.getNome()] = hotel;
}
list<Hotel> ContainerHotel::listarTodos() {
  list<Hotel> lista;
  for (auto const &[key, val] : hoteis) {
    lista.push_back(val);
  }
  return lista;
}

// ContainerQuarto
void ContainerQuarto::inserir(const Quarto &quarto) {
  if (quartos.count(quarto.getNumero())) {
    throw invalid_argument("Quarto já cadastrado.");
  }
  quartos.emplace(quarto.getNumero(), quarto);
}
void ContainerQuarto::remover(int numero) {
  if (!quartos.count(numero)) {
    throw invalid_argument("Quarto não encontrado.");
  }
  quartos.erase(numero);
}
Quarto ContainerQuarto::pesquisar(int numero) {
  if (!quartos.count(numero)) {
    throw invalid_argument("Quarto não encontrado.");
  }
  return quartos.at(numero);
}
void ContainerQuarto::atualizar(const Quarto &quarto) {
  if (!quartos.count(quarto.getNumero())) {
    throw invalid_argument("Quarto não encontrado.");
  }
  quartos[quarto.getNumero()] = quarto;
}
list<Quarto> ContainerQuarto::listarTodos() {
  list<Quarto> lista;
  for (auto const &[key, val] : quartos) {
    lista.push_back(val);
  }
  return lista;
}

// ContainerReserva
void ContainerReserva::inserir(const Reserva &reserva) {
  if (reservas.count(reserva.getCodigo())) {
    throw invalid_argument("Reserva já cadastrada.");
  }
  reservas.emplace(reserva.getCodigo(), reserva);
}
void ContainerReserva::remover(const string &codigo) {
  if (!reservas.count(codigo)) {
    throw invalid_argument("Reserva não encontrada.");
  }
  reservas.erase(codigo);
}
Reserva ContainerReserva::pesquisar(const string &codigo) {
  if (!reservas.count(codigo)) {
    throw invalid_argument("Reserva não encontrada.");
  }
  return reservas.at(codigo);
}
void ContainerReserva::atualizar(const Reserva &reserva) {
  if (!reservas.count(reserva.getCodigo())) {
    throw invalid_argument("Reserva não encontrada.");
  }
  reservas[reserva.getCodigo()] = reserva;
}
list<Reserva> ContainerReserva::listarTodos() {
  list<Reserva> lista;
  for (auto const &[key, val] : reservas) {
    lista.push_back(val);
  }
  return lista;
}

// ---------- IMPLEMENTAÇÃO DAS CONTROLADORAS DE SERVIÇO ----------

// CntrServicoAutenticacao
bool CntrServicoAutenticacao::autenticar(const Email &email,
                                        const Senha &senha) {
  try {
    Gerente gerente = containerGerente.pesquisar(email.getValor());
    if (gerente.getSenha() == senha.getValor()) {
      return true;
    }
    return false;
  } catch (const invalid_argument &e) {
    return false; // Gerente não encontrado
  }
}

// CntrServicoGerente
bool CntrServicoGerente::cadastrar(const Gerente &gerente) {
  containerGerente.inserir(gerente);
  return true;
}

bool CntrServicoGerente::editar(const Gerente &gerente) {
  // A chave primária (email) não pode ser editada.
  // O container usa o email como chave, então a atualização é direta.
  containerGerente.atualizar(gerente);
  return true;
}

bool CntrServicoGerente::descadastrar(const Email &email) {
  containerGerente.remover(email.getValor());
  return true;
}

// CntrServicoHospede
bool CntrServicoHospede::cadastrar(const Hospede &hospede) {
  containerHospede.inserir(hospede);
  return true;
}
Hospede CntrServicoHospede::consultar(const Email &email) {
  return containerHospede.pesquisar(email.getValor());
}
bool CntrServicoHospede::editar(const Hospede &hospede) {
  containerHospede.atualizar(hospede);
  return true;
}
bool CntrServicoHospede::descadastrar(const Email &email) {
  // Regra de negócio: não permitir exclusão se houver reservas associadas.
  list<Reserva> todasReservas = containerReserva.listarTodos();
  for (const auto &reserva : todasReservas) {
    if (reserva.getHospede().getEmail() == email.getValor()) {
      throw invalid_argument("Hóspede possui reservas e não pode ser excluído.");
    }
  }
  containerHospede.remover(email.getValor());
  return true;
}
list<Hospede> CntrServicoHospede::listar() {
  return containerHospede.listarTodos();
}

// CntrServicoHotel
bool CntrServicoHotel::cadastrar(const Hotel &hotel) {
  containerHotel.inserir(hotel);
  return true;
}
Hotel CntrServicoHotel::consultar(const Nome &nome) {
  return containerHotel.pesquisar(nome.getValor());
}
bool CntrServicoHotel::editar(const Hotel &hotel) {
  containerHotel.atualizar(hotel);
  return true;
}
bool CntrServicoHotel::descadastrar(const Nome &nome) {
  // Regra de negócio: não permitir exclusão se houver quartos associados.
  // Esta verificação é simplificada. Uma implementação real associaria
  // quartos a hotéis. Como não há essa associação direta, a regra não pode
  // ser implementada aqui.
  containerHotel.remover(nome.getValor());
  return true;
}
list<Hotel> CntrServicoHotel::listar() { return containerHotel.listarTodos(); }

// CntrServicoQuarto
bool CntrServicoQuarto::cadastrar(const Quarto &quarto) {
  containerQuarto.inserir(quarto);
  return true;
}
Quarto CntrServicoQuarto::consultar(const Numero &numero) {
  return containerQuarto.pesquisar(numero.getValor());
}
bool CntrServicoQuarto::editar(const Quarto &quarto) {
  containerQuarto.atualizar(quarto);
  return true;
}
bool CntrServicoQuarto::descadastrar(const Numero &numero) {
  // Regra de negócio: não permitir exclusão se houver reservas associadas.
  list<Reserva> todasReservas = containerReserva.listarTodos();
  for (const auto &reserva : todasReservas) {
    if (reserva.getQuarto().getNumero() == numero.getValor()) {
      throw invalid_argument("Quarto possui reservas e não pode ser excluído.");
    }
  }
  containerQuarto.remover(numero.getValor());
  return true;
}
list<Quarto> CntrServicoQuarto::listar() { return containerQuarto.listarTodos(); }

// CntrServicoReserva
bool CntrServicoReserva::cadastrar(const Reserva &reserva) {
  // Regra de negócio: Verificar conflito de datas.
  // Simplificado: verifica se já existe reserva para o mesmo quarto.
  // Uma implementação real precisaria de lógica de datas.
  list<Reserva> todasReservas = containerReserva.listarTodos();
  for (const auto &existente : todasReservas) {
    if (existente.getQuarto().getNumero() == reserva.getQuarto().getNumero()) {
      // Lógica de sobreposição de datas seria implementada aqui.
      // Por simplicidade, vamos apenas verificar se a data de início é a mesma.
      if (existente.getDataInicio() == reserva.getDataInicio()) {
        throw invalid_argument("Conflito de reserva para este quarto e data.");
      }
    }
  }
  containerReserva.inserir(reserva);
  return true;
}
Reserva CntrServicoReserva::consultar(const Codigo &codigo) {
  return containerReserva.pesquisar(codigo.getValor());
}
bool CntrServicoReserva::editar(const Reserva &reserva) {
  containerReserva.atualizar(reserva);
  return true;
}
bool CntrServicoReserva::descadastrar(const Codigo &codigo) {
  containerReserva.remover(codigo.getValor());
  return true;
}
list<Reserva> CntrServicoReserva::listar() {
  return containerReserva.listarTodos();
}
