#include <iostream>
#include <vector>
#include <string>
#include <utility> // Para usar pair
#include <algorithm> // Para usar find_if

using namespace std;

// Classe base (mãe)
class Time {
protected:
    string nome;
    string estadio;
    int capacidade_estadio;
    string tecnico;
    vector<pair<string, pair<int, string>>> jogadores_do_time; // Armazena nome, valor de mercado e data de término do contrato
    int total_geral; // Total geral do time

public:
    Time(string nome, string estadio, int capacidade, string tecnico, int total_geral)
        : nome(nome), estadio(estadio), capacidade_estadio(capacidade), tecnico(tecnico), total_geral(total_geral) {}

    void exibirInformacoes() {
        cout << "Time: " << nome << endl;
        cout << "Estadio: " << estadio << endl;
        cout << "Capacidade: " << capacidade_estadio << endl;
        cout << "Tecnico: " << tecnico << endl;
        cout << "Jogadores: " << endl;
        for (const auto& jogador : jogadores_do_time) {
            cout << jogador.first << " (Valor (euros): " << jogador.second.first << ", Contrato ate: " << jogador.second.second << ")" << endl;
        }
        cout << "Total Geral (euros): " << total_geral << ",00" << endl; // Exibe o total geral do time
        cout << "----------------------\n";
    }

    void adicionarJogadoresPrincipais(vector<pair<string, pair<int, string>>> jogadores) {
        jogadores_do_time = jogadores;
    }

    vector<pair<string, pair<int, string>>>& getJogadores() {
        return jogadores_do_time;
    }

    string getNome() const {
        return nome;
    }

    void adicionarJogador(const string& nomeJogador, int valor, const string& dataContrato) {
        jogadores_do_time.emplace_back(nomeJogador, make_pair(valor, dataContrato));
        total_geral += valor;
    }

    void removerJogador(const string& nomeJogador) {
        auto it = find_if(jogadores_do_time.begin(), jogadores_do_time.end(),
                          [&nomeJogador](const pair<string, pair<int, string>>& jogador) {
                              return jogador.first == nomeJogador;
                          });
        if (it != jogadores_do_time.end()) {
            total_geral -= it->second.first;
            jogadores_do_time.erase(it);
        }
    }

    void atualizarContrato(const string& nomeJogador, const string& novaData) {
        auto it = find_if(jogadores_do_time.begin(), jogadores_do_time.end(),
                          [&nomeJogador](const pair<string, pair<int, string>>& jogador) {
                              return jogador.first == nomeJogador;
                          });
        if (it != jogadores_do_time.end()) {
            it->second.second = novaData;
        }
    }

    string getDataContratoJogador(const string& nomeJogador) {
        auto it = find_if(jogadores_do_time.begin(), jogadores_do_time.end(),
                          [&nomeJogador](const pair<string, pair<int, string>>& jogador) {
                              return jogador.first == nomeJogador;
                          });
        if (it != jogadores_do_time.end()) {
            return it->second.second;
        }
        return "";
    }
};

// Classe derivada para o Atlético Mineiro
class AtleticoMG : public Time {
public:
    AtleticoMG() : Time("AtleticoMG", "Arena MRV", 46000, "Cuca", 84900000) {
        jogadores_do_time = {
            {"Everson", {1500000, "31/12/2027"}}, {"Gabriel Delfim", {200000, "31/12/2026"}}, {"Gabriel Atila", {100000, "31/12/2026"}},
            {"Junior Alonso", {6000000, "31/12/2027"}}, {"Lyanco", {3000000, "31/12/2028"}}, {"Bruno Fuchs", {2000000, "31/12/2028"}},
            {"Igor Rabello", {2000000, "31/12/2026"}}, {"Romulo", {500000, "31/12/2027"}}, {"Guilherme Arana", {13000000, "31/12/2027"}},
            {"Rubens", {4000000, "31/12/2027"}}, {"Renzo Saravia", {2000000, "31/12/2026"}}, {"Natanael", {1800000, "31/12/2028"}},
            {"Vitor Gabriel", {800000, "31/12/2027"}}, {"Fausto Vera", {5000000, "31/12/2027"}}, {"Otavio", {4000000, "30/06/2026"}},
            {"Paulo Vitor", {900000, "31/12/2027"}}, {"Vitinho", {200000, "31/12/2026"}}, {"Patrick", {100000, "31/12/2028"}},
            {"Gabriel Menino", {6000000, "31/12/2028"}}, {"Alan Franco", {3500000, "31/12/2027"}}, {"Gustavo Scarpa", {8000000, "31/12/2027"}},
            {"Igor Gomes", {3500000, "31/12/2026"}}, {"Robert Santos", {300000, "31/12/2027"}}, {"Bernard", {1800000, "31/12/2027"}},
            {"Junior Santos", {6000000, "31/12/2028"}}, {"Alisson", {4500000, "31/12/2027"}}, {"Brahian Palacios", {1500000, "31/12/2027"}},
            {"Hulk", {1500000, "31/12/2026"}}, {"Deyverson", {700000, "31/12/2027"}}, {"Cadu", {500000, "31/12/2027"}}
        };
    }
};

