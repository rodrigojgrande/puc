#include <graphics.h>
#include <time.h>
main()
{
	int x, y, c;
	initwindow(640, 480, "Prova", 0, 0);
	srand(time(NULL));
	do
	{
			x = rand() % 640; y = rand() % 480; c = rand() % 16;
			putpixel(x,y,c);
			setcolor(c);
			circle(x,y,5);
			Sleep(200);
	}
	while (!kbhit());
}
