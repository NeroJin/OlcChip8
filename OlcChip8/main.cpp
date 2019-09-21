#include <string>
#include <iostream>
#include "chip8.h"
#include "SimpleTimer.h"
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#define OLC_PGEX_SOUND
#include "olcPGEX_Sound.h"
using namespace std;


class Chip8Machine : public olc::PixelGameEngine
{
private:
	Chip8 chip8;
	SimpleTimer drawTimer;
	SimpleTimer cpuTimer;
	string romFilePath;
	int clockRate;
	double cpuTickTime;
	double drawTickTime;

	olc::Pixel backgroundPixel;
	olc::Pixel foregroundPixel;
		
	static bool bSynthPlaying;
	static float fSynthFrequency;
	
	static float MyCustomSynthFunction(int nChannel, float fGlobalTime, float fTimeStep)
	{
		// Just generate a sine wave of the appropriate frequency
		if (bSynthPlaying)
			return sin(fSynthFrequency * 2.0f * 3.14159f * fGlobalTime);
		else
			return 0.0f;
	}

public:
	Chip8Machine()
	{
		sAppName = "Chip8 Emulator";
		backgroundPixel.r = 0;
		backgroundPixel.g = 0;
		backgroundPixel.b = 0;

		foregroundPixel.r = 255;
		foregroundPixel.g = 255;
		foregroundPixel.b = 255;

		clockRate = 500;
		cpuTickTime = 1000.0 / clockRate;
		drawTickTime = 1000.0 / 60;
	}

	/// <summary>
	/// 重启chip8主机并载入rom。
	/// </summary>
	void Reset()
	{
		if (romFilePath.length() != 0)
		{
			chip8.LoadRom(romFilePath.c_str());

			drawTimer.SetTargetElapsedTimer(drawTickTime);
			drawTimer.Start();

			cpuTimer.SetTargetElapsedTimer(cpuTickTime);
			cpuTimer.Start();
		}
	}

	/// <summary>
	/// 设置CPU频率。
	/// </summary>
	void SetClockRate(int hz)
	{
		if (hz <= 0)
		{
			hz = 1;
		}
		else if (hz > 1000)
		{
			hz = 1000;
		}
		clockRate = hz;
		cpuTickTime = 1000.0 / clockRate;
	}

	bool OnUserCreate() override
	{
		olc::SOUND::InitialiseAudio(44100, 1, 8, 512);
		olc::SOUND::SetUserSynthFunction(MyCustomSynthFunction);
		return true;
	}

	bool OnUserDestroy() override
	{
		olc::SOUND::DestroyAudio();
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		HandleInput();

		//处理CPU循环
		if (cpuTimer.CheckTargetTimer())
		{
			chip8.Tick();
			cpuTimer.Restart();
		}
		
		//处理声音和绘图循环
		if (drawTimer.CheckTargetTimer())
		{
			
			chip8.TicksPer60FPS();
			if (chip8.needsRedraw)
			{
				for (int y = 0; y < chip8.SCREEN_HEIGHT; y++)
					for (int x = 0; x < chip8.SCREEN_WIDTH; x++)
					{
						if (chip8.videoBuffer[y][x])
						{
							Draw(x, y, foregroundPixel);
						}
						else
						{
							Draw(x, y, backgroundPixel);
						}

					}
				chip8.needsRedraw = false;
			}

			if (chip8.needsSound)
				bSynthPlaying = true;
			else
				bSynthPlaying = false;

			drawTimer.Restart();
		}
		
		return true;
	}

