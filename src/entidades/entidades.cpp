/**
 * @file entidades.cpp
 * @brief Implementations of entity classes that aggregate validated domains.
 *
 * Fornece a lógica de construção e acesso aos atributos encapsulados pelos
 * domínios declarados em dominios.hpp, garantindo validação centralizada.
 */

#include "entidades.hpp"
#include <utility>

// -------------------- Pessoa --------------------
Pessoa::Pessoa(const string &nomeValor, const string &emailValor) {
  setNome(nomeValor);
  setEmail(emailValor);
}

string Pessoa::getNome() const { return nome.getValor(); }

void Pessoa::setNome(const string &valor) { nome.setValor(valor); }

string Pessoa::getEmail() const { return email.getValor(); }

void Pessoa::setEmail(const string &valor) { email.setValor(valor); }

// -------------------- Gerente --------------------
Gerente::Gerente(const string &nomeValor, const string &emailValor,
                 const string &matriculaValor, const string &senhaValor)
    : Pessoa(nomeValor, emailValor) {
  setMatricula(matriculaValor);
  setSenha(senhaValor);
}

string Gerente::getMatricula() const { return matricula.getValor(); }

void Gerente::setMatricula(const string &valor) { matricula.setValor(valor); }

string Gerente::getSenha() const { return senha.getValor(); }

void Gerente::setSenha(const string &valor) { senha.setValor(valor); }

// -------------------- Hospede --------------------
Hospede::Hospede(const string &nomeValor, const string &emailValor,
                 const string &cartaoValor)
    : Pessoa(nomeValor, emailValor) {
  setCartaoCredito(cartaoValor);
}

string Hospede::getCartaoCredito() const { return cartaoCredito.getValor(); }

void Hospede::setCartaoCredito(const string &valor) {
  cartaoCredito.setValor(valor);
}

// -------------------- Quarto --------------------
Quarto::Quarto(int numeroValor, int capacidadeValor, int precoCentavos) {
  setNumero(numeroValor);
  setCapacidade(capacidadeValor);
  setPrecoDiaria(precoCentavos);
}

int Quarto::getNumero() const { return numero.getValor(); }

void Quarto::setNumero(int valor) { numero.setValor(valor); }

int Quarto::getCapacidade() const { return capacidade.getValor(); }

void Quarto::setCapacidade(int valor) { capacidade.setValor(valor); }

int Quarto::getPrecoDiariaCentavos() const { return precoDiaria.getValor(); }

double Quarto::getPrecoDiariaReais() const {
  return static_cast<double>(precoDiaria.getValor()) / 100.0;
}

void Quarto::setPrecoDiaria(int centavos) { precoDiaria.setValor(centavos); }

// -------------------- Hotel --------------------
Hotel::Hotel(const string &nomeValor, const string &cidadeValor, int vagasValor) {
  setNome(nomeValor);
  setCidade(cidadeValor);
  setVagas(vagasValor);
}

string Hotel::getNome() const { return nome.getValor(); }

void Hotel::setNome(const string &valor) { nome.setValor(valor); }

string Hotel::getCidade() const { return cidade.getValor(); }

void Hotel::setCidade(const string &valor) { cidade.setValor(valor); }

int Hotel::getVagas() const { return vagas.getValor(); }

void Hotel::setVagas(int valor) { vagas.setValor(valor); }

// -------------------- Reserva --------------------
Reserva::Reserva(const string &codigoValor, const string &dataInicioValor,
                 int diasValor, const Hospede &h, const Quarto &q)
    : hospede(h), quarto(q) {
  setCodigo(codigoValor);
  setDataInicio(dataInicioValor);
  setDias(diasValor);
}

string Reserva::getCodigo() const { return codigo.getValor(); }

void Reserva::setCodigo(const string &valor) { codigo.setValor(valor); }

string Reserva::getDataInicio() const { return dataInicio.getValor(); }

void Reserva::setDataInicio(const string &valor) { dataInicio.setValor(valor); }

Hospede Reserva::getHospede() const { return hospede; }

Quarto Reserva::getQuarto() const { return quarto; }

int Reserva::getDias() const { return dias.getValor(); }

void Reserva::setDias(int valor) { dias.setValor(valor); }

long Reserva::calcularTotalCentavos() const {
  return static_cast<long>(getDias()) * quarto.getPrecoDiariaCentavos();
}

double Reserva::calcularTotalReais() const {
  return static_cast<double>(calcularTotalCentavos()) / 100.0;
}
