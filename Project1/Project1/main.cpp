#include <SFML/Graphics.hpp>

using namespace sf;

////////////////////КЛАСС ИГРОКА////////////////////////
class Player {
public:
	float x, y, w, h, dx, dy, speed = 0; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	int dir = 0; //направление (direction) движения игрока
	bool life;
	String File; //файл с расширением
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт

	Player(String F, float X, float Y, float W, float H) {  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
		File = F;//имя файла+расширение
		w = W; h = H;//высота и ширина
		life = true;
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
	bool game_start = false;
	RenderWindow window(sf::VideoMode(800, 600), "Save the cockroach");


///////////////////////ЗАГРУЗАЕМ СТАТИЧНЫЕ ТЕКСТУРЫ///////////////////////////////////
	Texture hallT;//создаем объект Texture (текстура)
	hallT.loadFromFile("images/hall.png");//передаем в него объект Image (изображения)
	Sprite hallS;//создаем объект Sprite(спрайт)
	hallS.setTexture(hallT);//передаём в него объект Texture (текстуры)
	hallS.setPosition(0, 0);//задаем начальные координаты появления спрайта

	Texture petliT;
	petliT.loadFromFile("images/petli.png");
	Sprite petliS;
	petliS.setTexture(petliT);
	petliS.setPosition(0, 0);

	Texture startT;
	startT.loadFromFile("images/start.png");
	Sprite startS;
	startS.setTexture(startT);
	startS.setPosition(0, -30);

	Texture doorT;
	doorT.loadFromFile("images/door.png");
	Sprite doorS;
	doorS.setTexture(doorT);
	doorS.setPosition(0, 0);

	Texture animT;
	animT.loadFromFile("images/hall_anim.png");
	Sprite animS;
	animS.setTexture(animT);
	animS.setPosition(0, 0);

	Texture bgtexture;
	bgtexture.loadFromFile("images/b.png");
	Sprite bgsprite;
	bgsprite.setTexture(bgtexture);
	bgsprite.setPosition(0, 0);

	Texture learntexture;
	learntexture.loadFromFile("images/learn.png");
	Sprite learnsprite;
	learnsprite.setTexture(learntexture);
	learnsprite.setPosition(0, 0);

	Clock clock;
	float CurrentFrame = 0, CurrentFrame1 = 0, CurrentFrameAnim = 0;
	int xPos, yPos, yPos1, tr, tr1;
	bool life = true;
	int anim_start = 0;


	Player p("c.png", 400, 454, 60, 100);
	Player shoes("adidas.png", 0, -750, 800, 600);
	Player shoes1("slipper.png", 0, -750, 800, 600);

	while (window.isOpen())
	{
		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time / 800; //скорость игры

////////////////////////УПРАВЛЕНИЕ///////////////////////////////
		if ((Keyboard::isKeyPressed(Keyboard::Left)) && (xPos > (-5))) { //если нажата клавиша стрелка влево
			p.dir = 1; p.speed = 0.5;
			CurrentFrame += 0.015 * time; //служит для прохождения по "кадрам". переменная доходит до 5 суммируя произведение времени и скорости
			if (CurrentFrame > 5) CurrentFrame -= 5; // если пришли к 5 кадру - откидываемся назад.
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100)); //проходимся по координатам Х
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left)) && (xPos <= (-5))) { //если нажата клавиша стрелка влево
			p.dir = 1; p.speed = 0;
			CurrentFrame += 0.015 * time;
			if (CurrentFrame > 5) CurrentFrame -= 5; 
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100));
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right)) && (xPos < 744)) { //если нажата клавиша стрелка влево
			p.dir = 0; p.speed = 0.5;
			CurrentFrame += 0.015 * time; 
			if (CurrentFrame > 5) CurrentFrame -= 5; 
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 85, 67, 100)); 	
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right)) && (xPos >= 744)) {
			p.dir = 0; p.speed = 0;
			CurrentFrame += 0.015 * time; 
			if (CurrentFrame > 5) CurrentFrame -= 5; 
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 85, 67, 100)); 
		}


		p.update(time); 
		shoes.update(time);
		shoes1.update(time);

		window.clear();
		window.draw(hallS);

