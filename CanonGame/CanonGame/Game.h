/// <summary>
/// author Pete Lowe May 2019
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void processMouseDown(sf::Event t_event);
	void processMouseMove(sf::Event t_event);
	void processMouseRelease(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	void moveTarget();
	void animateGumba();
	
	void setupFontAndText();
	void setupSprite();
	void setupAimLine();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Texture m_logoTexture; // texture used for sfml logo
	sf::Sprite m_logoSprite; // sprite used for sfml logo
	bool m_exitGame; // control exiting game

	bool m_graphics{ false }; // draw fancy pictures [or not]

	sf::RectangleShape m_wall; // rectangle for wall
	sf::RectangleShape m_target; // rectangle for target
	sf::RectangleShape m_cannon;// rectangle for canon
	sf::Vector2f m_mouseEnd; // mouse end of line
	sf::Vector2f m_cannonEnd{ 100.0f,550.0f }; // canon end of line

	sf::VertexArray m_aimLine{ sf::Lines };
	bool m_aiming{ false };


	sf::Vector2f m_targetLocation; // position of target,top left corner
	sf::Vector2f m_targetVelocity{ 0.6f,0.0f }; // velocity of target


	sf::Texture m_wallTexture;
	sf::Sprite m_wallSprite;
	sf::Texture m_backgrolundTexture;
	sf::Sprite m_backgroundSprite;
	sf::Texture m_gumbaTexture;
	sf::Sprite m_gumbaSprite;
	int m_gumbaLastFrame{ 20 }; // last frame in animation
	int m_gumbaFrame{ -1 }; // current frame will trigger a new frame
	float m_gumbaFrameIncrement{ 0.3f }; // add this 60 times a second 
	float m_gumbaFrameCounter{ 0.0f }; // current frame as a float

};

#endif // !GAME_HPP

