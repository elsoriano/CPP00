#include <iostream>

int	main(int argc, char **argv)
{
	bool	space;
	int		i;
	int		j;

	space = true;
	i = 1;
	j = 0;
	if (argc < 2)
	{
		std::cout << "LOUD AND UNBEARABLE NOISE" << "\n";
		return (0);
	}
	while (i < argc && space)
	{
		while (argv[i][j])
		{
			if (!std::isspace(static_cast <unsigned char> (argv[i][j])))
			{
				space = false;
				break;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (space)
		std::cout << "LOUD AND UNBEARABLE NOISE" << "\n";
	else
	{
		i = 1;
		while (i < argc)
		{
			while (argv[i][j])
			{
				std::cout << static_cast <char> (std::toupper(static_cast <unsigned char> (argv[i][j])));
				j++;
			}
			i++;
			if (i >= argc)
				std::cout << std::endl;
			j = 0;
		}
	}
	return (0);
};
