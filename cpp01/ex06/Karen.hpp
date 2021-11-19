#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>
#include <iostream>
#include <string>

class Karen{
public:
	Karen(void);
	~Karen(void);
	void complain(const std::string &level);

private:
	void _debug(void) const;
	void _info(void) const;
	void _warning(void) const;
	void _error(void) const;
};
#endif
