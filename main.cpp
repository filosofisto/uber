#include <iostream>
#include <list>

using namespace std;

// -------------------------------------
// Motorista
// -------------------------------------
class Motorista {
public:
    Motorista(
            const string &nome,
            const string &user,
            const string &senha,
            const string &telefone,
            const string &email,
            const string &modelo,
            float motor,
            int ano,
            const string &placa,
            int litros,
            const string &categoria
    );

    ~Motorista();

    string getUser();

    string getNome();

    double getValorCorridas();

    void adicionarValorCorridas(double valor);

    float estrelas();

    void adicionarAvaliacao(int valor);

private:
    string nome;
    string user;
    string senha;
    string telefone;
    string email;
    string modelo;
    float motor;
    int ano;
    string placa;
    int litros;
    string categoria;
    double valorCorridas;
    int totalEstrelas;
    int totalAvaliacao;
};

Motorista::Motorista(
        const string &nome,
        const string &user,
        const string &senha,
        const string &telefone,
        const string &email,
        const string &modelo,
        float motor,
        int ano,
        const string &placa,
        int litros, const string &categoria) :
        nome(nome),
        user(user),
        senha(senha),
        telefone(telefone),
        email(email),
        modelo(modelo),
        motor(motor),
        ano(ano),
        placa(placa),
        litros(litros),
        categoria(categoria),
        valorCorridas(0.0) {

}

Motorista::~Motorista() {

}

string Motorista::getUser() {
    return user;
}

string Motorista::getNome() {
    return nome;
}

double Motorista::getValorCorridas() {
    return valorCorridas;
}

void Motorista::adicionarValorCorridas(double valor) {
    valorCorridas += valor;
}

float Motorista::estrelas() {
    return totalEstrelas / totalAvaliacao;
}

void Motorista::adicionarAvaliacao(int valor) {
    totalEstrelas += valor;
    totalAvaliacao++;
}

// -------------------------------------
// Usuario
// -------------------------------------
class Usuario {
public:
    Usuario(const string &nome, const string &usuario, const string &senha);

    ~Usuario();

    void pagarCorrida(double valor);
    double getValorTotalPago();
private:
    string nome;
    string usuario;
    string senha;
    double valorTotalPago;
};

Usuario::Usuario(const string &nome, const string &usuario, const string &senha) :
        nome(nome), usuario(usuario), senha(senha), valorTotalPago(0.0) {

}

Usuario::~Usuario() {

}

void Usuario::pagarCorrida(double valor)
{
    valorTotalPago += valor;
}

double Usuario::getValorTotalPago()
{
    return valorTotalPago;
}

// -------------------------------------
// Mapa
// -------------------------------------
class Mapa {
public:
    Mapa();

    ~Mapa();

