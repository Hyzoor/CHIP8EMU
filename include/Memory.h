#ifndef MEMORY_H
#define MEMORY_H
#include <cstdint>
#include <string>

class Memory {

  public:
	Memory();
	~Memory();

	void loadROM(const std::string &);
	void write(uint16_t, uint8_t);
	uint8_t read(uint16_t);

  private:
	uint8_t memoryArray[4096]{};
	void initSprites();
};

#endif
