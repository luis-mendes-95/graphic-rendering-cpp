/**********************************************************************************
// WinGame
//
//
// Descrição:   Um jogo para Windows é uma classe derivada de Game.
//              Crie uma classe derivada e sobrescreva os métodos Init,
//              Update, Draw e Finalize.
//
**********************************************************************************/

#include "Resources.h"
#include "Engine.h"
#include "Game.h"
#include <sstream>
using std::stringstream;

// ------------------------------------------------------------------------------

class WinGame : public Game
{
private:
	HDC hdc;
	int xi, xf, yi, yf;
	int velXi, velYi;
	int velXf, velYf;

public:
	void Init();
	void Update();
	void Draw();
	void Finalize();
};

// ------------------------------------------------------------------------------

void WinGame::Init()
{
	hdc = GetDC(window->Id());

	xi = 10;
	yi = 10;
	xf = 100;
	yf = 100;

	velXi = 10;
	velYi = 10;
	velXf = 10;
	velYf = 10;
}

// ------------------------------------------------------------------------------

void WinGame::Update()
{
	if (window->KeyDown(VK_ESCAPE))
		window->Close();

	
	xi += velXi;
	yi += velYi;
	xf += velXf;
	yf += velYf;

	if (xi > window->Width())
		velXi = -velXi;

	if (yi > window->Height())
		velYi = -velYi;

	if (xi < 0)
		velXi = -velXi;

	if (yi < 0)
		velYi = -velYi;



	if (xf > window->Width())
		velXf = -velXf;

	if (yf > window->Height())
		velYf = -velYf;

	if (xf < 0)
		velXf = -velXf;

	if (yf < 0)
		velYf = -velYf;
	

	MoveToEx(hdc, xi, yi, NULL);

}

// ------------------------------------------------------------------------------

void WinGame::Draw()
{
	LineTo(hdc, xf, yf);
}

// ------------------------------------------------------------------------------

void WinGame::Finalize()
{
	ReleaseDC(window->Id(), hdc);
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// cria motor e configura a janela
	Engine* engine = new Engine();
	engine->window->Mode(WINDOWED);
	engine->window->Size(960, 540);
	engine->window->Color(240, 240, 140);
	engine->window->Title("Goat Engine");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);

	// cria e inicia o jogo
	engine->Start(new WinGame());
}

// ----------------------------------------------------------------------------