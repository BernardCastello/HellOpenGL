#pragma once

#include "CoreDef.h"
#include "crenderutils.h"
#include <map>
#include <vector>
#include <string>

coreDef(Asset)

std::vector<Shader>				    m_shaders;
std::vector<TextureData>		    m_textures;
std::vector<RenderData>			    m_meshes;

std::map<std::string, Shader*>	    m_shaderMap;
std::map<std::string, TextureData*> m_textureMap;
std::map<std::string, RenderData*>  m_meshMap;


bool init() { return true; }

bool step() { return true; }

bool term()
{
	for each(auto s in m_shaders)
		glDeleteProgram(s);
	
	for each(auto t in m_textures)
		glDeleteTextures(1, &t.handle);

	for each(auto r in m_meshes)
	{
		glDeleteVertexArrays(1, &r.VAO);
		glDeleteBuffers(1, &r.IBO);
		glDeleteBuffers(1, &r.VBO);
	}
	return true;
}


public:

void loadShader(const char*name, const char* a_vertPath, const char* a_fragPath)
{
	Shader s = CreateProgram(a_vertPath, a_fragPath);
	m_shaders.push_back(s);
	m_shaderMap[name] = &m_shaders.back();
}
void loadTexture(const char*name,const char*path)
{
	TextureData t = LoadTexture(path);
	m_textures.push_back(t);
	m_textureMap[name] = &m_textures.back();
}
void loadMesh(const char*name, Vertex *verts, int nverts, Triangle *tris, int ntris)
{
	RenderData r = LoadMesh(verts, nverts, tris, ntris);
	m_meshes.push_back(r);
	m_meshMap[name] = &m_meshes.back();
}


TextureData getTexture(std::string name) { return *m_textureMap[name]; }
RenderData getMesh(std::string name) { return *m_meshMap[name]; }
Shader getShader(std::string name) { return *m_shaderMap[name]; }

coreEndDef