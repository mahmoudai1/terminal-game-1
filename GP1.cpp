#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <MMSystem.h>
#include <string>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void intro(char y[][138], int& IntroTimer);
void MainMenu(int c, int& ClickFix);
void ReplyF(char z[][138], int&counterFS, int& timerFS, int& rH, int& cH, int& counterFS2, int& rCarFS, int& cCarFS, int& Reply, int& Scene, int& level, int r1OFS1, int r1OFS2, int r1OFS3, int r1OFS4, int r1OFS5, int c1OFS1, int c1OFS2, int c1OFS3, int c1OFS4, int c1OFS5, int r2OFS1, int r2OFS2, int r2OFS3, int r2OFS4, int r2OFS5, int c2OFS1, int c2OFS2, int c2OFS3, int c2OFS4, int c2OFS5, int& rEnemyFS, int& cEnemyFS);
void GameMap(char x[][138], int level);
void StaticObjects(char x[][138], int cO1, int rO1, int cO2, int rO2, int cO3, int rO3, int cO4, int rO4, int cO5, int rO5, int cO6, int rO6, int cO7, int rO7, int cO8, int rO8, int cO9, int rO9);
void DynamicObjects(char x[][138], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, char keyB, int AutoWalk);
void StaticFloor(char x[][138], int& cF, int CounterFloor, int level);
void StaticHero(char x[][138], int &rH, int &cH, int countRLHL1, int& CountStart, int& LeftLook, int rEv, int Reload, int& ActionReload, int level, int rB, int cB);
void StaticHero5(char x[][138], int &rH, int &cH, int countRLHL1, int& CountStart, int& LeftLook, int Reload, int ActionReload, int level, int rB, int cB);
void DynamicHero(char x[][138], int& rH, int& cH, char keyB, int& countRLHL1, int& flag1, int& CounterUntilStop, int& pass1, int& pass2, int& lose1, int& ScrollCounter, int& GetOut, int& LeftLook, int& rEv, int& level, int& DeathT, int& shoot1, int& SkateIn, int& rSkate, int& cSkate, int& RopeIn, int& rR, int & cR, int& rMS1, int& cMS1, int& rMS2, int& cMS2, int& ClickShot, int& WhichShot, int& rB, int &cB, int &ct, int win, int& rEvR, int& cT6, int& cFC, int& TelephRide, int& ladder, int& AutoWalk, int& AutoWalkCounter);
void LandCheck(char x[][138], int& rH, int& cH, int& flag1, int GetOut, int level, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4);
void AutoForward(char x[][138], int& rH, int& cH, int& countRLHL1, int& flag1, int& CounterUntilStop, int& pass1, int& pass2, int& lose1, int& ScrollCounter, int& GetOut, int& LeftLook, int& rEv, int& level, int& DeathT, int& shoot1, int& SkateIn, int& rSkate, int& cSkate, int& RopeIn, int& rR, int & cR, int& rMS1, int& cMS1, int& rMS2, int& cMS2, int& ClickShot, int& WhichShot, int& rB, int &cB, int &ct, int win, int& rEvR, int& cT6, int& cFC, int& TelephRide, int& ladder, int Reload, int ActionReload, int& AutoWalk);
void Constructor(char x[][138], int rH, int cH, int &ConstructorCount, int timer, int CounterUntilStop, int rGuide, int cGuide, int& cC, int level, int GetOut, int timer2, int timer3, int BSc, int flagScore1, int flagScore, int flagScore3, int timer4, int flagTime1, int flagTime2, int flagTime3, int TSc, int mins, int flagScore4, int flagTime4, int timer5, int win, int timerBSC, int rFC, int cFC, int TelephRide);
void AutoBackward(char x[][138], int& rH, int& cH, int& lose1, int& pass1, int& pass2, int& cF, int& LeftLook, int CounterUntilStop, int& cO1, int& cC, int& rO1, int& DeathT, int& countRLHL1, int level);
void ToLand(char x[][138], int rH, int cH, int& flag1, int GetOut, int LeftLook, int level, int rEv, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4);
void JumpReaction(char x[][138], int& rH, int& cH, int& flag1, int GetOut, int& LeftLook, int level, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4);
void LeftHandMoveH1(char x[][138], int rH, int cH, int countRLHL1, int Reload, int& ReloadAction, int level, int& rB, int cB);
void RightHandMoveH1(char x[][138], int rH, int cH, int countRLHL1);
void RightLegMoveH1(char x[][138], int& rH, int& cH, int countRLH1);
void LeftLegMoveH1(char x[][138], int& rH, int& cH, int countRLHL1);
void LevelCounter(char x[][138], int Stage);
void TimeCounter(char x[][138], int &mins, int &secs, int CounterUntilStop, int& lose1, int& DeathT, int level, int shoot1);
void HealthBar(char x[][138], int rH, int cH, int& shoot1, int& lose1, int& DeathT, int level, int& countHearts, int& countHearts2, int mins);
void HighScore(char x[][138], int rH, int cH, int& Scounter, int CounterUntilStop, int& HScounter, int level, int shoot1, int flagScore1, int flagScore2, int flagScore3, int AutoWalk);
void StaticGunShot(char x[][138], int rE1, int cE1, int& rEG1, int& cEG1, int& countG1, int CounterUntilStop, int GetOut);
void DynamicGunShot(char x[][138], int& rE1, int& cE1, int& rEG1, int& cEG1, int& countG1, int CounterUntilStop, int rH, int cH, int& shoot1, int GetOut, int& DelayShot, int& lose1, int& DeathT);
void StaticEnemy(char x[][138], int cE1, int rE1, int CounterUntilStop, int countRLEL1, int Reload, int ActionReload, int level, int rB, int cB);
void DynamicEnemy(char x[][138], int& cE1, int& rE1, int CounterUntilStop, int& countRLEL1, int rEG1, int cEG1, int countG1, int GetOut);
void StaticGunShot2(char x[][138], int rE2, int cE2, int& rEG2, int& cEG2, int& countG2, int CounterUntilStop, int GetOut);
void DynamicGunShot2(char x[][138], int& rE2, int& cE2, int& rEG2, int& cEG2, int& countG2, int CounterUntilStop, int rH, int cH, int& shoot1, int GetOut, int& DelayShot, int& DeathT);
void StaticEnemy2(char x[][138], int cE2, int rE2, int CounterUntilStop, int countRLEL2, int Reload, int ActionReload, int level, int rB, int cB);
void DynamicEnemy2(char x[][138], int& cE2, int& rE2, int CounterUntilStop, int& countRLEL2, int rEG2, int cEG2, int countG2, int GetOut);
void StaticCar1(char x[][138], int cCar, int rCar, int cH, int rH, int level, int countCar1, int& ratio);
void DynamicCar1(char x[][138], int& cCar, int& rCar, int& cH, int& rH, int& level, int& countCar1, int& lose1, int& DeathT, int& shoot1, int& ratio1, int cCar2, int rCar2, int& flagC, int timer2, int& c2);
void StaticCar2(char x[][138], int c, int r, int cH, int rH, int level, int sarena, int& ratio1, int& flagC);
void DynamicCar2(char x[][138], int& c, int& r, int& cH, int& rH, int& level, int& sarena, int& lose1, int& DeathT, int& Shoot1, int& ratio1, int& flagC);
void StaticPlane1(char x[][138], int r, int c, int rH, int cH, int level, int ratio);
void DynamicPlane1(char x[][138], int& r1, int& c1, int& rH, int& cH, int level, int& ratio, int& c2, int& flagP2, int& c3, int& r2, int& r3);
void StaticPlane2(char x[][138], int r, int c, int rH, int cH, int level, int ratio, int flagP2);
void DynamicPlane2(char x[][138], int& r, int& c, int& rH, int& cH, int level, int& ratio, int& flagP22);
void StaticPlane3(char x[][138], int r, int c, int rH, int cH, int level, int ratio, int flagP2);
void DynamicPlane3(char x[][138], int& r, int& c, int& rH, int& cH, int level, int& ratio, int& flagP22);
void StaticPlaneShot1(char x[][138], int& rPG1, int& cPG1, int& rPG2, int& cPG2, int& rPG3, int& cPG3, int& ratio, int r1, int c1, int r2, int c2, int r3, int c3, int& shoot1, int rH, int cH, int& DeathT);
void DynamicPlaneShot1(char x[][138], int& rPG1, int& cPG1, int& rPG2, int& cPG2, int& rPG3, int& cPG3, int ratio, int r1, int c1, int r2, int c2, int r3, int c3, int& shoot1, int rH, int cH, int& DeathT);
void StaticSkate(char x[][138], int r, int c, int rH, int cH, int& SkateIn);
void Output(char x[][138], int& ScrollCounter, int& cH);

struct PlayerInfo
{
	int PlayerScore;
	int TemprScore;
	int PlayerDiedLevel;
	char PlayerName[100];
};

void InsideMenu(char keyB, PlayerInfo P[], int& startgame, int H1, int H2, int H3, int HS, int k, int ks, int ClickFix, int& Reply)
{


	if (keyB == 'h' || keyB == 'H')
	{
		if (ClickFix == 1)
		{
			if (k > 1)
			{
				system("cls");
				cout << "\n\t\t\t\t\b\b Top three\n\n";
				if (k > 1)
				{
					cout << "1-" << P[H1].PlayerName << "\t\t\t\t\t\t" << P[H1].PlayerScore;
				}

				if (k > 2)
				{
					cout << "\n\n2-" << P[H2].PlayerName << "\t\t\t\t\t\t" << P[H2].PlayerScore;

				}

				if (k > 3)
				{
					cout << "\n\n3-" << P[H3].PlayerName << "\t\t\t\t\t\t" << P[H3].PlayerScore;

				}
				cout << "\n\n__________________________________________________________________________________________________________________________________________\n\n";
				cout << "\t\t\t\tOthers\n\n";
				if (k > 4)
				{
					for (int i = 1; i < k; i++)
					{
						if (i != H1 && i != H2 && i != H3)
						{
							cout << "- " << P[i].PlayerName << " (" << P[i].PlayerScore << ")\n\n";

						}
					}
				}
				if (k == 1)
				{
					cout << "\n\n\nX - back\t\tH - Analytics\t\tS - Start the game\n\n";
				}

				if (k > 1)
				{
					cout << "\n\n\nX - back\t\tH - Analytics\t\tS - Start the game\t\tR - Reply Story\n\n";

				}
			}
			else
			{
				system("cls");
				cout << "\nThere is no analytics yet to show.\n\n";
				if (k == 1)
				{
					cout << "\n\n\nX - back\t\tH - Analytics\t\tS - Start the game\n\n";
				}

				if (k > 1)
				{
					cout << "\n\n\nX - back\t\tH - Analytics\t\tS - Start the game\t\tR - Reply Story\n\n";

				}
			}
		}
	}

	else if (keyB == 'x' || keyB == 'X')
	{
		system("cls");
		MainMenu(k, ClickFix);
	}

	else if (keyB == 's' || keyB == 'S')
	{
		if (ClickFix == 1)
		{
			startgame = 1;
		}
	}

	else if (keyB == 'i' || keyB == 'I')
	{
		if (ClickFix == 1)
		{
			system("cls");

			cout << "\n\t--Instructions(15)--\n\n\n";
			cout << "1- Use W,A,S,D and space-bar to move.\n\n";
			cout << "2- Using 's' is to fast landing.\n\n";
			cout << "3- You'll need to use 'e' to do things so be aware!\n\n";
			cout << "4- You only have 10-minutes to do the mission, do not waste your time!\n\n";
			cout << "5- In the top left, there's a mini-guide will help you what you should do.\n\n";
			cout << "6- The game includes 5 levels.\n\n";
			cout << "7- Your health bar is 6, and it's re-injecting every level.\n\n";
			cout << "8- If you pass a level with 6 or 5 bars, you will get more bonus score and time.\n\n";
			cout << "9- If you run to the left, you die.\n\n";
			cout << "10- Each level, game color will change according to the difficulty.\n\n";
			cout << "11- If your health lower than 2 bars (or) the time less than 2, you will get notified by the game color (grey then red).\n\n";
			cout << "12- You will see hearts in some levels, take them, this will raise your health.\n\n";
			cout << "13- In level 1, each shot is decreasing your health by 1.\n";
			cout << "    In level 2, by 2.\n";
			cout << "    In level 3, by 3.\n";
			cout << "    In level 4, by 4.\n";
			cout << "    In level 5, by 2.\n\n";
			cout << "14- When you do try-again, you will start with the latest highscore had made, so try to pass it.\n\n";
			cout << "15- Jump, speed and in-game design is variable according to level atmosphere.\n\n\n\n";
			if (k == 1)
			{
				cout << "\n\n\nX - back\t\tH - Analytics\t\tS - Start the game\n\n";
			}

			if (k > 1)
			{
				cout << "\n\n\nX - back\t\tH - Analytics\t\tS - Start the game\t\tR - Reply Story\n\n";

			}
		}
	}

	else if (keyB == 'r' || keyB == 'R')
	{
		if (ClickFix == 1 && k > 1 && (Reply == 0 || Reply == 2))
		{
			Reply = 1;
		}
	}

	else
	{
		system("cls");
		MainMenu(k, ClickFix);
	}

}

void MainMenu(int c, int& ClickFix)
{

	cout << "\nI - Full instructions list\n\n";
	cout << "H - Who played and scores\n\n";
	cout << "S - Start Game!\n\n";
	if (c > 1)
	{
		cout << "R - Reply Story\n\n";
	}
}

void outputy(char y[][138])
{
	system("cls");
	for (int r = 0; r < 48; r++)
	{
		for (int c = 0; c < 138; c++)
		{
			cout << y[r][c];
		}
	}
}

void intro(char y[][138], int& IntroTimer)
{
	if (IntroTimer == -1)
	{
		for (int r = 0; r < 48; r++)
		{
			for (int c = 0; c < 138; c++)
			{
				y[r][c] = ' ';
			}
		}

	}

	if (IntroTimer >= -1 && IntroTimer <= 5)
	{

		y[22][57] = 'M';
		y[22][58] = 'I';
		y[22][59] = 'S';
		y[22][60] = 'S';
		y[22][61] = 'I';
		y[22][62] = 'O';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = 'M';
		y[22][67] = 'P';
		y[22][68] = 'O';
		y[22][69] = 'S';
		y[22][70] = 'S';
		y[22][71] = 'I';
		y[22][72] = 'B';
		y[22][73] = 'L';
		y[22][74] = 'E';

	}



	if (IntroTimer > 5 && IntroTimer <= 6)
	{
		y[22][57] = 'M';
		y[22][58] = 'I';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = 'I';
		y[22][62] = 'O';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = 'M';
		y[22][67] = 'P';
		y[22][68] = 'O';
		y[22][69] = 'S';
		y[22][70] = 'S';
		y[22][71] = 'I';
		y[22][72] = 'B';
		y[22][73] = 'L';
		y[22][74] = 'E';

	}



	if (IntroTimer > 6 && IntroTimer <= 7)
	{
		y[22][57] = 'M';
		y[22][58] = 'I';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = 'I';
		y[22][62] = 'O';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = 'M';
		y[22][67] = ' ';
		y[22][68] = 'O';
		y[22][69] = 'S';
		y[22][70] = 'S';
		y[22][71] = 'I';
		y[22][72] = 'B';
		y[22][73] = 'L';
		y[22][74] = 'E';

	}



	if (IntroTimer > 7 && IntroTimer <= 8)
	{
		y[22][57] = 'M';
		y[22][58] = 'I';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = 'I';
		y[22][62] = 'O';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = 'M';
		y[22][67] = ' ';
		y[22][68] = 'O';
		y[22][69] = 'S';
		y[22][70] = 'S';
		y[22][71] = 'I';
		y[22][72] = ' ';
		y[22][73] = 'L';
		y[22][74] = 'E';

	}



	if (IntroTimer > 8 && IntroTimer <= 9)
	{
		y[22][57] = 'M';
		y[22][58] = 'I';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = 'I';
		y[22][62] = 'O';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = 'M';
		y[22][67] = ' ';
		y[22][68] = 'O';
		y[22][69] = 'S';
		y[22][70] = ' ';
		y[22][71] = 'I';
		y[22][72] = ' ';
		y[22][73] = 'L';
		y[22][74] = 'E';

	}



	if (IntroTimer > 9 && IntroTimer <= 10)
	{
		y[22][57] = 'M';
		y[22][58] = 'I';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = 'I';
		y[22][62] = ' ';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = 'M';
		y[22][67] = ' ';
		y[22][68] = 'O';
		y[22][69] = 'S';
		y[22][70] = ' ';
		y[22][71] = 'I';
		y[22][72] = ' ';
		y[22][73] = 'L';
		y[22][74] = 'E';

	}



	if (IntroTimer > 10 && IntroTimer <= 11)
	{
		y[22][57] = 'M';
		y[22][58] = 'I';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = 'I';
		y[22][62] = ' ';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = 'O';
		y[22][69] = 'S';
		y[22][70] = ' ';
		y[22][71] = 'I';
		y[22][72] = ' ';
		y[22][73] = 'L';
		y[22][74] = 'E';

	}



	if (IntroTimer > 11 && IntroTimer <= 12)
	{
		y[22][57] = 'M';
		y[22][58] = 'I';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = 'I';
		y[22][62] = ' ';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = 'O';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = 'I';
		y[22][72] = ' ';
		y[22][73] = 'L';
		y[22][74] = 'E';

	}



	if (IntroTimer > 12 && IntroTimer <= 13)
	{
		y[22][57] = 'M';
		y[22][58] = 'I';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = 'I';
		y[22][62] = ' ';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = 'O';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = 'I';
		y[22][72] = ' ';
		y[22][73] = ' ';
		y[22][74] = 'E';

	}



	if (IntroTimer > 13 && IntroTimer <= 14)
	{
		y[22][57] = 'M';
		y[22][58] = ' ';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = 'I';
		y[22][62] = ' ';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = 'O';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = 'I';
		y[22][72] = ' ';
		y[22][73] = ' ';
		y[22][74] = 'E';

	}



	if (IntroTimer > 14 && IntroTimer <= 15)
	{
		y[22][57] = 'M';
		y[22][58] = ' ';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = ' ';
		y[22][62] = ' ';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = 'O';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = 'I';
		y[22][72] = ' ';
		y[22][73] = ' ';
		y[22][74] = 'E';

	}



	if (IntroTimer > 15 && IntroTimer <= 16)
	{
		y[22][57] = 'M';
		y[22][58] = ' ';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = ' ';
		y[22][62] = ' ';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = ' ';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = 'I';
		y[22][72] = ' ';
		y[22][73] = ' ';
		y[22][74] = 'E';

	}



	if (IntroTimer > 16 && IntroTimer <= 17)
	{
		y[22][57] = ' ';
		y[22][58] = ' ';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = ' ';
		y[22][62] = ' ';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = ' ';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = 'I';
		y[22][72] = ' ';
		y[22][73] = ' ';
		y[22][74] = 'E';

	}



	if (IntroTimer > 17 && IntroTimer <= 18)
	{
		y[22][57] = ' ';
		y[22][58] = ' ';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = ' ';
		y[22][62] = ' ';
		y[22][63] = 'N';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = ' ';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = ' ';
		y[22][72] = ' ';
		y[22][73] = ' ';
		y[22][74] = 'E';

	}



	if (IntroTimer > 18 && IntroTimer <= 19)
	{
		y[22][57] = ' ';
		y[22][58] = ' ';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = ' ';
		y[22][62] = ' ';
		y[22][63] = ' ';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = ' ';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = 'I';
		y[22][72] = ' ';
		y[22][73] = ' ';
		y[22][74] = 'E';

	}



	if (IntroTimer > 19 && IntroTimer <= 20)
	{
		y[22][57] = ' ';
		y[22][58] = ' ';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = ' ';
		y[22][62] = ' ';
		y[22][63] = ' ';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = ' ';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = ' ';
		y[22][72] = ' ';
		y[22][73] = ' ';
		y[22][74] = 'E';

	}



	if (IntroTimer > 20 && IntroTimer <= 21)
	{
		y[22][57] = ' ';
		y[22][58] = ' ';
		y[22][59] = 'S';
		y[22][60] = ' ';
		y[22][61] = ' ';
		y[22][62] = ' ';
		y[22][63] = ' ';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = ' ';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = ' ';
		y[22][72] = ' ';
		y[22][73] = ' ';
		y[22][74] = ' ';

	}



	if (IntroTimer > 21 && IntroTimer <= 22)
	{
		y[22][57] = ' ';
		y[22][58] = ' ';
		y[22][59] = ' ';
		y[22][60] = ' ';
		y[22][61] = ' ';
		y[22][62] = ' ';
		y[22][63] = ' ';
		y[22][64] = ' ';
		y[22][65] = 'I';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = ' ';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = ' ';
		y[22][72] = ' ';
		y[22][73] = ' ';
		y[22][74] = ' ';

	}



	if (IntroTimer > 22 && IntroTimer <= 23)
	{
		y[22][57] = ' ';
		y[22][58] = ' ';
		y[22][59] = ' ';
		y[22][60] = ' ';
		y[22][61] = ' ';
		y[22][62] = ' ';
		y[22][63] = ' ';
		y[22][64] = ' ';
		y[22][65] = ' ';
		y[22][66] = ' ';
		y[22][67] = ' ';
		y[22][68] = ' ';
		y[22][69] = ' ';
		y[22][70] = ' ';
		y[22][71] = ' ';
		y[22][72] = ' ';
		y[22][73] = ' ';
		y[22][74] = ' ';

	}


}

void GameMap(char x[][138], int level)
{

	for (int r = 0; r < 48; r++)
	{
		for (int c = 0; c < 138; c++)
		{
			x[r][c] = ' ';
		}
	}



	if (level == 1)
	{
		x[46][42] = '|';
		x[45][42] = '|';
		for (int c = 43; c < 49; c++)					//ROCKS
		{
			x[45][c] = 45;
		}

		x[46][48] = '|';
		x[45][48] = '|';

		////////////////////////////////////////////////////////////////////////////////////

		x[46][61] = '|';
		x[45][61] = '|';
		x[43][61] = '|';
		x[41][61] = '|';
		x[42][61] = '|';
		x[44][61] = '|';

		for (int c = 62; c < 68; c++)					//ROCKS
		{
			x[45][c] = 45;
		}
		for (int c = 62; c < 68; c++)					//ROCKS
		{
			x[43][c] = 45;
		}
		for (int c = 62; c < 68; c++)					//ROCKS
		{
			x[41][c] = 45;
		}

		x[46][67] = '|';
		x[45][67] = '|';
		x[43][67] = '|';
		x[41][67] = '|';
		x[42][67] = '|';
		x[44][67] = '|';

		////////////////////////////////////////////////////////////////////////////////////

		x[43][75] = '|';
		x[44][75] = '|';
		x[46][75] = '|';
		x[45][75] = '|';
		for (int c = 76; c < 82; c++)					//ROCKS
		{
			x[45][c] = 45;
		}
		for (int c = 76; c < 82; c++)					//ROCKS
		{
			x[43][c] = 45;
		}

		x[46][81] = '|';
		x[45][81] = '|';
		x[43][81] = '|';
		x[44][81] = '|';

		/////////////////////////////////////////////////////////////////////////////////////

		x[46][97] = '|';
		x[45][97] = '|';
		for (int c = 98; c < 104; c++)					//ROCKS
		{
			x[45][c] = 45;
		}

		x[46][103] = '|';
		x[45][103] = '|';

	}

	if (level == 2)
	{
		x[35][22] = '|';
		x[34][22] = '|';
		for (int c = 23; c < 27; c++)					//ROCKS
		{
			x[34][c] = 45;
		}

		x[34][26] = '|';
		x[35][26] = '|';




		x[35][52] = '|';
		x[34][52] = '|';
		for (int c = 53; c < 57; c++)					//ROCKS
		{
			x[34][c] = 45;
		}

		x[34][56] = '|';
		x[35][56] = '|';



		x[35][82] = '|';
		x[34][82] = '|';
		for (int c = 83; c < 87; c++)					//ROCKS
		{
			x[34][c] = 45;
		}

		x[34][86] = '|';
		x[35][86] = '|';



		x[35][122] = '|';
		x[34][122] = '|';
		for (int c = 123; c < 138; c++)					//ROCKS
		{
			x[34][c] = 45;
		}



	}
}

void GameMap6(char x[][138], int level, int TelephRide, int ladder, int rH, int cH)
{

	for (int r = 0; r < 48; r++)
	{
		for (int c = 0; c < 138; c++)
		{
			x[r][c] = ' ';
		}
	}


	if (level == 6 && TelephRide == 0)
	{
		for (int r = 32; r <= 47; r++)
		{
			x[r][19] = 179;
		}
		for (int r = 32; r <= 47; r++)
		{
			x[r][30] = 179;
		}

		for (int r = 33; r <= 46; r += 3)
		{
			for (int c = 20; c < 30; c++)
			{
				x[r][c] = '_';
			}
		}
	}

	if (level == 6 && x[rH][cH + 9] != ' ' && ladder == 0)
	{
		x[rH - 1][cH + 6] = 'T';
		x[rH - 1][cH + 7] = 'A';
		x[rH - 1][cH + 8] = 'P';
		x[rH - 1][cH + 9] = ' ';
		x[rH - 1][cH + 10] = 'E';
		x[rH - 1][cH + 11] = ' ';
		x[rH - 1][cH + 12] = 'T';
		x[rH - 1][cH + 13] = 'O';
		x[rH - 1][cH + 14] = ' ';
		x[rH - 1][cH + 15] = 'C';
		x[rH - 1][cH + 16] = 'L';
		x[rH - 1][cH + 17] = 'I';
		x[rH - 1][cH + 18] = 'M';
		x[rH - 1][cH + 19] = 'B';
	}

	if (level == 6 && ladder == 2 && rH == 30)
	{
		x[rH - 1][cH + 6] = 'T';
		x[rH - 1][cH + 7] = 'A';
		x[rH - 1][cH + 8] = 'P';
		x[rH - 1][cH + 9] = ' ';
		x[rH - 1][cH + 10] = 'E';
		x[rH - 1][cH + 11] = ' ';
		x[rH - 1][cH + 12] = 'T';
		x[rH - 1][cH + 13] = 'O';
		x[rH - 1][cH + 14] = ' ';
		x[rH - 1][cH + 15] = 'R';
		x[rH - 1][cH + 16] = 'I';
		x[rH - 1][cH + 17] = 'D';
		x[rH - 1][cH + 18] = 'E';
	}

	if (level == 6 && ladder == 0 && TelephRide == 2)
	{
		for (int c = 30; c <= 58; c++)
		{
			x[46][c] = '_';
		}
		for (int c = 30; c <= 58; c++)
		{
			x[41][c] = '_';
		}
		for (int c = 31; c <= 57; c += 5)
		{
			for (int r = 42; r < 47; r++)
			{
				x[r][c] = 179;
			}
		}
	}
}

void StaticObjects(char x[][138], int cO1, int rO1, int cO2, int rO2, int cO3, int rO3, int cO4, int rO4, int cO5, int rO5, int cO6, int rO6, int cO7, int rO7, int cO8, int rO8, int cO9, int rO9)
{
	{

		x[rO1 + 23][cO1] = 179;
		x[rO1 + 22][cO1] = 179;
		x[rO1 + 21][cO1] = 179;
		x[rO1 + 20][cO1] = 179;
		x[rO1 + 19][cO1] = 179;
		x[rO1 + 18][cO1] = 179;
		x[rO1 + 17][cO1] = 179;
		x[rO1 + 16][cO1] = 179;
		x[rO1 + 15][cO1] = 179;
		x[rO1 + 14][cO1] = 179;
		x[rO1 + 13][cO1] = 179;
		x[rO1 + 12][cO1] = 179;
		x[rO1 + 11][cO1] = 179;
		x[rO1 + 10][cO1] = 179;
		x[rO1 + 9][cO1] = 179;
		x[rO1 + 8][cO1] = 179;
		x[rO1 + 7][cO1] = 179;
		x[rO1 + 6][cO1] = 179;
		x[rO1 + 5][cO1] = 179;

		x[rO1 + 5][cO1 - 1] = 22;
	}

	{
		x[rO2 + 23][cO2] = 186;
		x[rO2 + 22][cO2] = 186;
		x[rO2 + 21][cO2] = 186;
		x[rO2 + 20][cO2] = 186;
		x[rO2 + 19][cO2] = 186;
		x[rO2 + 18][cO2] = 186;
		x[rO2 + 17][cO2] = 186;
		x[rO2 + 16][cO2] = 186;
		x[rO2 + 15][cO2] = 186;
		x[rO2 + 14][cO2] = 186;
		x[rO2 + 13][cO2] = 186;

		x[rO2 + 13][cO2 - 8] = 176;
		x[rO2 + 13][cO2 - 7] = 176;
		x[rO2 + 13][cO2 - 6] = 176;
		x[rO2 + 13][cO2 - 5] = 176;
		x[rO2 + 13][cO2 - 4] = 176;
		x[rO2 + 13][cO2 - 3] = 176;
		x[rO2 + 13][cO2 - 2] = 176;
		x[rO2 + 13][cO2 - 1] = 176;
		x[rO2 + 13][cO2] = 176;
		x[rO2 + 13][cO2 + 1] = 176;
		x[rO2 + 13][cO2 + 2] = 176;
		x[rO2 + 13][cO2 + 3] = 176;
		x[rO2 + 13][cO2 + 4] = 176;
		x[rO2 + 13][cO2 + 5] = 176;
		x[rO2 + 13][cO2 + 6] = 176;
		x[rO2 + 13][cO2 + 7] = 176;
		x[rO2 + 13][cO2 + 8] = 176;

		x[rO2 + 12][cO2 - 7] = 176;
		x[rO2 + 12][cO2 - 6] = 176;
		x[rO2 + 12][cO2 - 5] = 176;
		x[rO2 + 12][cO2 - 4] = 176;
		x[rO2 + 12][cO2 - 3] = 176;
		x[rO2 + 12][cO2 - 2] = 176;
		x[rO2 + 12][cO2 - 1] = 176;
		x[rO2 + 12][cO2] = 176;
		x[rO2 + 12][cO2 + 1] = 176;
		x[rO2 + 12][cO2 + 2] = 176;
		x[rO2 + 12][cO2 + 3] = 176;
		x[rO2 + 12][cO2 + 4] = 176;
		x[rO2 + 12][cO2 + 5] = 176;
		x[rO2 + 12][cO2 + 6] = 176;
		x[rO2 + 12][cO2 + 7] = 176;

		x[rO2 + 11][cO2 - 6] = 176;
		x[rO2 + 11][cO2 - 5] = 176;
		x[rO2 + 11][cO2 - 4] = 176;
		x[rO2 + 11][cO2 - 3] = 176;
		x[rO2 + 11][cO2 - 2] = 176;
		x[rO2 + 11][cO2 - 1] = 176;
		x[rO2 + 11][cO2] = 176;
		x[rO2 + 11][cO2 + 1] = 176;
		x[rO2 + 11][cO2 + 2] = 176;
		x[rO2 + 11][cO2 + 3] = 176;
		x[rO2 + 11][cO2 + 4] = 176;
		x[rO2 + 11][cO2 + 5] = 176;
		x[rO2 + 11][cO2 + 6] = 176;

		x[rO2 + 10][cO2 - 5] = 176;
		x[rO2 + 10][cO2 - 4] = 176;
		x[rO2 + 10][cO2 - 3] = 176;
		x[rO2 + 10][cO2 - 2] = 176;
		x[rO2 + 10][cO2 - 1] = 176;
		x[rO2 + 10][cO2] = 176;
		x[rO2 + 10][cO2 + 1] = 176;
		x[rO2 + 10][cO2 + 2] = 176;
		x[rO2 + 10][cO2 + 3] = 176;
		x[rO2 + 10][cO2 + 4] = 176;
		x[rO2 + 10][cO2 + 5] = 176;

		x[rO2 + 9][cO2 - 4] = 176;
		x[rO2 + 9][cO2 - 3] = 176;
		x[rO2 + 9][cO2 - 2] = 176;
		x[rO2 + 9][cO2 - 1] = 176;
		x[rO2 + 9][cO2] = 176;
		x[rO2 + 9][cO2 + 1] = 176;
		x[rO2 + 9][cO2 + 2] = 176;
		x[rO2 + 9][cO2 + 3] = 176;
		x[rO2 + 9][cO2 + 4] = 176;

		x[rO2 + 8][cO2 - 3] = 176;
		x[rO2 + 8][cO2 - 2] = 176;
		x[rO2 + 8][cO2 - 1] = 176;
		x[rO2 + 8][cO2] = 176;
		x[rO2 + 8][cO2 + 1] = 176;
		x[rO2 + 8][cO2 + 2] = 176;
		x[rO2 + 8][cO2 + 3] = 176;

		x[rO2 + 7][cO2 - 2] = 176;
		x[rO2 + 7][cO2 - 1] = 176;
		x[rO2 + 7][cO2] = 176;
		x[rO2 + 7][cO2 + 1] = 176;
		x[rO2 + 7][cO2 + 2] = 176;

		x[rO2 + 6][cO2 - 1] = 176;
		x[rO2 + 6][cO2] = 176;
		x[rO2 + 6][cO2 + 1] = 176;

		x[rO2 + 5][cO2] = 176;


	}


	{
		x[rO3 + 23][cO3] = 179;
		x[rO3 + 22][cO3] = 179;
		x[rO3 + 21][cO3] = 179;
		x[rO3 + 20][cO3] = 179;
		x[rO3 + 19][cO3] = 179;
		x[rO3 + 18][cO3] = 179;
		x[rO3 + 17][cO3] = 179;
		x[rO3 + 16][cO3] = 179;
		x[rO3 + 15][cO3] = 179;
		x[rO3 + 14][cO3] = 179;
		x[rO3 + 13][cO3] = 179;
		x[rO3 + 12][cO3] = 179;
		x[rO3 + 11][cO3] = 179;
		x[rO3 + 10][cO3] = 179;
		x[rO3 + 9][cO3] = 179;
		x[rO3 + 8][cO3] = 179;
		x[rO3 + 7][cO3] = 179;
		x[rO3 + 6][cO3] = 179;
		x[rO3 + 5][cO3] = 179;

		x[rO3 + 5][cO3 - 1] = 22;
	}

	{
		x[rO4 + 23][cO4] = 179;
		x[rO4 + 22][cO4] = 179;
		x[rO4 + 21][cO4] = 179;
		x[rO4 + 20][cO4] = 179;
		x[rO4 + 19][cO4] = 179;
		x[rO4 + 18][cO4] = 179;
		x[rO4 + 17][cO4] = 179;
		x[rO4 + 16][cO4] = 179;
		x[rO4 + 15][cO4] = 179;
		x[rO4 + 14][cO4] = 179;
		x[rO4 + 13][cO4] = 179;
		x[rO4 + 12][cO4] = 179;
		x[rO4 + 11][cO4] = 179;
		x[rO4 + 10][cO4] = 179;
		x[rO4 + 9][cO4] = 179;
		x[rO4 + 8][cO4] = 179;
		x[rO4 + 7][cO4] = 179;
		x[rO4 + 6][cO4] = 179;
		x[rO4 + 5][cO4] = 179;


		x[rO4 + 5][cO4 - 1] = 22;
	}


	{
		x[rO5 + 23][cO5] = 186;
		x[rO5 + 22][cO5] = 186;
		x[rO5 + 21][cO5] = 186;
		x[rO5 + 20][cO5] = 186;
		x[rO5 + 19][cO5] = 186;
		x[rO5 + 18][cO5] = 186;
		x[rO5 + 17][cO5] = 186;
		x[rO5 + 16][cO5] = 186;
		x[rO5 + 15][cO5] = 186;
		x[rO5 + 14][cO5] = 186;
		x[rO5 + 13][cO5] = 186;

		x[rO5 + 13][cO5 - 8] = 176;
		x[rO5 + 13][cO5 - 7] = 176;
		x[rO5 + 13][cO5 - 6] = 176;
		x[rO5 + 13][cO5 - 5] = 176;
		x[rO5 + 13][cO5 - 4] = 176;
		x[rO5 + 13][cO5 - 3] = 176;
		x[rO5 + 13][cO5 - 2] = 176;
		x[rO5 + 13][cO5 - 1] = 176;
		x[rO5 + 13][cO5] = 176;
		x[rO5 + 13][cO5 + 1] = 176;
		x[rO5 + 13][cO5 + 2] = 176;
		x[rO5 + 13][cO5 + 3] = 176;
		x[rO5 + 13][cO5 + 4] = 176;
		x[rO5 + 13][cO5 + 5] = 176;
		x[rO5 + 13][cO5 + 6] = 176;
		x[rO5 + 13][cO5 + 7] = 176;
		x[rO5 + 13][cO5 + 8] = 176;

		x[rO5 + 12][cO5 - 7] = 176;
		x[rO5 + 12][cO5 - 6] = 176;
		x[rO5 + 12][cO5 - 5] = 176;
		x[rO5 + 12][cO5 - 4] = 176;
		x[rO5 + 12][cO5 - 3] = 176;
		x[rO5 + 12][cO5 - 2] = 176;
		x[rO5 + 12][cO5 - 1] = 176;
		x[rO5 + 12][cO5] = 176;
		x[rO5 + 12][cO5 + 1] = 176;
		x[rO5 + 12][cO5 + 2] = 176;
		x[rO5 + 12][cO5 + 3] = 176;
		x[rO5 + 12][cO5 + 4] = 176;
		x[rO5 + 12][cO5 + 5] = 176;
		x[rO5 + 12][cO5 + 6] = 176;
		x[rO5 + 12][cO5 + 7] = 176;

		x[rO5 + 11][cO5 - 6] = 176;
		x[rO5 + 11][cO5 - 5] = 176;
		x[rO5 + 11][cO5 - 4] = 176;
		x[rO5 + 11][cO5 - 3] = 176;
		x[rO5 + 11][cO5 - 2] = 176;
		x[rO5 + 11][cO5 - 1] = 176;
		x[rO5 + 11][cO5] = 176;
		x[rO5 + 11][cO5 + 1] = 176;
		x[rO5 + 11][cO5 + 2] = 176;
		x[rO5 + 11][cO5 + 3] = 176;
		x[rO5 + 11][cO5 + 4] = 176;
		x[rO5 + 11][cO5 + 5] = 176;
		x[rO5 + 11][cO5 + 6] = 176;

		x[rO5 + 10][cO5 - 5] = 176;
		x[rO5 + 10][cO5 - 4] = 176;
		x[rO5 + 10][cO5 - 3] = 176;
		x[rO5 + 10][cO5 - 2] = 176;
		x[rO5 + 10][cO5 - 1] = 176;
		x[rO5 + 10][cO5] = 176;
		x[rO5 + 10][cO5 + 1] = 176;
		x[rO5 + 10][cO5 + 2] = 176;
		x[rO5 + 10][cO5 + 3] = 176;
		x[rO5 + 10][cO5 + 4] = 176;
		x[rO5 + 10][cO5 + 5] = 176;

		x[rO5 + 9][cO5 - 4] = 176;
		x[rO5 + 9][cO5 - 3] = 176;
		x[rO5 + 9][cO5 - 2] = 176;
		x[rO5 + 9][cO5 - 1] = 176;
		x[rO5 + 9][cO5] = 176;
		x[rO5 + 9][cO5 + 1] = 176;
		x[rO5 + 9][cO5 + 2] = 176;
		x[rO5 + 9][cO5 + 3] = 176;
		x[rO5 + 9][cO5 + 4] = 176;

		x[rO5 + 8][cO5 - 3] = 176;
		x[rO5 + 8][cO5 - 2] = 176;
		x[rO5 + 8][cO5 - 1] = 176;
		x[rO5 + 8][cO5] = 176;
		x[rO5 + 8][cO5 + 1] = 176;
		x[rO5 + 8][cO5 + 2] = 176;
		x[rO5 + 8][cO5 + 3] = 176;

		x[rO5 + 7][cO5 - 2] = 176;
		x[rO5 + 7][cO5 - 1] = 176;
		x[rO5 + 7][cO5] = 176;
		x[rO5 + 7][cO5 + 1] = 176;
		x[rO5 + 7][cO5 + 2] = 176;

		x[rO5 + 6][cO5 - 1] = 176;
		x[rO5 + 6][cO5] = 176;
		x[rO5 + 6][cO5 + 1] = 176;

		x[rO5 + 5][cO5] = 176;


	}

	{
		x[rO6 + 23][cO6] = 179;
		x[rO6 + 22][cO6] = 179;
		x[rO6 + 21][cO6] = 179;
		x[rO6 + 20][cO6] = 179;
		x[rO6 + 19][cO6] = 179;
		x[rO6 + 18][cO6] = 179;
		x[rO6 + 17][cO6] = 179;
		x[rO6 + 16][cO6] = 179;
		x[rO6 + 15][cO6] = 179;
		x[rO6 + 14][cO6] = 179;
		x[rO6 + 13][cO6] = 179;
		x[rO6 + 12][cO6] = 179;
		x[rO6 + 11][cO6] = 179;
		x[rO6 + 10][cO6] = 179;
		x[rO6 + 9][cO6] = 179;
		x[rO6 + 8][cO6] = 179;
		x[rO6 + 7][cO6] = 179;
		x[rO6 + 6][cO6] = 179;
		x[rO6 + 5][cO6] = 179;

		x[rO6 + 5][cO6 - 1] = 22;
	}

	{
		x[rO7 + 23][cO7] = 186;
		x[rO7 + 22][cO7] = 186;
		x[rO7 + 21][cO7] = 186;
		x[rO7 + 20][cO7] = 186;
		x[rO7 + 19][cO7] = 186;
		x[rO7 + 18][cO7] = 186;
		x[rO7 + 17][cO7] = 186;
		x[rO7 + 16][cO7] = 186;
		x[rO7 + 15][cO7] = 186;
		x[rO7 + 14][cO7] = 186;
		x[rO7 + 13][cO7] = 186;

		x[rO7 + 13][cO7 - 8] = 176;
		x[rO7 + 13][cO7 - 7] = 176;
		x[rO7 + 13][cO7 - 6] = 176;
		x[rO7 + 13][cO7 - 5] = 176;
		x[rO7 + 13][cO7 - 4] = 176;
		x[rO7 + 13][cO7 - 3] = 176;
		x[rO7 + 13][cO7 - 2] = 176;
		x[rO7 + 13][cO7 - 1] = 176;
		x[rO7 + 13][cO7] = 176;
		x[rO7 + 13][cO7 + 1] = 176;
		x[rO7 + 13][cO7 + 2] = 176;
		x[rO7 + 13][cO7 + 3] = 176;
		x[rO7 + 13][cO7 + 4] = 176;
		x[rO7 + 13][cO7 + 5] = 176;
		x[rO7 + 13][cO7 + 6] = 176;
		x[rO7 + 13][cO7 + 7] = 176;
		x[rO7 + 13][cO7 + 8] = 176;

		x[rO7 + 12][cO7 - 7] = 176;
		x[rO7 + 12][cO7 - 6] = 176;
		x[rO7 + 12][cO7 - 5] = 176;
		x[rO7 + 12][cO7 - 4] = 176;
		x[rO7 + 12][cO7 - 3] = 176;
		x[rO7 + 12][cO7 - 2] = 176;
		x[rO7 + 12][cO7 - 1] = 176;
		x[rO7 + 12][cO7] = 176;
		x[rO7 + 12][cO7 + 1] = 176;
		x[rO7 + 12][cO7 + 2] = 176;
		x[rO7 + 12][cO7 + 3] = 176;
		x[rO7 + 12][cO7 + 4] = 176;
		x[rO7 + 12][cO7 + 5] = 176;
		x[rO7 + 12][cO7 + 6] = 176;
		x[rO7 + 12][cO7 + 7] = 176;

		x[rO7 + 11][cO7 - 6] = 176;
		x[rO7 + 11][cO7 - 5] = 176;
		x[rO7 + 11][cO7 - 4] = 176;
		x[rO7 + 11][cO7 - 3] = 176;
		x[rO7 + 11][cO7 - 2] = 176;
		x[rO7 + 11][cO7 - 1] = 176;
		x[rO7 + 11][cO7] = 176;
		x[rO7 + 11][cO7 + 1] = 176;
		x[rO7 + 11][cO7 + 2] = 176;
		x[rO7 + 11][cO7 + 3] = 176;
		x[rO7 + 11][cO7 + 4] = 176;
		x[rO7 + 11][cO7 + 5] = 176;
		x[rO7 + 11][cO7 + 6] = 176;

		x[rO7 + 10][cO7 - 5] = 176;
		x[rO7 + 10][cO7 - 4] = 176;
		x[rO7 + 10][cO7 - 3] = 176;
		x[rO7 + 10][cO7 - 2] = 176;
		x[rO7 + 10][cO7 - 1] = 176;
		x[rO7 + 10][cO7] = 176;
		x[rO7 + 10][cO7 + 1] = 176;
		x[rO7 + 10][cO7 + 2] = 176;
		x[rO7 + 10][cO7 + 3] = 176;
		x[rO7 + 10][cO7 + 4] = 176;
		x[rO7 + 10][cO7 + 5] = 176;

		x[rO7 + 9][cO7 - 4] = 176;
		x[rO7 + 9][cO7 - 3] = 176;
		x[rO7 + 9][cO7 - 2] = 176;
		x[rO7 + 9][cO7 - 1] = 176;
		x[rO7 + 9][cO7] = 176;
		x[rO7 + 9][cO7 + 1] = 176;
		x[rO7 + 9][cO7 + 2] = 176;
		x[rO7 + 9][cO7 + 3] = 176;
		x[rO7 + 9][cO7 + 4] = 176;

		x[rO7 + 8][cO7 - 3] = 176;
		x[rO7 + 8][cO7 - 2] = 176;
		x[rO7 + 8][cO7 - 1] = 176;
		x[rO7 + 8][cO7] = 176;
		x[rO7 + 8][cO7 + 1] = 176;
		x[rO7 + 8][cO7 + 2] = 176;
		x[rO7 + 8][cO7 + 3] = 176;

		x[rO7 + 7][cO7 - 2] = 176;
		x[rO7 + 7][cO7 - 1] = 176;
		x[rO7 + 7][cO7] = 176;
		x[rO7 + 7][cO7 + 1] = 176;
		x[rO7 + 7][cO7 + 2] = 176;

		x[rO7 + 6][cO7 - 1] = 176;
		x[rO7 + 6][cO7] = 176;
		x[rO7 + 6][cO7 + 1] = 176;

		x[rO7 + 5][cO7] = 176;


	}

	/*{
	x[rO8 + 23][cO8] = 179;
	x[rO8 + 22][cO8] = 179;
	x[rO8 + 21][cO8] = 179;
	x[rO8 + 20][cO8] = 179;
	x[rO8 + 19][cO8] = 179;
	x[rO8 + 18][cO8] = 179;
	x[rO8 + 17][cO8] = 179;
	x[rO8 + 16][cO8] = 179;
	x[rO8 + 15][cO8] = 179;
	x[rO8 + 14][cO8] = 179;
	x[rO8 + 13][cO8] = 179;
	x[rO8 + 12][cO8] = 179;
	x[rO8 + 11][cO8] = 179;
	x[rO8 + 10][cO8] = 179;
	x[rO8 + 9][cO8] = 179;
	x[rO8 + 8][cO8] = 179;
	x[rO8 + 7][cO8] = 179;
	x[rO8 + 6][cO8] = 179;
	x[rO8 + 5][cO8] = 179;

	x[rO8 + 5][cO8 - 1] = 22;
	}*/


	{
		x[rO9 + 23][cO9] = 186;
		x[rO9 + 22][cO9] = 186;
		x[rO9 + 21][cO9] = 186;
		x[rO9 + 20][cO9] = 186;
		x[rO9 + 19][cO9] = 186;
		x[rO9 + 18][cO9] = 186;
		x[rO9 + 17][cO9] = 186;
		x[rO9 + 16][cO9] = 186;
		x[rO9 + 15][cO9] = 186;
		x[rO9 + 14][cO9] = 186;
		x[rO9 + 13][cO9] = 186;

		x[rO9 + 13][cO9 - 8] = 176;
		x[rO9 + 13][cO9 - 7] = 176;
		x[rO9 + 13][cO9 - 6] = 176;
		x[rO9 + 13][cO9 - 5] = 176;
		x[rO9 + 13][cO9 - 4] = 176;
		x[rO9 + 13][cO9 - 3] = 176;
		x[rO9 + 13][cO9 - 2] = 176;
		x[rO9 + 13][cO9 - 1] = 176;
		x[rO9 + 13][cO9] = 176;
		x[rO9 + 13][cO9 + 1] = 176;
		x[rO9 + 13][cO9 + 2] = 176;
		x[rO9 + 13][cO9 + 3] = 176;
		x[rO9 + 13][cO9 + 4] = 176;
		x[rO9 + 13][cO9 + 5] = 176;
		x[rO9 + 13][cO9 + 6] = 176;
		x[rO9 + 13][cO9 + 7] = 176;
		x[rO9 + 13][cO9 + 8] = 176;

		x[rO9 + 12][cO9 - 7] = 176;
		x[rO9 + 12][cO9 - 6] = 176;
		x[rO9 + 12][cO9 - 5] = 176;
		x[rO9 + 12][cO9 - 4] = 176;
		x[rO9 + 12][cO9 - 3] = 176;
		x[rO9 + 12][cO9 - 2] = 176;
		x[rO9 + 12][cO9 - 1] = 176;
		x[rO9 + 12][cO9] = 176;
		x[rO9 + 12][cO9 + 1] = 176;
		x[rO9 + 12][cO9 + 2] = 176;
		x[rO9 + 12][cO9 + 3] = 176;
		x[rO9 + 12][cO9 + 4] = 176;
		x[rO9 + 12][cO9 + 5] = 176;
		x[rO9 + 12][cO9 + 6] = 176;
		x[rO9 + 12][cO9 + 7] = 176;

		x[rO9 + 11][cO9 - 6] = 176;
		x[rO9 + 11][cO9 - 5] = 176;
		x[rO9 + 11][cO9 - 4] = 176;
		x[rO9 + 11][cO9 - 3] = 176;
		x[rO9 + 11][cO9 - 2] = 176;
		x[rO9 + 11][cO9 - 1] = 176;
		x[rO9 + 11][cO9] = 176;
		x[rO9 + 11][cO9 + 1] = 176;
		x[rO9 + 11][cO9 + 2] = 176;
		x[rO9 + 11][cO9 + 3] = 176;
		x[rO9 + 11][cO9 + 4] = 176;
		x[rO9 + 11][cO9 + 5] = 176;
		x[rO9 + 11][cO9 + 6] = 176;

		x[rO9 + 10][cO9 - 5] = 176;
		x[rO9 + 10][cO9 - 4] = 176;
		x[rO9 + 10][cO9 - 3] = 176;
		x[rO9 + 10][cO9 - 2] = 176;
		x[rO9 + 10][cO9 - 1] = 176;
		x[rO9 + 10][cO9] = 176;
		x[rO9 + 10][cO9 + 1] = 176;
		x[rO9 + 10][cO9 + 2] = 176;
		x[rO9 + 10][cO9 + 3] = 176;
		x[rO9 + 10][cO9 + 4] = 176;
		x[rO9 + 10][cO9 + 5] = 176;

		x[rO9 + 9][cO9 - 4] = 176;
		x[rO9 + 9][cO9 - 3] = 176;
		x[rO9 + 9][cO9 - 2] = 176;
		x[rO9 + 9][cO9 - 1] = 176;
		x[rO9 + 9][cO9] = 176;
		x[rO9 + 9][cO9 + 1] = 176;
		x[rO9 + 9][cO9 + 2] = 176;
		x[rO9 + 9][cO9 + 3] = 176;
		x[rO9 + 9][cO9 + 4] = 176;

		x[rO9 + 8][cO9 - 3] = 176;
		x[rO9 + 8][cO9 - 2] = 176;
		x[rO9 + 8][cO9 - 1] = 176;
		x[rO9 + 8][cO9] = 176;
		x[rO9 + 8][cO9 + 1] = 176;
		x[rO9 + 8][cO9 + 2] = 176;
		x[rO9 + 8][cO9 + 3] = 176;

		x[rO9 + 7][cO9 - 2] = 176;
		x[rO9 + 7][cO9 - 1] = 176;
		x[rO9 + 7][cO9] = 176;
		x[rO9 + 7][cO9 + 1] = 176;
		x[rO9 + 7][cO9 + 2] = 176;

		x[rO9 + 6][cO9 - 1] = 176;
		x[rO9 + 6][cO9] = 176;
		x[rO9 + 6][cO9 + 1] = 176;

		x[rO9 + 5][cO9] = 176;

		//	SetConsoleTextAttribute(hConsole, 15);
	}
}

void DynamicObjects(char x[][138], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, char keyB, int AutoWalk)
{
	if (CounterUntilStop >= 16 && level == 1 && (keyB == 'd' || keyB == 'D'))
	{
		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}
	}
	else
	{
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}
	}



}

void DynamicObjects_2(char x[][138], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, int AutoWalk)
{
	if (CounterUntilStop >= 16 && AutoWalk == 1)
	{
		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}
	}
	else
	{
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}
	}



}

void StaticObjects2(char x[][138], int cO1, int rO1, int cO2, int rO2, int cO3, int rO3, int cO4, int rO4, int cO5, int rO5, int cO6, int rO6, int cO7, int rO7, int cO8, int rO8, int cO9, int rO9)
{
	{


		x[rO1 + 21][cO1] = 179;
		x[rO1 + 20][cO1] = 179;
		x[rO1 + 19][cO1] = 179;
		x[rO1 + 18][cO1] = 179;
		x[rO1 + 17][cO1] = 179;
		x[rO1 + 16][cO1] = 179;
		x[rO1 + 15][cO1] = 179;
		x[rO1 + 14][cO1] = 179;
		x[rO1 + 13][cO1] = 179;
		x[rO1 + 12][cO1] = 179;
		x[rO1 + 11][cO1] = 179;
		x[rO1 + 10][cO1] = 179;
		x[rO1 + 9][cO1] = 179;
		x[rO1 + 8][cO1] = 179;
		x[rO1 + 7][cO1] = 179;
		x[rO1 + 6][cO1] = 179;
		x[rO1 + 5][cO1] = 179;

		x[rO1 + 5][cO1 - 1] = 22;
	}

	{

		x[rO2 + 21][cO2] = 186;
		x[rO2 + 20][cO2] = 186;
		x[rO2 + 19][cO2] = 186;
		x[rO2 + 18][cO2] = 186;
		x[rO2 + 17][cO2] = 186;
		x[rO2 + 16][cO2] = 186;
		x[rO2 + 15][cO2] = 186;
		x[rO2 + 14][cO2] = 186;
		x[rO2 + 13][cO2] = 186;

		x[rO2 + 13][cO2 - 8] = 176;
		x[rO2 + 13][cO2 - 7] = 176;
		x[rO2 + 13][cO2 - 6] = 176;
		x[rO2 + 13][cO2 - 5] = 176;
		x[rO2 + 13][cO2 - 4] = 176;
		x[rO2 + 13][cO2 - 3] = 176;
		x[rO2 + 13][cO2 - 2] = 176;
		x[rO2 + 13][cO2 - 1] = 176;
		x[rO2 + 13][cO2] = 176;
		x[rO2 + 13][cO2 + 1] = 176;
		x[rO2 + 13][cO2 + 2] = 176;
		x[rO2 + 13][cO2 + 3] = 176;
		x[rO2 + 13][cO2 + 4] = 176;
		x[rO2 + 13][cO2 + 5] = 176;
		x[rO2 + 13][cO2 + 6] = 176;
		x[rO2 + 13][cO2 + 7] = 176;
		x[rO2 + 13][cO2 + 8] = 176;

		x[rO2 + 12][cO2 - 7] = 176;
		x[rO2 + 12][cO2 - 6] = 176;
		x[rO2 + 12][cO2 - 5] = 176;
		x[rO2 + 12][cO2 - 4] = 176;
		x[rO2 + 12][cO2 - 3] = 176;
		x[rO2 + 12][cO2 - 2] = 176;
		x[rO2 + 12][cO2 - 1] = 176;
		x[rO2 + 12][cO2] = 176;
		x[rO2 + 12][cO2 + 1] = 176;
		x[rO2 + 12][cO2 + 2] = 176;
		x[rO2 + 12][cO2 + 3] = 176;
		x[rO2 + 12][cO2 + 4] = 176;
		x[rO2 + 12][cO2 + 5] = 176;
		x[rO2 + 12][cO2 + 6] = 176;
		x[rO2 + 12][cO2 + 7] = 176;

		x[rO2 + 11][cO2 - 6] = 176;
		x[rO2 + 11][cO2 - 5] = 176;
		x[rO2 + 11][cO2 - 4] = 176;
		x[rO2 + 11][cO2 - 3] = 176;
		x[rO2 + 11][cO2 - 2] = 176;
		x[rO2 + 11][cO2 - 1] = 176;
		x[rO2 + 11][cO2] = 176;
		x[rO2 + 11][cO2 + 1] = 176;
		x[rO2 + 11][cO2 + 2] = 176;
		x[rO2 + 11][cO2 + 3] = 176;
		x[rO2 + 11][cO2 + 4] = 176;
		x[rO2 + 11][cO2 + 5] = 176;
		x[rO2 + 11][cO2 + 6] = 176;

		x[rO2 + 10][cO2 - 5] = 176;
		x[rO2 + 10][cO2 - 4] = 176;
		x[rO2 + 10][cO2 - 3] = 176;
		x[rO2 + 10][cO2 - 2] = 176;
		x[rO2 + 10][cO2 - 1] = 176;
		x[rO2 + 10][cO2] = 176;
		x[rO2 + 10][cO2 + 1] = 176;
		x[rO2 + 10][cO2 + 2] = 176;
		x[rO2 + 10][cO2 + 3] = 176;
		x[rO2 + 10][cO2 + 4] = 176;
		x[rO2 + 10][cO2 + 5] = 176;

		x[rO2 + 9][cO2 - 4] = 176;
		x[rO2 + 9][cO2 - 3] = 176;
		x[rO2 + 9][cO2 - 2] = 176;
		x[rO2 + 9][cO2 - 1] = 176;
		x[rO2 + 9][cO2] = 176;
		x[rO2 + 9][cO2 + 1] = 176;
		x[rO2 + 9][cO2 + 2] = 176;
		x[rO2 + 9][cO2 + 3] = 176;
		x[rO2 + 9][cO2 + 4] = 176;

		x[rO2 + 8][cO2 - 3] = 176;
		x[rO2 + 8][cO2 - 2] = 176;
		x[rO2 + 8][cO2 - 1] = 176;
		x[rO2 + 8][cO2] = 176;
		x[rO2 + 8][cO2 + 1] = 176;
		x[rO2 + 8][cO2 + 2] = 176;
		x[rO2 + 8][cO2 + 3] = 176;

		x[rO2 + 7][cO2 - 2] = 176;
		x[rO2 + 7][cO2 - 1] = 176;
		x[rO2 + 7][cO2] = 176;
		x[rO2 + 7][cO2 + 1] = 176;
		x[rO2 + 7][cO2 + 2] = 176;

		x[rO2 + 6][cO2 - 1] = 176;
		x[rO2 + 6][cO2] = 176;
		x[rO2 + 6][cO2 + 1] = 176;

		x[rO2 + 5][cO2] = 176;


	}


	{

		x[rO3 + 21][cO3] = 179;
		x[rO3 + 20][cO3] = 179;
		x[rO3 + 19][cO3] = 179;
		x[rO3 + 18][cO3] = 179;
		x[rO3 + 17][cO3] = 179;
		x[rO3 + 16][cO3] = 179;
		x[rO3 + 15][cO3] = 179;
		x[rO3 + 14][cO3] = 179;
		x[rO3 + 13][cO3] = 179;
		x[rO3 + 12][cO3] = 179;
		x[rO3 + 11][cO3] = 179;
		x[rO3 + 10][cO3] = 179;
		x[rO3 + 9][cO3] = 179;
		x[rO3 + 8][cO3] = 179;
		x[rO3 + 7][cO3] = 179;
		x[rO3 + 6][cO3] = 179;
		x[rO3 + 5][cO3] = 179;

		x[rO3 + 5][cO3 - 1] = 22;
	}

	{

		x[rO4 + 21][cO4] = 179;
		x[rO4 + 20][cO4] = 179;
		x[rO4 + 19][cO4] = 179;
		x[rO4 + 18][cO4] = 179;
		x[rO4 + 17][cO4] = 179;
		x[rO4 + 16][cO4] = 179;
		x[rO4 + 15][cO4] = 179;
		x[rO4 + 14][cO4] = 179;
		x[rO4 + 13][cO4] = 179;
		x[rO4 + 12][cO4] = 179;
		x[rO4 + 11][cO4] = 179;
		x[rO4 + 10][cO4] = 179;
		x[rO4 + 9][cO4] = 179;
		x[rO4 + 8][cO4] = 179;
		x[rO4 + 7][cO4] = 179;
		x[rO4 + 6][cO4] = 179;
		x[rO4 + 5][cO4] = 179;


		x[rO4 + 5][cO4 - 1] = 22;
	}


	{

		x[rO5 + 21][cO5] = 186;
		x[rO5 + 20][cO5] = 186;
		x[rO5 + 19][cO5] = 186;
		x[rO5 + 18][cO5] = 186;
		x[rO5 + 17][cO5] = 186;
		x[rO5 + 16][cO5] = 186;
		x[rO5 + 15][cO5] = 186;
		x[rO5 + 14][cO5] = 186;
		x[rO5 + 13][cO5] = 186;

		x[rO5 + 13][cO5 - 8] = 176;
		x[rO5 + 13][cO5 - 7] = 176;
		x[rO5 + 13][cO5 - 6] = 176;
		x[rO5 + 13][cO5 - 5] = 176;
		x[rO5 + 13][cO5 - 4] = 176;
		x[rO5 + 13][cO5 - 3] = 176;
		x[rO5 + 13][cO5 - 2] = 176;
		x[rO5 + 13][cO5 - 1] = 176;
		x[rO5 + 13][cO5] = 176;
		x[rO5 + 13][cO5 + 1] = 176;
		x[rO5 + 13][cO5 + 2] = 176;
		x[rO5 + 13][cO5 + 3] = 176;
		x[rO5 + 13][cO5 + 4] = 176;
		x[rO5 + 13][cO5 + 5] = 176;
		x[rO5 + 13][cO5 + 6] = 176;
		x[rO5 + 13][cO5 + 7] = 176;
		x[rO5 + 13][cO5 + 8] = 176;

		x[rO5 + 12][cO5 - 7] = 176;
		x[rO5 + 12][cO5 - 6] = 176;
		x[rO5 + 12][cO5 - 5] = 176;
		x[rO5 + 12][cO5 - 4] = 176;
		x[rO5 + 12][cO5 - 3] = 176;
		x[rO5 + 12][cO5 - 2] = 176;
		x[rO5 + 12][cO5 - 1] = 176;
		x[rO5 + 12][cO5] = 176;
		x[rO5 + 12][cO5 + 1] = 176;
		x[rO5 + 12][cO5 + 2] = 176;
		x[rO5 + 12][cO5 + 3] = 176;
		x[rO5 + 12][cO5 + 4] = 176;
		x[rO5 + 12][cO5 + 5] = 176;
		x[rO5 + 12][cO5 + 6] = 176;
		x[rO5 + 12][cO5 + 7] = 176;

		x[rO5 + 11][cO5 - 6] = 176;
		x[rO5 + 11][cO5 - 5] = 176;
		x[rO5 + 11][cO5 - 4] = 176;
		x[rO5 + 11][cO5 - 3] = 176;
		x[rO5 + 11][cO5 - 2] = 176;
		x[rO5 + 11][cO5 - 1] = 176;
		x[rO5 + 11][cO5] = 176;
		x[rO5 + 11][cO5 + 1] = 176;
		x[rO5 + 11][cO5 + 2] = 176;
		x[rO5 + 11][cO5 + 3] = 176;
		x[rO5 + 11][cO5 + 4] = 176;
		x[rO5 + 11][cO5 + 5] = 176;
		x[rO5 + 11][cO5 + 6] = 176;

		x[rO5 + 10][cO5 - 5] = 176;
		x[rO5 + 10][cO5 - 4] = 176;
		x[rO5 + 10][cO5 - 3] = 176;
		x[rO5 + 10][cO5 - 2] = 176;
		x[rO5 + 10][cO5 - 1] = 176;
		x[rO5 + 10][cO5] = 176;
		x[rO5 + 10][cO5 + 1] = 176;
		x[rO5 + 10][cO5 + 2] = 176;
		x[rO5 + 10][cO5 + 3] = 176;
		x[rO5 + 10][cO5 + 4] = 176;
		x[rO5 + 10][cO5 + 5] = 176;

		x[rO5 + 9][cO5 - 4] = 176;
		x[rO5 + 9][cO5 - 3] = 176;
		x[rO5 + 9][cO5 - 2] = 176;
		x[rO5 + 9][cO5 - 1] = 176;
		x[rO5 + 9][cO5] = 176;
		x[rO5 + 9][cO5 + 1] = 176;
		x[rO5 + 9][cO5 + 2] = 176;
		x[rO5 + 9][cO5 + 3] = 176;
		x[rO5 + 9][cO5 + 4] = 176;

		x[rO5 + 8][cO5 - 3] = 176;
		x[rO5 + 8][cO5 - 2] = 176;
		x[rO5 + 8][cO5 - 1] = 176;
		x[rO5 + 8][cO5] = 176;
		x[rO5 + 8][cO5 + 1] = 176;
		x[rO5 + 8][cO5 + 2] = 176;
		x[rO5 + 8][cO5 + 3] = 176;

		x[rO5 + 7][cO5 - 2] = 176;
		x[rO5 + 7][cO5 - 1] = 176;
		x[rO5 + 7][cO5] = 176;
		x[rO5 + 7][cO5 + 1] = 176;
		x[rO5 + 7][cO5 + 2] = 176;

		x[rO5 + 6][cO5 - 1] = 176;
		x[rO5 + 6][cO5] = 176;
		x[rO5 + 6][cO5 + 1] = 176;

		x[rO5 + 5][cO5] = 176;


	}

	{

		x[rO6 + 21][cO6] = 179;
		x[rO6 + 20][cO6] = 179;
		x[rO6 + 19][cO6] = 179;
		x[rO6 + 18][cO6] = 179;
		x[rO6 + 17][cO6] = 179;
		x[rO6 + 16][cO6] = 179;
		x[rO6 + 15][cO6] = 179;
		x[rO6 + 14][cO6] = 179;
		x[rO6 + 13][cO6] = 179;
		x[rO6 + 12][cO6] = 179;
		x[rO6 + 11][cO6] = 179;
		x[rO6 + 10][cO6] = 179;
		x[rO6 + 9][cO6] = 179;
		x[rO6 + 8][cO6] = 179;
		x[rO6 + 7][cO6] = 179;
		x[rO6 + 6][cO6] = 179;
		x[rO6 + 5][cO6] = 179;

		x[rO6 + 5][cO6 - 1] = 22;
	}

	{

		x[rO7 + 21][cO7] = 186;
		x[rO7 + 20][cO7] = 186;
		x[rO7 + 19][cO7] = 186;
		x[rO7 + 18][cO7] = 186;
		x[rO7 + 17][cO7] = 186;
		x[rO7 + 16][cO7] = 186;
		x[rO7 + 15][cO7] = 186;
		x[rO7 + 14][cO7] = 186;
		x[rO7 + 13][cO7] = 186;

		x[rO7 + 13][cO7 - 8] = 176;
		x[rO7 + 13][cO7 - 7] = 176;
		x[rO7 + 13][cO7 - 6] = 176;
		x[rO7 + 13][cO7 - 5] = 176;
		x[rO7 + 13][cO7 - 4] = 176;
		x[rO7 + 13][cO7 - 3] = 176;
		x[rO7 + 13][cO7 - 2] = 176;
		x[rO7 + 13][cO7 - 1] = 176;
		x[rO7 + 13][cO7] = 176;
		x[rO7 + 13][cO7 + 1] = 176;
		x[rO7 + 13][cO7 + 2] = 176;
		x[rO7 + 13][cO7 + 3] = 176;
		x[rO7 + 13][cO7 + 4] = 176;
		x[rO7 + 13][cO7 + 5] = 176;
		x[rO7 + 13][cO7 + 6] = 176;
		x[rO7 + 13][cO7 + 7] = 176;
		x[rO7 + 13][cO7 + 8] = 176;

		x[rO7 + 12][cO7 - 7] = 176;
		x[rO7 + 12][cO7 - 6] = 176;
		x[rO7 + 12][cO7 - 5] = 176;
		x[rO7 + 12][cO7 - 4] = 176;
		x[rO7 + 12][cO7 - 3] = 176;
		x[rO7 + 12][cO7 - 2] = 176;
		x[rO7 + 12][cO7 - 1] = 176;
		x[rO7 + 12][cO7] = 176;
		x[rO7 + 12][cO7 + 1] = 176;
		x[rO7 + 12][cO7 + 2] = 176;
		x[rO7 + 12][cO7 + 3] = 176;
		x[rO7 + 12][cO7 + 4] = 176;
		x[rO7 + 12][cO7 + 5] = 176;
		x[rO7 + 12][cO7 + 6] = 176;
		x[rO7 + 12][cO7 + 7] = 176;

		x[rO7 + 11][cO7 - 6] = 176;
		x[rO7 + 11][cO7 - 5] = 176;
		x[rO7 + 11][cO7 - 4] = 176;
		x[rO7 + 11][cO7 - 3] = 176;
		x[rO7 + 11][cO7 - 2] = 176;
		x[rO7 + 11][cO7 - 1] = 176;
		x[rO7 + 11][cO7] = 176;
		x[rO7 + 11][cO7 + 1] = 176;
		x[rO7 + 11][cO7 + 2] = 176;
		x[rO7 + 11][cO7 + 3] = 176;
		x[rO7 + 11][cO7 + 4] = 176;
		x[rO7 + 11][cO7 + 5] = 176;
		x[rO7 + 11][cO7 + 6] = 176;

		x[rO7 + 10][cO7 - 5] = 176;
		x[rO7 + 10][cO7 - 4] = 176;
		x[rO7 + 10][cO7 - 3] = 176;
		x[rO7 + 10][cO7 - 2] = 176;
		x[rO7 + 10][cO7 - 1] = 176;
		x[rO7 + 10][cO7] = 176;
		x[rO7 + 10][cO7 + 1] = 176;
		x[rO7 + 10][cO7 + 2] = 176;
		x[rO7 + 10][cO7 + 3] = 176;
		x[rO7 + 10][cO7 + 4] = 176;
		x[rO7 + 10][cO7 + 5] = 176;

		x[rO7 + 9][cO7 - 4] = 176;
		x[rO7 + 9][cO7 - 3] = 176;
		x[rO7 + 9][cO7 - 2] = 176;
		x[rO7 + 9][cO7 - 1] = 176;
		x[rO7 + 9][cO7] = 176;
		x[rO7 + 9][cO7 + 1] = 176;
		x[rO7 + 9][cO7 + 2] = 176;
		x[rO7 + 9][cO7 + 3] = 176;
		x[rO7 + 9][cO7 + 4] = 176;

		x[rO7 + 8][cO7 - 3] = 176;
		x[rO7 + 8][cO7 - 2] = 176;
		x[rO7 + 8][cO7 - 1] = 176;
		x[rO7 + 8][cO7] = 176;
		x[rO7 + 8][cO7 + 1] = 176;
		x[rO7 + 8][cO7 + 2] = 176;
		x[rO7 + 8][cO7 + 3] = 176;

		x[rO7 + 7][cO7 - 2] = 176;
		x[rO7 + 7][cO7 - 1] = 176;
		x[rO7 + 7][cO7] = 176;
		x[rO7 + 7][cO7 + 1] = 176;
		x[rO7 + 7][cO7 + 2] = 176;

		x[rO7 + 6][cO7 - 1] = 176;
		x[rO7 + 6][cO7] = 176;
		x[rO7 + 6][cO7 + 1] = 176;

		x[rO7 + 5][cO7] = 176;


	}

	/*{
	x[rO8 + 23][cO8] = 179;
	x[rO8 + 22][cO8] = 179;
	x[rO8 + 21][cO8] = 179;
	x[rO8 + 20][cO8] = 179;
	x[rO8 + 19][cO8] = 179;
	x[rO8 + 18][cO8] = 179;
	x[rO8 + 17][cO8] = 179;
	x[rO8 + 16][cO8] = 179;
	x[rO8 + 15][cO8] = 179;
	x[rO8 + 14][cO8] = 179;
	x[rO8 + 13][cO8] = 179;
	x[rO8 + 12][cO8] = 179;
	x[rO8 + 11][cO8] = 179;
	x[rO8 + 10][cO8] = 179;
	x[rO8 + 9][cO8] = 179;
	x[rO8 + 8][cO8] = 179;
	x[rO8 + 7][cO8] = 179;
	x[rO8 + 6][cO8] = 179;
	x[rO8 + 5][cO8] = 179;

	x[rO8 + 5][cO8 - 1] = 22;
	}*/


	{

		x[rO9 + 21][cO9] = 186;
		x[rO9 + 20][cO9] = 186;
		x[rO9 + 19][cO9] = 186;
		x[rO9 + 18][cO9] = 186;
		x[rO9 + 17][cO9] = 186;
		x[rO9 + 16][cO9] = 186;
		x[rO9 + 15][cO9] = 186;
		x[rO9 + 14][cO9] = 186;
		x[rO9 + 13][cO9] = 186;

		x[rO9 + 13][cO9 - 8] = 176;
		x[rO9 + 13][cO9 - 7] = 176;
		x[rO9 + 13][cO9 - 6] = 176;
		x[rO9 + 13][cO9 - 5] = 176;
		x[rO9 + 13][cO9 - 4] = 176;
		x[rO9 + 13][cO9 - 3] = 176;
		x[rO9 + 13][cO9 - 2] = 176;
		x[rO9 + 13][cO9 - 1] = 176;
		x[rO9 + 13][cO9] = 176;
		x[rO9 + 13][cO9 + 1] = 176;
		x[rO9 + 13][cO9 + 2] = 176;
		x[rO9 + 13][cO9 + 3] = 176;
		x[rO9 + 13][cO9 + 4] = 176;
		x[rO9 + 13][cO9 + 5] = 176;
		x[rO9 + 13][cO9 + 6] = 176;
		x[rO9 + 13][cO9 + 7] = 176;
		x[rO9 + 13][cO9 + 8] = 176;

		x[rO9 + 12][cO9 - 7] = 176;
		x[rO9 + 12][cO9 - 6] = 176;
		x[rO9 + 12][cO9 - 5] = 176;
		x[rO9 + 12][cO9 - 4] = 176;
		x[rO9 + 12][cO9 - 3] = 176;
		x[rO9 + 12][cO9 - 2] = 176;
		x[rO9 + 12][cO9 - 1] = 176;
		x[rO9 + 12][cO9] = 176;
		x[rO9 + 12][cO9 + 1] = 176;
		x[rO9 + 12][cO9 + 2] = 176;
		x[rO9 + 12][cO9 + 3] = 176;
		x[rO9 + 12][cO9 + 4] = 176;
		x[rO9 + 12][cO9 + 5] = 176;
		x[rO9 + 12][cO9 + 6] = 176;
		x[rO9 + 12][cO9 + 7] = 176;

		x[rO9 + 11][cO9 - 6] = 176;
		x[rO9 + 11][cO9 - 5] = 176;
		x[rO9 + 11][cO9 - 4] = 176;
		x[rO9 + 11][cO9 - 3] = 176;
		x[rO9 + 11][cO9 - 2] = 176;
		x[rO9 + 11][cO9 - 1] = 176;
		x[rO9 + 11][cO9] = 176;
		x[rO9 + 11][cO9 + 1] = 176;
		x[rO9 + 11][cO9 + 2] = 176;
		x[rO9 + 11][cO9 + 3] = 176;
		x[rO9 + 11][cO9 + 4] = 176;
		x[rO9 + 11][cO9 + 5] = 176;
		x[rO9 + 11][cO9 + 6] = 176;

		x[rO9 + 10][cO9 - 5] = 176;
		x[rO9 + 10][cO9 - 4] = 176;
		x[rO9 + 10][cO9 - 3] = 176;
		x[rO9 + 10][cO9 - 2] = 176;
		x[rO9 + 10][cO9 - 1] = 176;
		x[rO9 + 10][cO9] = 176;
		x[rO9 + 10][cO9 + 1] = 176;
		x[rO9 + 10][cO9 + 2] = 176;
		x[rO9 + 10][cO9 + 3] = 176;
		x[rO9 + 10][cO9 + 4] = 176;
		x[rO9 + 10][cO9 + 5] = 176;

		x[rO9 + 9][cO9 - 4] = 176;
		x[rO9 + 9][cO9 - 3] = 176;
		x[rO9 + 9][cO9 - 2] = 176;
		x[rO9 + 9][cO9 - 1] = 176;
		x[rO9 + 9][cO9] = 176;
		x[rO9 + 9][cO9 + 1] = 176;
		x[rO9 + 9][cO9 + 2] = 176;
		x[rO9 + 9][cO9 + 3] = 176;
		x[rO9 + 9][cO9 + 4] = 176;

		x[rO9 + 8][cO9 - 3] = 176;
		x[rO9 + 8][cO9 - 2] = 176;
		x[rO9 + 8][cO9 - 1] = 176;
		x[rO9 + 8][cO9] = 176;
		x[rO9 + 8][cO9 + 1] = 176;
		x[rO9 + 8][cO9 + 2] = 176;
		x[rO9 + 8][cO9 + 3] = 176;

		x[rO9 + 7][cO9 - 2] = 176;
		x[rO9 + 7][cO9 - 1] = 176;
		x[rO9 + 7][cO9] = 176;
		x[rO9 + 7][cO9 + 1] = 176;
		x[rO9 + 7][cO9 + 2] = 176;

		x[rO9 + 6][cO9 - 1] = 176;
		x[rO9 + 6][cO9] = 176;
		x[rO9 + 6][cO9 + 1] = 176;

		x[rO9 + 5][cO9] = 176;

		//	SetConsoleTextAttribute(hConsole, 15);
	}
}

void DynamicObjects2(char x[][138], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, char keyB, int AutoWalk)
{
	if (((level == 2 || level == 4 || level == 5 || level == 6) && (keyB == 'd' || keyB == 'D')))
	{


		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= 0)
		{
			rO1 = -2;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = -2;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = -2;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = -2;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = -2;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = -2;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = -2;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = -2;
			cO9 = 137;
		}

	}

	if (level == 3 && (keyB == 'd' || keyB == 'D'))
	{
		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= 0)
		{
			rO1 = 10;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 10;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 10;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 10;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 10;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 10;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 10;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 10;
			cO9 = 137;
		}
	}

}

void DynamicObjects2_2(char x[][138], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, int AutoWalk)
{
	if ((level == 2 || level == 4 || level == 5 || level == 6) && AutoWalk == 1)
	{


		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= 0)
		{
			rO1 = -2;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = -2;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = -2;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = -2;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = -2;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = -2;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = -2;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = -2;
			cO9 = 137;
		}

	}

	if (level == 3 && AutoWalk == 1)
	{
		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= 0)
		{
			rO1 = 10;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 10;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 10;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 10;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 10;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 10;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 10;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 10;
			cO9 = 137;
		}
	}

}

void DynamicObjects3(char x[][138], int& cO1, int& rO1, int& cO2, int& rO2, int& cO3, int& rO3, int& cO4, int& rO4, int& cO5, int& rO5, int& cO6, int& rO6, int&cO7, int& rO7, int& cO8, int& rO8, int& cO9, int& rO9, int CounterUntilStop, int level, char keyB, int& cFC, int AutoWalk)
{
	if ((level == 6 && (keyB == 'd' || keyB == 'D')))
	{
		cO1 -= 3;
		cO2 -= 3;
		cO3 -= 3;
		cO4 -= 3;
		cO5 -= 3;
		cO6 -= 3;
		cO7 -= 3;
		cO8 -= 3;
		cO9 -= 3;
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}
	}
	else
	{
		if (cO1 <= 0)
		{
			rO1 = 3;
			cO1 = 137;
		}

		if (cO2 <= 0)
		{
			rO2 = 3;
			cO2 = 137;
		}
		if (cO3 <= 0)
		{
			rO3 = 3;
			cO3 = 137;
		}
		if (cO4 <= 0)
		{
			rO4 = 3;
			cO4 = 137;
		}
		if (cO5 <= 0)
		{
			rO5 = 3;
			cO5 = 137;
		}
		if (cO6 <= 0)
		{
			rO6 = 3;
			cO6 = 137;
		}
		if (cO7 <= 0)
		{
			rO7 = 3;
			cO7 = 137;
		}

		if (cO9 <= 0)
		{
			rO9 = 3;
			cO9 = 137;
		}



	}


}

void StaticFloor(char x[][138], int& cF, int CounterFloor, int level)
{
	if (CounterFloor == 0)
	{

		for (cF = 0; cF < 138; cF += 2)			//FLOOR
		{
			x[47][cF] = 205;
		}

		if (level == 1)
		{
			for (cF = 0; cF < 138; cF++)			//SIDEWALK
			{

				x[26][cF] = 177;
			}
		}

		if (level == 2 || level == 4 || level == 5 || level == 6)
		{
			for (cF = 0; cF < 138; cF++)			//SIDEWALK
			{

				x[19][cF] = 177;
			}
		}

		if (level == 3)
		{
			for (cF = 0; cF < 138; cF++)			//SIDEWALK
			{

				x[31][cF] = 177;
			}
		}


	}




	if (CounterFloor % 2 == 0)
	{

		for (cF = 0; cF < 138; cF += 2)
		{
			x[47][cF] = 205;
		}

		if (level == 1)
		{
			for (cF = 0; cF < 138; cF++)			//SIDEWALK
			{

				x[26][cF] = 177;
			}
		}

		if (level == 2 || level == 4 || level == 5 || level == 6)
		{
			for (cF = 0; cF < 138; cF++)			//SIDEWALK
			{

				x[19][cF] = 177;
			}
		}

		if (level == 3)
		{
			for (cF = 0; cF < 138; cF++)			//SIDEWALK
			{

				x[31][cF] = 177;
			}
		}


	}

	else
	{

		for (cF = 1; cF < 138; cF += 2)
		{
			x[47][cF] = 205;
		}

		if (level == 1)
		{
			for (cF = 0; cF < 138; cF++)			//SIDEWALK
			{

				x[26][cF] = 177;
			}
		}

		if (level == 2 || level == 4 || level == 5 || level == 6)
		{
			for (cF = 0; cF < 138; cF++)			//SIDEWALK
			{

				x[19][cF] = 177;
			}
		}

		if (level == 3)
		{
			for (cF = 0; cF < 138; cF++)			//SIDEWALK
			{

				x[31][cF] = 177;
			}
		}


	}



}

void StaticFloor4(char x[][138], int& cF, int CounterFloor, int level, int& rT, int& cT, int rR, int cR)
{
	if (CounterFloor == 0)
	{
		for (cF = 0; cF < 138; cF += 2)			//FLOOR
		{
			x[47][cF] = 205;
		}
		for (cF = 0; cF < 138; cF++)			//SIDEWALK
		{

			x[19][cF] = 177;
		}
	}

	if (CounterFloor % 2 == 0)
	{
		for (cF = 0; cF < 138; cF += 2)			//FLOOR
		{
			x[47][cF] = 205;
		}
		for (cF = 0; cF < 138; cF++)			//SIDEWALK
		{

			x[19][cF] = 177;
		}
	}
	else
	{
		for (cF = 1; cF < 138; cF += 2)
		{
			x[47][cF] = 205;
		}
		for (cF = 1; cF < 138; cF++)			//SIDEWALK
		{

			x[19][cF] = 177;
		}
	}

	x[rT][cT] = '/';
	x[rT][cT + 1] = '\\';
	x[rT][cT + 2] = '/';
	x[rT][cT + 3] = '\\';
	x[rT][cT + 4] = '/';
	x[rT][cT + 5] = '\\';
	x[rT][cT + 6] = '/';
	x[rT][cT + 7] = '\\';
	x[rT][cT + 8] = '/';
	x[rT][cT + 9] = '\\';
	x[rT][cT + 10] = '/';
	x[rT][cT + 11] = '\\';
	x[rT][cT + 12] = '/';
	x[rT][cT + 13] = '\\';
	x[rT][cT + 14] = '/';
	x[rT][cT + 15] = '\\';
	x[rT][cT + 16] = '/';
	x[rT][cT + 17] = '\\';
	x[rT][cT + 18] = '/';
	x[rT][cT + 19] = '\\';
	x[rT][cT + 20] = '/';
	x[rT][cT + 21] = '\\';
	x[rT][cT + 22] = '/';
	x[rT][cT + 23] = '\\';
	x[rT][cT + 24] = '/';
	x[rT][cT + 25] = '\\';
	x[rT][cT + 26] = '/';
	x[rT][cT + 27] = '\\';
	x[rT][cT + 28] = '/';
	x[rT][cT + 29] = '\\';
	x[rT][cT + 30] = '/';
	x[rT][cT + 31] = '\\';
	x[rT][cT + 32] = '/';
	x[rT][cT + 33] = '\\';
	x[rT][cT + 34] = '/';
	x[rT][cT + 35] = '\\';
	x[rT][cT + 36] = '/';
	x[rT][cT + 37] = '\\';
	x[rT][cT + 38] = '/';
	x[rT][cT + 39] = '\\';
	x[rT][cT + 40] = '/';
	x[rT][cT + 41] = '\\';
	x[rT][cT + 42] = '/';
	x[rT][cT + 43] = '\\';
	x[rT][cT + 44] = '/';
	x[rT][cT + 45] = '\\';
	x[rT][cT + 46] = '/';
	x[rT][cT + 47] = '\\';
	x[rT][cT + 48] = '/';
	x[rT][cT + 49] = '\\';
	x[rT][cT + 50] = '/';
	x[rT][cT + 51] = '\\';
	x[rT][cT + 52] = '/';
	x[rT][cT + 53] = '\\';
	x[rT][cT + 54] = '/';
	x[rT][cT + 55] = '\\';
	x[rT][cT + 56] = '/';
	x[rT][cT + 57] = '\\';
	x[rT][cT + 58] = '/';
	x[rT][cT + 59] = '\\';
	x[rT][cT + 60] = '/';
	x[rT][cT + 61] = '\\';
	x[rT][cT + 62] = '/';
	x[rT][cT + 63] = '\\';
	x[rT][cT + 64] = '/';
	x[rT][cT + 65] = '\\';

	x[rR + 1][cR] = 179;
	x[rR + 2][cR] = 179;
	x[rR + 3][cR] = 179;
	x[rR + 4][cR] = 179;
	x[rR + 5][cR] = 179;
	x[rR + 6][cR] = 179;
	x[rR + 7][cR] = 179;
	x[rR + 8][cR] = 179;
	x[rR + 9][cR] = 179;
	x[rR + 10][cR] = 179;
	x[rR + 11][cR] = 179;
	x[rR + 12][cR] = 179;
	x[rR + 13][cR] = 179;
	x[rR + 14][cR] = 179;
	x[rR + 15][cR] = 179;
	x[rR + 16][cR] = 179;
	x[rR + 17][cR] = 179;
	x[rR + 18][cR] = 179;
	x[rR + 19][cR] = 179;
	x[rR + 20][cR] = 179;
	x[rR + 21][cR] = 179;
	x[rR + 22][cR] = 179;
	x[rR + 23][cR] = 179;
	x[rR + 24][cR] = 179;
	x[rR + 25][cR] = 179;
	x[rR + 26][cR] = 179;
	x[rR + 27][cR] = 179;
	x[rR + 28][cR] = 179;
	x[rR + 29][cR] = 179;
	x[rR + 30][cR] = 179;
	x[rR + 31][cR] = 179;
	x[rR + 32][cR] = 179;
	x[rR + 33][cR] = 179;
	x[rR + 34][cR] = 179;


	cT -= 16;

	if (cT + 30 <= 0)
	{
		cT = 95;
	}

}

void StaticHero(char x[][138], int &rH, int &cH, int countRLHL1, int& CountStart, int& LeftLook, int rEv, int Reload, int& ActionReload, int level, int rB, int cB)
{

	if (rH < 0)
	{
		rH = rEv + 1;
	}
	x[rH][cH - 1] = '_';
	x[rH][cH] = '_';
	x[rH][cH + 1] = '_';
	x[rH][cH + 2] = '_';

	if (LeftLook == 1)
	{

		x[rH + 2][cH] = ' ';
		x[rH + 2][cH + 2] = ' ';

		x[rH + 2][cH + 1] = '-';
		x[rH + 2][cH - 1] = '-';

	}
	else
	{
		x[rH + 2][cH] = '-';
		x[rH + 2][cH + 2] = '-';

		x[rH + 2][cH + 1] = ' ';
		x[rH + 2][cH - 1] = ' ';
	}

	x[rH + 1][cH - 2] = '/';
	x[rH + 1][cH + 3] = '\\';

	x[rH + 2][cH - 2] = '|';
	x[rH + 2][cH + 3] = '|';

	x[rH + 3][cH - 2] = '\\';
	x[rH + 3][cH + 3] = '/';

	x[rH + 3][cH - 1] = '_';
	x[rH + 3][cH] = '_';
	x[rH + 3][cH + 1] = 251;
	x[rH + 3][cH + 2] = '_';

	x[rH + 4][cH - 2] = '_';
	x[rH + 4][cH - 1] = '/';
	x[rH + 4][cH + 2] = '/';
	x[rH + 4][cH + 3] = '_';

	RightHandMoveH1(x, rH, cH, countRLHL1);
	LeftHandMoveH1(x, rH, cH, countRLHL1, Reload, ActionReload, level, rB, cB);

	//x[rH + 5][cH + 3] = ' ';	   
	//x[rH + 6][cH + 3] = '|';	   
	x[rH + 7][cH + 3] = '|';

	//x[rH + 5][cH - 2] = ' ';
	//x[rH + 6][cH - 2] = ' ';
	x[rH + 7][cH - 2] = '|';

	x[rH + 7][cH - 1] = ' ';
	x[rH + 7][cH + 1] = ' ';
	x[rH + 7][cH + 2] = ' ';
	x[rH + 7][cH] = ' ';

	LeftLegMoveH1(x, rH, cH, countRLHL1);
	RightLegMoveH1(x, rH, cH, countRLHL1);

	//if (CountStart == 1)
	//{
	//	rH = 26;
	//	CountStart++;
	//}
	//x[rH + 11][cH] = 'F';
	//x[rH + 10][cH + 5] = 'K';

}

void StaticHero6(char x[][138], int &rH, int cH, int countRLHL1, int& CountStart, int& LeftLook, int rEv, int Reload, int& ActionReload, int level, int rB, int cB, int& DeathT, int& lose1)
{

	x[rH][cH - 1] = '_';
	x[rH][cH] = '_';
	x[rH][cH + 1] = '_';
	x[rH][cH + 2] = '_';

	if (LeftLook == 1)
	{

		x[rH + 2][cH] = ' ';
		x[rH + 2][cH + 2] = ' ';

		x[rH + 2][cH + 1] = 248;
		x[rH + 2][cH - 1] = 248;

	}
	else
	{
		x[rH + 2][cH] = 248;
		x[rH + 2][cH + 2] = 248;

		x[rH + 2][cH + 1] = ' ';
		x[rH + 2][cH - 1] = ' ';
	}

	x[rH + 1][cH - 2] = '/';
	x[rH + 1][cH + 3] = '\\';

	x[rH + 2][cH - 2] = '|';
	x[rH + 2][cH + 3] = '|';

	x[rH + 3][cH - 2] = '\\';
	x[rH + 3][cH + 3] = '/';

	x[rH + 3][cH - 1] = '_';
	x[rH + 3][cH] = '_';
	x[rH + 3][cH + 1] = 251;
	x[rH + 3][cH + 2] = '_';

	x[rH + 4][cH - 2] = '_';
	x[rH + 4][cH - 1] = '/';
	x[rH + 4][cH + 2] = '/';
	x[rH + 4][cH + 3] = '_';



	//x[rH + 5][cH + 3] = ' ';	   
	//x[rH + 6][cH + 3] = '|';	   
	x[rH + 7][cH + 3] = '_';

	//x[rH + 5][cH - 2] = ' ';
	//x[rH + 6][cH - 2] = ' ';
	x[rH + 7][cH - 2] = '|';

	x[rH + 7][cH - 1] = ' ';
	x[rH + 7][cH + 1] = ' ';
	x[rH + 7][cH + 2] = ' ';
	x[rH + 7][cH] = ' ';


	//x[rH + 7][cH - 1] = '_';
	//x[rH + 7][cH] = '_';
//	x[rH + 7][cH + 1] = '_';
	//x[rH + 7][cH + 2] = '_';

	x[rH + 4][cH + 4] = '_';
	x[rH + 4][cH + 5] = '|';
	x[rH + 3][cH + 5] = '|';
	x[rH + 2][cH + 5] = '|';
	x[rH + 1][cH + 5] = '|';
	x[rH][cH + 6] = '_';
	x[rH + 1][cH + 7] = '|';
	x[rH + 2][cH + 7] = '|';
	x[rH + 3][cH + 7] = '|';
	x[rH + 4][cH + 7] = '|';
	x[rH + 5][cH + 7] = '|';
	x[rH + 5][cH + 6] = '_';
	x[rH + 5][cH + 5] = '_';


	x[rH + 4][cH - 3] = '_';
	x[rH + 4][cH - 4] = '|';
	x[rH + 3][cH - 4] = '|';
	x[rH + 2][cH - 4] = '|';
	x[rH + 1][cH - 4] = '|';
	x[rH][cH - 5] = '_';
	x[rH + 1][cH - 6] = '|';
	x[rH + 2][cH - 6] = '|';
	x[rH + 3][cH - 6] = '|';
	x[rH + 4][cH - 6] = '|';
	x[rH + 5][cH - 6] = '|';
	x[rH + 5][cH - 5] = '_';
	x[rH + 5][cH - 4] = '_';



	x[rH + 7][cH + 4] = '_';
	x[rH + 7][cH + 5] = '_';
	x[rH + 7][cH + 6] = '_';
	x[rH + 7][cH + 7] = '_';
	x[rH + 7][cH + 8] = '_';
	x[rH + 7][cH + 9] = 179;
	x[rH + 6][cH + 8] = '_';
	x[rH + 6][cH + 7] = '_';
	x[rH + 6][cH + 6] = '_';
	x[rH + 6][cH + 5] = '_';
	x[rH + 6][cH + 4] = '_';

	x[rH + 8][cH - 2] = '|';

	//x[rH + 8][cH - 1] = '_';
	x[rH + 8][cH] = '_';
	x[rH + 8][cH + 1] = '_';
	x[rH + 8][cH + 2] = '_';
	x[rH + 8][cH + 3] = '_';
	x[rH + 8][cH + 4] = '_';
	x[rH + 8][cH + 5] = '_';
	x[rH + 8][cH + 6] = '_';
	x[rH + 8][cH + 7] = '_';
	x[rH + 8][cH + 8] = 179;






}

void StaticHero6_2(char x[][138], int rH, int cH, int counter)
{
	x[rH][cH - 1] = '_';
	x[rH][cH] = '_';
	x[rH][cH + 1] = '_';
	x[rH][cH + 2] = '_';

	x[rH + 1][cH - 1] = ' ';
	x[rH + 1][cH] = ' ';
	x[rH + 1][cH + 1] = ' ';
	x[rH + 1][cH + 2] = ' ';

	x[rH + 2][cH - 1] = ' ';
	x[rH + 2][cH] = ' ';
	x[rH + 2][cH + 1] = ' ';
	x[rH + 2][cH + 2] = ' ';


	x[rH + 1][cH - 2] = '/';
	x[rH + 1][cH + 3] = '\\';

	x[rH + 2][cH - 2] = '|';
	x[rH + 2][cH + 3] = '|';

	x[rH + 3][cH - 2] = '\\';
	x[rH + 3][cH + 3] = '/';

	x[rH + 3][cH - 1] = '_';
	x[rH + 3][cH] = '_';
	x[rH + 3][cH + 1] = '_';
	x[rH + 3][cH + 2] = '_';

	x[rH + 4][cH - 2] = '_';
	x[rH + 4][cH - 1] = 179;
	x[rH + 4][cH + 2] = 179;
	x[rH + 4][cH + 3] = '_';

	x[rH + 4][cH] = ' ';
	x[rH + 4][cH + 1] = ' ';

	if (counter % 2 == 0)
	{

		x[rH + 4][cH + 4] = '_';
		x[rH + 4][cH + 5] = '|';
		x[rH + 3][cH + 5] = '|';
		x[rH + 2][cH + 5] = '|';
		x[rH + 1][cH + 5] = '|';
		x[rH][cH + 6] = '_';
		x[rH + 1][cH + 7] = '|';
		x[rH + 2][cH + 7] = '|';
		x[rH + 3][cH + 7] = '|';
		x[rH + 4][cH + 7] = '|';
		x[rH + 5][cH + 7] = '|';
		x[rH + 5][cH + 6] = '_';
		x[rH + 5][cH + 5] = '_';


		x[rH + 1][cH + 6] = ' ';
		x[rH + 2][cH + 6] = ' ';
		x[rH + 3][cH + 6] = ' ';
		x[rH + 4][cH + 6] = ' ';

		x[rH + 4][cH - 3] = '_';
		x[rH + 4][cH - 4] = '|';
		x[rH + 3][cH - 4] = '|';
		x[rH + 2][cH - 4] = '|';
		x[rH + 1][cH - 4] = '|';
		x[rH][cH - 5] = '_';
		x[rH + 1][cH - 6] = '|';
		x[rH + 2][cH - 6] = '|';
		x[rH + 3][cH - 6] = '|';
		x[rH + 4][cH - 6] = '|';
		x[rH + 5][cH - 6] = '|';
		x[rH + 5][cH - 5] = '_';
		x[rH + 5][cH - 4] = '_';

		x[rH + 1][cH - 5] = ' ';
		x[rH + 2][cH - 5] = ' ';
		x[rH + 3][cH - 5] = ' ';
		x[rH + 4][cH - 5] = ' ';

		x[rH + 9][cH - 2] = '|';
		x[rH + 10][cH - 2] = '|';
		x[rH + 11][cH - 2] = '|';
		x[rH + 9][cH - 1] = ' ';
		x[rH + 10][cH - 1] = ' ';
		x[rH + 11][cH - 1] = ' ';
		x[rH + 12][cH - 2] = '|';
		x[rH + 12][cH - 1] = '_';
		x[rH + 12][cH] = '|';
		x[rH + 11][cH] = '|';
		x[rH + 10][cH] = '|';
		x[rH + 9][cH] = '|';

		x[rH + 9][cH + 3] = '|';
		x[rH + 10][cH + 3] = '|';
		x[rH + 10][cH + 2] = '_';
		x[rH + 10][cH + 1] = '|';
		x[rH + 9][cH + 1] = '|';


	}
	else
	{

		x[rH + 4][cH + 4] = '_';
		x[rH + 4][cH + 5] = '|';
		x[rH + 3][cH + 5] = '|';
		x[rH + 2][cH + 5] = '|';
		x[rH + 1][cH + 5] = '|';
		x[rH][cH + 6] = '_';
		x[rH + 1][cH + 7] = '|';
		x[rH + 2][cH + 7] = '|';
		x[rH + 3][cH + 7] = '|';
		x[rH + 4][cH + 7] = '|';
		x[rH + 5][cH + 7] = '|';
		x[rH + 5][cH + 6] = '_';
		x[rH + 5][cH + 5] = '_';

		x[rH + 1][cH + 6] = ' ';
		x[rH + 2][cH + 6] = ' ';
		x[rH + 3][cH + 6] = ' ';
		x[rH + 4][cH + 6] = ' ';

		x[rH + 4][cH - 3] = '_';
		x[rH + 4][cH - 4] = '|';
		x[rH + 3][cH - 4] = '|';
		x[rH + 2][cH - 4] = '|';
		x[rH + 1][cH - 4] = '|';
		x[rH][cH - 5] = '_';
		x[rH + 1][cH - 6] = '|';
		x[rH + 2][cH - 6] = '|';
		x[rH + 3][cH - 6] = '|';
		x[rH + 4][cH - 6] = '|';
		x[rH + 5][cH - 6] = '|';
		x[rH + 5][cH - 5] = '_';
		x[rH + 5][cH - 4] = '_';

		x[rH + 1][cH - 5] = ' ';
		x[rH + 2][cH - 5] = ' ';
		x[rH + 3][cH - 5] = ' ';
		x[rH + 4][cH - 5] = ' ';


		x[rH + 9][cH + 3] = '|';
		x[rH + 10][cH + 3] = '|';
		x[rH + 11][cH + 3] = '|';
		x[rH + 9][cH + 2] = ' ';
		x[rH + 10][cH + 2] = ' ';
		x[rH + 11][cH + 2] = ' ';
		x[rH + 12][cH + 3] = '|';
		x[rH + 12][cH + 2] = '_';
		x[rH + 12][cH + 1] = '|';
		x[rH + 11][cH + 1] = '|';
		x[rH + 10][cH + 1] = '|';
		x[rH + 9][cH + 1] = '|';

		x[rH + 9][cH - 2] = '|';
		x[rH + 10][cH - 2] = '|';
		x[rH + 10][cH - 1] = '_';
		x[rH + 10][cH] = '|';
		x[rH + 9][cH] = '|';


	}

	x[rH + 5][cH - 2] = ' ';
	x[rH + 5][cH - 1] = ' ';
	x[rH + 5][cH] = ' ';
	x[rH + 5][cH + 1] = ' ';
	x[rH + 5][cH + 2] = ' ';
	x[rH + 5][cH + 3] = ' ';
	x[rH + 5][cH + 4] = ' ';
	x[rH + 5][cH + 5] = ' ';

	x[rH + 6][cH - 2] = ' ';
	x[rH + 6][cH - 1] = ' ';
	x[rH + 6][cH] = ' ';
	x[rH + 6][cH + 1] = ' ';
	x[rH + 6][cH + 2] = ' ';
	x[rH + 6][cH + 3] = ' ';
	x[rH + 6][cH + 4] = ' ';
	x[rH + 6][cH + 5] = ' ';

	x[rH + 7][cH - 2] = ' ';
	x[rH + 7][cH - 1] = ' ';
	x[rH + 7][cH] = ' ';
	x[rH + 7][cH + 1] = ' ';
	x[rH + 7][cH + 2] = ' ';
	x[rH + 7][cH + 3] = ' ';
	x[rH + 7][cH + 4] = ' ';
	x[rH + 7][cH + 5] = ' ';

	x[rH + 8][cH - 2] = ' ';
	x[rH + 8][cH - 1] = ' ';
	x[rH + 8][cH] = ' ';
	x[rH + 8][cH + 1] = ' ';
	x[rH + 8][cH + 2] = ' ';
	x[rH + 8][cH + 3] = ' ';
	x[rH + 8][cH + 4] = ' ';
	x[rH + 8][cH + 5] = ' ';

	x[rH + 9][cH - 1] = ' ';
	//x[rH + 10][cH - 1] = ' ';

	x[rH + 9][cH + 2] = ' ';
	//x[rH + 10][cH + 2] = ' ';
	//x[rH + 11][cH + 2] = ' ';

	//x[rH + 5][cH - 3] = '_';
	//x[rH + 5][cH - 2] = '_';
	//x[rH + 6][cH - 2] = 179;
	x[rH + 7][cH - 2] = 179;
	x[rH + 8][cH - 2] = 179;

	x[rH + 5][cH + 5] = '_';
	x[rH + 5][cH + 4] = '_';
	//x[rH + 5][cH + 3] = '_';
	//x[rH + 6][cH + 3] = 179;
	x[rH + 7][cH + 3] = 179;
	x[rH + 8][cH + 3] = 179;

	x[rH + 5][cH + 4] = ' ';

}

void StaticHero5(char x[][138], int &rH, int &cH, int countRLHL1, int& CountStart, int& LeftLook, int Reload, int ActionReload, int level, int rB, int cB)
{

	x[rH][cH - 1] = '_';
	x[rH][cH] = '_';
	x[rH][cH + 1] = '_';
	x[rH][cH + 2] = '_';

	if (LeftLook == 1)
	{

		x[rH + 2][cH] = ' ';
		x[rH + 2][cH + 2] = ' ';

		x[rH + 2][cH + 1] = '-';
		x[rH + 2][cH - 1] = '-';

	}
	else
	{
		x[rH + 2][cH] = '-';
		x[rH + 2][cH + 2] = '-';

		x[rH + 2][cH + 1] = ' ';
		x[rH + 2][cH - 1] = ' ';
	}

	x[rH + 1][cH - 2] = '/';
	x[rH + 1][cH + 3] = '\\';

	x[rH + 2][cH - 2] = '|';
	x[rH + 2][cH + 3] = '|';

	x[rH + 3][cH - 2] = '\\';
	x[rH + 3][cH + 3] = '/';

	x[rH + 3][cH - 1] = '_';
	x[rH + 3][cH] = '_';
	x[rH + 3][cH + 1] = 251;
	x[rH + 3][cH + 2] = '_';

	x[rH + 4][cH - 2] = '_';
	x[rH + 4][cH - 1] = '/';
	x[rH + 4][cH + 2] = '/';
	x[rH + 4][cH + 3] = '_';

	if (countRLHL1 == 0)
	{


		x[rH + 6][cH + 4] = '\\';	//RIGHT HAND
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 6] = '_';
		x[rH + 6][cH + 7] = '/';
		x[rH + 5][cH + 8] = '_';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '\\';
		x[rH + 5][cH + 6] = '/';
		x[rH + 4][cH + 4] = '_';

		x[rH + 4][cH + 7] = '_';	//GUN
		x[rH + 4][cH + 8] = '_';
		x[rH + 4][cH + 9] = '_';
		x[rH + 4][cH + 10] = '_';
		x[rH + 4][cH + 11] = '_';
		x[rH + 4][cH + 12] = '_';
		x[rH + 5][cH + 13] = '|';
		x[rH + 5][cH + 12] = '_';
		x[rH + 5][cH + 11] = '_';
		x[rH + 5][cH + 10] = '_';
		x[rH + 6][cH + 9] = '/';
		x[rH + 6][cH + 8] = '_';

		x[rH + 6][cH + 12] = '2';



	}
	if (countRLHL1 % 2 != 0)
	{
		x[rH + 6][cH + 4] = '_';	//RIGHT HAND
		x[rH + 6][cH + 3] = ' ';
		x[rH + 5][cH + 3] = '/';
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 7] = ' ';
		x[rH + 6][cH + 6] = ' ';//
		x[rH + 6][cH + 8] = ' ';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '_';
		x[rH + 5][cH + 6] = ' ';
		x[rH + 5][cH + 7] = ' ';
		x[rH + 4][cH + 4] = ' ';
		x[rH + 5][cH + 4] = '_';
		x[rH + 4][cH + 7] = ' ';

		x[rH + 5][cH + 6] = ' ';	//GUN
		x[rH + 6][cH + 6] = '/';
		x[rH + 5][cH + 7] = '_';
		x[rH + 5][cH + 8] = '_';
		x[rH + 5][cH + 9] = '_';
		x[rH + 5][cH + 10] = '_';
		x[rH + 5][cH + 11] = '_';
		x[rH + 6][cH + 12] = '|';
		x[rH + 6][cH + 11] = '_';
		x[rH + 6][cH + 10] = '_';
		x[rH + 6][cH + 9] = '_';
		x[rH + 7][cH + 8] = '/';
		x[rH + 7][cH + 7] = '_';
		x[rH + 6][cH + 7] = ' ';
		x[rH + 7][cH + 6] = '|';


		x[rH + 7][cH + 11] = '2';



	}
	else
	{
		x[rH + 6][cH + 4] = '\\';	//RIGHT HAND
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 6] = '_';
		x[rH + 6][cH + 7] = '/';
		x[rH + 5][cH + 8] = '_';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '\\';
		x[rH + 5][cH + 6] = '/';
		x[rH + 4][cH + 4] = '_';

		x[rH + 4][cH + 7] = '_';	//GUN
		x[rH + 4][cH + 8] = '_';
		x[rH + 4][cH + 9] = '_';
		x[rH + 4][cH + 10] = '_';
		x[rH + 4][cH + 11] = '_';
		x[rH + 4][cH + 12] = '_';
		x[rH + 5][cH + 13] = '|';
		x[rH + 5][cH + 12] = '_';
		x[rH + 5][cH + 11] = '_';
		x[rH + 5][cH + 10] = '_';
		x[rH + 6][cH + 9] = '/';
		x[rH + 6][cH + 8] = '_';

		x[rH + 6][cH + 12] = '2';


	}

	LeftHandMoveH1(x, rH, cH, countRLHL1, Reload, ActionReload, level, rB, cB);

	//x[rH + 5][cH + 3] = ' ';	   
	//x[rH + 6][cH + 3] = '|';	   
	x[rH + 7][cH + 3] = '|';

	//x[rH + 5][cH - 2] = ' ';
	//x[rH + 6][cH - 2] = ' ';
	x[rH + 7][cH - 2] = '|';

	x[rH + 7][cH - 1] = ' ';
	x[rH + 7][cH + 1] = ' ';
	x[rH + 7][cH + 2] = ' ';
	x[rH + 7][cH] = ' ';

	LeftLegMoveH1(x, rH, cH, countRLHL1);
	RightLegMoveH1(x, rH, cH, countRLHL1);
}

void StaticHeroFS(char x[][138], int &rH, int &cH, int counter, int timerFS)
{


	x[rH][cH - 1] = '_';
	x[rH][cH] = '_';
	x[rH][cH + 1] = '_';
	x[rH][cH + 2] = '_';



	//x[rH + 2][cH] = ' ';
	//x[rH + 2][cH + 2] = ' ';

	//x[rH + 2][cH + 1] = '-';
	//x[rH + 2][cH - 1] = '-';


	//x[rH + 2][cH] = '-';
	//x[rH + 2][cH + 2] = '-';

	//x[rH + 2][cH + 1] = ' ';
	//x[rH + 2][cH - 1] = ' ';


	x[rH + 1][cH - 2] = '/';
	x[rH + 1][cH + 3] = '\\';

	x[rH + 2][cH - 2] = '|';
	x[rH + 2][cH + 3] = '|';

	x[rH + 3][cH - 2] = '\\';
	x[rH + 3][cH + 3] = '/';

	x[rH + 3][cH - 1] = '_';
	x[rH + 3][cH] = '_';
	x[rH + 3][cH + 1] = '_';
	x[rH + 3][cH + 2] = '_';

	x[rH + 4][cH - 2] = '_';
	x[rH + 4][cH - 1] = 179;
	x[rH + 4][cH + 2] = 179;
	x[rH + 4][cH + 3] = '_';



	//x[rH + 5][cH + 3] = ' ';	   
	//x[rH + 6][cH + 3] = '|';	   
	x[rH + 7][cH + 3] = '|';
	x[rH + 8][cH + 3] = '|';


	//x[rH + 5][cH - 2] = ' ';
	//x[rH + 6][cH - 2] = ' ';
	x[rH + 7][cH - 2] = '|';
	x[rH + 8][cH - 2] = '|';


	x[rH + 8][cH - 1] = '_';
	x[rH + 8][cH + 1] = '_';
	x[rH + 8][cH + 2] = '_';
	x[rH + 8][cH] = '_';



	if (timerFS >= 0 && timerFS <= 15)
	{
		if (counter % 2 == 0)
		{

			x[rH + 4][cH + 4] = '_';
			x[rH + 5][cH + 5] = '|';
			x[rH + 6][cH + 5] = '|';
			x[rH + 7][cH + 5] = '|';
			x[rH + 8][cH + 5] = '|';
			x[rH + 8][cH + 4] = '_';

			x[rH + 3][cH - 3] = '|';
			x[rH + 2][cH - 4] = '_';
			x[rH + 3][cH - 5] = '|';
			x[rH + 4][cH - 5] = '|';
			x[rH + 5][cH - 5] = '|';
			x[rH + 6][cH - 4] = '\\';
			x[rH + 6][cH - 3] = '_';

			x[rH + 9][cH - 2] = '|';
			x[rH + 10][cH - 2] = '|';
			x[rH + 11][cH - 2] = '|';
			x[rH + 12][cH - 2] = '|';
			x[rH + 12][cH - 1] = '_';
			x[rH + 12][cH] = '|';
			x[rH + 11][cH] = '|';
			x[rH + 10][cH] = '|';
			x[rH + 9][cH] = '|';

			x[rH + 9][cH + 3] = '|';
			x[rH + 10][cH + 3] = '|';
			x[rH + 10][cH + 2] = ' ';
			x[rH + 10][cH + 1] = '|';
			x[rH + 9][cH + 1] = '|';
			rH--;

		}
		else
		{

			x[rH + 3][cH + 4] = '|';
			x[rH + 2][cH + 5] = '_';
			x[rH + 3][cH + 6] = '|';
			x[rH + 4][cH + 6] = '|';
			x[rH + 5][cH + 6] = '|';
			x[rH + 6][cH + 5] = '/';
			x[rH + 6][cH + 4] = '_';

			x[rH + 4][cH - 3] = '_';
			x[rH + 5][cH - 4] = '|';
			x[rH + 6][cH - 4] = '|';
			x[rH + 7][cH - 4] = '|';
			x[rH + 8][cH - 4] = '|';
			x[rH + 8][cH - 3] = '_';

			x[rH + 9][cH + 3] = '|';
			x[rH + 10][cH + 3] = '|';
			x[rH + 11][cH + 3] = '|';
			x[rH + 12][cH + 3] = '|';
			x[rH + 12][cH + 2] = '_';
			x[rH + 12][cH + 1] = '|';
			x[rH + 11][cH + 1] = '|';
			x[rH + 10][cH + 1] = '|';
			x[rH + 9][cH + 1] = '|';

			x[rH + 9][cH - 2] = '|';
			x[rH + 10][cH - 2] = '|';
			x[rH + 10][cH - 1] = ' ';
			x[rH + 10][cH] = '|';
			x[rH + 9][cH] = '|';
			rH--;

		}
	}
	else
	{
		x[rH + 4][cH + 4] = '_';
		x[rH + 5][cH + 5] = '|';
		x[rH + 6][cH + 5] = '|';
		x[rH + 7][cH + 5] = '|';
		x[rH + 8][cH + 5] = '|';
		x[rH + 8][cH + 4] = '_';

		x[rH + 4][cH - 3] = '_';
		x[rH + 5][cH - 4] = '|';
		x[rH + 6][cH - 4] = '|';
		x[rH + 7][cH - 4] = '|';
		x[rH + 8][cH - 4] = '|';
		x[rH + 8][cH - 3] = '_';

		x[rH + 9][cH + 3] = '|';
		x[rH + 10][cH + 3] = '|';
		x[rH + 11][cH + 3] = '|';
		x[rH + 12][cH + 3] = '|';
		x[rH + 12][cH + 2] = '_';
		x[rH + 12][cH + 1] = '|';
		x[rH + 11][cH + 1] = '|';
		x[rH + 10][cH + 1] = '|';
		x[rH + 9][cH + 1] = '|';

		x[rH + 9][cH - 2] = '|';
		x[rH + 10][cH - 2] = '|';
		x[rH + 11][cH - 2] = '|';
		x[rH + 12][cH - 2] = '|';
		x[rH + 12][cH - 1] = '_';
		x[rH + 12][cH] = '|';
		x[rH + 11][cH] = '|';
		x[rH + 10][cH] = '|';
		x[rH + 9][cH] = '|';

		x[rH + 2][cH + 1] = '-';
		x[rH + 2][cH - 1] = '-';
	}
}

void DynamicHero(char x[][138], int& rH, int& cH, char keyB, int& countRLHL1, int& flag1, int& CounterUntilStop, int& pass1, int& pass2, int& lose1, int& ScrollCounter, int& GetOut, int& LeftLook, int& rEv, int& level, int& DeathT, int& shoot1, int& SkateIn, int& rSkate, int& cSkate, int& RopeIn, int& rR, int & cR, int& rMS1, int& cMS1, int& rMS2, int& cMS2, int& ClickShot, int& WhichShot, int& rB, int &cB, int &ct, int win, int& rEvR, int& cT6, int& cFC, int& TelephRide, int& ladder, int& AutoWalk, int& AutoWalkCounter)
{
	if (keyB == 32)
	{
		if ((rH + 11 == 47 || x[rH + 11][cH - 6] != ' ' || x[rH + 11][cH - 5] != ' ' || x[rH + 11][cH - 4] != ' ' || x[rH + 11][cH - 3] != ' ' || x[rH + 11][cH - 2] != ' ' || x[rH + 11][cH - 1] != ' ' || x[rH + 11][cH] != ' ' || x[rH + 11][cH + 1] != ' ' || x[rH + 11][cH + 2] != ' ' || x[rH + 11][cH + 3] != ' ' || x[rH + 11][cH + 4] != ' ' || x[rH + 11][cH + 5] != ' ' || x[rH + 11][cH + 6] != ' ') && (cH + 5) < 137 && (GetOut == 0 || GetOut == 3))
		{
			if (CounterUntilStop >= 14 && level == 1)
			{
				for (int i = 0; i < 20; i++)
				{
					if (x[rH - 1][cH] == ' ' && x[rH - 1][cH - 1] == ' ' && x[rH - 1][cH - 2] == ' ' && x[rH - 1][cH + 1] == ' ' && x[rH - 1][cH + 2] == ' ' && x[rH - 1][cH + 3] == ' ')
					{
						rH--;

					}

					else
					{
						break;
					}
				}

				//cH += 1;
				flag1 = 1;
			}
			if (level == 2)
			{
				for (int i = 0; i < 20; i++)
				{
					if ((x[rH - 1][cH] == ' ' && x[rH - 1][cH - 1] == ' ' && x[rH - 1][cH - 2] == ' ' && x[rH - 1][cH + 1] == ' ' && x[rH - 1][cH + 2] == ' ' && x[rH - 1][cH + 3] == ' ') || (x[rH - 1][cH] == 3 || x[rH - 1][cH - 1] == 3 || x[rH - 1][cH - 2] == 3 || x[rH - 1][cH + 1] == 3 || x[rH - 1][cH + 2] == 3 || x[rH - 1][cH + 3] == 3))
					{
						rH--;

					}

					else
					{
						break;
					}
				}

				//cH += 1;
				flag1 = 1;
			}

			if (level == 3 && SkateIn == 1)
			{
				for (int i = 0; i < 20; i++)
				{
					if (x[rH - 1][cH] == ' ' && x[rH - 1][cH - 1] == ' ' && x[rH - 1][cH - 2] == ' ' && x[rH - 1][cH + 1] == ' ' && x[rH - 1][cH + 2] == ' ' && x[rH - 1][cH + 3] == ' ')
					{
						rH -= 1;
						rSkate -= 1;
						cH += 7;
						cSkate += 7;
						LeftLook = 0;

					}

					else
					{
						break;
					}
				}

				//cH += 1;
				flag1 = 1;
			}

			if (level == 3 && SkateIn == 0)
			{
				for (int i = 0; i < 20; i++)
				{
					if (x[rH - 1][cH] == ' ' && x[rH - 1][cH - 1] == ' ' && x[rH - 1][cH - 2] == ' ' && x[rH - 1][cH + 1] == ' ' && x[rH - 1][cH + 2] == ' ' && x[rH - 1][cH + 3] == ' ')
					{
						rH--;


					}

					else
					{
						break;
					}
				}

				//cH += 1;
				flag1 = 1;
			}

			if (level == 4 && RopeIn == 0)
			{
				for (int i = 0; i < 20; i++)
				{
					if (x[rH - 1][cH] == ' ' && x[rH - 1][cH - 1] == ' ' && x[rH - 1][cH - 2] == ' ' && x[rH - 1][cH + 1] == ' ' && x[rH - 1][cH + 2] == ' ' && x[rH - 1][cH + 3] == ' ')
					{
						rH--;

					}

					else
					{
						break;
					}
				}

				//cH += 1;
				flag1 = 1;
			}

			if (level == 5)
			{
				for (int i = 0; i < 20; i++)
				{
					if (x[rH - 3][cH] == ' ' && x[rH - 3][cH - 1] == ' ' && x[rH - 3][cH - 2] == ' ' && x[rH - 3][cH + 1] == ' ' && x[rH - 3][cH + 2] == ' ' && x[rH - 3][cH + 3] == ' ')
					{
						rH--;
						countRLHL1 = 2;
					}

					else
					{
						break;
					}
				}

				//cH += 1;
				flag1 = 1;
			}

		}

		if (cH - 1 > 137)
		{
			cH = 0;
			rH = 36;
		}
	}


	if (keyB == 's' || keyB == 'S')
	{
		if ((GetOut == 0 || GetOut == 3) && rH < 36 && level != 6)
		{
			countRLHL1 = 2;
			//cH -= 2;

			for (;;)
			{
				if (x[rH + 11][cH - 4] == ' ' && x[rH + 11][cH - 3] == ' ' && x[rH + 11][cH - 2] == ' ' && x[rH + 11][cH - 1] == ' ' && x[rH + 11][cH] == ' ' && x[rH + 11][cH + 1] == ' ' && x[rH + 11][cH + 2] == ' ' && x[rH + 11][cH + 3] == ' ' && x[rH + 11][cH + 4] == ' ')
				{
					rH++;
				}
				else
				{
					break;
				}
			}
			//rH--;

			flag1 = 0;
			RopeIn = 0;
		}

		if (level == 6 && rH <= 34 && ladder == 2 && TelephRide == 0)
		{
			rH++;
			countRLHL1++;
		}
		/*if (level == 1 && GetOut == 1)
		{
			if (rEv + 13 < 46)
			{
				rH += 2;
				rEv += 2;
				rEvR += 2;
			}

		}*/
	}


	if (keyB == 'a' || keyB == 'A')
	{
		AutoWalk = 0;
		AutoWalkCounter = 1;
		if (cH - 1 > 1)
		{

			if (CounterUntilStop >= 21 && level == 1)
			{
				if (x[rH + 10][cH - 5] == ' ' && GetOut != 1 && x[rH][cH - 3] == ' ' && x[rH + 1][cH - 3] == ' ' && x[rH + 2][cH - 3] == ' ' && x[rH + 3][cH - 3] == ' ' && x[rH + 4][cH - 5] == ' ' && x[rH + 5][cH - 6] == ' ' && x[rH + 6][cH - 5] == ' ' && x[rH + 7][cH - 6] == ' ' && x[rH + 8][cH - 6] == ' ' && x[rH + 9][cH - 5] == ' ')
				{
					cH -= 2;
					countRLHL1 = 2;
					LeftLook = 1;


					if (cH + 10 >= 108 && rEv == 34)
					{
						GetOut = 3;
					}
					else
					{
						if (rEv == 34)
						{
							GetOut = 0;
						}
					}


				}
			}
			if (level == 2)
			{
				if ((x[rH + 10][cH - 5] == ' ' && GetOut != 1 && x[rH][cH - 3] == ' ' && x[rH + 1][cH - 3] == ' ' && x[rH + 2][cH - 3] == ' ' && x[rH + 3][cH - 3] == ' ' && x[rH + 4][cH - 4] == ' ' && x[rH + 5][cH - 5] == ' ' && x[rH + 6][cH - 5] == ' ' && x[rH + 7][cH - 5] == ' ' && x[rH + 8][cH - 5] == ' ' && x[rH + 9][cH - 5] == ' ' && x[rH + 10][cH - 5] == ' ') || (x[rH][cH - 3] == 3 || x[rH + 1][cH - 3] == 3 || x[rH + 2][cH - 3] == 3 || x[rH + 3][cH - 3] == 3 || x[rH + 4][cH - 4] == 3 || x[rH + 5][cH - 5] == 3 || x[rH + 6][cH - 5] == 3 || x[rH + 7][cH - 5] == 3 || x[rH + 8][cH - 5] == 3 || x[rH + 9][cH - 5] == 3 || x[rH + 10][cH - 5] == 3))
				{
					cH -= 2;
					countRLHL1 = 2;
					LeftLook = 1;

				}
			}
			if (level == 3 && SkateIn == 1)
			{

				LeftLook = 1;
				//countRLHL1++;
				cH -= 5;
				cSkate -= 5;
			}

			if (level == 3 && SkateIn == 0)
			{

				LeftLook = 1;
				countRLHL1 = 2;
				cH -= 2;

			}

			if (level == 4 && RopeIn == 0)
			{
				cH -= 2;
				countRLHL1 = 2;
				LeftLook = 1;


			}
			if (level == 4 && RopeIn == 1)
			{
				cH -= 4;
				cR -= 4;
				countRLHL1 = 2;
				LeftLook = 1;


			}

			if (level == 5)
			{
				cH -= 2;
				countRLHL1 = 2;
				LeftLook = 1;


			}

			if (level == 6 && cT6 > 14 && TelephRide == 2)
			{
				cH -= 4;
				cT6 -= 4;
				LeftLook = 1;
				if (cFC + 20 <= 137)
				{
					cFC += 4;
				}
			}

			if (level == 6 && TelephRide == 0 && ladder == 0)
			{
				cH -= 2;
				LeftLook = 1;
				countRLHL1 = 2;
			}

			if (level == 6 && (ladder == 2 || ladder == 1) && TelephRide == 0)
			{
				ladder = 0;
				rH = 36;
				cH -= 14;
				countRLHL1 = 2;
			}

			if (cH - 3 < 0)
			{
				lose1 = 1;
				DeathT = 0;
			}
		}
	}


	if (keyB == 'd' || keyB == 'D')
	{
		AutoWalk = 0;
		AutoWalkCounter = 1;
		if (rH < 0 && level == 1)
		{
			rH = rEv + 1;
		}
		if (CounterUntilStop >= 14 && level == 1)
		{

			if (level == 1 && x[rH + 11][cH + 5] != '_' && x[rH + 11][cH + 5] != '|' && GetOut != 1)
			{
				cH++; //FIXED
			}
			if (level == 1 && x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ' && GetOut != 1)
			{
				LeftLook = 0;
				countRLHL1++;
				cH += 1.8;


				if (cH + 10 >= 108 && rEv == 33)
				{
					GetOut = 3;
				}
				else
				{
					if (rEv == 33)
					{
						GetOut = 0;
					}
				}
			}


		}
		if (level == 2 && (rH == 36 || rH == 23))
		{
			if (level == 2 && x[rH + 11][cH + 5] != '_' && x[rH + 11][cH + 5] != '|' && GetOut != 1 && x[rH][cH + 9] == ' ' && x[rH + 1][cH + 9] == ' ' && x[rH + 2][cH + 9] == ' ' && x[rH + 3][cH + 9] == ' ' && x[rH + 4][cH + 9] == ' ' && x[rH + 5][cH + 9] == ' ' && x[rH + 6][cH + 9] == ' ' && x[rH + 7][cH + 9] == ' ' && x[rH + 8][cH + 5] == ' ' && x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ' || (x[rH][cH + 9] == 3 || x[rH + 1][cH + 9] == 3 || x[rH + 2][cH + 9] == 3 || x[rH + 3][cH + 9] == 3 || x[rH + 4][cH + 9] == 3 || x[rH + 5][cH + 9] == 3 || x[rH + 6][cH + 9] == 3 || x[rH + 7][cH + 9] == 3 || x[rH + 8][cH + 5] == 3 || x[rH + 9][cH + 5] == 3 || x[rH + 10][cH + 5] == 3 || x[rH + 10][cH + 6] == 3))
			{
				cH++; //FIXED
			}
			if (level == 2 && x[rH][cH + 9] == ' ' && x[rH + 1][cH + 9] == ' ' && x[rH + 2][cH + 9] == ' ' && x[rH + 3][cH + 9] == ' ' && x[rH + 4][cH + 9] == ' ' && x[rH + 5][cH + 9] == ' ' && x[rH + 6][cH + 9] == ' ' && x[rH + 7][cH + 9] == ' ' && x[rH + 8][cH + 5] == ' ' && x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ' || (x[rH][cH + 9] == 3 || x[rH + 1][cH + 9] == 3 || x[rH + 2][cH + 9] == 3 || x[rH + 3][cH + 9] == 3 || x[rH + 4][cH + 9] == 3 || x[rH + 5][cH + 9] == 3 || x[rH + 6][cH + 9] == 3 || x[rH + 7][cH + 9] == 3 || x[rH + 8][cH + 5] == 3 || x[rH + 9][cH + 5] == 3 || x[rH + 10][cH + 5] == 3 || x[rH + 10][cH + 6] == 3) && GetOut != 1)
			{
				LeftLook = 0;
				countRLHL1++;
				cH += 1.8;

			}



		}

		if (level == 2 && rH != 36 && rH != 23)
		{
			if (level == 2 && x[rH + 11][cH + 5] != '_' && x[rH + 11][cH + 5] != '|' && GetOut != 1 && x[rH][cH + 9] == ' ' && x[rH + 1][cH + 9] == ' ' && x[rH + 2][cH + 9] == ' ' && x[rH + 3][cH + 9] == ' ' && x[rH + 4][cH + 9] == ' ' && x[rH + 5][cH + 9] == ' ' && x[rH + 6][cH + 9] == ' ' && x[rH + 7][cH + 9] == ' ' && x[rH + 8][cH + 5] == ' ' && x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ' || (x[rH][cH + 9] == 3 || x[rH + 1][cH + 9] == 3 || x[rH + 2][cH + 9] == 3 || x[rH + 3][cH + 9] == 3 || x[rH + 4][cH + 9] == 3 || x[rH + 5][cH + 9] == 3 || x[rH + 6][cH + 9] == 3 || x[rH + 7][cH + 9] == 3 || x[rH + 8][cH + 5] == 3 || x[rH + 9][cH + 5] == 3 || x[rH + 10][cH + 5] == 3 || x[rH + 10][cH + 6] == 3))
			{
				cH++; //FIXED
			}
			if (level == 2 && x[rH][cH + 9] == ' ' && x[rH + 1][cH + 9] == ' ' && x[rH + 2][cH + 9] == ' ' && x[rH + 3][cH + 9] == ' ' && x[rH + 4][cH + 9] == ' ' && x[rH + 5][cH + 9] == ' ' && x[rH + 6][cH + 9] == ' ' && x[rH + 7][cH + 9] == ' ' && x[rH + 8][cH + 5] == ' ' && x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ' || (x[rH][cH + 9] == 3 || x[rH + 1][cH + 9] == 3 || x[rH + 2][cH + 9] == 3 || x[rH + 3][cH + 9] == 3 || x[rH + 4][cH + 9] == 3 || x[rH + 5][cH + 9] == 3 || x[rH + 6][cH + 9] == 3 || x[rH + 7][cH + 9] == 3 || x[rH + 8][cH + 5] == 3 || x[rH + 9][cH + 5] == 3 || x[rH + 10][cH + 5] == 3 || x[rH + 10][cH + 6] == 3) && GetOut != 1)
			{
				LeftLook = 0;
				countRLHL1 = 2;
				cH += 1.8;

			}



		}




		if (level == 3 && SkateIn == 0 && rH == 36)
		{
			LeftLook = 0;
			countRLHL1++;
			cH += 1.4;
		}
		if (level == 3 && SkateIn == 0 && rH < 36)
		{
			LeftLook = 0;
			countRLHL1 = 2;
			cH += 1.4;
		}

		if (level == 3 && SkateIn == 1)
		{
			LeftLook = 0;
			countRLHL1 = 2;
			cH += 4;
			cSkate += 4;
		}
		//ALL

		if (level == 4 && RopeIn == 0 && rH == 36)
		{
			if (x[rH + 11][cH + 5] != '_' && x[rH + 11][cH + 5] != '|')
			{
				cH++; //FIXED
			}
			if (x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ')
			{
				LeftLook = 0;
				countRLHL1++;
				cH += 1.8;
			}
		}

		if (level == 4 && RopeIn == 0 && rH < 36)
		{
			if (x[rH + 11][cH + 5] != '_' && x[rH + 11][cH + 5] != '|')
			{
				cH++; //FIXED
			}
			if (x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ')
			{
				LeftLook = 0;
				countRLHL1 = 2;
				cH += 1.8;
			}
		}

		if (level == 4 && RopeIn == 1)
		{
			LeftLook = 0;
			cH += 4;
			cR += 4;

		}

		if (level == 5 && cH < 70 && rH == 36 && win == 0)
		{
			cH += 2;
			countRLHL1++;
			LeftLook = 0;
		}
		if (level == 5 && cH < 70 && rH < 36 && win == 0)
		{
			cH += 2;
			countRLHL1 = 2;
			LeftLook = 0;
		}

		if (level == 5 && rH == 36 && (win == 1 || win == 2))
		{
			cH += 2;
			countRLHL1++;
			LeftLook = 0;
		}
		if (level == 5 && rH < 36 && win == 1)
		{
			cH += 2;
			countRLHL1 = 2;
			LeftLook = 0;
		}

		if (level == 6 && TelephRide == 2 && ladder == 0)
		{
			cH += 4;
			cT6 += 4;
			LeftLook = 0;
			for (int l = 0; l < 4; l++)
			{

				if (x[37][cFC - 6] == ' ')
				{
					cFC--;
				}
				else
				{
					cFC++;
				}
			}
		}

		if (level == 6 && TelephRide == 0 && ladder == 0 && x[rH][cH + 9] == ' ')
		{
			cH += 2;
			countRLHL1++;
			LeftLook = 0;
		}


		if (level == 6 && (ladder == 2 || ladder == 1) && TelephRide == 0)
		{
			ladder = 0;
			rH = 36;
			cH -= 14;
			countRLHL1 = 2;
		}

		if (cH + 10 >= 137)
		{
			level++;
			ScrollCounter = 1;
			GetOut = 0;
			cout << "\a";

		}





	}


	if ((keyB == 'e' || keyB == 'E') && cH >= 24 && level == 3)
	{
		SkateIn = 1;
		rH = 33;
		cH = 42;
		countRLHL1 = 2;
	}


	if ((keyB == 'e' || keyB == 'E') && cH > (cR - 16) && cH < (cR + 4) && RopeIn == 0 && level == 4)
	{

		cH = cR - 5;
		rH = 26;
		RopeIn = 1;
		countRLHL1 = 2;

		if (LeftLook == 1)
		{

			x[rH + 2][cH] = ' ';
			x[rH + 2][cH + 2] = ' ';

			x[rH + 2][cH + 1] = '-';
			x[rH + 2][cH - 1] = '-';

		}
		else
		{
			x[rH + 2][cH] = '-';
			x[rH + 2][cH + 2] = '-';

			x[rH + 2][cH + 1] = ' ';
			x[rH + 2][cH - 1] = ' ';

		}
	}


	if ((keyB == 'e' || keyB == 'E') && level == 6)
	{
		if (x[rH][cH + 9] != ' ' && ladder == 0)
		{
			ladder = 1;
		}
		if (rH == 30)
		{
			ladder = 0;
			TelephRide = 1;
		}
	}


	if (keyB == 43 && level == 5 && ClickShot <= 2)
	{
		ClickShot++;
		WhichShot = 1;

		if (ClickShot == 1)
		{
			rMS1 = rH;
			cMS1 = cH;
		}

		if (ClickShot == 2)
		{
			rMS2 = rH;
			cMS2 = cH;
			rB = rH + 6;
			cB = cH + 7;
			ct = 0;
		}

		if (ClickShot > 2)
		{
			ClickShot = 2;
		}


	}


	if ((keyB == 'w' || keyB == 'W') && level == 6 && ladder == 2 && TelephRide == 0 && rH > 30)
	{
		countRLHL1++;
		rH--;
	}


	if ((keyB == 8) && CounterUntilStop > 14)
	{
		AutoWalkCounter++;
		LeftLook = 0;
		if (AutoWalkCounter % 2 == 0)
		{
			AutoWalk = 1;
		}
		else
		{
			AutoWalk = 0;
		}

	}
}

void LandCheck(char x[][138], int& rH, int& cH, int& flag1, int GetOut, int level, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4)
{
	if (GetOut != 1 && SkateIn == 0 && level != 4 && level != 5 && x[rH + 11][cH - 4] == ' ' && x[rH + 11][cH - 3] == ' ' && x[rH + 11][cH - 2] == ' ' && x[rH + 11][cH - 1] == ' ' && x[rH + 11][cH] == ' ' && x[rH + 11][cH + 1] == ' ' && x[rH + 11][cH + 2] == ' ' && x[rH + 11][cH + 3] == ' ' && x[rH + 11][cH + 4] == ' ' && x[rH + 8][cH + 4] == ' ' && x[rH + 8][cH + 5] == ' ' && x[rH + 8][cH + 6] == ' ' && x[rH + 8][cH + 7] == ' ' && (x[rH + 11][cH] == ' ' || x[rH + 11][cH] == '='))
	{
		rH++;
		if (rH < 32 && (GetOut == 0 || GetOut == 3))
		{
			x[rH - 3][cH + 4] = 'T';
			x[rH - 3][cH + 5] = 'a';
			x[rH - 3][cH + 6] = 'p';
			x[rH - 3][cH + 7] = ' ';
			x[rH - 3][cH + 8] = 39;
			x[rH - 3][cH + 9] = 's';
			x[rH - 3][cH + 10] = 39;
			x[rH - 3][cH + 11] = ' ';
			x[rH - 3][cH + 12] = 't';
			x[rH - 3][cH + 13] = 'o';
			x[rH - 3][cH + 14] = ' ';
			x[rH - 3][cH + 15] = 'f';
			x[rH - 3][cH + 16] = 'a';
			x[rH - 3][cH + 17] = 's';
			x[rH - 3][cH + 18] = 't';
			x[rH - 3][cH + 19] = ' ';
			x[rH - 3][cH + 20] = 'l';
			x[rH - 3][cH + 21] = 'a';
			x[rH - 3][cH + 22] = 'n';
			x[rH - 3][cH + 23] = 'd';
		}



		else
		{

			flag1 = 0;
		}

	}

	if (rH < 34 && rH > 25 && level == 2)
	{
		x[rH - 3][cH + 4] = 'T';
		x[rH - 3][cH + 5] = 'a';
		x[rH - 3][cH + 6] = 'p';
		x[rH - 3][cH + 7] = ' ';
		x[rH - 3][cH + 8] = 39;
		x[rH - 3][cH + 9] = 's';
		x[rH - 3][cH + 10] = 39;
		x[rH - 3][cH + 11] = ' ';
		x[rH - 3][cH + 12] = 't';
		x[rH - 3][cH + 13] = 'o';
		x[rH - 3][cH + 14] = ' ';
		x[rH - 3][cH + 15] = 'f';
		x[rH - 3][cH + 16] = 'a';
		x[rH - 3][cH + 17] = 's';
		x[rH - 3][cH + 18] = 't';
		x[rH - 3][cH + 19] = ' ';
		x[rH - 3][cH + 20] = 'l';
		x[rH - 3][cH + 21] = 'a';
		x[rH - 3][cH + 22] = 'n';
		x[rH - 3][cH + 23] = 'd';
	}

	if (level == 3 && SkateIn == 1 && rH < 33)
	{
		rH++;
		cH += 2;
		rSkate++;
		cSkate += 2;

	}

	if (RopeIn == 0 && level == 4 && rH <= 36)
	{
		rH++;
		if (rH < 32 && tap4 == 0)
		{
			x[rH - 3][cH + 4] = 'T';
			x[rH - 3][cH + 5] = 'a';
			x[rH - 3][cH + 6] = 'p';
			x[rH - 3][cH + 7] = ' ';
			x[rH - 3][cH + 8] = 39;
			x[rH - 3][cH + 9] = 's';
			x[rH - 3][cH + 10] = 39;
			x[rH - 3][cH + 11] = ' ';
			x[rH - 3][cH + 12] = 't';
			x[rH - 3][cH + 13] = 'o';
			x[rH - 3][cH + 14] = ' ';
			x[rH - 3][cH + 15] = 'f';
			x[rH - 3][cH + 16] = 'a';
			x[rH - 3][cH + 17] = 's';
			x[rH - 3][cH + 18] = 't';
			x[rH - 3][cH + 19] = ' ';
			x[rH - 3][cH + 20] = 'l';
			x[rH - 3][cH + 21] = 'a';
			x[rH - 3][cH + 22] = 'n';
			x[rH - 3][cH + 23] = 'd';
		}
		else
		{

			flag1 = 0;
		}

	}

	if (level == 5 && x[rH + 11][cH - 4] == ' ' && x[rH + 11][cH - 3] == ' ' && x[rH + 11][cH - 2] == ' ' && x[rH + 11][cH - 1] == ' ' && x[rH + 11][cH] == ' ' && x[rH + 11][cH + 1] == ' ' && x[rH + 11][cH + 2] == ' ' && x[rH + 11][cH + 3] == ' ' && x[rH + 11][cH + 4] == ' ' || x[rH + 11][cH] == '=')
	{
		rH++;


		if (level == 5 && rH < 32)
		{
			x[rH + 1][cH + 6] = 'T';
			x[rH + 1][cH + 7] = 'a';
			x[rH + 1][cH + 8] = 'p';
			x[rH + 1][cH + 9] = ' ';
			x[rH + 1][cH + 10] = 39;
			x[rH + 1][cH + 11] = 's';
			x[rH + 1][cH + 12] = 39;
			x[rH + 1][cH + 13] = ' ';
			x[rH + 1][cH + 14] = 't';
			x[rH + 1][cH + 15] = 'o';
			x[rH + 1][cH + 16] = ' ';
			x[rH + 1][cH + 17] = 'f';
			x[rH + 1][cH + 18] = 'a';
			x[rH + 1][cH + 19] = 's';
			x[rH + 1][cH + 20] = 't';
			x[rH + 1][cH + 21] = ' ';
			x[rH + 1][cH + 22] = 'l';
			x[rH + 1][cH + 23] = 'a';
			x[rH + 1][cH + 24] = 'n';
			x[rH + 1][cH + 25] = 'd';
		}

		else
		{

			flag1 = 0;
		}

	}

}

void AutoForward(char x[][138], int& rH, int& cH, int& countRLHL1, int& flag1, int& CounterUntilStop, int& pass1, int& pass2, int& lose1, int& ScrollCounter, int& GetOut, int& LeftLook, int& rEv, int& level, int& DeathT, int& shoot1, int& SkateIn, int& rSkate, int& cSkate, int& RopeIn, int& rR, int & cR, int& rMS1, int& cMS1, int& rMS2, int& cMS2, int& ClickShot, int& WhichShot, int& rB, int &cB, int &ct, int win, int& rEvR, int& cT6, int& cFC, int& TelephRide, int& ladder, int Reload, int ActionReload, int& AutoWalk) {
	if (CounterUntilStop < 14 && level == 1)
	{
		LeftHandMoveH1(x, rH, cH, countRLHL1, Reload, ActionReload, level, rB, cB);
		RightHandMoveH1(x, rH, cH, countRLHL1);
		RightLegMoveH1(x, rH, cH, countRLHL1);
		LeftLegMoveH1(x, rH, cH, countRLHL1);
		countRLHL1++;
		cH += 2;
		LeftLook = 0;
	}
	if (CounterUntilStop >= 14 && AutoWalk == 1)
	{
		if (rH < 0 && level == 1)
		{
			rH = rEv + 1;
		}
		if (CounterUntilStop >= 14 && level == 1)
		{


			if (level == 1 && x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ' && GetOut != 1)
			{
				LeftLook = 0;
				countRLHL1++;
				cH += 2.7;


				if (cH + 10 >= 108 && rEv == 33)
				{
					GetOut = 3;
				}
				else
				{
					if (rEv == 33)
					{
						GetOut = 0;
					}
				}
			}


		}
		if (level == 2 && (rH == 36 || rH == 23))
		{
			if (level == 2 && x[rH + 11][cH + 5] != '_' && x[rH + 11][cH + 5] != '|' && GetOut != 1 && x[rH][cH + 9] == ' ' && x[rH + 1][cH + 9] == ' ' && x[rH + 2][cH + 9] == ' ' && x[rH + 3][cH + 9] == ' ' && x[rH + 4][cH + 9] == ' ' && x[rH + 5][cH + 9] == ' ' && x[rH + 6][cH + 9] == ' ' && x[rH + 7][cH + 9] == ' ' && x[rH + 8][cH + 5] == ' ' && x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ' || (x[rH][cH + 9] == 3 || x[rH + 1][cH + 9] == 3 || x[rH + 2][cH + 9] == 3 || x[rH + 3][cH + 9] == 3 || x[rH + 4][cH + 9] == 3 || x[rH + 5][cH + 9] == 3 || x[rH + 6][cH + 9] == 3 || x[rH + 7][cH + 9] == 3 || x[rH + 8][cH + 5] == 3 || x[rH + 9][cH + 5] == 3 || x[rH + 10][cH + 5] == 3 || x[rH + 10][cH + 6] == 3))
			{
				cH++; //FIXED
			}
			if (level == 2 && x[rH][cH + 9] == ' ' && x[rH + 1][cH + 9] == ' ' && x[rH + 2][cH + 9] == ' ' && x[rH + 3][cH + 9] == ' ' && x[rH + 4][cH + 9] == ' ' && x[rH + 5][cH + 9] == ' ' && x[rH + 6][cH + 9] == ' ' && x[rH + 7][cH + 9] == ' ' && x[rH + 8][cH + 5] == ' ' && x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ' || (x[rH][cH + 9] == 3 || x[rH + 1][cH + 9] == 3 || x[rH + 2][cH + 9] == 3 || x[rH + 3][cH + 9] == 3 || x[rH + 4][cH + 9] == 3 || x[rH + 5][cH + 9] == 3 || x[rH + 6][cH + 9] == 3 || x[rH + 7][cH + 9] == 3 || x[rH + 8][cH + 5] == 3 || x[rH + 9][cH + 5] == 3 || x[rH + 10][cH + 5] == 3 || x[rH + 10][cH + 6] == 3) && GetOut != 1)
			{
				LeftLook = 0;
				countRLHL1++;
				cH += 1.8;

			}



		}

		if (level == 2 && rH != 36 && rH != 23)
		{
			if (level == 2 && x[rH + 11][cH + 5] != '_' && x[rH + 11][cH + 5] != '|' && GetOut != 1 && x[rH][cH + 9] == ' ' && x[rH + 1][cH + 9] == ' ' && x[rH + 2][cH + 9] == ' ' && x[rH + 3][cH + 9] == ' ' && x[rH + 4][cH + 9] == ' ' && x[rH + 5][cH + 9] == ' ' && x[rH + 6][cH + 9] == ' ' && x[rH + 7][cH + 9] == ' ' && x[rH + 8][cH + 5] == ' ' && x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ' || (x[rH][cH + 9] == 3 || x[rH + 1][cH + 9] == 3 || x[rH + 2][cH + 9] == 3 || x[rH + 3][cH + 9] == 3 || x[rH + 4][cH + 9] == 3 || x[rH + 5][cH + 9] == 3 || x[rH + 6][cH + 9] == 3 || x[rH + 7][cH + 9] == 3 || x[rH + 8][cH + 5] == 3 || x[rH + 9][cH + 5] == 3 || x[rH + 10][cH + 5] == 3 || x[rH + 10][cH + 6] == 3))
			{
				cH++; //FIXED
			}
			if (level == 2 && x[rH][cH + 9] == ' ' && x[rH + 1][cH + 9] == ' ' && x[rH + 2][cH + 9] == ' ' && x[rH + 3][cH + 9] == ' ' && x[rH + 4][cH + 9] == ' ' && x[rH + 5][cH + 9] == ' ' && x[rH + 6][cH + 9] == ' ' && x[rH + 7][cH + 9] == ' ' && x[rH + 8][cH + 5] == ' ' && x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ' || (x[rH][cH + 9] == 3 || x[rH + 1][cH + 9] == 3 || x[rH + 2][cH + 9] == 3 || x[rH + 3][cH + 9] == 3 || x[rH + 4][cH + 9] == 3 || x[rH + 5][cH + 9] == 3 || x[rH + 6][cH + 9] == 3 || x[rH + 7][cH + 9] == 3 || x[rH + 8][cH + 5] == 3 || x[rH + 9][cH + 5] == 3 || x[rH + 10][cH + 5] == 3 || x[rH + 10][cH + 6] == 3) && GetOut != 1)
			{
				LeftLook = 0;
				countRLHL1 = 2;
				cH += 1.8;

			}



		}




		if (level == 3 && SkateIn == 0 && rH == 36)
		{
			LeftLook = 0;
			countRLHL1++;
			cH += 1.4;
		}
		if (level == 3 && SkateIn == 0 && rH < 36)
		{
			LeftLook = 0;
			countRLHL1 = 2;
			cH += 1.4;
		}

		if (level == 3 && SkateIn == 1)
		{
			LeftLook = 0;
			countRLHL1 = 2;
			cH += 4;
			cSkate += 4;
		}
		//ALL

		if (level == 4 && RopeIn == 0 && rH == 36)
		{
			if (x[rH + 11][cH + 5] != '_' && x[rH + 11][cH + 5] != '|')
			{
				cH++; //FIXED
			}
			if (x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ')
			{
				LeftLook = 0;
				countRLHL1++;
				cH += 1.8;
			}
		}

		if (level == 4 && RopeIn == 0 && rH < 36)
		{
			if (x[rH + 11][cH + 5] != '_' && x[rH + 11][cH + 5] != '|')
			{
				cH++; //FIXED
			}
			if (x[rH + 9][cH + 5] == ' ' && x[rH + 10][cH + 5] == ' ' && x[rH + 10][cH + 6] == ' ')
			{
				LeftLook = 0;
				countRLHL1 = 2;
				cH += 1.8;
			}
		}

		if (level == 4 && RopeIn == 1)
		{
			LeftLook = 0;
			cH += 4;
			cR += 4;

		}

		if (level == 5 && cH < 70 && rH == 36 && win == 0)
		{
			cH += 2;
			countRLHL1++;
			LeftLook = 0;
		}
		if (level == 5 && cH < 70 && rH < 36 && win == 0)
		{
			cH += 2;
			countRLHL1 = 2;
			LeftLook = 0;
		}

		if (level == 5 && rH == 36 && win == 1)
		{
			cH += 2;
			countRLHL1++;
			LeftLook = 0;
		}
		if (level == 5 && rH < 36 && win == 1)
		{
			cH += 2;
			countRLHL1 = 2;
			LeftLook = 0;
		}

		if (level == 6 && TelephRide == 2 && ladder == 0)
		{
			cH += 4;
			cT6 += 4;
			LeftLook = 0;
			for (int l = 0; l < 4; l++)
			{

				if (x[37][cFC - 6] == ' ')
				{
					cFC--;
				}
				else
				{
					cFC++;
				}
			}
		}

		if (level == 6 && TelephRide == 0 && ladder == 0 && x[rH][cH + 9] == ' ')
		{
			cH += 2;
			countRLHL1++;
			LeftLook = 0;
		}




		if (cH + 10 >= 137)
		{
			level++;
			ScrollCounter = 1;
			GetOut = 0;
			cout << "\a";

		}
	}
}

void Constructor(char x[][138], int rH, int cH, int &ConstructorCount, int timer, int CounterUntilStop, int rGuide, int cGuide, int& cC, int level, int GetOut, int timer2, int timer3, int BSc, int flagScore1, int flagScore2, int flagScore3, int timer4, int flagTime1, int flagTime2, int flagTime3, int TSc, int mins, int flagScore4, int flagTime4, int timer5, int win, int timerBSC, int rFC, int cFC, int TelephRide)
{
	cC -= 2;
	if (CounterUntilStop >= 14 && CounterUntilStop <= 38 && level == 1)
	{
		x[28][cC] = 'G';
		x[28][cC + 1] = 'O';
		x[28][cC + 2] = '!';

	}

	if (timer >= 0 && timer <= 16 && level == 1)
	{
		x[6][24] = 'T';
		x[6][25] = 'h';
		x[6][26] = 'i';
		x[6][27] = 's';
		x[6][28] = ' ';
		x[6][29] = 'w';
		x[6][30] = 'i';
		x[6][31] = 'l';
		x[6][32] = 'l';
		x[6][33] = ' ';
		x[6][34] = 'g';
		x[6][35] = 'u';
		x[6][36] = 'i';
		x[6][37] = 'd';
		x[6][38] = 'e';
		x[6][39] = ' ';
		x[6][40] = 'y';
		x[6][41] = 'o';
		x[6][42] = 'u';


		x[5][23] = 22;
		x[5][22] = 22;
		x[5][21] = 22;
		x[5][20] = 22;
		x[5][19] = '|';
		x[4][19] = '|';
		x[3][19] = '|';
		x[2][19] = '|';

		x[1][19] = 30;
		/////////////////////////
		x[0][0] = '-';
		x[0][1] = 'I';
		x[0][2] = 39;
		x[0][3] = 'm';
		x[0][4] = ' ';
		x[0][5] = 'y';
		x[0][6] = 'o';
		x[0][7] = 'u';
		x[0][8] = 'r';
		x[0][9] = ' ';
		x[0][10] = 'i';
		x[0][11] = 'n';
		x[0][12] = 's';
		x[0][13] = 't';
		x[0][14] = 'r';
		x[0][15] = 'u';
		x[0][16] = 'c';
		x[0][17] = 't';
		x[0][18] = 'o';
		x[0][19] = 'r';
		x[0][20] = '.';
		x[0][21] = '.';
		x[0][22] = '.';
		x[0][23] = '.';
		//sleep_until(system_clock::now() + seconds(1));

	}

	if (timer > 16 && timer < 26 && level == 1)
	{
		x[0][0] = '-';
		x[0][1] = 'A';
		x[0][2] = ',';
		x[0][3] = 'S';
		x[0][4] = ',';
		x[0][5] = 'D';
		x[0][6] = ' ';
		x[0][7] = 't';
		x[0][8] = 'o';
		x[0][9] = ' ';
		x[0][10] = 'm';
		x[0][11] = 'o';
		x[0][12] = 'v';
		x[0][13] = 'e';




	}

	if (timer >= 36 && timer < 46 && level == 1)
	{

		x[0][0] = '-';
		x[0][1] = 'S';
		x[0][2] = 'p';
		x[0][3] = 'a';
		x[0][4] = 'c';
		x[0][5] = 'e';
		x[0][6] = ' ';
		x[0][7] = 't';
		x[0][8] = 'o';
		x[0][9] = ' ';
		x[0][10] = 'j';
		x[0][11] = 'u';
		x[0][12] = 'm';
		x[0][13] = 'p';



	}

	if (timer >= 46 && level == 1 && (GetOut == 0 || GetOut == 3))
	{

		x[0][0] = '-';
		x[0][1] = 'T';
		x[0][2] = 'a';
		x[0][3] = 'k';
		x[0][4] = 'e';
		x[0][5] = ' ';
		x[0][6] = 't';
		x[0][7] = 'h';
		x[0][8] = 'e';
		x[0][9] = ' ';
		x[0][10] = 'e';
		x[0][11] = 'l';
		x[0][12] = 'e';
		x[0][13] = 'v';
		x[0][14] = 'a';
		x[0][15] = 't';
		x[0][16] = 'o';
		x[0][17] = 'r';
		x[0][18] = '.';
		x[0][19] = '.';
		x[0][20] = '.';



	}

	if (timer > 50 && (GetOut == 2 || GetOut == 1) && level == 1)
	{
		x[0][0] = '-';
		x[0][1] = 'L';
		x[0][2] = 'e';
		x[0][3] = 'v';
		x[0][4] = 'e';
		x[0][5] = 'l';
		x[0][6] = ' ';
		x[0][7] = '1';
		x[0][8] = ' ';
		x[0][9] = 'd';
		x[0][10] = 'o';
		x[0][11] = 'n';
		x[0][12] = 'e';
		x[0][13] = '!';


	}

	if (timer2 >= 0 && timer2 <= 5 && level == 2)
	{
		x[0][0] = '-';
		x[0][1] = 'D';
		x[0][2] = 'i';
		x[0][3] = 'f';
		x[0][4] = 'f';
		x[0][5] = 'i';
		x[0][6] = 'c';
		x[0][7] = 'u';
		x[0][8] = 'l';
		x[0][9] = 't';
		x[0][10] = 'y';
		x[0][11] = ' ';
		x[0][12] = 'i';
		x[0][13] = 'n';
		x[0][14] = 'c';
		x[0][15] = 'r';
		x[0][16] = 'e';
		x[0][17] = 'a';
		x[0][18] = 's';
		x[0][19] = 'e';
		x[0][20] = 'd';
		x[0][21] = '!';
	}

	if (timer2 > 5 && level == 2 && timer2 <= 15)
	{
		x[0][0] = '-';
		x[0][1] = 'U';
		x[0][2] = 's';
		x[0][3] = 'e';
		x[0][4] = ' ';
		x[0][5] = 's';
		x[0][6] = ' ';
		x[0][7] = 't';
		x[0][8] = 'o';
		x[0][9] = ' ';
		x[0][10] = 'e';
		x[0][11] = 'a';
		x[0][12] = 's';
		x[0][13] = 'i';
		x[0][14] = 'l';
		x[0][15] = 'y';
		x[0][16] = ' ';
		x[0][17] = 'c';
		x[0][18] = 'o';
		x[0][19] = 'n';
		x[0][20] = 't';
		x[0][21] = 'r';
		x[0][22] = 'o';
		x[0][23] = 'l';
	}

	if (timer2 > 15 && level == 2 && cH < 120)
	{
		x[0][0] = '-';
		x[0][1] = 'P';
		x[0][2] = 'a';
		x[0][3] = 's';
		x[0][4] = 's';
		x[0][5] = ' ';
		x[0][6] = 't';
		x[0][7] = 'h';
		x[0][8] = 'e';
		x[0][9] = ' ';
		x[0][10] = 'c';
		x[0][11] = 'a';
		x[0][12] = 'r';
		x[0][13] = 's';
		x[0][14] = ' ';
		x[0][15] = 'g';
		x[0][16] = 'e';
		x[0][17] = 'n';
		x[0][18] = 't';
		x[0][19] = 'l';
		x[0][20] = 'y';
		x[0][21] = '!';
	}

	if (level == 2 && cH >= 120)
	{
		x[0][0] = '-';
		x[0][1] = 'L';
		x[0][2] = 'e';
		x[0][3] = 'v';
		x[0][4] = 'e';
		x[0][5] = 'l';
		x[0][6] = ' ';
		x[0][7] = '2';
		x[0][8] = ' ';
		x[0][9] = 'd';
		x[0][10] = 'o';
		x[0][11] = 'n';
		x[0][12] = 'e';
		x[0][13] = '!';

	}

	if (level == 2)
	{



		x[21][128] = '-';
		x[21][129] = '-';
		x[21][130] = '-';
		x[21][131] = '-';
		x[21][132] = '-';
		x[21][133] = '-';
		x[21][134] = '-';
		x[21][135] = 16;
	}

	if (timer3 >= 0 && timer3 <= 5 && level == 3)
	{
		x[0][0] = '-';
		x[0][1] = 'D';
		x[0][2] = 'i';
		x[0][3] = 'f';
		x[0][4] = 'f';
		x[0][5] = 'i';
		x[0][6] = 'c';
		x[0][7] = 'u';
		x[0][8] = 'l';
		x[0][9] = 't';
		x[0][10] = 'y';
		x[0][11] = ' ';
		x[0][12] = 'i';
		x[0][13] = 'n';
		x[0][14] = 'c';
		x[0][15] = 'r';
		x[0][16] = 'e';
		x[0][17] = 'a';
		x[0][18] = 's';
		x[0][19] = 'e';
		x[0][20] = 'd';
		x[0][21] = '!';
	}

	if (timer3 > 5 && timer3 <= 25 && level == 3)
	{
		x[0][0] = '-';
		x[0][1] = 'T';
		x[0][2] = 'a';
		x[0][3] = 'k';
		x[0][4] = 'e';
		x[0][5] = ' ';
		x[0][6] = 't';
		x[0][7] = 'h';
		x[0][8] = 'e';
		x[0][9] = ' ';
		x[0][10] = 's';
		x[0][11] = 'k';
		x[0][12] = 'a';
		x[0][13] = 't';
		x[0][14] = 'e';
		x[0][15] = ' ';
		x[0][16] = 'b';
		x[0][17] = 'o';
		x[0][18] = 'a';
		x[0][19] = 'r';
		x[0][20] = 'd';
		x[0][21] = ' ';
		x[0][22] = 't';
		x[0][23] = 'o';
		x[0][24] = ' ';
		x[0][25] = 'f';
		x[0][26] = 'a';
		x[0][27] = 's';
		x[0][28] = 't';
		x[0][29] = ' ';
		x[0][30] = 'e';
		x[0][31] = 's';
		x[0][32] = 'c';
		x[0][33] = 'a';
		x[0][34] = 'p';
		x[0][35] = 'e';
	}

	if (level == 3)
	{
		x[33][120] = '-';
		x[33][121] = '-';
		x[33][122] = '-';
		x[33][123] = '-';
		x[33][124] = '-';
		x[33][125] = '-';
		x[33][126] = '-';
		x[33][127] = '-';
		x[33][128] = '-';
		x[33][129] = '-';
		x[33][130] = '-';
		x[33][131] = '-';
		x[33][132] = '-';
		x[33][133] = '-';
		x[33][134] = '-';
		x[33][135] = 16;
	}
	if (level == 3 && cH >= 128 && timer3 > 25)
	{
		x[0][0] = '-';
		x[0][1] = 'L';
		x[0][2] = 'e';
		x[0][3] = 'v';
		x[0][4] = 'e';
		x[0][5] = 'l';
		x[0][6] = ' ';
		x[0][7] = '3';
		x[0][8] = ' ';
		x[0][9] = 'd';
		x[0][10] = 'o';
		x[0][11] = 'n';
		x[0][12] = 'e';
		x[0][13] = '!';

	}

	if (level == 4)
	{
		x[25][120] = '-';
		x[25][121] = '-';
		x[25][122] = '-';
		x[25][123] = '-';
		x[25][124] = '-';
		x[25][125] = '-';
		x[25][126] = '-';
		x[25][127] = '-';
		x[25][128] = '-';
		x[25][129] = '-';
		x[25][130] = '-';
		x[25][131] = '-';
		x[25][132] = '-';
		x[25][133] = '-';
		x[25][134] = '-';
		x[25][135] = 16;
	}
	if (level == 4 && timer4 >= 0 && timer4 < 25)
	{
		x[0][0] = '-';
		x[0][1] = 'T';
		x[0][2] = 'a';
		x[0][3] = 'k';
		x[0][4] = 'e';
		x[0][5] = ' ';
		x[0][6] = 't';
		x[0][7] = 'h';
		x[0][8] = 'e';
		x[0][9] = ' ';
		x[0][10] = 'r';
		x[0][11] = 'o';
		x[0][12] = 'p';
		x[0][13] = 'e';
		x[0][14] = ' ';
		x[0][15] = 'a';
		x[0][16] = 'n';
		x[0][17] = 'd';
		x[0][18] = ' ';
		x[0][19] = 'p';
		x[0][20] = 'a';
		x[0][21] = 's';
		x[0][22] = 's';
		x[0][23] = ' ';
		x[0][24] = 't';
		x[0][25] = 'h';
		x[0][26] = 'e';
		x[0][27] = ' ';
		x[0][28] = 't';
		x[0][29] = 'r';
		x[0][30] = 'a';
		x[0][31] = 'p';
	}

	if (level == 4 && cH >= 128 && timer4 > 25)
	{
		x[0][0] = '-';
		x[0][1] = 'L';
		x[0][2] = 'e';
		x[0][3] = 'v';
		x[0][4] = 'e';
		x[0][5] = 'l';
		x[0][6] = ' ';
		x[0][7] = '4';
		x[0][8] = ' ';
		x[0][9] = 'd';
		x[0][10] = 'o';
		x[0][11] = 'n';
		x[0][12] = 'e';
		x[0][13] = '!';

	}

	if (level == 5 && timer5 >= 0 && timer5 < 10)
	{
		x[0][0] = '-';
		x[0][1] = 'K';
		x[0][2] = 'i';
		x[0][3] = 'l';
		x[0][4] = 'l';
		x[0][5] = ' ';
		x[0][6] = 't';
		x[0][7] = 'h';
		x[0][8] = 'i';
		x[0][9] = 's';
		x[0][10] = ' ';
		x[0][11] = 'm';
		x[0][12] = 'o';
		x[0][13] = 'u';
		x[0][14] = 'n';
		x[0][15] = 't';
		x[0][16] = 'a';
		x[0][17] = 'i';
		x[0][18] = 'n';
		x[0][19] = ' ';
		x[0][20] = 't';
		x[0][21] = 'o';
		x[0][22] = ' ';
		x[0][23] = 'w';
		x[0][24] = 'i';
		x[0][25] = 'n';

		x[21][57] = 'P';
		x[21][58] = 'r';
		x[21][59] = 'e';
		x[21][60] = 's';
		x[21][61] = 's';
		x[21][62] = ' ';
		x[21][63] = ' ';
		x[21][64] = '+';
		x[21][65] = ' ';
		x[21][66] = ' ';
		x[21][67] = 't';
		x[21][68] = 'o';
		x[21][69] = ' ';
		x[21][70] = 's';
		x[21][71] = 'h';
		x[21][72] = 'o';
		x[21][73] = 'o';
		x[21][74] = 't';
	}

	if (level == 5 && timer5 >= 10 && timer5 < 85 && win == 0)
	{
		x[21][41] = 'L';
		x[21][42] = 'e';
		x[21][43] = 'g';
		x[21][44] = ' ';
		x[21][45] = 's';
		x[21][46] = 'h';
		x[21][47] = 'o';
		x[21][48] = 't';
		x[21][49] = ' ';
		x[21][50] = '(';
		x[21][51] = '0';
		x[21][52] = ')';
		x[21][53] = ' ';
		x[21][54] = '|';
		x[21][55] = ' ';
		x[21][56] = 'C';
		x[21][57] = 'h';
		x[21][58] = 'e';
		x[21][59] = 's';
		x[21][60] = 't';
		x[21][61] = ' ';
		x[21][62] = 's';
		x[21][63] = 'h';
		x[21][64] = 'o';
		x[21][65] = 't';
		x[21][66] = ' ';
		x[21][67] = '(';
		x[21][68] = '1';
		x[21][69] = ')';
		x[21][70] = ' ';
		x[21][71] = '|';
		x[21][72] = ' ';
		x[21][73] = 'H';
		x[21][74] = 'e';
		x[21][75] = 'a';
		x[21][76] = 'd';
		x[21][77] = 's';
		x[21][78] = 'h';
		x[21][79] = 'o';
		x[21][80] = 't';
		x[21][81] = ' ';
		x[21][82] = '(';
		x[21][83] = '2';
		x[21][84] = ')';

	}

	if (level == 5 && win == 1)
	{
		x[30][120] = '-';
		x[30][121] = '-';
		x[30][122] = '-';
		x[30][123] = '-';
		x[30][124] = '-';
		x[30][125] = '-';
		x[30][126] = '-';
		x[30][127] = '-';
		x[30][128] = '-';
		x[30][129] = '-';
		x[30][130] = '-';
		x[30][131] = '-';
		x[30][132] = '-';
		x[30][133] = '-';
		x[30][134] = '-';
		x[30][135] = 16;
	}

	if (level == 5 && win == 1)
	{
		x[21][55] = 'Y';
		x[21][56] = 'o';
		x[21][57] = 'u';
		x[21][58] = ' ';
		x[21][59] = 'K';
		x[21][60] = 'i';
		x[21][61] = 'l';
		x[21][62] = 'l';
		x[21][63] = 'e';
		x[21][64] = 'd';
		x[21][65] = ' ';
		x[21][66] = 't';
		x[21][67] = 'h';
		x[21][68] = 'e';
		x[21][69] = ' ';
		x[21][70] = 'b';
		x[21][71] = 'o';
		x[21][72] = 's';
		x[21][73] = 's';
		x[21][74] = '!';
	}

	if (level == 6 && TelephRide == 2)
	{
		x[37][cFC] = 'M';//cFC=56
		x[37][cFC + 1] = 'I';
		x[37][cFC + 2] = 'S';
		x[37][cFC + 3] = 'S';
		x[37][cFC + 4] = 'I';
		x[37][cFC + 5] = 'O';
		x[37][cFC + 6] = 'N';
		x[37][cFC + 7] = ' ';
		x[37][cFC + 8] = 'S';
		x[37][cFC + 9] = 'U';
		x[37][cFC + 10] = 'C';
		x[37][cFC + 11] = 'C';
		x[37][cFC + 12] = 'E';
		x[37][cFC + 13] = 'S';
		x[37][cFC + 14] = 'S';
		x[37][cFC + 15] = '!';
	}

	if (flagScore1 == 1 && timer2 >= 0 && timer2 < 7 && level == 2)
	{
		x[1][BSc] = '+';
		x[1][BSc + 1] = '1';
		x[1][BSc + 2] = '0';
		x[1][BSc + 3] = '0';
		x[1][BSc + 4] = '0';
	}

	if (flagScore2 == 1 && timer3 >= 0 && timer3 < 7 && level == 3)
	{
		x[1][BSc] = '+';
		x[1][BSc + 1] = '3';
		x[1][BSc + 2] = '0';
		x[1][BSc + 3] = '0';
		x[1][BSc + 4] = '0';
	}

	if (flagScore3 == 1 && timer4 >= 0 && timer4 < 7 && level == 4)
	{
		x[1][BSc] = '+';
		x[1][BSc + 1] = '6';
		x[1][BSc + 2] = '0';
		x[1][BSc + 3] = '0';
		x[1][BSc + 4] = '0';
	}

	if (flagScore4 == 1 && timer5 >= 0 && timer5 < 7 && level == 5)
	{
		x[1][BSc] = '+';
		x[1][BSc + 1] = '1';
		x[1][BSc + 2] = '0';
		x[1][BSc + 3] = '0';
		x[1][BSc + 4] = '0';
		x[1][BSc + 5] = '0';
	}

	if (win == 1 && timerBSC >= 0 && timerBSC < 7)
	{
		x[1][BSc] = '+';
		x[1][BSc + 1] = '2';
		x[1][BSc + 2] = '0';
		x[1][BSc + 3] = '0';
		x[1][BSc + 4] = '0';
		x[1][BSc + 5] = '0';
	}





	if (flagTime1 == 2 && timer2 >= 0 && timer2 < 7 && level == 2)
	{
		x[1][TSc] = '+';
		x[1][TSc + 1] = '2';
		x[1][TSc + 2] = 'm';
	}

	if (flagTime2 == 2 && timer3 >= 0 && timer3 < 7 && level == 3)
	{
		x[1][TSc] = '+';
		x[1][TSc + 1] = '2';
		x[1][TSc + 2] = 'm';
	}

	if (flagTime3 == 2 && timer4 >= 0 && timer4 < 7 && level == 4)
	{
		x[1][TSc] = '+';
		x[1][TSc + 1] = '2';
		x[1][TSc + 2] = 'm';
	}

	if (flagTime4 == 2 && timer5 >= 0 && timer5 < 7 && level == 5)
	{
		x[1][TSc] = '+';
		x[1][TSc + 1] = '2';
		x[1][TSc + 2] = 'm';
	}




	if (flagTime1 == 1 && timer2 >= 0 && timer2 < 7 && level == 2)
	{
		x[1][TSc] = '+';
		x[1][TSc + 1] = '1';
		x[1][TSc + 2] = 'm';

	}

	if (flagTime2 == 1 && timer3 >= 0 && timer3 < 7 && level == 3)
	{
		x[1][TSc] = '+';
		x[1][TSc + 1] = '1';
		x[1][TSc + 2] = 'm';
	}

	if (flagTime3 == 1 && timer4 >= 0 && timer4 < 7 && level == 4)
	{
		x[1][TSc] = '+';
		x[1][TSc + 1] = '1';
		x[1][TSc + 2] = 'm';
	}

	if (flagTime4 == 1 && timer5 >= 0 && timer5 < 7 && level == 5)
	{
		x[1][TSc] = '+';
		x[1][TSc + 1] = '1';
		x[1][TSc + 2] = 'm';
	}

}

void AutoBackward(char x[][138], int& rH, int& cH, int& lose1, int& pass1, int& pass2, int& cF, int& LeftLook, int CounterUntilStop, int& cO1, int& cC, int& rO1, int& DeathT, int& countRLHL1, int level)
{
	if (cH - 4 < -4)
	{
		DeathT = 0;
		lose1 = 1;
	}
	else
		if (CounterUntilStop >= 14 && level == 1)
		{
			if (rH == 36)
			{

				if (x[rH + 10][cH - 5] == ' ' || cH - 4 <= 0)
				{
					cH--;
					LeftLook = 1;
				}

			}

		}

	if (level == 2)
	{
		if (rH == 36)
		{


			cH--;
			LeftLook = 1;


		}

	}

	cF++;

}

void ToLand(char x[][138], int rH, int cH, int& flag1, int GetOut, int LeftLook, int level, int rEv, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4)
{
	if (level == 1 && rH < 0 && cH < 20)
	{
		rH = rEv + 1;
	}
	if (GetOut != 1 && x[rH + 11][cH - 4] == ' ' && x[rH + 11][cH - 3] == ' ' && x[rH + 11][cH - 2] == ' ' && x[rH + 11][cH - 1] == ' ' && x[rH + 11][cH] == ' ' && x[rH + 11][cH + 1] == ' ' && x[rH + 11][cH + 2] == ' ' && x[rH + 11][cH + 3] == ' ' && x[rH + 11][cH + 4] == ' ')
	{

		JumpReaction(x, rH, cH, flag1, GetOut, LeftLook, level, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
		//LandCheck(x, rH, cH, flag1, GetOut);
	}

	else
	{

		flag1 = 0;
	}


}

void JumpReaction(char x[][138], int& rH, int& cH, int& flag1, int GetOut, int& LeftLook, int level, int SkateIn, int& rSkate, int& cSkate, int RopeIn, int cR, int tap4)
{
	if (flag1 == 1 && level != 5)
	{
		if (LeftLook == 1)
		{

			x[rH + 2][cH] = ' ';
			x[rH + 2][cH + 2] = ' ';

			x[rH + 2][cH - 1] = 248;
			x[rH + 2][cH + 1] = 248;
		}
		else
		{
			x[rH + 2][cH] = 248;
			x[rH + 2][cH + 2] = 248;

			x[rH + 2][cH - 1] = ' ';
			x[rH + 2][cH + 1] = ' ';

		}

		x[rH + 3][cH + 1] = '-';

		x[rH + 6][cH + 4] = '\\';	//RIGHT HAND
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 6] = '_';
		x[rH + 7][cH + 6] = ' ';
		x[rH + 7][cH + 5] = ' ';
		x[rH + 7][cH + 7] = ' ';
		x[rH + 7][cH + 8] = ' ';
		x[rH + 6][cH + 7] = '/';
		x[rH + 5][cH + 8] = '/';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '\\';
		x[rH + 5][cH + 6] = '/';
		x[rH + 5][cH + 3] = ' ';
		x[rH + 5][cH + 4] = ' ';
		x[rH + 4][cH + 4] = '_';

		x[rH + 8][cH - 2] = '/';			//LEFT LEG 1
		x[rH + 9][cH - 3] = '/';
		x[rH + 10][cH - 4] = '/';

		x[rH + 8][cH] = '/'; 			//LEFT LEG 2
		x[rH + 9][cH - 1] = '/';
		x[rH + 10][cH - 2] = '/';

		x[rH + 8][cH + 1] = '\\';			//RIGHT LEG 3
		x[rH + 9][cH + 2] = '\\';
		x[rH + 10][cH + 2] = '|';

		x[rH + 8][cH + 3] = '\\';			//RIGHT LEG 4
		x[rH + 9][cH + 4] = '\\';
		x[rH + 10][cH + 4] = '|';

		//fix
		x[rH + 10][cH] = ' ';
		x[rH + 10][cH + 1] = ' ';
		x[rH + 10][cH - 1] = ' ';
		x[rH + 10][cH - 3] = '_';
		x[rH + 10][cH + 3] = '_';
		x[rH + 9][cH + 1] = ' ';



	}

	if (flag1 == 1 && level == 5)
	{
		if (LeftLook == 1)
		{

			x[rH + 2][cH] = ' ';
			x[rH + 2][cH + 2] = ' ';

			x[rH + 2][cH - 1] = 248;
			x[rH + 2][cH + 1] = 248;
		}
		else
		{
			x[rH + 2][cH] = 248;
			x[rH + 2][cH + 2] = 248;

			x[rH + 2][cH - 1] = ' ';
			x[rH + 2][cH + 1] = ' ';

		}
	}
	if (rH < 36)
	{
		//sleep_for(nanoseconds(9900000));
		//dsleep_until(system_clock::now() + seconds(1));
		//cH += 1;
		LandCheck(x, rH, cH, flag1, GetOut, level, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);



	}



}

void LeftHandMoveH1(char x[][138], int rH, int cH, int countRLHL1, int Reload, int& ReloadAction, int level, int& rB, int cB)
{

	if (countRLHL1 == 0)
	{
		x[rH + 5][cH - 3] = '/';			//LEFT HAND 
		x[rH + 6][cH - 4] = '\\';
		x[rH + 5][cH - 4] = '_';
		x[rH + 5][cH - 2] = '_';
		x[rH + 6][cH - 3] = '_';
		x[rH + 6][cH - 1] = '_';
		x[rH + 6][cH - 2] = '_';
		x[rH + 6][cH] = '|';
		x[rH + 5][cH - 1] = '_';

		if (Reload == 1 && ReloadAction == 2 && level == 5)
		{
			x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
			x[rH + 6][cH - 2] = ' ';
			x[rH + 5][cH - 7] = ' ';
			x[rH + 6][cH - 5] = ' ';
			x[rH + 7][cH - 6] = ' ';
			x[rH + 7][cH - 5] = ' ';
			//x[rH + 6][cH - 3] = '/';
			x[rH + 7][cH - 4] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 5][cH - 4] = ' ';
			x[rH + 4][cH - 3] = ' ';

			x[rH + 6][cH] = ' ';
			x[rH + 6][cH - 1] = ' ';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 5][cH - 1] = ' ';
			x[rH + 6][cH - 4] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 5][cH - 3] = ' ';

			x[rH + 8][cH - 6] = ' ';
			x[rH + 8][cH - 5] = ' ';
			x[rH + 8][cH - 4] = ' ';
			x[rH + 9][cH - 6] = ' ';
			x[rH + 9][cH - 4] = ' ';
			x[rH + 9][cH - 5] = ' ';


			x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
			x[rH + 6][cH - 4] = ' ';
			x[rH + 5][cH - 4] = ' ';
			x[rH + 5][cH - 2] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 6][cH - 1] = ' ';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 6][cH] = ' ';
			x[rH + 5][cH - 1] = ' ';


			x[rH + 5][cH] = '_';			//LEFT HAND 
			x[rH + 6][cH] = '_';
			x[rH + 6][cH - 1] = '_';
			x[rH + 6][cH + 1] = '_';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 7][cH + 1] = '_';
			x[rH + 6][cH + 2] = '|';
			x[rH + 5][cH - 1] = '_';
			x[rH + 5][cH - 2] = '\\';
			x[rH + 5][cH - 3] = ' ';
			x[rH + 5][cH + 1] = '_';

			x[rH + 5][cH + 2] = ' ';
			x[rH + 5][cH + 3] = '_';
			x[rH + 5][cH + 4] = '_';
			x[rH + 5][cH + 5] = '_';
			x[rH + 6][cH + 6] = '|';
			x[rH + 6][cH + 5] = '2';
			x[rH + 6][cH + 4] = '_';
			x[rH + 6][cH + 3] = '_';



		}

		if (Reload == 1 && ReloadAction == 1 && level == 5)
		{
			x[rH + 5][cH - 3] = '/';			//LEFT HAND 
			x[rH + 6][cH - 2] = '|';
			x[rH + 5][cH - 7] = ' ';
			x[rH + 6][cH - 5] = '/';
			x[rH + 7][cH - 6] = '/';
			x[rH + 7][cH - 5] = '_';
			//x[rH + 6][cH - 3] = '/';
			x[rH + 7][cH - 4] = '/';
			x[rH + 6][cH - 3] = '/';
			x[rH + 5][cH - 4] = '/';
			x[rH + 4][cH - 3] = '_';

			x[rH + 6][cH] = ' ';
			x[rH + 6][cH - 1] = ' ';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 5][cH - 1] = ' ';
			x[rH + 6][cH - 4] = ' ';
			x[rH + 6][cH - 3] = '/';
			x[rH + 5][cH - 3] = ' ';

			x[rH + 8][cH - 6] = '|';
			x[rH + 8][cH - 5] = '2';
			x[rH + 8][cH - 4] = '|';
			x[rH + 9][cH - 6] = '|';
			x[rH + 9][cH - 4] = '|';
			x[rH + 9][cH - 5] = '_';




			x[rB + 1][cB] = '_';
			x[rB + 2][cB] = '0';
			x[rB + 2][cB - 1] = '|';
			x[rB + 2][cB + 1] = '|';
			x[rB + 3][cB - 1] = '|';
			x[rB + 3][cB + 1] = '|';
			x[rB + 3][cB] = '_';


		}
	}
	if (countRLHL1 % 2 != 0)
	{

		x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
		x[rH + 6][cH - 4] = ' ';
		x[rH + 5][cH - 4] = ' ';
		x[rH + 5][cH - 2] = ' ';
		x[rH + 6][cH - 3] = ' ';
		x[rH + 6][cH - 1] = ' ';
		x[rH + 6][cH - 2] = ' ';
		x[rH + 6][cH] = ' ';
		x[rH + 5][cH - 1] = ' ';


		x[rH + 5][cH] = '_';			//LEFT HAND 
		x[rH + 6][cH] = '_';
		x[rH + 6][cH - 1] = '_';
		x[rH + 6][cH + 1] = '_';
		x[rH + 6][cH - 2] = '_';
		x[rH + 6][cH - 3] = '\\';
		//x[rH + 7][cH + 1] = '_';
		x[rH + 6][cH + 2] = '|';
		x[rH + 5][cH - 1] = '_';
		x[rH + 5][cH - 2] = '\\';
		x[rH + 5][cH - 3] = ' ';
		x[rH + 5][cH + 1] = '_';

		if (Reload == 1 && ReloadAction == 2 && level == 5)
		{
			x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
			x[rH + 6][cH - 2] = ' ';
			x[rH + 5][cH - 7] = ' ';
			x[rH + 6][cH - 5] = ' ';
			x[rH + 7][cH - 6] = ' ';
			x[rH + 7][cH - 5] = ' ';
			//x[rH + 6][cH - 3] = '/';
			x[rH + 7][cH - 4] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 5][cH - 4] = ' ';
			x[rH + 4][cH - 3] = ' ';

			x[rH + 6][cH] = ' ';
			x[rH + 6][cH - 1] = ' ';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 5][cH - 1] = ' ';
			x[rH + 6][cH - 4] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 5][cH - 3] = ' ';

			x[rH + 8][cH - 6] = ' ';
			x[rH + 8][cH - 5] = ' ';
			x[rH + 8][cH - 4] = ' ';
			x[rH + 9][cH - 6] = ' ';
			x[rH + 9][cH - 4] = ' ';
			x[rH + 9][cH - 5] = ' ';


			x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
			x[rH + 6][cH - 4] = ' ';
			x[rH + 5][cH - 4] = ' ';
			x[rH + 5][cH - 2] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 6][cH - 1] = ' ';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 6][cH] = ' ';
			x[rH + 5][cH - 1] = ' ';


			x[rH + 5][cH] = '_';			//LEFT HAND 
			x[rH + 6][cH] = '_';
			x[rH + 6][cH - 1] = '_';
			x[rH + 6][cH + 1] = '_';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 7][cH + 1] = '_';
			x[rH + 6][cH + 2] = '|';
			x[rH + 5][cH - 1] = '_';
			x[rH + 5][cH - 2] = '\\';
			x[rH + 5][cH - 3] = ' ';
			x[rH + 5][cH + 1] = '_';

			x[rH + 5][cH + 2] = ' ';
			x[rH + 5][cH + 3] = '_';
			x[rH + 5][cH + 4] = '_';
			x[rH + 5][cH + 5] = '_';
			x[rH + 6][cH + 6] = '|';
			x[rH + 6][cH + 5] = '2';
			x[rH + 6][cH + 4] = '_';
			x[rH + 6][cH + 3] = '_';

		}

		if (Reload == 1 && ReloadAction == 1 && level == 5)
		{
			x[rH + 5][cH - 3] = '/';			//LEFT HAND 
			x[rH + 6][cH - 2] = '|';
			x[rH + 5][cH - 7] = ' ';
			x[rH + 6][cH - 5] = '/';
			x[rH + 7][cH - 6] = '/';
			x[rH + 7][cH - 5] = '_';
			//x[rH + 6][cH - 3] = '/';
			x[rH + 7][cH - 4] = '/';
			x[rH + 6][cH - 3] = '/';
			x[rH + 5][cH - 4] = '/';
			x[rH + 4][cH - 3] = '_';

			x[rH + 6][cH] = ' ';
			x[rH + 6][cH - 1] = ' ';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 5][cH - 1] = ' ';
			x[rH + 6][cH - 4] = ' ';
			x[rH + 6][cH - 3] = '/';
			x[rH + 5][cH - 3] = ' ';

			x[rH + 8][cH - 6] = '|';
			x[rH + 8][cH - 5] = '2';
			x[rH + 8][cH - 4] = '|';
			x[rH + 9][cH - 6] = '|';
			x[rH + 9][cH - 4] = '|';
			x[rH + 9][cH - 5] = '_';




			x[rB + 1][cB] = '_';
			x[rB + 2][cB] = '0';
			x[rB + 2][cB - 1] = '|';
			x[rB + 2][cB + 1] = '|';
			x[rB + 3][cB - 1] = '|';
			x[rB + 3][cB + 1] = '|';
			x[rB + 3][cB] = '_';


		}


	}
	else
	{
		x[rH + 5][cH - 3] = '/';			//LEFT HAND 
		x[rH + 6][cH - 4] = '\\';
		x[rH + 5][cH - 4] = '_';
		x[rH + 5][cH - 2] = '_';
		x[rH + 6][cH - 3] = '_';
		x[rH + 6][cH - 1] = '_';
		x[rH + 6][cH - 2] = '_';
		x[rH + 6][cH] = '|';
		x[rH + 5][cH - 1] = '_';


		if (Reload == 1 && ReloadAction == 2 && level == 5)
		{
			x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
			x[rH + 6][cH - 2] = ' ';
			x[rH + 5][cH - 7] = ' ';
			x[rH + 6][cH - 5] = ' ';
			x[rH + 7][cH - 6] = ' ';
			x[rH + 7][cH - 5] = ' ';
			//x[rH + 6][cH - 3] = '/';
			x[rH + 7][cH - 4] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 5][cH - 4] = ' ';
			x[rH + 4][cH - 3] = ' ';

			x[rH + 6][cH] = ' ';
			x[rH + 6][cH - 1] = ' ';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 5][cH - 1] = ' ';
			x[rH + 6][cH - 4] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 5][cH - 3] = ' ';

			x[rH + 8][cH - 6] = ' ';
			x[rH + 8][cH - 5] = ' ';
			x[rH + 8][cH - 4] = ' ';
			x[rH + 9][cH - 6] = ' ';
			x[rH + 9][cH - 4] = ' ';
			x[rH + 9][cH - 5] = ' ';


			x[rH + 5][cH - 3] = ' ';			//LEFT HAND 
			x[rH + 6][cH - 4] = ' ';
			x[rH + 5][cH - 4] = ' ';
			x[rH + 5][cH - 2] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 6][cH - 1] = ' ';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 6][cH] = ' ';
			x[rH + 5][cH - 1] = ' ';


			x[rH + 5][cH] = '_';			//LEFT HAND 
			x[rH + 6][cH] = '_';
			x[rH + 6][cH - 1] = '_';
			x[rH + 6][cH + 1] = '_';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 6][cH - 3] = ' ';
			x[rH + 7][cH + 1] = '_';
			x[rH + 6][cH + 2] = '|';
			x[rH + 5][cH - 1] = '_';
			x[rH + 5][cH - 2] = '\\';
			x[rH + 5][cH - 3] = ' ';
			x[rH + 5][cH + 1] = '_';

			x[rH + 5][cH + 2] = ' ';
			x[rH + 5][cH + 3] = '_';
			x[rH + 5][cH + 4] = '_';
			x[rH + 5][cH + 5] = '_';
			x[rH + 6][cH + 6] = '|';
			x[rH + 6][cH + 5] = '2';
			x[rH + 6][cH + 4] = '_';
			x[rH + 6][cH + 3] = '_';


		}

		if (Reload == 1 && ReloadAction == 1 && level == 5)
		{
			x[rH + 5][cH - 3] = '/';			//LEFT HAND 
			x[rH + 6][cH - 2] = '|';
			x[rH + 5][cH - 7] = ' ';
			x[rH + 6][cH - 5] = '/';
			x[rH + 7][cH - 6] = '/';
			x[rH + 7][cH - 5] = '_';
			//x[rH + 6][cH - 3] = '/';
			x[rH + 7][cH - 4] = '/';
			x[rH + 6][cH - 3] = '/';
			x[rH + 5][cH - 4] = '/';
			x[rH + 5][cH - 2] = ' ';
			x[rH + 6][cH - 2] = '|';
			x[rH + 4][cH - 3] = '_';

			x[rH + 6][cH] = ' ';
			x[rH + 6][cH - 1] = ' ';
			x[rH + 6][cH - 2] = ' ';
			x[rH + 5][cH - 1] = ' ';
			x[rH + 6][cH - 4] = ' ';
			x[rH + 6][cH - 3] = '/';
			x[rH + 5][cH - 3] = ' ';

			x[rH + 8][cH - 6] = '|';
			x[rH + 8][cH - 5] = '2';
			x[rH + 8][cH - 4] = '|';
			x[rH + 9][cH - 6] = '|';
			x[rH + 9][cH - 4] = '|';
			x[rH + 9][cH - 5] = '_';




			x[rB + 1][cB] = '_';
			x[rB + 2][cB] = '0';
			x[rB + 2][cB - 1] = '|';
			x[rB + 2][cB + 1] = '|';
			x[rB + 3][cB - 1] = '|';
			x[rB + 3][cB + 1] = '|';

			x[rB + 3][cB] = '_';


		}


	}

}

void RightHandMoveH1(char x[][138], int rH, int cH, int countRLHL1)
{

	if (countRLHL1 == 0)
	{


		x[rH + 6][cH + 4] = '\\';	//RIGHT HAND
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 6] = '_';
		x[rH + 6][cH + 7] = '/';
		x[rH + 5][cH + 8] = '/';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '\\';
		x[rH + 5][cH + 6] = '/';
		x[rH + 4][cH + 4] = '_';

	}
	if (countRLHL1 % 2 != 0)
	{
		x[rH + 6][cH + 4] = '_';	//RIGHT HAND
		x[rH + 6][cH + 3] = ' ';
		x[rH + 5][cH + 3] = '/';
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 7] = ' ';
		x[rH + 6][cH + 6] = '|';
		x[rH + 6][cH + 8] = ' ';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '_';
		x[rH + 5][cH + 6] = ' ';
		x[rH + 5][cH + 7] = ' ';
		x[rH + 4][cH + 4] = ' ';
		x[rH + 5][cH + 4] = '_';
		x[rH + 4][cH + 7] = ' ';

	}
	else
	{
		x[rH + 6][cH + 4] = '\\';	//RIGHT HAND
		x[rH + 6][cH + 5] = '_';
		x[rH + 6][cH + 6] = '_';
		x[rH + 6][cH + 7] = '/';
		x[rH + 5][cH + 8] = '/';
		x[rH + 4][cH + 7] = '_';
		x[rH + 5][cH + 5] = '\\';
		x[rH + 5][cH + 6] = '/';
		x[rH + 4][cH + 4] = '_';


	}
}

void RightLegMoveH1(char x[][138], int& rH, int& cH, int countRLH1)
{
	if (countRLH1 == 0)
	{

		x[rH + 8][cH + 1] = '\\';			//RIGHT LEG 3
		x[rH + 9][cH + 2] = '\\';
		x[rH + 10][cH + 2] = '|';

		x[rH + 8][cH + 3] = '\\';			//RIGHT LEG 4
		x[rH + 9][cH + 4] = '\\';
		x[rH + 10][cH + 4] = '|';
		x[rH + 10][cH + 3] = '_';
	}

	if (countRLH1 % 2 != 0)
	{
		x[rH + 8][cH + 1] = '/';			//RIGHT LEG 3
		x[rH + 9][cH + 2] = '/';
		//x[rH + 10][cH + 2] = ' ';//////

		x[rH + 8][cH + 3] = '/';			//RIGHT LEG 4
		x[rH + 9][cH + 4] = ' ';
		x[rH + 10][cH + 4] = ' ';
		x[rH + 10][cH + 3] = ' ';
		x[rH + 10][cH - 1] = '_';
		x[rH + 10][cH - 2] = '|';
	}

	else
	{
		x[rH + 8][cH + 1] = '\\';			//RIGHT LEG 3
		x[rH + 9][cH + 2] = '\\';
		x[rH + 10][cH + 2] = '|';

		x[rH + 8][cH + 3] = '\\';			//RIGHT LEG 4
		x[rH + 9][cH + 4] = '\\';
		x[rH + 10][cH + 4] = '|';
		x[rH + 10][cH + 3] = '_';
	}
}

void LeftLegMoveH1(char x[][138], int& rH, int& cH, int countRLHL1)
{
	if (countRLHL1 == 0)
	{
		x[rH + 8][cH - 2] = '/';			//LEFT LEG 1
		x[rH + 9][cH - 3] = '/';
		x[rH + 10][cH - 4] = '/';

		x[rH + 8][cH] = '/'; 			//LEFT LEG 2
		x[rH + 9][cH - 1] = '/';
		x[rH + 10][cH - 2] = '/';
		x[rH + 10][cH - 3] = '_';
	}

	if (countRLHL1 % 2 != 0)
	{
		x[rH + 8][cH - 2] = '\\';			//LEFT LEG 1
		x[rH + 9][cH - 1] = '\\';
		x[rH + 10][cH] = '\\';

		x[rH + 8][cH] = '\\'; 			//LEFT LEG 2
		x[rH + 9][cH + 1] = '\\';
		x[rH + 10][cH + 1] = '_';		//FOOT
		x[rH + 10][cH + 2] = '\\';

		//x[rH + 10][cH - 3] = ' ';


	}
	else
	{
		x[rH + 8][cH - 2] = '/';			//LEFT LEG 1
		x[rH + 9][cH - 3] = '/';
		x[rH + 10][cH - 4] = '/';

		x[rH + 8][cH] = '/'; 			//LEFT LEG 2
		x[rH + 9][cH - 1] = '/';
		x[rH + 10][cH - 2] = '/';
		x[rH + 10][cH - 3] = '_';
	}
}

void SElev(char x[][138], int rEv, int cEv, int rH, int cH, int GetOut, int openG, int rEvR)
{
	/*if (rEv > 33 || rEv < 0 || rH < 0 || cH > 138 || rH > 100)
	{

		rH = rEv + 1;
		cH = 114;

	}*/




	x[rEv][cEv] = '_';
	x[rEv][cEv + 1] = '_';
	x[rEv][cEv + 2] = '_';
	x[rEv][cEv + 3] = '_';
	x[rEv][cEv + 4] = '_';
	x[rEv][cEv + 5] = '_';
	x[rEv][cEv + 6] = '_';
	x[rEv][cEv + 7] = '_';
	x[rEv][cEv + 8] = '_';
	x[rEv][cEv + 9] = '_';
	x[rEv][cEv + 10] = '_';
	x[rEv][cEv + 11] = '_';
	x[rEv][cEv + 12] = '_';
	x[rEv][cEv + 13] = '_';
	x[rEv][cEv + 14] = '_';
	x[rEv][cEv + 15] = '_';

	x[rEv + 12][cEv] = '_';
	x[rEv + 12][cEv + 1] = '_';
	x[rEv + 12][cEv + 2] = '_';
	x[rEv + 12][cEv + 3] = '_';
	x[rEv + 12][cEv + 4] = '_';
	x[rEv + 12][cEv + 5] = '_';
	x[rEv + 12][cEv + 6] = '_';
	x[rEv + 12][cEv + 7] = '_';
	x[rEv + 12][cEv + 8] = '_';
	x[rEv + 12][cEv + 9] = '_';
	x[rEv + 12][cEv + 10] = '_';
	x[rEv + 12][cEv + 11] = '_';
	x[rEv + 12][cEv + 12] = '_';
	x[rEv + 12][cEv + 13] = '_';
	x[rEv + 12][cEv + 14] = '_';
	x[rEv + 12][cEv + 15] = '_';



	for (int i = 0; (rEvR - 1) >= -1; i++, rEvR--)
	{
		x[rEvR][117] = 179;

	}

	if (GetOut != 1)
	{

		x[rEv - 1][118] = 'E';
		x[rEv - 1][119] = 'l';
		x[rEv - 1][120] = 'e';
		x[rEv - 1][121] = 'v';
		x[rEv - 1][122] = 'a';
		x[rEv - 1][123] = 't';
		x[rEv - 1][124] = 'o';
		x[rEv - 1][125] = 'r';

	}



	if (GetOut != 2 && openG == 0)
	{

		x[rEv + 1][125] = '|';
		x[rEv + 2][125] = '|';
		x[rEv + 3][125] = '|';
		x[rEv + 4][125] = '|';
		x[rEv + 5][125] = '|';
		x[rEv + 6][125] = '|';
		x[rEv + 7][125] = '|';
		x[rEv + 8][125] = '|';
		x[rEv + 9][125] = '|';
		x[rEv + 10][125] = '|';
		x[rEv + 11][125] = '|';
		x[rEv + 12][125] = '|';

	}

	if (GetOut != 3)
	{

		x[rEv + 1][108] = '|';
		x[rEv + 2][108] = '|';
		x[rEv + 3][108] = '|';
		x[rEv + 4][108] = '|';
		x[rEv + 5][108] = '|';
		x[rEv + 6][108] = '|';
		x[rEv + 7][108] = '|';
		x[rEv + 8][108] = '|';
		x[rEv + 9][108] = '|';
		x[rEv + 10][108] = '|';
		x[rEv + 11][108] = '|';
		x[rEv + 12][108] = '|';

	}

	for (int r = rEv + 1, i = 0; i < 11; r++, i++)
	{
		for (int c = cEv, j = 0; j < 16; c++, j++)
		{
			x[r][c] = ' ';
		}
	}

}

void DElev(char x[][138], int& rEv, int cEv, int& rH, int cH, int& GetOut, int& countRLHL1, int& openG, int &rEvR)
{
	if (cH >= 115 && rEv > 11)
	{
		rH = rEv + 1;
		rEv -= 2;
		GetOut = 1;
		countRLHL1 = 2;
		rEvR -= 2;
	}

	else if (rEv <= 11)
	{
		//rH = 12;
		GetOut = 2;
		openG = 1;
		rH = rEv + 1;
		//system("pause");
		x[9][120] = '-';
		x[9][121] = '-';
		x[9][122] = '-';
		x[9][123] = '-';
		x[9][124] = '-';
		x[9][125] = '-';
		x[9][126] = '-';
		x[9][127] = '-';
		x[9][128] = '-';
		x[9][129] = 16;
	}
}

void Floor_Elev(char x[][138], int& r, int& c, int& FloorNumber, int GetOut, int& FloorNumberCount)
{
	x[r][c] = 'F';
	x[r][c + 1] = 'l';
	x[r][c + 2] = 'o';
	x[r][c + 3] = 'o';
	x[r][c + 4] = 'r';
	x[r][c + 5] = ':';
	x[r][c + 6] = 'G';
	char FN[2];
	_itoa_s(FloorNumber, FN, 10);

	if (GetOut == 1)
	{
		if (FloorNumberCount % 3 == 0)
		{
			FloorNumber++;
		}
		x[r][c + 6] = FN[0];
		r -= 2;
	}
	if (GetOut == 2)
	{
		x[r][c + 6] = FN[0];
	}
	FloorNumberCount++;
}

void LevelCounter(char x[][138], int Stage)
{
	if (Stage == 1)
	{
		x[0][43] = 'L';
		x[0][44] = 'e';
		x[0][45] = 'v';
		x[0][46] = 'e';
		x[0][47] = 'l';
		x[0][48] = ' ';
		x[0][49] = '1';
		x[0][50] = ' ';
		x[0][51] = '|';
		x[0][52] = ' ';
	}

	if (Stage == 2)
	{
		x[0][43] = 'L';
		x[0][44] = 'e';
		x[0][45] = 'v';
		x[0][46] = 'e';
		x[0][47] = 'l';
		x[0][48] = ' ';
		x[0][49] = '2';
		x[0][50] = ' ';
		x[0][51] = '|';
		x[0][52] = ' ';
	}

	if (Stage == 3)
	{
		x[0][43] = 'L';
		x[0][44] = 'e';
		x[0][45] = 'v';
		x[0][46] = 'e';
		x[0][47] = 'l';
		x[0][48] = ' ';
		x[0][49] = '3';
		x[0][50] = ' ';
		x[0][51] = '|';
		x[0][52] = ' ';
	}

	if (Stage == 4)
	{
		x[0][43] = 'L';
		x[0][44] = 'e';
		x[0][45] = 'v';
		x[0][46] = 'e';
		x[0][47] = 'l';
		x[0][48] = ' ';
		x[0][49] = '4';
		x[0][50] = ' ';
		x[0][51] = '|';
		x[0][52] = ' ';
	}

	if (Stage == 5)
	{
		x[0][43] = 'L';
		x[0][44] = 'e';
		x[0][45] = 'v';
		x[0][46] = 'e';
		x[0][47] = 'l';
		x[0][48] = ' ';
		x[0][49] = '5';
		x[0][50] = ' ';
		x[0][51] = '|';
		x[0][52] = ' ';
	}
	if (Stage == 6)
	{
		x[0][43] = 'W';
		x[0][44] = 'i';
		x[0][45] = 'n';
		x[0][46] = 'n';
		x[0][47] = 'e';
		x[0][48] = 'r';
		x[0][49] = '!';
		x[0][50] = ' ';
		x[0][51] = '|';
		x[0][52] = ' ';
	}
}

void TimeCounter(char x[][138], int& mins, int& secs, int CounterUntilStop, int& lose1, int& DeathT, int level, int shoot1)
{

	x[0][53] = 'T';
	x[0][54] = 'i';
	x[0][55] = 'm';
	x[0][56] = 'e';
	x[0][57] = ' ';
	x[0][58] = 'L';
	x[0][59] = 'e';
	x[0][60] = 'f';
	x[0][61] = 't';
	x[0][62] = ' ';
	//x[0][63] = '5';
	//x[0][64] = 'm';
	x[0][65] = ' ';
	//x[0][66] = '9';
	//x[0][67] = '9';
	//x[0][68] = 's';
	x[0][69] = ' ';
	x[0][70] = '|';
	x[0][71] = ' ';


	char TimeS[5];
	_itoa_s(secs, TimeS, 10);
	x[0][66] = TimeS[0];
	x[0][67] = TimeS[1];
	x[0][68] = 's';

	if (secs < 10)
	{
		x[0][66] = TimeS[0];
		x[0][67] = 's';
		x[0][68] = ' ';
	}

	if (CounterUntilStop >= 14 && level != 6)
	{
		secs--;

	}

	char TimeM[5];
	_itoa_s(mins, TimeM, 10);
	x[0][63] = TimeM[0];
	x[0][64] = 'm';

	if (secs == 0 && level != 6)
	{
		mins--;
		if (mins < 0 && secs == 0)
		{
			lose1 = 1;
			DeathT = 1;
		}
		secs = 60;

	}

	if (mins == 1 && level != 6)
	{
		SetConsoleTextAttribute(hConsole, 8);
	}
	else if (mins == 0 && level != 6)
	{
		SetConsoleTextAttribute(hConsole, 4);
	}
	if (mins > 1)
	{
		if (level == 1 && shoot1 < 4)
		{
			SetConsoleTextAttribute(hConsole, 2);
		}
		if (level == 2 && shoot1 < 4)
		{
			SetConsoleTextAttribute(hConsole, 3);
		}
		if (level == 3 && shoot1 < 4)
		{
			SetConsoleTextAttribute(hConsole, 6);
		}
		if (level == 4 && shoot1 < 4)
		{
			SetConsoleTextAttribute(hConsole, 5);
		}
		if (level == 5 && shoot1 < 4)
		{
			SetConsoleTextAttribute(hConsole, 12);
		}
		if (level == 6 && shoot1 < 4)
		{
			SetConsoleTextAttribute(hConsole, 11);
		}
	}


}

void HealthBar(char x[][138], int rH, int cH, int& shoot1, int& lose1, int& DeathT, int level, int& countHearts, int& countHearts2, int mins)
{

	if (level != 5)
	{
		if (shoot1 == 0)
		{
			char HB1[2];
			_itoa_s(6, HB1, 10);
			x[0][72] = 'H';
			x[0][73] = 'e';
			x[0][74] = 'a';
			x[0][75] = 'l';
			x[0][76] = 't';
			x[0][77] = 'h';
			x[0][78] = ' ';
			x[0][79] = 'B';
			x[0][80] = 'a';
			x[0][81] = 'r';
			x[0][82] = ' ';
			x[0][83] = 219;
			x[0][84] = ' ';
			x[0][85] = 219;
			x[0][86] = ' ';
			x[0][87] = 219;
			x[0][88] = ' ';
			x[0][89] = 219;
			x[0][90] = ' ';
			x[0][91] = 219;
			x[0][92] = ' ';
			x[0][93] = 219;
			x[0][94] = ' ';
			x[0][95] = HB1[0];
			if (level == 1 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 2);
			}
			if (level == 2 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 3);
			}
			if (level == 3 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 6);
			}
			if (level == 4 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 5);
			}

			if (level == 6 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 11);
			}
		}
		if (shoot1 == 1)
		{
			char HB2[2];
			_itoa_s(5, HB2, 10);
			x[0][72] = 'H';
			x[0][73] = 'e';
			x[0][74] = 'a';
			x[0][75] = 'l';
			x[0][76] = 't';
			x[0][77] = 'h';
			x[0][78] = ' ';
			x[0][79] = 'B';
			x[0][80] = 'a';
			x[0][81] = 'r';
			x[0][82] = ' ';
			x[0][83] = 219;
			x[0][84] = ' ';
			x[0][85] = 219;
			x[0][86] = ' ';
			x[0][87] = 219;
			x[0][88] = ' ';
			x[0][89] = 219;
			x[0][90] = ' ';
			x[0][91] = 219;
			x[0][92] = ' ';
			x[0][93] = HB2[0];
			if (level == 1 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 2);
			}
			if (level == 2 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 3);
			}
			if (level == 3 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 6);
			}
			if (level == 4 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 5);
			}

			if (level == 6 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 11);
			}

		}
		if (shoot1 == 2)
		{
			char HB3[2];
			_itoa_s(4, HB3, 10);
			x[0][72] = 'H';
			x[0][73] = 'e';
			x[0][74] = 'a';
			x[0][75] = 'l';
			x[0][76] = 't';
			x[0][77] = 'h';
			x[0][78] = ' ';
			x[0][79] = 'B';
			x[0][80] = 'a';
			x[0][81] = 'r';
			x[0][82] = ' ';
			x[0][83] = 219;
			x[0][84] = ' ';
			x[0][85] = 219;
			x[0][86] = ' ';
			x[0][87] = 219;
			x[0][88] = ' ';
			x[0][89] = 219;
			x[0][90] = ' ';
			x[0][91] = HB3[0];
			if (level == 1 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 2);
			}
			if (level == 2 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 3);
			}
			if (level == 3 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 6);
			}
			if (level == 4 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 5);
			}

			if (level == 6 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 11);
			}

		}
		if (shoot1 == 3)
		{
			char HB4[2];
			_itoa_s(3, HB4, 10);
			x[0][72] = 'H';
			x[0][73] = 'e';
			x[0][74] = 'a';
			x[0][75] = 'l';
			x[0][76] = 't';
			x[0][77] = 'h';
			x[0][78] = ' ';
			x[0][79] = 'B';
			x[0][80] = 'a';
			x[0][81] = 'r';
			x[0][82] = ' ';
			x[0][83] = 219;
			x[0][84] = ' ';
			x[0][85] = 219;
			x[0][86] = ' ';
			x[0][87] = 219;
			x[0][88] = ' ';
			x[0][89] = HB4[0];
			if (level == 1 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 2);
			}
			if (level == 2 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 3);
			}
			if (level == 3 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 6);
			}
			if (level == 4 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 5);
			}

			if (level == 6 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 11);
			}

		}
		if (shoot1 == 4)
		{
			char HB5[2];
			_itoa_s(2, HB5, 10);
			x[0][72] = 'H';
			x[0][73] = 'e';
			x[0][74] = 'a';
			x[0][75] = 'l';
			x[0][76] = 't';
			x[0][77] = 'h';
			x[0][78] = ' ';
			x[0][79] = 'B';
			x[0][80] = 'a';
			x[0][81] = 'r';
			x[0][82] = ' ';
			x[0][83] = 219;
			x[0][84] = ' ';
			x[0][85] = 219;
			x[0][86] = ' ';
			x[0][87] = HB5[0];
			if (level != 6)
			{
				SetConsoleTextAttribute(hConsole, 8);
			}
		}
		if (shoot1 == 5)
		{
			char HB6[2];
			_itoa_s(1, HB6, 10);
			x[0][72] = 'H';
			x[0][73] = 'e';
			x[0][74] = 'a';
			x[0][75] = 'l';
			x[0][76] = 't';
			x[0][77] = 'h';
			x[0][78] = ' ';
			x[0][79] = 'B';
			x[0][80] = 'a';
			x[0][81] = 'r';
			x[0][82] = ' ';
			x[0][83] = 219;
			x[0][84] = ' ';
			x[0][85] = HB6[0];
			if (level != 6)
			{
				SetConsoleTextAttribute(hConsole, 4);
			}
		}
		if (shoot1 >= 6)
		{
			char HB7[2];
			_itoa_s(0, HB7, 10);
			x[0][72] = 'H';
			x[0][73] = 'e';
			x[0][74] = 'a';
			x[0][75] = 'l';
			x[0][76] = 't';
			x[0][77] = 'h';
			x[0][78] = ' ';
			x[0][79] = 'B';
			x[0][80] = 'a';
			x[0][81] = 'r';
			x[0][82] = ' ';
			x[0][83] = HB7[0];
			if (level != 6)
			{
				SetConsoleTextAttribute(hConsole, 4);
			}
			lose1 = 1;

		}
	}

	if (level == 2 && countHearts == 0)
	{
		x[28][95] = 3;

	}
	if (level == 2 && countHearts2 == 0)
	{
		x[32][41] = 3;
	}

	if ((x[28][96] != ' ' || x[28][94] != ' ' || x[28][95] != 3 || x[27][94] != ' ' || x[27][95] != ' ' || x[27][96] != ' ' || x[29][94] != ' ' || x[29][95] != ' ' || x[29][96] != ' ') && level == 2 && shoot1 >= 1 && countHearts == 0)
	{

		if (shoot1 >= 1)
		{
			shoot1--;
		}

		x[28][95] = ' ';
		countHearts++;
	}

	if ((x[32][40] != ' ' || x[32][41] != 3 || x[32][42] != ' ' || x[31][41] != ' ' || x[31][42] != ' ' || x[31][43] != ' ' || x[33][41] != ' ' || x[33][42] != ' ' || x[33][43] != ' ') && level == 2 && shoot1 >= 1 && countHearts2 == 0)
	{
		if (shoot1 >= 1)
		{
			shoot1--;
		}

		x[32][41] = ' ';
		countHearts2++;
	}


	if (level == 5)
	{
		if (shoot1 == 0)
		{
			char HB1[2];
			_itoa_s(6, HB1, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = 219;
			x[rH - 2][cH - 1] = ' ';
			x[rH - 2][cH] = 219;
			x[rH - 2][cH + 1] = ' ';
			x[rH - 2][cH + 2] = 219;
			x[rH - 2][cH + 3] = ' ';
			x[rH - 2][cH + 4] = 219;
			x[rH - 2][cH + 5] = ' ';
			x[rH - 2][cH + 6] = 219;
			x[rH - 2][cH + 7] = ' ';
			x[rH - 2][cH + 8] = HB1[0];
			if (level == 1 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 2);
			}
			if (level == 2 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 3);
			}
			if (level == 3 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 6);
			}
			if (level == 4 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 5);
			}
			if (level == 5 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 12);
			}
		}
		if (shoot1 == 1)
		{
			char HB2[2];
			_itoa_s(5, HB2, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = 219;
			x[rH - 2][cH - 1] = ' ';
			x[rH - 2][cH] = 219;
			x[rH - 2][cH + 1] = ' ';
			x[rH - 2][cH + 2] = 219;
			x[rH - 2][cH + 3] = ' ';
			x[rH - 2][cH + 4] = 219;
			x[rH - 2][cH + 5] = ' ';
			x[rH - 2][cH + 6] = HB2[0];
			if (level == 1 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 2);
			}
			if (level == 2 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 3);
			}
			if (level == 3 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 6);
			}
			if (level == 4 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 5);
			}
			if (level == 5 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 12);
			}

		}
		if (shoot1 == 2)
		{
			char HB3[2];
			_itoa_s(4, HB3, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = 219;
			x[rH - 2][cH - 1] = ' ';
			x[rH - 2][cH] = 219;
			x[rH - 2][cH + 1] = ' ';
			x[rH - 2][cH + 2] = 219;
			x[rH - 2][cH + 3] = ' ';
			x[rH - 2][cH + 4] = HB3[0];
			if (level == 1 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 2);
			}
			if (level == 2 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 3);
			}
			if (level == 3 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 6);
			}
			if (level == 4 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 5);
			}
			if (level == 5 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 12);
			}

		}
		if (shoot1 == 3)
		{
			char HB4[2];
			_itoa_s(3, HB4, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = 219;
			x[rH - 2][cH - 1] = ' ';
			x[rH - 2][cH] = 219;
			x[rH - 2][cH + 1] = ' ';
			x[rH - 2][cH + 2] = HB4[0];
			if (level == 1 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 2);
			}
			if (level == 2 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 3);
			}
			if (level == 3 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 6);
			}
			if (level == 4 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 5);
			}
			if (level == 5 && mins > 1)
			{
				SetConsoleTextAttribute(hConsole, 12);
			}

		}
		if (shoot1 == 4)
		{
			char HB5[2];
			_itoa_s(2, HB5, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = 219;
			x[rH - 2][cH - 1] = ' ';
			x[rH - 2][cH] = HB5[0];
			SetConsoleTextAttribute(hConsole, 8);

		}
		if (shoot1 == 5)
		{
			char HB6[2];
			_itoa_s(1, HB6, 10);

			x[rH - 2][cH - 4] = 219;
			x[rH - 2][cH - 3] = ' ';
			x[rH - 2][cH - 2] = HB6[0];
			SetConsoleTextAttribute(hConsole, 4);

		}
		if (shoot1 >= 6)
		{
			char HB7[2];
			_itoa_s(0, HB7, 10);

			x[rH - 2][cH - 4] = HB7[0];
			SetConsoleTextAttribute(hConsole, 4);
			lose1 = 1;

		}
	}
}

void BigBossHealthBar(char x[][138], int rH, int cH, int& gotshot, int& win, int mins, int rBB, int cBB)
{

	if (gotshot == 0)
	{
		char HB1[3];
		_itoa_s(10, HB1, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = 219;
		x[rBB - 3][cBB + 1] = ' ';
		x[rBB - 3][cBB + 2] = 219;
		x[rBB - 3][cBB + 3] = ' ';
		x[rBB - 3][cBB + 4] = 219;
		x[rBB - 3][cBB + 5] = ' ';
		x[rBB - 3][cBB + 6] = 219;
		x[rBB - 3][cBB + 7] = ' ';
		x[rBB - 3][cBB + 8] = 219;
		x[rBB - 3][cBB + 9] = ' ';
		x[rBB - 3][cBB + 10] = HB1[0];
		x[rBB - 3][cBB + 11] = HB1[1];


	}
	if (gotshot == 1)
	{
		char HB2[2];
		_itoa_s(9, HB2, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = 219;
		x[rBB - 3][cBB + 1] = ' ';
		x[rBB - 3][cBB + 2] = 219;
		x[rBB - 3][cBB + 3] = ' ';
		x[rBB - 3][cBB + 4] = 219;
		x[rBB - 3][cBB + 5] = ' ';
		x[rBB - 3][cBB + 6] = 219;
		x[rBB - 3][cBB + 7] = ' ';
		x[rBB - 3][cBB + 8] = HB2[0];



	}
	if (gotshot == 2)
	{
		char HB3[2];
		_itoa_s(8, HB3, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = 219;
		x[rBB - 3][cBB + 1] = ' ';
		x[rBB - 3][cBB + 2] = 219;
		x[rBB - 3][cBB + 3] = ' ';
		x[rBB - 3][cBB + 4] = 219;
		x[rBB - 3][cBB + 5] = ' ';
		x[rBB - 3][cBB + 6] = HB3[0];


	}
	if (gotshot == 3)
	{
		char HB4[2];
		_itoa_s(7, HB4, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = 219;
		x[rBB - 3][cBB + 1] = ' ';
		x[rBB - 3][cBB + 2] = 219;
		x[rBB - 3][cBB + 3] = ' ';
		x[rBB - 3][cBB + 4] = HB4[0];


	}
	if (gotshot == 4)
	{
		char HB5[2];
		_itoa_s(6, HB5, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = 219;
		x[rBB - 3][cBB + 1] = ' ';
		x[rBB - 3][cBB + 2] = HB5[0];


	}
	if (gotshot == 5)
	{
		char HB6[2];
		_itoa_s(5, HB6, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = 219;
		x[rBB - 3][cBB - 1] = ' ';
		x[rBB - 3][cBB] = HB6[0];


	}
	if (gotshot == 6)
	{
		char HB7[2];
		_itoa_s(4, HB7, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = 219;
		x[rBB - 3][cBB - 3] = ' ';
		x[rBB - 3][cBB - 2] = HB7[0];



	}

	if (gotshot == 7)
	{
		char HB8[2];
		_itoa_s(3, HB8, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = 219;
		x[rBB - 3][cBB - 5] = ' ';
		x[rBB - 3][cBB - 4] = HB8[0];



	}

	if (gotshot == 8)
	{
		char HB9[2];
		_itoa_s(2, HB9, 10);


		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = 219;
		x[rBB - 3][cBB - 7] = ' ';
		x[rBB - 3][cBB - 6] = HB9[0];



	}

	if (gotshot == 9)
	{
		char HB10[2];
		_itoa_s(1, HB10, 10);

		x[rBB - 3][cBB - 10] = 219;
		x[rBB - 3][cBB - 9] = ' ';
		x[rBB - 3][cBB - 8] = HB10[0];



	}

	if (gotshot >= 10)
	{
		char HB11[2];
		_itoa_s(0, HB11, 10);

		x[rBB - 3][cBB - 9] = ' ';

		win = 1;

	}

}

void HighScore(char x[][138], int rH, int cH, int& Scounter, int CounterUntilStop, int& HScounter, int level, int shoot1, int flagScore1, int flagScore2, int flagScore3, int AutoWalk)
{
	x[0][124] = 'S';
	x[0][125] = 'c';
	x[0][126] = 'o';
	x[0][127] = 'r';
	x[0][128] = 'e';
	x[0][129] = ':';

	if (level == 1)
	{


		x[27][2] = 'H';
		x[27][3] = 'i';
		x[27][4] = 'g';
		x[27][5] = 'h';
		x[27][6] = ' ';
		x[27][7] = 'S';
		x[27][8] = 'c';
		x[27][9] = 'o';
		x[27][10] = 'r';
		x[27][11] = 'e';
		x[27][12] = ':';

		if (AutoWalk == 0)
		{
			x[27][53] = 'A';
			x[27][54] = 'u';
			x[27][55] = 't';
			x[27][56] = 'o';
			x[27][57] = ' ';
			x[27][58] = 'W';
			x[27][59] = 'a';
			x[27][60] = 'l';
			x[27][61] = 'k';
			x[27][62] = ' ';
			x[27][63] = ':';
			x[27][64] = ' ';
			x[27][65] = 'O';
			x[27][66] = 'F';
			x[27][67] = 'F';
			x[27][68] = ' ';
			x[27][69] = '(';
			x[27][70] = 'B';
			x[27][71] = 'S';
			x[27][72] = 'P';
			x[27][73] = ')';

		}
		if (AutoWalk == 1)
		{
			x[27][53] = 'A';
			x[27][54] = 'u';
			x[27][55] = 't';
			x[27][56] = 'o';
			x[27][57] = ' ';
			x[27][58] = 'W';
			x[27][59] = 'a';
			x[27][60] = 'l';
			x[27][61] = 'k';
			x[27][62] = ' ';
			x[27][63] = ':';
			x[27][64] = ' ';
			x[27][65] = 'O';
			x[27][66] = 'N';
			x[27][67] = ' ';
			x[27][68] = ' ';
			x[27][69] = '(';
			x[27][70] = 'B';
			x[27][71] = 'S';
			x[27][72] = 'P';
			x[27][73] = ')';

		}
	}

	if (level == 2 || level == 4)
	{


		x[20][2] = 'H';
		x[20][3] = 'i';
		x[20][4] = 'g';
		x[20][5] = 'h';
		x[20][6] = ' ';
		x[20][7] = 'S';
		x[20][8] = 'c';
		x[20][9] = 'o';
		x[20][10] = 'r';
		x[20][11] = 'e';
		x[20][12] = ':';

		if (AutoWalk == 0)
		{
			x[20][53] = 'A';
			x[20][54] = 'u';
			x[20][55] = 't';
			x[20][56] = 'o';
			x[20][57] = ' ';
			x[20][58] = 'W';
			x[20][59] = 'a';
			x[20][60] = 'l';
			x[20][61] = 'k';
			x[20][62] = ' ';
			x[20][63] = ':';
			x[20][64] = ' ';
			x[20][65] = 'O';
			x[20][66] = 'F';
			x[20][67] = 'F';
			x[20][68] = ' ';
			x[20][69] = '(';
			x[20][70] = 'B';
			x[20][71] = 'S';
			x[20][72] = 'P';
			x[20][73] = ')';

		}
		if (AutoWalk == 1)
		{
			x[20][53] = 'A';
			x[20][54] = 'u';
			x[20][55] = 't';
			x[20][56] = 'o';
			x[20][57] = ' ';
			x[20][58] = 'W';
			x[20][59] = 'a';
			x[20][60] = 'l';
			x[20][61] = 'k';
			x[20][62] = ' ';
			x[20][63] = ':';
			x[20][64] = ' ';
			x[20][65] = 'O';
			x[20][66] = 'N';
			x[20][67] = ' ';
			x[20][68] = ' ';
			x[20][69] = '(';
			x[20][70] = 'B';
			x[20][71] = 'S';
			x[20][72] = 'P';
			x[20][73] = ')';

		}
	}

	if (level == 3)
	{


		x[32][2] = 'H';
		x[32][3] = 'i';
		x[32][4] = 'g';
		x[32][5] = 'h';
		x[32][6] = ' ';
		x[32][7] = 'S';
		x[32][8] = 'c';
		x[32][9] = 'o';
		x[32][10] = 'r';
		x[32][11] = 'e';
		x[32][12] = ':';

		if (AutoWalk == 0)
		{
			x[32][53] = 'A';
			x[32][54] = 'u';
			x[32][55] = 't';
			x[32][56] = 'o';
			x[32][57] = ' ';
			x[32][58] = 'W';
			x[32][59] = 'a';
			x[32][60] = 'l';
			x[32][61] = 'k';
			x[32][62] = ' ';
			x[32][63] = ':';
			x[32][64] = ' ';
			x[32][65] = 'O';
			x[32][66] = 'F';
			x[32][67] = 'F';
			x[32][68] = ' ';
			x[32][69] = '(';
			x[32][70] = 'B';
			x[32][71] = 'S';
			x[32][72] = 'P';
			x[32][73] = ')';

		}
		if (AutoWalk == 1)
		{
			x[32][53] = 'A';
			x[32][54] = 'u';
			x[32][55] = 't';
			x[32][56] = 'o';
			x[32][57] = ' ';
			x[32][58] = 'W';
			x[32][59] = 'a';
			x[32][60] = 'l';
			x[32][61] = 'k';
			x[32][62] = ' ';
			x[32][63] = ':';
			x[32][64] = ' ';
			x[32][65] = 'O';
			x[32][66] = 'N';
			x[32][67] = ' ';
			x[32][68] = ' ';
			x[32][69] = '(';
			x[32][70] = 'B';
			x[32][71] = 'S';
			x[32][72] = 'P';
			x[32][73] = ')';

		}
	}

	if (level == 5)
	{


		x[0][72] = 'H';
		x[0][73] = 'i';
		x[0][74] = 'g';
		x[0][75] = 'h';
		x[0][76] = ' ';
		x[0][77] = 'S';
		x[0][78] = 'c';
		x[0][79] = 'o';
		x[0][80] = 'r';
		x[0][81] = 'e';
		x[0][82] = ':';

		if (AutoWalk == 0)
		{
			x[20][1] = 'A';
			x[20][2] = 'u';
			x[20][3] = 't';
			x[20][4] = 'o';
			x[20][5] = ' ';
			x[20][6] = 'W';
			x[20][7] = 'a';
			x[20][8] = 'l';
			x[20][9] = 'k';
			x[20][10] = ' ';
			x[20][11] = ':';
			x[20][12] = ' ';
			x[20][13] = 'O';
			x[20][14] = 'F';
			x[20][15] = 'F';
			x[20][16] = ' ';
			x[20][17] = '(';
			x[20][18] = 'B';
			x[20][19] = 'S';
			x[20][20] = 'P';
			x[20][21] = ')';

		}
		if (AutoWalk == 1)
		{
			x[20][1] = 'A';
			x[20][2] = 'u';
			x[20][3] = 't';
			x[20][4] = 'o';
			x[20][5] = ' ';
			x[20][6] = 'W';
			x[20][7] = 'a';
			x[20][8] = 'l';
			x[20][9] = 'k';
			x[20][10] = ' ';
			x[20][11] = ':';
			x[20][12] = ' ';
			x[20][13] = 'O';
			x[20][14] = 'N';
			x[20][15] = ' ';
			x[20][16] = ' ';
			x[20][17] = '(';
			x[20][18] = 'B';
			x[20][19] = 'S';
			x[20][20] = 'P';
			x[20][21] = ')';

		}
	}

	if (level == 6)
	{


		x[0][1] = 'H';
		x[0][2] = 'i';
		x[0][3] = 'g';
		x[0][4] = 'h';
		x[0][5] = ' ';
		x[0][6] = 'S';
		x[0][7] = 'c';
		x[0][8] = 'o';
		x[0][9] = 'r';
		x[0][10] = 'e';
		x[0][11] = ':';
		if (AutoWalk == 0)
		{
			x[20][55] = 'A';
			x[20][56] = 'u';
			x[20][57] = 't';
			x[20][58] = 'o';
			x[20][59] = ' ';
			x[20][60] = 'W';
			x[20][61] = 'a';
			x[20][62] = 'l';
			x[20][63] = 'k';
			x[20][64] = ' ';
			x[20][65] = ':';
			x[20][66] = ' ';
			x[20][67] = 'O';
			x[20][68] = 'F';
			x[20][69] = 'F';
			x[20][70] = ' ';
			x[20][71] = '(';
			x[20][72] = 'B';
			x[20][73] = 'S';
			x[20][74] = 'P';
			x[20][75] = ')';

		}
		if (AutoWalk == 1)
		{
			x[20][55] = 'A';
			x[20][56] = 'u';
			x[20][57] = 't';
			x[20][58] = 'o';
			x[20][59] = ' ';
			x[20][60] = 'W';
			x[20][61] = 'a';
			x[20][62] = 'l';
			x[20][63] = 'k';
			x[20][64] = ' ';
			x[20][65] = ':';
			x[20][66] = ' ';
			x[20][67] = 'O';
			x[20][68] = 'N';
			x[20][69] = ' ';
			x[20][70] = ' ';
			x[20][71] = '(';
			x[20][72] = 'B';
			x[20][73] = 'S';
			x[20][74] = 'P';
			x[20][75] = ')';

		}

	}

	if (CounterUntilStop >= 14 && level != 6)
	{
		Scounter++;
	}

	char SC[10];
	_itoa_s(Scounter, SC, 10);

	x[0][130] = SC[0];

	if (Scounter > 9)
	{
		x[0][131] = SC[1];
	}
	if (Scounter > 99)
	{
		x[0][132] = SC[2];
	}
	if (Scounter > 999)
	{
		x[0][133] = SC[3];
	}
	if (Scounter > 9999)
	{
		x[0][134] = SC[4];
	}
	if (Scounter > 99999)
	{
		x[0][135] = SC[5];
	}
	if (Scounter > 999999)
	{
		x[0][136] = SC[6];
	}
	if (Scounter > 9999999)
	{
		x[0][137] = SC[7];
	}

	if (level == 1)
	{


		char HSC[10];
		_itoa_s(HScounter, HSC, 10);

		if (HScounter >= 0)
		{
			x[27][13] = HSC[0];
		}
		if (HScounter > 9)
		{
			x[27][14] = HSC[1];
		}
		if (HScounter > 99)
		{
			x[27][15] = HSC[2];
		}
		if (HScounter > 999)
		{
			x[27][16] = HSC[3];
		}
		if (HScounter > 9999)
		{
			x[27][17] = HSC[4];
		}
		if (HScounter > 99999)
		{
			x[27][18] = HSC[5];
		}
		if (HScounter > 999999)
		{
			x[27][19] = HSC[6];
		}
		if (HScounter > 9999999)
		{
			x[27][20] = HSC[7];
		}

		if (CounterUntilStop >= 14)
		{
			if (Scounter > HScounter)
			{
				HScounter = Scounter;

				x[27][13] = SC[0];

				if (HScounter > 9)
				{
					x[27][14] = SC[1];
				}
				if (HScounter > 99)
				{
					x[27][15] = SC[2];
				}
				if (HScounter > 999)
				{
					x[27][16] = SC[3];
				}
				if (HScounter > 9999)
				{
					x[27][17] = SC[4];
				}
				if (HScounter > 99999)
				{
					x[27][18] = SC[5];
				}
				if (HScounter > 999999)
				{
					x[27][19] = SC[6];
				}
				if (HScounter > 9999999)
				{
					x[27][20] = SC[7];
				}
			}

		}
	}

	if (level == 2 || level == 4)
	{


		char HSC[10];
		_itoa_s(HScounter, HSC, 10);

		if (HScounter >= 0)
		{
			x[20][13] = HSC[0];
		}
		if (HScounter > 9)
		{
			x[20][14] = HSC[1];
		}
		if (HScounter > 99)
		{
			x[20][15] = HSC[2];
		}
		if (HScounter > 999)
		{
			x[20][16] = HSC[3];
		}
		if (HScounter > 9999)
		{
			x[20][17] = HSC[4];
		}
		if (HScounter > 99999)
		{
			x[20][18] = HSC[5];
		}
		if (HScounter > 999999)
		{
			x[20][19] = HSC[6];
		}
		if (HScounter > 9999999)
		{
			x[20][20] = HSC[7];
		}

		if (CounterUntilStop >= 14)
		{
			if (Scounter > HScounter)
			{
				HScounter = Scounter;

				x[20][13] = SC[0];

				if (HScounter > 9)
				{
					x[20][14] = SC[1];
				}
				if (HScounter > 99)
				{
					x[20][15] = SC[2];
				}
				if (HScounter > 999)
				{
					x[20][16] = SC[3];
				}
				if (HScounter > 9999)
				{
					x[20][17] = SC[4];
				}
				if (HScounter > 99999)
				{
					x[20][18] = SC[5];
				}
				if (HScounter > 999999)
				{
					x[20][19] = SC[6];
				}
				if (HScounter > 9999999)
				{
					x[20][20] = SC[7];
				}
			}

		}
	}


	if (level == 3)
	{


		char HSC[10];
		_itoa_s(HScounter, HSC, 10);

		if (HScounter >= 0)
		{
			x[32][13] = HSC[0];
		}
		if (HScounter > 9)
		{
			x[32][14] = HSC[1];
		}
		if (HScounter > 99)
		{
			x[32][15] = HSC[2];
		}
		if (HScounter > 999)
		{
			x[32][16] = HSC[3];
		}
		if (HScounter > 9999)
		{
			x[32][17] = HSC[4];
		}
		if (HScounter > 99999)
		{
			x[32][18] = HSC[5];
		}
		if (HScounter > 999999)
		{
			x[32][19] = HSC[6];
		}
		if (HScounter > 9999999)
		{
			x[32][20] = HSC[7];
		}

		if (CounterUntilStop >= 14)
		{
			if (Scounter > HScounter)
			{
				HScounter = Scounter;

				x[32][13] = SC[0];

				if (HScounter > 9)
				{
					x[32][14] = SC[1];
				}
				if (HScounter > 99)
				{
					x[32][15] = SC[2];
				}
				if (HScounter > 999)
				{
					x[32][16] = SC[3];
				}
				if (HScounter > 9999)
				{
					x[32][17] = SC[4];
				}
				if (HScounter > 99999)
				{
					x[32][18] = SC[5];
				}
				if (HScounter > 999999)
				{
					x[32][19] = SC[6];
				}
				if (HScounter > 9999999)
				{
					x[32][20] = SC[7];
				}
			}

		}
	}

	if (level == 5)
	{


		char HSC[10];
		_itoa_s(HScounter, HSC, 10);

		if (HScounter >= 0)
		{
			x[0][83] = HSC[0];
		}
		if (HScounter > 9)
		{
			x[0][84] = HSC[1];
		}
		if (HScounter > 99)
		{
			x[0][85] = HSC[2];
		}
		if (HScounter > 999)
		{
			x[0][86] = HSC[3];
		}
		if (HScounter > 9999)
		{
			x[0][87] = HSC[4];
		}
		if (HScounter > 99999)
		{
			x[0][88] = HSC[5];
		}
		if (HScounter > 999999)
		{
			x[0][89] = HSC[6];
		}
		if (HScounter > 9999999)
		{
			x[0][90] = HSC[7];
		}

		if (CounterUntilStop >= 14)
		{
			if (Scounter > HScounter)
			{
				HScounter = Scounter;

				x[0][83] = SC[0];

				if (HScounter > 9)
				{
					x[0][84] = SC[1];
				}
				if (HScounter > 99)
				{
					x[0][85] = SC[2];
				}
				if (HScounter > 999)
				{
					x[0][86] = SC[3];
				}
				if (HScounter > 9999)
				{
					x[0][87] = SC[4];
				}
				if (HScounter > 99999)
				{
					x[0][88] = SC[5];
				}
				if (HScounter > 999999)
				{
					x[0][89] = SC[6];
				}
				if (HScounter > 9999999)
				{
					x[0][90] = SC[7];
				}
			}

		}
	}

	if (level == 6)
	{


		char HSC[10];
		_itoa_s(HScounter, HSC, 10);

		if (HScounter >= 0)
		{
			x[0][12] = HSC[0];
		}
		if (HScounter > 9)
		{
			x[0][13] = HSC[1];
		}
		if (HScounter > 99)
		{
			x[0][14] = HSC[2];
		}
		if (HScounter > 999)
		{
			x[0][15] = HSC[3];
		}
		if (HScounter > 9999)
		{
			x[0][16] = HSC[4];
		}
		if (HScounter > 99999)
		{
			x[0][17] = HSC[5];
		}
		if (HScounter > 999999)
		{
			x[0][18] = HSC[6];
		}
		if (HScounter > 9999999)
		{
			x[0][19] = HSC[7];
		}

		if (CounterUntilStop >= 14)
		{
			if (Scounter > HScounter)
			{
				HScounter = Scounter;

				x[0][12] = SC[0];

				if (HScounter > 9)
				{
					x[0][13] = SC[1];
				}
				if (HScounter > 99)
				{
					x[0][14] = SC[2];
				}
				if (HScounter > 999)
				{
					x[0][15] = SC[3];
				}
				if (HScounter > 9999)
				{
					x[0][16] = SC[4];
				}
				if (HScounter > 99999)
				{
					x[0][17] = SC[5];
				}
				if (HScounter > 999999)
				{
					x[0][18] = SC[6];
				}
				if (HScounter > 9999999)
				{
					x[0][19] = SC[7];
				}
			}

		}
	}
}

void StaticGunShot(char x[][138], int rE1, int cE1, int& rEG1, int& cEG1, int& countG1, int CounterUntilStop, int GetOut)
{
	/*if (countG1 % 2 != 0)
	{
		rEG1 = rE1;
		cEG1 = cE1;

	}*/

	if (CounterUntilStop >= 21 && (GetOut == 0 || GetOut == 3))
	{
		x[rEG1 + 5][cEG1 + 13] = 22;

	}

}

void DynamicGunShot(char x[][138], int& rE1, int& cE1, int& rEG1, int& cEG1, int& countG1, int CounterUntilStop, int rH, int cH, int& shoot1, int GetOut, int& DelayShot, int& lose1, int& DeathT)
{

	int breakable = 0;
	breakable = 0;
	if (CounterUntilStop >= 21 && (GetOut == 0 || GetOut == 3))
	{
		cEG1 += 4;
	}

	if (cEG1 > 95 && CounterUntilStop >= 21 && (GetOut == 0 || GetOut == 3))
	{
		cEG1 = cE1;
	}


	if (CounterUntilStop >= 21 && (GetOut == 0 || GetOut == 3))
	{
		for (int r = rH, i = 0; i < 12; i++, r++)
		{
			for (int c = cH - 4, j = 0; j < 8; j++, c++)
			{
				if (x[r][c] == 22)
				{
					DeathT = 3;
					shoot1++;
					cEG1 = cE1;
					breakable = 1;
					break;
				}
			}
			if (breakable == 1)
			{
				breakable = 0;
				break;
			}

		}

		for (int r = rH - 1, i = 0; i < 12; i++, r++)
		{
			for (int c = cH - 13, j = 0; j < 20; j++, c++)
			{
				if (x[r][c] == 21)
				{
					lose1 = 1;
					DeathT = 2;
					breakable = 1;
					break;
				}
			}
			if (breakable == 1)
			{
				break;
			}

		}

	}

	if (CounterUntilStop >= 21 && cH <= 26)
	{
		DeathT = 2;
		lose1 = 1;
	}


}

void StaticEnemy(char x[][138], int cE1, int rE1, int CounterUntilStop, int countRLEL1, int Reload, int ActionReload, int level, int rB, int cB)
{

	if (CounterUntilStop >= 21)
	{


		x[rE1][cE1 - 2] = '_';
		x[rE1][cE1 - 3] = '/';
		x[rE1 + 1][cE1 - 3] = '\\';
		x[rE1 - 1][cE1 - 2] = '_';
		x[rE1 - 1][cE1 - 1] = '_';
		x[rE1 - 1][cE1] = '_';
		x[rE1 - 1][cE1 + 1] = '_';
		x[rE1 - 1][cE1 + 2] = '_';
		x[rE1 - 1][cE1 + 3] = '_';
		x[rE1][cE1 + 3] = '_';
		x[rE1][cE1 + 4] = '\\';
		x[rE1 + 1][cE1 + 4] = '/';



		x[rE1][cE1 - 1] = '_';
		x[rE1][cE1] = 21;
		x[rE1][cE1 + 1] = '_';
		x[rE1][cE1 + 2] = '_';


		{
			x[rE1 + 2][cE1] = 127;
			x[rE1 + 2][cE1 + 2] = 127;

			x[rE1 + 2][cE1 + 1] = ' ';
			x[rE1 + 2][cE1 - 1] = ' ';
		}

		x[rE1 + 1][cE1 - 2] = '/';
		x[rE1 + 1][cE1 + 3] = '\\';

		x[rE1 + 2][cE1 - 2] = '|';
		x[rE1 + 2][cE1 + 3] = '|';

		x[rE1 + 3][cE1 - 2] = '\\';
		x[rE1 + 3][cE1 + 3] = '/';

		x[rE1 + 3][cE1 - 1] = '_';
		x[rE1 + 3][cE1] = '_';
		x[rE1 + 3][cE1 + 1] = '^';
		x[rE1 + 3][cE1 + 2] = '_';

		x[rE1 + 4][cE1 - 2] = '_';
		x[rE1 + 4][cE1 - 1] = '/';
		x[rE1 + 4][cE1 + 2] = '/';
		x[rE1 + 4][cE1 + 3] = '_';

		if (countRLEL1 == 0)
		{


			x[rE1 + 6][cE1 + 4] = '\\';	//RIGHT HAND
			x[rE1 + 6][cE1 + 5] = '_';
			x[rE1 + 6][cE1 + 6] = '_';
			x[rE1 + 6][cE1 + 7] = '/';
			x[rE1 + 5][cE1 + 8] = '_';
			x[rE1 + 4][cE1 + 7] = '_';
			x[rE1 + 5][cE1 + 5] = '\\';
			x[rE1 + 5][cE1 + 6] = '/';
			x[rE1 + 4][cE1 + 4] = '_';

			x[rE1 + 4][cE1 + 7] = '_';	//GUN
			x[rE1 + 4][cE1 + 8] = '_';
			x[rE1 + 4][cE1 + 9] = '_';
			x[rE1 + 4][cE1 + 10] = '_';
			x[rE1 + 4][cE1 + 11] = '_';
			x[rE1 + 4][cE1 + 12] = '_';
			x[rE1 + 5][cE1 + 13] = '|';
			x[rE1 + 5][cE1 + 12] = '_';
			x[rE1 + 5][cE1 + 11] = '_';
			x[rE1 + 5][cE1 + 10] = '_';
			x[rE1 + 6][cE1 + 9] = '/';
			x[rE1 + 6][cE1 + 8] = '_';

		}
		if (countRLEL1 % 2 != 0)
		{
			x[rE1 + 6][cE1 + 4] = '_';	//RIGHT HAND
			x[rE1 + 6][cE1 + 3] = ' ';
			x[rE1 + 5][cE1 + 3] = '/';
			x[rE1 + 6][cE1 + 5] = '_';
			x[rE1 + 6][cE1 + 7] = ' ';
			x[rE1 + 6][cE1 + 6] = ' ';//
			x[rE1 + 6][cE1 + 8] = ' ';
			x[rE1 + 4][cE1 + 7] = '_';
			x[rE1 + 5][cE1 + 5] = '_';
			x[rE1 + 5][cE1 + 6] = ' ';
			x[rE1 + 5][cE1 + 7] = ' ';
			x[rE1 + 4][cE1 + 4] = ' ';
			x[rE1 + 5][cE1 + 4] = '_';
			x[rE1 + 4][cE1 + 7] = ' ';

			x[rE1 + 5][cE1 + 6] = ' ';	//GUN
			x[rE1 + 6][cE1 + 6] = '/';
			x[rE1 + 5][cE1 + 7] = '_';
			x[rE1 + 5][cE1 + 8] = '_';
			x[rE1 + 5][cE1 + 9] = '_';
			x[rE1 + 5][cE1 + 10] = '_';
			x[rE1 + 5][cE1 + 11] = '_';
			x[rE1 + 6][cE1 + 12] = '|';
			x[rE1 + 6][cE1 + 11] = '_';
			x[rE1 + 6][cE1 + 10] = '_';
			x[rE1 + 6][cE1 + 9] = '_';
			x[rE1 + 7][cE1 + 8] = '/';
			x[rE1 + 7][cE1 + 7] = '_';
			x[rE1 + 6][cE1 + 7] = ' ';
			x[rE1 + 7][cE1 + 6] = '|';



		}
		else
		{
			x[rE1 + 6][cE1 + 4] = '\\';	//RIGHT HAND
			x[rE1 + 6][cE1 + 5] = '_';
			x[rE1 + 6][cE1 + 6] = '_';
			x[rE1 + 6][cE1 + 7] = '/';
			x[rE1 + 5][cE1 + 8] = '_';
			x[rE1 + 4][cE1 + 7] = '_';
			x[rE1 + 5][cE1 + 5] = '\\';
			x[rE1 + 5][cE1 + 6] = '/';
			x[rE1 + 4][cE1 + 4] = '_';

			x[rE1 + 4][cE1 + 7] = '_';	//GUN
			x[rE1 + 4][cE1 + 8] = '_';
			x[rE1 + 4][cE1 + 9] = '_';
			x[rE1 + 4][cE1 + 10] = '_';
			x[rE1 + 4][cE1 + 11] = '_';
			x[rE1 + 4][cE1 + 12] = '_';
			x[rE1 + 5][cE1 + 13] = '|';
			x[rE1 + 5][cE1 + 12] = '_';
			x[rE1 + 5][cE1 + 11] = '_';
			x[rE1 + 5][cE1 + 10] = '_';
			x[rE1 + 6][cE1 + 9] = '/';
			x[rE1 + 6][cE1 + 8] = '_';



		}

		LeftHandMoveH1(x, rE1, cE1, countRLEL1, Reload, ActionReload, level, rB, cB);

		//x[rH + 5][cH + 3] = ' ';	   
		//x[rH + 6][cH + 3] = '|';	   
		x[rE1 + 7][cE1 + 3] = '|';

		//x[rH + 5][cH - 2] = ' ';
		//x[rH + 6][cH - 2] = ' ';
		x[rE1 + 7][cE1 - 2] = '|';

		x[rE1 + 7][cE1 - 1] = '_';
		x[rE1 + 7][cE1 + 1] = '_';
		x[rE1 + 7][cE1 + 2] = '_';
		x[rE1 + 7][cE1] = '_';

		LeftLegMoveH1(x, rE1, cE1, countRLEL1);
		RightLegMoveH1(x, rE1, cE1, countRLEL1);

	}

}

void DynamicEnemy(char x[][138], int& cE1, int& rE1, int CounterUntilStop, int& countRLEL1, int rEG1, int cEG1, int countG1, int GetOut)
{
	if (CounterUntilStop >= 21 && CounterUntilStop < 48 && (GetOut == 0 || GetOut == 3))
	{
		cE1++;
		countRLEL1++;

	}
}

void StaticGunShot2(char x[][138], int rE2, int cE2, int& rEG2, int& cEG2, int& countG2, int CounterUntilStop, int GetOut)
{
	/*if (countG1 % 2 != 0)
	{
		rEG1 = rE1;
		cEG1 = cE1;

	}*/

	if (CounterUntilStop >= 44 && (GetOut == 0 || GetOut == 3))
	{
		x[rEG2 + 5][cEG2 + 13] = '=';
	}

}

void DynamicGunShot2(char x[][138], int& rE2, int& cE2, int& rEG2, int& cEG2, int& countG2, int CounterUntilStop, int rH, int cH, int& shoot1, int GetOut, int& DelayShot, int& DeathT)
{

	int breakable = 0;
	breakable = 0;

	if (CounterUntilStop >= 44 && (GetOut == 0 || GetOut == 3))
	{
		cEG2 += 3;
	}

	if (cEG2 > 95 && CounterUntilStop >= 44 && (GetOut == 0 || GetOut == 3))
	{
		cEG2 = cE2;
	}


	/*if (CounterUntilStop >= 44 && (GetOut == 0 || GetOut == 3))
	{
		for (int r = rH, i = 0; i < 6; i++, r++)
		{
			for (int c = cH - 3, j = 0; j < 8; j++, c++)
			{
				if (rEG2 == r && cEG2 == c)
				{
					shoot1++;
					cEG2 = cE2 + 13;
					breakable = 1;
					break;
				}
			}
			if (breakable == 1)
			{
				break;
			}

		}

	}*/

	if (CounterUntilStop >= 44 && (GetOut == 0 || GetOut == 3))
	{
		for (int r = rH, i = 0; i < 12; i++, r++)
		{
			for (int c = cH - 4, j = 0; j < 8; j++, c++)
			{
				if (x[r][c] == '=')
				{
					DeathT = 3;
					shoot1++;
					cEG2 = cE2;
					breakable = 1;
					break;
				}
				if (breakable == 1)
				{
					break;
				}
			}

		}

	}



}

void StaticEnemy2(char x[][138], int cE2, int rE2, int CounterUntilStop, int countRLEL2, int Reload, int ActionReload, int level, int rB, int cB)
{

	if (CounterUntilStop >= 44)
	{


		x[rE2][cE2 - 2] = '_';
		x[rE2][cE2 - 3] = '/';
		x[rE2 + 1][cE2 - 3] = '\\';
		x[rE2 - 1][cE2 - 2] = '_';
		x[rE2 - 1][cE2 - 1] = '_';
		x[rE2 - 1][cE2] = '_';
		x[rE2 - 1][cE2 + 1] = '_';
		x[rE2 - 1][cE2 + 2] = '_';
		x[rE2 - 1][cE2 + 3] = '_';
		x[rE2][cE2 + 3] = '_';
		x[rE2][cE2 + 4] = '\\';
		x[rE2 + 1][cE2 + 4] = '/';



		x[rE2][cE2 - 1] = '_';
		x[rE2][cE2] = 21;
		x[rE2][cE2 + 1] = '_';
		x[rE2][cE2 + 2] = '_';


		{
			x[rE2 + 2][cE2] = 127;
			x[rE2 + 2][cE2 + 2] = 127;

			x[rE2 + 2][cE2 + 1] = ' ';
			x[rE2 + 2][cE2 - 1] = ' ';
		}

		x[rE2 + 1][cE2 - 2] = '/';
		x[rE2 + 1][cE2 + 3] = '\\';

		x[rE2 + 2][cE2 - 2] = '|';
		x[rE2 + 2][cE2 + 3] = '|';

		x[rE2 + 3][cE2 - 2] = '\\';
		x[rE2 + 3][cE2 + 3] = '/';

		x[rE2 + 3][cE2 - 1] = '_';
		x[rE2 + 3][cE2] = '_';
		x[rE2 + 3][cE2 + 1] = '^';
		x[rE2 + 3][cE2 + 2] = '_';

		x[rE2 + 4][cE2 - 2] = '_';
		x[rE2 + 4][cE2 - 1] = '/';
		x[rE2 + 4][cE2 + 2] = '/';
		x[rE2 + 4][cE2 + 3] = '_';

		if (countRLEL2 == 0)
		{


			x[rE2 + 6][cE2 + 4] = '\\';	//RIGHT HAND
			x[rE2 + 6][cE2 + 5] = '_';
			x[rE2 + 6][cE2 + 6] = '_';
			x[rE2 + 6][cE2 + 7] = '/';
			x[rE2 + 5][cE2 + 8] = '_';
			x[rE2 + 4][cE2 + 7] = '_';
			x[rE2 + 5][cE2 + 5] = '\\';
			x[rE2 + 5][cE2 + 6] = '/';
			x[rE2 + 4][cE2 + 4] = '_';

			x[rE2 + 4][cE2 + 7] = '_';	//GUN
			x[rE2 + 4][cE2 + 8] = '_';
			x[rE2 + 4][cE2 + 9] = '_';
			x[rE2 + 4][cE2 + 10] = '_';
			x[rE2 + 4][cE2 + 11] = '_';
			x[rE2 + 4][cE2 + 12] = '_';
			x[rE2 + 5][cE2 + 13] = '|';
			x[rE2 + 5][cE2 + 12] = '_';
			x[rE2 + 5][cE2 + 11] = '_';
			x[rE2 + 5][cE2 + 10] = '_';
			x[rE2 + 6][cE2 + 9] = '/';
			x[rE2 + 6][cE2 + 8] = '_';

		}
		if (countRLEL2 % 2 != 0)
		{
			x[rE2 + 6][cE2 + 4] = '_';	//RIGHT HAND
			x[rE2 + 6][cE2 + 3] = ' ';
			x[rE2 + 5][cE2 + 3] = '/';
			x[rE2 + 6][cE2 + 5] = '_';
			x[rE2 + 6][cE2 + 7] = ' ';
			x[rE2 + 6][cE2 + 6] = ' ';//
			x[rE2 + 6][cE2 + 8] = ' ';
			x[rE2 + 4][cE2 + 7] = '_';
			x[rE2 + 5][cE2 + 5] = '_';
			x[rE2 + 5][cE2 + 6] = ' ';
			x[rE2 + 5][cE2 + 7] = ' ';
			x[rE2 + 4][cE2 + 4] = ' ';
			x[rE2 + 5][cE2 + 4] = '_';
			x[rE2 + 4][cE2 + 7] = ' ';

			x[rE2 + 5][cE2 + 6] = ' ';	//GUN
			x[rE2 + 6][cE2 + 6] = '/';
			x[rE2 + 5][cE2 + 7] = '_';
			x[rE2 + 5][cE2 + 8] = '_';
			x[rE2 + 5][cE2 + 9] = '_';
			x[rE2 + 5][cE2 + 10] = '_';
			x[rE2 + 5][cE2 + 11] = '_';
			x[rE2 + 6][cE2 + 12] = '|';
			x[rE2 + 6][cE2 + 11] = '_';
			x[rE2 + 6][cE2 + 10] = '_';
			x[rE2 + 6][cE2 + 9] = '_';
			x[rE2 + 7][cE2 + 8] = '/';
			x[rE2 + 7][cE2 + 7] = '_';
			x[rE2 + 6][cE2 + 7] = ' ';
			x[rE2 + 7][cE2 + 6] = '|';



		}
		else
		{
			x[rE2 + 6][cE2 + 4] = '\\';	//RIGHT HAND
			x[rE2 + 6][cE2 + 5] = '_';
			x[rE2 + 6][cE2 + 6] = '_';
			x[rE2 + 6][cE2 + 7] = '/';
			x[rE2 + 5][cE2 + 8] = '_';
			x[rE2 + 4][cE2 + 7] = '_';
			x[rE2 + 5][cE2 + 5] = '\\';
			x[rE2 + 5][cE2 + 6] = '/';
			x[rE2 + 4][cE2 + 4] = '_';

			x[rE2 + 4][cE2 + 7] = '_';	//GUN
			x[rE2 + 4][cE2 + 8] = '_';
			x[rE2 + 4][cE2 + 9] = '_';
			x[rE2 + 4][cE2 + 10] = '_';
			x[rE2 + 4][cE2 + 11] = '_';
			x[rE2 + 4][cE2 + 12] = '_';
			x[rE2 + 5][cE2 + 13] = '|';
			x[rE2 + 5][cE2 + 12] = '_';
			x[rE2 + 5][cE2 + 11] = '_';
			x[rE2 + 5][cE2 + 10] = '_';
			x[rE2 + 6][cE2 + 9] = '/';
			x[rE2 + 6][cE2 + 8] = '_';



		}

		LeftHandMoveH1(x, rE2, cE2, countRLEL2, Reload, ActionReload, level, rB, cB);

		//x[rH + 5][cH + 3] = ' ';	   
		//x[rH + 6][cH + 3] = '|';	   
		x[rE2 + 7][cE2 + 3] = '|';

		//x[rH + 5][cH - 2] = ' ';
		//x[rH + 6][cH - 2] = ' ';
		x[rE2 + 7][cE2 - 2] = '|';

		x[rE2 + 7][cE2 - 1] = '_';
		x[rE2 + 7][cE2 + 1] = '_';
		x[rE2 + 7][cE2 + 2] = '_';
		x[rE2 + 7][cE2] = '_';

		LeftLegMoveH1(x, rE2, cE2, countRLEL2);
		RightLegMoveH1(x, rE2, cE2, countRLEL2);

	}

}

void DynamicEnemy2(char x[][138], int& cE2, int& rE2, int CounterUntilStop, int& countRLEL2, int rEG2, int cEG2, int countG2, int GetOut)
{
	if (CounterUntilStop >= 44 && CounterUntilStop <= 51 && (GetOut == 0 || GetOut == 3))
	{
		cE2++;
		countRLEL2++;

	}
}

void StaticCar1(char x[][138], int c, int r, int cH, int rH, int level, int sarena, int& ratio1)
{

	x[r][c - 1] = '_';
	x[r][c - 2] = '_';
	x[r][c] = '_';
	x[r][c + 1] = '_';
	x[r][c + 2] = '_';

	x[r + 1][c - 1] = '_';
	x[r + 1][c - 2] = '_';
	x[r + 1][c] = 179;
	x[r + 1][c + 1] = '_';
	x[r + 1][c + 2] = '_';

	x[r + 1][c + 3] = 179;
	x[r + 1][c - 3] = 179;

	x[r + 1][c + 4] = '_';
	x[r + 1][c - 4] = '_';


	x[r + 2][c + 6] = '\\';
	x[r + 3][c + 8] = '\\';
	x[r + 3][c + 9] = '_';
	x[r + 3][c + 10] = '_';
	x[r + 3][c + 11] = '_';
	x[r + 3][c + 12] = '_';
	x[r + 3][c + 13] = '_';
	x[r + 3][c + 14] = '_';
	x[r + 4][c + 15] = 179;

	x[r + 2][c - 6] = '/';
	x[r + 3][c - 8] = '/';
	x[r + 4][c - 10] = '/';
	x[r + 4][c - 11] = '_';
	x[r + 4][c - 12] = '_';
	x[r + 4][c - 13] = '_';
	x[r + 4][c - 14] = '_';
	x[r + 4][c - 15] = '_';
	x[r + 4][c - 16] = '_';
	x[r + 4][c - 17] = '_';
	x[r + 4][c - 18] = '_';
	x[r + 5][c - 19] = '/';

	x[r + 5][c - 18] = '_';
	x[r + 5][c - 17] = '_';
	x[r + 5][c - 16] = '/';
	x[r + 6][c - 19] = '\\';
	x[r + 7][c - 19] = 179;
	x[r + 8][c - 18] = '\\';
	x[r + 8][c - 17] = '_';
	x[r + 8][c - 16] = '_';
	x[r + 8][c - 15] = '_';
	x[r + 8][c - 14] = '_';


	x[r + 8][c - 13] = '|';						//el3agala LEFT
	x[r + 7][c - 13] = '/';
	x[r + 6][c - 12] = '_';
	x[r + 6][c - 11] = '_';
	x[r + 6][c - 10] = '_';
	x[r + 7][c - 9] = '\\';
	x[r + 8][c - 9] = '|';




	x[r + 8][c - 8] = '_';
	x[r + 8][c - 7] = '_';
	x[r + 8][c - 6] = '_';
	x[r + 8][c - 5] = '_';
	x[r + 8][c - 4] = '_';
	x[r + 8][c - 3] = '_';
	x[r + 8][c - 2] = '_';
	x[r + 8][c - 1] = '_';
	x[r + 8][c] = '_';
	x[r + 8][c + 1] = '_';
	x[r + 8][c + 2] = '_';
	x[r + 8][c + 3] = '_';
	x[r + 8][c + 4] = '_';
	x[r + 8][c + 5] = '_';
	x[r + 8][c + 6] = '_';
	x[r + 8][c + 7] = '_';


	x[r + 8][c + 8] = '|';						//el3agala RIGHT
	x[r + 7][c + 8] = '/';
	x[r + 6][c + 9] = '_';
	x[r + 6][c + 10] = '_';
	x[r + 6][c + 11] = '_';
	x[r + 7][c + 12] = '\\';
	x[r + 8][c + 12] = '|';





	x[r + 4][c + 14] = '_';
	x[r + 5][c + 13] = '|';
	x[r + 5][c + 14] = '_';


	x[r + 6][c + 14] = '_';
	x[r + 6][c + 13] = '|';


	x[r + 7][c + 15] = 179;
	x[r + 8][c + 16] = '\\';
	x[r + 8][c + 15] = '_';
	x[r + 8][c + 14] = '_';
	x[r + 8][c + 13] = '_';

	x[r + 6][c + 15] = '|';
	x[r + 5][c + 15] = '|';

	//////////////////////INSIDE//////


	x[r + 4][c - 9] = '_';
	x[r + 4][c - 8] = '_';
	x[r + 4][c - 7] = '_';
	x[r + 4][c - 6] = '_';
	x[r + 4][c - 5] = '_';
	x[r + 4][c - 4] = '^';
	x[r + 4][c - 3] = '_';
	x[r + 4][c - 2] = '_';
	x[r + 4][c - 1] = '_';
	x[r + 4][c] = '_';
	x[r + 4][c + 1] = '_';
	x[r + 4][c + 2] = '_';
	x[r + 4][c + 3] = '_';
	x[r + 4][c + 4] = '_';
	x[r + 4][c + 5] = '_';
	x[r + 4][c + 6] = '_';
	x[r + 4][c + 7] = '_';
	x[r + 4][c + 8] = '_';
	x[r + 4][c + 9] = '_';
	x[r + 4][c + 10] = '/';


	x[r + 2][c + 5] = '\\';
	x[r + 3][c + 7] = '\\';

	x[r + 2][c + 4] = '|';
	x[r + 3][c + 4] = '|';
	x[r + 4][c + 4] = '|';


	x[r + 3][c + 3] = '/';
	x[r + 4][c + 3] = '|';

	x[r + 5][c + 2] = 191;

	x[r + 5][c + 3] = '\\';
	x[r + 6][c + 4] = 179;
	x[r + 7][c + 4] = 179;

	///////////////FACE INSIDE///

	x[r + 2][c - 3] = '_';
	x[r + 2][c - 4] = '_';
	x[r + 2][c - 5] = '_';
	x[r + 3][c - 2] = 179;
	x[r + 4][c - 2] = 179;

	x[r + 3][c - 6] = 179;
	x[r + 4][c - 6] = 179;

	x[r + 3][c - 5] = '-';
	x[r + 3][c - 4] = '-';

	x[r + 6][c - 2] = 'F';
	x[r + 6][c - 1] = 'B';
	x[r + 6][c] = 'I';


}

void DynamicCar1(char x[][138], int& c, int& r, int& cH, int& rH, int& level, int& sarena, int& lose1, int& DeathT, int& Shoot1, int& ratio1, int cCar2, int rCar2, int& flagC, int timer2, int& c2)
{
	if (timer2 >= 2)
	{
		if (x[r][c - 20] == ' ' && x[r + 1][c - 20] == ' ' && x[r + 2][c - 20] == ' ' && x[r + 3][c - 20] == ' ' && x[r + 4][c - 20] == ' ' && x[r + 5][c - 20] == ' ' && x[r + 6][c - 20] == ' ' && x[r + 7][c - 20] == ' ' && x[r + 8][c - 20] == ' ' && x[r + 3][c - 18] == ' ' && x[r + 3][c - 17] == ' ' && x[r + 3][c - 16] == ' ' && x[r + 3][c - 15] == ' ' && x[r + 3][c - 14] == ' ' && x[r + 3][c - 13] == ' ' && x[r + 3][c - 12] == ' ' && x[r + 3][c - 11] == ' ' && x[r + 3][c - 10] == ' ' && x[r + 2][c - 8] == ' ' && x[r + 1][c - 6] == ' ' && x[r][c - 4] == ' ' && x[r][c - 3] == ' ' && x[r - 1][c - 1] == ' ' && x[r - 1][c - 2] == ' ' && x[r - 1][c] == ' ' && x[r - 1][c + 1] == ' ' && x[r - 1][c + 2] == ' ' && x[r - 1][c + 3] == ' ' && x[r][c + 4] == ' ' && x[r + 1][c + 5] == ' ' && x[r + 1][c + 6] == ' ' && x[r + 2][c + 7] == ' ' && x[r + 2][c + 8] == ' ' && x[r + 2][c + 9] == ' ' && x[r + 2][c + 10] == ' ' && x[r + 2][c + 11] == ' ' && x[r + 2][c + 12] == ' ' && x[r + 2][c + 13] == ' ' && x[r + 2][c + 14] == ' ' && x[r + 2][c + 15] == ' ')
		{
			if (sarena % 2 == 0)
			{
				x[r + 1][c - 1] = 219;
				x[r + 1][c - 2] = 219;

				x[r + 1][c + 1] = '_';
				x[r + 1][c + 2] = '_';


				//elgwa el3agala  LEFT
				x[r + 7][c - 11] = 179;
				x[r + 8][c - 10] = '\\';
				x[r + 8][c - 12] = ' ';

				//elgwa el3agala  RIGHT
				x[r + 7][c + 10] = 179;
				x[r + 8][c + 11] = '\\';
				x[r + 8][c + 9] = ' ';


			}
			else
			{
				x[r + 1][c + 1] = 219;
				x[r + 1][c + 2] = 219;

				x[r + 1][c - 1] = '_';
				x[r + 1][c - 2] = '_';


				//elgwa el3agala  LEFT
				x[r + 7][c - 11] = ' ';
				x[r + 8][c - 10] = '\\';
				x[r + 8][c - 12] = '/';

				//elgwa el3agala  RIGHT
				x[r + 7][c + 10] = ' ';
				x[r + 8][c + 11] = '\\';
				x[r + 8][c + 9] = '/';

			}

			c -= 6;
		}
		else if ((x[r][c - 20] != ' ' || x[r + 1][c - 20] != ' ' || x[r + 2][c - 20] != ' ' || x[r + 3][c - 20] != ' ' || x[r + 4][c - 20] != ' ' || x[r + 5][c - 20] != ' ' || x[r + 6][c - 20] != ' ' || x[r + 7][c - 20] != ' ' || x[r + 8][c - 20] != ' ' || x[r + 3][c - 18] != ' ' || x[r + 3][c - 17] != ' ' || x[r + 3][c - 16] != ' ' || x[r + 3][c - 15] != ' ' || x[r + 3][c - 14] != ' ' || x[r + 3][c - 13] != ' ' || x[r + 3][c - 12] != ' ' || x[r + 3][c - 11] != ' ' || x[r + 3][c - 10] != ' ' || x[r + 2][c - 8] != ' ' || x[r + 1][c - 6] != ' ' || x[r][c - 4] != ' ' || x[r][c - 3] != ' ' || x[r - 1][c - 1] != ' ' || x[r - 1][c - 2] != ' ' || x[r - 1][c] != ' ' || x[r - 1][c + 1] != ' ' || x[r - 1][c + 2] != ' ' || x[r - 1][c + 3] != ' ' || x[r][c + 4] != ' ' || x[r + 1][c + 5] != ' ' || x[r + 1][c + 6] != ' ' || x[r + 2][c + 7] != ' ' || x[r + 2][c + 8] != ' ' || x[r + 2][c + 9] != ' ' || x[r + 2][c + 10] != ' ' || x[r + 2][c + 11] != ' ' || x[r + 2][c + 12] != ' ' || x[r + 2][c + 13] != ' ' || x[r + 2][c + 14] != ' ' || x[r + 2][c + 15] == ' '))
		{
			cH -= 10;
			c = 120;
			DeathT = 4;
			Shoot1 += 2;

		}


		if (c - 16 <= 0 && ratio1 == 1)
		{
			c = 120;
			ratio1 = 2;
			c2 = 75;
		}

		if (c - 16 <= 0 && ratio1 == 2)
		{
			c = 120;
			ratio1 = 1;
		}
	}
}

void StaticCar2(char x[][138], int c, int r, int cH, int rH, int level, int sarena, int& ratio1, int& flagC2)
{
	if (ratio1 == 2 && flagC2 == 1)
	{


		x[r][c - 1] = '_';
		x[r][c - 2] = '_';
		x[r][c] = '_';
		x[r][c + 1] = '_';
		x[r][c + 2] = '_';

		x[r + 1][c - 1] = '_';
		x[r + 1][c - 2] = '_';
		x[r + 1][c] = 179;
		x[r + 1][c + 1] = '_';
		x[r + 1][c + 2] = '_';

		x[r + 1][c + 3] = 179;
		x[r + 1][c - 3] = 179;

		x[r + 1][c + 4] = '_';
		x[r + 1][c - 4] = '_';


		x[r + 2][c + 6] = '\\';
		x[r + 3][c + 8] = '\\';
		x[r + 3][c + 9] = '_';
		x[r + 3][c + 10] = '_';
		x[r + 3][c + 11] = '_';
		x[r + 3][c + 12] = '_';
		x[r + 3][c + 13] = '_';
		x[r + 3][c + 14] = '_';
		x[r + 4][c + 15] = 179;

		x[r + 2][c - 6] = '/';
		x[r + 3][c - 8] = '/';
		x[r + 4][c - 10] = '/';
		x[r + 4][c - 11] = '_';
		x[r + 4][c - 12] = '_';
		x[r + 4][c - 13] = '_';
		x[r + 4][c - 14] = '_';
		x[r + 4][c - 15] = '_';
		x[r + 4][c - 16] = '_';
		x[r + 4][c - 17] = '_';
		x[r + 4][c - 18] = '_';
		x[r + 5][c - 19] = '/';

		x[r + 5][c - 18] = '_';
		x[r + 5][c - 17] = '_';
		x[r + 5][c - 16] = '/';
		x[r + 6][c - 19] = '\\';
		x[r + 7][c - 19] = 179;
		x[r + 8][c - 18] = '\\';
		x[r + 8][c - 17] = '_';
		x[r + 8][c - 16] = '_';
		x[r + 8][c - 15] = '_';
		x[r + 8][c - 14] = '_';


		x[r + 8][c - 13] = '|';						//el3agala LEFT
		x[r + 7][c - 13] = '/';
		x[r + 6][c - 12] = '_';
		x[r + 6][c - 11] = '_';
		x[r + 6][c - 10] = '_';
		x[r + 7][c - 9] = '\\';
		x[r + 8][c - 9] = '|';




		x[r + 8][c - 8] = '_';
		x[r + 8][c - 7] = '_';
		x[r + 8][c - 6] = '_';
		x[r + 8][c - 5] = '_';
		x[r + 8][c - 4] = '_';
		x[r + 8][c - 3] = '_';
		x[r + 8][c - 2] = '_';
		x[r + 8][c - 1] = '_';
		x[r + 8][c] = '_';
		x[r + 8][c + 1] = '_';
		x[r + 8][c + 2] = '_';
		x[r + 8][c + 3] = '_';
		x[r + 8][c + 4] = '_';
		x[r + 8][c + 5] = '_';
		x[r + 8][c + 6] = '_';
		x[r + 8][c + 7] = '_';


		x[r + 8][c + 8] = '|';						//el3agala RIGHT
		x[r + 7][c + 8] = '/';
		x[r + 6][c + 9] = '_';
		x[r + 6][c + 10] = '_';
		x[r + 6][c + 11] = '_';
		x[r + 7][c + 12] = '\\';
		x[r + 8][c + 12] = '|';





		x[r + 4][c + 14] = '_';
		x[r + 5][c + 13] = '|';
		x[r + 5][c + 14] = '_';


		x[r + 6][c + 14] = '_';
		x[r + 6][c + 13] = '|';


		x[r + 7][c + 15] = 179;
		x[r + 8][c + 16] = '\\';
		x[r + 8][c + 15] = '_';
		x[r + 8][c + 14] = '_';
		x[r + 8][c + 13] = '_';

		x[r + 6][c + 15] = '|';
		x[r + 5][c + 15] = '|';

		//////////////////////INSIDE//////


		x[r + 4][c - 9] = '_';
		x[r + 4][c - 8] = '_';
		x[r + 4][c - 7] = '_';
		x[r + 4][c - 6] = '_';
		x[r + 4][c - 5] = '_';
		x[r + 4][c - 4] = '^';
		x[r + 4][c - 3] = '_';
		x[r + 4][c - 2] = '_';
		x[r + 4][c - 1] = '_';
		x[r + 4][c] = '_';
		x[r + 4][c + 1] = '_';
		x[r + 4][c + 2] = '_';
		x[r + 4][c + 3] = '_';
		x[r + 4][c + 4] = '_';
		x[r + 4][c + 5] = '_';
		x[r + 4][c + 6] = '_';
		x[r + 4][c + 7] = '_';
		x[r + 4][c + 8] = '_';
		x[r + 4][c + 9] = '_';
		x[r + 4][c + 10] = '/';


		x[r + 2][c + 5] = '\\';
		x[r + 3][c + 7] = '\\';

		x[r + 2][c + 4] = '|';
		x[r + 3][c + 4] = '|';
		x[r + 4][c + 4] = '|';


		x[r + 3][c + 3] = '/';
		x[r + 4][c + 3] = '|';

		x[r + 5][c + 2] = 191;

		x[r + 5][c + 3] = '\\';
		x[r + 6][c + 4] = 179;
		x[r + 7][c + 4] = 179;

		///////////////FACE INSIDE///

		x[r + 2][c - 3] = '_';
		x[r + 2][c - 4] = '_';
		x[r + 2][c - 5] = '_';
		x[r + 3][c - 2] = 179;
		x[r + 4][c - 2] = 179;

		x[r + 3][c - 6] = 179;
		x[r + 4][c - 6] = 179;

		x[r + 3][c - 5] = '-';
		x[r + 3][c - 4] = '-';

		x[r + 6][c - 2] = 'F';
		x[r + 6][c - 1] = 'B';
		x[r + 6][c] = 'I';
	}

}

void DynamicCar2(char x[][138], int& c, int& r, int& cH, int& rH, int& level, int& sarena, int& lose1, int& DeathT, int& Shoot1, int& ratio1, int& flagC2)
{
	if (ratio1 == 2 && c - 16 >= 0)
	{
		if (x[r][c - 20] == ' ' && x[r + 1][c - 20] == ' ' && x[r + 2][c - 20] == ' ' && x[r + 3][c - 20] == ' ' && x[r + 4][c - 20] == ' ' && x[r + 5][c - 20] == ' ' && x[r + 6][c - 20] == ' ' && x[r + 7][c - 20] == ' ' && x[r + 8][c - 20] == ' ' && x[r + 3][c - 18] == ' ' && x[r + 3][c - 17] == ' ' && x[r + 3][c - 16] == ' ' && x[r + 3][c - 15] == ' ' && x[r + 3][c - 14] == ' ' && x[r + 3][c - 13] == ' ' && x[r + 3][c - 12] == ' ' && x[r + 3][c - 11] == ' ' && x[r + 3][c - 10] == ' ' && x[r + 2][c - 8] == ' ' && x[r + 1][c - 6] == ' ' && x[r][c - 4] == ' ' && x[r][c - 3] == ' ' && x[r - 1][c - 1] == ' ' && x[r - 1][c - 2] == ' ' && x[r - 1][c] == ' ' && x[r - 1][c + 1] == ' ' && x[r - 1][c + 2] == ' ' && x[r - 1][c + 3] == ' ' && x[r][c + 4] == ' ' && x[r + 1][c + 5] == ' ' && x[r + 1][c + 6] == ' ' && x[r + 2][c + 7] == ' ' && x[r + 2][c + 8] == ' ' && x[r + 2][c + 9] == ' ' && x[r + 2][c + 10] == ' ' && x[r + 2][c + 11] == ' ' && x[r + 2][c + 12] == ' ' && x[r + 2][c + 13] == ' ' && x[r + 2][c + 14] == ' ' && x[r + 2][c + 15] == ' ')
		{

			if (sarena % 2 == 0 && flagC2 == 1)
			{
				x[r + 1][c - 1] = 219;
				x[r + 1][c - 2] = 219;

				x[r + 1][c + 1] = '_';
				x[r + 1][c + 2] = '_';


				//elgwa el3agala  LEFT
				x[r + 7][c - 11] = 179;
				x[r + 8][c - 10] = '\\';
				x[r + 8][c - 12] = ' ';

				//elgwa el3agala  RIGHT
				x[r + 7][c + 10] = 179;
				x[r + 8][c + 11] = '\\';
				x[r + 8][c + 9] = ' ';


			}
			else if (sarena % 2 != 0 && flagC2 == 1)
			{
				x[r + 1][c + 1] = 219;
				x[r + 1][c + 2] = 219;

				x[r + 1][c - 1] = '_';
				x[r + 1][c - 2] = '_';


				//elgwa el3agala  LEFT
				x[r + 7][c - 11] = ' ';
				x[r + 8][c - 10] = '\\';
				x[r + 8][c - 12] = '/';

				//elgwa el3agala  RIGHT
				x[r + 7][c + 10] = ' ';
				x[r + 8][c + 11] = '\\';
				x[r + 8][c + 9] = '/';

			}

			flagC2 = 1;
			c -= 6;

		}

		else if ((x[r][c - 20] != ' ' || x[r + 1][c - 20] != ' ' || x[r + 2][c - 20] != ' ' || x[r + 3][c - 20] != ' ' || x[r + 4][c - 20] != ' ' || x[r + 5][c - 20] != ' ' || x[r + 6][c - 20] != ' ' || x[r + 7][c - 20] != ' ' || x[r + 8][c - 20] != ' ' || x[r + 3][c - 18] != ' ' || x[r + 3][c - 17] != ' ' || x[r + 3][c - 16] != ' ' || x[r + 3][c - 15] != ' ' || x[r + 3][c - 14] != ' ' || x[r + 3][c - 13] != ' ' || x[r + 3][c - 12] != ' ' || x[r + 3][c - 11] != ' ' || x[r + 3][c - 10] != ' ' || x[r + 2][c - 8] != ' ' || x[r + 1][c - 6] != ' ' || x[r][c - 4] != ' ' || x[r][c - 3] != ' ' || x[r - 1][c - 1] != ' ' || x[r - 1][c - 2] != ' ' || x[r - 1][c] != ' ' || x[r - 1][c + 1] != ' ' || x[r - 1][c + 2] != ' ' || x[r - 1][c + 3] != ' ' || x[r][c + 4] != ' ' || x[r + 1][c + 5] != ' ' || x[r + 1][c + 6] != ' ' || x[r + 2][c + 7] != ' ' || x[r + 2][c + 8] != ' ' || x[r + 2][c + 9] != ' ' || x[r + 2][c + 10] != ' ' || x[r + 2][c + 11] != ' ' || x[r + 2][c + 12] != ' ' || x[r + 2][c + 13] != ' ' || x[r + 2][c + 14] != ' ' || x[r + 2][c + 15] == ' ') && flagC2 == 1)
		{
			flagC2 = 0;
			ratio1 = 1;
			cH -= 10;
			c = 75;
			DeathT = 4;
			Shoot1 += 2;

		}
	}

	if (c - 16 <= 0 && ratio1 == 2)
	{
		flagC2 = 0;
	}
}

void StaticPlane1(char x[][138], int r, int c, int rH, int cH, int level, int ratio)
{
	x[r][c] = '/';
	x[r - 1][c + 1] = '/';
	x[r - 2][c + 2] = '/';
	x[r - 3][c + 3] = '/';
	x[r - 4][c + 4] = '/';


	x[r - 2][c + 3] = '_';
	//x[r - 1][c + 2] = '_';
	x[r - 2][c + 4] = '/';
	x[r - 3][c + 5] = '/';
	x[r - 3][c + 4] = '_';
	x[r - 4][c + 5] = '_';


	x[r - 5][c + 4] = '_';
	x[r - 5][c + 3] = '_';
	x[r - 5][c + 2] = '_';
	x[r - 5][c + 1] = '_';
	x[r - 5][c] = '_';
	x[r - 5][c - 1] = '\\';
	x[r - 6][c - 1] = '_';
	x[r - 6][c] = '_';
	x[r - 6][c + 1] = '_';
	x[r - 6][c + 2] = '_';
	x[r - 6][c + 3] = '_';
	x[r - 6][c + 4] = '_';
	x[r - 6][c + 5] = '_';
	x[r - 6][c + 6] = '_';
	x[r - 6][c + 7] = '_';
	x[r - 6][c + 8] = '_';
	x[r - 6][c + 9] = '_';
	x[r - 6][c + 10] = '_';

	x[r - 5][c + 11] = '\\';
	x[r - 4][c + 12] = '\\';
	x[r - 3][c + 13] = '\\';
	x[r - 2][c + 14] = '\\';

	x[r - 5][c + 9] = '\\';
	x[r - 4][c + 10] = '\\';
	x[r - 3][c + 11] = '\\';
	x[r - 3][c + 12] = '_';
	x[r - 2][c + 12] = '\\';
	x[r - 1][c + 13] = '\\';

	x[r - 2][c + 15] = '/';
	x[r - 3][c + 16] = '/';
	x[r - 4][c + 17] = '/';
	x[r - 5][c + 18] = '_';
	x[r - 5][c + 19] = '_';
	x[r - 5][c + 20] = '_';

	x[r - 4][c + 21] = 179;
	x[r - 3][c + 21] = 179;
	x[r - 2][c + 21] = 179;
	x[r - 1][c + 21] = 179;
	x[r][c + 21] = 179;

	x[r][c + 20] = '_';
	x[r][c + 19] = '_';
	x[r][c + 18] = '_';
	x[r][c + 17] = '_';
	x[r][c + 16] = '_';
	x[r][c + 15] = '_';
	x[r][c + 14] = '_';
	x[r][c + 13] = '_';
	x[r][c + 12] = '_';
	x[r][c + 11] = '_';
	x[r][c + 10] = '_';
	x[r][c + 9] = '_';
	x[r][c + 8] = '_';
	x[r][c + 7] = '_';
	x[r][c + 6] = '_';
	x[r][c + 5] = '_';
	x[r][c + 4] = '_';
	x[r][c + 3] = '_';
	x[r][c + 2] = '_';
	x[r][c + 1] = '_';
	//x[r][c] = '_';
	//x[r][c - 1] = '_';
	x[r][c - 2] = '_';
	x[r][c - 3] = '_';
	x[r][c - 4] = '_';
	x[r][c - 5] = '_';
	x[r][c - 6] = '_';
	x[r][c - 7] = '_';
	x[r][c - 8] = '_';
	x[r][c - 9] = '_';
	x[r][c - 10] = '_';
	x[r][c - 11] = '_';
	x[r][c - 12] = '_';
	x[r][c - 13] = '_';
	x[r][c - 14] = '_';
	x[r][c - 15] = '_';
	x[r][c - 16] = '_';

	x[r][c - 1] = 179;
	x[r - 1][c - 1] = 179;
	x[r - 2][c - 1] = 179;

	x[r - 3][c - 2] = '_';
	x[r - 3][c - 2] = '_';
	x[r - 3][c - 3] = '_';

	x[r - 2][c - 4] = '/';
	x[r - 1][c - 5] = '/';
	x[r][c - 6] = '/';


	x[r - 1][c + 14] = '/';
	x[r][c + 13] = '/';


	x[r + 1][c - 17] = '/';
	x[r + 2][c - 18] = '/';

	x[r + 2][c - 17] = '_';
	x[r + 2][c - 16] = '_';
	x[r + 2][c - 15] = '_';
	x[r + 2][c - 14] = '_';
	x[r + 2][c - 13] = '_';
	x[r + 2][c - 12] = '_';
	x[r + 2][c - 11] = '_';
	x[r + 2][c - 10] = '_';
	x[r + 2][c - 9] = '_';
	x[r + 2][c - 8] = '_';
	x[r + 2][c - 7] = '_';
	x[r + 2][c - 6] = '_';
	x[r + 2][c - 5] = '_';
	x[r + 2][c - 4] = '_';
	x[r + 2][c - 3] = '_';
	x[r + 2][c - 2] = '_';
	x[r + 2][c - 1] = '_';
	x[r + 2][c] = '_';
	x[r + 2][c + 1] = '_';
	x[r + 2][c + 2] = '_';
	x[r + 2][c + 3] = '_';
	x[r + 2][c + 4] = '_';
	x[r + 2][c + 5] = '_';
	x[r + 2][c + 6] = '_';
	x[r + 2][c + 7] = '_';
	x[r + 2][c + 8] = '_';
	x[r + 2][c + 9] = '_';
	x[r + 2][c + 10] = '_';
	x[r + 2][c + 11] = '_';
	x[r + 2][c + 12] = '_';
	x[r + 2][c + 13] = '_';
	x[r + 2][c + 14] = '_';
	x[r + 2][c + 15] = '_';
	x[r + 2][c + 16] = '_';
	x[r + 2][c + 17] = '_';
	x[r + 2][c + 18] = '_';
	x[r + 2][c + 19] = '_';
	x[r + 2][c + 20] = '_';
	x[r + 2][c + 21] = '_';
	x[r + 2][c + 22] = '/';
	x[r + 1][c + 22] = '_';
	x[r + 1][c + 21] = 179;

	//Lower Wing
	x[r + 3][c - 6] = '\\';
	x[r + 4][c - 5] = '\\';
	x[r + 4][c - 6] = '_';
	//ROCKETING
	x[r + 5][c - 7] = 34;
	/////////////////////
	x[r + 4][c - 8] = '_';
	x[r + 4][c - 9] = '\\';
	x[r + 3][c - 9] = '_';
	x[r + 3][c - 8] = '_';
	x[r + 3][c - 7] = '_';

	x[r + 5][c - 4] = '\\';
	x[r + 5][c - 3] = '_';
	x[r + 5][c - 2] = '_';
	x[r + 5][c - 1] = 179;
	x[r + 4][c - 1] = 179;
	x[r + 3][c - 1] = 179;

	//INSIDE -->
	x[r + 1][c - 14] = '|';
	x[r + 1][c - 13] = '_';
	x[r + 1][c - 12] = '_';
	x[r + 1][c - 11] = '_';
	x[r + 1][c - 10] = '_';
	x[r + 1][c - 9] = '_';
	x[r + 1][c - 8] = '|';
	x[r + 1][c - 7] = '_';
	x[r + 1][c - 6] = '_';
	x[r + 1][c - 5] = '_';
	x[r + 1][c - 4] = '_';
	x[r + 1][c - 3] = '_';
	x[r + 1][c - 2] = '|';
	x[r + 1][c - 1] = '_';
	x[r + 1][c] = '_';
	x[r + 1][c + 1] = '/';

	//OUTSIDE --->
	x[r + 6][c] = '\\';
	x[r + 7][c + 1] = '\\';

	x[r + 6][c + 2] = '\\';
	x[r + 7][c + 3] = '\\';

	x[r + 5][c + 1] = '_';
	x[r + 7][c + 2] = '_';
	x[r + 6][c + 1] = '_';

	x[r + 7][c] = '_';
	x[r + 7][c - 1] = '_';
	x[r + 7][c - 2] = '_';
	x[r + 8][c - 2] = '\\';
	x[r + 8][c - 1] = '_';
	x[r + 8][c] = '_';
	x[r + 8][c + 1] = '_';
	x[r + 8][c + 2] = '_';
	x[r + 8][c + 3] = '_';
	x[r + 8][c + 4] = '_';
	x[r + 8][c + 5] = '_';
	x[r + 8][c + 6] = '_';
	x[r + 8][c + 7] = '_';
	x[r + 8][c + 8] = '_';

	x[r + 8][c + 9] = '/';
	x[r + 7][c + 10] = '/';
	x[r + 6][c + 11] = '/';
	x[r + 5][c + 12] = '/';
	x[r + 4][c + 13] = '/';
	x[r + 3][c + 14] = '/';

	x[r + 8][c + 7] = '/';
	x[r + 7][c + 8] = '/';
	x[r + 6][c + 9] = '/';
	x[r + 5][c + 10] = '/';
	x[r + 5][c + 11] = '_';
	x[r + 4][c + 11] = '/';
	x[r + 3][c + 12] = '/';

	x[r + 4][c + 1] = 196;
	x[r + 4][c + 2] = 196;
	x[r + 4][c + 3] = 196;
	x[r + 4][c + 4] = 196;
	x[r + 4][c + 5] = 196;
	x[r + 4][c + 6] = 196;
	x[r + 4][c + 7] = 196;
	x[r + 4][c + 8] = 196;
	x[r + 4][c + 9] = 196;

	x[r - 1][c + 5] = 196;
	x[r - 1][c + 6] = 196;
	x[r - 1][c + 7] = 196;
	x[r - 1][c + 8] = 196;
	x[r - 1][c + 9] = 196;
	x[r - 1][c + 10] = 196;

	x[r - 1][c + 7] = 'F';
	x[r - 1][c + 8] = 'B';
	x[r - 1][c + 9] = 'I';

	x[r + 4][c + 4] = 'F';
	x[r + 4][c + 5] = 'B';
	x[r + 4][c + 6] = 'I';


}

void DynamicPlane1(char x[][138], int& r1, int& c1, int& rH, int& cH, int level, int& ratio, int& c2, int& flagP2, int& c3, int& r2, int& r3)
{
	c1 -= 9;
	if (c1 < 70)
	{
		r1++;
		if (r1 <= 0)
		{
			r1 = 7;
		}
	}
	if (c1 - 10 <= 0 && ratio == 1)
	{
		ratio = 2;
		c1 = 115;
		c2 = 80;
		r1 = 7;
		r2 = 9;
	}

	if (c1 - 10 <= 0 && ratio == 2)
	{
		ratio = 3;
		c1 = 120;
		c2 = 90;
		c3 = 48;
		r1 = 7;
		r2 = 9;
		r3 = 11;
	}

	if (c1 - 10 <= 0 && ratio == 3)
	{
		ratio = 1;
		c1 = 115;
		r1 = 7;

	}
}

void StaticPlane2(char x[][138], int r, int c, int rH, int cH, int level, int ratio, int flagP2)
{
	if ((ratio == 2 || ratio == 3) && flagP2 == 1)
	{


		x[r][c] = '/';
		x[r - 1][c + 1] = '/';
		x[r - 2][c + 2] = '/';
		x[r - 3][c + 3] = '/';
		x[r - 4][c + 4] = '/';


		x[r - 2][c + 3] = '_';
		//x[r - 1][c + 2] = '_';
		x[r - 2][c + 4] = '/';
		x[r - 3][c + 5] = '/';
		x[r - 3][c + 4] = '_';
		x[r - 4][c + 5] = '_';


		x[r - 5][c + 4] = '_';
		x[r - 5][c + 3] = '_';
		x[r - 5][c + 2] = '_';
		x[r - 5][c + 1] = '_';
		x[r - 5][c] = '_';
		x[r - 5][c - 1] = '\\';
		x[r - 6][c - 1] = '_';
		x[r - 6][c] = '_';
		x[r - 6][c + 1] = '_';
		x[r - 6][c + 2] = '_';
		x[r - 6][c + 3] = '_';
		x[r - 6][c + 4] = '_';
		x[r - 6][c + 5] = '_';
		x[r - 6][c + 6] = '_';
		x[r - 6][c + 7] = '_';
		x[r - 6][c + 8] = '_';
		x[r - 6][c + 9] = '_';
		x[r - 6][c + 10] = '_';

		x[r - 5][c + 11] = '\\';
		x[r - 4][c + 12] = '\\';
		x[r - 3][c + 13] = '\\';
		x[r - 2][c + 14] = '\\';

		x[r - 5][c + 9] = '\\';
		x[r - 4][c + 10] = '\\';
		x[r - 3][c + 11] = '\\';
		x[r - 3][c + 12] = '_';
		x[r - 2][c + 12] = '\\';
		x[r - 1][c + 13] = '\\';

		x[r - 2][c + 15] = '/';
		x[r - 3][c + 16] = '/';
		x[r - 4][c + 17] = '/';
		x[r - 5][c + 18] = '_';
		x[r - 5][c + 19] = '_';
		x[r - 5][c + 20] = '_';

		x[r - 4][c + 21] = 179;
		x[r - 3][c + 21] = 179;
		x[r - 2][c + 21] = 179;
		x[r - 1][c + 21] = 179;
		x[r][c + 21] = 179;

		x[r][c + 20] = '_';
		x[r][c + 19] = '_';
		x[r][c + 18] = '_';
		x[r][c + 17] = '_';
		x[r][c + 16] = '_';
		x[r][c + 15] = '_';
		x[r][c + 14] = '_';
		x[r][c + 13] = '_';
		x[r][c + 12] = '_';
		x[r][c + 11] = '_';
		x[r][c + 10] = '_';
		x[r][c + 9] = '_';
		x[r][c + 8] = '_';
		x[r][c + 7] = '_';
		x[r][c + 6] = '_';
		x[r][c + 5] = '_';
		x[r][c + 4] = '_';
		x[r][c + 3] = '_';
		x[r][c + 2] = '_';
		x[r][c + 1] = '_';
		//x[r][c] = '_';
		//x[r][c - 1] = '_';
		x[r][c - 2] = '_';
		x[r][c - 3] = '_';
		x[r][c - 4] = '_';
		x[r][c - 5] = '_';
		x[r][c - 6] = '_';
		x[r][c - 7] = '_';
		x[r][c - 8] = '_';
		x[r][c - 9] = '_';
		x[r][c - 10] = '_';
		x[r][c - 11] = '_';
		x[r][c - 12] = '_';
		x[r][c - 13] = '_';
		x[r][c - 14] = '_';
		x[r][c - 15] = '_';
		x[r][c - 16] = '_';

		x[r][c - 1] = 179;
		x[r - 1][c - 1] = 179;
		x[r - 2][c - 1] = 179;

		x[r - 3][c - 2] = '_';
		x[r - 3][c - 2] = '_';
		x[r - 3][c - 3] = '_';

		x[r - 2][c - 4] = '/';
		x[r - 1][c - 5] = '/';
		x[r][c - 6] = '/';


		x[r - 1][c + 14] = '/';
		x[r][c + 13] = '/';


		x[r + 1][c - 17] = '/';
		x[r + 2][c - 18] = '/';

		x[r + 2][c - 17] = '_';
		x[r + 2][c - 16] = '_';
		x[r + 2][c - 15] = '_';
		x[r + 2][c - 14] = '_';
		x[r + 2][c - 13] = '_';
		x[r + 2][c - 12] = '_';
		x[r + 2][c - 11] = '_';
		x[r + 2][c - 10] = '_';
		x[r + 2][c - 9] = '_';
		x[r + 2][c - 8] = '_';
		x[r + 2][c - 7] = '_';
		x[r + 2][c - 6] = '_';
		x[r + 2][c - 5] = '_';
		x[r + 2][c - 4] = '_';
		x[r + 2][c - 3] = '_';
		x[r + 2][c - 2] = '_';
		x[r + 2][c - 1] = '_';
		x[r + 2][c] = '_';
		x[r + 2][c + 1] = '_';
		x[r + 2][c + 2] = '_';
		x[r + 2][c + 3] = '_';
		x[r + 2][c + 4] = '_';
		x[r + 2][c + 5] = '_';
		x[r + 2][c + 6] = '_';
		x[r + 2][c + 7] = '_';
		x[r + 2][c + 8] = '_';
		x[r + 2][c + 9] = '_';
		x[r + 2][c + 10] = '_';
		x[r + 2][c + 11] = '_';
		x[r + 2][c + 12] = '_';
		x[r + 2][c + 13] = '_';
		x[r + 2][c + 14] = '_';
		x[r + 2][c + 15] = '_';
		x[r + 2][c + 16] = '_';
		x[r + 2][c + 17] = '_';
		x[r + 2][c + 18] = '_';
		x[r + 2][c + 19] = '_';
		x[r + 2][c + 20] = '_';
		x[r + 2][c + 21] = '_';
		x[r + 2][c + 22] = '/';
		x[r + 1][c + 22] = '_';
		x[r + 1][c + 21] = 179;

		//Lower Wing
		x[r + 3][c - 6] = '\\';
		x[r + 4][c - 5] = '\\';
		x[r + 4][c - 6] = '_';
		//ROCKETING
		x[r + 5][c - 7] = 34;
		/////////////////////
		x[r + 4][c - 8] = '_';
		x[r + 4][c - 9] = '\\';
		x[r + 3][c - 9] = '_';
		x[r + 3][c - 8] = '_';
		x[r + 3][c - 7] = '_';

		x[r + 5][c - 4] = '\\';
		x[r + 5][c - 3] = '_';
		x[r + 5][c - 2] = '_';
		x[r + 5][c - 1] = 179;
		x[r + 4][c - 1] = 179;
		x[r + 3][c - 1] = 179;

		//INSIDE -->
		x[r + 1][c - 14] = '|';
		x[r + 1][c - 13] = '_';
		x[r + 1][c - 12] = '_';
		x[r + 1][c - 11] = '_';
		x[r + 1][c - 10] = '_';
		x[r + 1][c - 9] = '_';
		x[r + 1][c - 8] = '|';
		x[r + 1][c - 7] = '_';
		x[r + 1][c - 6] = '_';
		x[r + 1][c - 5] = '_';
		x[r + 1][c - 4] = '_';
		x[r + 1][c - 3] = '_';
		x[r + 1][c - 2] = '|';
		x[r + 1][c - 1] = '_';
		x[r + 1][c] = '_';
		x[r + 1][c + 1] = '/';

		//OUTSIDE --->
		x[r + 6][c] = '\\';
		x[r + 7][c + 1] = '\\';

		x[r + 6][c + 2] = '\\';
		x[r + 7][c + 3] = '\\';

		x[r + 5][c + 1] = '_';
		x[r + 7][c + 2] = '_';
		x[r + 6][c + 1] = '_';

		x[r + 7][c] = '_';
		x[r + 7][c - 1] = '_';
		x[r + 7][c - 2] = '_';
		x[r + 8][c - 2] = '\\';
		x[r + 8][c - 1] = '_';
		x[r + 8][c] = '_';
		x[r + 8][c + 1] = '_';
		x[r + 8][c + 2] = '_';
		x[r + 8][c + 3] = '_';
		x[r + 8][c + 4] = '_';
		x[r + 8][c + 5] = '_';
		x[r + 8][c + 6] = '_';
		x[r + 8][c + 7] = '_';
		x[r + 8][c + 8] = '_';

		x[r + 8][c + 9] = '/';
		x[r + 7][c + 10] = '/';
		x[r + 6][c + 11] = '/';
		x[r + 5][c + 12] = '/';
		x[r + 4][c + 13] = '/';
		x[r + 3][c + 14] = '/';

		x[r + 8][c + 7] = '/';
		x[r + 7][c + 8] = '/';
		x[r + 6][c + 9] = '/';
		x[r + 5][c + 10] = '/';
		x[r + 5][c + 11] = '_';
		x[r + 4][c + 11] = '/';
		x[r + 3][c + 12] = '/';

		x[r + 4][c + 1] = 196;
		x[r + 4][c + 2] = 196;
		x[r + 4][c + 3] = 196;
		x[r + 4][c + 4] = 196;
		x[r + 4][c + 5] = 196;
		x[r + 4][c + 6] = 196;
		x[r + 4][c + 7] = 196;
		x[r + 4][c + 8] = 196;
		x[r + 4][c + 9] = 196;

		x[r - 1][c + 5] = 196;
		x[r - 1][c + 6] = 196;
		x[r - 1][c + 7] = 196;
		x[r - 1][c + 8] = 196;
		x[r - 1][c + 9] = 196;
		x[r - 1][c + 10] = 196;

		x[r - 1][c + 7] = 'F';
		x[r - 1][c + 8] = 'B';
		x[r - 1][c + 9] = 'I';

		x[r + 4][c + 4] = 'F';
		x[r + 4][c + 5] = 'B';
		x[r + 4][c + 6] = 'I';

	}

}

void DynamicPlane2(char x[][138], int& r2, int& c2, int& rH, int& cH, int level, int& ratio, int& flagP2)
{
	if (ratio == 2)
	{
		if (c2 < 65)
		{
			r2++;
		}
		c2 -= 9;
		flagP2 = 1;
	}

	if (ratio == 3)
	{
		if (c2 < 45)
		{
			r2++;
		}
		c2 -= 9;
		flagP2 = 1;
	}

	if (c2 - 10 <= 0 && (ratio == 3 || ratio == 2))
	{
		flagP2 = 0;
	}

}

void StaticPlane3(char x[][138], int r, int c, int rH, int cH, int level, int ratio, int flagP22)
{
	if (ratio == 3 && flagP22 == 1)
	{


		x[r][c] = '/';
		x[r - 1][c + 1] = '/';
		x[r - 2][c + 2] = '/';
		x[r - 3][c + 3] = '/';
		x[r - 4][c + 4] = '/';


		x[r - 2][c + 3] = '_';
		//x[r - 1][c + 2] = '_';
		x[r - 2][c + 4] = '/';
		x[r - 3][c + 5] = '/';
		x[r - 3][c + 4] = '_';
		x[r - 4][c + 5] = '_';


		x[r - 5][c + 4] = '_';
		x[r - 5][c + 3] = '_';
		x[r - 5][c + 2] = '_';
		x[r - 5][c + 1] = '_';
		x[r - 5][c] = '_';
		x[r - 5][c - 1] = '\\';
		x[r - 6][c - 1] = '_';
		x[r - 6][c] = '_';
		x[r - 6][c + 1] = '_';
		x[r - 6][c + 2] = '_';
		x[r - 6][c + 3] = '_';
		x[r - 6][c + 4] = '_';
		x[r - 6][c + 5] = '_';
		x[r - 6][c + 6] = '_';
		x[r - 6][c + 7] = '_';
		x[r - 6][c + 8] = '_';
		x[r - 6][c + 9] = '_';
		x[r - 6][c + 10] = '_';

		x[r - 5][c + 11] = '\\';
		x[r - 4][c + 12] = '\\';
		x[r - 3][c + 13] = '\\';
		x[r - 2][c + 14] = '\\';

		x[r - 5][c + 9] = '\\';
		x[r - 4][c + 10] = '\\';
		x[r - 3][c + 11] = '\\';
		x[r - 3][c + 12] = '_';
		x[r - 2][c + 12] = '\\';
		x[r - 1][c + 13] = '\\';

		x[r - 2][c + 15] = '/';
		x[r - 3][c + 16] = '/';
		x[r - 4][c + 17] = '/';
		x[r - 5][c + 18] = '_';
		x[r - 5][c + 19] = '_';
		x[r - 5][c + 20] = '_';

		x[r - 4][c + 21] = 179;
		x[r - 3][c + 21] = 179;
		x[r - 2][c + 21] = 179;
		x[r - 1][c + 21] = 179;
		x[r][c + 21] = 179;

		x[r][c + 20] = '_';
		x[r][c + 19] = '_';
		x[r][c + 18] = '_';
		x[r][c + 17] = '_';
		x[r][c + 16] = '_';
		x[r][c + 15] = '_';
		x[r][c + 14] = '_';
		x[r][c + 13] = '_';
		x[r][c + 12] = '_';
		x[r][c + 11] = '_';
		x[r][c + 10] = '_';
		x[r][c + 9] = '_';
		x[r][c + 8] = '_';
		x[r][c + 7] = '_';
		x[r][c + 6] = '_';
		x[r][c + 5] = '_';
		x[r][c + 4] = '_';
		x[r][c + 3] = '_';
		x[r][c + 2] = '_';
		x[r][c + 1] = '_';
		//x[r][c] = '_';
		//x[r][c - 1] = '_';
		x[r][c - 2] = '_';
		x[r][c - 3] = '_';
		x[r][c - 4] = '_';
		x[r][c - 5] = '_';
		x[r][c - 6] = '_';
		x[r][c - 7] = '_';
		x[r][c - 8] = '_';
		x[r][c - 9] = '_';
		x[r][c - 10] = '_';
		x[r][c - 11] = '_';
		x[r][c - 12] = '_';
		x[r][c - 13] = '_';
		x[r][c - 14] = '_';
		x[r][c - 15] = '_';
		x[r][c - 16] = '_';

		x[r][c - 1] = 179;
		x[r - 1][c - 1] = 179;
		x[r - 2][c - 1] = 179;

		x[r - 3][c - 2] = '_';
		x[r - 3][c - 2] = '_';
		x[r - 3][c - 3] = '_';

		x[r - 2][c - 4] = '/';
		x[r - 1][c - 5] = '/';
		x[r][c - 6] = '/';


		x[r - 1][c + 14] = '/';
		x[r][c + 13] = '/';


		x[r + 1][c - 17] = '/';
		x[r + 2][c - 18] = '/';

		x[r + 2][c - 17] = '_';
		x[r + 2][c - 16] = '_';
		x[r + 2][c - 15] = '_';
		x[r + 2][c - 14] = '_';
		x[r + 2][c - 13] = '_';
		x[r + 2][c - 12] = '_';
		x[r + 2][c - 11] = '_';
		x[r + 2][c - 10] = '_';
		x[r + 2][c - 9] = '_';
		x[r + 2][c - 8] = '_';
		x[r + 2][c - 7] = '_';
		x[r + 2][c - 6] = '_';
		x[r + 2][c - 5] = '_';
		x[r + 2][c - 4] = '_';
		x[r + 2][c - 3] = '_';
		x[r + 2][c - 2] = '_';
		x[r + 2][c - 1] = '_';
		x[r + 2][c] = '_';
		x[r + 2][c + 1] = '_';
		x[r + 2][c + 2] = '_';
		x[r + 2][c + 3] = '_';
		x[r + 2][c + 4] = '_';
		x[r + 2][c + 5] = '_';
		x[r + 2][c + 6] = '_';
		x[r + 2][c + 7] = '_';
		x[r + 2][c + 8] = '_';
		x[r + 2][c + 9] = '_';
		x[r + 2][c + 10] = '_';
		x[r + 2][c + 11] = '_';
		x[r + 2][c + 12] = '_';
		x[r + 2][c + 13] = '_';
		x[r + 2][c + 14] = '_';
		x[r + 2][c + 15] = '_';
		x[r + 2][c + 16] = '_';
		x[r + 2][c + 17] = '_';
		x[r + 2][c + 18] = '_';
		x[r + 2][c + 19] = '_';
		x[r + 2][c + 20] = '_';
		x[r + 2][c + 21] = '_';
		x[r + 2][c + 22] = '/';
		x[r + 1][c + 22] = '_';
		x[r + 1][c + 21] = 179;

		//Lower Wing
		x[r + 3][c - 6] = '\\';
		x[r + 4][c - 5] = '\\';
		x[r + 4][c - 6] = '_';
		//ROCKETING
		x[r + 5][c - 7] = 34;
		/////////////////////
		x[r + 4][c - 8] = '_';
		x[r + 4][c - 9] = '\\';
		x[r + 3][c - 9] = '_';
		x[r + 3][c - 8] = '_';
		x[r + 3][c - 7] = '_';

		x[r + 5][c - 4] = '\\';
		x[r + 5][c - 3] = '_';
		x[r + 5][c - 2] = '_';
		x[r + 5][c - 1] = 179;
		x[r + 4][c - 1] = 179;
		x[r + 3][c - 1] = 179;

		//INSIDE -->
		x[r + 1][c - 14] = '|';
		x[r + 1][c - 13] = '_';
		x[r + 1][c - 12] = '_';
		x[r + 1][c - 11] = '_';
		x[r + 1][c - 10] = '_';
		x[r + 1][c - 9] = '_';
		x[r + 1][c - 8] = '|';
		x[r + 1][c - 7] = '_';
		x[r + 1][c - 6] = '_';
		x[r + 1][c - 5] = '_';
		x[r + 1][c - 4] = '_';
		x[r + 1][c - 3] = '_';
		x[r + 1][c - 2] = '|';
		x[r + 1][c - 1] = '_';
		x[r + 1][c] = '_';
		x[r + 1][c + 1] = '/';

		//OUTSIDE --->
		x[r + 6][c] = '\\';
		x[r + 7][c + 1] = '\\';

		x[r + 6][c + 2] = '\\';
		x[r + 7][c + 3] = '\\';

		x[r + 5][c + 1] = '_';
		x[r + 7][c + 2] = '_';
		x[r + 6][c + 1] = '_';

		x[r + 7][c] = '_';
		x[r + 7][c - 1] = '_';
		x[r + 7][c - 2] = '_';
		x[r + 8][c - 2] = '\\';
		x[r + 8][c - 1] = '_';
		x[r + 8][c] = '_';
		x[r + 8][c + 1] = '_';
		x[r + 8][c + 2] = '_';
		x[r + 8][c + 3] = '_';
		x[r + 8][c + 4] = '_';
		x[r + 8][c + 5] = '_';
		x[r + 8][c + 6] = '_';
		x[r + 8][c + 7] = '_';
		x[r + 8][c + 8] = '_';

		x[r + 8][c + 9] = '/';
		x[r + 7][c + 10] = '/';
		x[r + 6][c + 11] = '/';
		x[r + 5][c + 12] = '/';
		x[r + 4][c + 13] = '/';
		x[r + 3][c + 14] = '/';

		x[r + 8][c + 7] = '/';
		x[r + 7][c + 8] = '/';
		x[r + 6][c + 9] = '/';
		x[r + 5][c + 10] = '/';
		x[r + 5][c + 11] = '_';
		x[r + 4][c + 11] = '/';
		x[r + 3][c + 12] = '/';

		x[r + 4][c + 1] = 196;
		x[r + 4][c + 2] = 196;
		x[r + 4][c + 3] = 196;
		x[r + 4][c + 4] = 196;
		x[r + 4][c + 5] = 196;
		x[r + 4][c + 6] = 196;
		x[r + 4][c + 7] = 196;
		x[r + 4][c + 8] = 196;
		x[r + 4][c + 9] = 196;

		x[r - 1][c + 5] = 196;
		x[r - 1][c + 6] = 196;
		x[r - 1][c + 7] = 196;
		x[r - 1][c + 8] = 196;
		x[r - 1][c + 9] = 196;
		x[r - 1][c + 10] = 196;

		x[r - 1][c + 7] = 'F';
		x[r - 1][c + 8] = 'B';
		x[r - 1][c + 9] = 'I';

		x[r + 4][c + 4] = 'F';
		x[r + 4][c + 5] = 'B';
		x[r + 4][c + 6] = 'I';

	}

}

void DynamicPlane3(char x[][138], int& r3, int& c3, int& rH, int& cH, int level, int& ratio, int& flagP22)
{
	if (ratio == 3)
	{
		if (c3 < 45)
		{
			r3++;
		}
		c3 -= 9;
		flagP22 = 1;
	}
	if (c3 - 10 <= 0 && ratio == 3)
	{
		flagP22 = 0;
	}

}

void StaticPlaneShot1(char x[][138], int& rPG1, int& cPG1, int& rPG2, int& cPG2, int& rPG3, int& cPG3, int& ratio, int r1, int c1, int r2, int c2, int r3, int c3, int& shoot1, int rH, int cH, int& DeathT)
{
	if (ratio == 1)
	{

		x[rPG1][cPG1] = 219;


	}
	if (ratio == 2)
	{

		x[rPG1][cPG1] = 219;



		x[rPG2][cPG2] = 219;
		x[rPG2 + 2][cPG2] = 219;

	}
	if (ratio == 3)
	{

		x[rPG1][cPG1] = 219;



		x[rPG2][cPG2] = 219;
		x[rPG2 + 2][cPG2] = 219;

		x[rPG3 + 1][cPG3] = 219;
		x[rPG3 + 3][cPG3] = 219;
		x[rPG3 + 5][cPG3] = 219;

	}
}

void DynamicPlaneShot1(char x[][138], int& rPG1, int& cPG1, int& rPG2, int& cPG2, int& rPG3, int& cPG3, int ratio, int r1, int c1, int r2, int c2, int r3, int c3, int& shoot1, int rH, int cH, int& DeathT)
{

	if (ratio == 1)
	{

		for (int a = 0; a < 8; a++)
		{
			rPG1++;
			if ((x[rPG1 + 1][cPG1] == '\\' || x[rPG1 + 1][cPG1] == '_' || x[rPG1 + 1][cPG1] == '|' || x[rPG1 + 1][cPG1] == '/' || x[rPG1 + 1][cPG1] == '-') && cPG1 >= 0 && cPG1 <= 137)
			{
				DeathT = 5;
				shoot1 += 2;
				rPG1 = r1 + 6;
				cPG1 = c1 - 7;
			}
		}

		if (rPG1 > 40)
		{
			rPG1 = r1 + 6;
			cPG1 = c1 - 7;
		}

		/*if (x[rH + 1][cH - 2] == 254 || x[rH + 1][cH - 1] == 254 || x[rH + 1][cH] == 254 || x[rH + 1][cH + 1] == 254 || x[rH + 1][cH + 2] == 254 || x[rH + 1][cH + 3] == 254 || x[rH + 2][cH - 2] == 254 || x[rH + 2][cH - 1] == 254 || x[rH + 2][cH] == 254 || x[rH + 2][cH + 1] == 254 || x[rH + 2][cH + 2] == 254 || x[rH + 2][cH + 3] == 254 || x[rH + 3][cH - 2] == 254 || x[rH + 3][cH - 1] == 254 || x[rH + 3][cH] == 254 || x[rH + 3][cH + 1] == 254 || x[rH + 3][cH + 2] == 254 || x[rH + 3][cH + 3] == 254 || x[rH + 4][cH - 4] == 254 || x[rH + 4][cH - 3] == 254 || x[rH + 4][cH - 2] == 254 || x[rH + 4][cH - 1] == 254 || x[rH + 4][cH] == 254 || x[rH + 4][cH + 1] == 254 || x[rH + 4][cH + 2] == 254 || x[rH + 4][cH + 3] == 254 || x[rH + 4][cH + 4] == 254 || x[rH + 4][cH + 5] == 254 || x[rH + 4][cH + 6] == 254 || x[rH + 4][cH + 7] == 254 || x[rH + 5][cH - 4] == 254 || x[rH + 5][cH - 3] == 254 || x[rH + 5][cH - 2] == 254 || x[rH + 5][cH - 1] == 254 || x[rH + 5][cH] == 254 || x[rH + 5][cH + 1] == 254 || x[rH + 5][cH + 2] == 254 || x[rH + 5][cH + 3] == 254 || x[rH + 5][cH + 4] == 254 || x[rH + 5][cH + 5] == 254 || x[rH + 5][cH + 6] == 254 || x[rH + 5][cH + 7] == 254)
		{
			DeathT = 3;
			shoot1++;
			rPG1 = r1 + 6;
			cPG1 = c1 - 7;
		}*/
	}



	if (ratio == 2)
	{
		for (int a = 0; a < 8; a++)
		{
			rPG1++;
			if ((x[rPG1 + 1][cPG1] == '\\' || x[rPG1 + 1][cPG1] == '_' || x[rPG1 + 1][cPG1] == '|' || x[rPG1 + 1][cPG1] == '/' || x[rPG1 + 1][cPG1] == '-') && cPG1 >= 0 && cPG1 <= 137)
			{
				DeathT = 5;
				shoot1 += 2;
				rPG1 = r1 + 6;
				cPG1 = c1 - 7;
			}
		}

		if (rPG1 > 40)
		{
			rPG1 = r1 + 6;
			cPG1 = c1 - 7;
		}

		for (int b = 0; b < 8; b++)
		{
			rPG2++;
			if ((x[rPG2 + 3][cPG2] == '\\' || x[rPG2 + 3][cPG2] == '_' || x[rPG2 + 3][cPG2] == '|' || x[rPG2 + 3][cPG2] == '/' || x[rPG2 + 3][cPG2] == '-') && cPG2 >= 0 && cPG2 <= 137)
			{
				DeathT = 5;
				shoot1 += 3;
				rPG2 = r2 + 6;
				cPG2 = c2 - 7;
			}
		}

		if (rPG2 > 40)
		{
			rPG2 = r2 + 6;
			cPG2 = c2 - 7;
		}

	}



	if (ratio == 3)
	{
		for (int a = 0; a < 8; a++)
		{
			rPG1++;
			if ((x[rPG1 + 1][cPG1] == '\\' || x[rPG1 + 1][cPG1] == '_' || x[rPG1 + 1][cPG1] == '|' || x[rPG1 + 1][cPG1] == '/' || x[rPG1 + 1][cPG1] == '-') && cPG1 >= 0 && cPG1 <= 137)
			{
				DeathT = 5;
				shoot1 += 2;
				rPG1 = r1 + 6;
				cPG1 = c1 - 7;
			}
		}
		if (rPG1 > 40)
		{
			rPG1 = r1 + 6;
			cPG1 = c1 - 7;
		}

		for (int b = 0; b < 8; b++)
		{
			rPG2++;
			if ((x[rPG2 + 3][cPG2] == '\\' || x[rPG2 + 3][cPG2] == '_' || x[rPG2 + 3][cPG2] == '|' || x[rPG2 + 3][cPG2] == '/' || x[rPG2 + 3][cPG2] == '-') && cPG2 >= 0 && cPG2 <= 137)
			{
				DeathT = 5;
				shoot1 += 3;
				rPG2 = r2 + 6;
				cPG2 = c2 - 7;
			}
		}

		if (rPG2 > 40)
		{
			rPG2 = r2 + 6;
			cPG2 = c2 - 7;
		}

		for (int c = 0; c < 8; c++)
		{
			rPG3++;
			if ((x[rPG3 + 6][cPG3] == '\\' || x[rPG3 + 6][cPG3] == '_' || x[rPG3 + 6][cPG3] == '|' || x[rPG3 + 6][cPG3] == '/' || x[rPG3 + 6][cPG3] == '-') && cPG3 >= 0 && cPG3 <= 137)
			{
				DeathT = 5;
				shoot1 += 3;
				rPG3 = r3 + 6;
				cPG3 = c3 - 7;
			}
		}
		if (rPG3 > 40)
		{
			rPG3 = r3 + 6;
			cPG3 = c3 - 7;
		}

	}
}

void StaticSkate(char x[][138], int r, int c, int rH, int cH, int& SkateIn)
{


	if (cH < 35 && SkateIn == 0)
	{


		x[r][c - 8] = '_';
		x[r][c - 7] = '_';
		x[r][c - 6] = '_';
		x[r][c - 5] = '_';
		x[r][c - 4] = '_';
		x[r][c - 3] = '_';
		x[r][c - 2] = '_';
		x[r][c - 1] = '_';
		x[r][c] = '_';
		x[r][c + 1] = '_';
		x[r][c + 2] = '_';
		x[r][c + 3] = '_';
		x[r][c + 4] = '_';
		x[r][c + 5] = '_';
		x[r][c + 6] = '_';
		x[r][c + 7] = '_';
		x[r][c + 8] = '_';

		x[r][c - 9] = '\\';
		x[r - 1][c - 10] = '_';
		x[r][c - 11] = 179;
		x[r + 1][c - 10] = '\\';
		x[r + 1][c - 9] = '_';
		x[r + 1][c - 8] = '_';
		x[r + 1][c - 7] = '_';
		x[r + 2][c - 6] = '\\';
		x[r + 2][c - 5] = '_';
		x[r + 2][c - 4] = '/';
		x[r + 1][c - 3] = '_';
		x[r + 1][c - 2] = '|';
		x[r + 1][c - 1] = '_';
		x[r + 1][c] = '_';
		x[r + 1][c + 1] = '_';
		x[r + 1][c + 2] = '|';
		x[r + 1][c + 3] = '_';
		x[r + 2][c + 4] = '\\';
		x[r + 2][c + 5] = '_';
		x[r + 2][c + 6] = '/';
		x[r + 1][c + 7] = '_';
		x[r + 1][c + 8] = '_';
		x[r + 1][c + 9] = '_';
		x[r][c + 9] = '/';
		x[r - 1][c + 10] = '_';
		x[r][c + 11] = 179;
		x[r + 1][c + 10] = '/';

		if (cH < 24 && SkateIn == 0)
		{
			x[r - 1][c - 5] = 'S';
			x[r - 1][c - 4] = 'K';
			x[r - 1][c - 3] = 'A';
			x[r - 1][c - 2] = 'T';
			x[r - 1][c - 1] = 'E';
			x[r - 1][c] = ' ';
			x[r - 1][c + 1] = 'B';
			x[r - 1][c + 2] = 'O';
			x[r - 1][c + 3] = 'A';
			x[r - 1][c + 4] = 'R';
			x[r - 1][c + 5] = 'D';



		}

		if (cH >= 24 && rH == 36 && SkateIn == 0)
		{
			x[rH - 1][cH + 6] = 'T';
			x[rH - 1][cH + 7] = 'A';
			x[rH - 1][cH + 8] = 'P';
			x[rH - 1][cH + 9] = ' ';
			x[rH - 1][cH + 10] = 'E';
			x[rH - 1][cH + 11] = ' ';
			x[rH - 1][cH + 12] = 'T';
			x[rH - 1][cH + 13] = 'O';
			x[rH - 1][cH + 14] = ' ';
			x[rH - 1][cH + 15] = 'E';
			x[rH - 1][cH + 16] = 'Q';
			x[rH - 1][cH + 17] = 'U';
			x[rH - 1][cH + 18] = 'I';
			x[rH - 1][cH + 19] = 'P';
		}
	}

	if (SkateIn == 1)
	{


		x[r][c - 8] = '_';
		x[r][c - 7] = '_';
		x[r][c - 6] = '_';
		x[r][c - 5] = '_';
		x[r][c - 4] = '_';
		x[r][c - 3] = '_';
		x[r][c - 2] = '_';
		x[r][c - 1] = '_';
		x[r][c] = '_';
		x[r][c + 1] = '_';
		x[r][c + 2] = '_';
		x[r][c + 3] = '_';
		x[r][c + 4] = '_';
		x[r][c + 5] = '_';
		x[r][c + 6] = '_';
		x[r][c + 7] = '_';
		x[r][c + 8] = '_';

		x[r][c - 9] = '\\';
		x[r - 1][c - 10] = '_';
		x[r][c - 11] = 179;
		x[r + 1][c - 10] = '\\';
		x[r + 1][c - 9] = '_';
		x[r + 1][c - 8] = '_';
		x[r + 1][c - 7] = '_';
		x[r + 2][c - 6] = '\\';
		x[r + 2][c - 5] = '_';
		x[r + 2][c - 4] = '/';
		x[r + 1][c - 3] = '_';
		x[r + 1][c - 2] = '|';
		x[r + 1][c - 1] = '_';
		x[r + 1][c] = '_';
		x[r + 1][c + 1] = '_';
		x[r + 1][c + 2] = '|';
		x[r + 1][c + 3] = '_';
		x[r + 2][c + 4] = '\\';
		x[r + 2][c + 5] = '_';
		x[r + 2][c + 6] = '/';
		x[r + 1][c + 7] = '_';
		x[r + 1][c + 8] = '_';
		x[r + 1][c + 9] = '_';
		x[r][c + 9] = '/';
		x[r - 1][c + 10] = '_';
		x[r][c + 11] = 179;
		x[r + 1][c + 10] = '/';
	}

}

void CheckTrap(char x[][138], int& rH, int& cH, int& DeathT, int& shoot1, int& rR, int& cR, int& RopeIn, int& tap4)
{
	if (RopeIn == 0 && x[rH + 11][cH - 2] == '/' || x[rH + 11][cH - 2] == '\\' || x[rH + 11][cH - 1] == '/' || x[rH + 11][cH - 1] == '\\' || x[rH + 11][cH] == '/' || x[rH + 11][cH] == '\\' || x[rH + 11][cH + 1] == '/' || x[rH + 11][cH + 1] == '\\' || x[rH + 11][cH + 2] == '/' || x[rH + 11][cH + 2] == '\\' || x[rH + 11][cH + 3] == '/' || x[rH + 11][cH + 3] == '\\' || x[rH + 11][cH + 4] == '/' || x[rH + 11][cH + 4] == '\\')
	{

		shoot1 += 4;
		rH -= 14;
		DeathT = 6;
		cH -= 5;

	}

	if (cH > (cR - 16) && cH < (cR + 4) && RopeIn == 0)
	{
		x[rH - 1][cH + 6] = 'T';
		x[rH - 1][cH + 7] = 'A';
		x[rH - 1][cH + 8] = 'P';
		x[rH - 1][cH + 9] = ' ';
		x[rH - 1][cH + 10] = 'E';
		x[rH - 1][cH + 11] = ' ';
		x[rH - 1][cH + 12] = 'T';
		x[rH - 1][cH + 13] = 'O';
		x[rH - 1][cH + 14] = ' ';
		x[rH - 1][cH + 15] = 'R';
		x[rH - 1][cH + 16] = 'I';
		x[rH - 1][cH + 17] = 'D';
		x[rH - 1][cH + 18] = 'E';
		tap4 = 1;
	}
	else
	{
		tap4 = 0;
	}
}

void MyStaticShot(char x[][138], int rH, int cH, int& rMS1, int& cMS1, int& rMS2, int& cMS2, int countRLHL1, int& countMyShot, int& ClickShot, int& WhichShot, int &rB)
{

	if (countRLHL1 % 2 == 0 && ClickShot >= 1)
	{
		x[rMS1 + 5][cMS1 + 14] = 22;
		x[rH + 6][cH + 12] = '1';
	}
	else if (countRLHL1 % 2 != 0 && ClickShot >= 1)
	{
		x[rMS1 + 6][cMS1 + 13] = 22;
		x[rH + 7][cH + 11] = '1';
	}


	if (countRLHL1 % 2 == 0 && ClickShot == 2)
	{
		x[rMS2 + 5][cMS2 + 14] = 22;
		x[rH + 6][cH + 12] = '0';

	}
	else if (countRLHL1 % 2 != 0 && ClickShot == 2)
	{
		x[rMS2 + 6][cMS2 + 13] = 22;
		x[rH + 7][cH + 11] = '0';

	}


}

void MyDynamicShot(char x[][138], int rH, int cH, int& rMS1, int& cMS1, int& rMS2, int& cMS2, int countRLHL1, int& countMyShot, int& ClickShot, int& Reload, int& ReloadAction, int& rB, int& ct, int& gotshot, int cBB, int rBB, int& WhichShot)
{


	if (cMS1 + 20 <= 137 && ClickShot >= 1)
	{
		for (int a = 0; a < 16; a++)
		{
			cMS1++;

			if (x[rMS1 + 5][cMS1 + 15] != ' ' && rMS1 + 5 >= rBB + 1 && rMS1 + 5 < rBB + 6 && cMS1 >= 0 && cMS1 <= 137)
			{
				x[28][83] = 'H';
				x[28][84] = 'E';
				x[28][85] = 'A';
				x[28][86] = 'D';
				x[28][87] = 'S';
				x[28][88] = 'H';
				x[28][89] = 'O';
				x[28][90] = 'T';
				x[28][91] = '!';

				gotshot += 2;
				cMS1 = 138;
				rMS1 = 46;
			}

			if (x[rMS1 + 5][cMS1 + 15] != ' ' && rMS1 + 5 >= 34 && rMS1 + 5 <= 40 && cMS1 >= 0 && cMS1 <= 137)
			{
				gotshot += 1;
				cMS1 = 137;
				rMS1 = 46;
			}

		}


	}
	else if (cMS1 + 20 > 137 && ClickShot >= 1)
	{
		cMS1 = 137;
		rMS1 = 46;

	}


	if (ClickShot >= 1)
	{

		if (countRLHL1 % 2 == 0)
		{
			x[rH + 6][cH + 12] = '1';
		}
		else
		{
			x[rH + 7][cH + 11] = '1';
		}
	}

	if (cMS2 + 20 <= 137 && ClickShot == 2)
	{
		for (int a = 0; a < 16; a++)
		{
			cMS2++;

			if (x[rMS2 + 5][cMS2 + 15] != ' ' && rMS2 + 5 >= rBB + 1 && rMS2 + 5 < rBB + 6 && cMS2 >= 0 && cMS2 <= 137)
			{
				x[28][83] = 'H';
				x[28][84] = 'E';
				x[28][85] = 'A';
				x[28][86] = 'D';
				x[28][87] = 'S';
				x[28][88] = 'H';
				x[28][89] = 'O';
				x[28][90] = 'T';
				x[28][91] = '!';
				gotshot += 2;
				cMS2 = 138;
				rMS2 = 46;
			}

			if (x[rMS2 + 5][cMS2 + 15] != ' ' && rMS2 + 5 >= 34 && rMS2 + 5 <= 40 && cMS2 >= 0 && cMS2 <= 137)
			{
				gotshot += 1;
				cMS2 = 137;
				rMS2 = 46;
			}
		}

	}
	else if (cMS2 + 20 > 137 && ClickShot == 2)
	{
		cMS2 = 137;
		rMS2 = 46;

	}



	if (ClickShot == 2)
	{

		Reload = 1;

		if (countRLHL1 % 2 == 0)
		{
			x[rH + 6][cH + 12] = '0';
		}
		else
		{
			x[rH + 7][cH + 11] = '0';
		}
		//ReloadAction = 2;

		if (ct >= 2)
		{
			ReloadAction = 2;
		}


	}

	if (cMS2 + 20 > 137 && ClickShot == 2)
	{
		ClickShot = 0;
		Reload = 0;
		ReloadAction = 1;

		if (countRLHL1 % 2 == 0)
		{
			x[rH + 6][cH + 12] = '2';
		}
		else
		{
			x[rH + 7][cH + 11] = '2';
		}
		//Reload = 0;
	}











}

void StaticBigBoss(char x[][138], int rH, int cH, int r, int c, int win)
{
	if (win == 0)
	{
		x[r][c - 3] = '_';
		x[r][c - 5] = '/';
		x[r - 1][c - 4] = '_';
		x[r - 1][c - 3] = '_';
		x[r - 1][c - 2] = '_';
		x[r - 1][c - 1] = '_';
		x[r - 1][c] = '_';
		x[r - 1][c + 1] = '_';
		x[r - 1][c + 2] = '_';
		x[r - 1][c + 3] = '_';
		x[r - 1][c + 4] = '_';
		x[r][c + 5] = '\\';
		x[r + 1][c + 4] = '\\';
		x[r + 1][c + 5] = '/';


		x[r + 1][c - 4] = '/';
		x[r + 1][c - 5] = '\\';
		x[r][c - 4] = '_';
		x[r][c - 3] = '_';
		x[r][c - 2] = '_';
		x[r][c - 1] = '7';
		x[r][c] = '7';
		x[r][c + 1] = '7';
		x[r][c + 2] = '_';
		x[r][c + 3] = '_';
		x[r][c + 4] = '_';

		x[r + 2][c - 4] = '|';
		x[r + 3][c - 4] = '|';
		x[r + 4][c - 4] = '|';
		x[r + 2][c + 4] = '|';
		x[r + 3][c + 4] = '|';
		x[r + 4][c + 4] = '|';

		x[r + 5][c - 4] = '\\';
		x[r + 5][c - 3] = '_';
		x[r + 5][c - 2] = '_';
		x[r + 5][c - 1] = '_';
		x[r + 5][c] = '_';
		x[r + 5][c + 1] = '_';
		x[r + 5][c + 2] = '_';
		x[r + 5][c + 3] = '_';
		x[r + 5][c + 4] = '/';

		x[r + 2][c - 2] = '_';
		x[r + 2][c + 1] = '_';

		x[r + 3][c - 1] = '_';
		x[r + 4][c - 2] = 179;
		//x[r + 4][c - 1] = '/';
		x[r + 4][c] = 179;

		x[r + 6][c + 3] = '/';
		x[r + 6][c + 4] = '_';
		x[r + 6][c - 3] = '/';
		x[r + 6][c - 4] = '_';
		x[r + 6][c - 4] = '_';
		x[r + 6][c - 5] = '_';
		x[r + 10][c - 4] = '|';
		x[r + 9][c - 4] = '|';
		x[r + 9][c - 5] = '_';
		x[r + 9][c - 6] = '_';
		x[r + 9][c - 7] = '_';
		x[r + 9][c - 8] = '_';
		x[r + 9][c - 9] = '_';
		x[r + 9][c - 10] = '_';
		x[r + 9][c - 11] = '_';
		x[r + 11][c - 4] = '|';
		x[r + 12][c - 4] = '|';
		x[r + 10][c + 4] = '|';
		x[r + 9][c + 4] = '|';
		x[r + 11][c + 4] = '|';
		x[r + 12][c + 4] = '|';
		//x[r + 12][c - 3] = '_';		
		//x[r + 12][c - 2] = '_';		
		//x[r + 12][c - 1] = '_';		
		//x[r + 12][c] = '_';		
		//x[r + 12][c + 1] = '_';		
		//x[r + 12][c + 2] = '_';		
		//x[r + 12][c + 3] = '_';		

		x[r + 7][c - 6] = '/';
		x[r + 7][c - 7] = '_';
		x[r + 7][c - 8] = '_';
		x[r + 7][c - 9] = '_';
		x[r + 7][c - 10] = '_';
		x[r + 7][c - 11] = '/';
		x[r + 6][c - 10] = '/';
		x[r + 5][c - 9] = '_';
		x[r + 6][c - 8] = 179;
		x[r + 6][c - 7] = '_';
		x[r + 6][c - 6] = 179;
		x[r + 5][c - 6] = 179;
		x[r + 4][c - 7] = '_';
		x[r + 4][c - 8] = '_';
		x[r + 4][c - 9] = '_';
		x[r + 4][c - 10] = '_';
		x[r + 4][c - 11] = '_';
		x[r + 5][c - 12] = '/';
		x[r + 6][c - 13] = '/';
		x[r + 7][c - 14] = '/';
		x[r + 7][c - 15] = '_';
		x[r + 7][c - 16] = '_';
		x[r + 7][c - 17] = '_';
		x[r + 7][c - 18] = '_';
		x[r + 7][c - 19] = '_';
		x[r + 7][c - 20] = '_';
		x[r + 7][c - 21] = '_';
		x[r + 7][c - 22] = '_';
		x[r + 7][c - 23] = '\\';
		x[r + 7][c - 24] = '/';
		x[r + 7][c - 25] = '_';
		x[r + 7][c - 26] = '_';
		x[r + 7][c - 27] = '_';
		x[r + 8][c - 27] = 179;
		x[r + 9][c - 27] = 179;
		x[r + 7][c - 28] = '_';
		x[r + 7][c - 29] = '_';
		x[r + 7][c - 30] = '_';
		x[r + 8][c - 31] = '|';
		x[r + 9][c - 31] = '|';
		x[r + 9][c - 30] = '_';
		x[r + 9][c - 29] = '_';
		x[r + 9][c - 28] = '_';
		x[r + 9][c - 27] = 179;
		x[r + 9][c - 26] = '_';
		x[r + 9][c - 25] = '_';
		x[r + 9][c - 24] = '_';
		x[r + 9][c - 23] = '_';
		x[r + 9][c - 22] = '_';
		x[r + 9][c - 21] = '_';
		x[r + 9][c - 20] = '_';
		x[r + 9][c - 19] = '_';
		x[r + 9][c - 18] = '_';
		x[r + 9][c - 17] = '_';
		x[r + 9][c - 16] = '_';
		x[r + 9][c - 15] = '_';
		x[r + 9][c - 14] = '_';
		x[r + 9][c - 13] = '/';
		x[r + 8][c - 12] = '_';
		x[r + 9][c - 12] = ' ';
		x[r + 9][c - 11] = '\\';
		x[r + 10][c - 28] = '|';
		x[r + 10][c - 27] = '_';
		x[r + 10][c - 26] = '_';
		x[r + 10][c - 25] = '_';
		x[r + 10][c - 24] = 179;
		x[r + 10][c - 23] = '_';
		x[r + 10][c - 22] = '_';
		x[r + 10][c - 21] = '_';
		x[r + 10][c - 20] = '_';
		x[r + 10][c - 19] = '_';
		x[r + 10][c - 18] = '_';
		x[r + 10][c - 17] = '_';
		x[r + 10][c - 16] = '_';
		x[r + 10][c - 15] = '_';
		x[r + 10][c - 14] = '_';
		x[r + 10][c - 13] = '_';
		x[r + 10][c - 12] = '_';
		x[r + 10][c - 11] = '_';
		x[r + 10][c - 10] = '_';
		x[r + 10][c - 9] = '_';
		x[r + 10][c - 8] = '|';

		x[r + 12][c - 5] = '/';
		x[r + 12][c - 6] = '_';
		x[r + 12][c - 7] = '_';
		x[r + 12][c - 8] = '_';
		x[r + 12][c - 9] = '_';
		x[r + 12][c - 10] = '\\';
		x[r + 11][c - 11] = '\\';


		x[r + 10][c - 6] = '/';
		x[r + 11][c - 7] = '/';
		x[r + 11][c - 8] = '\\';

		x[r + 13][c - 4] = '/';
		x[r + 14][c - 5] = '/';
		x[r + 15][c - 6] = '/';
		x[r + 16][c - 7] = '/';
		x[r + 17][c - 7] = '|';
		x[r + 18][c - 7] = '|';
		x[r + 18][c - 6] = '_';
		x[r + 18][c - 5] = '_';
		x[r + 18][c - 4] = '|';
		x[r + 17][c - 4] = '|';
		x[r + 16][c - 4] = '/';
		x[r + 15][c - 3] = '/';
		x[r + 14][c - 2] = '/';
		x[r + 13][c - 1] = '/';

		x[r + 13][c] = '\\';
		x[r + 14][c + 1] = '\\';
		x[r + 15][c + 2] = '\\';
		x[r + 16][c + 3] = '\\';
		x[r + 17][c + 4] = '\\';
		x[r + 18][c + 5] = '\\';
		x[r + 18][c + 6] = '_';
		x[r + 18][c + 7] = '_';
		x[r + 18][c + 8] = '\\';
		x[r + 17][c + 7] = '\\';
		x[r + 16][c + 6] = '\\';
		x[r + 15][c + 5] = '\\';
		x[r + 14][c + 4] = '\\';
		x[r + 13][c + 4] = '|';



	}

}

void StaticBigBossShot(char x[][138], int rH, int cH, int r1, int c1, int r2, int c2, int when)
{
	if (when == 0)
	{
		x[r1][c1] = 219;
		x[r1 + 1][c1] = 219;
		x[r1][c1 - 1] = 219;
		x[r1 + 1][c1 - 1] = 219;

		x[r1][c1 - 3] = 219;
		x[r1 + 1][c1 - 3] = 219;
		x[r1][c1 - 4] = 219;
		x[r1 + 1][c1 - 4] = 219;
	}


	if (when == 1)
	{
		x[r2][c2] = 219;
		x[r2][c2 - 1] = 219;
	}
}

void DynamicBigBossShot(char x[][138], int rH, int& cH, int& r1, int& c1, int& r2, int& c2, int& DeathT, int& shoot1, int rBB, int& cBB, int& when)
{


	for (int z = 0; z < 14; z++)
	{
		if (when == 0)
		{
			c1--;

			if (x[r1][c1 - 5] != ' ' || x[r1 + 1][c1 - 5] != ' ')
			{
				cBB -= 4;
				shoot1 += 2;
				DeathT = 7;
				r1 = rBB + 8;
				c1 = cBB - 32;
				when = 1;
				cH -= 2;
			}
			if (c1 - 5 <= 0)
			{
				cBB++;
				r1 = rBB + 8;
				c1 = cBB - 32;
				when = 1;

			}
		}
	}

	for (int y = 0; y < 14; y++)
	{
		if (when == 1)
		{
			c2--;

			if (x[r2][c2 - 2] != ' ')
			{
				cBB -= 4;
				shoot1++;
				DeathT = 7;
				r2 = rBB + 10;
				c2 = cBB - 29;
				when = 0;
				cH -= 2;
			}
			if (c2 - 2 <= 0)
			{
				cBB++;
				r2 = rBB + 10;
				c2 = cBB - 29;
				when = 0;
			}

		}
	}

}

void Telepherique(char x[][138], int rH, int cH, int r, int c, int& cFC)
{
	x[20][8] = 179;
	x[21][8] = 179;
	x[22][8] = 179;
	x[23][8] = 179;
	x[24][8] = 179;
	x[25][8] = 179;
	x[26][8] = 179;
	x[27][8] = 179;

	x[20][7] = '_';
	x[20][6] = '_';
	x[21][5] = 179;
	x[22][5] = 179;
	x[22][6] = '_';
	x[22][7] = '_';
	x[23][5] = 179;
	x[24][5] = 179;
	x[24][6] = '_';
	x[24][7] = '_';

	for (int a = 9; a <= 137; a++)
	{
		x[27][a] = '_';
	}





	x[20][c + 1] = 179;
	x[21][c + 1] = 179;
	x[22][c + 1] = 179;
	x[23][c + 1] = 179;
	x[24][c + 1] = 179;
	x[25][c + 1] = 179;
	x[26][c + 1] = 179;
	x[27][c + 1] = 179;
	x[28][c + 1] = 179;
	x[29][c + 1] = 179;

	x[20][c] = 179;
	x[21][c] = 179;
	x[22][c] = 179;
	x[23][c] = 179;
	x[24][c] = 179;
	x[25][c] = 179;
	x[26][c] = 179;
	x[27][c] = 179;
	x[28][c] = 179;
	x[29][c] = 179;

	x[r + 2][c - 1] = '_';
	x[r + 2][c - 2] = '_';
	x[r + 2][c - 3] = '_';
	//x[29][13] = '_';
	x[r + 2][c + 2] = '_';
	x[r + 2][c + 3] = '_';
	x[r + 2][c + 4] = '_';
	x[r + 3][c + 5] = '\\';
	x[r + 3][c - 4] = '/';

	x[21][11] = 'T';
	x[21][12] = 'e';
	x[21][13] = 'l';
	x[21][14] = 'e';
	x[21][15] = 'p';
	x[21][16] = 'h';
	x[21][17] = 'e';
	x[21][18] = 'r';
	x[21][19] = 'i';
	x[21][20] = 'q';
	x[21][21] = 'u';
	x[21][22] = 'e';



}

void MapFS(char z[][138], int counter, int timerFS)
{

	for (int r = 0; r < 48; r++)
	{
		for (int c = 0; c < 138; c++)
		{
			z[r][c] = ' ';
		}
	}

	/*for (int i = 47,k=10; i >= 0; i--,k++)
	{
		z[i][k] = 177;
	}

	for (int j = 47, l = 127; j >= 0; j--, l--)
	{
		z[j][l] = 177;
	}*/

	if (counter % 2 == 0)
	{
		for (int i = 47, k = 10; i >= 0; i--, k++)
		{
			z[i][k] = 177;
		}

		for (int j = 47, l = 127; j >= 0; j--, l--)
		{
			z[j][l] = 177;
		}

		if (timerFS <= 15)
		{
			for (int m = 0; m <= 47; m += 2)
			{
				z[m][69] = 186;
			}
		}
		else
		{
			for (int m = 0; m <= 47; m += 2)
			{
				z[m][69] = 186;
			}
		}
	}

	else
	{

		for (int i = 47, k = 11; i >= 0; i--, k++)
		{
			z[i][k] = 177;
		}

		for (int j = 47, l = 128; j >= 0; j--, l--)
		{
			z[j][l] = 177;
		}

		if (timerFS <= 15)
		{
			for (int m = 1; m <= 47; m += 2)
			{
				z[m][69] = 186;
			}
		}
		else
		{
			for (int m = 0; m <= 47; m += 2)
			{
				z[m][69] = 186;
			}
		}
	}

	if (timerFS >= 10)
	{
		z[0][1] = 'P';
		z[0][2] = 'r';
		z[0][3] = 'e';
		z[0][4] = 's';
		z[0][5] = 's';
		z[0][6] = ' ';
		z[0][7] = 'a';
		z[0][8] = 'n';
		z[0][9] = 'y';
		z[0][10] = ' ';
		z[0][11] = 'k';
		z[0][12] = 'e';
		z[0][13] = 'y';
		z[0][14] = ' ';
		z[0][15] = 't';
		z[0][16] = 'o';
		z[0][17] = ' ';
		z[0][18] = 's';
		z[0][19] = 'k';
		z[0][20] = 'i';
		z[0][21] = 'p';
	}
}

void SObjectsFS1(char z[][138], int rO1, int rO2, int rO3, int rO4, int rO5, int cO1, int cO2, int cO3, int cO4, int cO5)
{
	//tree = 186 176
	//light = 179 22




	{
		z[rO2 + 21][cO2] = 186;
		z[rO2 + 20][cO2] = 186;
		z[rO2 + 19][cO2] = 186;
		z[rO2 + 18][cO2] = 186;
		z[rO2 + 17][cO2] = 186;
		z[rO2 + 16][cO2] = 186;
		z[rO2 + 15][cO2] = 186;
		z[rO2 + 14][cO2] = 186;
		z[rO2 + 13][cO2] = 186;

		z[rO2 + 13][cO2 - 8] = 176;
		z[rO2 + 13][cO2 - 7] = 176;
		z[rO2 + 13][cO2 - 6] = 176;
		z[rO2 + 13][cO2 - 5] = 176;
		z[rO2 + 13][cO2 - 4] = 176;
		z[rO2 + 13][cO2 - 3] = 176;
		z[rO2 + 13][cO2 - 2] = 176;
		z[rO2 + 13][cO2 - 1] = 176;
		z[rO2 + 13][cO2] = 176;
		z[rO2 + 13][cO2 + 1] = 176;
		z[rO2 + 13][cO2 + 2] = 176;
		z[rO2 + 13][cO2 + 3] = 176;
		z[rO2 + 13][cO2 + 4] = 176;
		z[rO2 + 13][cO2 + 5] = 176;
		z[rO2 + 13][cO2 + 6] = 176;
		z[rO2 + 13][cO2 + 7] = 176;
		z[rO2 + 13][cO2 + 8] = 176;

		z[rO2 + 12][cO2 - 7] = 176;
		z[rO2 + 12][cO2 - 6] = 176;
		z[rO2 + 12][cO2 - 5] = 176;
		z[rO2 + 12][cO2 - 4] = 176;
		z[rO2 + 12][cO2 - 3] = 176;
		z[rO2 + 12][cO2 - 2] = 176;
		z[rO2 + 12][cO2 - 1] = 176;
		z[rO2 + 12][cO2] = 176;
		z[rO2 + 12][cO2 + 1] = 176;
		z[rO2 + 12][cO2 + 2] = 176;
		z[rO2 + 12][cO2 + 3] = 176;
		z[rO2 + 12][cO2 + 4] = 176;
		z[rO2 + 12][cO2 + 5] = 176;
		z[rO2 + 12][cO2 + 6] = 176;
		z[rO2 + 12][cO2 + 7] = 176;

		z[rO2 + 11][cO2 - 6] = 176;
		z[rO2 + 11][cO2 - 5] = 176;
		z[rO2 + 11][cO2 - 4] = 176;
		z[rO2 + 11][cO2 - 3] = 176;
		z[rO2 + 11][cO2 - 2] = 176;
		z[rO2 + 11][cO2 - 1] = 176;
		z[rO2 + 11][cO2] = 176;
		z[rO2 + 11][cO2 + 1] = 176;
		z[rO2 + 11][cO2 + 2] = 176;
		z[rO2 + 11][cO2 + 3] = 176;
		z[rO2 + 11][cO2 + 4] = 176;
		z[rO2 + 11][cO2 + 5] = 176;
		z[rO2 + 11][cO2 + 6] = 176;

		z[rO2 + 10][cO2 - 5] = 176;
		z[rO2 + 10][cO2 - 4] = 176;
		z[rO2 + 10][cO2 - 3] = 176;
		z[rO2 + 10][cO2 - 2] = 176;
		z[rO2 + 10][cO2 - 1] = 176;
		z[rO2 + 10][cO2] = 176;
		z[rO2 + 10][cO2 + 1] = 176;
		z[rO2 + 10][cO2 + 2] = 176;
		z[rO2 + 10][cO2 + 3] = 176;
		z[rO2 + 10][cO2 + 4] = 176;
		z[rO2 + 10][cO2 + 5] = 176;

		z[rO2 + 9][cO2 - 4] = 176;
		z[rO2 + 9][cO2 - 3] = 176;
		z[rO2 + 9][cO2 - 2] = 176;
		z[rO2 + 9][cO2 - 1] = 176;
		z[rO2 + 9][cO2] = 176;
		z[rO2 + 9][cO2 + 1] = 176;
		z[rO2 + 9][cO2 + 2] = 176;
		z[rO2 + 9][cO2 + 3] = 176;
		z[rO2 + 9][cO2 + 4] = 176;

		z[rO2 + 8][cO2 - 3] = 176;
		z[rO2 + 8][cO2 - 2] = 176;
		z[rO2 + 8][cO2 - 1] = 176;
		z[rO2 + 8][cO2] = 176;
		z[rO2 + 8][cO2 + 1] = 176;
		z[rO2 + 8][cO2 + 2] = 176;
		z[rO2 + 8][cO2 + 3] = 176;

		z[rO2 + 7][cO2 - 2] = 176;
		z[rO2 + 7][cO2 - 1] = 176;
		z[rO2 + 7][cO2] = 176;
		z[rO2 + 7][cO2 + 1] = 176;
		z[rO2 + 7][cO2 + 2] = 176;

		z[rO2 + 6][cO2 - 1] = 176;
		z[rO2 + 6][cO2] = 176;
		z[rO2 + 6][cO2 + 1] = 176;

		z[rO2 + 5][cO2] = 176;
	}



	{

		z[rO3 + 21][cO3] = 179;
		z[rO3 + 20][cO3] = 179;
		z[rO3 + 19][cO3] = 179;
		z[rO3 + 18][cO3] = 179;
		z[rO3 + 17][cO3] = 179;
		z[rO3 + 16][cO3] = 179;
		z[rO3 + 15][cO3] = 179;
		z[rO3 + 14][cO3] = 179;
		z[rO3 + 13][cO3] = 179;
		z[rO3 + 12][cO3] = 179;
		z[rO3 + 11][cO3] = 179;
		z[rO3 + 10][cO3] = 179;
		z[rO3 + 9][cO3] = 179;
		z[rO3 + 8][cO3] = 179;
		z[rO3 + 7][cO3] = 179;
		z[rO3 + 6][cO3] = 179;
		z[rO3 + 5][cO3] = 179;

		z[rO3 + 5][cO3 - 1] = 22;
	}


	{

		z[rO4 + 21][cO4] = 179;
		z[rO4 + 20][cO4] = 179;
		z[rO4 + 19][cO4] = 179;
		z[rO4 + 18][cO4] = 179;
		z[rO4 + 17][cO4] = 179;
		z[rO4 + 16][cO4] = 179;
		z[rO4 + 15][cO4] = 179;
		z[rO4 + 14][cO4] = 179;
		z[rO4 + 13][cO4] = 179;
		z[rO4 + 12][cO4] = 179;
		z[rO4 + 11][cO4] = 179;
		z[rO4 + 10][cO4] = 179;
		z[rO4 + 9][cO4] = 179;

		z[rO4 + 8][cO4] = 179;
		z[rO4 + 7][cO4] = 179;
		z[rO4 + 6][cO4] = 179;
		z[rO4 + 5][cO4] = 179;
		z[rO4 + 5][cO4 - 1] = 22;
	}


	{

		z[rO5 + 21][cO5] = 186;
		z[rO5 + 20][cO5] = 186;
		z[rO5 + 19][cO5] = 186;
		z[rO5 + 18][cO5] = 186;
		z[rO5 + 17][cO5] = 186;
		z[rO5 + 16][cO5] = 186;
		z[rO5 + 15][cO5] = 186;
		z[rO5 + 14][cO5] = 186;
		z[rO5 + 13][cO5] = 186;

		z[rO5 + 13][cO5 - 8] = 176;
		z[rO5 + 13][cO5 - 7] = 176;
		z[rO5 + 13][cO5 - 6] = 176;
		z[rO5 + 13][cO5 - 5] = 176;
		z[rO5 + 13][cO5 - 4] = 176;
		z[rO5 + 13][cO5 - 3] = 176;
		z[rO5 + 13][cO5 - 2] = 176;
		z[rO5 + 13][cO5 - 1] = 176;
		z[rO5 + 13][cO5] = 176;
		z[rO5 + 13][cO5 + 1] = 176;
		z[rO5 + 13][cO5 + 2] = 176;
		z[rO5 + 13][cO5 + 3] = 176;
		z[rO5 + 13][cO5 + 4] = 176;
		z[rO5 + 13][cO5 + 5] = 176;
		z[rO5 + 13][cO5 + 6] = 176;
		z[rO5 + 13][cO5 + 7] = 176;
		z[rO5 + 13][cO5 + 8] = 176;

		z[rO5 + 12][cO5 - 7] = 176;
		z[rO5 + 12][cO5 - 6] = 176;
		z[rO5 + 12][cO5 - 5] = 176;
		z[rO5 + 12][cO5 - 4] = 176;
		z[rO5 + 12][cO5 - 3] = 176;
		z[rO5 + 12][cO5 - 2] = 176;
		z[rO5 + 12][cO5 - 1] = 176;
		z[rO5 + 12][cO5] = 176;
		z[rO5 + 12][cO5 + 1] = 176;
		z[rO5 + 12][cO5 + 2] = 176;
		z[rO5 + 12][cO5 + 3] = 176;
		z[rO5 + 12][cO5 + 4] = 176;
		z[rO5 + 12][cO5 + 5] = 176;
		z[rO5 + 12][cO5 + 6] = 176;
		z[rO5 + 12][cO5 + 7] = 176;

		z[rO5 + 11][cO5 - 6] = 176;
		z[rO5 + 11][cO5 - 5] = 176;
		z[rO5 + 11][cO5 - 4] = 176;
		z[rO5 + 11][cO5 - 3] = 176;
		z[rO5 + 11][cO5 - 2] = 176;
		z[rO5 + 11][cO5 - 1] = 176;
		z[rO5 + 11][cO5] = 176;
		z[rO5 + 11][cO5 + 1] = 176;
		z[rO5 + 11][cO5 + 2] = 176;
		z[rO5 + 11][cO5 + 3] = 176;
		z[rO5 + 11][cO5 + 4] = 176;
		z[rO5 + 11][cO5 + 5] = 176;
		z[rO5 + 11][cO5 + 6] = 176;

		z[rO5 + 10][cO5 - 5] = 176;
		z[rO5 + 10][cO5 - 4] = 176;
		z[rO5 + 10][cO5 - 3] = 176;
		z[rO5 + 10][cO5 - 2] = 176;
		z[rO5 + 10][cO5 - 1] = 176;
		z[rO5 + 10][cO5] = 176;
		z[rO5 + 10][cO5 + 1] = 176;
		z[rO5 + 10][cO5 + 2] = 176;
		z[rO5 + 10][cO5 + 3] = 176;
		z[rO5 + 10][cO5 + 4] = 176;
		z[rO5 + 10][cO5 + 5] = 176;

		z[rO5 + 9][cO5 - 4] = 176;
		z[rO5 + 9][cO5 - 3] = 176;
		z[rO5 + 9][cO5 - 2] = 176;
		z[rO5 + 9][cO5 - 1] = 176;
		z[rO5 + 9][cO5] = 176;
		z[rO5 + 9][cO5 + 1] = 176;
		z[rO5 + 9][cO5 + 2] = 176;
		z[rO5 + 9][cO5 + 3] = 176;
		z[rO5 + 9][cO5 + 4] = 176;

		z[rO5 + 8][cO5 - 3] = 176;
		z[rO5 + 8][cO5 - 2] = 176;
		z[rO5 + 8][cO5 - 1] = 176;
		z[rO5 + 8][cO5] = 176;
		z[rO5 + 8][cO5 + 1] = 176;
		z[rO5 + 8][cO5 + 2] = 176;
		z[rO5 + 8][cO5 + 3] = 176;

		z[rO5 + 7][cO5 - 2] = 176;
		z[rO5 + 7][cO5 - 1] = 176;
		z[rO5 + 7][cO5] = 176;
		z[rO5 + 7][cO5 + 1] = 176;
		z[rO5 + 7][cO5 + 2] = 176;

		z[rO5 + 6][cO5 - 1] = 176;
		z[rO5 + 6][cO5] = 176;
		z[rO5 + 6][cO5 + 1] = 176;

		z[rO5 + 5][cO5] = 176;


	}
	z[rO1 + 21][cO1] = 179;
	z[rO1 + 20][cO1] = 179;
	z[rO1 + 19][cO1] = 179;
	z[rO1 + 18][cO1] = 179;
	z[rO1 + 17][cO1] = 179;
	z[rO1 + 16][cO1] = 179;
	z[rO1 + 15][cO1] = 179;
	z[rO1 + 14][cO1] = 179;
	z[rO1 + 13][cO1] = 179;
	z[rO1 + 12][cO1] = 179;
	z[rO1 + 11][cO1] = 179;
	z[rO1 + 10][cO1] = 179;
	z[rO1 + 9][cO1] = 179;
	z[rO1 + 8][cO1] = 179;
	z[rO1 + 7][cO1] = 179;
	z[rO1 + 6][cO1] = 179;
	z[rO1 + 5][cO1] = 179;
	z[rO1 + 5][cO1 - 1] = 22;





}

void DObjectsFS1(char x[][138], int& rO1, int& rO2, int& rO3, int& rO4, int& rO5, int& cO1, int& cO2, int& cO3, int& cO4, int& cO5)
{
	for (int a = 0; a < 3; a++)
	{
		cO5++;
		cO4++;
		cO3++;
		cO2++;
		cO1++;

		rO5++;
		rO4++;
		rO3++;
		rO2++;
		rO1++;
		if (cO1 >= 133)
		{
			rO1 = -8;
			cO1 = 98;
		}

		if (cO2 >= 133)
		{
			rO2 = -8;
			cO2 = 98;
		}
		if (cO3 >= 133)
		{
			rO3 = -8;
			cO3 = 98;
		}
		if (cO4 >= 133)
		{
			rO4 = -8;
			cO4 = 98;
		}
		if (cO5 >= 133)
		{
			rO5 = -8;
			cO5 = 98;
		}
	}


}

void SObjectsFS2(char z[][138], int rO1, int rO2, int rO3, int& rO4, int rO5, int cO1, int cO2, int cO3, int cO4, int cO5)
{
	//tree = 186 176
	//light = 179 22


	{

		z[rO4 + 21][cO4] = 179;
		z[rO4 + 20][cO4] = 179;
		z[rO4 + 19][cO4] = 179;
		z[rO4 + 18][cO4] = 179;
		z[rO4 + 17][cO4] = 179;
		z[rO4 + 16][cO4] = 179;
		z[rO4 + 15][cO4] = 179;
		z[rO4 + 14][cO4] = 179;
		z[rO4 + 13][cO4] = 179;
		z[rO4 + 12][cO4] = 179;
		z[rO4 + 11][cO4] = 179;
		z[rO4 + 10][cO4] = 179;
		z[rO4 + 9][cO4] = 179;

		z[rO4 + 8][cO4] = 179;
		z[rO4 + 7][cO4] = 179;
		z[rO4 + 6][cO4] = 179;
		z[rO4 + 5][cO4] = 179;
		z[rO4 + 5][cO4 - 1] = 22;
	}

	{
		z[rO2 + 21][cO2] = 186;
		z[rO2 + 20][cO2] = 186;
		z[rO2 + 19][cO2] = 186;
		z[rO2 + 18][cO2] = 186;
		z[rO2 + 17][cO2] = 186;
		z[rO2 + 16][cO2] = 186;
		z[rO2 + 15][cO2] = 186;
		z[rO2 + 14][cO2] = 186;
		z[rO2 + 13][cO2] = 186;

		z[rO2 + 13][cO2 - 8] = 176;
		z[rO2 + 13][cO2 - 7] = 176;
		z[rO2 + 13][cO2 - 6] = 176;
		z[rO2 + 13][cO2 - 5] = 176;
		z[rO2 + 13][cO2 - 4] = 176;
		z[rO2 + 13][cO2 - 3] = 176;
		z[rO2 + 13][cO2 - 2] = 176;
		z[rO2 + 13][cO2 - 1] = 176;
		z[rO2 + 13][cO2] = 176;
		z[rO2 + 13][cO2 + 1] = 176;
		z[rO2 + 13][cO2 + 2] = 176;
		z[rO2 + 13][cO2 + 3] = 176;
		z[rO2 + 13][cO2 + 4] = 176;
		z[rO2 + 13][cO2 + 5] = 176;
		z[rO2 + 13][cO2 + 6] = 176;
		z[rO2 + 13][cO2 + 7] = 176;
		z[rO2 + 13][cO2 + 8] = 176;

		z[rO2 + 12][cO2 - 7] = 176;
		z[rO2 + 12][cO2 - 6] = 176;
		z[rO2 + 12][cO2 - 5] = 176;
		z[rO2 + 12][cO2 - 4] = 176;
		z[rO2 + 12][cO2 - 3] = 176;
		z[rO2 + 12][cO2 - 2] = 176;
		z[rO2 + 12][cO2 - 1] = 176;
		z[rO2 + 12][cO2] = 176;
		z[rO2 + 12][cO2 + 1] = 176;
		z[rO2 + 12][cO2 + 2] = 176;
		z[rO2 + 12][cO2 + 3] = 176;
		z[rO2 + 12][cO2 + 4] = 176;
		z[rO2 + 12][cO2 + 5] = 176;
		z[rO2 + 12][cO2 + 6] = 176;
		z[rO2 + 12][cO2 + 7] = 176;

		z[rO2 + 11][cO2 - 6] = 176;
		z[rO2 + 11][cO2 - 5] = 176;
		z[rO2 + 11][cO2 - 4] = 176;
		z[rO2 + 11][cO2 - 3] = 176;
		z[rO2 + 11][cO2 - 2] = 176;
		z[rO2 + 11][cO2 - 1] = 176;
		z[rO2 + 11][cO2] = 176;
		z[rO2 + 11][cO2 + 1] = 176;
		z[rO2 + 11][cO2 + 2] = 176;
		z[rO2 + 11][cO2 + 3] = 176;
		z[rO2 + 11][cO2 + 4] = 176;
		z[rO2 + 11][cO2 + 5] = 176;
		z[rO2 + 11][cO2 + 6] = 176;

		z[rO2 + 10][cO2 - 5] = 176;
		z[rO2 + 10][cO2 - 4] = 176;
		z[rO2 + 10][cO2 - 3] = 176;
		z[rO2 + 10][cO2 - 2] = 176;
		z[rO2 + 10][cO2 - 1] = 176;
		z[rO2 + 10][cO2] = 176;
		z[rO2 + 10][cO2 + 1] = 176;
		z[rO2 + 10][cO2 + 2] = 176;
		z[rO2 + 10][cO2 + 3] = 176;
		z[rO2 + 10][cO2 + 4] = 176;
		z[rO2 + 10][cO2 + 5] = 176;

		z[rO2 + 9][cO2 - 4] = 176;
		z[rO2 + 9][cO2 - 3] = 176;
		z[rO2 + 9][cO2 - 2] = 176;
		z[rO2 + 9][cO2 - 1] = 176;
		z[rO2 + 9][cO2] = 176;
		z[rO2 + 9][cO2 + 1] = 176;
		z[rO2 + 9][cO2 + 2] = 176;
		z[rO2 + 9][cO2 + 3] = 176;
		z[rO2 + 9][cO2 + 4] = 176;

		z[rO2 + 8][cO2 - 3] = 176;
		z[rO2 + 8][cO2 - 2] = 176;
		z[rO2 + 8][cO2 - 1] = 176;
		z[rO2 + 8][cO2] = 176;
		z[rO2 + 8][cO2 + 1] = 176;
		z[rO2 + 8][cO2 + 2] = 176;
		z[rO2 + 8][cO2 + 3] = 176;

		z[rO2 + 7][cO2 - 2] = 176;
		z[rO2 + 7][cO2 - 1] = 176;
		z[rO2 + 7][cO2] = 176;
		z[rO2 + 7][cO2 + 1] = 176;
		z[rO2 + 7][cO2 + 2] = 176;

		z[rO2 + 6][cO2 - 1] = 176;
		z[rO2 + 6][cO2] = 176;
		z[rO2 + 6][cO2 + 1] = 176;

		z[rO2 + 5][cO2] = 176;
	}



	z[rO1 + 21][cO1] = 179;
	z[rO1 + 20][cO1] = 179;
	z[rO1 + 19][cO1] = 179;
	z[rO1 + 18][cO1] = 179;
	z[rO1 + 17][cO1] = 179;
	z[rO1 + 16][cO1] = 179;
	z[rO1 + 15][cO1] = 179;
	z[rO1 + 14][cO1] = 179;
	z[rO1 + 13][cO1] = 179;
	z[rO1 + 12][cO1] = 179;
	z[rO1 + 11][cO1] = 179;
	z[rO1 + 10][cO1] = 179;
	z[rO1 + 9][cO1] = 179;
	z[rO1 + 8][cO1] = 179;
	z[rO1 + 7][cO1] = 179;
	z[rO1 + 6][cO1] = 179;
	z[rO1 + 5][cO1] = 179;
	z[rO1 + 5][cO1 - 1] = 22;



	{

		z[rO3 + 21][cO3] = 179;
		z[rO3 + 20][cO3] = 179;
		z[rO3 + 19][cO3] = 179;
		z[rO3 + 18][cO3] = 179;
		z[rO3 + 17][cO3] = 179;
		z[rO3 + 16][cO3] = 179;
		z[rO3 + 15][cO3] = 179;
		z[rO3 + 14][cO3] = 179;
		z[rO3 + 13][cO3] = 179;
		z[rO3 + 12][cO3] = 179;
		z[rO3 + 11][cO3] = 179;
		z[rO3 + 10][cO3] = 179;
		z[rO3 + 9][cO3] = 179;
		z[rO3 + 8][cO3] = 179;
		z[rO3 + 7][cO3] = 179;
		z[rO3 + 6][cO3] = 179;
		z[rO3 + 5][cO3] = 179;

		z[rO3 + 5][cO3 - 1] = 22;
	}





	{

		z[rO5 + 21][cO5] = 186;
		z[rO5 + 20][cO5] = 186;
		z[rO5 + 19][cO5] = 186;
		z[rO5 + 18][cO5] = 186;
		z[rO5 + 17][cO5] = 186;
		z[rO5 + 16][cO5] = 186;
		z[rO5 + 15][cO5] = 186;
		z[rO5 + 14][cO5] = 186;
		z[rO5 + 13][cO5] = 186;

		z[rO5 + 13][cO5 - 8] = 176;
		z[rO5 + 13][cO5 - 7] = 176;
		z[rO5 + 13][cO5 - 6] = 176;
		z[rO5 + 13][cO5 - 5] = 176;
		z[rO5 + 13][cO5 - 4] = 176;
		z[rO5 + 13][cO5 - 3] = 176;
		z[rO5 + 13][cO5 - 2] = 176;
		z[rO5 + 13][cO5 - 1] = 176;
		z[rO5 + 13][cO5] = 176;
		z[rO5 + 13][cO5 + 1] = 176;
		z[rO5 + 13][cO5 + 2] = 176;
		z[rO5 + 13][cO5 + 3] = 176;
		z[rO5 + 13][cO5 + 4] = 176;
		z[rO5 + 13][cO5 + 5] = 176;
		z[rO5 + 13][cO5 + 6] = 176;
		z[rO5 + 13][cO5 + 7] = 176;
		z[rO5 + 13][cO5 + 8] = 176;

		z[rO5 + 12][cO5 - 7] = 176;
		z[rO5 + 12][cO5 - 6] = 176;
		z[rO5 + 12][cO5 - 5] = 176;
		z[rO5 + 12][cO5 - 4] = 176;
		z[rO5 + 12][cO5 - 3] = 176;
		z[rO5 + 12][cO5 - 2] = 176;
		z[rO5 + 12][cO5 - 1] = 176;
		z[rO5 + 12][cO5] = 176;
		z[rO5 + 12][cO5 + 1] = 176;
		z[rO5 + 12][cO5 + 2] = 176;
		z[rO5 + 12][cO5 + 3] = 176;
		z[rO5 + 12][cO5 + 4] = 176;
		z[rO5 + 12][cO5 + 5] = 176;
		z[rO5 + 12][cO5 + 6] = 176;
		z[rO5 + 12][cO5 + 7] = 176;

		z[rO5 + 11][cO5 - 6] = 176;
		z[rO5 + 11][cO5 - 5] = 176;
		z[rO5 + 11][cO5 - 4] = 176;
		z[rO5 + 11][cO5 - 3] = 176;
		z[rO5 + 11][cO5 - 2] = 176;
		z[rO5 + 11][cO5 - 1] = 176;
		z[rO5 + 11][cO5] = 176;
		z[rO5 + 11][cO5 + 1] = 176;
		z[rO5 + 11][cO5 + 2] = 176;
		z[rO5 + 11][cO5 + 3] = 176;
		z[rO5 + 11][cO5 + 4] = 176;
		z[rO5 + 11][cO5 + 5] = 176;
		z[rO5 + 11][cO5 + 6] = 176;

		z[rO5 + 10][cO5 - 5] = 176;
		z[rO5 + 10][cO5 - 4] = 176;
		z[rO5 + 10][cO5 - 3] = 176;
		z[rO5 + 10][cO5 - 2] = 176;
		z[rO5 + 10][cO5 - 1] = 176;
		z[rO5 + 10][cO5] = 176;
		z[rO5 + 10][cO5 + 1] = 176;
		z[rO5 + 10][cO5 + 2] = 176;
		z[rO5 + 10][cO5 + 3] = 176;
		z[rO5 + 10][cO5 + 4] = 176;
		z[rO5 + 10][cO5 + 5] = 176;

		z[rO5 + 9][cO5 - 4] = 176;
		z[rO5 + 9][cO5 - 3] = 176;
		z[rO5 + 9][cO5 - 2] = 176;
		z[rO5 + 9][cO5 - 1] = 176;
		z[rO5 + 9][cO5] = 176;
		z[rO5 + 9][cO5 + 1] = 176;
		z[rO5 + 9][cO5 + 2] = 176;
		z[rO5 + 9][cO5 + 3] = 176;
		z[rO5 + 9][cO5 + 4] = 176;

		z[rO5 + 8][cO5 - 3] = 176;
		z[rO5 + 8][cO5 - 2] = 176;
		z[rO5 + 8][cO5 - 1] = 176;
		z[rO5 + 8][cO5] = 176;
		z[rO5 + 8][cO5 + 1] = 176;
		z[rO5 + 8][cO5 + 2] = 176;
		z[rO5 + 8][cO5 + 3] = 176;

		z[rO5 + 7][cO5 - 2] = 176;
		z[rO5 + 7][cO5 - 1] = 176;
		z[rO5 + 7][cO5] = 176;
		z[rO5 + 7][cO5 + 1] = 176;
		z[rO5 + 7][cO5 + 2] = 176;

		z[rO5 + 6][cO5 - 1] = 176;
		z[rO5 + 6][cO5] = 176;
		z[rO5 + 6][cO5 + 1] = 176;

		z[rO5 + 5][cO5] = 176;


	}




}

void DObjectsFS2(char x[][138], int& rO1, int& rO2, int& rO3, int& rO4, int& rO5, int& cO1, int& cO2, int& cO3, int& cO4, int& cO5)
{

	for (int b = 0; b < 3; b++)
	{

		cO5--;
		cO4--;
		cO3--;
		cO2--;
		cO1--;



		rO5++;
		rO4++;
		rO3++;
		rO2++;
		rO1++;


		if (cO1 <= 5)
		{
			rO1 = -8;
			cO1 = 40;
		}

		if (cO2 <= 5)
		{
			rO2 = -8;
			cO2 = 40;
		}
		if (cO3 <= 5)
		{
			rO3 = -8;
			cO3 = 40;
		}
		if (cO4 <= 5)
		{
			rO4 = -8;
			cO4 = 40;
		}
		if (cO5 <= 5)
		{
			rO5 = -8;
			cO5 = 40;
		}
	}

}

void ActionFS(char z[][138])
{


}

void CarFS(char z[][138], int r, int c)
{


	z[r][c] = '_';
	z[r][c + 1] = '_';
	z[r][c + 2] = '_';
	z[r][c + 3] = '_';
	z[r][c + 4] = '_';
	z[r][c + 5] = '_';
	z[r][c + 6] = '_';
	z[r][c + 7] = '_';
	z[r][c + 8] = '_';
	z[r][c + 9] = '_';
	z[r][c + 10] = '_';
	z[r][c + 11] = '_';
	z[r][c + 12] = '_';
	z[r][c + 13] = '_';
	z[r][c + 14] = '_';
	z[r][c + 15] = '_';
	z[r + 1][c + 16] = '\\';
	z[r + 2][c + 17] = '\\';
	z[r + 3][c + 18] = '\\';
	z[r + 4][c + 19] = '\\';
	z[r + 5][c + 20] = '\\';
	z[r + 6][c + 21] = '\\';
	z[r + 1][c - 1] = '/';
	z[r + 2][c - 2] = '/';
	z[r + 3][c - 3] = '/';
	z[r + 4][c - 4] = '/';
	z[r + 5][c - 5] = '/';
	z[r + 6][c - 6] = '/';

	z[r - 1][c] = '_';
	z[r - 1][c + 1] = '_';
	z[r - 1][c + 2] = '_';
	z[r - 1][c + 3] = '_';
	z[r - 1][c + 4] = '_';
	z[r - 1][c + 5] = '_';
	z[r - 1][c + 6] = '_';
	z[r - 1][c + 7] = '_';
	z[r - 1][c + 8] = '_';
	z[r - 1][c + 9] = '_';
	z[r - 1][c + 10] = '_';
	z[r - 1][c + 11] = '_';
	z[r - 1][c + 12] = '_';
	z[r - 1][c + 13] = '_';
	z[r - 1][c + 14] = '_';
	z[r - 1][c + 15] = '_';
	z[r][c + 16] = '\\';
	z[r + 1][c + 17] = '\\';
	z[r + 2][c + 18] = '\\';
	z[r + 3][c + 19] = '\\';
	z[r + 4][c + 20] = '\\';
	z[r + 5][c + 21] = '\\';
	z[r + 6][c + 22] = '\\';
	z[r][c - 1] = '/';
	z[r + 1][c - 2] = '/';
	z[r + 2][c - 3] = '/';
	z[r + 3][c - 4] = '/';
	z[r + 4][c - 5] = '/';
	z[r + 5][c - 6] = '/';
	z[r + 6][c - 7] = '/';

	z[r + 6][c - 8] = 179;
	z[r + 5][c - 9] = '_';
	z[r + 5][c - 10] = '_';
	z[r + 5][c - 11] = '_';
	z[r + 6][c - 12] = '/';
	z[r + 7][c - 12] = 179;
	z[r + 7][c - 11] = '_';
	z[r + 7][c - 10] = '_';
	z[r + 7][c - 9] = '_';
	z[r + 7][c - 8] = '_';

	z[r + 8][c - 9] = 179;
	z[r + 9][c - 9] = 179;
	z[r + 10][c - 9] = 179;
	z[r + 11][c - 9] = '/';
	z[r + 12][c - 10] = 179;
	z[r + 12][c - 10] = 179;
	z[r + 13][c - 10] = 179;
	z[r + 14][c - 10] = 179;
	z[r + 15][c - 10] = 179;
	z[r + 16][c - 10] = 179;
	z[r + 17][c - 9] = '_';
	z[r + 17][c - 8] = '_';
	z[r + 17][c - 7] = '_';
	z[r + 17][c - 6] = '_';
	z[r + 17][c - 5] = '_';
	z[r + 17][c - 4] = '_';
	z[r + 17][c - 3] = '_';
	z[r + 17][c - 2] = 179;
	z[r + 17][c - 1] = '_';
	z[r + 17][c] = '_';
	z[r + 17][c + 1] = '_';
	z[r + 17][c + 2] = '_';
	z[r + 17][c + 3] = '_';
	z[r + 17][c + 4] = '_';
	z[r + 17][c + 5] = '_';
	z[r + 17][c + 6] = '_';
	z[r + 17][c + 7] = '_';
	z[r + 17][c + 8] = '_';
	z[r + 17][c + 9] = '_';
	z[r + 17][c + 10] = '_';
	z[r + 17][c + 11] = '_';
	z[r + 17][c + 12] = '_';
	z[r + 17][c + 13] = '_';
	z[r + 17][c + 14] = '_';
	z[r + 17][c + 15] = '_';
	z[r + 17][c + 16] = 179;
	z[r + 17][c + 17] = '_';
	z[r + 17][c + 18] = '_';
	z[r + 17][c + 19] = '_';
	z[r + 17][c + 20] = '_';
	z[r + 17][c + 21] = '_';
	z[r + 17][c + 22] = '_';
	z[r + 17][c + 23] = '_';

	z[r + 16][c + 24] = 179;
	z[r + 15][c + 24] = 179;
	z[r + 14][c + 24] = 179;
	z[r + 13][c + 24] = 179;
	z[r + 12][c + 24] = 179;
	z[r + 11][c + 23] = '\\';
	z[r + 10][c + 23] = 179;
	z[r + 9][c + 23] = 179;
	z[r + 8][c + 23] = 179;

	z[r + 7][c + 22] = '_';
	z[r + 7][c + 23] = '_';
	z[r + 7][c + 24] = '_';
	z[r + 7][c + 25] = '_';
	z[r + 7][c + 26] = 179;
	z[r + 6][c + 26] = '\\';
	z[r + 5][c + 25] = '_';
	z[r + 5][c + 24] = '_';
	z[r + 5][c + 23] = '_';
	z[r + 6][c + 22] = 179;

	//////INSIDE/////

	z[r + 6][c - 5] = '_';
	z[r + 6][c - 4] = '_';
	z[r + 6][c - 3] = '_';
	z[r + 6][c - 2] = '_';
	z[r + 6][c - 1] = '_';
	z[r + 6][c] = '_';
	z[r + 6][c + 1] = '_';
	z[r + 6][c + 2] = '/';
	z[r + 5][c + 3] = '_';
	z[r + 5][c + 4] = '_';
	z[r + 5][c + 5] = '_';
	z[r + 5][c + 6] = '_';
	z[r + 5][c + 7] = '_';
	z[r + 5][c + 8] = '_';
	z[r + 5][c + 9] = '_';
	z[r + 5][c + 10] = '_';
	z[r + 5][c + 11] = '_';
	z[r + 5][c + 12] = '_';
	z[r + 6][c + 13] = '\\';
	z[r + 6][c + 14] = '_';
	z[r + 6][c + 15] = '_';
	z[r + 6][c + 16] = '_';
	z[r + 6][c + 17] = '_';
	z[r + 6][c + 18] = '_';
	z[r + 6][c + 19] = '_';
	z[r + 6][c + 20] = '_';


	z[r + 6][c + 3] = '\\';
	z[r + 7][c + 4] = '\\';
	z[r + 7][c + 5] = '_';
	z[r + 7][c + 6] = '_';
	z[r + 7][c + 7] = '_';
	z[r + 7][c + 8] = '_';
	z[r + 7][c + 9] = '_';
	z[r + 7][c + 10] = '_';
	z[r + 7][c + 11] = '/';
	z[r + 6][c + 12] = '/';

	z[r + 8][c + 3] = '/';
	z[r + 9][c + 2] = '/';
	z[r + 10][c + 1] = '/';
	z[r + 11][c + 1] = '\\';
	z[r + 12][c + 2] = '\\';
	z[r + 13][c + 3] = '\\';
	z[r + 14][c + 4] = '\\';
	z[r + 14][c + 5] = '_';
	z[r + 14][c + 6] = '_';
	z[r + 14][c + 7] = '_';
	z[r + 14][c + 8] = '_';
	z[r + 14][c + 9] = '_';
	z[r + 14][c + 10] = '_';
	z[r + 14][c + 11] = '/';
	z[r + 13][c + 12] = '/';
	z[r + 12][c + 13] = '/';
	z[r + 11][c + 14] = '/';
	z[r + 10][c + 14] = '\\';
	z[r + 9][c + 13] = '\\';
	z[r + 8][c + 12] = '\\';

	z[r + 9][c + 3] = '_';
	z[r + 9][c + 4] = '_';
	z[r + 9][c + 5] = '_';
	z[r + 9][c + 6] = '_';
	z[r + 9][c + 7] = '_';
	z[r + 9][c + 8] = '_';
	z[r + 9][c + 9] = '_';
	z[r + 9][c + 10] = '_';
	z[r + 9][c + 11] = '_';
	z[r + 9][c + 12] = '_';

	z[r + 10][c + 2] = '_';
	z[r + 10][c + 3] = '_';
	z[r + 10][c + 4] = '_';
	z[r + 10][c + 5] = '_';
	z[r + 10][c + 6] = '_';
	z[r + 10][c + 7] = '_';
	z[r + 10][c + 8] = '_';
	z[r + 10][c + 9] = '_';
	z[r + 10][c + 10] = '_';
	z[r + 10][c + 11] = '_';
	z[r + 10][c + 12] = '_';
	z[r + 10][c + 13] = '_';

	z[r + 11][c + 3] = '_';
	z[r + 11][c + 4] = '_';
	z[r + 11][c + 5] = '_';
	z[r + 11][c + 6] = '_';
	z[r + 11][c + 7] = 'F';
	z[r + 11][c + 8] = 'B';
	z[r + 11][c + 9] = 'I';
	z[r + 11][c + 10] = '_';
	z[r + 11][c + 11] = '_';
	z[r + 11][c + 12] = '_';


	z[r + 12][c + 4] = '_';
	z[r + 12][c + 5] = '_';
	z[r + 12][c + 6] = '_';
	z[r + 12][c + 7] = '_';
	z[r + 12][c + 8] = '_';
	z[r + 12][c + 9] = '_';
	z[r + 12][c + 10] = '_';
	z[r + 12][c + 11] = '_';


	z[r + 11][c + 16] = '_';
	z[r + 11][c + 17] = '_';
	z[r + 11][c + 18] = '_';
	z[r + 11][c + 19] = '_';
	z[r + 11][c + 20] = '_';
	z[r + 11][c + 21] = '_';
	z[r + 11][c + 22] = '_';
	z[r + 12][c + 22] = 179;
	z[r + 13][c + 22] = '/';
	z[r + 13][c + 21] = '_';
	z[r + 13][c + 20] = '_';
	z[r + 13][c + 19] = '_';
	z[r + 13][c + 18] = '_';
	z[r + 13][c + 17] = '_';
	z[r + 13][c + 16] = '\\';


	z[r + 12][c + 17] = '.';
	z[r + 12][c + 18] = '.';
	z[r + 12][c + 19] = '.';
	z[r + 12][c + 20] = '.';
	z[r + 12][c + 21] = '.';

	z[r + 16][c - 7] = '_';
	z[r + 16][c - 6] = '_';
	z[r + 16][c - 5] = '_';
	z[r + 16][c - 4] = '_';
	z[r + 16][c - 3] = '_';
	z[r + 16][c - 2] = '_';
	z[r + 16][c - 1] = '_';
	z[r + 16][c] = '_';
	z[r + 16][c + 1] = '_';
	z[r + 16][c + 2] = '_';
	z[r + 16][c + 3] = '_';

	z[r + 16][c + 4] = '/';

	z[r + 15][c + 5] = '_';
	z[r + 15][c + 6] = '_';
	z[r + 15][c + 7] = '_';
	z[r + 15][c + 8] = '_';
	z[r + 15][c + 9] = '_';
	z[r + 15][c + 10] = '_';

	z[r + 16][c + 11] = '\\';

	z[r + 16][c + 12] = '_';
	z[r + 16][c + 13] = '_';
	z[r + 16][c + 14] = '_';
	z[r + 16][c + 15] = '_';
	z[r + 16][c + 16] = '_';
	z[r + 16][c + 17] = '_';
	z[r + 16][c + 18] = '_';
	z[r + 16][c + 19] = '_';
	z[r + 16][c + 20] = '_';
	z[r + 16][c + 21] = '_';
	z[r + 16][c + 22] = '_';


	z[r + 11][c - 1] = '_';
	z[r + 11][c - 2] = '_';
	z[r + 11][c - 3] = '_';
	z[r + 11][c - 4] = '_';
	z[r + 11][c - 5] = '_';
	z[r + 11][c - 6] = '_';
	z[r + 11][c - 7] = '_';
	z[r + 12][c - 7] = 179;
	z[r + 13][c - 7] = '\\';
	z[r + 13][c - 6] = '_';
	z[r + 13][c - 5] = '_';
	z[r + 13][c - 4] = '_';
	z[r + 13][c - 3] = '_';
	z[r + 13][c - 2] = '_';
	z[r + 13][c - 1] = '/';


	z[r + 12][c - 2] = '.';
	z[r + 12][c - 3] = '.';
	z[r + 12][c - 4] = '.';
	z[r + 12][c - 5] = '.';
	z[r + 12][c - 6] = '.';
	if (r < 4)
	{
		z[r + 6][c + 14] = '|';
		z[r + 5][c + 14] = '|';
		z[r + 4][c + 14] = '|';
		z[r + 3][c + 15] = '_';
		z[r + 3][c + 16] = '_';
		z[r + 3][c + 17] = '_';
		z[r + 3][c + 18] = '_';

		z[r + 5][c + 16] = 127;
		z[r + 5][c + 18] = 127;
		z[r + 6][c + 17] = '^';
	}

}

void DynCarFS(char z[][138], int& r, int& c)
{
	if (r < 4)
	{
		r += 2;
	}
}

void OutputFS(char z[][138])
{
	system("cls");

	for (int r = 0; r < 48; r++)
	{
		for (int c = 0; c < 138; c++)
		{

			cout << z[r][c];
		}
	}
}

void EnemyFS(char z[][138], int r, int c)

{


	z[r][c - 2] = '_';
	z[r][c - 3] = '/';
	z[r + 1][c - 3] = '\\';
	z[r - 1][c - 2] = '_';
	z[r - 1][c - 1] = '_';
	z[r - 1][c] = '_';
	z[r - 1][c + 1] = '_';
	z[r - 1][c + 2] = '_';
	z[r - 1][c + 3] = '_';
	z[r][c + 3] = '_';
	z[r][c + 4] = '\\';
	z[r + 1][c + 4] = '/';



	z[r][c - 1] = '_';
	z[r][c] = 21;
	z[r][c + 1] = '_';
	z[r][c + 2] = '_';


	{
		z[r + 2][c] = 127;
		z[r + 2][c + 2] = 127;

		z[r + 2][c + 1] = ' ';
		z[r + 2][c - 1] = ' ';
	}

	z[r + 1][c - 2] = '/';
	z[r + 1][c + 3] = '\\';

	z[r + 2][c - 2] = '|';
	z[r + 2][c + 3] = '|';

	z[r + 3][c - 2] = '\\';
	z[r + 3][c + 3] = '/';

	z[r + 3][c - 1] = '_';
	z[r + 3][c] = '_';
	z[r + 3][c + 1] = '^';
	z[r + 3][c + 2] = '_';

	z[r + 4][c - 2] = '_';
	z[r + 4][c - 1] = '/';
	z[r + 4][c + 2] = '/';
	z[r + 4][c + 3] = '_';




	z[r + 6][c + 4] = '\\';	//RIGHT HAND
	z[r + 6][c + 5] = '_';
	z[r + 6][c + 6] = '_';
	z[r + 6][c + 7] = '/';
	z[r + 5][c + 8] = '_';
	z[r + 4][c + 7] = '_';
	z[r + 5][c + 5] = '\\';
	z[r + 5][c + 6] = '/';
	z[r + 4][c + 4] = '_';

	z[r + 4][c + 7] = '_';	//GUN
	z[r + 4][c + 8] = '_';
	z[r + 4][c + 9] = '_';
	z[r + 4][c + 10] = '_';
	z[r + 4][c + 11] = '_';
	z[r + 4][c + 12] = '_';
	z[r + 5][c + 13] = '|';
	z[r + 5][c + 12] = '_';
	z[r + 5][c + 11] = '_';
	z[r + 5][c + 10] = '_';
	z[r + 6][c + 9] = '/';
	z[r + 6][c + 8] = '_';




	z[r + 5][c - 3] = '/';			//LEFT HAND 
	z[r + 6][c - 4] = '\\';
	z[r + 5][c - 4] = '_';
	z[r + 5][c - 2] = '_';
	z[r + 6][c - 3] = '_';
	z[r + 6][c - 1] = '_';
	z[r + 6][c - 2] = '_';
	z[r + 6][c] = '|';
	z[r + 5][c - 1] = '_';

	z[r + 7][c + 3] = '|';


	z[r + 7][c - 2] = '|';

	z[r + 7][c - 1] = '_';
	z[r + 7][c + 1] = '_';
	z[r + 7][c + 2] = '_';
	z[r + 7][c] = '_';

	z[r + 8][c - 2] = '/';			//LEFT LEG 1
	z[r + 9][c - 3] = '/';
	z[r + 10][c - 4] = '/';

	z[r + 8][c] = '/'; 			//LEFT LEG 2
	z[r + 9][c - 1] = '/';
	z[r + 10][c - 2] = '/';
	z[r + 10][c - 3] = '_';
	z[r + 8][c + 1] = '\\';			//RIGHT LEG 3
	z[r + 9][c + 2] = '\\';
	z[r + 10][c + 2] = '|';

	z[r + 8][c + 3] = '\\';			//RIGHT LEG 4
	z[r + 9][c + 4] = '\\';
	z[r + 10][c + 4] = '|';
	z[r + 10][c + 3] = '_';

}

void ReplyF(char z[][138], int&counterFS, int& timerFS, int& rH, int& cH, int& counterFS2, int& rCarFS, int& cCarFS, int& Reply, int& Scene, int& level, int r1OFS1, int r1OFS2, int r1OFS3, int r1OFS4, int r1OFS5, int c1OFS1, int c1OFS2, int c1OFS3, int c1OFS4, int c1OFS5, int r2OFS1, int r2OFS2, int r2OFS3, int r2OFS4, int r2OFS5, int c2OFS1, int c2OFS2, int c2OFS3, int c2OFS4, int c2OFS5, int& rEnemyFS, int& cEnemyFS)
{
	rH = 30;
	cH = 86;
	for (;;)
	{
		for (; !_kbhit();)
		{
			MapFS(z, counterFS, timerFS);
			SObjectsFS1(z, r1OFS1, r1OFS2, r1OFS3, r1OFS4, r1OFS5, c1OFS1, c1OFS2, c1OFS3, c1OFS4, c1OFS5);
			if (timerFS <= 15)
			{
				DObjectsFS1(z, r1OFS1, r1OFS2, r1OFS3, r1OFS4, r1OFS5, c1OFS1, c1OFS2, c1OFS3, c1OFS4, c1OFS5);
			}
			StaticHeroFS(z, rH, cH, counterFS2, timerFS);

			SObjectsFS2(z, r2OFS1, r2OFS2, r2OFS3, r2OFS4, r2OFS5, c2OFS1, c2OFS2, c2OFS3, c2OFS4, c2OFS5);

			if (timerFS <= 15)
			{
				DObjectsFS2(z, r2OFS1, r2OFS2, r2OFS3, r2OFS4, r2OFS5, c2OFS1, c2OFS2, c2OFS3, c2OFS4, c2OFS5);
			}
			for (int row = rCarFS - 1, n = 0; n < 19; row++, n++)
			{
				for (int col = cCarFS - 12, m = 0; m < 38; col++, m++)
				{
					z[row][col] = ' ';
				}
			}
			CarFS(z, rCarFS, cCarFS);
			DynCarFS(z, rCarFS, cCarFS);
			if (timerFS > 12)
			{
				for (int row = rEnemyFS - 2, n = 0; n < 11; row++, n++)
				{
					for (int col = cEnemyFS - 2, m = 0; m < 6; col++, m++)
					{
						z[row][col] = ' ';
					}
				}
				EnemyFS(z, rEnemyFS, cEnemyFS);
			}
			if (timerFS > 15 && timerFS <= 20)
			{
				z[13][75] = 'Y';
				z[13][76] = 'o';
				z[13][77] = 'u';
				z[13][78] = ' ';
				z[13][79] = 'a';
				z[13][80] = 'r';
				z[13][81] = 'e';
				z[13][82] = ' ';
				z[13][83] = 'u';
				z[13][84] = 'n';
				z[13][85] = 'd';
				z[13][86] = 'e';
				z[13][87] = 'r';
				z[13][88] = ' ';
				z[13][89] = 'a';
				z[13][90] = 'r';
				z[13][91] = 'r';
				z[13][92] = 'e';
				z[13][93] = 's';
				z[13][94] = 't';



			}
			if (timerFS > 20 && timerFS <= 25)
			{
				z[13][75] = 'f';
				z[13][76] = 'o';
				z[13][77] = 'r';
				z[13][78] = ' ';
				z[13][79] = 'k';
				z[13][80] = 'i';
				z[13][81] = 'l';
				z[13][82] = 'l';
				z[13][83] = 'i';
				z[13][84] = 'n';
				z[13][85] = 'g';
				z[13][86] = ' ';
				z[13][87] = 'p';
				z[13][88] = 'e';
				z[13][89] = 'o';
				z[13][90] = 'p';
				z[13][91] = 'l';
				z[13][92] = 'e';
				z[13][93] = ' ';
				z[13][94] = ' ';



			}
			if (timerFS > 25 && timerFS <= 30)
			{
				z[13][91] = 'I';
				z[13][92] = ' ';
				z[13][93] = 'w';
				z[13][94] = 'o';
				z[13][95] = 'n';
				z[13][96] = '`';
				z[13][97] = 't';
				z[13][98] = ' ';
				z[13][99] = 'g';
				z[13][100] = 'i';
				z[13][101] = 'v';
				z[13][102] = 'e';
				z[13][103] = ' ';
				z[13][104] = 'u';
				z[13][105] = 'p';
			}

			if (timerFS > 30 && timerFS <= 35)
			{
				z[13][75] = 'Y';
				z[13][76] = 'o';
				z[13][77] = 'u';
				z[13][78] = ' ';
				z[13][79] = 'w';
				z[13][80] = 'i';
				z[13][81] = 'l';
				z[13][82] = 'l';
				z[13][83] = ' ';
				z[13][84] = 'r';
				z[13][85] = 'e';
				z[13][86] = 'g';
				z[13][87] = 'r';
				z[13][88] = 'e';
				z[13][89] = 't';
				z[13][90] = ' ';
				z[13][91] = 'f';
				z[13][92] = 'o';
				z[13][93] = 'r';
				z[13][94] = ' ';
				z[13][95] = 't';
				z[13][96] = 'h';
				z[13][97] = 'a';
				z[13][98] = 't';
			}

			if (timerFS > 35 && timerFS <= 43)
			{
				z[13][91] = 'W';
				z[13][92] = 'e';
				z[13][93] = ' ';
				z[13][94] = 'w';
				z[13][95] = 'i';
				z[13][96] = 'l';
				z[13][97] = 'l';
				z[13][98] = ' ';
				z[13][99] = 's';
				z[13][100] = 'e';
				z[13][101] = 'e';
				z[13][102] = ' ';
				z[13][103] = 'w';
				z[13][104] = 'h';
				z[13][105] = 'o';
				z[13][106] = ' ';
				z[13][107] = 'w';
				z[13][108] = 'i';
				z[13][109] = 'l';
				z[13][110] = 'l';
			}

			if (timerFS > 45)
			{
				break;
				Reply = 2;
			}
			OutputFS(z);
			Scene++;
			counterFS++;
			counterFS2++;
			timerFS++;
		}

		if (timerFS >= 0)
		{
			//level++;
			Reply = 2;
			break;

		}
		if (timerFS > 45)
		{
			//level++;
			Reply = 2;
			break;

		}
	}
}




void Output(char x[][138], int& ScrollCounter, int& cH)
{

	if (ScrollCounter == 0)
	{
		system("cls");

		for (int r = 0; r < 48; r++)
		{
			for (int c = 0; c < 138; c++)
			{

				cout << x[r][c];
			}
		}




	}

	if (ScrollCounter == 1)
	{
		for (int r = 0; r < 48; r++)
		{
			for (int c = 0; c < 138; c++)
			{

				cout << x[r][c];
			}
		}
		//cH = 5;
		ScrollCounter = 0;

	}

}


int main()
{
	char x[48][138];
	int countRLHL1 = 0;
	int rH = 36, cH = 8;
	int mins = 9, secs = 60;
	int level = 0;
	int flag1 = 0;
	int sand = 0;
	int lose1 = 0;
	int ConstructorCount = 0;
	char playerchoice[100];
	int CountStart = 0;
	int shoot1 = 0;
	int CounterUntilStop = 0;
	int pass1 = 0, pass2 = 0;
	int rF = 24, cF = 0;
	int CounterFloor = 0;
	int timer = 0;
	int ScrollCounter = 0, ScrollDelay = 0;
	int rEv = 33, cEv = 109;
	int rFEv = 46, cFEv = 118;
	int FloorNumber = 1;
	int OneTime = 0;
	int GetOut = 0;
	int rGuide = 0, cGuide = 0;
	int LeftLook = 0;
	int cO1 = 2, rO1 = 3;
	int cO2 = 20, rO2 = 3;
	int cO3 = 38, rO3 = 3;
	int cO4 = 43, rO4 = 3;
	int cO5 = 61, rO5 = 3;
	int cO6 = 79, rO6 = 3;
	int cO7 = 97, rO7 = 3;
	int cO8 = 0, rO8 = 0;
	int cO9 = 121, rO9 = 3;
	int cC = 85;
	int rE1 = 36, cE1 = 7;
	int rE2 = 36, cE2 = 7;
	int rEG1 = 36, cEG1 = 7;
	int rEG2 = 36, cEG2 = 7;
	int countRLEL1 = 1;
	int countRLEL2 = 1;
	int countG1 = 1;
	int countG2 = 1;
	int timer2 = 0;
	int timer3 = 0;
	int timer4 = 0;
	int timer5 = 0;
	int DelayShot = 2;
	int DeathT = 10;
	int Scounter = 0;
	int HScounter = 0;
	int GameOver = 0;
	int cCar1 = 120, rCar1 = 38;
	int cCar2 = 85, rCar2 = 38;
	int countCar1 = 0;
	int ratio1 = 1;
	int flagC = 0;
	int countHearts = 0;
	int countHearts2 = 0;
	int flagScore1 = 0, flagScore2 = 0, flagScore3 = 0, flagScore4 = 0;
	int flagTime1 = 0, flagTime2 = 0, flagTime3 = 0, flagTime4 = 0;
	int BSc = 128;
	int openG = 0;
	int TSc = 64;
	int rPlane1 = 7, cPlane1 = 120;
	int rPlane2 = 9, cPlane2 = 85;
	int rPlane3 = 11, cPlane3 = 50;
	int ratio2 = 1;
	int flagP2 = 0;
	int flagP22 = 0;
	int rPG1 = 13, rPG2 = 15, rPG3 = 17;
	int cPG1 = 113, cPG2 = 78, cPG3 = 43;
	int rSkate = 44, cSkate = 42;
	int SkateIn = 0;
	int rT = 47, cT = 95;
	int rR = 0, cR = 51;
	int RopeIn = 0;
	int tap4 = 0;
	int rMS1 = 36, cMS1 = 8;
	int rMS2 = 36, cMS2 = 8;
	int countMyShot = 0;
	int ShootON = 0;
	int countShots = 1;
	int Reload = 0, ActionReload = 1;
	int rB = 0;
	int cB = 0;
	int ct = 0;
	int rBB = 28;
	int cBB = 124;
	int win = 0;
	int gotshot = 0;
	int firsttime = 1;
	int timerBSC = 0;
	int rFC = 37, cFC = 121;
	int rEvR = 33;
	int flag6C = 1;
	int rBBS1 = rBB + 8, cBBS1 = cBB - 32;
	int rBBS2 = rBB + 10, cBBS2 = cBB - 29;
	int when = 0;
	int LevelSelection;
	int breakme = 0;
	int tryagain = 3;
	int ks = 0;
	int rT6 = 27, cT6 = 24;
	int shittybug = 0;
	int TelephRide = 0;
	int ladder = 0;
	int AutoWalk = 0;
	int AutoWalkCounter = 1;
	int FloorNumberCount = 0;
	int Reply = 0;
	int rEnemyFS = 14;
	int cEnemyFS = 68;
	char y[48][138];
	char z[48][138];



	int Scene = 0;
	int counterFS = 2;
	int r1OFS1 = -5;
	int r1OFS2 = 1;
	int r1OFS3 = 11;
	int r1OFS4 = 15;
	int r1OFS5 = 20;

	int c1OFS1 = 100;
	int c1OFS2 = 108;
	int c1OFS3 = 118;
	int c1OFS4 = 123;
	int c1OFS5 = 128;

	///////////////////////////////
	int r2OFS2 = -5;
	int r2OFS1 = 1;
	int r2OFS3 = 5;
	int r2OFS5 = 12;
	int r2OFS4 = 22;

	int c2OFS2 = 37;
	int c2OFS1 = 31;
	int c2OFS3 = 27;
	int c2OFS5 = 19;//5
	int c2OFS4 = 10;//5

	int counterFS2 = 2;
	int timerFS = 0;
	int rCarFS = -18;
	int cCarFS = 56;


	PlayerInfo P[200];
	int IntroTimer = -1;
	int startgame = 0;
	int k = 1;
	int i;
	int H1 = 0;
	int H2 = 0;
	int H3 = 0;
	int max1 = -99999;
	int max2 = -99999;
	int max3 = -99999;
	int ClickFix = 0;


	SetConsoleTitle(TEXT("2D CHAR GAME : MISSION IMPOSSIBLE"));


	if (level == 0)
	{
		SetConsoleTextAttribute(hConsole, 4);
		for (;;)
		{
			intro(y, IntroTimer);

			if (IntroTimer >= -1)
			{
				outputy(y);
			}
			IntroTimer++;
			if (IntroTimer >= 24)
			{
				break;

			}
		}
	}



	for (;;)
	{

		if (level == 0)
		{
			SetConsoleTextAttribute(hConsole, 11);
			//i = 1;

			if (k > 1)
			{
				for (i = 1; i < k; i++)
				{
					if (P[i].PlayerScore > max1)
					{
						max1 = P[i].PlayerScore;//10
						H1 = i;
						break;
					}
				}
			}

			if (k > 2)
			{
				for (i = 1; i < k; i++)
				{
					if (P[i].PlayerScore > max2 && P[i].PlayerScore <= max1 && i != H1)
					{
						max2 = P[i].PlayerScore;
						H2 = i;
						break;
					}
				}
			}

			if (k > 3)
			{
				for (i = 1; i < k; i++)
				{
					if (P[i].PlayerScore > max3 && P[i].PlayerScore <= max1 && P[i].PlayerScore <= max2 && i != H2 && i != H1)
					{
						max3 = P[i].PlayerScore;
						H3 = i;
						break;
					}
				}
			}




			system("cls");
			MainMenu(k, ClickFix);
			for (;;)
			{

				for (; !_kbhit();)
				{
					if (Reply == 0)
					{

						if (IntroTimer == 24 && k == 1)
						{
							ClickFix = 1;
						}
						if (k > 1)
						{
							ClickFix = 1;

						}
						if (startgame == 1)
						{
							break;
						}
					}

					if (Reply == 1)
					{
						SetConsoleTextAttribute(hConsole, 15);
						Scene = 0;
						counterFS = 2;
						r1OFS1 = -5;
						r1OFS2 = 1;
						r1OFS3 = 11;
						r1OFS4 = 15;
						r1OFS5 = 20;

						c1OFS1 = 100;
						c1OFS2 = 108;
						c1OFS3 = 118;
						c1OFS4 = 123;
						c1OFS5 = 128;

						///////////////////////////
						r2OFS2 = -5;
						r2OFS1 = 1;
						r2OFS3 = 5;
						r2OFS5 = 12;
						r2OFS4 = 22;

						c2OFS2 = 37;
						c2OFS1 = 31;
						c2OFS3 = 27;
						c2OFS5 = 19;//5
						c2OFS4 = 10;//5

						counterFS2 = 2;
						timerFS = 0;
						rCarFS = -18;
						cCarFS = 56;
						rEnemyFS = 14;
						cEnemyFS = 68;
						rH = 30;
						cH = 86;

						ReplyF(z, counterFS, timerFS, rH, cH, counterFS2, rCarFS, cCarFS, Reply, Scene, level, r1OFS1, r1OFS2, r1OFS3, r1OFS4, r1OFS5, c1OFS1, c1OFS2, c1OFS3, c1OFS4, c1OFS5, r2OFS1, r2OFS2, r2OFS3, r2OFS4, r2OFS5, c2OFS1, c2OFS2, c2OFS3, c2OFS4, c2OFS5, rEnemyFS, cEnemyFS);

					}

					if (Reply == 2)
					{
						system("cls");
						SetConsoleTextAttribute(hConsole, 11);

						Reply = 0;
						MainMenu(k, ClickFix);
					}
				}

				char kboard000 = _getch();
				InsideMenu(kboard000, P, startgame, H1, H2, H3, HScounter, k, ks, ClickFix, Reply);
				if (startgame == 1)
				{
					break;
				}
			}

			if (Scene > 0)
			{
				level++;
			}

		}


		SetConsoleTextAttribute(hConsole, 11);

		if (Scene == 0 && level == 0 && Reply == 0)
		{
			SetConsoleTextAttribute(hConsole, 15);
			rH = 30;
			cH = 86;
			for (;;)
			{
				for (; !_kbhit();)
				{
					MapFS(z, counterFS, timerFS);
					SObjectsFS1(z, r1OFS1, r1OFS2, r1OFS3, r1OFS4, r1OFS5, c1OFS1, c1OFS2, c1OFS3, c1OFS4, c1OFS5);
					if (timerFS <= 15)
					{
						DObjectsFS1(z, r1OFS1, r1OFS2, r1OFS3, r1OFS4, r1OFS5, c1OFS1, c1OFS2, c1OFS3, c1OFS4, c1OFS5);
					}
					StaticHeroFS(z, rH, cH, counterFS2, timerFS);

					SObjectsFS2(z, r2OFS1, r2OFS2, r2OFS3, r2OFS4, r2OFS5, c2OFS1, c2OFS2, c2OFS3, c2OFS4, c2OFS5);

					if (timerFS <= 15)
					{
						DObjectsFS2(z, r2OFS1, r2OFS2, r2OFS3, r2OFS4, r2OFS5, c2OFS1, c2OFS2, c2OFS3, c2OFS4, c2OFS5);
					}
					for (int row = rCarFS - 1, n = 0; n < 19; row++, n++)
					{
						for (int col = cCarFS - 12, m = 0; m < 38; col++, m++)
						{
							z[row][col] = ' ';
						}
					}
					CarFS(z, rCarFS, cCarFS);
					DynCarFS(z, rCarFS, cCarFS);
					if (timerFS > 12)
					{
						for (int row = rEnemyFS - 2, n = 0; n < 11; row++, n++)
						{
							for (int col = cEnemyFS - 2, m = 0; m < 6; col++, m++)
							{
								z[row][col] = ' ';
							}
						}
						EnemyFS(z, rEnemyFS, cEnemyFS);
					}
					if (timerFS > 15 && timerFS <= 20)
					{
						z[13][75] = 'Y';
						z[13][76] = 'o';
						z[13][77] = 'u';
						z[13][78] = ' ';
						z[13][79] = 'a';
						z[13][80] = 'r';
						z[13][81] = 'e';
						z[13][82] = ' ';
						z[13][83] = 'u';
						z[13][84] = 'n';
						z[13][85] = 'd';
						z[13][86] = 'e';
						z[13][87] = 'r';
						z[13][88] = ' ';
						z[13][89] = 'a';
						z[13][90] = 'r';
						z[13][91] = 'r';
						z[13][92] = 'e';
						z[13][93] = 's';
						z[13][94] = 't';



					}
					if (timerFS > 20 && timerFS <= 25)
					{
						z[13][75] = 'f';
						z[13][76] = 'o';
						z[13][77] = 'r';
						z[13][78] = ' ';
						z[13][79] = 'k';
						z[13][80] = 'i';
						z[13][81] = 'l';
						z[13][82] = 'l';
						z[13][83] = 'i';
						z[13][84] = 'n';
						z[13][85] = 'g';
						z[13][86] = ' ';
						z[13][87] = 'p';
						z[13][88] = 'e';
						z[13][89] = 'o';
						z[13][90] = 'p';
						z[13][91] = 'l';
						z[13][92] = 'e';
						z[13][93] = ' ';
						z[13][94] = ' ';



					}
					if (timerFS > 25 && timerFS <= 30)
					{
						z[13][91] = 'I';
						z[13][92] = ' ';
						z[13][93] = 'w';
						z[13][94] = 'o';
						z[13][95] = 'n';
						z[13][96] = '`';
						z[13][97] = 't';
						z[13][98] = ' ';
						z[13][99] = 'g';
						z[13][100] = 'i';
						z[13][101] = 'v';
						z[13][102] = 'e';
						z[13][103] = ' ';
						z[13][104] = 'u';
						z[13][105] = 'p';
					}

					if (timerFS > 30 && timerFS <= 35)
					{
						z[13][75] = 'Y';
						z[13][76] = 'o';
						z[13][77] = 'u';
						z[13][78] = ' ';
						z[13][79] = 'w';
						z[13][80] = 'i';
						z[13][81] = 'l';
						z[13][82] = 'l';
						z[13][83] = ' ';
						z[13][84] = 'r';
						z[13][85] = 'e';
						z[13][86] = 'g';
						z[13][87] = 'r';
						z[13][88] = 'e';
						z[13][89] = 't';
						z[13][90] = ' ';
						z[13][91] = 'f';
						z[13][92] = 'o';
						z[13][93] = 'r';
						z[13][94] = ' ';
						z[13][95] = 't';
						z[13][96] = 'h';
						z[13][97] = 'a';
						z[13][98] = 't';
					}

					if (timerFS > 35 && timerFS <= 43)
					{
						z[13][91] = 'W';
						z[13][92] = 'e';
						z[13][93] = ' ';
						z[13][94] = 'w';
						z[13][95] = 'i';
						z[13][96] = 'l';
						z[13][97] = 'l';
						z[13][98] = ' ';
						z[13][99] = 's';
						z[13][100] = 'e';
						z[13][101] = 'e';
						z[13][102] = ' ';
						z[13][103] = 'w';
						z[13][104] = 'h';
						z[13][105] = 'o';
						z[13][106] = ' ';
						z[13][107] = 'w';
						z[13][108] = 'i';
						z[13][109] = 'l';
						z[13][110] = 'l';
					}

					if (timerFS > 45)
					{
						break;
					}
					OutputFS(z);
					Scene++;
					counterFS++;
					counterFS2++;
					timerFS++;
				}

				if (timerFS >= 0)
				{
					level++;
					break;

				}
				if (timerFS > 45)
				{
					level++;
					break;

				}
			}
		}

		SetConsoleTextAttribute(hConsole, 11);
		if (tryagain == 3)
		{
			system("cls");
			cout << "\nNick-name: ";
			for (;;)
			{
				gets_s(P[k].PlayerName);
				if (P[k].PlayerName[0] == 32 || P[k].PlayerName[0] == NULL || P[k].PlayerName[0] == '`')
				{
					system("cls");
					cout << "\nNick-name: ";
				}
				else
				{
					break;
				}
			}

		}




		cout << "\a";




		ScrollCounter = 1;
		if (level == 1)
		{
			rH = 36;
			cH = 8;
			SetConsoleTextAttribute(hConsole, 2);
			for (;;)
			{
				for (; !_kbhit(); )
				{
					GameMap(x, level);

				

					StaticObjects(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9);
					DynamicObjects_2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, AutoWalk);
					
					////FIXED SG2


					StaticFloor(x, cF, CounterFloor, level);
					SElev(x, rEv, cEv, rH, cH, GetOut, openG, rEvR);
					DElev(x, rEv, cEv, rH, cH, GetOut, countRLHL1, openG, rEvR);
					Floor_Elev(x, rFEv, cFEv, FloorNumber, GetOut, FloorNumberCount);
					StaticHero(x, rH, cH, countRLHL1, CountStart, LeftLook, rEv, Reload, ActionReload, level, rB, cB);



					StaticEnemy(x, cE1, rE1, CounterUntilStop, countRLEL1, Reload, ActionReload, level, rB, cB);
					DynamicEnemy(x, cE1, rE1, CounterUntilStop, countRLEL1, rEG1, cEG1, countG1, GetOut);

					StaticEnemy2(x, cE2, rE2, CounterUntilStop, countRLEL1, Reload, ActionReload, level, rB, cB);
					DynamicEnemy2(x, cE2, rE2, CounterUntilStop, countRLEL2, rEG2, cEG2, countG2, GetOut);

					StaticGunShot(x, rE1, cE1, rEG1, cEG1, countG1, CounterUntilStop, GetOut);
					DynamicGunShot(x, rE1, cE1, rEG1, cEG1, countG1, CounterUntilStop, rH, cH, shoot1, GetOut, DelayShot, lose1, DeathT);

					StaticGunShot2(x, rE2, cE2, rEG2, cEG2, countG2, CounterUntilStop, GetOut);
					DynamicGunShot2(x, rE2, cE2, rEG2, cEG2, countG2, CounterUntilStop, rH, cH, shoot1, GetOut, DelayShot, DeathT);



					//////////
					////FIXED DG2
					CounterFloor++;
					ToLand(x, rH, cH, flag1, GetOut, LeftLook, level, rEv, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					JumpReaction(x, rH, cH, flag1, GetOut, LeftLook, level, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					TimeCounter(x, mins, secs, CounterUntilStop, lose1, DeathT, level, shoot1);
					HealthBar(x, rH, cH, shoot1, lose1, DeathT, level, countHearts, countHearts2, mins);
					AutoForward(x, rH, cH, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, Reload, ActionReload, AutoWalk);
					LevelCounter(x, level);
					if (AutoWalk == 0)
					{
						AutoBackward(x, rH, cH, lose1, pass1, pass2, cF, LeftLook, CounterUntilStop, cO1, cC, rO1, DeathT, countRLHL1, level);
					}
					Constructor(x, rH, cH, ConstructorCount, timer, CounterUntilStop, rGuide, cGuide, cC, level, GetOut, timer2, timer3, BSc, flagScore1, flagScore2, flagScore3, timer4, flagTime1, flagTime2, flagTime3, TSc, mins, flagScore4, flagTime4, timer5, win, timerBSC, rFC, cFC, TelephRide);
					HighScore(x, rH, cH, Scounter, CounterUntilStop, HScounter, level, shoot1, flagScore1, flagScore2, flagScore3, AutoWalk);

					if (cH - 3 < 0)
					{
						lose1 = 1;
						DeathT = 0;
					}

					if (level == 2)
					{
						if (shoot1 == 1 || shoot1 == 0)
						{
							Scounter += 1000;
							flagScore1 = 1;
							if (mins == 8)
							{
								mins++;
								flagTime1 = 1;
							}
							if (mins < 8)
							{
								mins += 2;
								flagTime1 = 2;
							}
						}
						shoot1 = 0;
						GetOut = 0;
						rO1 = -2;
						rO2 = -2;
						rO3 = -2;
						rO4 = -2;
						rO5 = -2;
						rO6 = -2;
						rO7 = -2;
						rO9 = -2;
						break;
					}
					if (lose1 == 1)
					{
						break;
					}

					Output(x, ScrollCounter, cH);
					timer++;
					CounterUntilStop++;

				}

				if (level == 2)
				{
					rH = 36;
					cH = 8;
					break;
				}

				if (lose1 == 1)
				{
					break;
				}


				char kboard = _getch();
				//DynamicHero(x, rH, cH, kboard, countRLHL1, flag1, CounterUntilStop, pass1,pass2,  lose1, ScrollCounter, GetOut,  LeftLook,  rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct,win, rEvR, mins,secs, sand, CountStart, rF, cF, CounterFloor,timer, ScrollDelay, cEv,OneTime, rGuide,cGuide,OneTime, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, cC, rE1, cE1, rE2, cE2, rEG1, cEG1, rEG2, cEG2, countRLEL1, countRLEL2, countG1, countG2, timer2, timer3, timer4, timer5, DelayShot, Scounter, GameOver, cCar1, rCar1, cCar2, rCar2, countCar1, ratio1, flagC, countHearts, countHearts2, flagScore1, flagScore2, flagScore3, flagScore4, flagTime1, flagTime2, flagTime3, flagTime4, BSc, TSc, openG, rPlane1, cPlane1, rPlane2, cPlane2, rPlane3, cPlane3, ratio2, flagP2, flagP22, rPG1, rPG2, rPG3, cPG1, cPG2, cPG3, rT, cT, tap4, countMyShot, ShootON, countShots,Reload, ActionReload, rBB, cBB, gotshot, firsttime,timerBSC, rFC, cFC, flag6C);
				DynamicHero(x, rH, cH, kboard, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, AutoWalk, AutoWalkCounter);

				DynamicObjects(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, kboard, AutoWalk);


			}

		}


		if (level == 2)
		{
			GetOut = 0;
			rO1 = -2;
			rO2 = -2;
			rO3 = -2;
			rO4 = -2;
			rO5 = -2;
			rO6 = -2;
			rO7 = -2;
			rO9 = -2;
			SetConsoleTextAttribute(hConsole, 3);
			for (;;)
			{
				for (; !_kbhit(); )
				{

					CounterUntilStop = 25;
					GameMap(x, level);



					StaticObjects2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9);
					DynamicObjects2_2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, AutoWalk);

					StaticFloor(x, cF, CounterFloor, level);

					StaticHero(x, rH, cH, countRLHL1, CountStart, LeftLook, rEv, Reload, ActionReload, level, rB, cB);

					//PlaySound(TEXT("cars.wav"),NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
					StaticCar1(x, cCar1, rCar1, cH, rH, level, countCar1, ratio1);
					if (timer2 >= 7)
					{

						DynamicCar1(x, cCar1, rCar1, cH, rH, level, countCar1, lose1, DeathT, shoot1, ratio1, cCar2, rCar2, flagC, timer2, cCar2);

						StaticCar2(x, cCar2, rCar2, cH, rH, level, countCar1, ratio1, flagC);
						DynamicCar2(x, cCar2, rCar2, cH, rH, level, countCar1, lose1, DeathT, shoot1, ratio1, flagC);
					}
					CounterFloor++;
					ToLand(x, rH, cH, flag1, GetOut, LeftLook, level, rEv, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					JumpReaction(x, rH, cH, flag1, GetOut, LeftLook, level, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					TimeCounter(x, mins, secs, CounterUntilStop, lose1, DeathT, level, shoot1);
					HealthBar(x, rH, cH, shoot1, lose1, DeathT, level, countHearts, countHearts2, mins);
					LevelCounter(x, level);
					AutoForward(x, rH, cH, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, Reload, ActionReload, AutoWalk);

					//AutoBackward(x, rH, cH, lose1, pass1, pass2, cF, LeftLook, CounterUntilStop, cO1, cC, rO1, DeathT, countRLHL1, level);
					Constructor(x, rH, cH, ConstructorCount, timer, CounterUntilStop, rGuide, cGuide, cC, level, GetOut, timer2, timer3, BSc, flagScore1, flagScore2, flagScore3, timer4, flagTime1, flagTime2, flagTime3, TSc, mins, flagScore4, flagTime4, timer5, win, timerBSC, rFC, cFC, TelephRide);
					HighScore(x, rH, cH, Scounter, CounterUntilStop, HScounter, level, shoot1, flagScore1, flagScore2, flagScore3, AutoWalk);

					if (cH - 3 < 0)
					{
						lose1 = 1;
						DeathT = 0;
					}

					if (level == 3)
					{

						if (shoot1 == 1 || shoot1 == 0)
						{
							Scounter += 3000;
							flagScore2 = 1;
							if (mins == 8)
							{
								mins++;
								flagTime2 = 1;
							}
							if (mins < 8)
							{
								mins += 2;
								flagTime2 = 2;
							}
						}

						shoot1 = 0;
						break;
					}



					if (lose1 == 1)
					{
						break;
					}

					Output(x, ScrollCounter, cH);



					timer2++;
					BSc++;
					TSc++;
					countCar1++;

				}

				if (level == 3)
				{

					break;
				}

				if (lose1 == 1)
				{
					break;
				}


				char kboard2 = _getch();
				DynamicHero(x, rH, cH, kboard2, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, AutoWalk, AutoWalkCounter);
				//DynamicHero(x, rH, cH, kboard2, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, mins, secs, sand, CountStart, rF, cF, CounterFloor, timer, ScrollDelay, cEv, OneTime, rGuide, cGuide, OneTime, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, cC, rE1, cE1, rE2, cE2, rEG1, cEG1, rEG2, cEG2, countRLEL1, countRLEL2, countG1, countG2, timer2, timer3, timer4, timer5, DelayShot, Scounter, GameOver, cCar1, rCar1, cCar2, rCar2, countCar1, ratio1, flagC, countHearts, countHearts2, flagScore1, flagScore2, flagScore3, flagScore4, flagTime1, flagTime2, flagTime3, flagTime4, BSc, TSc, openG, rPlane1, cPlane1, rPlane2, cPlane2, rPlane3, cPlane3, ratio2, flagP2, flagP22, rPG1, rPG2, rPG3, cPG1, cPG2, cPG3, rT, cT, tap4, countMyShot, ShootON, countShots, Reload, ActionReload, rBB, cBB, gotshot, firsttime, timerBSC, rFC, cFC, flag6C);
				DynamicObjects2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, kboard2, AutoWalk);////FIXED



			}

		}

		BSc = 128;
		TSc = 64;

		if (level == 3)
		{

			SetConsoleTextAttribute(hConsole, 6);
			cH = 8;
			rH = 36;
			rO1 = 10;
			rO2 = 10;
			rO3 = 10;
			rO4 = 10;
			rO5 = 10;
			rO6 = 10;
			rO7 = 10;
			rO9 = 10;
			for (;;)
			{
				for (; !_kbhit(); )
				{

					CounterUntilStop = 25;
					GameMap(x, level);



					StaticObjects2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9);
					DynamicObjects2_2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, AutoWalk);

					StaticFloor(x, cF, CounterFloor, level);

					StaticHero(x, rH, cH, countRLHL1, CountStart, LeftLook, rEv, Reload, ActionReload, level, rB, cB);
					StaticPlane1(x, rPlane1, cPlane1, rH, cH, level, ratio2);
					if (timer3 >= 7)
					{

						DynamicPlane1(x, rPlane1, cPlane1, rH, cH, level, ratio2, cPlane2, flagP2, cPlane3, rPlane2, rPlane3);

						StaticPlane2(x, rPlane2, cPlane2, rH, cH, level, ratio2, flagP2);
						DynamicPlane2(x, rPlane2, cPlane2, rH, cH, level, ratio2, flagP2);

						StaticPlane3(x, rPlane3, cPlane3, rH, cH, level, ratio2, flagP22);
						DynamicPlane3(x, rPlane3, cPlane3, rH, cH, level, ratio2, flagP22);



						StaticPlaneShot1(x, rPG1, cPG1, rPG2, cPG2, rPG3, cPG3, ratio2, rPlane1, cPlane1, rPlane2, cPlane2, rPlane3, cPlane3, shoot1, rH, cH, DeathT);
						DynamicPlaneShot1(x, rPG1, cPG1, rPG2, cPG2, rPG3, cPG3, ratio2, rPlane1, cPlane1, rPlane2, cPlane2, rPlane3, cPlane3, shoot1, rH, cH, DeathT);
					}
					StaticSkate(x, rSkate, cSkate, rH, cH, SkateIn);

					CounterFloor++;
					ToLand(x, rH, cH, flag1, GetOut, LeftLook, level, rEv, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					JumpReaction(x, rH, cH, flag1, GetOut, LeftLook, level, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					TimeCounter(x, mins, secs, CounterUntilStop, lose1, DeathT, level, shoot1);
					HealthBar(x, rH, cH, shoot1, lose1, DeathT, level, countHearts, countHearts2, mins);
					LevelCounter(x, level);
					AutoForward(x, rH, cH, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, Reload, ActionReload, AutoWalk);

					//AutoBackward(x, rH, cH, lose1, pass1, pass2, cF, LeftLook, CounterUntilStop, cO1, cC, rO1, DeathT, countRLHL1, level);
					Constructor(x, rH, cH, ConstructorCount, timer, CounterUntilStop, rGuide, cGuide, cC, level, GetOut, timer2, timer3, BSc, flagScore1, flagScore2, flagScore3, timer4, flagTime1, flagTime2, flagTime3, TSc, mins, flagScore4, flagTime4, timer5, win, timerBSC, rFC, cFC, TelephRide);
					HighScore(x, rH, cH, Scounter, CounterUntilStop, HScounter, level, shoot1, flagScore1, flagScore2, flagScore3, AutoWalk);

					if (cH - 3 < 0)
					{
						lose1 = 1;
						DeathT = 0;
					}

					if (level == 4)
					{

						if (shoot1 == 1 || shoot1 == 0)
						{
							Scounter += 6000;
							flagScore3 = 1;
							if (mins == 8)
							{
								mins++;
								flagTime3 = 1;
							}
							if (mins < 8)
							{
								mins += 2;
								flagTime3 = 2;
							}
						}

						shoot1 = 0;

						break;
					}

					if (lose1 == 1)
					{
						//SetConsoleTextAttribute(hConsole, 4);
						break;
					}

					timer3++;
					BSc++;
					TSc++;
					Output(x, ScrollCounter, cH);
					HealthBar(x, rH, cH, shoot1, lose1, DeathT, level, countHearts, countHearts2, mins);

				}

				if (level == 4)
				{
					cH = 4;
					rH = 36;
					break;
				}

				if (lose1 == 1)
				{

					break;
				}

				char kboard3 = _getch();

				DynamicHero(x, rH, cH, kboard3, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, AutoWalk, AutoWalkCounter);
				//DynamicHero(x, rH, cH, kboard3, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, mins, secs, sand, CountStart, rF, cF, CounterFloor, timer, ScrollDelay, cEv, OneTime, rGuide, cGuide, OneTime, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, cC, rE1, cE1, rE2, cE2, rEG1, cEG1, rEG2, cEG2, countRLEL1, countRLEL2, countG1, countG2, timer2, timer3, timer4, timer5, DelayShot, Scounter, GameOver, cCar1, rCar1, cCar2, rCar2, countCar1, ratio1, flagC, countHearts, countHearts2, flagScore1, flagScore2, flagScore3, flagScore4, flagTime1, flagTime2, flagTime3, flagTime4, BSc, TSc, openG, rPlane1, cPlane1, rPlane2, cPlane2, rPlane3, cPlane3, ratio2, flagP2, flagP22, rPG1, rPG2, rPG3, cPG1, cPG2, cPG3, rT, cT, tap4, countMyShot, ShootON, countShots, Reload, ActionReload, rBB, cBB, gotshot, firsttime, timerBSC, rFC, cFC, flag6C);

				DynamicObjects2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, kboard3, AutoWalk);////FIXED



			}

		}

		BSc = 128;
		TSc = 64;

		if (level == 4)
		{

			CounterUntilStop = 25;
			rO1 = -2;
			rO2 = -2;
			rO3 = -2;
			rO4 = -2;
			rO5 = -2;
			rO6 = -2;
			rO7 = -2;
			rO9 = -2;
			SetConsoleTextAttribute(hConsole, 5);
			for (;;)
			{
				for (; !_kbhit(); )
				{

					GameMap(x, level);

					StaticObjects2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9);
					DynamicObjects2_2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, AutoWalk);

					Constructor(x, rH, cH, ConstructorCount, timer, CounterUntilStop, rGuide, cGuide, cC, level, GetOut, timer2, timer3, BSc, flagScore1, flagScore2, flagScore3, timer4, flagTime1, flagTime2, flagTime3, TSc, mins, flagScore4, flagTime4, timer5, win, timerBSC, rFC, cFC, TelephRide);
					StaticFloor4(x, cF, CounterFloor, level, rT, cT, rR, cR);

					StaticHero(x, rH, cH, countRLHL1, CountStart, LeftLook, rEv, Reload, ActionReload, level, rB, cB);

					CheckTrap(x, rH, cH, DeathT, shoot1, rR, cR, RopeIn, tap4);

					CounterFloor++;
					ToLand(x, rH, cH, flag1, GetOut, LeftLook, level, rEv, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					JumpReaction(x, rH, cH, flag1, GetOut, LeftLook, level, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					TimeCounter(x, mins, secs, CounterUntilStop, lose1, DeathT, level, shoot1);
					HealthBar(x, rH, cH, shoot1, lose1, DeathT, level, countHearts, countHearts2, mins);
					LevelCounter(x, level);
					AutoForward(x, rH, cH, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, Reload, ActionReload, AutoWalk);

					//AutoBackward(x, rH, cH, lose1, pass1, pass2, cF, LeftLook, CounterUntilStop, cO1, cC, rO1, DeathT, countRLHL1, level);
					HighScore(x, rH, cH, Scounter, CounterUntilStop, HScounter, level, shoot1, flagScore1, flagScore2, flagScore3, AutoWalk);

					if (cH - 3 < 0)
					{
						lose1 = 1;
						DeathT = 0;
					}

					if (level == 5)
					{

						if (shoot1 == 1 || shoot1 == 0 || shoot1 == 2)
						{
							Scounter += 10000;
							flagScore4 = 1;
							if (mins == 8)
							{
								mins++;
								flagTime4 = 1;
							}
							if (mins < 8)
							{
								mins += 2;
								flagTime4 = 2;
							}
						}

						shoot1 = 0;
						break;
					}



					if (lose1 == 1)
					{
						break;
					}

					Output(x, ScrollCounter, cH);



					timer4++;
					BSc++;
					TSc++;


				}


				if (level == 5)
				{
					cH = 8;
					rH = 36;
					break;
				}

				if (lose1 == 1)
				{
					break;
				}

				char kboard4 = _getch();
				DynamicHero(x, rH, cH, kboard4, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, AutoWalk, AutoWalkCounter);
				//DynamicHero(x, rH, cH, kboard4, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, mins, secs, sand, CountStart, rF, cF, CounterFloor, timer, ScrollDelay, cEv, OneTime, rGuide, cGuide, OneTime, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, cC, rE1, cE1, rE2, cE2, rEG1, cEG1, rEG2, cEG2, countRLEL1, countRLEL2, countG1, countG2, timer2, timer3, timer4, timer5, DelayShot, Scounter, GameOver, cCar1, rCar1, cCar2, rCar2, countCar1, ratio1, flagC, countHearts, countHearts2, flagScore1, flagScore2, flagScore3, flagScore4, flagTime1, flagTime2, flagTime3, flagTime4, BSc, TSc, openG, rPlane1, cPlane1, rPlane2, cPlane2, rPlane3, cPlane3, ratio2, flagP2, flagP22, rPG1, rPG2, rPG3, cPG1, cPG2, cPG3, rT, cT, tap4, countMyShot, ShootON, countShots, Reload, ActionReload, rBB, cBB, gotshot, firsttime, timerBSC, rFC, cFC, flag6C);

				DynamicObjects2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, kboard4, AutoWalk);////FIXED

			}
		}

		BSc = 128;
		TSc = 64;

		if (level == 5)
		{
			BSc = 128;

			SetConsoleTextAttribute(hConsole, 12);
			CounterUntilStop = 25;
			rO1 = -2;
			rO2 = -2;
			rO3 = -2;
			rO4 = -2;
			rO5 = -2;
			rO6 = -2;
			rO7 = -2;
			rO9 = -2;
			for (;;)
			{
				for (; !_kbhit(); )
				{
					GameMap(x, level);



					StaticObjects2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9);
					DynamicObjects2_2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, AutoWalk);

					StaticFloor(x, cF, CounterFloor, level);

					StaticHero5(x, rH, cH, countRLHL1, CountStart, LeftLook, Reload, ActionReload, level, rB, cB);


					StaticBigBoss(x, rH, cH, rBB, cBB, win);

					MyStaticShot(x, rH, cH, rMS1, cMS1, rMS2, cMS2, countRLHL1, countMyShot, ShootON, countShots, rB);
					MyDynamicShot(x, rH, cH, rMS1, cMS1, rMS2, cMS2, countRLHL1, countMyShot, ShootON, Reload, ActionReload, rB, ct, gotshot, cBB, rBB, ShootON);

					if (win == 0)
					{
						StaticBigBossShot(x, rH, cH, rBBS1, cBBS1, rBBS2, cBBS2, when);
						DynamicBigBossShot(x, rH, cH, rBBS1, cBBS1, rBBS2, cBBS2, DeathT, shoot1, rBB, cBB, when);
					}
					if (rB + 4 < 47)
					{
						if (rB + 4 > 47)
						{
							rB = 43;

						}
						rB += 5;

						if (rB + 4 > 47)
						{
							rB = 43;

						}

					}
					CounterFloor++;
					ToLand(x, rH, cH, flag1, GetOut, LeftLook, level, rEv, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					JumpReaction(x, rH, cH, flag1, GetOut, LeftLook, level, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					TimeCounter(x, mins, secs, CounterUntilStop, lose1, DeathT, level, shoot1);
					HealthBar(x, rH, cH, shoot1, lose1, DeathT, level, countHearts, countHearts2, mins);
					BigBossHealthBar(x, rH, cH, gotshot, win, mins, rBB, cBB);
					LevelCounter(x, level);
					AutoForward(x, rH, cH, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, Reload, ActionReload, AutoWalk);

					//AutoBackward(x, rH, cH, lose1, pass1, pass2, cF, LeftLook, CounterUntilStop, cO1, cC, rO1, DeathT, countRLHL1, level);
					Constructor(x, rH, cH, ConstructorCount, timer, CounterUntilStop, rGuide, cGuide, cC, level, GetOut, timer2, timer3, BSc, flagScore1, flagScore2, flagScore3, timer4, flagTime1, flagTime2, flagTime3, TSc, mins, flagScore4, flagTime4, timer5, win, timerBSC, rFC, cFC, TelephRide);
					HighScore(x, rH, cH, Scounter, CounterUntilStop, HScounter, level, shoot1, flagScore1, flagScore2, flagScore3, AutoWalk);

					if (cH - 3 < 0)
					{
						lose1 = 1;
						DeathT = 0;
					}

					if (level == 6)
					{

						break;
					}

					if (lose1 == 1)
					{
						break;
					}

					if (win == 1 && firsttime == 1)
					{
						Scounter += 20000;
						firsttime = 2;
					}
					if (win >= 1)
					{
						if (win == 1)
						{
							BSc = 128;
							win++;
						}
						timerBSC++;
						BSc++;
					}
					Output(x, ScrollCounter, cH);

					timer5++;
					BSc++;
					TSc++;

					ct++;
				}

				if (level == 6)
				{

					break;
				}

				if (lose1 == 1)
				{
					break;
				}

				char kboard5 = _getch();
				DynamicHero(x, rH, cH, kboard5, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, AutoWalk, AutoWalkCounter);
				//DynamicHero(x, rH, cH, kboard5, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, mins, secs, sand, CountStart, rF, cF, CounterFloor, timer, ScrollDelay, cEv, OneTime, rGuide, cGuide, OneTime, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, cC, rE1, cE1, rE2, cE2, rEG1, cEG1, rEG2, cEG2, countRLEL1, countRLEL2, countG1, countG2, timer2, timer3, timer4, timer5, DelayShot, Scounter, GameOver, cCar1, rCar1, cCar2, rCar2, countCar1, ratio1, flagC, countHearts, countHearts2, flagScore1, flagScore2, flagScore3, flagScore4, flagTime1, flagTime2, flagTime3, flagTime4, BSc, TSc, openG, rPlane1, cPlane1, rPlane2, cPlane2, rPlane3, cPlane3, ratio2, flagP2, flagP22, rPG1, rPG2, rPG3, cPG1, cPG2, cPG3, rT, cT, tap4, countMyShot, ShootON, countShots, Reload, ActionReload, rBB, cBB, gotshot, firsttime, timerBSC, rFC, cFC, flag6C);

				DynamicObjects2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, kboard5, AutoWalk);////FIXED

			}
		}

		BSc = 128;
		TSc = 64;

		if (level == 6)
		{
			rH = 36;
			cH = 4;
			rO1 = -2;
			rO2 = -2;
			rO3 = -2;
			rO4 = -2;
			rO5 = -2;
			rO6 = -2;
			rO7 = -2;
			rO9 = -2;

			SetConsoleTextAttribute(hConsole, 11);
			CounterUntilStop = 25;

			for (;;)
			{
				for (; !_kbhit(); )
				{

					GameMap6(x, level, TelephRide, ladder, rH, cH);

					StaticObjects2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9);
					DynamicObjects2_2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, AutoWalk);

					////FIXED

					StaticFloor(x, cF, CounterFloor, level);

					if (TelephRide == 1 && ladder == 0)
					{
						cH = 24;
						rH = 30;
						TelephRide = 2;
						StaticHero6(x, rH, cH, countRLHL1, CountStart, LeftLook, rEv, Reload, ActionReload, level, rB, cB, DeathT, lose1);
					}
					if (TelephRide == 2 && ladder == 0)
					{
						StaticHero6(x, rH, cH, countRLHL1, CountStart, LeftLook, rEv, Reload, ActionReload, level, rB, cB, DeathT, lose1);
					}
					if (TelephRide == 0 && ladder == 0)
					{
						StaticHero(x, rH, cH, countRLHL1, CountStart, LeftLook, rEv, Reload, ActionReload, level, rB, cB);
					}
					if (TelephRide == 0 && ladder == 1)
					{
						cH = 24;
						rH = 35;
						ladder = 2;
						StaticHero6_2(x, rH, cH, countRLHL1);
					}
					if (TelephRide == 0 && ladder == 2)
					{
						StaticHero6_2(x, rH, cH, countRLHL1);
					}
					Telepherique(x, rH, cH, rT6, cT6, cFC);
					CounterFloor++;
					//ToLand(x, rH, cH, flag1, GetOut, LeftLook, level, rEv, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					//JumpReaction(x, rH, cH, flag1, GetOut, LeftLook, level, SkateIn, rSkate, cSkate, RopeIn, cR, tap4);
					TimeCounter(x, mins, secs, CounterUntilStop, lose1, DeathT, level, shoot1);
					HealthBar(x, rH, cH, shoot1, lose1, DeathT, level, countHearts, countHearts2, mins);
					LevelCounter(x, level);
					AutoForward(x, rH, cH, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, Reload, ActionReload, AutoWalk);

					//AutoBackward(x, rH, cH, lose1, pass1, pass2, cF, LeftLook, CounterUntilStop, cO1, cC, rO1, DeathT, countRLHL1, level);

					Constructor(x, rH, cH, ConstructorCount, timer, CounterUntilStop, rGuide, cGuide, cC, level, GetOut, timer2, timer3, BSc, flagScore1, flagScore2, flagScore3, timer4, flagTime1, flagTime2, flagTime3, TSc, mins, flagScore4, flagTime4, timer5, win, timerBSC, rFC, cFC, TelephRide);

					HighScore(x, rH, cH, Scounter, CounterUntilStop, HScounter, level, shoot1, flagScore1, flagScore2, flagScore3, AutoWalk);
					if (level == 7)
					{
						DeathT = 10;
						break;
					}
					Output(x, ScrollCounter, cH);


				}


				if (level == 7)
				{
					DeathT = 10;
					break;
				}
				char kboard6 = _getch();
				DynamicHero(x, rH, cH, kboard6, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, cT6, cFC, TelephRide, ladder, AutoWalk, AutoWalkCounter);
				//DynamicHero(x, rH, cH, kboard6, countRLHL1, flag1, CounterUntilStop, pass1, pass2, lose1, ScrollCounter, GetOut, LeftLook, rEv, level, DeathT, shoot1, SkateIn, rSkate, cSkate, RopeIn, rR, cR, rMS1, cMS1, rMS2, cMS2, ShootON, countShots, rB, cB, ct, win, rEvR, mins, secs, sand, CountStart, rF, cF, CounterFloor, timer, ScrollDelay, cEv, OneTime, rGuide, cGuide, OneTime, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, cC, rE1, cE1, rE2, cE2, rEG1, cEG1, rEG2, cEG2, countRLEL1, countRLEL2, countG1, countG2, timer2, timer3, timer4, timer5, DelayShot, Scounter, GameOver, cCar1, rCar1, cCar2, rCar2, countCar1, ratio1, flagC, countHearts, countHearts2, flagScore1, flagScore2, flagScore3, flagScore4, flagTime1, flagTime2, flagTime3, flagTime4, BSc, TSc, openG, rPlane1, cPlane1, rPlane2, cPlane2, rPlane3, cPlane3, ratio2, flagP2, flagP22, rPG1, rPG2, rPG3, cPG1, cPG2, cPG3, rT, cT, tap4, countMyShot, ShootON, countShots, Reload, ActionReload, rBB, cBB, gotshot, firsttime, timerBSC, rFC, cFC, flag6C);

				DynamicObjects2(x, cO1, rO1, cO2, rO2, cO3, rO3, cO4, rO4, cO5, rO5, cO6, rO6, cO7, rO7, cO8, rO8, cO9, rO9, CounterUntilStop, level, kboard6, AutoWalk);
			}


		}


		system("cls");

		SetConsoleTextAttribute(hConsole, 15);
		P[ks].TemprScore = Scounter;
		ks++;


		cout << "\a";
		for (;;)
		{
			system("cls");
			if (DeathT == 0)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Game Over!, the road killed you\n\n";
				cout << "\t\t\t\t\t\t         Play again? y/n : ";
				cin >> noskipws >> playerchoice;

			}
			if (DeathT == 1)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tGame Over!, you passed the 10 minutes..\n\n";
				cout << "\t\t\t\t\t\t        Play again? y/n : ";
				cin >> noskipws >> playerchoice;

			}
			if (DeathT == 2)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\bGame Over!, the police man arrested you\n\n";
				cout << "\t\t\t\t\t\t\b           Play again? y/n : ";
				cin >> noskipws >> playerchoice;


			}
			if (DeathT == 3)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\b\b\b\bGame Over!, you have been killed by the shooters\n\n";
				cout << "\t\t\t\t\t\t\b\b\b\b              Play again? y/n : ";
				cin >> noskipws >> playerchoice;

			}
			if (DeathT == 4)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Game Over!, You got arrested by the FBI cars\n\n";
				cout << "\t\t\t\t\t\t            Play again? y/n : ";
				cin >> noskipws >> playerchoice;

			}
			if (DeathT == 5)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Game Over!, You got killed by the F-16\n\n";
				cout << "\n\t\t\t\t\t\t           Play again? y/n : ";//25
				cin >> noskipws >> playerchoice;

			}
			if (DeathT == 6)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Game Over!, you got trapped\n\n";
				cout << "\t\t\t\t\t\t        Play again? y/n : ";
				cin >> noskipws >> playerchoice;

			}
			if (DeathT == 7)
			{
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Game Over!, fight better next time\n\n";
				cout << "\t\t\t\t\t\t          Play again? y/n : ";
				cin >> noskipws >> playerchoice;

			}
			if (DeathT == 10)
			{
				SetConsoleTextAttribute(hConsole, 4);
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t        Good job, hitman\n\n";
				cout << "\t\t\t\t\t\t         Play again? : ";
				cin >> noskipws >> playerchoice;


			}


			if (playerchoice[0] == ' ' || playerchoice[0] == NULL || playerchoice[0] == '`' || !cin >> playerchoice[0] || strlen(playerchoice) > 1)
			{
				system("cls");
				cin.clear();
				cin.ignore(10000, '\n');
			}

			else if ((playerchoice[0] == 'n' || playerchoice[0] == 'N') && cin >> playerchoice[0] && strlen(playerchoice) == 1)
			{
				system("cls");
				//system("cls");
				GameOver = 1;
				break;
			}

			else if ((playerchoice[0] == 'y' || playerchoice[0] == 'Y') && cin >> playerchoice[0] && strlen(playerchoice) == 1)
			{
				//system("cls");

				//RESET ALL
				countRLHL1 = 0;
				rH = 36, cH = 8;
				mins = 9, secs = 60;
				flag1 = 0;
				sand = 0;
				lose1 = 0;
				ConstructorCount = 0;
				CountStart = 0;
				shoot1 = 0;
				CounterUntilStop = 0;
				pass1 = 0, pass2 = 0;
				rF = 24, cF = 0;
				CounterFloor = 0;
				timer = 46;
				ScrollCounter = 0, ScrollDelay = 0;
				rEv = 33, cEv = 109;
				OneTime = 0;
				GetOut = 0;
				rGuide = 0, cGuide = 0;
				LeftLook = 0;
				cO1 = 2, rO1 = 3;
				cO2 = 20, rO2 = 3;
				cO3 = 38, rO3 = 3;
				cO4 = 43, rO4 = 3;
				cO5 = 61, rO5 = 3;
				cO6 = 79, rO6 = 3;
				cO7 = 97, rO7 = 3;
				cO8 = 0, rO8 = 0;
				cO9 = 121, rO9 = 3;
				cC = 85;
				rE1 = 36, cE1 = 7;
				rE2 = 36, cE2 = 7;
				rEG1 = 36, cEG1 = 7;
				rEG2 = 36, cEG2 = 7;
				countRLEL1 = 1;
				countRLEL2 = 1;
				countG1 = 1;
				countG2 = 1;
				timer2 = 0;
				timer3 = 0;
				timer4 = 0;
				timer5 = 0;
				DelayShot = 2;
				DeathT = 10;
				Scounter = 0;
				GameOver = 0;
				cCar1 = 120, rCar1 = 38;
				cCar2 = 85, rCar2 = 38;
				countCar1 = 0;
				ratio1 = 1;
				flagC = 0;
				countHearts = 0;
				countHearts2 = 0;
				flagScore1 = 0, flagScore2 = 0, flagScore3 = 0, flagScore4 = 0;
				flagTime1 = 0, flagTime2 = 0, flagTime3 = 0, flagTime4 = 0;
				BSc = 128;
				TSc = 64;
				openG = 0;
				rPlane1 = 7, cPlane1 = 120;
				rPlane2 = 9, cPlane2 = 85;
				rPlane3 = 11, cPlane3 = 50;
				ratio2 = 1;
				flagP2 = 0;
				flagP22 = 0;
				rPG1 = 13, rPG2 = 15, rPG3 = 17;
				cPG1 = 113, cPG2 = 78, cPG3 = 43;
				rSkate = 44, cSkate = 42;
				SkateIn = 0;
				rT = 47, cT = 95;
				rR = 0, cR = 51;
				RopeIn = 0;
				tap4 = 0;
				rMS1 = 36, cMS1 = 8;
				rMS2 = 36, cMS2 = 8;
				countMyShot = 0;
				ShootON = 0;
				countShots = 1;
				Reload = 0, ActionReload = 1;
				rB = 0;
				cB = 0;
				ct = 0;
				rBB = 28;
				cBB = 124;
				win = 0;
				gotshot = 0;
				firsttime = 1;
				timerBSC = 0;
				rFC = 37, cFC = 113;
				rEvR = 33;
				flag6C = 1;
				rBBS1 = rBB + 8, cBBS1 = cBB - 32;
				rBBS2 = rBB + 10, cBBS2 = cBB - 29;
				when = 0;
				startgame = 0;
				rT6 = 27, cT6 = 24;
				shittybug = 0;
				TelephRide = 0;
				ladder = 0;
				AutoWalk = 0;
				AutoWalkCounter = 1;
				rFEv = 46, cFEv = 118;
				FloorNumber = 1;
				FloorNumberCount = 0;
				ClickFix = 0;
				Reply = 0;
				rEnemyFS = 14;
				cEnemyFS = 68;
				counterFS = 2;
				counterFS2 = 2;
				timerFS = 0;
				rCarFS = -18;
				cCarFS = 56;
				for (;;)
				{
					system("cls");

					tryagain--;

					SetConsoleTextAttribute(hConsole, 15);
					if (tryagain != 0)
					{
						for (;;)
						{
							system("cls");
							cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\bYou have " << tryagain << " more chance(s)" << endl;
							cout << "\n\t\t\t\t\t\t\bStart in specific level (1,2,3,4,5) : ";
							cin >> noskipws >> LevelSelection;
							cin.clear();
							cin.ignore(10000, '\n');

							if (LevelSelection >= 1 && LevelSelection <= 5 && tryagain > 0)
							{
								level = LevelSelection;
								breakme = 1;
								break;
							}


						}

						if (breakme == 1)
						{
							break;
						}
					}

					else
					{
						tryagain = 3;
						level = 0;
						breakme = 1;
						int maxhere = -9999;
						for (int v = ks - 3, m = 0; m < 3; v++, m++)
						{
							if (P[v].TemprScore > maxhere)
							{
								maxhere = P[v].TemprScore;
								P[k].PlayerScore = P[v].TemprScore;
							}
						}
						k++;
						//ks = 0;

						break;
					}

				}

				if (breakme == 1)
				{
					break;
				}

			}



		}

		if (GameOver == 1)
		{
			break;
		}

	}

	char SmileFace = 1;
	SetConsoleTextAttribute(hConsole, 4);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t        See you soon " << SmileFace << "\n\n";
	cout << "\n\t\t\t\t\t\t  Press ESC to close the game";
	for (;;)
	{
		char kboard00 = _getch();
		if (kboard00 == 27)
		{
			break;
		}

	}



	return(0);
}