    double distancia(int origem, int destino) const;

private:
    double quilometragem[33][33] = {
            {0, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,     0,    0}, //linha 0
            {0, 0,    7.5,  19.7, 51.8, 12.9, 12.7, 28.8, 13.8, 33.0, 31.9, 25.8, 18.8, 8.2,  12.9, 18.7, 12.6, 48.6, 33.9, 19.5, 28.7, 26.5, 23.2, 20.8, 12.1, 28.8, 12.6, 23.6, 18.0,  17.8, 18.3},//linha 1
            {0, 5.5,  0.0,  27.6, 51.2, 18.4, 18.2, 32.3, 11.2, 26.3, 37.4, 25.6, 12.1, 11.0, 18.4, 20.8, 18.1, 41.9, 39.3, 25.0, 34.2, 32.0, 25.3, 20.4, 17.5, 22.1, 9.8,  0.0,  11.3,  23.3, 20.4},//linha 2
            {0, 21,   26.9, 0,    36.6, 12.6, 9.9,  12.2, 14.5, 41.5, 33.4, 42.7, 28.4, 23.7, 11.9, 38.5, 14.1, 57.1, 12.8, 8.3,  13.1, 28,   42.6, 12.7, 10.4, 37.3, 15.6, 6.9,  27.6,  6.7,  37}, //linha 3
            {0, 50.4, 54.7, 37.6, 0.0,  51.0, 42.1, 30.1, 42.5, 67.9, 71.7, 69.2, 54.9, 55.6, 49.5, 64.5, 52.5, 83.5, 45.1, 40.6, 36.1, 66.4, 69.1, 38.7, 42.6, 63.7, 45.3, 31.2, 54.1,  34,   64.2}, //linha4
            {0, 12.6, 17.7, 11.3, 51.1, 0.0,  7.9,  26.6, 8.8,  35.8, 24.1, 33.6, 22.7, 12.3, 4.1,  26.5, 4.8,  51.3, 26.1, 8.7,  17.9, 18.7, 31.1, 17.9, 9.8,  31.5, 10.1, 21.4, 21.9,  15.1, 25.6}, //linha 5
            {0, 15.1, 20.4, 10.2, 42.3, 9.1,  0.0,  19.2, 8.7,  35.7, 29.8, 36.9, 22.6, 15,   7.3,  29.2, 10.5, 51.2, 20.6, 11.7, 20.9, 24.4, 33.8, 10.5, 4.6,  31.5, 9.8,  14,   21.8,  8.3,  28.9}, //linha 6
            {0, 29.9, 38.5, 12.9, 28,   27.8, 18.8, 0.0,  23.4, 51.7, 31.2, 53,   38.7, 34,   23.1, 48.2, 29.2, 67.3, 16.9, 18.9, 7.5,  30.2, 52.8, 17.9, 19.3, 47.5, 24.6, 7.0,  37.9,  17.8, 46.5}, //linha 7
            {0, 11.5, 15.4, 14.6, 44,   11.9, 9.1,  25.1, 0.0,  28.7, 32.6, 29.9, 15.6, 14.1, 13.6, 24.2, 13.3, 44.2, 34.6, 17.4, 23.8, 27.2, 28.8, 15,   6.9,  24.5, 2.6,  18.4, 14.8,  12.7, 23.8}, //linha 8
            {0, 29.2, 23.8, 41.7, 67.3, 37.1, 35.5, 48.3, 28.3, 0.0,  57.8, 26.4, 24.2, 34.8, 39.2, 36,   38.5, 35,   51.6, 42.7, 51.9, 52.4, 49.3, 43.4, 33,   15.2, 29.4, 42.4, 23.2,  39.8, 44.4}, //linha 9
            {0, 33.8, 38.4, 33.3, 61.5, 24.1, 30.5, 31.7, 31.3, 58.3, 0.0,  59.6, 45.3, 31.8, 24.2, 47.6, 23.9, 73.9, 18.9, 24.7, 24.2, 11.6, 42.6, 40.5, 32.4, 54.1, 32.7, 31.8, 44.5,  38.2, 42.6},//linha 10
            {0, 28.6, 23.1, 43.6, 69.4, 36.3, 36.6, 49.2, 30.3, 26.5, 57.6, 0.0,  21.3, 23.9, 37.2, 13.4, 37.8, 26.4, 59.4, 41.9, 51.1, 48.7, 26.4, 47.5, 34.9, 18.3, 31.3, 44.6, 15.8,  41.8, 21.5}, //linha 11
            {0, 15.2, 9.8,  29.4, 55.1, 27.7, 23.2, 34.9, 16,   25,   45.5, 20.3, 0.0,  23.9, 28.1, 27.3, 26.2, 40.6, 49.1, 30.4, 38.6, 40.1, 33.5, 33.2, 20.6, 20.8, 17,   30.3, 6.0,   27.5, 28.6}, //linha 12
            {0, 9.5,  11.6, 22.2, 55.7, 13,   15.2, 34.2, 18.1, 36.5, 31.9, 28.8, 22.3, 0.0,  12.9, 19.9, 12.6, 52.1, 33.9, 19.5, 28.7, 26.5, 19.8, 25.4, 17.4, 32.3, 13,   27.1, 21.5,  21.4, 14.9}, //linha 13
            {0, 14.4, 19.6, 9.7,  53,   3.3,  9.8,  22.3, 10.6, 37.6, 24.1, 38.8, 24.5, 14.2, 0.0,  29.1, 4.9,  53.2, 14.8, 6.8,  16,   18.8, 33,   14,   11.7, 33.4, 12,   17.5, 23.7,  11.6, 28}, //linha 14
            {0, 19.3, 27.9, 38.3, 66.6, 30.1, 30.3, 47.7, 31.4, 34.7, 47.7, 12.3, 28.9, 17.7, 31,   0.0,  30.7, 36.9, 49.5, 36.8, 54.8, 38.8, 16.5, 22.8, 32.5, 27,   25.2, 41.8, 22.5,  38.5, 11.5},//linha 15
            {0, 15.5, 20.6, 14.1, 50.3, 8.3,  14.8, 26.7, 16.4, 42.5, 19.3, 37.2, 29.2, 14.1, 5.4,  30,   0.0,  54.1, 20.1, 18.3, 20.4, 16.8, 30.5, 18.7, 15.4, 38.4, 16.4, 20.6, 28.3,  21.1, 25.6}, //linha 16
            {0, 46.6, 41.1, 57.5, 83.1, 52.7, 51.3, 64.1, 45,   34.4, 78.5, 26.1, 39.8, 48.2, 53.7, 37.6, 54.1, 0.0,  67.2, 81.2, 66.7, 44.5, 50.6, 47.6, 43.2, 22.4, 45,   58.2, 58.2,  59.2, 45.7}, //linha 17
            {0, 28.2, 33.3, 12.6, 46.6, 17,   21.3, 16.8, 25.7, 51.2, 16.7, 51.7, 38.3, 27.7, 14.1, 42.1, 18.6, 66.9, 0.0,  6.9,  9.3,  15.9, 43.4, 24.8, 23.7, 47.1, 25.7, 14.1, 37.5,  21.7, 39.2}, //linha 18
            {0, 32.1, 36.6, 17.2, 45.6, 18.1, 26.6, 20.1, 29.0, 54.5, 22.4, 41.4, 30.5, 19.9, 6.3,  34.3, 10.8, 29.1, 8.1,  0.0,  11.3, 24.3, 38.9, 19.3, 15.9, 39.3, 17.9, 11.5, 29.7,  15.2, 34.0},//linha 19
            {0, 30.6, 33.8, 12.2, 33.1, 18.8, 18.2, 7.7,  25.4, 51.2, 24.0, 51.1, 38.2, 29.8, 15.9, 43.9, 20.4, 66.9, 9.7,  13.9, 0.0,  23.0, 48.5, 19.6, 18.7, 47.1, 25.4, 10.1, 37.44, 17.0, 43.6},//linha 20
            {0, 27.7, 32.8, 27.8, 61.0, 18.6, 25.0, 31.2, 27.2, 52.7, 11.4, 47.0, 39.8, 26.3, 18.7, 38.1, 18.4, 68.4, 18.4, 19.0, 23.7, 0.0,  33.1, 29.0, 25.2, 49.6, 27.2, 29.6, 39.0,  34.2, 33.1},//linha 21
            {0, 22.8, 25.3, 41.7, 70.0, 33.5, 33.7, 50.9, 28.7, 46.4, 42.7, 25.0, 32.3, 18.3, 34.4, 16.1, 34.9, 49.6, 44.5, 45.0, 48.2, 33.8, 0.0,  34.6, 32.4, 39.7, 28.7, 45.7, 31.5,  41.4, 11.1},//linha 22
            {0, 15.5, 16.3, 10.7, 36.2, 13.1, 6.7,  16.1, 9.6,  33.0, 34.1, 33.5, 20.0, 19.7, 13.9, 29.6, 14.8, 48.7, 23.8, 28.1, 19.9, 28.8, 34.2, 0.0,  4.1,  28.9, 9.6,  11.5, 19.2,  10.3, 29.3},//linha 23
            {0, 12.2, 15.7, 9.8,  41.9, 10.5, 4.2,  18.9, 6.3,  33.0, 31.2, 31.8, 20.1, 15.2, 11.5, 27.9, 11.9, 48.7, 22.9, 27.2, 19.0, 25.8, 35.5, 4.4,  0.0,  28.9, 6.3,  13.6, 19.3,  9.3,  30.6},//linha 24
            {0, 25.0, 19.6, 39.9, 63.1, 32.9, 31.3, 44.1, 24.1, 14.7, 53.6, 18.3, 20.0, 30.6, 33.9, 27.9, 34.3, 23.6, 47.4, 38.5, 47.7, 48.3, 45.1, 27.6, 28.8, 0.0,  25.2, 38.3, 19.0,  62.7, 40.2},//linha 25
            {0, 7.9,  9.8,  18.0, 46.6, 12.5, 10.1, 24.7, 3.0,  30.3, 33.2, 31.5, 17.2, 13.2, 13.5, 22.0, 13.9, 45.9, 27.0, 18.1, 24.8, 27.9, 26.6, 11.1, 7.9,  26.1, 0.0,  19.4, 16.4,  46.2, 21.7},//linha 26
            {0, 24.9, 29.2, 7.8,  31.5, 18.3, 13.8, 6.3,  17.0, 42.3, 29.9, 43.7, 29.4, 29.0, 15.4, 43.2, 24.2, 58.0, 15.6, 11.1, 10.7, 28.9, 46.2, 11.9, 14.3, 38.2, 19.5, 0.0,  28.6,  31.1, 42.9},//linha 27
            {0, 14.3, 8.8,  28.5, 54.2, 27.2, 27.0, 33.9, 15.0, 19.4, 46.2, 16.2, 7.0,  23.0, 27.2, 23.2, 26.9, 49.0, 42.7, 33.8, 43.0, 40.8, 32.6, 18.7, 19.6, 14.8, 16.1, 29.1, 0.0,   26.9, 27.7},//linha 28
            {0, 19.4, 23.8, 6.0,  34.7, 13.5, 8.1,  12.4, 11.6, 37.4, 34.4, 38.2, 23.9, 21.8, 12.9, 33.6, 15.2, 52.6, 23,   0.14, 1.14, 6,    29.0, 38.1, 6.5,  8.6,  32.8, 14.4, 6.4,   23.1, 0.0, 33.2},//linha 29
            {0, 18.0, 20.6, 37.0, 65.3, 25.2, 28.9, 46.1, 23.8, 41.7, 42.8, 20.2, 27.5, 13.6, 25.2, 11.3, 51.6, 44.8, 44.6, 31.8, 57.3, 33.9, 11.6, 29.8, 298,  34.9, 23.9, 40.4, 26.7,  35.1, 0.0} //linha 30
    };
};

