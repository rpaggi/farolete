#ifndef ENEMMYPARMSINTERFACE_HPP
#define ENEMMYPARMSINTERFACE_HPP

#include <string>

class EnemmyParmsInterface{
private:	
	int               id;
	char              name[50];
	float             velocity;
	int               idGun;

public:
	EnemmyParmsInterface();
	
	int               getId();
	std::string       getName();
	float             getVelocity();
	int               getIdGun();

};

#endif