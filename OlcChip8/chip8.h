#pragma once
#include <cstdint>



class Chip8
{
public:
	Chip8();
	~Chip8();

	//
	//  摘要:
	//      CHIP8的内存大小
	const static int MEMORY_SIZE = 4096;
	//
	//  摘要:
	//      CHIP8的寄存器大小
	const static int REGISTER_SIZE = 16;
	//
	//  摘要:
	//      CHIP8的栈大小
	const static int STACK_SIZE = 16;

	//
	//  摘要:
	//      CHIP8的栈大小
	const static int KEYBOARD_KEYS_SIZE = 16;

	//
	//  摘要:
	//      0x200是chip8程序开始的地址。
	const static int START_ADDRESS = 0x200;

	//
	//  摘要:
	//      表示CHIP8的显示屏标准像素宽度。此字段为常数。
	const static int SCREEN_WIDTH = 64;

	//
	//  摘要:
	//      表示CHIP8的显示屏标准像素高度。此字段为常数。
	const static int SCREEN_HEIGHT = 32;

	//用于通知类外部程序是否需要更新画图。
	bool needsRedraw = true;

	//用于通知类外部程序是否需要发出喇叭声音。
	bool needsSound = false;

	//内存4K
	uint8_t memory[MEMORY_SIZE];

	//16个8位寄存器，v0-vf。
	uint8_t v[REGISTER_SIZE];

	//16位的寄存器，用于保存内存地址。
	uint16_t i;

	//16位的程序计数器,类似void指针。
	uint16_t pc;

	//堆栈
	uint16_t stack[KEYBOARD_KEYS_SIZE];

	//堆栈指针
	uint16_t sp;

	//此定时器用于计时游戏事件，每60Hz递减1，到0就停用。也就是画面每更新一帧，就减1。
	uint8_t delayTimer;

	//声音计数器，可以存储0-255的值，每60Hz递减1，该值不为零时，会发出哔哔声。
	uint8_t soundTimer;

	//视频缓冲区,用于显示64×32像素的图像。
	bool videoBuffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	//用于存储当前的CPU周期指令。
	uint16_t opcode;

	//CHIP8的键盘。
	uint8_t keyboard[KEYBOARD_KEYS_SIZE];

	
private:
	void Proc0(const uint16_t &opcode);
	void Proc1(const uint16_t &opcode);
	void Proc2(const uint16_t &opcode);
	void Proc3(const uint16_t &opcode);
	void Proc4(const uint16_t &opcode);
	void Proc5(const uint16_t &opcode);
	void Proc6(const uint16_t &opcode);
	void Proc7(const uint16_t &opcode);
	void Proc8(const uint16_t &opcode);
	void Proc9(const uint16_t &opcode);
	void ProcA(const uint16_t &opcode);
	void ProcB(const uint16_t &opcode);
	void ProcC(const uint16_t &opcode);
	void ProcD(const uint16_t &opcode);
	void ProcE(const uint16_t &opcode);
	void ProcF(const uint16_t &opcode);
	
public:
	/// <summary>
	/// CHIP8 CPU周期函数，每一个周期调用一次，用于执行CPU指令。默认的周期是1/840秒运行一次。
	/// </summary>
	void Tick();

	/// <summary>
	/// CHIP8的每秒60帧之1周期函数，每一个周期调用一次，用于绘制屏幕和延时计时器的递减。默认的周期是1/60秒运行一次。
	/// </summary>
	void TicksPer60FPS();

	void Init();

	bool LoadRom(const char * filename);

};
