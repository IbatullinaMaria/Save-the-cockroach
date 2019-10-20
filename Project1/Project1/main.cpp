#include <SFML/Graphics.hpp>

using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::
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

	int x = 400;
	int y = 454;
	Texture ctexture;
	ctexture.loadFromFile("images/c.png");
	Sprite csprite;
	csprite.setTexture(ctexture);
	csprite.setTextureRect(IntRect(0, 0, 60, 100));//�������� ������ ��� ������������� � ���������
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

		float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
		clock.restart(); //������������� �����
		time = time/800; //�������� ����

		

		if ((Keyboard::isKeyPressed(Keyboard::Left))&&(xPos>(-5))) { //���� ������ ������� ������� �����
			CurrentFrame += 0.015 * time; //������ ��� ����������� �� "������". ���������� ������� �� 5 �������� ������������ ������� � ��������
			if (CurrentFrame > 5) CurrentFrame -= 5; // ���� ������ � 5 ����� - ������������ �����.
			csprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100)); //���������� �� ����������� �
			csprite.move(-0.35 * time, 0);//���������� ���� �������� ��������� �����
		}
		if ((Keyboard::isKeyPressed(Keyboard::Left)) && (xPos <= (-5))) { //���� ������ ������� ������� �����
			CurrentFrame += 0.015 * time; //������ ��� ����������� �� "������". ���������� ������� �� 5 �������� ������������ ������� � ��������
			if (CurrentFrame > 5) CurrentFrame -= 5; // ���� ������ � 5 ����� - ������������ �����.
			csprite.setTextureRect(IntRect(67 * int(CurrentFrame), 0, 67, 100)); //���������� �� ����������� �
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right))&&(xPos<744)) { //���� ������ ������� ������� �����
			CurrentFrame += 0.015 * time; //������ ��� ����������� �� "������". ���������� ������� �� 5 �������� ������������ ������� � ��������
			if (CurrentFrame > 5) CurrentFrame -= 5; // ���� ������ � 5 ����� - ������������ �����.
			csprite.setTextureRect(IntRect(67 * int(CurrentFrame), 85, 67, 100)); //���������� �� ����������� �
			csprite.move(0.35 * time, 0);//���������� ���� �������� ��������� ������			
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right))&&(xPos >= 744)){
			CurrentFrame += 0.015 * time; //������ ��� ����������� �� "������". ���������� ������� �� 5 �������� ������������ ������� � ��������
			if (CurrentFrame > 5) CurrentFrame -= 5; // ���� ������ � 5 ����� - ������������ �����.
			csprite.setTextureRect(IntRect(67 * int(CurrentFrame), 85, 67, 100)); //���������� �� ����������� �
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