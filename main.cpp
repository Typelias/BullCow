#include <iostream>
#include <vector>
#include <string>
#include <set>

std::vector<std::pair<std::string, std::string>> guesses;

bool unique(std::string number) {

    std::set<char> checker(number.begin(), number.end());
    if(checker.size() != number.size()) {
        return false;
    }
    return true;

}

std::string generateNextNumber(std::string g) {
    int temp = std::stoi(g);
    temp++;
    while (!unique(std::to_string(temp)))
    {
        temp++;
    }

    return std::to_string(temp);
    
}

std::string bullCow(std::string x, std::string y) {
    int bull = 0;
    int cow = 0;

    for(int i = 0; i < 4; i++) {
        if(x[i] == y[i]) bull++;
        else if(y.find(x[i]) != std::string::npos) cow++;
    }

    return std::to_string(bull) + std::to_string(cow);
}

bool PossibleGuess(std::string guess) {
    for(auto c : guesses) {
        if(bullCow(guess, c.first) != c.second) {           
            return false;
        }
    }
    return true;
}

std::string GenerateGuess() {
    if(guesses.empty()) {
        return "1023";
    }

    std::string g = generateNextNumber(guesses.back().first);

    while(!PossibleGuess(g)){
        g = generateNextNumber(g);
        if(std::stoi(g) > 9999) {
            g = "0000";
        }
    } 

    return g;    
}

int main() {
    std::string seecretIn;
    std::string bull;
    std::string cow;
    std::cout << "tal:\n";
    std::cin>> seecretIn;

    if(seecretIn.length()> 4 || seecretIn.length()<4) {
        std::cout << "error\n";
        return 0;
    }

    if(!unique(seecretIn)) {
        std::cout << "error\n";
        return 0;
    }

    std::cout << "\n\n";

    while(bull != "4") {
        std::cout << "Ditt nummer: \t" << seecretIn << "\n";
        std::string g = GenerateGuess();
        std::cout << "Gissning: \t" << g << "\n";
        std::cout << "bull: ";
        std::cin >> bull;
        std::cout<<"\ncow: ";
        std::cin>>cow;
        guesses.push_back(std::make_pair(g, bull+cow));
    }   
}