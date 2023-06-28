#include "Header.h"
#include "Class.cpp"
using namespace std;

int main()
{
	int choice;
	RenderWindow window(VideoMode(1100, 600), "Cricbuzz!", Style::Close);

	//To control the text of code
	Font font;

	if (!font.loadFromFile("robo.ttf"))
	{
		cout << "\n\nFont is unable to load.\n\n";
		return 0;
	}

	Music backgroundMusic;
	if (!backgroundMusic.openFromFile("musi.ogg"))
	{
		cout << "error";
	}

	RectangleShape sound_Button(Vector2f(50.0f, 50.0f));
	sound_Button.setPosition(-380.0f, window.getSize().y / 0.862);
	sound_Button.setOrigin(-380.0f, 144.0f);
	Texture sound_ButtonTexture;
	sound_ButtonTexture.loadFromFile("Sound Button.jpg");
	sound_Button.setTexture(&sound_ButtonTexture);

	RectangleShape start(Vector2f(100.0f, 40));
	start.setPosition(-30.0f, window.getSize().y / 1.09);
	start.setOrigin(-148.0f, 165.0f);
	Texture startTexture;
	startTexture.loadFromFile("start.jpg");
	start.setTexture(&startTexture);

	RectangleShape exit(Vector2f(100.0f, 40.0f));
	exit.setPosition(650.f, window.getSize().y / 1.09);
	exit.setOrigin(-148.0f, 165.0f);
	Texture exitTexture;
	exitTexture.loadFromFile("exit.jpg");
	exit.setTexture(&exitTexture);

	Texture t;
	t.loadFromFile("background.jpg");
	Sprite s;
	s.setTexture(t);

	Text text;
	text.setFont(font);
	text.setString("Welcome to Cricbuzz");
	text.setCharacterSize(24);
	text.setFillColor(Color::Red);
	Vector2f vector2f(440, 300);
	text.setPosition(vector2f);

	Vector2u textureSize;
	Vector2u windowSize;

	textureSize = t.getSize();
	windowSize = window.getSize();

	float scaleX = (float)windowSize.x / textureSize.x;
	float scaleY = (float)windowSize.y / textureSize.y;

	s.setScale(scaleX, scaleY);
	backgroundMusic.play();
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))

		{
			
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;

			case Event::MouseButtonPressed:
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					if (sound_Button.getGlobalBounds().contains(window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y))))
					{
						sound_Button.setFillColor(Color(255, 255, 255));
						backgroundMusic.play();
					}
					if (start.getGlobalBounds().contains(window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y))))
					{
						window.close();
						window.clear();
					}
					if (exit.getGlobalBounds().contains(window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y))))
					{
						system("pause>0");
						return 0;
					}
				}
				else if (event.mouseButton.button == Mouse::Right)
				{
					if (sound_Button.getGlobalBounds().contains(window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y))))
					{
						sound_Button.setFillColor(Color(23, 294, 60));
						backgroundMusic.pause();
					}
				}
			}

			}

		}
		window.draw(s);
		window.draw(sound_Button);
		window.draw(start);
		window.draw(exit);
		window.draw(text);
		window.display();
	}



	//RenderWindow window2(VideoMode(1100, 600), "Cricbuzz!", Style::Close);


	//RectangleShape player(Vector2f(80.0f, 50));
	//player.setPosition(-30.0f, window2.getSize().y / 1.09);
	//player.setOrigin(-148.0f, 165.0f);
	//startTexture.loadFromFile("player.jpg");
	//player.setTexture(&startTexture);

	//RectangleShape admin(Vector2f(100.0f, 40.0f));
	//admin.setPosition(650.f, window2.getSize().y / 1.09);
	//admin.setOrigin(-148.0f, 165.0f);
	//exitTexture.loadFromFile("admin.jpg");
	//admin.setTexture(&exitTexture);

	//t.loadFromFile("2nd.jpg");
	//s.setTexture(t);

	//text.setFont(font);
	//text.setString("Welcome to Cricbuzz");
	//text.setCharacterSize(24);
	//text.setFillColor(Color::Red);
	//text.setPosition(vector2f);

	//s.setScale(scaleX, scaleY);

	//backgroundMusic.play();
	//while (window2.isOpen())
	//{
	//	Event event;
	//	while (window2.pollEvent(event))

	//	{
	//		switch (event.type)
	//		{
	//		case  Event::Closed:
	//			window2.close();
	//			break;
	//		}

	//		if (event.type == Event::MouseButtonPressed)
	//		{
	//			if (event.mouseButton.button == Mouse::Left)
	//			{
	//				if (sound_Button.getGlobalBounds().contains(window2.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y))))
	//				{
	//					backgroundMusic.play();
	//				}
	//				if (admin.getGlobalBounds().contains(window2.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y))))
	//				{
	//					choice = 1;
	//					window2.close();
	//				}
	//				if (player.getGlobalBounds().contains(window2.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y))))
	//				{
	//					choice = 2;
	//					window.close();
	//				}
	//			}
	//			else if (event.mouseButton.button == Mouse::Right)
	//			{
	//				if (sound_Button.getGlobalBounds().contains(window2.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y))))
	//				{
	//					backgroundMusic.pause();
	//				}
	//			}
	//		}


	//	}
	//	window2.draw(s);
	//	window2.draw(sound_Button);
	//	window2.draw(player);
	//	window2.draw(admin);
	//	window2.display();
	//}
	
	system("color F0");

	team team1(1);
	team1.teamName = "Pakistan";
	team team2(2);
	team2.teamName = "India";
	int teamChoice;
	cout << "1) Pakistan\n2) India\n3) Conduct Match\nPlease enter your Choice : ";
	cin >> teamChoice;
	cout << endl;

	switch (teamChoice)
	{
	case 1:
	{
		cout << "1) Admin login\n2) Player login\nPlease enter your choice : ";
		cout << endl;
		if (choice == 1)
		{
			team1.adminLogin();
		}
		else if (choice == 2)
		{
			team1.playerLogin();
		}
		else
		{
			cout << "\n\nInvalid input\n\n";
		}
		break;
	}
	case 2:
	{
		cout << "1) Admin login\n2) Player login\nPlease enter your choice : ";
		cout << endl;
		if (choice == 1)
		{
			team2.adminLogin();
		}
		else if (choice == 2)
		{
			team2.playerLogin();
		}
		else
		{
			cout << "\n\nInvalid input\n\n";
		}
		break;
	}
	case 3:
	{
		Match m1, m2, m3;
		int score1 = 0, score2 = 0;

		m1.scheduleMatch();

		if (m1.toss() == 0)
		{
			cout << "\n\nPress 1 to bat and 2 to ball first : ";
			cin >> teamChoice;
			switch (teamChoice)
			{
			case 1:
			{
				m1.team1(score1);
				m1.team2(score2);
				break;
			}
			case 2:
			{
				m1.team2(score2);
				m1.team1(score1);
				break;
			}
			}

		}
		else
		{
			cout << "\n\nPress 1 to bat and 2 to ball first : ";
			cin >> teamChoice;
			switch (teamChoice) {
			case 1:
				m1.team2(score2);
				m1.team1(score1); break;
			case 2:
				m1.team1(score1);
				m1.team2(score2); break;
			}
		}
		cout << "\n\nTotal score of Team 1 = " << score1;
		cout << "\n\nTotal score of Team 2 = " << score2;

		m1.winner(score1, score2);
		cout << endl;
		break;

	}

	default:
	{
		cout << "\n\nInvalid choice.\n\n";
		system("pause>0");
		return 0;
	}
	}

	system("pause>0");
	return 0;
}