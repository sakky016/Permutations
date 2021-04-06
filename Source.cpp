#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>


using namespace std;


//-------------------------------------------------------------------------------------
// Display usage information
//-------------------------------------------------------------------------------------
static void Usage()
{
    cout << "Usage:\n";
    cout << "Permuations.exe <character sequence>\n";
}



//-------------------------------------------------------------------------------------
// Fetches a vector of different permutations of the given character sequence
//-------------------------------------------------------------------------------------
static vector<string> getPermutations(const string & input)
{
    vector<string> permutations;

    // next_permutations() is destructive in nature, so make a copy
    // of the input strings
    string tmp(input);

    // Sort the input first in lexicographical order
    sort(tmp.begin(), tmp.end());

    do
    {
        permutations.emplace_back(tmp);
    } while (next_permutation(tmp.begin(), tmp.end()));
    
    return permutations;
}


//-------------------------------------------------------------------------------------
// M A I N
//-------------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        Usage();
        return 0;
    }

    string input = argv[1];
    vector<string> permutations = getPermutations(input);

    if (permutations.size())
    {
        cout << "There are " << permutations.size() << " permutations of " << input << " are:\n";
        for (const auto& entry : permutations)
        {
            cout << entry << endl;
        }
    }
    

    return 0;
}