#pragma once
#include <string>
#include <random>
#include <vector>

class JarvisPoem {
public:
	void vers(int versszakszam, int versszaksorszam);

	JarvisPoem();

private:
	std::string verseadjective();
	std::string versestatement();
	std::string verseimperative();
		
	std::random_device rDevice;
	std::default_random_engine rEngine;
	std::uniform_int_distribution<int> dist10;

	std::vector<std::string> adjective;
	std::vector<std::string> object;
	std::vector<std::string> statement;
	std::vector<std::string> quantifiers;
	std::vector<std::string> punctuation;

	void read_line(const std::string& line, std::vector<std::string>& wordVec) const;
};