// Classe derivada para o Bahia
class Bahia : public Time {
public:
    Bahia() : Time("Bahia", "Arena Fonte Nova", 50025, "Renato Paiva", 88450000) {
        jogadores_do_time = {
            {"Marcos Felipe", {2500000, "31/12/2027"}}, {"Denis Junior", {650000, "31/12/2026"}}, {"Danilo Fernandes", {200000, "31/07/2025"}},
            {"Santiago Ramos Mingo", {200000, "31/12/2025"}}, {"Gabriel Xavier", {4000000, "31/12/2029"}}, {"Kanu", {3500000, "31/12/2029"}},
            {"David Duarte", {3500000, "31/12/2026"}}, {"Vitor Hugo", {1000000, "31/12/2026"}}, {"Marcos Victor", {900000, "31/12/2027"}},
            {"Iago", {3500000, "31/12/2028"}}, {"Luciano Juba", {3500000, "31/12/2027"}}, {"Ryan", {500000, "31/12/2025"}},
            {"Caio Roque", {400000, "31/12/2025"}}, {"Gilberto", {2500000, "30/06/2026"}}, {"Santiago Arias", {2200000, "31/12/2025"}},
            {"Andre Dhominique", {600000, "30/09/2027"}}, {"Douglas Borel", {350000, "31/12/2026"}}, {"Caio Alexandre", {6500000, "31/12/2028"}},
            {"Erick", {4000000, "31/12/2029"}}, {"Nikolas Acevedo", {400000, "31/12/2029"}}, {"Rezende", {800000, "31/12/2026"}},
            {"Jean Lucas", {8000000, "31/12/2028"}}, {"Rodrigo Nestor", {8000000, "31/12/2025"}}, {"Yago Felipe", {2000000, "31/12/2025"}},
            {"Leo Cittadini", {1200000, "31/12/2025"}}, {"Cauly", {5500000, "31/12/2028"}}, {"Everton Ribeiro", {1800000, "31/12/2025"}},
            {"Biel", {5000000, "31/12/2029"}}, {"Erick Pulga", {2000000, "31/12/2029"}}, {"Michel Araujo", {1500000, "31/12/2028"}},
            {"Ademir", {1500000, "31/12/2025"}}, {"Luciano Rodriguez", {7500000, "30/06/2029"}}, {"Willian Jose", {2000000, "31/12/2026"}},
            {"Everaldo", {550000, "31/12/2025"}}, {"Everton Morais", {200000, "31/12/2026"}}
        };
    }
};

// Classe derivada para o Botafogo
class Botafogo : public Time {
public:
    Botafogo() : Time("Botafogo", "Nilton Santos", 46931, "Luis Castro", 98500000) {
        jogadores_do_time = {
            {"John Victor", {7000000, "31/12/2027"}}, {"Raul", {1000000, "31/12/2026"}}, {"Alexander Barboza", {100000, "31/12/2025"}},
            {"Lucas Halter", {5000000, "31/12/2028"}}, {"Luis Segovia", {2500000, "31/12/2027"}}, {"Bastos", {1200000, "31/12/2026"}},
            {"Philippe Sampaio", {1000000, "31/12/2025"}}, {"Alex Telles", {450000, "31/12/2026"}}, {"Cuibaiano", {5000000, "31/12/2028"}},
            {"Vithino", {4500000, "31/12/2027"}}, {"Mateo Ponte", {6000000, "31/12/2029"}}, {"Marlon Freitas", {3000000, "31/12/2028"}},
            {"Gregore", {3000000, "31/12/2027"}}, {"Danilo Barbosa", {1200000, "31/12/2026"}}, {"Allan", {1000000, "31/12/2025"}},
            {"Patrick de Paula", {250000, "31/12/2026"}}, {"Kaua", {9000000, "31/12/2029"}}, {"Newton", {7000000, "31/12/2028"}},
            {"Jefferson Savarino", {5000000, "31/12/2027"}}, {"Matheus Martins", {8000000, "31/12/2028"}}, {"Jeffinho", {1300000, "31/12/2026"}},
            {"Artur", {15000000, "31/12/2029"}}, {"Carlos Alberto", {5000000, "31/12/2027"}}, {"Igor Jesus", {500000, "31/12/2025"}},
            {"Matheus Nascimento", {5000000, "31/12/2028"}}, {"Valentin Adamo", {500000, "31/12/2026"}}
        };
    }
};

