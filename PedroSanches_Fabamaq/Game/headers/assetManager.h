/* ***************************************************************  */
/* ********** Desafio Fabamaq ************************************  */
/* **                                                           **  */
/* ********** Autor: Pedro Sanches *******************************  */
/* **                                                           **  */
/* ********** Data Entrega: 15 outubro 2020 **********************  */
/* ***************************************************************  */
/* **  LINKEDIN : https://www.linkedin.com/in/pedro-ma-sanches/  ** */
/* ***************************************************************  */

#pragma once

#include <map>
#include <SFML/Graphics.hpp>


namespace desafio
{
	class AssetManager
	{
		public:
			AssetManager() {}
			~AssetManager() {}
			
			void LoadTexture(std::string name, std::string fileName);
			sf::Texture &GetTexture(std::string name);

			void LoadFont(std::string name, std::string fileName);
			sf::Font &GetFont(std::string name);

		private:
			std::map<std::string, sf::Texture> _textures;
			std::map<std::string, sf::Font> _fonts;
	};
}