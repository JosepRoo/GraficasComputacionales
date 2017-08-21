/*********************************************************
Materia: Gráficas Computacionales
Fecha: 21 de agosto del 2017
Autor: A01374637 Josep Romagosa Llorden
*********************************************************/

#pragma once
#include <string>

class InputFile
{
public:
	bool Read(std::string);
	std::string GetContents();
private:
	std::string _contents;
};

