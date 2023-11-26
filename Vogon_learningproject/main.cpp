#include <iostream>
#include <windows.h>

#include "Jarvis.h"

#pragma execution_character_set( "utf-8" ) 



int main() {
	SetConsoleOutputCP(65001); // If you would like to use languages with accent, you will need this.

	JarvisPoem Version_1;
	std::cout << "-------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "--------------------------------------------------Jarvis-Version_1-------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	int verse;
	int versus;
	while (true) {
		std::cout << "- Greetings Traveler. I am the virtual poet of the Forgotten Realms, you can ask me to performe some bard magic if you would like to. " << std::endl;
		std::cout << std::endl;
		std::cout << "- Please tell me how many stanzas you would like me to write, said the poet, with an anxious look in his eyes. " << std::endl;
		std::cin >> verse;
		std::cout << std::endl;
		std::cout << "- Please indicate the number of lines in the stanzas, the poet asked. " << std::endl;
		std::cin >> versus;
		std::cout << std::endl;
		std::cout << "Then the poet took pen in hand and began the poem, which is: " << std::endl;
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		Version_1.vers(verse, versus);
		
		system("pause");

		std::cout << std::endl;
		std::string is_ending;
		std::cout << "- Would you like to repeat me the process? yes - no " << std::endl;
		std::cin >> is_ending;

		while (is_ending != "yes" && is_ending != "no") {
			std::cout << "You gave wrong answer, please type yes or no, thank you. " << std::endl;
			std::cin >> is_ending;
		}

		if (is_ending == "yes") {
			continue;
		}
		else {
			break;
		}
		
	}
	return 0;
}