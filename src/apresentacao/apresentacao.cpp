/**
 * @file apresentacao.cpp
 * @brief Implementação das classes de controle da camada de apresentação.
 */

#include "apresentacao.hpp"
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

// ---------- CntrApresentacaoControle ----------

void CntrApresentacaoControle::setCntrServicoAutenticacao(
    IServicoAutenticacao *cntr) {
  this->cntrServicoAutenticacao = cntr;
}

void CntrApresentacaoControle::setCntrServicoGerente(IServicoGerente *cntr) {
  this->cntrServicoGerente = cntr;
}
void CntrApresentacaoControle::setCntrServicoHospede(IServicoHospede *cntr) {
  this->cntrServicoHospede = cntr;
}
void CntrApresentacaoControle::setCntrServicoHotel(IServicoHotel *cntr) {
  this->cntrServicoHotel = cntr;
}
void CntrApresentacaoControle::setCntrServicoQuarto(IServicoQuarto *cntr) {
  this->cntrServicoQuarto = cntr;
}
void CntrApresentacaoControle::setCntrServicoReserva(IServicoReserva *cntr) {
  this->cntrServicoReserva = cntr;
}

void CntrApresentacaoControle::executar() {
  cout << "Bem-vindo ao Sistema de Gestão de Hotel!" << endl;
  cout << "----------------------------------------" << endl;

  // Cadastrar um gerente padrão para permitir o primeiro login
  try {
    Gerente gerentePadrao("Admin Primeiro", "admin@hotel.com", "12345abcde",
                          "A1a!2");
    cntrServicoGerente->cadastrar(gerentePadrao);
    cout << "INFO: Gerente padrão 'admin@hotel.com' com senha 'A1a!2' criado."
         << endl;
  } catch (const invalid_argument &e) {
    // Ignora se o gerente já existe em execuções anteriores.
  }

  while (true) {
    cout << "\n1. Login" << endl;
    cout << "2. Cadastrar novo gerente" << endl;
    cout << "3. Sair" << endl;
    cout << "Escolha uma opção: ";

    int opcao;
    cin >> opcao;
    if (!cin) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Opção inválida." << endl;
      continue;
    }

    switch (opcao) {
    case 1: {
      try {
        string emailInput, senhaInput;
        cout << "Email: ";
        cin >> emailInput;
        cout << "Senha (5 chars): ";
        cin >> senhaInput;

        Email email;
        email.setValor(emailInput);
        Senha senha;
        senha.setValor(senhaInput);

        if (cntrServicoAutenticacao->autenticar(email, senha)) {
          cout << "Login bem-sucedido!" << endl;
          CntrApresentacaoPessoal cntrPessoal;
          cntrPessoal.setCntrServicoHospede(this->cntrServicoHospede);
          cntrPessoal.setCntrServicoHotel(this->cntrServicoHotel);
          cntrPessoal.setCntrServicoQuarto(this->cntrServicoQuarto);
          cntrPessoal.setCntrServicoReserva(this->cntrServicoReserva);
          cntrPessoal.executar();
        } else {
          cout << "Falha na autenticação. Verifique email e senha." << endl;
        }
      } catch (const invalid_argument &e) {
        cout << "Erro de formato: " << e.what() << endl;
      }
      break;
    }
    case 2: {
      CntrApresentacaoGerente cntrGerente;
      cntrGerente.setCntrServicoGerente(cntrServicoGerente);
      cntrGerente.cadastrar();
      break;
    }
    case 3:
      cout << "Saindo do sistema." << endl;
      return;
    default:
      cout << "Opção inválida." << endl;
    }
  }
}

// ---------- CntrApresentacaoGerente ----------

void CntrApresentacaoGerente::setCntrServicoGerente(IServicoGerente *cntr) {
  this->cntrServicoGerente = cntr;
}

