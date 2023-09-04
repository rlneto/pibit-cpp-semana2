#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <locale>

using namespace std;

int main() {
  setlocale(LC_ALL, "Portuguese");
  srand(time(nullptr));
  int vida, bonus, dano, armadura, classe;
  string nome, nome_classe;
  cout << "Digite o nome do personagem: ";
  cin >> nome;
  cout << "Escolha uma das classes de personagem: " << endl;
  cout << "1 - Guerreiro" << endl;
  cout << "2 - Bárbaro" << endl;
  cout << "3 - Arqueiro" << endl;
  cout << "4 - Ladino" << endl;
  cin >> classe;
  switch (classe) {
    case 1:
      vida = 100;
      bonus = 2;
      dano = 10;
      armadura = 10;
      nome_classe = "Guerreiro";
      break;
    case 2:
      vida = 120;
      bonus = 1;
      dano = 12;
      armadura = 5;
      nome_classe = "Bárbaro";
      break;
    case 3:
      vida = 80;
      bonus = 2;
      dano = 6;
      armadura = 10;
      nome_classe = "Arqueiro";
      break;
    case 4:
      vida = 80;
      bonus = 0;
      dano = 18;
      armadura = 10;
      nome_classe = "Ladino";
      break;
    default:
      cout << "Opção inválida!" << endl;
      break;
  }
  cout << nome << "é um " << nome_classe << ", incumbido de salvar o filho de um camponês em uma caverna de goblins." << endl;
  cout << "Sua aventura começa indo em direção a uma floresta." << endl;
  cout << "Você está andando pela floresta e encontra um orc sedento por sangue!" << endl;
  cout << "Combate!" << endl;
  int vida_orc = 100;
  int dano_orc = 8;
  int armadura_orc = 10;
  int bonus_orc = 0;
  int dado = rand() % 20 + 1;
  int rodada = 1;
  while (vida_orc > 0 and vida > 0) {
    cout << "Rodada " << rodada << endl;
    cout << "O Orc ataca!" << endl;
    dado = rand() % 20 + 1 + bonus_orc;
    cout << "O Orc rolou " << (dado - bonus_orc) << " no dado." << endl;
    if (dado > armadura) {
      cout << "O Orc acertou!" << endl;
      cout << "O Orc causou " << dano_orc << " de dano." << endl;
      vida -= dano_orc;
      cout << "Você tem " << vida << " de vida." << endl;
    } else {
      cout << "O Orc errou!" << endl;
    }
    if (vida <= 0) {
      break;
    }
    cout << "Você ataca!" << endl;
    dado = rand() % 20 + 1 + bonus;
    cout << "Você rolou " << (dado - bonus) << " no dado." << endl;
    if (dado > armadura_orc) {
      cout << "Você acertou!" << endl;
      cout << "Você causou " << dano << " de dano." << endl;
      vida_orc -= dano;
      cout << "O Orc tem " << vida_orc << " de vida." << endl;
    } else {
      cout << "Você errou!" << endl;
    }
    rodada++;
  }
  if (vida_orc <= 0) {
    cout << "Você venceu!" << endl;
    cout << "No orc você encontra " << rand() % 20 + 1 << " moedas de cobre e um machado de batalha." << endl;
  } else {
    cout << "Você morreu! Sua história será lembrada na vila..." << endl;
  }

  return 0;
}