	/// <summary>
	/// 处理键盘输入。
	/// </summary>
	void HandleInput()
	{
		//处理按键输入
		//chip8的键盘布局
		//---------------------------------------
		//|		1	|	2	|	3	|	C		|
		//---------------------------------------
		//|		4	|	5	|	6	|	D		|
		//---------------------------------------
		//|		7	|	8	|	9	|	E		|
		//---------------------------------------
		//|		A	|	0	|	B	|	F		|
		//---------------------------------------
		if (IsFocused())
		{
			if (GetKey(olc::Key::ESCAPE).bPressed)
				Reset();

			// 123C <---> 1234
			if (GetKey(olc::Key::K1).bPressed)
				chip8.keyboard[0x1] = 1;
			else if (GetKey(olc::Key::K1).bReleased)
				chip8.keyboard[0x1] = 0;

			if (GetKey(olc::Key::K2).bPressed)
				chip8.keyboard[0x2] = 1;
			else if (GetKey(olc::Key::K2).bReleased)
				chip8.keyboard[0x2] = 0;

			if (GetKey(olc::Key::K3).bPressed)
				chip8.keyboard[0x3] = 1;
			else if (GetKey(olc::Key::K3).bReleased)
				chip8.keyboard[0x3] = 0;

			if (GetKey(olc::Key::K4).bPressed)
				chip8.keyboard[0xC] = 1;
			else if (GetKey(olc::Key::K4).bReleased)
				chip8.keyboard[0xC] = 0;

			// 456D <---> QWER
			if (GetKey(olc::Key::Q).bPressed)
				chip8.keyboard[0x4] = 1;
			else if (GetKey(olc::Key::Q).bReleased)
				chip8.keyboard[0x4] = 0;

			if (GetKey(olc::Key::W).bPressed)
				chip8.keyboard[0x5] = 1;
			else if (GetKey(olc::Key::W).bReleased)
				chip8.keyboard[0x5] = 0;

			if (GetKey(olc::Key::E).bPressed)
				chip8.keyboard[0x6] = 1;
			else if (GetKey(olc::Key::E).bReleased)
				chip8.keyboard[0x6] = 0;

			if (GetKey(olc::Key::R).bPressed)
				chip8.keyboard[0xD] = 1;
			else if (GetKey(olc::Key::R).bReleased)
				chip8.keyboard[0xD] = 0;


			//789E <---> ASDF
			if (GetKey(olc::Key::A).bPressed)
				chip8.keyboard[0x7] = 1;
			else if (GetKey(olc::Key::A).bReleased)
				chip8.keyboard[0x7] = 0;

			if (GetKey(olc::Key::S).bPressed)
				chip8.keyboard[0x8] = 1;
			else if (GetKey(olc::Key::S).bReleased)
				chip8.keyboard[0x8] = 0;

			if (GetKey(olc::Key::D).bPressed)
				chip8.keyboard[0x9] = 1;
			else if (GetKey(olc::Key::D).bReleased)
				chip8.keyboard[0x9] = 0;

			if (GetKey(olc::Key::F).bPressed)
				chip8.keyboard[0xE] = 1;
			else if (GetKey(olc::Key::F).bReleased)
				chip8.keyboard[0xE] = 0;


			// A0BF <---> ZXCV
			if (GetKey(olc::Key::Z).bPressed)
				chip8.keyboard[0xA] = 1;
			else if (GetKey(olc::Key::Z).bReleased)
				chip8.keyboard[0xA] = 0;

			if (GetKey(olc::Key::X).bPressed)
				chip8.keyboard[0x0] = 1;
			else if (GetKey(olc::Key::X).bReleased)
				chip8.keyboard[0x0] = 0;

			if (GetKey(olc::Key::C).bPressed)
				chip8.keyboard[0xB] = 1;
			else if (GetKey(olc::Key::C).bReleased)
				chip8.keyboard[0xB] = 0;

			if (GetKey(olc::Key::V).bPressed)
				chip8.keyboard[0xF] = 1;
			else if (GetKey(olc::Key::V).bReleased)
				chip8.keyboard[0xF] = 0;


		}
	}

	/// <summary>
	/// 设置背景像素的显示颜色。
	/// </summary>
	void BackgroundColor(int R, int G, int B)
	{
		backgroundPixel.r = R;
		backgroundPixel.g = G;
		backgroundPixel.b = B;
	}

	/// <summary>
	/// 设置前景像素的显示颜色。
	/// </summary>
	void ForegroundColor(int R, int G, int B)
	{
		foregroundPixel.r = R;
		foregroundPixel.g = G;
		foregroundPixel.b = B;
	}

	/// <summary>
	/// 读取Rom文件。
	/// </summary>
	bool LoadRom(const char * filePath)
	{
		if (chip8.LoadRom(filePath))
		{
			romFilePath = (string)(filePath);
			drawTimer.SetTargetElapsedTimer(drawTickTime);
			drawTimer.Start();

			cpuTimer.SetTargetElapsedTimer(cpuTickTime);
			cpuTimer.Start();

			return true;
		}
		else
		{
			return false;
		}
		
	}
};


bool Chip8Machine::bSynthPlaying = false;
float Chip8Machine::fSynthFrequency = 400.0f;

/// <summary>
/// 显示帮助信息。
/// </summary>
void Usage()
{
	cout << "Usage: OlcChip8 [-s Pixel_Scale] [-b Background_Pixel_Color] [-f Foreground_Pixel_Color] [-c Cpu_hz] [-h] rom_path" << endl;
	cout << "Options:" << endl;
	cout << "-s Pixel_Scale" << '\t\t\t' << "Pixel scale value,scaling value only using integers, default value is 10." << endl;
	cout << "-b Background_Pixel_Color" << '\t\t\t' << "Background pixel color format(RRRGGGBBB), default value is black(000000000)." << endl;
	cout << "-f Foreground_Pixel_Color" << '\t\t\t' << "foreground pixel color format(RRRGGGBBB), default value is white(255255255)." << endl;
	cout << "-c Cpu_hz" << '\t\t\t' << "Chip8 cpu clock rate, default value is 500 and the maximum value is limited to 1000." << endl;
	cout << "-h" << '\t\t\t' << "Echo help" << endl;
	cout << "rom_path" << '\t\t\t' << "Rom path " << endl;
}

