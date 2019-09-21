#include "chip8.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <Windows.h>
using namespace std;

uint8_t chip8Fonts[80] =
{
	0xF0, 0x90, 0x90, 0x90, 0xF0, //0
	0x20, 0x60, 0x20, 0x20, 0x70, //1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, //2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, //3
	0x90, 0x90, 0xF0, 0x10, 0x10, //4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, //5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, //6
	0xF0, 0x10, 0x20, 0x40, 0x40, //7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, //8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, //9
	0xF0, 0x90, 0xF0, 0x90, 0x90, //A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, //B
	0xF0, 0x80, 0x80, 0x80, 0xF0, //C
	0xE0, 0x90, 0x90, 0x90, 0xE0, //D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, //E
	0xF0, 0x80, 0xF0, 0x80, 0x80  //F
};



Chip8::Chip8()
{
	
	
}

Chip8::~Chip8()
{
	
}

/// <summary>
/// CHIP8 CPU周期函数，每一个周期调用一次，用于执行CPU指令。默认的周期是1/840秒运行一次。
/// </summary>
void Chip8::Tick()
{
	//取指令，Chip8每个指令都是2个字节长（16位，大端序）。
	uint16_t opcode = memory[pc] << 8 | memory[pc + 1];

	if (pc == 774)
	{
		bool br = true;
	}
	switch (opcode >> 12)
	{
	case 0x00:
		Proc0(opcode);
		break;
	case 0x01:
		Proc1(opcode);
		break;
	case 0x02:
		Proc2(opcode);
		break;
	case 0x03:
		Proc3(opcode);
		break;
	case 0x04:
		Proc4(opcode);
		break;
	case 0x05:
		Proc5(opcode);
		break;
	case 0x06:
		Proc6(opcode);
		break;
	case 0x07:
		Proc7(opcode);
		break;
	case 0x08:
		Proc8(opcode);
		break;
	case 0x09:
		Proc9(opcode);
		break;
	case 0x0A:
		ProcA(opcode);
		break;
	case 0x0B:
		ProcB(opcode);
		break;
	case 0x0C:
		ProcC(opcode);
		break;
	case 0x0D:
		ProcD(opcode);
		break;
	case 0x0E:
		ProcE(opcode);
		break;
	case 0x0F:
		ProcF(opcode);
		break;
	default:
		break;
	}
}

/// <summary>
/// CHIP8的每秒60帧之1周期函数，每一个周期调用一次，用于绘制屏幕和延时计时器的递减。默认的周期是1/60秒运行一次。
/// </summary>
void Chip8::TicksPer60FPS()
{
	if (delayTimer > 0)
	{
		delayTimer--;
	}
	if (soundTimer > 0)
	{
		soundTimer--;
		needsSound = true;
	}
	else if (soundTimer == 0)
	{
		needsSound = false;
	}

}


/// <summary>
/// 将内存、寄存器、栈等都重置原值。
/// </summary>
void Chip8::Init()
{
	//重置内存
	for (int i = 0; i < MEMORY_SIZE; i++)
		memory[i] = 0;

	//重置寄存器
	for (int i = 0; i < REGISTER_SIZE; i++)
		v[i] = 0;

	
	this->i = 0;

	pc = START_ADDRESS;

	for (int i = 0; i < STACK_SIZE; i++)
		stack[i] = 0;

	this->sp = 0;
	
	this->delayTimer = 0;

	this->soundTimer = 0;

	for (int y = 0; y < SCREEN_HEIGHT; y++)
		for (int x = 0; x < SCREEN_WIDTH; x++)
			videoBuffer[y][x] = false;

	for (int i = 0; i < KEYBOARD_KEYS_SIZE; i++)
		keyboard[i] = 0;

	for (int i = 0; i < MEMORY_SIZE; ++i)
		memory[i] = 0;

	//重新装载字符集。
	for (int i = 0; i < 80; ++i)
		memory[i] = chip8Fonts[i];

	srand(time(NULL));
}

/// <summary>
/// 将文件中的rom加载到内存中。
/// </summary>
bool Chip8::LoadRom(const char * filename)
{
	Init();
	
	std::ifstream file;
	size_t fileSize;

	file.open(filename, std::ios::in | std::ios::binary);

	if (file.is_open())
	{
		file.seekg(0, std::ios::end);
		fileSize = file.tellg();

		// 如果rom太大就不加载
		if (fileSize > 0xFFF - START_ADDRESS)
		{
			file.close();
			return false;
		}
		else
		{
			char* data= (char*)(&(memory[START_ADDRESS]));
			file.seekg(0, std::ios::beg);
			file.read(data, fileSize);
			file.close();
			return true;
		}
	}
	else
	{
		return false;
	}
	
	return true;
}

