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
		std::cout << "add" << std::endl;
		m_assets[file] = new Image();
		m_assets[file]->LoadFromFile(file);
	}
}

Image* AssetManager::get(string file)
{
	if(m_assets.count(file))
	{
		std::cout << "get" << std::endl;
		return m_assets[file];
	}
	else
	{
		return NULL;
	}
}