Mapa::Mapa() {

}

Mapa::~Mapa() {

}

double Mapa::distancia(int origem, int destino) const {
    return quilometragem[origem][destino];
}


// -------------------------------------
// Corrida
// -------------------------------------
class Corrida {
public:
    Corrida(const Mapa &mapa, const Usuario &usuario, const Motorista &motorista, int origem, int destino);

    ~Corrida();

    double calcularValor() const;

private:
    Mapa mapa;
    Usuario usuario;
    Motorista motorista;
    int origem;
    int destino;
};

Corrida::Corrida(const Mapa &mapa, const Usuario &usuario, const Motorista &motorista, int origem, int destino) :
        mapa(mapa), usuario(usuario), motorista(motorista), origem(origem), destino(destino) {

}

Corrida::~Corrida() {

}

double Corrida::calcularValor() const {
    if (origem == 4 || origem == 9 || origem == 15 || origem == 17 || origem == 21 || origem == 22 || origem == 25 ||
        origem == 28) {
        return mapa.distancia(origem, destino) * 2.0;
    }

    if (origem == 7 || origem == 10 || origem == 11 || origem == 18 || origem == 20 || origem == 23) {
        return mapa.distancia(origem, destino) * 1.9;
    }

    return mapa.distancia(origem, destino) * 1.65;
}

