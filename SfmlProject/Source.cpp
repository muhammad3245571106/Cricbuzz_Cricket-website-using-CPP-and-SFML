//#include "Header.h"
//using namespace sf;
//int main()
//{
//	RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
//	RectangleShape shape(Vector2f(42.0f, 35.0f));
//	shape.setOutlineThickness(4);
//	shape.setOutlineColor(Color(222, 184, 135));
//	shape.setFillColor(Color::Blue);
//	shape.setPosition(7, 160);
//	Text line;
//	line.setString("Button # 1");
//	line.move(Vector2f(42.0f, 35.0f));
//	line.setOutlineThickness(4);
//	line.setOutlineColor(Color(222, 184, 135));
//	line.setFillColor(Color::Cyan);
//	line.
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//		}
//		window.clear();
//		window.draw(shape);
//		window.draw(line);
//		window.display();
//	}
//	return 0;
//}