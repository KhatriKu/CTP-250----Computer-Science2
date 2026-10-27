#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "WordFrequencyAnalyzer.h"
#include "WordInfo.h"
#include "KeyValuePair.h"

using namespace std;

void LoadHashMap(WordFrequencyAnalyzer &HashMap, WordFrequencyAnalyzer &HashMap1, WordFrequencyAnalyzer &HashMap2, WordFrequencyAnalyzer &HashMap3,ifstream &inFs){
    string line;
    while (inFs >> line) {
        HashMap.addWord(line);
            HashMap1.addWord(line);
            HashMap2.addWord(line);
            HashMap3.addWord(line);
    }
}
void displayBuckets(WordFrequencyAnalyzer &HashMap, WordFrequencyAnalyzer &HashMap1, WordFrequencyAnalyzer &HashMap2, WordFrequencyAnalyzer &HashMap3){
    HashMap.displayAnalysis();
    HashMap.printDistribution();
    HashMap1.displayAnalysis();
    HashMap1.printDistribution();
    HashMap2.displayAnalysis();
    HashMap2.printDistribution();
    HashMap3.displayAnalysis();
    HashMap3.printDistribution();
}


int main() {
    ifstream greatGatsby("partOfBeginningTheGreatGatsby.txt");
    if (!greatGatsby) {throw runtime_error("File was unable to be opened.");}
    WordFrequencyAnalyzer HashMap(1);
    WordFrequencyAnalyzer HashMap1(2);
    WordFrequencyAnalyzer HashMap2(3);
    WordFrequencyAnalyzer HashMap3(4);
    LoadHashMap(HashMap, HashMap1, HashMap2, HashMap3, greatGatsby);
    displayBuckets(HashMap, HashMap1, HashMap2, HashMap3);
    return 0;
}
/**
 1. The purpose of the inner vector is that allows for multiple KeyValuePair Objects to fall into one bucket  as the buckets can dynammically resize thanks to the vector class - the outer vector acts like a bucket itself. - It makes it easier to find items in each bucket as well by using linear scans. In addition - it enhances the runtime complexity of the program to O(N) - where N is the amount of items in a bucket of the given index of the key
 
 2. One bucket would signifigantly reduce the runtime complexity of the program to O(N) considering everything is in a single vector. 1000 Buckets actually do have a lower runtime complexity BUT they use up a lot more memory in the Heap and Stack. This tells me that Bucket choosing should be porportional to the number of expected unique words - I would personally use a bigger bucket size for academic papers compared to papers in the frst person which would use more tense words and personable words that repeat.
 
 3.    Look at the printDistribution() output for all four hash functions. Which function produced the most even distribution? Which produced the worst? What do you think makes one hash function better than another for this purpose?
 
 
 
 4.    The ASCII sum function has a known weakness: it produces the same hash value for anagrams (e.g., "stop" and "pots" hash to the same bucket). Did any of your three researched functions address this problem? If so, how?  5.  Change the number of buckets in the table 2 times and rerun your analysis.  What number of buckets do you like?  Why?
 
 
 
 */
