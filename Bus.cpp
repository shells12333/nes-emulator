#include "Bus.h"

Bus::Bus()
{
	for (auto& i : ram) i = 0x00; // flush ram

	cpu.ConnectBus(this);
}

void Bus::write(uint16_t addr, uint8_t data)
{
	if(addr >= 0x0000 && addr <= 0xFFFF) // address guard
	ram[addr] = data;
}

uint8_t Bus::read(uint16_t addr, bool bReadOnly)
{
	if (addr >= 0x0000 && addr <= 0xFFFF) // address guard
		return ram[addr];
	return 0x00; // else
}

Bus::~Bus()
{

}