#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class ZeNextEngine : public olc::PixelGameEngine
{
public:
	ZeNextEngine()
	{
		sAppName = "ZeNextEngine 3D";
	}

	bool OnUserCreate() override
	{
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		DrawTriangle(0.0f, 0.0f, 120.0f, 0.0f, 0.0f, 120.0f);
		return true;
	}
};

int main()
{
	ZeNextEngine game;
	if (game.Construct(256, 240, 4, 4))
		game.Start();
	return 0;
};