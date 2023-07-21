#include <math.h>
#include <stdio.h>



int	main(void)
{
	int	i;
	int j;
	double	x1;
	double	y1;
	int	x2;
	int	y2;

	i = 0;
	while (i < 5000)
	{
		j = 0;
		while (j < 5000)
		{
			x1 = i * cos(M_PI / 5) - j * cos(M_PI / 7);
			y1 = i * sin(M_PI / 5) + j * sin(M_PI / 7) - 3;
			x2 = i * cos(M_PI / 5) - j * cos(M_PI / 7) - 0.5;
			y2 = i * sin(M_PI / 5) + j * sin(M_PI / 7) - 3 + 0.5;
//			if ((x1 != x2) || (y1 != y2))
				printf("(%2f, %2f)\t(%2d, %2d)\n", x1, y1, x2, y2);
			j++;
		}
		i++;
	}
	
}