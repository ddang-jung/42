# define ERROR 1

void	error_handler(char *msg)
{
	printf("Error\n%s.\n", msg);
	exit();
}

void	check(int ac, char **av)
{
	if (ac != 2)
		error_handler("Invalid Number of Arguments");
	if (*av[1] == '\0')
		error_handler("Empty Filename");
	if (check_file_extension(av[1]))
		error_handler("Not a '.cub' File");
}

int	main(int ac, char **av)
{
	check(ac, av);
	start();
	return (0);
}
