#include <SFML/Graphics.hpp>

using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::

////////////////////КЛАСС ИГРОКА////////////////////////
class Player {
public:
	float x, y, w, h, dx, dy, speed = 0; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	int dir = 0; //направление (direction) движения игрока
	String File; //файл с расширением
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт

	Player(String F, float X, float Y, float W, float H) {  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
		File = F;//имя файла+расширение
		w = W; h = H;//высота и ширина
		image.loadFromFile("images/" + F);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта. 
		texture.loadFromImage(image);//закидываем наше изображение в текстуру
		sprite.setTexture(texture);//заливаем спрайт текстурой
		x = X; y = Y;//координата появления спрайта
		sprite.setTextureRect(IntRect(0, 0, w, h));  //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
	}

	void update(float time) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
	{
		switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
		{
		case 0: dx = speed; dy = 0;   break;
		case 1: dx = -speed; dy = 0;  break;
		case 2: dx = 0; dy = speed;   break;
		case 3: dx = 0; dy = -speed;  break;
		}

		x += dx * time;//то движение из прошлого урока. наше ускорение на время получаем смещение координат и как следствие движение
		y += dy * time;//аналогично по игреку

		speed = 0;//зануляем скорость, чтобы персонаж остановился.
		sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
	}

};

int main()
{
	RenderWindow window(sf::VideoMode(800, 600), "Save the cockroach");

	Texture bgtexture;//создаем объект Texture (текстура)
	bgtexture.loadFromFile("images/b.png");//передаем в него объект Image (изображения)
	Sprite bgsprite;//создаем объект Sprite(спрайт)
	bgsprite.setTexture(bgtexture);//передаём в него объект Texture (текстуры)
	bgsprite.setPosition(0, 0);//задаем начальные координаты появления спрайта

	Texture learntexture;//создаем объект Texture (текстура)
	learntexture.loadFromFile("images/learn.png");//передаем в него объект Image (изображения)
	Sprite learnsprite;//создаем объект Sprite(спрайт)
	learnsprite.setTexture(learntexture);//передаём в него объект Texture (текстуры)
	learnsprite.setPosition(0, 0);//задаем начальные координаты появления спрайта

	Clock clock;
	float CurrentFrame=0;
	int xPos, yPos, yPos1, tr, tr1;

	Player p("c.png", 400, 454, 60, 100);
	Player shoes("adidas.png", 0, -750, 800, 600);
	Player shoes1("slipper.png", 0, -750, 800, 600);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time/800; //скорость игры
		

		if ((Keyboard::isKeyPressed(Keyboard::Left))&&(xPos>(-5))) { //если нажата клавиша стрелка влево
			p.dir = 1; p.speed = 0.5;
			CurrentFrame += 0.015 * time; //служит для прохождения по "кадрам". переменная доходит до 5 суммируя произведение времени и скорости
			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к 5 кадру - откидываемся назад.
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100)); //проходимся по координатам Х
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left)) && (xPos <= (-5))) { //если нажата клавиша стрелка влево
			p.dir = 1; p.speed = 0;
			CurrentFrame += 0.015 * time; //служит для прохождения по "кадрам". переменная доходит до 5 суммируя произведение времени и скорости
			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к 5 кадру - откидываемся назад.
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100)); //проходимся по координатам Х
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right))&&(xPos<744)) { //если нажата клавиша стрелка влево
			p.dir = 0; p.speed = 0.5;
			CurrentFrame += 0.015 * time; //служит для прохождения по "кадрам". переменная доходит до 5 суммируя произведение времени и скорости
			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к 5 кадру - откидываемся назад.
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 85, 67, 100)); //проходимся по координатам Х	
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right))&&(xPos >= 744)){
			p.dir = 0; p.speed = 0;
			CurrentFrame += 0.015 * time; //служит для прохождения по "кадрам". переменная доходит до 5 суммируя произведение времени и скорости
			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к 5 кадру - откидываемся назад.
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 85, 67, 100)); //проходимся по координатам Х
		}

		
		p.update(time);  //оживляем объект p класса Player с помощью времени sfml, передавая время в качестве параметра функции update. благодаря этому персонаж может двигаться
		shoes.update(time);
		shoes1.update(time);

		window.clear();
		window.draw(bgsprite);
		window.draw(learnsprite);
		window.draw(p.sprite);  
		window.draw(shoes.sprite);
		window.draw(shoes1.sprite);
		xPos = p.sprite.getPosition().x;
		yPos = shoes.sprite.getPosition().y;
		yPos1 = shoes1.sprite.getPosition().y;

		if ((yPos == 0)|| (yPos == 1)|| (yPos == 2)|| (yPos == 3)|| (yPos == 4)) {
			tr = 1;
		}

		if ((yPos == -750)|| (yPos == -749)|| (yPos == -748)|| (yPos == -747)| (yPos == -746)) {
			tr = 0;
		}

		if (tr == 1) {
			shoes.dir = 3;
			shoes.speed = 0.2;
		}

		if (tr == 0) {
			shoes.dir = 2;
			shoes.speed = 0.4;
		}

		

		if ((yPos1 == 0) || (yPos1 == 1) || (yPos1 == 2) || (yPos1 == 3) || (yPos1 == 4)|| (yPos1 == 5)) {
			tr1 = 1;
		}

		if ((yPos1 == -750) || (yPos1 == -749) || (yPos1 == -748) || (yPos1 == -747) | (yPos1 == -746)|| (yPos1 == -745)) {
			tr1 = 0;
		}

		if (tr1 == 1) {
			shoes1.dir = 3;
			shoes1.speed = 0.2;
		}

		if (tr1 == 0) {
			shoes1.dir = 2;
			shoes1.speed = 0.5;
		}
		
		window.display();
		
	}
	return 0;
}