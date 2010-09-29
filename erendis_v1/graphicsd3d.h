#ifndef _GRAPHICS_D3D_H
#define _GRAPHICS_D3D_H

#pragma once
//includes
#include <d3d10.h>
#include <d3dx10.h>
#include <windows.h>
//class definition
class GraphicsD3D
{
public:
	GraphicsD3D();
	~GraphicsD3D();

	bool InitD3D(HWND hwnd, int width, int height);

	void RenderScene();
	void CleanUp();

private:
	ID3D10Device*				m_pd3ddevice;
	ID3D10RenderTargetView*		m_prendertargetview;
	IDXGISwapChain*				m_pswapchain;
	D3D10_DRIVER_TYPE			m_drivertype;
};
#endif