//--------------------------------------
// Uber
//--------------------------------------

class Uber {
public:
    Uber();

    ~Uber();

    void menuPrincipal();

private:
    void menuMotorista();

    void cadastrarMotorista();

    void menuUsuario();

    void cadastrarUsuario();

    bool opcaoMotoristaValida(int opcao);

    void visualizarDinheiroMotorista();

    void visualizarPontuacaoMotorista();

    void visualizarStatusRankingMotorista();

    void realizarCorrida();

    void acessarRota();

    void visualizarDinheiroUsuario();

    list<Motorista> listaMotorista;
    list<Usuario> listaUsuario;
};

void Uber::menuPrincipal() {
    bool sair = false;
    int opcaoSelecionada;

    while (!sair) {
        opcaoSelecionada = 0;

        cout << "Selecione: " << endl;
        cout << "1- Motorista Cadastrado" << endl;
        cout << "2- Novo Motorista" << endl;
        cout << "3- usuario Cadastrado" << endl;
        cout << "4- Novo usuario" << endl;
        cout << "5- Sair" << endl;
        cin >> opcaoSelecionada;

//        system("cls");

        switch (opcaoSelecionada) {
            case 1:
                menuMotorista();
                break;
            case 2:
                cadastrarMotorista();
                break;
            case 3:
                menuUsuario();
                break;
            case 4:
                cadastrarUsuario();
                break;
            case 5:
                sair = true;
                break;
            default:
                cerr << "Opcao invalida" << endl;
        }
    }
}

