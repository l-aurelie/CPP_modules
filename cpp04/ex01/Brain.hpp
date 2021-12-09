#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain{
public:
	Brain(void);
	Brain(const std::string idea[100]);
	Brain(const Brain &src);
	virtual ~Brain(void);
	
	Brain &operator=(const Brain &rhs);

	void	setIdea();
	void	setIdea(int index, std::string new_idea);
	void 	print_brain_content() const;

private:
	std::string _idea[100];
};

#endif
