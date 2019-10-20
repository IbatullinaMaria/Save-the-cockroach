#include <SFML/Graphics.hpp>

using namespace sf;//включаем пространство имен sf, чтобы посто€нно не писать sf::
int main()
{
	RenderWindow window(sf::VideoMode(800, 600), "Save the cockroach");

	Texture bgtexture;//создаем объект Texture (текстура)
	bgtexture.loadFromFile("images/b.png");//передаем в него объект Image (изображени€)
	Sprite bgsprite;//создаем объект Sprite(спрайт)
	bgsprite.setTexture(bgtexture);//передаЄм в него объект Texture (текстуры)
	bgsprite.setPosition(0, 0);//задаем начальные координаты по€влени€ спрайта

	Texture learntexture;//создаем объект Texture (текстура)
	learntexture.loadFromFile("images/learn.png");//передаем в него объект Image (изображени€)
	Sprite learnsprite;//создаем объект Sprite(спрайт)
	learnsprite.setTexture(learntexture);//передаЄм в него объект Texture (текстуры)
	learnsprite.setPosition(0, 0);//задаем начальные координаты по€влени€ спрайта

	int x = 400;
	int y = 454;
	Texture ctexture;
	ctexture.loadFromFile("images/c.png");
	Sprite csprite;
	csprite.setTexture(ctexture);
	csprite.setTextureRect(IntRect(0, 0, 60, 100));//получили нужный нам пр€моугольник с такараном
	csprite.setPosition(x, y);

	Clock clock;
	float CurrentFrame=0;
	int xPos, yPos;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее врем€ в микросекундах
		clock.restart(); //перезагружает врем€
		time = time/800; //скорость игры

		

		if ((Keyboard::isKeyPressed(Keyboard::Left))&&(xPos>(-5))) { //если нажата клавиша стрелка влево
			CurrentFrame += 0.015 * time; //служит дл€ прохождени€ по "кадрам". переменна€ доходит до 5 суммиру€ произведение времени и скорости
			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к 5 кадру - откидываемс€ назад.
			csprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100)); //проходимс€ по координатам ’
			csprite.move(-0.35 * time, 0);//происходит само движение персонажа влево
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left)) && (xPos <= (-5))) { //если нажата клавиша стрелка влево
			CurrentFrame += 0.015 * time; //служит дл€ прохождени€ по "кадрам". переменна€ доходит до 5 суммиру€ произведение времени и скорости
			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к 5 кадру - откидываемс€ назад.
			csprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100)); //проходимс€ по координатам ’
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right))&&(xPos<744)) { //если нажата клавиша стрелка влево
			CurrentFrame += 0.015 * time; //служит дл€ прохождени€ по "кадрам". переменна€ доходит до 5 суммиру€ произведение времени и скорости
			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к 5 кадру - откидываемс€ назад.
			csprite.setTextureRect(IntRect(67 * int(CurrentFrame), 85, 67, 100)); //проходимс€ по координатам ’
			csprite.move(0.35 * time, 0);//происходит само движение персонажа вправо			
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right))&&(xPos >= 744)){
			CurrentFrame += 0.015 * time; //служит дл€ прохождени€ по "кадрам". переменна€ доходит до 5 суммиру€ произведение времени и скорости
			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к 5 кадру - откидываемс€ назад.
			csprite.setTextureRect(IntRect(67 * int(CurrentFrame), 85, 67, 100)); //проходимс€ по координатам ’
		}

		window.clear();
		window.draw(bgsprite);
		window.draw(learnsprite);
		window.draw(csprite);
		xPos = csprite.getPosition().x;
		yPos = csprite.getPosition().y;
		window.display();
		
	}
	return 0;
}