#include <SFML/Graphics.hpp>

using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::

////////////////////����� ������////////////////////////
class Player {
public:
	float x, y, w, h, dx, dy, speed = 0; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	int dir = 0; //����������� (direction) �������� ������
	String File; //���� � �����������
	Image image;//���� �����������
	Texture texture;//���� ��������
	Sprite sprite;//���� ������

	Player(String F, float X, float Y, float W, float H) {  //����������� � �����������(�����������) ��� ������ Player. ��� �������� ������� ������ �� ����� �������� ��� �����, ���������� � � �, ������ � ������
		File = F;//��� �����+����������
		w = W; h = H;//������ � ������
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
	RenderWindow window(sf::VideoMode(800, 600), "Save the cockroach");

	Texture bgtexture;//������� ������ Texture (��������)
	bgtexture.loadFromFile("images/b.png");//�������� � ���� ������ Image (�����������)
	Sprite bgsprite;//������� ������ Sprite(������)
	bgsprite.setTexture(bgtexture);//������� � ���� ������ Texture (��������)
	bgsprite.setPosition(0, 0);//������ ��������� ���������� ��������� �������

	Texture learntexture;//������� ������ Texture (��������)
	learntexture.loadFromFile("images/learn.png");//�������� � ���� ������ Image (�����������)
	Sprite learnsprite;//������� ������ Sprite(������)
	learnsprite.setTexture(learntexture);//������� � ���� ������ Texture (��������)
	learnsprite.setPosition(0, 0);//������ ��������� ���������� ��������� �������

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

		float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
		clock.restart(); //������������� �����
		time = time/800; //�������� ����
		

		if ((Keyboard::isKeyPressed(Keyboard::Left))&&(xPos>(-5))) { //���� ������ ������� ������� �����
			p.dir = 1; p.speed = 0.5;
			CurrentFrame += 0.015 * time; //������ ��� ����������� �� "������". ���������� ������� �� 5 �������� ������������ ������� � ��������
			if (CurrentFrame > 5) CurrentFrame -= 5; // ���� ������ � 5 ����� - ������������ �����.
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100)); //���������� �� ����������� �
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left)) && (xPos <= (-5))) { //���� ������ ������� ������� �����
			p.dir = 1; p.speed = 0;
			CurrentFrame += 0.015 * time; //������ ��� ����������� �� "������". ���������� ������� �� 5 �������� ������������ ������� � ��������
			if (CurrentFrame > 5) CurrentFrame -= 5; // ���� ������ � 5 ����� - ������������ �����.
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100)); //���������� �� ����������� �
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right))&&(xPos<744)) { //���� ������ ������� ������� �����
			p.dir = 0; p.speed = 0.5;
			CurrentFrame += 0.015 * time; //������ ��� ����������� �� "������". ���������� ������� �� 5 �������� ������������ ������� � ��������
			if (CurrentFrame > 5) CurrentFrame -= 5; // ���� ������ � 5 ����� - ������������ �����.
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 85, 67, 100)); //���������� �� ����������� �	
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right))&&(xPos >= 744)){
			p.dir = 0; p.speed = 0;
			CurrentFrame += 0.015 * time; //������ ��� ����������� �� "������". ���������� ������� �� 5 �������� ������������ ������� � ��������
			if (CurrentFrame > 5) CurrentFrame -= 5; // ���� ������ � 5 ����� - ������������ �����.
			p.sprite.setTextureRect(IntRect(67 * int(CurrentFrame), 85, 67, 100)); //���������� �� ����������� �
		}

		
		p.update(time);  //�������� ������ p ������ Player � ������� ������� sfml, ��������� ����� � �������� ��������� ������� update. ��������� ����� �������� ����� ���������
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