void CntrApresentacaoGerente::cadastrar() {
  cout << "\n--- Cadastro de Novo Gerente ---" << endl;
  try {
    string nome, email, matricula, senha;
    cout << "Nome: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nome);
    cout << "Email: ";
    cin >> email;
    cout << "Matrícula: ";
    cin >> matricula;
    cout << "Senha: ";
    cin >> senha;

    Gerente gerente(nome, email, matricula, senha);
    if (cntrServicoGerente->cadastrar(gerente)) {
      cout << "Gerente cadastrado com sucesso!" << endl;
    }
  } catch (const invalid_argument &e) {
    cout << "Erro no cadastro: " << e.what() << endl;
  }
}

void CntrApresentacaoGerente::executar(const Email &email) {
  (void)email;
  // Implementar menu para editar/descadastrar a própria conta
  cout << "\nFuncionalidades de gerenciamento de conta não implementadas."
       << endl;
}

// ---------- CntrApresentacaoPessoal ----------

void CntrApresentacaoPessoal::setCntrServicoHospede(IServicoHospede *cntr) {
  this->cntrServicoHospede = cntr;
}
void CntrApresentacaoPessoal::setCntrServicoHotel(IServicoHotel *cntr) {
  this->cntrServicoHotel = cntr;
}
void CntrApresentacaoPessoal::setCntrServicoQuarto(IServicoQuarto *cntr) {
  this->cntrServicoQuarto = cntr;
}
void CntrApresentacaoPessoal::setCntrServicoReserva(IServicoReserva *cntr) {
  this->cntrServicoReserva = cntr;
}

void CntrApresentacaoPessoal::executar() {

  while (true) {
    cout << "\n--- Menu Principal ---" << endl;
    cout << "1. Gerenciar Hóspedes" << endl;
    cout << "2. Gerenciar Hotéis" << endl;
    cout << "3. Gerenciar Quartos" << endl;
    cout << "4. Gerenciar Reservas" << endl;
    cout << "5. Voltar (Logout)" << endl;
    cout << "Escolha uma opção: ";

    int opcao;
    cin >> opcao;
    if (!cin) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Opção inválida." << endl;
      continue;
    }

    switch (opcao) {
    case 1:
      menuHospedes();
      break;
    case 2:
      menuHoteis();
      break;
    case 3:
      menuQuartos();
      break;
    case 4:
      menuReservas();
      break;
    case 5:
      return;
    default:
      cout << "Opção inválida." << endl;
    }
  }
}

