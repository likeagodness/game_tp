#include <iostream>
#include <SFML/Window.hpp>
#include <player.h>
#include <map.h>
using sf::Keyboard;

player::player(const float x, const float y) : shooter(x, y, "Textures/playerset.png"), timeBeforeShot(0)
//����������� ������������ - ���������� �������������� �����������, 
//�������� � ���� ��������� ���������� ������ � ���� � ��� ��������,
//������������� ����� �� �������� �� ��������� �� 0
//������������� ����� �� �������� �� ��������� �� 0
{

}

player::~player() //����������� ����������� - ����������
{
	std::cout << "Player "; //�������� �������� ������� ������ - ������ � �������
}

void player::move_1(const sf::Int64 time) //����������� �������-����������� ������ 1
{
	if (Keyboard::isKeyPressed(Keyboard::A)) //���� ������ ������� 'A' 
	{
		t_dir = left; //����������� ������ - �����
		t_Speed = 0.11; //������������� �������� �����������
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) //���� ������ ������� 'D' 
	{
		t_dir = right; //����������� ������ - ������
		t_Speed = 0.11; //������������� �������� �����������
	}

	if (Keyboard::isKeyPressed(Keyboard::W)) //���� ������ ������� 'W' 
	{
		t_dir = up; //����������� ������ - �����
		t_Speed = 0.11; //������������� �������� �����������
	}

	if (Keyboard::isKeyPressed(Keyboard::S)) //���� ������ ������� '����' 
	{
		t_dir = down; //����������� ������ - ����
		t_Speed = 0.11; //������������� �������� �����������
	}

	switch (t_dir) //���� ����� ������������:
	{
	case right: //������, ��
		t_dx = t_Speed; //���������� ���������� x ����� �������� ������ - �������� ������
		t_dy = 0;
		break;

	case left: //�����, ��
		t_dx = -t_Speed; //���������� ���������� x ����� ������������� �������� ������ - �������� �����
		t_dy = 0;
		break;

	case down: //����, ��
		t_dx = 0; 
		t_dy = t_Speed; //���������� ���������� y ����� �������� ������ - �������� ����
		break;

	case up: //�����, ��
		t_dx = 0;
		t_dy = -t_Speed; //���������� ���������� y ����� �������� ������ - �������� �����
		break;
	}

	t_x += t_dx * time; //��������� ���������� x
	t_y += t_dy * time; //��������� ���������� y
}

void player::move_2(const sf::Int64 time) //����������� �������-����������� ������ 2
{
	if (Keyboard::isKeyPressed(Keyboard::Left)) //���� ������ ������� ����� 
	{
		t_dir = left; //����������� ������ - �����
		t_Speed = 0.11; //������������� �������� �����������
	}

	if (Keyboard::isKeyPressed(Keyboard::Right)) //���� ������ ������� ������ 
	{
		t_dir = right; //����������� ������ - ������
		t_Speed = 0.11; //������������� �������� �����������
	}

	if (Keyboard::isKeyPressed(Keyboard::Up)) //���� ������ ������� ����� 
	{
		t_dir = up; //����������� ������ - �����
		t_Speed = 0.11; //������������� �������� �����������
	}

	if (Keyboard::isKeyPressed(Keyboard::Down)) //���� ������ ������� ���� 
	{
		t_dir = down; //����������� ������ - ����
		t_Speed = 0.11; //������������� �������� �����������
	}

	switch (t_dir) //���� ����� ������������:
	{
	case right: //������, ��
		t_dx = t_Speed; //���������� ���������� x ����� �������� ������ - �������� ������
		t_dy = 0;
		break;

	case left: //�����, ��
		t_dx = -t_Speed; //���������� ���������� x ����� ������������� �������� ������ - �������� �����
		t_dy = 0;
		break;

	case down: //����, ��
		t_dx = 0;
		t_dy = t_Speed; //���������� ���������� y ����� �������� ������ - �������� ����
		break;

	case up: //�����, ��
		t_dx = 0;
		t_dy = -t_Speed; //���������� ���������� y ����� �������� ������ - �������� �����
		break;
	}

	t_x += t_dx * time; //��������� ���������� x
	t_y += t_dy * time; //��������� ���������� y
}

void player::update_1(const sf::Int64 time, map& map) //����������� �������-���������� �������-������ 1 �� ����� ���� �� �����
{
	move_1(time); //����������� ������ 1

	t_Speed = 0; //�������� ������ 1 = 0
	t_Sprite.setPosition(t_x, t_y); //������������� ������ ������ �� ��� �����������
	animate(time); //��������� ������
	map_interaction(map); //��������������� ������ � ������
}

void player::update_2(const sf::Int64 time, map& map) //����������� �������-���������� �������-������ 2 �� ����� ���� �� �����
{
	move_2(time); //����������� ������ 2

	t_Speed = 0; //�������� ������ 2 = 0
	t_Sprite.setPosition(t_x, t_y); //������������� ������ ������ �� ��� �����������
	animate(time); //��������� ������
	map_interaction(map); //��������������� ������ � ������
}