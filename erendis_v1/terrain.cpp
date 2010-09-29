#include "terrain.h"

Terrain::Terrain()
{
	m_vertexcount = 0;
	m_indexcount = 0;
	m_pindexbuffer = 0;
	m_pvertexbuffer = 0;
}

Terrain::~Terrain()
{

}

bool Terrain::LoadHeightMap(char* filename)
{
	//FILE*	pfile = fopen(filename, );

	int terrainsize = (TERRAIN_WIDTH + 1) * (TERRAIN_HEIGHT + 1);

	
	return true;
}

bool Terrain::InitTerrain(ID3D10Device* device)
{
	return true;
}

void Terrain::RenderTerrain(D3DXMATRIX worldmatrix, D3DXMATRIX projectionmatrix, D3DXMATRIX viewmatrix)
{

}

void Terrain::CleanUp()
{
	if(m_pindexbuffer)
		m_pindexbuffer->Release();

	if(m_pvertexbuffer)
		m_pvertexbuffer->Release();
}