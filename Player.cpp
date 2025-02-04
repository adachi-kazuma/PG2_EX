#include "Player.h"
#include <Novice.h>

Player::Player(int posX, int posY, int speed, int radius, int MHP, int isAlive)
{
	this->posX = posX;
	this->posY = posY;
	this->speed = speed;
	this->radius = radius;
	this->MHp = MHP;
	this->isAlive = isAlive;
	this->graphHandle0 = Novice::LoadTexture("./DDD.png");
}

void Player::Update(char* keys, char* preKeys)
{
	//Ž©‹@_“®‚«
	if (keys[DIK_W])
	{
		posY = posY - 3;
	}
	if (keys[DIK_S])
	{
		posY = posY + 3;
	}
	if (keys[DIK_A])
	{
		posX = posX - 3;
	}
	if (keys[DIK_D])
	{
		posX = posX + 3;
	}
}

void Player::Draw()
{
	Novice::DrawSprite(posX, posY, graphHandle0, 1, 1, 0.0f, WHITE);
}