//////////////////////////////АНИМАЦИЯ ДВЕРИ//////////////////////////////
		if (anim_start == 1) {
			window.draw(animS);
			CurrentFrameAnim += 0.002 * time;
			if (CurrentFrameAnim > 4) game_start = true;
			if ((CurrentFrameAnim <= 4) && (CurrentFrameAnim>=2)){
			animS.setPosition(-70 * CurrentFrameAnim, -20 * CurrentFrameAnim);
			if (CurrentFrameAnim <= 4) {
				animS.setScale(CurrentFrameAnim, CurrentFrameAnim);
			}
			}

		}
///////////////////////////НАЧАЛО АНИАЦИИ ДВЕРИ/////////////////////////////
		if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
			if (event.key.code == Mouse::Left)
				if (doorS.getGlobalBounds().contains(pos.x, pos.y)) {//а именно левая				
					doorS.setScale(0, 0);
					startS.setScale(0, 0);
					petliS.setScale(0, 0);
					anim_start = 1;
				}

		window.draw(doorS);
		window.draw(startS);
		window.draw(petliS);

//////////////////////////САМА ИГРА///////////////////////////
		if (game_start == true) {

			window.draw(bgsprite);
			window.draw(learnsprite);

			if (life == true) {
				window.draw(p.sprite);
			}
			
				window.draw(shoes.sprite);
				window.draw(shoes1.sprite);
				xPos = p.sprite.getPosition().x;
				yPos = shoes.sprite.getPosition().y;
				yPos1 = shoes1.sprite.getPosition().y;

////////////////////////////ТАРАКАН СДОХ///////////////////////////
				if ((xPos >= 622) && (xPos <= 738) && (yPos == 0)) {
					life = false;
				}

				if (life == false) {
					Player pd("cd.png", xPos, 494, 102, 77);
					pd.update(time);
					CurrentFrame1 += 0.008 * time;
					pd.sprite.setTextureRect(IntRect(102 * int(CurrentFrame1), 0, 102, 77));					
					window.draw(pd.sprite);


					shoes.dir = 3;
					shoes.speed = 0.45;
					shoes1.dir = 3;
					shoes1.speed = 0.45;
					
				}

////////////////////////////ДВИЖЕНИЕ НОГИ АДИДАС/////////////////////////////////////////
				if ((yPos == 0) || (yPos == 1) || (yPos == 2) || (yPos == 3) || (yPos == 4)) {
					tr = 1;
				}

				if ((yPos == -750) || (yPos == -749) || (yPos == -748) || (yPos == -747) | (yPos == -746)) {
					tr = 0;
				}

				if (life == true) {
					if (tr == 1) {
						shoes.dir = 3;
						shoes.speed = 0.2;
					}

					if (tr == 0) {
						shoes.dir = 2;
						shoes.speed = 0.4;
					}
				}

/////////////////////////////////ДВИЖЕНИЕ НОГИ ТАПОК///////////////////////////////////
				if ((yPos1 == 0) || (yPos1 == 1) || (yPos1 == 2) || (yPos1 == 3) || (yPos1 == 4) || (yPos1 == 5)) {
					tr1 = 1;
				}

				if ((yPos1 == -750) || (yPos1 == -749) || (yPos1 == -748) || (yPos1 == -747) | (yPos1 == -746) || (yPos1 == -745)) {
					tr1 = 0;
				}

				if (life == true) {
					if (tr1 == 1) {
						shoes1.dir = 3;
						shoes1.speed = 0.2;
					}

					if (tr1 == 0) {
						shoes1.dir = 2;
						shoes1.speed = 0.5;
					}
				}
			}
		
		window.display();
		
	}
	return 0;
}