#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

////////////////////����� ������////////////////////////
class Player {
public:
	float x, y, w, h, dx, dy, speed = 0; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	int dir = 0; //����������� (direction) �������� ������
	bool life;
	String File; //���� � �����������
	Image image;//���� �����������
	Texture texture;//���� ��������
	Sprite sprite;//���� ������

	Player(String F, float X, float Y, float W, float H) {  //����������� � �����������(�����������) ��� ������ Player. ��� �������� ������� ������ �� ����� �������� ��� �����, ���������� � � �, ������ � ������
		File = F;//��� �����+����������
		w = W; h = H;//������ � ������
		life = true;
		image.loadFromFile("images/" + F);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. 
		texture.loadFromImage(image);//���������� ���� ����������� � ��������
		sprite.setTexture(texture);//�������� ������ ���������
		x = X; y = Y;//���������� ��������� �������
		sprite.setTextureRect(IntRect(0, 0, w, h));  //������ ������� ���� ������������� ��� ������ ������ ����, � �� ���� ����� �����. IntRect - ���������� �����
	}

	void update(float time) //������� "���������" ������� ������. update - ����������. ��������� � ���� ����� SFML , ���������� ���� �������� ����������, ����� ��������� ��������.
	{
		switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
		{
		case 0: dx = speed; dy = 0;   break;
		case 1: dx = -speed; dy = 0;  break;
		case 2: dx = 0; dy = speed;   break;
		case 3: dx = 0; dy = -speed;  break;
		}

		x += dx * time;//�� �������� �� �������� �����. ���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
		y += dy * time;//���������� �� ������

		speed = 0;//�������� ��������, ����� �������� �����������.
		sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
	}

};

