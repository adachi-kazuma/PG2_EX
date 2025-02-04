#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy(int Eposx, int Eposy, int EsizeX, int EsizeY, int enemyspeed, int resporntimer, int resporncount, int isenemyAlive, int enemylife, int Radius)
{
	this->Eposx = Eposx;
	this->Eposy = Eposy;
	this->EsizeX = EsizeX;
	this->EsizeY = EsizeY;
	this->enemyspeed = enemyspeed;
	this->resporntimer = resporntimer;
	this->resporncount = resporncount;
	this->isenemyAlive = isenemyAlive;
	this->enemylife = enemylife;
	this->Radius = Radius;
	this->graphHandle1 = Novice::LoadTexture("./tot.png");


}

void Enemy::Update()

{
	Eposx = Eposx + enemyspeed;
	if (Eposx + EsizeX >= 500)
	{
		enemyspeed = enemyspeed * -1;
	}
	if (Eposx - EsizeX <= 0)
	{
		enemyspeed = enemyspeed * -1;
	}

	if (isenemyAlive == 0)
	{
		resporntimer++;

		if (resporntimer >= 180)
		{
			resporntimer = 0;
			isenemyAlive = 1;
		}
	}
}

void Enemy::Draw()
{
	if (isenemyAlive == 1)
	{
		Novice::DrawSprite(Eposx, Eposy, graphHandle1, 1, 1, 0.0f, WHITE);
	}


}