/// <summary>
/// 处理当opcode前一位0x0的情形。
/// </summary>
void Chip8::Proc0(const uint16_t &opcode)
{
	uint8_t nn = opcode & 0x00FF;
	if (nn == 0xE0)
	{
		//清除屏幕；视频缓冲区全置0。
		for (int y = 0; y < SCREEN_HEIGHT; y++)
			for (int x = 0; x < SCREEN_WIDTH; x++)
			{
				videoBuffer[y][x] = false;
			}
		needsRedraw = true;
		pc += 2;
	}
	else if (nn == 0xEE)
	{
		//从子程序返回；堆栈指针自减，然后通过堆栈指针获取堆栈的值（出栈）赋给PC。
		--sp;
		pc = stack[sp];
		pc += 2;
	}
}

/// <summary>
/// 处理当opcode前一位0x1的情形。
/// </summary>
void Chip8::Proc1(const uint16_t &opcode)
{
	//跳转地址到NNN（将NNN赋值给PC）。
	pc = opcode & 0x0FFF;
}

/// <summary>
/// 处理当opcode前一位0x2的情形。
/// </summary>
void Chip8::Proc2(const uint16_t &opcode)
{
	//在NNN处调用子程序。将当前PC（程序计数器：16位，储存指令地址）放入堆栈。然后堆栈指针自增，并将当前操作指令的NNN（后12位）赋值给PC
	stack[sp] = pc;
	++sp;
	pc = opcode & 0x0FFF;
}

/// <summary>
/// 处理当opcode前一位0x3的情形。
/// </summary>
void Chip8::Proc3(const uint16_t &opcode)
{
	//如果寄存器[X]等于NN，跳过下一条指令（PC += 4）。
	if (v[(opcode & 0x0F00) >> 8] == (opcode & 0x00FF))
		pc += 4;
	else
		pc += 2;
}

/// <summary>
/// 处理当opcode前一位0x4的情形。
/// </summary>
void Chip8::Proc4(const uint16_t &opcode)
{
	//如果寄存器[X]不等于NN，跳过下一条指令（PC += 4）。
	if (v[(opcode & 0x0F00) >> 8] != (opcode & 0x00FF))
		pc += 4;
	else
		pc += 2;
}

/// <summary>
/// 处理当opcode前一位0x5的情形。
/// </summary>
void Chip8::Proc5(const uint16_t &opcode)
{
	//如果寄存器[X]等于寄存器[Y]，跳过下一条指令（PC += 4）。
	if (v[(opcode & 0x0F00) >> 8] == v[(opcode & 0x00F0) >> 4])
		pc += 4;
	else
		pc += 2;
}

/// <summary>
/// 处理当opcode前一位0x6的情形。
/// </summary>
void Chip8::Proc6(const uint16_t &opcode)
{
	//将NN赋值给寄存器[X]。
	v[(opcode & 0x0F00) >> 8] = (opcode & 0x00FF);
	pc += 2;
}

/// <summary>
/// 处理当opcode前一位0x7的情形。
/// </summary>
void Chip8::Proc7(const uint16_t &opcode)
{
	//寄存器[X]自增NN值（寄存器[X] += NN）。
	v[(opcode & 0x0F00) >> 8] += (opcode & 0x00FF);
	pc += 2;
}

/// <summary>
/// 处理当opcode前一位0x8的情形。
/// </summary>
void Chip8::Proc8(const uint16_t &opcode)
{
	switch (opcode & 0x000F)
	{
	case 0x0: //将寄存器[Y]赋值给寄存器[X]。
		v[(opcode & 0x0F00) >> 8] = v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x1: //将寄存器[X]和寄存器[Y]“或”操作的结果赋值给寄存器[X]。
		v[(opcode & 0x0F00) >> 8] |= v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x2: //将寄存器[X]和寄存器[Y]“与”操作的结果赋值给寄存器[X]。
		v[(opcode & 0x0F00) >> 8] &= v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x3: //将寄存器[X]和寄存器[Y]“异或”操作的结果赋值给寄存器[X]。
		v[(opcode & 0x0F00) >> 8] ^= v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x4: //寄存器[X]自增寄存器[Y]的值。如果寄存器[X]的结果大于8位，将寄存器[F]的值设置成1，否则设置成0。
		if (v[(opcode & 0x0F00) >> 8] > (0xFF - v[(opcode & 0x00F0) >> 4]))
			v[0xF] = 1;
		else
			v[0xF] = 0;

		v[(opcode & 0x0F00) >> 8] += v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x5: //寄存器[X]自减寄存器[Y]的值。如果寄存器[X]的值大于寄存器[Y]的值，将寄存器[F]的值设置成1，否则设置成0。
		if (v[(opcode & 0x0F00) >> 8] > v[(opcode & 0x00F0) >> 4])
			v[0xF] = 1;
		else
			v[0xF] = 0;

		v[(opcode & 0x0F00) >> 8] -= v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x6: //将寄存器[X]的值右移1位后赋值给自身（相当于自身除2），另外在寄存器[X]位移前，会将寄存器[X]的值的最后一位赋值给V[F]。
		v[0xF] = v[(opcode & 0x0F00) >> 8] & 0x1;
		v[(opcode & 0x0F00) >> 8] >>= 1;
		pc += 2;
		break;
	case 0x7: //将寄存器[Y]的值减去寄存器[X]的值，并将结果赋值给寄存器[X]。如果寄存器[Y]的值大于寄存器[X]的值，V[F] = 1，否则V[F] = 0。
		if (v[(opcode & 0x00F0) >> 4] > v[(opcode & 0x0F00) >> 8])
			v[0xF] = 1;
		else
			v[0xF] = 0;

		v[(opcode & 0x0F00) >> 8] = v[(opcode & 0x00F0) >> 4] - v[(opcode & 0x0F00) >> 8];
		pc += 2;
		break;
	case 0xE: //将寄存器[X]的值左移1位后赋值给自身（相当于自身乘2），另外在寄存器[X]位移前，会将寄存器[X]的值的最后一位赋值给V[F]。
		v[0xF] = v[(opcode & 0x0F00) >> 8] >> 7;
		v[(opcode & 0x0F00) >> 8] <<= 1;
		pc += 2;
		break;
	}
}

