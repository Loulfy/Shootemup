#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

class AssetManager
{
	public:

		AssetManager();
		~AssetManager();
		void add(std::string file);
		sf::Image* get(std::string file);

	private:

		std::map<std::string, sf::Image*> m_assets;
};

#endif
