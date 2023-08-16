#include "Serializer.hpp"
#include <iostream>

int	main(void) {
	Data		data;
	uintptr_t	raw;
	Data		*ddata;

	data.value = 42;
	std::cout << "data value  : " << data.value << std::endl;
	std::cout << "data ptr    : " << &data << std::endl;

	raw = Serializer::serialize(&data);
	std::cout << "raw         : " << raw << std::endl;

	ddata = Serializer::deserialize(raw);
	std::cout << "ddata value : " << ddata->value << std::endl;
	std::cout << "ddata ptr   : " << ddata << std::endl;
	return (0);
}