// Classe derivada para o Ceará
class Ceara : public Time {
public:
    Ceara() : Time("Ceará", "Castelao", 63903, "Guto Ferreira", 20900000) {
        jogadores_do_time = {
            {"Keiller", {1300000, "31/12/2025"}}, {"Bruno", {300000, "31/12/2025"}}, {"Richard Costa", {250000, "31/12/2025"}},
            {"Fernando Miguel", {100000, "31/12/2025"}}, {"David Ricardo", {1000000, "31/12/2025"}}, {"Eder", {650000, "31/12/2025"}},
            {"Willian Machado", {600000, "31/12/2027"}}, {"Gabriel Lacerda", {550000, "31/12/2025"}}, {"Marllon", {450000, "31/12/2026"}},
            {"Ramon Menezes", {400000, "31/12/2025"}}, {"Luiz Otavio", {100000, "31/12/2025"}}, {"Matheus Bahia", {1300000, "31/12/2025"}},
            {"Nicolas", {1200000, "31/12/2025"}}, {"Eric", {100000, "30/06/2025"}}, {"Fabinho", {1500000, "31/12/2026"}},
            {"Dieguinho", {1000000, "31/12/2026"}}, {"Rafael Ramos", {500000, "31/12/2026"}}, {"Bruno Tubarao", {450000, "31/12/2025"}},
            {"Richardson", {250000, "31/12/2026"}}, {"Fernando Sobral", {1800000, "31/12/2025"}}, {"Lourenço", {1200000, "31/12/2025"}},
            {"Matheus Araujo", {2000000, "31/12/2027"}}, {"Jorge Recalde", {550000, "31/12/2025"}}, {"Lucas Mugni", {300000, "31/12/2025"}},
            {"Fernandinho", {600000, "31/12/2026"}}, {"Joao Victor", {150000, "31/12/2025"}}, {"Antonio Galeano", {150000, "31/12/2025"}},
            {"Pedro Henrique", {1500000, "31/12/2025"}}, {"Aylon", {350000, "31/12/2025"}}, {"Kaique", {300000, "31/12/2025"}}
        };
    }
};

// Classe derivada para o Corinthians
class Corinthians : public Time {
public:
    Corinthians() : Time("Corinthians", "Arena Corinthians", 49205, "Ramon Diaz", 102300000) {
        jogadores_do_time = {
            {"Felix Torres", {2000000, "31/12/2028"}}, {"Caca", {1000000, "30/06/2028"}}, {"Andre Ramalho", {2000000, "31/12/2027"}},
            {"Gustavo Henrique", {1000000, "31/12/2028"}}, {"Tchoca", {500000, "31/12/2026"}}, {"Renato Santos", {200000, "31/12/2025"}},
            {"Matheus Bidu", {2500000, "31/12/2025"}}, {"Diego Palacios", {1200000, "31/12/2027"}}, {"Hugo", {8000000, "31/12/2026"}},
            {"Matheuzinho", {3000000, "31/12/2028"}}, {"Leo Mana", {1000000, "31/12/2029"}}, {"Raniele", {800000, "31/12/2028"}},
            {"Jose Martinez", {750000, "31/12/2027"}}, {"Ryan", {650000, "31/12/2028"}}, {"Breno Bidon", {1200000, "31/12/2029"}},
            {"Maycon", {2100000, "31/12/2025"}}, {"Alex Santana", {2700000, "31/12/2027"}}, {"Charles", {2900000, "31/12/2028"}},
            {"Andre Carrillo", {3000000, "31/12/2026"}}, {"Rodrigo Garro", {14000000, "31/12/2028"}}, {"Igor Coronado", {4000000, "31/12/2026"}},
            {"Talles Magno", {5000000, "01/07/2025"}}, {"Angel Romero", {2500000, "31/12/2025"}}, {"Kayke", {3500000, "30/06/2027"}},
            {"Yuri Alberto", {14000000, "31/12/2027"}}, {"Memphis Depay", {10000000, "31/12/2026"}}, {"Giovane", {6000000, "30/06/2025"}},
            {"Pedro Raul", {5000000, "31/12/2028"}}, {"Hector Hernández", {1800000, "31/12/2026"}}
        };
    }
};