void CntrApresentacaoPessoal::menuHospedes() {
  cout << "\n--- Gerenciar Hóspedes ---" << endl;
  cout << "Funcionalidade de Hóspedes:" << endl;
  cout << "1. Cadastrar" << endl;
  cout << "2. Listar" << endl;
  cout << "3. Editar" << endl;
  cout << "4. Excluir" << endl;
  cout << "Opção: ";
  int opcao;
  cin >> opcao;
  if (!cin) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Opção inválida." << endl;
    return;
  }
  if (opcao == 1) {
    try {
      string nome, email, cartao;
      cout << "Nome: ";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      getline(cin, nome);
      cout << "Email: ";
      cin >> email;
      cout << "Cartão de Crédito: ";
      cin >> cartao;
      Hospede hospede(nome, email, cartao);
      if (cntrServicoHospede->cadastrar(hospede)) {
        cout << "Hóspede cadastrado com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  } else if (opcao == 2) {
    list<Hospede> lista = cntrServicoHospede->listar();
    cout << "\n--- Lista de Hóspedes ---" << endl;
    for (const auto &h : lista) {
      cout << "Nome: " << h.getNome() << " | Email: " << h.getEmail() << endl;
    }
  } else if (opcao == 3) {
    try {
      string email, nome, cartao;
      cout << "Email do Hóspede a editar: ";
      cin >> email;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Novo Nome: ";
      getline(cin, nome);
      cout << "Novo Cartão de Crédito: ";
      cin >> cartao;
      Hospede hospede(nome, email, cartao); // PK = email permanece igual
      if (cntrServicoHospede->editar(hospede)) {
        cout << "Hóspede atualizado com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  } else if (opcao == 4) {
    try {
      string email;
      cout << "Email do Hóspede a excluir: ";
      cin >> email;
      Email dom;
      dom.setValor(email);
      if (cntrServicoHospede->descadastrar(dom)) {
        cout << "Hóspede excluído com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  }
}

void CntrApresentacaoPessoal::menuHoteis() {
  cout << "\n--- Gerenciar Hotéis ---" << endl;
  cout << "1. Cadastrar" << endl;
  cout << "2. Listar" << endl;
  cout << "3. Editar" << endl;
  cout << "4. Excluir" << endl;
  cout << "Opção: ";
  int opcao;
  cin >> opcao;
  if (!cin) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Opção inválida." << endl;
    return;
  }
  if (opcao == 1) {
    try {
      string nome, cidade;
      int vagas;
      cout << "Nome do Hotel (5-20 chars, palavras com inicial maiúscula): ";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      getline(cin, nome);
      cout << "Cidade (>=5 chars, palavras com inicial maiúscula): ";
      getline(cin, cidade);
      cout << "Vagas: ";
      cin >> vagas;
      Hotel hotel(nome, cidade, vagas);
      if (cntrServicoHotel->cadastrar(hotel)) {
        cout << "Hotel cadastrado com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  } else if (opcao == 2) {
    list<Hotel> lista = cntrServicoHotel->listar();
    cout << "\n--- Lista de Hotéis ---" << endl;
    for (const auto &h : lista) {
      cout << "Nome: " << h.getNome() << " | Cidade: " << h.getCidade()
           << " | Vagas: " << h.getVagas() << endl;
    }
  } else if (opcao == 3) {
    try {
      string nome, cidade;
      int vagas;
      cout << "Nome do Hotel a editar: ";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      getline(cin, nome);
      cout << "Nova Cidade: ";
      getline(cin, cidade);
      cout << "Novas Vagas: ";
      cin >> vagas;
      Hotel hotel(nome, cidade, vagas); // PK = nome permanece igual
      if (cntrServicoHotel->editar(hotel)) {
        cout << "Hotel atualizado com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  } else if (opcao == 4) {
    try {
      string nome;
      cout << "Nome do Hotel a excluir: ";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      getline(cin, nome);
      Nome dom;
      dom.setValor(nome);
      if (cntrServicoHotel->descadastrar(dom)) {
        cout << "Hotel excluído com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  }
}

void CntrApresentacaoPessoal::menuQuartos() {
  cout << "\n--- Gerenciar Quartos ---" << endl;
  cout << "1. Cadastrar" << endl;
  cout << "2. Listar" << endl;
  cout << "3. Editar" << endl;
  cout << "4. Excluir" << endl;
  cout << "Opção: ";
  int opcao;
  cin >> opcao;
  if (!cin) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Opção inválida." << endl;
    return;
  }
  if (opcao == 1) {
    try {
      int numero, capacidade, preco;
      cout << "Número do Quarto: ";
      cin >> numero;
      cout << "Capacidade: ";
      cin >> capacidade;
      cout << "Preço (centavos): ";
      cin >> preco;
      Quarto quarto(numero, capacidade, preco);
      if (cntrServicoQuarto->cadastrar(quarto)) {
        cout << "Quarto cadastrado com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  } else if (opcao == 2) {
    list<Quarto> lista = cntrServicoQuarto->listar();
    cout << "\n--- Lista de Quartos ---" << endl;
    for (const auto &q : lista) {
      cout << "Número: " << q.getNumero()
           << " | Capacidade: " << q.getCapacidade()
           << " | Preço: R$ " << q.getPrecoDiariaReais() << endl;
    }
  } else if (opcao == 3) {
    try {
      int numero, capacidade, preco;
      cout << "Número do Quarto a editar: ";
      cin >> numero;
      cout << "Nova Capacidade: ";
      cin >> capacidade;
      cout << "Novo Preço (centavos): ";
      cin >> preco;
      Quarto quarto(numero, capacidade, preco); // PK = numero permanece igual
      if (cntrServicoQuarto->editar(quarto)) {
        cout << "Quarto atualizado com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  } else if (opcao == 4) {
    try {
      int numero;
      cout << "Número do Quarto a excluir: ";
      cin >> numero;
      Numero dom;
      dom.setValor(numero);
      if (cntrServicoQuarto->descadastrar(dom)) {
        cout << "Quarto excluído com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  }
}

void CntrApresentacaoPessoal::menuReservas() {
  cout << "\n--- Gerenciar Reservas ---" << endl;
  cout << "1. Cadastrar" << endl;
  cout << "2. Listar" << endl;
  cout << "3. Editar" << endl;
  cout << "4. Excluir" << endl;
  cout << "Opção: ";
  int opcao;
  cin >> opcao;
  if (!cin) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Opção inválida." << endl;
    return;
  }
  if (opcao == 1) {
    try {
      string codigo, dataInicio, emailHospede;
      int numQuarto, dias;
      cout << "Código da Reserva: ";
      cin >> codigo;
      cout << "Data de Início (DD-MES-YYYY, ex.: 10-MAI-2025): ";
      cin >> dataInicio;
      cout << "Dias: ";
      cin >> dias;
      cout << "Email do Hóspede: ";
      cin >> emailHospede;
      cout << "Número do Quarto: ";
      cin >> numQuarto;

      Email email;
      email.setValor(emailHospede);
      Hospede hospede = cntrServicoHospede->consultar(email);

      Numero numero;
      numero.setValor(numQuarto);
      Quarto quarto = cntrServicoQuarto->consultar(numero);

      Reserva reserva(codigo, dataInicio, dias, hospede, quarto);
      if (cntrServicoReserva->cadastrar(reserva)) {
        cout << "Reserva cadastrada com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  } else if (opcao == 2) {
    list<Reserva> lista = cntrServicoReserva->listar();
    cout << "\n--- Lista de Reservas ---" << endl;
    for (const auto &r : lista) {
      cout << "Código: " << r.getCodigo()
           << " | Início: " << r.getDataInicio()
           << " | Quarto: " << r.getQuarto().getNumero()
           << " | Hóspede: " << r.getHospede().getEmail() << endl;
    }
  } else if (opcao == 3) {
    try {
      string codigo, dataInicio, emailHospede;
      int numQuarto, dias;
      cout << "Código da Reserva a editar: ";
      cin >> codigo;
      cout << "Nova Data de Início (DD-MES-YYYY, ex.: 10-MAI-2025): ";
      cin >> dataInicio;
      cout << "Novos Dias: ";
      cin >> dias;
      cout << "Email do Hóspede: ";
      cin >> emailHospede;
      cout << "Número do Quarto: ";
      cin >> numQuarto;

      Email email;
      email.setValor(emailHospede);
      Hospede hospede = cntrServicoHospede->consultar(email);

      Numero numero;
      numero.setValor(numQuarto);
      Quarto quarto = cntrServicoQuarto->consultar(numero);

      Reserva reserva(codigo, dataInicio, dias, hospede, quarto); // PK = codigo permanece
      if (cntrServicoReserva->editar(reserva)) {
        cout << "Reserva atualizada com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  } else if (opcao == 4) {
    try {
      string codigo;
      cout << "Código da Reserva a excluir: ";
      cin >> codigo;
      Codigo cod;
      cod.setValor(codigo);
      if (cntrServicoReserva->descadastrar(cod)) {
        cout << "Reserva excluída com sucesso!" << endl;
      }
    } catch (const invalid_argument &e) {
      cout << "Erro: " << e.what() << endl;
    }
  }
}
