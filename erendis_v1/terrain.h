#ifndef _TERRAIN_H
#define _TERRAIN_H

#pragma once
//includes
#include <d3d10.h>
#include <d3dx10.h>
#include <fstream>
#include <ios>
#include <iostream>

//definitions
#define TERRAIN_WIDTH 200
#define TERRAIN_HEIGHT 200

//class definition
class Terrain
{
public:
	Terrain();
	~Terrain();

	bool LoadHeightMap(char* filename);

	bool InitTerrain(ID3D10Device* device);

	void RenderTerrain(D3DXMATRIX worldmatrix, D3DXMATRIX projectionmatrix, D3DXMATRIX viewmatrix);

	void CleanUp();

private:
	ID3D10Buffer*		m_pvertexbuffer;
	ID3D10Buffer*		m_pindexbuffer;
	int					m_vertexcount;
	int					m_indexcount;
};
#endif