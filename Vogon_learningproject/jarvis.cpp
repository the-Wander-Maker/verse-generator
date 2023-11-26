#include "Jarvis.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cctype>
#include <clocale>
#include <fstream>
#include <windows.h>

#pragma execution_character_set( "utf-8" )


JarvisPoem::JarvisPoem() : rDevice(), rEngine(rDevice()), dist10(0, 10){
	
	//Open file
	const std::string filename = "voc_input.txt";
	std::ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		throw std::runtime_error("Error: voc_input.txt file cannot be opened");
	}

	//Read data
	std::string line;

	getline(inputFile, line);
	read_line(line, adjective);

	getline(inputFile, line);
	read_line(line, object);

	getline(inputFile, line);
	read_line(line, statement);

	getline(inputFile, line);
	read_line(line, quantifiers);

	getline(inputFile, line);
	read_line(line, punctuation);

	inputFile.close();
}

void JarvisPoem::read_line(const std::string& line, std::vector<std::string>& wordVec) const {
	size_t found;
	size_t pos = 0;
	while ((found = line.find(" ", pos)) != std::string::npos){
		wordVec.push_back(line.substr(pos, found - pos));
		pos = found + 1;
	}
	if (pos < line.size()){
		wordVec.push_back(line.substr(pos));
	}
}



void JarvisPoem::vers(const int versszakszam, const int versszaksorszam) {
	for (int i = 0; i < versszakszam; i++) {
		//you have to randomize the two lines in a loop, because then you will not have the same verses
		for (int j = 0; j < versszaksorszam; j++) {
			std::random_device r;

			std::default_random_engine e1(r());
			std::uniform_int_distribution<int> uniform_dist(1, 3);

			//needs the following random variable to create multiple verses
			unsigned random_verse = uniform_dist(e1);

			if (random_verse == 1) {
				std::cout << verseadjective();
				std::cout << std::endl;
			}
			else if (random_verse == 2) {
				std::cout << versestatement();
				std::cout << std::endl;
			}
			else {
				std::cout << verseimperative();
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}
}

std::string JarvisPoem::verseadjective() {
	int random_num = dist10(rEngine);
	return std::string(1,std::toupper(adjective[random_num][0])) + adjective[random_num].substr(1) + std::string(" ") + object[dist10(rEngine)] + std::string(" ") + statement[dist10(rEngine)] + punctuation[dist10(rEngine)];
}

std::string JarvisPoem::versestatement() {
	int random_num = dist10(rEngine);
	return std::string(1, std::toupper(statement[random_num][0])) + statement[random_num].substr(1) + std::string(" ") + quantifiers[dist10(rEngine)] + std::string(" ") + adjective[dist10(rEngine)] + std::string(" ") + object[dist10(rEngine)] + punctuation[dist10(rEngine)];
}

std::string JarvisPoem::verseimperative() {
	int random_num = dist10(rEngine);
	return std::string(1, std::toupper(statement[random_num][0])) + statement[random_num].substr(1) + std::string(" ") + quantifiers[dist10(rEngine)] + std::string(" ") + adjective[dist10(rEngine)] + std::string(" ") + object[dist10(rEngine)] + punctuation[dist10(rEngine)];
}