// Classe derivada para o Cruzeiro
class Cruzeiro : public Time {
public:
    Cruzeiro() : Time("Cruzeiro", "Mineirão", 61846, "Paulo Pezzolano", 90060000) {
        jogadores_do_time = {
            {"Cássio", {300000, "31/05/2027"}}, {"Léo Aragão", {50000, "31/12/2026"}}, {"Otávio Costa", {10000, "31/12/2028"}},
            {"Fabrício Bruno", {7000000, "31/12/2028"}}, {"João Marcelo", {5500000, "31/12/2028"}}, {"Lucas Villalba", {1800000, "31/12/2026"}},
            {"Jonathan Jesus", {300000, "31/12/2029"}}, {"Marlon", {5500000, "31/12/2026"}}, {"Kaiki", {1500000, "31/12/2027"}},
            {"William", {1500000, "31/12/2026"}}, {"Helibelton Palacios", {5000000, "31/12/2025"}}, {"Fagner", {1500000, "31/12/2025"}},
            {"Walace", {5000000, "31/12/2028"}}, {"Lucas Romero", {900000, "31/12/2025"}}, {"Fabrizio Peralta", {3500000, "30/06/2029"}},
            {"Lucas Silva", {700000, "31/12/2026"}}, {"Matheus Henrique", {8000000, "30/06/2029"}}, {"Christian", {7000000, "31/12/2027"}},
            {"Japa", {300000, "31/12/2027"}}, {"Jhosefer", {200000, "31/12/2026"}}, {"Matheus Pereira", {10000000, "30/06/2026"}},
            {"Eduardo", {900000, "31/12/2025"}}, {"Dudu", {3000000, "31/12/2027"}}, {"Rodriguinho", {600000, "31/12/2027"}},
            {"Yannick Bolasie", {250000, "31/12/2025"}}, {"Marquinhos", {6000000, "31/12/2025"}}, {"Tevis", {4500000, "31/12/2026"}},
            {"Gabriel Barbosa", {3000000, "31/12/2028"}}, {"Kaio Jorge", {1500000, "31/12/2028"}}, {"Juan Dinnenno", {250000, "31/12/2025"}},
            {"Lautaro Diaz", {4500000, "30/06/2028"}}
        };
    }
};

// Classe derivada para o Flamengo
class Flamengo : public Time {
public:
    Flamengo() : Time("Flamengo", "Maracana", 78838, "Filipe Luis", 214250000) {
        jogadores_do_time = {
            {"Agustin Rossi", {7000000, "31/12/2027"}}, {"Matheus Cunha", {3000000, "31/12/2025"}}, {"Dyogo Alves", {300000, "31/12/2026"}},
            {"Leo Ortiz", {11000000, "31/12/2028"}}, {"Leo Pereira", {9000000, "31/12/2027"}}, {"Danilo", {4000000, "31/12/2026"}},
            {"Pablo", {900000, "31/12/2025"}}, {"Cleiton", {600000, "31/12/2025"}}, {"Ayrton Lucas", {8000000, "31/12/2028"}},
            {"Alex Sandro", {1800000, "31/12/2027"}}, {"Matias Vina", {10000000, "31/12/2028"}}, {"Ze Welinton", {250000, "31/12/2025"}},
            {"Wesley", {9000000, "31/12/2028"}}, {"Guillermo Varela", {1500000, "31/12/2025"}}, {"Erick Pulgar", {5000000, "31/12/2025"}},
            {"Allan", {5000000, "31/12/2027"}}, {"Evertton Araujo", {5000000, "31/12/2028"}}, {"Caio Garcia", {100000, "31/12/2026"}},
            {"Gerson", {20000000, "31/12/2027"}}, {"Nicolás de la Cruz", {18000000, "30/06/2028"}}, {"Carlos Alcaraz", {14000000, "30/12/2029"}},
            {"Giorgian de Arrascaeta", {14000000, "31/12/2026"}}, {"Lorran", {12000000, "31/12/2029"}}, {"Everton", {9000000, "30/06/2026"}},
            {"Michael", {7000000, "31/12/2028"}}, {"Bruno Henrique", {1200000, "31/12/2026"}}, {"Gonzalo Plata", {6000000, "30/06/2029"}},
            {"Luiz Araujo", {4000000, "31/12/2027"}}, {"Matheus Gonçalves", {700000, "31/12/2027"}}, {"Thiaguinho", {1200000, "31/12/2025"}},
            {"Pedro", {23000000, "31/12/2027"}}, {"Juninho", {2000000, "31/12/2028"}}, {"Carlinhos", {700000, "31/12/2026"}}
        };
    }
};

