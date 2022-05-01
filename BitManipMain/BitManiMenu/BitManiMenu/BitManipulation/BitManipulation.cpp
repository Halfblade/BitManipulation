#include <iostream>
#include "Console.h"
#include <string>
using namespace System;

unsigned int RightShift(unsigned int bitField);
unsigned int LeftShift(unsigned int bitField);
unsigned int Negate(unsigned int bitField);
unsigned int Toggle(unsigned int bitField, unsigned int bitNumber);
unsigned int TurnOff(unsigned int bitField, unsigned int bitNumber);
unsigned int TurnOn(unsigned int bitField, unsigned int bitNumber);
bool IsBitOn(unsigned int bitField, unsigned int bitNumber);
std::string StringToBinary(unsigned int num, unsigned int bits);


void main()
{
	unsigned int bitField = 0;
	unsigned int nSelectedBit = 0;
	std::string strBits = "Bits: ";

	while (true)
	{
		Console::Lock(true);
		system("cls");

		// render interface
		std::cout << "Bitfield Value: " << bitField << "\n\n";
		std::cout << "F1: Turn On\t\tF2: Turn Off\nF3: Toggle\t\tF4: Negate\nLShift: Shift Left\tRShift: Shift right";
		std::cout << "\n\n" << strBits;
		std::cout << StringToBinary(bitField, 16); //Function built in lecture

		// render bit selector
		Console::SetCursorPosition(strBits.length() + 15 - nSelectedBit, Console::CursorTop() + 1);
		std::cout << "^";

		if (GetAsyncKeyState(VK_LEFT))
		{
			if (nSelectedBit < 16)
				++nSelectedBit;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (nSelectedBit > 0)
				--nSelectedBit;
		}
		if (GetAsyncKeyState(VK_F1))
		{
			//Implement turn on
			bitField = TurnOn(bitField, nSelectedBit);
		}
		if (GetAsyncKeyState(VK_F2))
		{
			//Implement turn off
			bitField = TurnOff(bitField, nSelectedBit);
		}
		if (GetAsyncKeyState(VK_F3))
		{
			//Implement toggle
			 bitField = Toggle(bitField, nSelectedBit);
		}
		if (GetAsyncKeyState(VK_F4))
		{
			//Implement negate
			bitField = Negate(bitField);
		}
		if (GetAsyncKeyState(VK_LSHIFT))
		{
			//Implement left shift
			bitField = LeftShift(bitField);
		}
		if (GetAsyncKeyState(VK_RSHIFT))
		{
			//Implement right shift
			bitField = RightShift(bitField);
		}

		Console::Lock(false);
		Sleep(100);
	}
}


unsigned int RightShift(unsigned int bitField)
{

	return bitField >> 1;

}


unsigned int LeftShift(unsigned int bitField)
{
	
	return bitField << 1;

}

unsigned int Negate(unsigned int bitField)
{

	return bitField =  ~bitField;
}


unsigned int Toggle(unsigned int bitField, unsigned int bitNumber)
{
	unsigned int ontbit = 1 << bitNumber;
	return bitField ^ ontbit;

}


unsigned int TurnOff(unsigned int bitField, unsigned int bitNumber)
{
	unsigned int ontbit = 1 << bitNumber;
	return bitField = (~ontbit) & bitField;

}


unsigned int TurnOn(unsigned int bitField, unsigned int bitNumber)
{
	unsigned int ontbit = 1 << bitNumber;
	return bitField = bitField | ontbit;

}


bool IsBitOn(unsigned int bitField, unsigned int bitNumber)
{
	unsigned int ontbit = 1 << bitNumber;
	return (bitNumber & ontbit) == ontbit;
}

std::string StringToBinary(unsigned int num, unsigned int bits)
{
	std::string text;
	for (unsigned int i = 0; i < bits; i++)
	{
		text = std::to_string(num % 2) + text;
		num /= 2;
	}
	return text;
}