#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'stringAnagram' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY dictionary
 *  2. STRING_ARRAY query
 */
 

 /*
 Ideas:
- sort each string item in dictionary vector, then create a map<string, int> (counts) to count freq of each string in dictionary
- iterate through the second vector - query, sort each string item, the number of that anagram is value of counts[string].

 */


vector<int> stringAnagram(vector<string> dictionary, vector<string> query) {
    unordered_map<string, int> counts;
    for (int i = 0; i < dictionary.size(); i++) {
        sort(dictionary[i].begin(), dictionary[i].end());
    }
    
    for (int i = 0; i < dictionary.size(); i++) {
        counts[dictionary[i]] ++;
    }
    
    vector<int> freq;
    
    for (int j = 0; j < query.size(); j++) {
        sort(query[j].begin(), query[j].end());
        freq.push_back(counts[query[j]]);
    }
    
    
    return freq;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string dictionary_count_temp;
    getline(cin, dictionary_count_temp);

    int dictionary_count = stoi(ltrim(rtrim(dictionary_count_temp)));

    vector<string> dictionary(dictionary_count);

    for (int i = 0; i < dictionary_count; i++) {
        string dictionary_item;
        getline(cin, dictionary_item);

        dictionary[i] = dictionary_item;
    }

    string query_count_temp;
    getline(cin, query_count_temp);

    int query_count = stoi(ltrim(rtrim(query_count_temp)));

    vector<string> query(query_count);

    for (int i = 0; i < query_count; i++) {
        string query_item;
        getline(cin, query_item);

        query[i] = query_item;
    }

    vector<int> result = stringAnagram(dictionary, query);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