int main()
{
	bool game_start = false;
	bool newTimer = false;
	RenderWindow window(sf::VideoMode(800, 600), "Save the cockroach");


///////////////////////��������� ��������� ��������///////////////////////////////////
	Texture hallT;//������� ������ Texture (��������)
	hallT.loadFromFile("images/hall.png");//�������� � ���� ������ Image (�����������)
	Sprite hallS;//������� ������ Sprite(������)
	hallS.setTexture(hallT);//������� � ���� ������ Texture (��������)
	hallS.setPosition(0, 0);//������ ��������� ���������� ��������� �������

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
	int xPos, yPos, yPos1, tr, tr1, yPosBalley, trb;
	int score = 0;
	bool life = true;
	int anim_start = 0;


	Player p("c.png", 400, 454, 60, 100);
	Player shoes("adidas.png", 0, -750, 800, 600);
	Player balley("balley.png", 0, -750, 800, 600);
	Player bomj("bomj.png", 0, -750, 800, 600);
	Player moda("moda.png", 0, -750, 800, 600);
	Player fu("fu.png", 0, -750, 800, 600);
	Player shoes1("slipper.png", 0, -750, 800, 600);

	Clock gameTimeClock;//���������� �������� �������, ����� ����� ������� ����� ���� 
	int gameTime = 0;//�������� ������� �����, ����������������.
	Font font;
	font.loadFromFile("times.ttf");
	Text text("", font, 20);
	//text.setColor(Color::Red);

	while (window.isOpen())
	{
		Vector2i pixelPos = Mouse::getPosition(window);//�������� ����� �������
		Vector2f pos = window.mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
		clock.restart(); //������������� �����
		time = time / 800; //�������� ����

////////////////////////����������///////////////////////////////
		if ((Keyboard::isKeyPressed(Keyboard::Left)) && (xPos > (-5))) { //���� ������ ������� ������� �����
			p.dir = 1; p.speed = 0.5;
			CurrentFrame += 0.015 * time; //������ ��� ����������� �� "������". ���������� ������� �� 5 �������� ������������ ������� � ��������
			if (CurrentFrame > 5) CurrentFrame -= 5; // ���� ������ � 5 ����� - ������������ �����.
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100)); //���������� �� ����������� �
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left)) && (xPos <= (-5))) { //���� ������ ������� ������� �����
			p.dir = 1; p.speed = 0;
			CurrentFrame += 0.015 * time;
			if (CurrentFrame > 5) CurrentFrame -= 5; 
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100));
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right)) && (xPos < 744)) { //���� ������ ������� ������� �����
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
		balley.update(time);

		window.clear();
		window.draw(hallS);

//////////////////////////////�������� �����//////////////////////////////
		if (anim_start == 1) {
			window.draw(animS);
			CurrentFrameAnim += 0.0011 * time;
			if (CurrentFrameAnim > 3) game_start = true;
		//	if ((CurrentFrameAnim <= 4) && (CurrentFrameAnim >= 1)) {
			//	animS.setPosition(-70 * CurrentFrameAnim, -20 * CurrentFrameAnim);
			//}
			if ((CurrentFrameAnim <= 3)&&(CurrentFrameAnim>=1)) {
				animS.setScale(CurrentFrameAnim, CurrentFrameAnim);
			}
			

		}
///////////////////////////������ ������� �����/////////////////////////////
		if (event.type == Event::MouseButtonPressed)//���� ������ ������� ����
			if (event.key.code == Mouse::Left)
				if (doorS.getGlobalBounds().contains(pos.x, pos.y)) {//� ������ �����				
					doorS.setScale(0, 0);
					startS.setScale(0, 0);
					anim_start = 1;
				}

		window.draw(doorS);
		window.draw(startS);
		if ((game_start == false) && (anim_start == 1)) {
			gameTimeClock.restart();
		}
//////////////////////////���� ����///////////////////////////
		if (game_start == true) {

			if ((life)&&(game_start)) gameTime = gameTimeClock.getElapsedTime().asSeconds(); //������� ����� � �������� ��� ������, ���� ��� �����, ������������� ��� time ��� �� ����. ��� �� ��������� ������ ����

			window.draw(bgsprite);
			window.draw(learnsprite);

			if (life == true) {
				window.draw(p.sprite);
			}
			
				window.draw(shoes.sprite);
				window.draw(shoes1.sprite);
				window.draw(balley.sprite);
				xPos = p.sprite.getPosition().x;
				yPos = shoes.sprite.getPosition().y;
				yPos1 = shoes1.sprite.getPosition().y;
				yPosBalley = balley.sprite.getPosition().y;

////////////////////////////������� ����///////////////////////////
				if (((xPos >= 622) && (xPos <= 738) && (yPos == 0)) // ������
					|| ((xPos >= 70) && (xPos <= 200) && (yPos1 == 0)) // �����
					|| ((xPos >= 428) && (xPos <= 475) && (yPosBalley == 0))) {   //��������
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
					balley.dir = 3;
					balley.speed = 0.45;

					score = gameTime;
					
				}

////////////////////////////�������� ���� ������/////////////////////////////////////////
				if ((yPos == 0) || (yPos == 1) || (yPos == 2) || (yPos == 3) || (yPos == 4)) {
					tr = 1;
				}

				if ((yPos == -750) || (yPos == -749) || (yPos == -748) || (yPos == -747) || (yPos == -746)) {
					tr = 0;
				}

				if (life == true) {
					if (tr == 1) {
						shoes.dir = 3;
						shoes.speed = 0.26;
					}

					if (tr == 0) {
						shoes.dir = 2;
						shoes.speed = 0.4;
					}
				}

/////////////////////////////////�������� ���� �����///////////////////////////////////
				if ((yPos1 == 0) || (yPos1 == 1) || (yPos1 == 2) || (yPos1 == 3) || (yPos1 == 4) || (yPos1 == 5)) {
					tr1 = 1;
				}

				if ((yPos1 == -750) || (yPos1 == -749) || (yPos1 == -748) || (yPos1 == -747) || (yPos1 == -746) || (yPos1 == -745)) {
					tr1 = 0;
				}

				if (life == true) {
					if (tr1 == 1) {
						shoes1.dir = 3;
						shoes1.speed = 0.1;
					}

					if (tr1 == 0) {
						shoes1.dir = 2;
						shoes1.speed = 0.5;
					}
				}
			


/////////////////////////////////�������� ���� ��������///////////////////////////////////
				if ((yPosBalley == 0) || (yPosBalley == 1) || (yPosBalley == 2) || (yPosBalley == 3) || (yPosBalley == 4) || (yPosBalley == 5)) {
					trb = 1;
				}

				if ((yPosBalley == -750) || (yPosBalley == -749) || (yPosBalley == -748) || (yPosBalley == -747) || (yPosBalley == -746) || (yPosBalley == -745)) {
					trb = 0;
				}

				if (life == true) {
					if (trb == 1) {
						balley.dir = 3;
						balley.speed = 0.2;
					}

					if (trb == 0) {
						balley.dir = 2;
						balley.speed = 0.45;
					}
				}

				
				std::string s = std::to_string(score);
				//gameTimeString<<gameTime;
				if (not life) {
					text.setString("Your score: " + s);
					window.draw(text);
				}


			}
		
		window.display();
		
	}
	return 0;
}