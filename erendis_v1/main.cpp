#include <windows.h>
#include "graphicsd3d.h"

#define WIN32_LEAN_AND_MEAN

GraphicsD3D*	m_pgraphics = 0;

LRESULT WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_QUIT:
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		DestroyWindow(hwnd);
		break;
	default:
		break;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

//name: WinMain
//desc: Main entry point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	MSG msg;
	HWND hwnd;
	m_pgraphics = new GraphicsD3D;

	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = L"Erendisclass";
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if(!RegisterClassEx(&wc))
	{
		m_pgraphics->CleanUp();
		delete m_pgraphics;
		m_pgraphics = 0;

		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,
						  L"Erendisclass",
						  L"Erendis, Dawn of the Elves",
						  WS_OVERLAPPEDWINDOW,
						  50,
						  50,
						  1200,
						  840,
						  NULL,
						  NULL,
						  hInstance,
						  NULL);

	if(hwnd == NULL)
	{
		m_pgraphics->CleanUp();
		delete m_pgraphics;
		m_pgraphics = 0;
		return 0;
	}

	if(!m_pgraphics->InitD3D(hwnd, 1200, 840))
	{
		MessageBox(NULL, L"D3D Init failed", L"Error", MB_OK);

		m_pgraphics->CleanUp();

		delete m_pgraphics;
		m_pgraphics = 0;
		return 0;
	}

	ZeroMemory(&msg, sizeof(msg));

	while(msg.message != WM_QUIT)
	{
		ShowWindow(hwnd, SW_SHOW);
		UpdateWindow(hwnd);

		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
			m_pgraphics->RenderScene();
	}

	UnregisterClass(L"Erendisclass", hInstance);

	m_pgraphics->CleanUp();
	delete m_pgraphics;
	m_pgraphics = 0;

	return 0;
}