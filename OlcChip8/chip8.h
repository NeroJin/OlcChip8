#pragma once
#include <cstdint>



class Chip8
{
public:
	Chip8();
	~Chip8();

	//
	//  ժҪ:
	//      CHIP8���ڴ��С
	const static int MEMORY_SIZE = 4096;
	//
	//  ժҪ:
	//      CHIP8�ļĴ�����С
	const static int REGISTER_SIZE = 16;
	//
	//  ժҪ:
	//      CHIP8��ջ��С
	const static int STACK_SIZE = 16;

	//
	//  ժҪ:
	//      CHIP8��ջ��С
	const static int KEYBOARD_KEYS_SIZE = 16;

	//
	//  ժҪ:
	//      0x200��chip8����ʼ�ĵ�ַ��
	const static int START_ADDRESS = 0x200;

	//
	//  ժҪ:
	//      ��ʾCHIP8����ʾ����׼���ؿ�ȡ����ֶ�Ϊ������
	const static int SCREEN_WIDTH = 64;

	//
	//  ժҪ:
	//      ��ʾCHIP8����ʾ����׼���ظ߶ȡ����ֶ�Ϊ������
	const static int SCREEN_HEIGHT = 32;

	//����֪ͨ���ⲿ�����Ƿ���Ҫ���»�ͼ��
	bool needsRedraw = true;

	//����֪ͨ���ⲿ�����Ƿ���Ҫ��������������
	bool needsSound = false;

	//�ڴ�4K
	uint8_t memory[MEMORY_SIZE];

	//16��8λ�Ĵ�����v0-vf��
	uint8_t v[REGISTER_SIZE];

	//16λ�ļĴ��������ڱ����ڴ��ַ��
	uint16_t i;

	//16λ�ĳ��������,����voidָ�롣
	uint16_t pc;

	//��ջ
	uint16_t stack[KEYBOARD_KEYS_SIZE];

	//��ջָ��
	uint16_t sp;

	//�˶�ʱ�����ڼ�ʱ��Ϸ�¼���ÿ60Hz�ݼ�1����0��ͣ�á�Ҳ���ǻ���ÿ����һ֡���ͼ�1��
	uint8_t delayTimer;

	//���������������Դ洢0-255��ֵ��ÿ60Hz�ݼ�1����ֵ��Ϊ��ʱ���ᷢ����������
	uint8_t soundTimer;

	//��Ƶ������,������ʾ64��32���ص�ͼ��
	bool videoBuffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	//���ڴ洢��ǰ��CPU����ָ�
	uint16_t opcode;

	//CHIP8�ļ��̡�
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
	/// CHIP8 CPU���ں�����ÿһ�����ڵ���һ�Σ�����ִ��CPUָ�Ĭ�ϵ�������1/840������һ�Ρ�
	/// </summary>
	void Tick();

	/// <summary>
	/// CHIP8��ÿ��60֮֡1���ں�����ÿһ�����ڵ���һ�Σ����ڻ�����Ļ����ʱ��ʱ���ĵݼ���Ĭ�ϵ�������1/60������һ�Ρ�
	/// </summary>
	void TicksPer60FPS();

	void Init();

	bool LoadRom(const char * filename);

};
