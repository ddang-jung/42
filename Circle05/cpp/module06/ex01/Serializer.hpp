#pragma once

# include <cstdint>

typedef struct	s_Data {
	int	value;
}	Data;

class Serializer
{
	private:
		// OCF
		Serializer(void);
		Serializer(const Serializer& ref);
		Serializer	&operator=(Serializer const& ref);
		virtual	~Serializer(void);

	public:
		// METHOD
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};