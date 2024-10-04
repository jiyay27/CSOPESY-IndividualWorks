#ifndef MARQUEECONSOLE_H
#define MARQUEECONSOLE_H

#include <conio.h>
#include <bits/stdc++.h>
#include <unistd.h>

#include <string>
#include <vector>

extern std::string currCommand;
extern std::vector<std::string> commands;

void pollKeyboard();
void drawScreen();

#endif