// Classe derivada para o Fluminense
class Fluminense : public Time {
public:
    Fluminense() : Time("Fluminense", "Maracana", 78838, "Mano Menezes", 77220000) {
        jogadores_do_time = {
            {"Pedro Rangel", {600000, "31/12/2026"}}, {"Vitor Eudes", {400000, "31/12/2027"}}, {"Marcelo Pitaluga", {200000, "31/12/2028"}},
            {"Fábio", {100000, "31/12/2025"}}, {"Gustavo Ramalho", {100000, "31/12/2025"}}, {"Ignacio", {1200000, "30/06/2028"}},
            {"Felipe Andrade", {1000000, "31/12/2025"}}, {"Juan Pablo Freytes", {900000, "31/12/2028"}}, {"Thiago Silva", {800000, "30/06/2026"}},
            {"Manoel", {200000, "31/12/2025"}}, {"Thiago Santos", {200000, "31/12/2025"}}, {"Esquerdinha", {3000000, "31/12/2026"}},
            {"Gabriel Fuentes", {1500000, "31/12/2028"}}, {"Renê", {800000, "31/12/2026"}}, {"Guga", {2000000, "31/12/2026"}},
            {"Samuel Xavier", {350000, "31/12/2025"}}, {"Facundo Bernal", {1500000, "31/07/2028"}}, {"Wallace Davi", {20000, "30/04/2027"}},
            {"Martinelli", {9000000, "31/12/2026"}}, {"Hércules", {6000000, "31/12/2029"}}, {"Nonato", {1200000, "30/06/2025"}},
            {"Renato Augusto", {700000, "31/12/2025"}}, {"Victor Hugo", {200000, "30/06/2025"}}, {"Gustavo Apis", {30000, "31/12/2025"}},
            {"Lima", {2500000, "31/12/2025"}}, {"Ganso", {500000, "31/12/2025"}}, {"Isaque", {20000, "31/12/2028"}},
            {"Agustín Canobbio", {4500000, "31/12/2029"}}, {"Joaquín Lavega", {2800000, "31/12/2029"}}, {"Keno", {600000, "31/12/2025"}},
            {"Paulo Baya", {5500000, "30/06/2026"}}, {"Jhon Arias", {16000000, "31/12/2027"}}, {"Kevin Serna", {1200000, "31/12/2025"}},
            {"Riquelme", {400000, "31/12/2029"}}, {"Kauã Elias", {9000000, "31/12/2029"}}, {"Lelê", {1200000, "31/12/2028"}},
            {"Germán Cano", {1000000, "31/12/2025"}}
        };
    }
};

// Classe derivada para o Fortaleza
class Fortaleza : public Time {
public:
    Fortaleza() : Time("Fortaleza", "Castelao", 63903, "Juan Pablo Vojvoda", 56780000) {
        jogadores_do_time = {
            {"Brenno", {1000000, "31/12/2027"}}, {"Santos", {800000, "31/12/2026"}}, {"João Ricardo", {500000, "31/12/2027"}},
            {"Magrão", {300000, "31/12/2026"}}, {"Gastón Ávila", {4000000, "31/12/2025"}}, {"Benjamin Kuscevic", {2000000, "31/12/2028"}},
            {"Tomás Cardona", {1800000, "31/12/2026"}}, {"Marcelo Benevenuto", {1700000, "31/12/2026"}}, {"Tobias Figueiredo", {1500000, "31/12/2026"}},
            {"Emanuel Brítez", {1000000, "31/12/2025"}}, {"Brayan Ceballos", {800000, "31/12/2026"}}, {"David Luiz", {300000, "31/12/2026"}},
            {"Titi", {200000, "31/12/2025"}}, {"Felipe Jonatan", {2500000, "30/04/2027"}}, {"Bruno Pacheco", {400000, "31/12/2026"}},
            {"Diogo Barbosa", {3500000, "31/12/2026"}}, {"Eros Mancuso", {4000000, "10/08/2028"}}, {"Tinga", {1200000, "30/04/2026"}},
            {"Zé Welison", {2000000, "31/12/2026"}}, {"Lucas Sasha", {300000, "31/12/2025"}}, {"Pedro Augusto", {1800000, "31/12/2026"}},
            {"Matheus Rossetto", {1500000, "31/12/2027"}}, {"Pol Fernández", {1300000, "31/12/2026"}}, {"Kauan", {1000000, "30/06/2028"}},
            {"Tomás Pochettino", {6000000, "31/12/2025"}}, {"Calebe", {2000000, "31/12/2028"}}, {"Emmanuel Martínez", {1500000, "30/06/2027"}},
            {"Kervin Andrade", {1500000, "31/12/2028"}}, {"Edinho", {550000, "31/12/2025"}}, {"Moises", {2500000, "31/12/2027"}},
            {"Breno Lopes", {2500000, "31/12/2028"}}, {"Dylan Borrero", {1000000, "31/12/2028"}}, {"Yago Pikachu", {500000, "31/12/2025"}},
            {"Marinho", {30000, "31/12/2025"}}, {"Bruno Branco", {1500000, "31/12/2025"}}, {"Juan Martín Lucero", {1000000, "31/12/2025"}},
            {"Renato Kayzer", {500000, "31/12/2025"}}
        };
    }
};

