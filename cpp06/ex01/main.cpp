#include <iostream>
#include <stdint.h>

typedef struct	Data
{
	char	c;
	int		i;
	float	f;
	double	d;
}				Data;

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t val)
{
	return (reinterpret_cast<Data*>(val));
}

int	main(void)
{
	Data*		data = new Data();
	uintptr_t	val;

	data->c = 'c';
	data->i = 42;
	data->f = 42.42;
	data->d = 42.4242;

	std::cout << "data address: " << data << std::endl;

	val = serialize(data);
	std::cout << "val address: " << val << std::endl;

	data = deserialize(val);
	std::cout << "data address: " << data << std::endl;

	std::cout << data->c << " | " << data->i << " | " << data->f << " | " << data->d <<  std::endl;

	delete data;

	return (0);
}
