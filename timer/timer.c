#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

void *startTimer(void *vargp)
{
	int end = 300;
	int mins = end / 60;

	for (end; end > 0; end--)
	{
		int secs = end % 60;

		if (secs < 10)
		{
			printf("%i:0%i\n", mins, secs);
		}
		else
		{
			printf("%i:%i\n", mins, secs);
		}
		
		if (secs == 0)
		{
			mins --;
		}
		
		sleep(1);
	}

	return NULL;
}

int main(int argc, char const *argv[])
{

	pthread_t thread_id;

	pthread_create(&thread_id, NULL, startTimer, NULL);
	pthread_join(thread_id, NULL);
	
	return 0;
}