// Classe derivada para o Grêmio
class Gremio : public Time {
public:
    Gremio() : Time("Gremio", "Arena do Gremio", 60540, "Gustavo Quinteros", 82500000) {
        jogadores_do_time = {
            {"Adriel", {1200000, "31/12/2025"}}, {"Tiago Volpi", {1000000, "31/12/2026"}}, {"Gabriel Grando", {1000000, "31/12/2026"}},
            {"Gustavo Martins", {3000000, "31/12/2027"}}, {"Rodrigo Ely", {2500000, "31/12/2026"}}, {"Nata", {1300000, "31/12/2026"}},
            {"Jermerson", {1200000, "31/12/2026"}}, {"Walter Kannemann", {600000, "31/12/2025"}}, {"Mayk", {500000, "31/12/2026"}},
            {"João Pedro", {4000000, "31/12/2025"}}, {"João Lucas", {2000000, "31/12/2028"}}, {"Igor Serrote", {800000, "31/12/2025"}},
            {"Mathías Villasanti", {10000000, "31/12/2028"}}, {"Gustavo Cuéllar", {3500000, "31/12/2026"}}, {"Ronald", {2000000, "31/12/2027"}},
            {"Dodi", {700000, "31/12/2026"}}, {"Lucas Milla", {500000, "31/12/2025"}}, {"Pepe", {3000000, "31/12/2025"}},
            {"Edenílson", {900000, "31/12/2025"}}, {"Franco Cristaldo", {10000000, "31/12/2026"}}, {"Miguel Gonsalve", {6000000, "31/12/2028"}},
            {"Gabriel Silva", {900000, "31/12/2025"}}, {"Nathan", {900000, "31/12/2025"}}, {"Alexander Aravena", {6000000, "31/12/2028"}},
            {"Nathan Fernandes", {6000000, "30/06/2028"}}, {"Cristian Pavon", {3000000, "31/12/2026"}}, {"Matias Arezo", {6000000, "31/12/2028"}},
            {"Martin Braithwaite", {3000000, "30/06/2026"}}, {"Andre Henrique", {1000000, "31/12/2026"}}
        };
    }
};

// Classe derivada para o Internacional
class Internacional : public Time {
public:
    Internacional() : Time("Internacional", "Beira-Rio", 50000, "Roger Machado", 98320000) {
        jogadores_do_time = {
            {"Sergio Rochet", {4000000, "31/12/2026"}}, {"Ivan", {1300000, "31/12/2026"}}, {"Anthonio", {800000, "31/12/2026"}},
            {"Kauan", {300000, "31/12/2026"}}, {"Vitao", {9000000, "31/12/2026"}}, {"Kaique Rocha", {3000000, "31/12/2027"}},
            {"Clayton", {1000000, "31/12/2028"}}, {"Agustin Rogel", {600000, "30/06/2025"}}, {"Gabriel Mercado", {200000, "31/12/2025"}},
            {"Victor Gabriel", {100000, "31/12/2025"}}, {"Pedro Kaua", {30000, "31/12/2025"}}, {"Alexandro Bernabei", {6000000, "31/12/2028"}},
            {"Pablo", {40000, "31/12/2025"}}, {"Nathan", {2000000, "30/06/2025"}}, {"Braian Aguirre", {1700000, "31/12/2027"}},
            {"Bruno Gomes", {6000000, "31/12/2027"}}, {"Thiago Maia", {6000000, "31/12/2026"}}, {"Fernando", {1000000, "31/12/2025"}},
            {"Ronaldo", {700000, "31/12/2025"}}, {"Luis Otavio", {400000, "31/12/2025"}}, {"Bernardo Jacob", {40000, "31/12/2025"}},
            {"Gustavo", {500000, "31/12/2025"}}, {"Gustavo Prado", {500000, "31/12/2025"}}, {"Bruno Henrique", {400000, "31/12/2025"}},
            {"Gabriel Carvalho", {12000000, "31/12/2027"}}, {"Alan Patrick", {3500000, "31/12/2025"}}, {"Yago Noal", {10000, "31/12/2026"}},
            {"Wesley", {8000000, "31/12/2026"}}, {"Vitinho", {6500000, "31/12/2026"}}, {"Wanderson", {6000000, "31/12/2026"}},
            {"Jhoan Carbonero", {2000000, "31/12/2026"}}, {"Bruno Tabata", {2500000, "31/12/2027"}}, {"Marlon", {50000, "31/12/2027"}},
            {"Rafael Borre", {8000000, "31/12/2027"}}, {"Enner Valencia", {2000000, "31/12/2027"}}, {"Lucca", {1000000, "31/12/2027"}},
            {"Ricardo Mathias", {1000000, "31/12/2027"}}, {"Lucca Drummond", {150000, "31/12/2027"}}
        };
    }
};

// Classe derivada para o Sport
class Sport : public Time {
public:
    Sport() : Time("Sport", "Ilha do Retiro", 32983, "Pepa", 21280000) {
        jogadores_do_time = {
            {"Caique França", {450000, "31/12/2027"}}, {"Thiago Couto", {300000, "31/12/2027"}}, {"Denis", {100000, "31/12/2025"}},
            {"Antonio Carlos", {1000000, "31/12/2025"}}, {"Rafael Thyere", {600000, "31/12/2025"}}, {"Chico", {600000, "31/12/2026"}},
            {"Renzo", {150000, "31/12/2025"}}, {"Marcelo Ajul", {30000, "31/12/2025"}}, {"Dalbert", {750000, "31/12/2025"}},
            {"Igor Carius", {400000, "31/12/2025"}}, {"Matheus Alexandre", {1500000, "31/12/2028"}}, {"Leonel Di Placido", {450000, "30/06/2025"}},
            {"Hereda", {250000, "31/12/2025"}}, {"Fabricio Dominguez", {1000000, "31/12/2027"}}, {"Hyoran", {1500000, "31/12/2025"}},
            {"Christian Ortiz", {700000, "31/12/2025"}}, {"Lucas Lima", {550000, "31/12/2026"}}, {"Lenny Lobato", {750000, "30/06/2025"}},
            {"Gustavo Maia", {450000, "31/12/2026"}}, {"Rodrigo Atencio", {3500000, "31/12/2029"}}, {"Barletta", {1500000, "31/12/2028"}},
            {"Romarinho", {1000000, "31/12/2026"}}, {"Gustavo Coutinho", {1600000, "31/12/2027"}}, {"Gonçalo Paciência", {1200000, "31/12/2025"}},
            {"Zé Roberto", {900000, "31/12/2025"}}, {"Dieguinho", {50000, "31/12/2025"}}
        };
    }
};



