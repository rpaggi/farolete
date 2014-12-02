#include "LoaderImages.hpp"
#include <iostream>

LoaderImages::LoaderImages(){
}

std::string LoaderImages::getImage(){
	int r = RandomInteger(1, 10);

	std::string out;

	switch (r){
		case 1:
			out = "images/loading/capitao.png";
			break;
		case 2:
			out = "images/loading/colt.png";
			break;
		case 3:
			out = "images/loading/facao.png";
			break;
		case 4:
			out = "images/loading/farolete.png";
			break;
		case 5:
			out = "images/loading/hotchkiss.png";
			break;
		case 6:
			out = "images/loading/luger.png";
			break;
		case 7:
			out = "images/loading/mauser.png";
			break;
		case 8:
			out = "images/loading/sargento.png";
			break;
		case 9:
			out = "images/loading/soldados.png";
			break;
		case 10:
			out = "images/loading/winchester.png";
			break;
	}

	return out;
}