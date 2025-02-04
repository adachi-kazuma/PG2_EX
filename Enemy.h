#pragma once
class Enemy
{
public:
	Enemy(int Eposx, int Eposy, int EsizeX, int EsizeY, int enemyspeed, int resporntimer, int resporncount, int isenemyAlive, int enemylife, int Radius);
	void Update();
	void Draw();
	int GetPosx() { return Eposx; };
	int GetPosy() { return Eposy; };
	int GetRadius() { return Radius; };
	int GetRespornCount() { return resporncount; };
	void SetRespornCount(int resporncount) { this->resporncount = resporncount; };
	int GetIsAlive() { return isenemyAlive; };
	void SetIsAlive(int isenemyAlive) { this->isenemyAlive = isenemyAlive; };
	int GetHp() { return enemylife; };
	void SetHp(int enemylife) { this->enemylife = enemylife; };
private:
	int Eposx;
	int Eposy;
	int EsizeX;
	int EsizeY;
	int enemyspeed;
	int resporntimer;
	int resporncount;
	int isenemyAlive;
	int enemylife;
	int Radius;
	int graphHandle1;
};

