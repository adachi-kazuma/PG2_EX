#pragma once
class Player
{
public:
	Player(int posX, int posY, int speed, int radius, int MHP, int isAlive);
	void Update(char* keys, char* preKeys);
	void Draw();
	int GetPosX() { return posX; };
	void SetPosX(int posX) { this->posX = posX; };
	int GetPosY() { return posY; };
	void SetPosY(int posY) { this->posY = posY; };
	int GetRadius() { return radius; };
	int GetMHp() { return MHp; };
	void SetMHp(int MHp) { this->MHp = MHp; };
	int GetIsAlive() { return isAlive; };
	void SetIsAlive(int isAlive) { this->isAlive = isAlive; };


private:
	int posX;
	int posY;
	int speed;
	int radius;
	int MHp;
	int isAlive;
	int graphHandle0;
};

