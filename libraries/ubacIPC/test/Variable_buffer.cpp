
#include <iostream>
#include <ubacipc/VariableBuffer.h>
#include <stdio.h>

using namespace std;

void custom_cpy(char *start, char *end, char *res)
{
	while(start < end) {
		*res = *(start);
		start++;
		res++;
	}
}

class Client:
	public VariableBuffer
{
	public:
		Client(size_t s):VariableBuffer::VariableBuffer(s, 10)
		{
		}

		~Client() {}

		size_t determine_packet_size(void *data)
		{
			int size = 10 + 5 * (random()%4);
			return size;
		}

};

#include <stdio.h>

#include <time.h>

#include <unistd.h>

int main()
{
	Client nClient(100);
	char str[30] = "abcdefghijklmnopqrstuvwxyz";
	char resB[30] = {0};
	char *start = str;
	char *end = start;
	char *END_OF_INPUT = alph + 26;
	int itr = 0;

	while(1) {
		while(itr > 30) {
			int seed = random()%15;
			end += seed;

			if (end >= END_OF_INPUT) {
				end = END_OF_INPUT;
			}


			custom_cpy(start,end,resB);

			printf("recv: %s, len: %ld\n", resB , strlen(resB));
			nClient.align_data(resB, strlen(resB));

			bzero(resB, sizeof(resB));
			start = end;
			usleep(1000000);
			itr++;
		}

		start = str;
		end = start;
	}

	return 0;
}
