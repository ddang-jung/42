#include <string>
#include <fstream>
#include <iostream>

int	main(int ac, char **av) {
	if (ac != 4 || !*av[1] || !*av[2] || !*av[3]) {
		std::cout <<  "Error: Unvalid arguments." << std::endl;
		return (1);
	}
	std::string		name = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::string		line;
	std::ifstream	in;
	std::ofstream	out;
	size_t			idx;

	in.open(name, std::ios_base::in);
	if (in.fail()) {
		std::cout << "Error: Failed open infile." << std::endl;
		return (1);
	}
	out.open(name.append(".replace"), std::ios_base::out);
	if (out.fail()) {
		std::cout << "Error: Failed open outfile." << std::endl;
		return (1);
	}

	while (std::getline(in, line)) {
		idx = line.find(s1);
		while (idx != std::string::npos) {
			line.erase(idx, s1.length());
			line.insert(idx, s2);
			idx = line.find(s1);
		}
		out << line << std::endl;
	}
	in.close();
	out.close();
	return (0);
}