/// <summary>
/// 处理当opcode前一位0x9的情形。
/// </summary>
void Chip8::Proc9(const uint16_t &opcode)
{
	//如果寄存器[X]不等于寄存器[Y]，跳过下一条指令（PC += 4）。
	if (v[(opcode & 0x0F00) >> 8] != v[(opcode & 0x00F0) >> 4])
		pc += 4;
	else
		pc += 2;
}

/// <summary>
/// 处理当opcode前一位0xA的情形。
/// </summary>
void Chip8::ProcA(const uint16_t &opcode)
{
	//将NNN赋值给寄存器I。
	i = (uint16_t)(opcode & 0x0FFF);
	pc += 2;
}

/// <summary>
/// 处理当opcode前一位0xB的情形。
/// </summary>
void Chip8::ProcB(const uint16_t &opcode)
{
	//将当前操作指令的NNN加上寄存器[0]的值后赋值给PC。
	pc = (opcode & 0x0FFF) + v[0];
}

/// <summary>
/// 处理当opcode前一位0xC的情形。
/// </summary>
void Chip8::ProcC(const uint16_t &opcode)
{
	//将NN与随机数（0至255）“与”操作的结果赋值给寄存器[X]。
	v[(opcode & 0x0F00) >> 8] = (opcode & 0x00FF) & (rand() % 0xFF);
	pc += 2;
}

/// <summary>
/// 处理当opcode前一位0xD的情形。
/// </summary>
void Chip8::ProcD(const uint16_t &opcode)
{
	//把内存[I]中保存的精灵以寄存器[X]、寄存器[Y]为坐标轴的X、Y的值作为左上起始点写入视频缓冲区。
	//内存[I]的值（1字节8位）代表了精灵1行8个像素点是否需要画点，1代表需要画点，0代表不要画点，这条指令中的精灵高度是由N（0至15）值决定的，画整个精灵就需要把内存[I至N]写入视屏缓冲区。
	//精灵的像素点与当前视屏缓冲区的像素点做“异或”操作，如果有任一的像素点导致被擦除，寄存器[F]被设置为1，否则设置为0。
	//而当精灵的某部份跨过屏幕时，需要把这部分环绕显示在屏幕的对面。而当前的视频缓冲区中与相对应即将写入的精灵的点重合时，要将寄存器[F]的值设置成1。
	uint16_t x = (uint16_t)(v[(opcode & 0x0F00) >> 8] % SCREEN_WIDTH);
	uint16_t y = (uint16_t)(v[(opcode & 0x00F0) >> 4] % SCREEN_HEIGHT);
	uint16_t spriteHeight = (uint16_t)(opcode & 0x000F);
	uint8_t spriteLine;

	v[0xF] = 0;
	for (int h = 0; h < spriteHeight; h++)
	{
		spriteLine = memory[i + h];
		for (int bit = 0; bit < 8; bit++)
		{
			//用0x80(1000 0000)右移0至7位后再和spriteLine进行位与操作，来判断spriteLine每一位是否为1。
			if ((spriteLine & (0x80 >> bit)) != 0)
			{
				if (videoBuffer[((y + h) % SCREEN_HEIGHT)][(x + bit) % SCREEN_WIDTH])
				{
					v[0xF] = 1;
				}
				videoBuffer[((y + h) % SCREEN_HEIGHT)][(x + bit) % SCREEN_WIDTH] ^= true;
			}
		}
	}
	needsRedraw = true;
	pc += 2;
}

