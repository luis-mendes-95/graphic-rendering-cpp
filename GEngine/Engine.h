/**********************************************************************************
// Engine (Arquivo de Cabe�alho)
//
//
// Descri��o:   A fun��o da Engine � rodar jogos criados a partir da classe
//              abstrata Game. Todo jogo deve ser uma classe derivada de Game
//              e portanto deve implementar as fun��es membro:
//                
//              Init, Update, Draw e Finalize,
//               
//              que ser�o chamadas pelo motor em um la�o de tempo real.
//              Para usar a classe Engine, o programador deve criar uma inst�ncia
//              e chamar o m�todo Start(), passando um objeto derivado de Game.
//
**********************************************************************************/

#ifndef _PROGJOGOS_ENGINE_H_
#define _PROGJOGOS_ENGINE_H_

// ---------------------------------------------------------------------------------

#include "Game.h"                       // implementa��o do jogo
#include "Window.h"                     // janela do jogo

// ---------------------------------------------------------------------------------

class Engine
{
private:
    int Loop();                         // inicia o la�o de tempo real

public:
    static Game* game;               // jogo a ser executado
    static Window* window;             // janela do jogo

    Engine();                           // construtor
    ~Engine();                          // destrutor

    int Start(Game* level);            // inicia a execu��o do jogo
};

// ---------------------------------------------------------------------------------

#endif