void Uber::menuMotorista() {
    int opcaoSelecionada;
    bool sair = false;

    while (!sair) {
        cout << "\nSelecione a opção desejada: " << endl;

        cout << "1. Visualizar dinheiro já obtido. " << endl;
        cout << "2. Ver minha pontuação. " << endl;
        cout << "3. Status do ranking. " << endl;
        cout << "4. Voltar " << endl;
        cin >> opcaoSelecionada;

        switch (opcaoSelecionada) {
            case 1:
                visualizarDinheiroMotorista();
                break;
            case 2:
                visualizarPontuacaoMotorista();
                break;
            case 3:
                visualizarStatusRankingMotorista();
            case 4:
                sair = true;
                break;
            default:
                cerr << "Opcao invalida" << endl;
        }
    }
}

void Uber::cadastrarMotorista() {
    string nome;
    string user;
    string senha;
    string telefone;
    string email;
    string modelo;
    float motor;
    int ano;
    string placa;
    int litros;
    string categoria;

    cout << "SEU CADASTRO: " << endl << endl;
    cout << "Nome: ";
    //cin.ignore();
    //getline(cin, nome);
    cin >> nome;

    cout << endl << "Telefone: ";
    cin >> telefone;

    cout << endl << "E-mail: ";
    cin.ignore();
    getline(cin, email);

    cout << endl << "Qual será seu user: ";
    getline(cin, user);

    cout << endl << "Senha (mínimo 4 caracteres númericos): ";
    cin >> senha;

    cout << endl << endl << "SEU CARRO: " << endl;              //opcvip - opcpop -opclight

    cout << "Modelo: ";
    cin.ignore();
    getline(cin, modelo);

    cout << endl << "Motor: ";
    cin >> motor;

    cout << endl << "Ano: ";
    cin >> ano;

    cout << endl << "Placa: ";
    cin >> placa;

    cout << endl << "Capacidade do bagageiro: (em litros)";
    cin >> litros;

    cout << endl << endl << "SEU CARRO FOI SELECIONADO NA CATEGORIA: " << endl;

    if (motor >= 1.8 && ano >= 2017) {
        cout << "OpcVip" << endl;
        categoria = "opcvip";
    } else if (litros >= 400 && motor < 1.8) {
        cout << "OpcPop" << endl;
        categoria = "opcpop";
    } else {
        cout << "OpcLight" << endl;
        categoria = "opclight";
    }

    Motorista motorista(nome, user, senha, telefone, email, modelo, motor, ano, placa, litros, categoria);
    listaMotorista.push_front(motorista);
}

void Uber::menuUsuario() {
    int opcao;
    bool sair = false;

    while (!sair) {
        cout << "Selecione a opção desejada: "<< endl;

        cout << "1. Realizar corrida. "  << endl;
        cout << "2. Acessar rota." << endl;
        cout << "3. Visualizar dinheiro já gasto. " << endl;
        cout << "4. Voltar " << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                realizarCorrida();
                break;
            case 2:
                acessarRota();
                break;
            case 3:
                visualizarDinheiroUsuario();
                break;
            case 4:
                sair = true;
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
    }
}

void Uber::cadastrarUsuario() {
    string nome;
    string usuario;
    string senha;

    cout << "SEU CADASTRO: " << endl << endl;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);

    cout << endl << "Qual será seu user: ";
    //	cin.ignore();
    getline(cin, usuario);

    cout << endl << "Senha (mínimo 4 caracteres númericos): ";
    cin >> senha;

    Usuario user(nome, usuario, senha);
    listaUsuario.push_front(user);
}

void Uber::visualizarDinheiroMotorista() {
    string user;
    cout << "Confirme o seu user: ";
    cin >> user;

    cout << "Dinheiro já obtido com as viagens que já foram realizadas: " << endl;

    for (list<Motorista>::iterator it = listaMotorista.begin(); it != listaMotorista.end(); it++) {
        if ((*it).getUser() == user) {
            cout << (*it).getNome() << ", valor já arrecadado: R$" << (*it).getValorCorridas() << endl;
        }
    }
}