/// <summary>
/// main
/// </summary>
int main(int argc, char *argv[])
{
	Chip8Machine chip8Machine;

	//处理命令行参数
	string romPath;
	const int LOAD_ROM_OPTION = 0x001;
	const int BACKGROUND_OPTION = 0x002;
	const int FOREGROUND_OPTION = 0x004;
	const int PIXEL_SCALE_OPTION = 0x008;
	const int CPU_RATE_OPTION = 0x010;
	int options = 0;
	int fr, fg, fb, br, bg, bb;
	int pixelScale = 10;

	if (argc == 1)
	{
		cout << "Need arguments !" << endl;
		cout << "help" << endl;
		return 1;
	}
	else
	{
		bool skipFlag = false;

		for (int i = 1; i < argc; i++)
		{
			string debugStr = argv[i];
			if (skipFlag)
			{
				skipFlag = false;
				continue;
			}

			char *ch = argv[i];
			switch (ch[0])
			{
			case '-':
				switch (ch[1])
				{
				case 'h':
					Usage();
					return 0;
				case 'c':
					options |= CPU_RATE_OPTION;
					if (i < argc - 1)
					{
						bool isDigit = true;
						int len = strlen(argv[i + 1]);
						for (int j = 0; j < strlen(argv[i + 1]); j++)
						{
							if (!isdigit(argv[i + 1][j]))
							{
								isDigit = false;
							}
						}
						if (isDigit)
						{
							int hz = atoi(argv[i + 1]);
							chip8Machine.SetClockRate(hz);
							skipFlag = true;
						}
						else
						{
							cout << "Argument is not a digital!" << endl;
							Usage();
							return 0;
						}
					}
					else
					{
						cout << "Argument error!" << endl;
						Usage();
						return 1;
					}

					break;
				case 's':
					options |= PIXEL_SCALE_OPTION;
					if (i < argc - 1)
					{
						bool isDigit = true;
						int len = strlen(argv[i + 1]);
						for (int j = 0; j < strlen(argv[i + 1]); j++)
						{
							if (!isdigit(argv[i + 1][j]))
							{
								isDigit = false;
							}
						}
						if (isDigit)
						{
							pixelScale = atoi(argv[i + 1]);
							skipFlag = true;
						}
						else
						{
							cout << "Argument is not a digital!" << endl;
							Usage();
							return 0;
						}
						
					}
					else
					{
						cout << "Argument error!" << endl;
						Usage();
						return 1;
					}

					break;
				case 'b':
					options |= BACKGROUND_OPTION;
					if (i < argc - 1)
					{
						if (strlen(argv[i + 1]) == 9)
						{
							//处理RGB
							string str = argv[i + 1];
							bool isDigit = true;
							for (int j = 0; j < 9; j++)
							{
								if (!isdigit(str[j]))
								{
									isDigit = false;
								}
								
							}
							if (isDigit)
							{
								br = atoi(str.substr(0, 3).c_str());
								bg = atoi(str.substr(3, 3).c_str());
								bb = atoi(str.substr(6, 3).c_str());
								chip8Machine.BackgroundColor(br, bg, bb);
								skipFlag = true;
							}
							else
							{
								cout << "Argument is not a digital!" << endl;
								Usage();
								return 1;
							}
						}
						else
						{
							cout << "Argument error!" << endl;
							Usage();
							return 1;
						}
					}
					else
					{
						cout << "Argument error!" << endl;
						Usage();
						return 1;
					}

					break;
				case 'f':
					options |= FOREGROUND_OPTION;
					if (i < argc - 1)
					{
						if (strlen(argv[i + 1]) == 9)
						{
							//处理RGB
							string str = argv[i + 1];
							bool isDigit = true;
							for (int j = 0; j < 9; j++)
							{
								if (!isdigit(str[j]))
								{
									isDigit = false;
								}
								
							}
							if (isDigit)
							{
								fr = atoi(str.substr(0, 3).c_str());
								fg = atoi(str.substr(3, 3).c_str());
								fb = atoi(str.substr(6, 3).c_str());
								chip8Machine.ForegroundColor(fr, fg, fb);
								skipFlag = true;
							}
							else
							{
								cout << "Argument is not a digital!" << endl;
								Usage();
								return 1;
							}
						}
						else
						{
							cout << "Argument error!" << endl;
							Usage();
							return 1;
						}
					}
					else
					{
						cout << "Argument error!" << endl;
						Usage();
						return 1;
					}

					break;
				default:
					cout << "Argument error!" << endl;
					Usage();
					return 1;
				}
				break;
			default:
				
				ifstream f(argv[i]);
				if (f.good())
				{
					options |= LOAD_ROM_OPTION;
					romPath = argv[i];
				}
				else
				{
					cout << "Can't read a rom file!" << endl;
					return 1;
				}
				
			}
		}
	}

	if ((options & FOREGROUND_OPTION) && (options & BACKGROUND_OPTION))
	{
		if (fr == br && fg == bg && fb == bb)
		{
			cout << "Background color and foreground color are the same, can't displayed." << endl;
			return 1;
		}
	}


	if (chip8Machine.Construct(Chip8::SCREEN_WIDTH, Chip8::SCREEN_HEIGHT, pixelScale, pixelScale))
	{
		if (chip8Machine.LoadRom(romPath.c_str()))
		{
			chip8Machine.Start();
		}
		else
		{
			cout << "Can't load rom!" << endl;
		}
	}
	return 0;
}