/// <summary>
/// 处理当opcode前一位0xE的情形。
/// </summary>
void Chip8::ProcE(const uint16_t &opcode)
{
	switch (opcode & 0x00FF)
	{
	case 0x9E:
		//如果相关键盘的按键（keyboard[寄存器[X]]）被按下，跳过下一条指令（PC += 4）。
		if (keyboard[v[(opcode & 0x0F00) >> 8]] != 0)
			pc += 4;
		else
			pc += 2;
		break;
	case 0xA1:
		//如果相关键盘的按键（keyboard[寄存器[X]]）没有被按下，跳过下一条指令（PC += 4）。
		if (keyboard[v[(opcode & 0x0F00) >> 8]] == 0)
			pc += 4;
		else
			pc += 2;
		break;
	}
}

/// <summary>
/// 处理当opcode前一位0xF的情形。
/// </summary>
void Chip8::ProcF(const uint16_t &opcode)
{
	switch (opcode & 0x00FF)
	{
	case 0x07:
		//将延时寄存器的值赋值给寄存器[X]。
		v[(opcode & 0x0F00) >> 8] = delayTimer;
		pc += 2;
		break;
	case 0x0A:
	{
		//等待一个键盘按键被按下，然后把它赋值给寄存器[X]。否则阻挡其他操作（可以不改变PC的值，使得该指令重复运行）。
		bool keyPress = false;
		for (int keyIndex = 0; keyIndex < 16; keyIndex++)
		{
			if (keyboard[keyIndex] != 0)
			{
				v[(opcode & 0x0F00) >> 8] = keyIndex;
				keyPress = true;
			}
		}

		if (!keyPress)
			return;

		pc += 2;
	}
		break;
	case 0x15:
		//将寄存器[X]的值赋值给延时寄存器。
		delayTimer = v[(opcode & 0x0F00) >> 8];
		pc += 2;
		break;
	case 0x18:
		//将寄存器[X]的值赋值给音乐计时寄存器。
		soundTimer = v[(opcode & 0x0F00) >> 8];
		//当寄存器[X]的值赋值给音乐计时寄存器soundTimer且数值不为0时，PC喇叭会响起，然后soundTimer会60分之一秒递减，减少至0时，PC喇叭停止响声。
		//这里直接用soundTimer乘以60分之一毫秒的结果作为PC喇叭响声的时长参数来调用Beep函数，所以音乐计时寄存器soundTimer的60分之一秒的递减不在有实际作用。
		//Beep((int)(soundTimer * (1000.0f / 60)));
		pc += 2;
		break;
	case 0x1E:
		//寄存器I自增将寄存器[X]的值。
		i += v[(opcode & 0x0F00) >> 8];
		pc += 2;
		break;
	case 0x29:
		//将精灵储存在寄存器[X]的索引值*Chip8字符的大小（5字节）赋值给寄存器I。（索引值 = 0，I = 0 * 5，程序将渲染字符0；索引值 = 1，I = 1 * 5，程序将渲染字符1；索引值 = 2，I = 2 * 5，程序将渲染字符2；以此类推）
		i = (uint16_t)(v[(opcode & 0x0F00) >> 8] * 0x5);
		pc += 2;
		break;
	case 0x33:
		//将寄存器[X]中储存的BCD码（这种编码形式利用了4个字节来储存一个十进制的数码，使二进制和十进制之间的转换得以快捷的进行。）放进内存中，内存地址索引从I开始，最多到I+2。
		memory[i] = v[(opcode & 0x0F00) >> 8] / 100;
		memory[i + 1] = (v[(opcode & 0x0F00) >> 8] / 10) % 10;
		memory[i + 2] = (v[(opcode & 0x0F00) >> 8] % 100) % 10;
		pc += 2;
		break;
	case 0x55:
		//把寄存器[0]至寄存器[X]的值放在内存[I]中，每放一个寄存器值，I增加1。复制完成后网上有多种说法，一种说法是现代编译器I的值不变，另外一种说法是I += X + 1。这里选择不变的实现。
		for (int vi = 0; vi <= ((opcode & 0x0F00) >> 8); vi++)
		{
			memory[i + vi] = v[vi];
		}
		pc += 2;
		break;
	case 0x65:
		//FX55的相反操作，把内存[I]中的值，放进寄存器[0]至寄存器[X]中，每放一个寄存器值，I增加1。复制完成后网上有多种说法，一种说法是现代编译器I的值不变，另外一种说法是I += X + 1。这里选择不变的实现。
		for (int vi = 0; vi <= ((opcode & 0x0F00) >> 8); vi++)
		{
			v[vi] = memory[i + vi];
		}
		pc += 2;
		break;
	}
}