void Uber::visualizarPontuacaoMotorista() {
    string user;
    cout << "Confirme o seu user: ";
    cin >> user;

    cout << "Sua pontuação: " << endl;

    for (list<Motorista>::iterator it = listaMotorista.begin(); it != listaMotorista.end(); it++) {
        if ((*it).getUser() == user) {
            cout << (*it).getNome() << ", sua avaliacao atual: " << (*it).estrelas() << endl;
        }
    }

    cout << endl;

}

void Uber::visualizarStatusRankingMotorista() {
    cout << "[IMPLEMENTAR]" << endl;
}

Uber::Uber()
{

}

Uber::~Uber()
{

}

void Uber::realizarCorrida()
{
    /*
    string nome_moto_aux;
    int cont_pos;
    double preco_aux_oficial;
    double preco_aux;
    cont_pos = 0;

    viagem:
    cout << "\tVAMOS INICIAR A CORRIDA: " << endl << endl;
    cout << "Para realizar a viagem você deve escolher o local de PARTIDA e de CHEGADA. " << endl << endl << endl;
    cout << "1. Asa sul \t         2. Asa Norte \t               3. Águas Claras " << endl;
    cout << "4. Brazlândia \t         5.Candangolândia \t       6.Guará "<< endl;
    cout << "7.Ceilândia \t         8.Cruzeiro \t               9.Fercal \t"<< endl;
    cout << "10.Gama \t         11.Itapoã  \t               12.Lago Norte \t"<< endl;
    cout << "13.Lago Sul \t         14.Nucleo Bandeirante \t       15.Paranoá \t"<< endl;
    cout << "16. Park Way \t         17.Planaltina \t               18.Recanto das Emas \t"<< endl;
    cout << "19. Riacho Fundo \t 20.Samambaia \t               21. Santa Maria \t"<< endl;
    cout << "22.São Sebastião \t 23.SCIA(Cidade Estrutural)\t24.SIA \t"<< endl;
    cout << "25.Sobradinho \t         26.Sudoeste \t               27.Taguatinga \t"<< endl;
    cout << "28.Varjão \t         29.Vicente Pires \t       30.Jardim Botânico  \t"<< endl;

    cout << endl;
    cout << "Opcional: Você deseja realizar alguma parada antes de seu destino final? (s/n)" << endl;
    cin >> op_parada;

    cout << endl;

    //	motorista_viagem();

    nome_moto_aux =motorista_viagem(); //igualando o nome escolhido a uma variavel

    cout << endl;

    if(op_parada == 's' || op_parada == 'S'){
        while(lugar_origem>30 || lugar_origem<1 ||lugar_destino>30 || lugar_destino<1){ // while de verificação
            cout << "Digite o número correspondente ao local de parada: " << endl;
            cin >> parada;
            cout << " \n\nCidade de PARTIDA: " << endl;
            cin >> lugar_origem;
            cout << " Cidade de DESTINO: " << endl;
            cin >> lugar_destino;
        }
        cout << "Quilômetros a serem percorridos: " << (quilometragem[lugar_origem][parada]) + (quilometragem[parada][lugar_destino]) << endl;
        cout << "Valor da viagem: R$ " << valor_parada(lugar_origem, lugar_destino, parada)  << endl;
        cout << "Motorista ";


        preco_aux = valor_parada(lugar_origem, lugar_destino, parada);
        it_modelo = motorista_modelo.begin();
        it_placa = motorista_placa.begin();
        it_cr_preco = motorista_cr_preco.begin();

        for(it_user= motorista_user.begin() ; it_user!= motorista_user.end() ; it_user++){
            if(nome_moto_aux== *it_user){
                cout << *it_user << endl;
                cout << "Modelo = " << *it_modelo << endl;
                cout << "Placa: " << *it_placa << endl;

                preco_aux += *it_cr_preco;

                motorista_cr_preco.insert(it_cr_preco, preco_aux);
            }
            it_modelo++;
            it_placa++;
            cont_pos++;
            it_cr_preco++;
        }



        string nome_user_aux;					//pra add o dinehro gasto do usuario
        cout << "Confirme nome de usuário : " << endl;
        cin >> nome_user_aux;
        it_cr_preco = usuario_cr_preco.begin();
        for(it_user= usuario_user.begin() ; it_user!= usuario_user.end() ; it_user++){
            if(nome_user_aux== *it_user){
                usuario_cr_preco.insert(it_cr_preco, preco_aux);
            }
            it_cr_preco++;
        }



        //	motorista_viagem();
    }




    if(op_parada == 'n' || op_parada == 'N'){
        cont_pos = 0;
        preco_aux=0;

        while(lugar_origem>30 || lugar_origem<1 ||lugar_destino>30 || lugar_destino<1){ // while de verificação
            cout << " \n\nPRIMEIRO escolha a cidade de PARTIDA: " << endl;
            cin >> lugar_origem;
            cout << " AGORA escolha a cidade de DESTINO: " << endl;
            cin >> lugar_destino;
        }

        cout << "Quilômetros a serem percorridos: " << quilometragem[lugar_origem][lugar_destino] << endl;
        quilometragem[lugar_origem][lugar_destino] = km;
        km_us.push_front(km);
        cout << "Valor da viagem: R$"  << valor_rota(lugar_origem,lugar_destino) << endl;
        cout << "Motorista: ";


        preco_aux = valor_rota(lugar_origem, lugar_destino);

        it_modelo = motorista_modelo.begin();
        it_placa = motorista_placa.begin();
        it_cr_preco = motorista_cr_preco.begin();
        for(it_user= motorista_user.begin() ; it_user!= motorista_user.end() ; it_user++){
            if(nome_moto_aux== *it_user){
                cout << *it_user << endl;
                cout << "Modelo = " << *it_modelo << endl;
                cout << "Placa: " << *it_placa << endl;

                preco_aux += *it_cr_preco;
                motorista_cr_preco.insert(it_cr_preco, preco_aux);

            }
            it_modelo++;
            it_placa++;
            cont_pos++;
            it_cr_preco++;
        }



        string nome_user_aux;					//pra add o dinehro gasto do usuario
        cout << "Confirme nome de usuário : " << endl;
        cin >> nome_user_aux;
        it_cr_preco = usuario_cr_preco.begin();
        for(it_user= usuario_user.begin() ; it_user!= usuario_user.end() ; it_user++){
            if(nome_user_aux== *it_user){
                usuario_cr_preco.insert(it_cr_preco, preco_aux);
            }
            it_cr_preco++;
        }




        for(it_user= usuario_user.begin() ; it_user!= usuario_user.end() ; it_user++){
            if(nome_user_aux== *it_user){
                motorista_cr_preco.insert(it_cr_preco, preco_aux);
            }
            it_cr_preco++;
        }
    }




    cout << endl << endl;

    cout << "Confirmar viagem? (s/n)" << endl;
    cin >> op_viagem;





    if(op_viagem == 'S' || op_viagem == 's'){
        time(&t); //para mostrar dia e hora atual
        cout << "Viagem solicitada em : ";
        cout << ctime(&t) << endl << endl;
        cout << "Seu motorista está indo até você! " << endl;

        tempo();
        cout << "Seu motorista chegou. Fique no lugar de encontro!" << endl << endl;
    }
    else {
        goto viagem;
    }

    cout << "Iniciar viagem! " << endl;
    tempo();

    cout << "Finalizar viagem!" << endl;
    cout << "Avalie seu motorista (1 a 5 estrelas): " << endl;
    cin >> estrelas;

    for(it_user= motorista_user.begin() ; it_user!= motorista_user.end() ; it_user++){
        if(nome_moto_aux== *it_user){
            estrelas_moto.insert(estrelas);	//armazenei as estrelas correspondente a cada motorista numa arvore
        }
    }

    while(estrelas <1 || estrelas>5){
        cout << "Opção não valida. Digite novamente:" << endl;
        cin >> estrelas;
        for(it_user= motorista_user.begin() ; it_user!= motorista_user.end() ; it_user++){
            if(nome_moto_aux== *it_user){
                estrelas_moto.insert(estrelas);	 //armazenei as estrelas correspondente a cada motorista numa arvore
            }
        }
    }
    cout << endl;
    cout << "Avaliação Motorista: " << estrelas << "estrelas " << endl;
     */
}

void Uber::acessarRota()
{

}

void Uber::visualizarDinheiroUsuario()
{

}

int main() {
    cout << "Uber" << endl;

    Uber user;
    user.menuPrincipal();

    return EXIT_SUCCESS;
}