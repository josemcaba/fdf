#include <math.h>
#include <stdio.h>

int	main(void)
{
	int	i;
	int j;
	int	x1;
	int	y1;
	int	x2;
	int	y2;

	i = 0;
	while (i < 5000)
	{
		j = 0;
		while (j < 5000)
		{
			x1 = (double)i * cos(M_PI / 6) - (double)j * cos(M_PI / 6);
			y1 = (double)i * sin(M_PI / 6) + (double)j * sin(M_PI / 6) - (double)0.5;
			x2 = i * cos(M_PI / 6) - j * cos(M_PI / 6);
			y2 = i * sin(M_PI / 6) + j * sin(M_PI / 6) - 0.5;
			if ((x1 != x2) || (y1 != y2))
				printf("(%2d, %2d)\t(%2d, %2d)\n", x1, y1, x2, y2);
			j++;
		}
		i++;
	}
	
}