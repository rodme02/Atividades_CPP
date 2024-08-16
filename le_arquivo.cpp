#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

int main(int argc, char* argv[]) {
    using namespace std;

    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Failed to open the input file: " << filename << endl;
        return 1;
    }

    string line;
    int totalWords = 0;
    int totalLines = 0;
    map<string, int> wordFrequency;

    while (getline(inputFile, line)) {
        totalLines++;

        istringstream iss(line);
        string word;
        while (iss >> word) {
            totalWords++;
            wordFrequency[word]++;
        }
    }

    inputFile.close();

    double averageWordsPerLine = static_cast<double>(totalWords) / totalLines;

    string outputFilename = "output.txt";
    ofstream outputFile(outputFilename);

    if (!outputFile) {
        cerr << "Failed to create the output file: " << outputFilename << endl;
        return 1;
    }

    outputFile << "Total words: " << totalWords << endl;
    outputFile << "Total lines: " << totalLines << endl;
    outputFile << "Average words per line: " << averageWordsPerLine << endl;

    string mostFrequentWord;
    int maxFrequency = 0;

    for (const auto& pair : wordFrequency) {
        if (pair.second > maxFrequency) {
            mostFrequentWord = pair.first;
            maxFrequency = pair.second;
        }
    }

    outputFile << "Most frequent word: " << mostFrequentWord << " (appeared " << maxFrequency << " times)" << endl;

    outputFile.close();

    cout << "Statistics saved to " << outputFilename << endl;

    return 0;
}
