#include "AssetManager.hpp"

using namespace std;
using namespace sf;

AssetManager::AssetManager()
{

}

AssetManager::~AssetManager()
{
	for(auto a : m_assets)
	{
		delete a.second;
	}
}

void AssetManager::add(string file)
{
	if(!m_assets.count(file))
	{
		m_assets[file] = new Image();
		m_assets[file]->LoadFromFile(file);
	}
}

Image* AssetManager::get(string file)
{
	if(m_assets.count(file))
	{
		return m_assets[file];
	}
	else
	{
		return nullptr;
	}
}
