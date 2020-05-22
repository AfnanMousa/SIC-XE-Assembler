#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "symbolTable.h"

class Controller
{
public:
	Controller() {}
	void findOPCode(symbolTable&,int);

};

#endif // CONTROLLER_H