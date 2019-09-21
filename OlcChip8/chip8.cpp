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
/// CHIP8 CPU���ں�����ÿһ�����ڵ���һ�Σ�����ִ��CPUָ�Ĭ�ϵ�������1/840������һ�Ρ�
/// </summary>
void Chip8::Tick()
{
	//ȡָ�Chip8ÿ��ָ���2���ֽڳ���16λ������򣩡�
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
/// CHIP8��ÿ��60֮֡1���ں�����ÿһ�����ڵ���һ�Σ����ڻ�����Ļ����ʱ��ʱ���ĵݼ���Ĭ�ϵ�������1/60������һ�Ρ�
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
/// ���ڴ桢�Ĵ�����ջ�ȶ�����ԭֵ��
/// </summary>
void Chip8::Init()
{
	//�����ڴ�
	for (int i = 0; i < MEMORY_SIZE; i++)
		memory[i] = 0;

	//���üĴ���
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

	//����װ���ַ�����
	for (int i = 0; i < 80; ++i)
		memory[i] = chip8Fonts[i];

	srand(time(NULL));
}

/// <summary>
/// ���ļ��е�rom���ص��ڴ��С�
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

		// ���rom̫��Ͳ�����
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
/// ����opcodeǰһλ0x0�����Ρ�
/// </summary>
void Chip8::Proc0(const uint16_t &opcode)
{
	uint8_t nn = opcode & 0x00FF;
	if (nn == 0xE0)
	{
		//�����Ļ����Ƶ������ȫ��0��
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
		//���ӳ��򷵻أ���ջָ���Լ���Ȼ��ͨ����ջָ���ȡ��ջ��ֵ����ջ������PC��
		--sp;
		pc = stack[sp];
		pc += 2;
	}
}

/// <summary>
/// ����opcodeǰһλ0x1�����Ρ�
/// </summary>
void Chip8::Proc1(const uint16_t &opcode)
{
	//��ת��ַ��NNN����NNN��ֵ��PC����
	pc = opcode & 0x0FFF;
}

/// <summary>
/// ����opcodeǰһλ0x2�����Ρ�
/// </summary>
void Chip8::Proc2(const uint16_t &opcode)
{
	//��NNN�������ӳ��򡣽���ǰPC�������������16λ������ָ���ַ�������ջ��Ȼ���ջָ��������������ǰ����ָ���NNN����12λ����ֵ��PC
	stack[sp] = pc;
	++sp;
	pc = opcode & 0x0FFF;
}

/// <summary>
/// ����opcodeǰһλ0x3�����Ρ�
/// </summary>
void Chip8::Proc3(const uint16_t &opcode)
{
	//����Ĵ���[X]����NN��������һ��ָ�PC += 4����
	if (v[(opcode & 0x0F00) >> 8] == (opcode & 0x00FF))
		pc += 4;
	else
		pc += 2;
}

/// <summary>
/// ����opcodeǰһλ0x4�����Ρ�
/// </summary>
void Chip8::Proc4(const uint16_t &opcode)
{
	//����Ĵ���[X]������NN��������һ��ָ�PC += 4����
	if (v[(opcode & 0x0F00) >> 8] != (opcode & 0x00FF))
		pc += 4;
	else
		pc += 2;
}

/// <summary>
/// ����opcodeǰһλ0x5�����Ρ�
/// </summary>
void Chip8::Proc5(const uint16_t &opcode)
{
	//����Ĵ���[X]���ڼĴ���[Y]��������һ��ָ�PC += 4����
	if (v[(opcode & 0x0F00) >> 8] == v[(opcode & 0x00F0) >> 4])
		pc += 4;
	else
		pc += 2;
}

/// <summary>
/// ����opcodeǰһλ0x6�����Ρ�
/// </summary>
void Chip8::Proc6(const uint16_t &opcode)
{
	//��NN��ֵ���Ĵ���[X]��
	v[(opcode & 0x0F00) >> 8] = (opcode & 0x00FF);
	pc += 2;
}

/// <summary>
/// ����opcodeǰһλ0x7�����Ρ�
/// </summary>
void Chip8::Proc7(const uint16_t &opcode)
{
	//�Ĵ���[X]����NNֵ���Ĵ���[X] += NN����
	v[(opcode & 0x0F00) >> 8] += (opcode & 0x00FF);
	pc += 2;
}

/// <summary>
/// ����opcodeǰһλ0x8�����Ρ�
/// </summary>
void Chip8::Proc8(const uint16_t &opcode)
{
	switch (opcode & 0x000F)
	{
	case 0x0: //���Ĵ���[Y]��ֵ���Ĵ���[X]��
		v[(opcode & 0x0F00) >> 8] = v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x1: //���Ĵ���[X]�ͼĴ���[Y]���򡱲����Ľ����ֵ���Ĵ���[X]��
		v[(opcode & 0x0F00) >> 8] |= v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x2: //���Ĵ���[X]�ͼĴ���[Y]���롱�����Ľ����ֵ���Ĵ���[X]��
		v[(opcode & 0x0F00) >> 8] &= v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x3: //���Ĵ���[X]�ͼĴ���[Y]����򡱲����Ľ����ֵ���Ĵ���[X]��
		v[(opcode & 0x0F00) >> 8] ^= v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x4: //�Ĵ���[X]�����Ĵ���[Y]��ֵ������Ĵ���[X]�Ľ������8λ�����Ĵ���[F]��ֵ���ó�1���������ó�0��
		if (v[(opcode & 0x0F00) >> 8] > (0xFF - v[(opcode & 0x00F0) >> 4]))
			v[0xF] = 1;
		else
			v[0xF] = 0;

		v[(opcode & 0x0F00) >> 8] += v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x5: //�Ĵ���[X]�Լ��Ĵ���[Y]��ֵ������Ĵ���[X]��ֵ���ڼĴ���[Y]��ֵ�����Ĵ���[F]��ֵ���ó�1���������ó�0��
		if (v[(opcode & 0x0F00) >> 8] > v[(opcode & 0x00F0) >> 4])
			v[0xF] = 1;
		else
			v[0xF] = 0;

		v[(opcode & 0x0F00) >> 8] -= v[(opcode & 0x00F0) >> 4];
		pc += 2;
		break;
	case 0x6: //���Ĵ���[X]��ֵ����1λ��ֵ�������൱�������2���������ڼĴ���[X]λ��ǰ���Ὣ�Ĵ���[X]��ֵ�����һλ��ֵ��V[F]��
		v[0xF] = v[(opcode & 0x0F00) >> 8] & 0x1;
		v[(opcode & 0x0F00) >> 8] >>= 1;
		pc += 2;
		break;
	case 0x7: //���Ĵ���[Y]��ֵ��ȥ�Ĵ���[X]��ֵ�����������ֵ���Ĵ���[X]������Ĵ���[Y]��ֵ���ڼĴ���[X]��ֵ��V[F] = 1������V[F] = 0��
		if (v[(opcode & 0x00F0) >> 4] > v[(opcode & 0x0F00) >> 8])
			v[0xF] = 1;
		else
			v[0xF] = 0;

		v[(opcode & 0x0F00) >> 8] = v[(opcode & 0x00F0) >> 4] - v[(opcode & 0x0F00) >> 8];
		pc += 2;
		break;
	case 0xE: //���Ĵ���[X]��ֵ����1λ��ֵ�������൱�������2���������ڼĴ���[X]λ��ǰ���Ὣ�Ĵ���[X]��ֵ�����һλ��ֵ��V[F]��
		v[0xF] = v[(opcode & 0x0F00) >> 8] >> 7;
		v[(opcode & 0x0F00) >> 8] <<= 1;
		pc += 2;
		break;
	}
}

/// <summary>
/// ����opcodeǰһλ0x9�����Ρ�
/// </summary>
void Chip8::Proc9(const uint16_t &opcode)
{
	//����Ĵ���[X]�����ڼĴ���[Y]��������һ��ָ�PC += 4����
	if (v[(opcode & 0x0F00) >> 8] != v[(opcode & 0x00F0) >> 4])
		pc += 4;
	else
		pc += 2;
}

/// <summary>
/// ����opcodeǰһλ0xA�����Ρ�
/// </summary>
void Chip8::ProcA(const uint16_t &opcode)
{
	//��NNN��ֵ���Ĵ���I��
	i = (uint16_t)(opcode & 0x0FFF);
	pc += 2;
}

/// <summary>
/// ����opcodeǰһλ0xB�����Ρ�
/// </summary>
void Chip8::ProcB(const uint16_t &opcode)
{
	//����ǰ����ָ���NNN���ϼĴ���[0]��ֵ��ֵ��PC��
	pc = (opcode & 0x0FFF) + v[0];
}

/// <summary>
/// ����opcodeǰһλ0xC�����Ρ�
/// </summary>
void Chip8::ProcC(const uint16_t &opcode)
{
	//��NN���������0��255�����롱�����Ľ����ֵ���Ĵ���[X]��
	v[(opcode & 0x0F00) >> 8] = (opcode & 0x00FF) & (rand() % 0xFF);
	pc += 2;
}

/// <summary>
/// ����opcodeǰһλ0xD�����Ρ�
/// </summary>
void Chip8::ProcD(const uint16_t &opcode)
{
	//���ڴ�[I]�б���ľ����ԼĴ���[X]���Ĵ���[Y]Ϊ�������X��Y��ֵ��Ϊ������ʼ��д����Ƶ��������
	//�ڴ�[I]��ֵ��1�ֽ�8λ�������˾���1��8�����ص��Ƿ���Ҫ���㣬1������Ҫ���㣬0����Ҫ���㣬����ָ���еľ���߶�����N��0��15��ֵ�����ģ��������������Ҫ���ڴ�[I��N]д��������������
	//��������ص��뵱ǰ���������������ص�������򡱲������������һ�����ص㵼�±��������Ĵ���[F]������Ϊ1����������Ϊ0��
	//���������ĳ���ݿ����Ļʱ����Ҫ���ⲿ�ֻ�����ʾ����Ļ�Ķ��档����ǰ����Ƶ�������������Ӧ����д��ľ���ĵ��غ�ʱ��Ҫ���Ĵ���[F]��ֵ���ó�1��
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
			//��0x80(1000 0000)����0��7λ���ٺ�spriteLine����λ����������ж�spriteLineÿһλ�Ƿ�Ϊ1��
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
/// ����opcodeǰһλ0xE�����Ρ�
/// </summary>
void Chip8::ProcE(const uint16_t &opcode)
{
	switch (opcode & 0x00FF)
	{
	case 0x9E:
		//�����ؼ��̵İ�����keyboard[�Ĵ���[X]]�������£�������һ��ָ�PC += 4����
		if (keyboard[v[(opcode & 0x0F00) >> 8]] != 0)
			pc += 4;
		else
			pc += 2;
		break;
	case 0xA1:
		//�����ؼ��̵İ�����keyboard[�Ĵ���[X]]��û�б����£�������һ��ָ�PC += 4����
		if (keyboard[v[(opcode & 0x0F00) >> 8]] == 0)
			pc += 4;
		else
			pc += 2;
		break;
	}
}

/// <summary>
/// ����opcodeǰһλ0xF�����Ρ�
/// </summary>
void Chip8::ProcF(const uint16_t &opcode)
{
	switch (opcode & 0x00FF)
	{
	case 0x07:
		//����ʱ�Ĵ�����ֵ��ֵ���Ĵ���[X]��
		v[(opcode & 0x0F00) >> 8] = delayTimer;
		pc += 2;
		break;
	case 0x0A:
	{
		//�ȴ�һ�����̰��������£�Ȼ�������ֵ���Ĵ���[X]�������赲�������������Բ��ı�PC��ֵ��ʹ�ø�ָ���ظ����У���
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
		//���Ĵ���[X]��ֵ��ֵ����ʱ�Ĵ�����
		delayTimer = v[(opcode & 0x0F00) >> 8];
		pc += 2;
		break;
	case 0x18:
		//���Ĵ���[X]��ֵ��ֵ�����ּ�ʱ�Ĵ�����
		soundTimer = v[(opcode & 0x0F00) >> 8];
		//���Ĵ���[X]��ֵ��ֵ�����ּ�ʱ�Ĵ���soundTimer����ֵ��Ϊ0ʱ��PC���Ȼ�����Ȼ��soundTimer��60��֮һ��ݼ���������0ʱ��PC����ֹͣ������
		//����ֱ����soundTimer����60��֮һ����Ľ����ΪPC����������ʱ������������Beep�������������ּ�ʱ�Ĵ���soundTimer��60��֮һ��ĵݼ�������ʵ�����á�
		//Beep((int)(soundTimer * (1000.0f / 60)));
		pc += 2;
		break;
	case 0x1E:
		//�Ĵ���I�������Ĵ���[X]��ֵ��
		i += v[(opcode & 0x0F00) >> 8];
		pc += 2;
		break;
	case 0x29:
		//�����鴢���ڼĴ���[X]������ֵ*Chip8�ַ��Ĵ�С��5�ֽڣ���ֵ���Ĵ���I��������ֵ = 0��I = 0 * 5��������Ⱦ�ַ�0������ֵ = 1��I = 1 * 5��������Ⱦ�ַ�1������ֵ = 2��I = 2 * 5��������Ⱦ�ַ�2���Դ����ƣ�
		i = (uint16_t)(v[(opcode & 0x0F00) >> 8] * 0x5);
		pc += 2;
		break;
	case 0x33:
		//���Ĵ���[X]�д����BCD�루���ֱ�����ʽ������4���ֽ�������һ��ʮ���Ƶ����룬ʹ�����ƺ�ʮ����֮���ת�����Կ�ݵĽ��С����Ž��ڴ��У��ڴ��ַ������I��ʼ����ൽI+2��
		memory[i] = v[(opcode & 0x0F00) >> 8] / 100;
		memory[i + 1] = (v[(opcode & 0x0F00) >> 8] / 10) % 10;
		memory[i + 2] = (v[(opcode & 0x0F00) >> 8] % 100) % 10;
		pc += 2;
		break;
	case 0x55:
		//�ѼĴ���[0]���Ĵ���[X]��ֵ�����ڴ�[I]�У�ÿ��һ���Ĵ���ֵ��I����1��������ɺ������ж���˵����һ��˵�����ִ�������I��ֵ���䣬����һ��˵����I += X + 1������ѡ�񲻱��ʵ�֡�
		for (int vi = 0; vi <= ((opcode & 0x0F00) >> 8); vi++)
		{
			memory[i + vi] = v[vi];
		}
		pc += 2;
		break;
	case 0x65:
		//FX55���෴���������ڴ�[I]�е�ֵ���Ž��Ĵ���[0]���Ĵ���[X]�У�ÿ��һ���Ĵ���ֵ��I����1��������ɺ������ж���˵����һ��˵�����ִ�������I��ֵ���䣬����һ��˵����I += X + 1������ѡ�񲻱��ʵ�֡�
		for (int vi = 0; vi <= ((opcode & 0x0F00) >> 8); vi++)
		{
			v[vi] = memory[i + vi];
		}
		pc += 2;
		break;
	}
}