// Função para verificar se o ano da nova data é maior que o ano da data atual
bool validarNovaData(const string& dataAtual, const string& novaData) {
    int anoAtual = stoi(dataAtual.substr(6, 4));
    int anoNovo = stoi(novaData.substr(6, 4));
    return anoNovo > anoAtual;
}

// Função para verificar se um time existe
Time* encontrarTimePorNome(vector<Time*>& times, const string& nome) {
    for (auto& time : times) {
        if (time->getNome() == nome) {
            return time;
        }
    }
    return nullptr;
}

// Função para verificar se um jogador existe em um time
bool jogadorExisteNoTime(Time* time, const string& nomeJogador) {
    auto& jogadores = time->getJogadores();
    return any_of(jogadores.begin(), jogadores.end(),
                  [&nomeJogador](const pair<string, pair<int, string>>& jogador) {
                      return jogador.first == nomeJogador;
                  });
}

// Função para contratar um jogador
void contratarJogador(vector<Time*>& times) {
    string timeVendedor, jogador, timeComprador, dataContrato;
    cout << "Digite o nome do time que vai vender o jogador: ";
    cin >> timeVendedor;
    Time* timeV = encontrarTimePorNome(times, timeVendedor);
    if (!timeV) {
        cout << "Time nao encontrado. Deseja tentar novamente? (s/n): ";
        char opcao;
        cin >> opcao;
        if (opcao == 's') contratarJogador(times);
        return;
    }

    cout << "Digite o nome do jogador: ";
    cin >> jogador;
    if (!jogadorExisteNoTime(timeV, jogador)) {
        cout << "Jogador nao encontrado. Deseja tentar novamente? (s/n): ";
        char opcao;
        cin >> opcao;
        if (opcao == 's') contratarJogador(times);
        return;
    }

    cout << "Digite o nome do time que vai contratar o jogador: ";
    cin >> timeComprador;
    Time* timeC = encontrarTimePorNome(times, timeComprador);
    if (!timeC) {
        cout << "Time nao encontrado. Deseja tentar novamente? (s/n): ";
        char opcao;
        cin >> opcao;
        if (opcao == 's') contratarJogador(times);
        return;
    }

    cout << "Digite a nova data de contrato (dd/mm/aaaa): ";
    cin >> dataContrato;
    // Aqui você pode adicionar validações para a data

    // Transferir jogador
    auto& jogadoresVendedor = timeV->getJogadores();
    auto it = find_if(jogadoresVendedor.begin(), jogadoresVendedor.end(),
                      [&jogador](const pair<string, pair<int, string>>& j) {
                          return j.first == jogador;
                      });
    if (it != jogadoresVendedor.end()) {
        int valorJogador = it->second.first;
        timeC->adicionarJogador(jogador, valorJogador, dataContrato);
        timeV->removerJogador(jogador);
        cout << "Jogador transferido com sucesso!\n";
    }
}

