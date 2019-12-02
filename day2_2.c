#include <stdio.h>
#include <string.h>

#define INPUT_LEN 153
const int init_mem[INPUT_LEN] = {1, 0, 0, 3, 1, 1, 2, 3, 1, 3, 4, 3, 1, 5, 0, 3, 2, 6, 1, 19, 1, 5, 19, 23, 1, 13, 23, 27, 1, 6, 27, 31, 2, 31, 13, 35, 1, 9, 35, 39, 2, 39, 13, 43, 1, 43, 10, 47, 1, 47, 13, 51, 2, 13, 51, 55, 1, 55, 9, 59, 1, 59, 5, 63, 1, 6, 63, 67, 1, 13, 67, 71, 2, 71, 10, 75, 1, 6, 75, 79, 1, 79, 10, 83, 1, 5, 83, 87, 2, 10, 87, 91, 1, 6, 91, 95, 1, 9, 95, 99, 1, 99, 9, 103, 2, 103, 10, 107, 1, 5, 107, 111, 1, 9, 111, 115, 2, 13, 115, 119, 1, 119, 10, 123, 1, 123, 10, 127, 2, 127, 10, 131, 1, 5, 131, 135, 1, 10, 135, 139, 1, 139, 2, 143, 1, 6, 143, 0, 99, 2, 14, 0, 0};
int memory[INPUT_LEN];

int run(int noun, int verb)
{
	memcpy(memory, init_mem, sizeof(init_mem));
	memory[1] = noun;
	memory[2] = verb;

	for (int i = 0; i < INPUT_LEN; i += 4)
	{
		if (memory[i] == 1)
		{
			memory[memory[i+3]] = memory[memory[i+1]] + memory[memory[i+2]];
		}
		else if (memory[i] == 2)
		{
			memory[memory[i+3]] = memory[memory[i+1]] * memory[memory[i+2]];
		}
		else if (memory[i] == 99)
		{
			return memory[0];
		}
		else
		{
			return -1;
		}
	}
	return -2;	
}

int main(int argc, char const *argv[])
{
	for (int n = 0; n < 100; ++n)
	{
		for (int noun = 0; noun <= n; ++noun)
		{
			int verb = n - noun;
			int result = run(noun, verb);
			if (result == 19690720)
			{
				int id = 100 * noun + verb;
				printf("%d, %d (%d): %d\n", noun, verb, id, result);
			}
		}
	}
	return 0;
}