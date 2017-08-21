/*********************************************************
Materia: Gráficas Computacionales
Fecha: 21 de agosto del 2017
Autor: A01374637 Josep Romagosa Llorden
*********************************************************/

#include "InputFile.h"
#include <string>
#include <iostream>
#include <fstream>

bool InputFile::Read(std::string filename) {
	_contents = "";
	std::ifstream file;
	file.open(filename);
	if (file.is_open())
	{
		std::string str;
		while (std::getline(file, str))
		{
			_contents = _contents + str + "\n";
		}
		return true;
	}

	return false;

	return 0;

}

std::string InputFile::GetContents() {
	return _contents;
}