// Função para trocar jogadores
void trocarJogadores(vector<Time*>& times) {
    string time1, jogador1, time2, jogador2, dataContrato1, dataContrato2;
    cout << "Digite o nome do primeiro time: ";
    cin >> time1;
    Time* t1 = encontrarTimePorNome(times, time1);
    if (!t1) {
        cout << "Time nao encontrado. Deseja tentar novamente? (s/n): ";
        char opcao;
        cin >> opcao;
        if (opcao == 's') trocarJogadores(times);
        return;
    }

    cout << "Digite o nome do jogador do primeiro time: ";
    cin >> jogador1;
    if (!jogadorExisteNoTime(t1, jogador1)) {
        cout << "Jogador nao encontrado. Deseja tentar novamente? (s/n): ";
        char opcao;
        cin >> opcao;
        if (opcao == 's') trocarJogadores(times);
        return;
    }

    cout << "Digite o nome do segundo time: ";
    cin >> time2;
    Time* t2 = encontrarTimePorNome(times, time2);
    if (!t2) {
        cout << "Time nao encontrado. Deseja tentar novamente? (s/n): ";
        char opcao;
        cin >> opcao;
        if (opcao == 's') trocarJogadores(times);
        return;
    }

    cout << "Digite o nome do jogador do segundo time: ";
    cin >> jogador2;
    if (!jogadorExisteNoTime(t2, jogador2)) {
        cout << "Jogador nao encontrado. Deseja tentar novamente? (s/n): ";
        char opcao;
        cin >> opcao;
        if (opcao == 's') trocarJogadores(times);
        return;
    }

    cout << "Digite a nova data de contrato para o jogador do primeiro time (dd/mm/aaaa): ";
    cin >> dataContrato1;
    cout << "Digite a nova data de contrato para o jogador do segundo time (dd/mm/aaaa): ";
    cin >> dataContrato2;

    // Trocar jogadores
    auto& jogadoresT1 = t1->getJogadores();
    auto& jogadoresT2 = t2->getJogadores();
    auto it1 = find_if(jogadoresT1.begin(), jogadoresT1.end(),
                       [&jogador1](const pair<string, pair<int, string>>& j) {
                           return j.first == jogador1;
                       });
    auto it2 = find_if(jogadoresT2.begin(), jogadoresT2.end(),
                       [&jogador2](const pair<string, pair<int, string>>& j) {
                           return j.first == jogador2;
                       });

    if (it1 != jogadoresT1.end() && it2 != jogadoresT2.end()) {
        int valorJogador1 = it1->second.first;
        int valorJogador2 = it2->second.first;

        t1->removerJogador(jogador1);
        t2->removerJogador(jogador2);

        t1->adicionarJogador(jogador2, valorJogador2, dataContrato2);
        t2->adicionarJogador(jogador1, valorJogador1, dataContrato1);

        cout << "Jogadores trocados com sucesso!\n";
    }
}

// Função para renovar contrato
void renovarContrato(vector<Time*>& times) {
    string time, jogador, novaData;
    cout << "Digite o nome do time: ";
    cin >> time;
    Time* t = encontrarTimePorNome(times, time);
    if (!t) {
        cout << "Time nao encontrado. Deseja tentar novamente? (s/n): ";
        char opcao;
        cin >> opcao;
        if (opcao == 's') renovarContrato(times);
        return;
    }

    cout << "Digite o nome do jogador: ";
    cin >> jogador;
    if (!jogadorExisteNoTime(t, jogador)) {
        cout << "Jogador nao encontrado. Deseja tentar novamente? (s/n): ";
        char opcao;
        cin >> opcao;
        if (opcao == 's') renovarContrato(times);
        return;
    }

    string dataAtual = t->getDataContratoJogador(jogador);
    while (true) {
        cout << "Digite a nova data de contrato (dd/mm/aaaa): ";
        cin >> novaData;
        if (validarNovaData(dataAtual, novaData)) {
            break;
        }
        cout << "Ano invalido! O ano deve ser maior que " << dataAtual.substr(6, 4) << ". Tente novamente.\n";
    }

    t->atualizarContrato(jogador, novaData);
    cout << "Contrato renovado com sucesso!\n";
}

// Função para receber informações do time
void receberInformacaoTime(vector<Time*>& times) {
    string time;
    cout << "Digite o nome do time: ";
    cin >> time;
    Time* t = encontrarTimePorNome(times, time);
    if (!t) {
        cout << "Time nao encontrado. Deseja tentar novamente? (s/n): ";
        char opcao;
        cin >> opcao;
        if (opcao == 's') receberInformacaoTime(times);
        return;
    }

    t->exibirInformacoes();
}

int main() {
    // Criando instâncias dos times
    AtleticoMG atletico;
    Bahia bahia;
    Botafogo botafogo;
    Ceara ceara;
    Corinthians corinthians;
    Cruzeiro cruzeiro;
    Flamengo flamengo;
    Fluminense fluminense;
    Fortaleza fortaleza;
    Gremio gremio;
    Internacional internacional;
    Sport sport;

    vector<Time*> times = {&atletico, &bahia, &botafogo, &ceara, &corinthians, &cruzeiro, &flamengo, &fluminense, &fortaleza, &gremio, &internacional, &sport};

    while (true) {
        cout << "Escolha uma opcao:\n";
        cout << "1. Contratar Jogador\n";
        cout << "2. Troca de Jogadores\n";
        cout << "3. Renovar Contrato\n";
        cout << "4. Receber Informacao do Time\n";
        cout << "5. Sair\n";
        int opcao;
        cin >> opcao;

        switch (opcao) {
            case 1:
                contratarJogador(times);
                break;
            case 2:
                trocarJogadores(times);
                break;
            case 3:
                renovarContrato(times);
                break;
            case 4:
                receberInformacaoTime(times);
                break;
            case 5:
                return 0;
            default:
                cout << "Opcao invalida. Deseja tentar novamente? (s/n): ";
                char opcao;
                cin >> opcao;
                if (opcao != 's') return 0;
                break;
        }
    }

    return 0;
}