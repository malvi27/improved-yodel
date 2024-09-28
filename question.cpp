#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string lc(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string newString(string str) {
    string result = "";
    for (char c : str) {
        if (isalnum(c) || isspace(c)) {
            result = result+ c;
        } else if (c == '&' || c == ',') {
            result = result + ' ';
        }
    }
    return result;
}

string clear_spaces(string &str) 
{
    string nstr;
    bool space_not = false;
    auto it = str.begin();
    while (it != str.end() && isspace(*it)) 
    {
        ++it;
    }

    for (; it != str.end(); ++it) 
    {
        if (isspace(*it)) 
        {
            if (space_not) 
            {
                nstr = nstr + ' ';
                space_not = false;
            }
        } 
        else 
        {
            nstr = nstr + *it;
            space_not = true;
        }
    }
    return nstr;
}


string removeSuffix(string str) 
{
    string suffixes[] = {"inc.", "corp.", "llc.", "l.l.c.", "llc"};
    str = clear_spaces(str);
    
    for (string i : suffixes) {
        if (str.size() >= i.size() && lc(str.substr(str.size() - i.size())) == i) {
            str = str.substr(0, str.size() - i.size()-1); // changed here to -1
            str = clear_spaces(str);
            break;
        }
    }
    return str;
}

string removeArticles(string str) {
    str = clear_spaces(str);
    
    if (str.size() > 3 && lc(str.substr(0, 4)) == "the ") {
        return str.substr(4);
    } else if (str.size() > 2 && lc(str.substr(0, 2)) == "a ") {
        return str.substr(2);
    } else if (str.size() > 3 && lc(str.substr(0, 3)) == "an ") {
        return str.substr(3);
    }
    
    return str;
}


string removeAnd(string str)
{
    str = clear_spaces(str);
    string result;
    int start = 0;
    int pos = str.find(" and ");
    while (pos != -1) 
    {
        if (pos > 0) 
        {
            result =result+ str.substr(start, pos - start);
        }
        start = pos + 4;
        pos = str.find(" and ", start);
    }
    result = result +str.substr(start);
    return result;
}

string alterString(string str) {
    str = lc(str);
    cout << str << endl;
    str = removeSuffix(str);
    cout << str << endl;
    str = newString(str);       
    cout << str << endl;
    str = removeArticles(str);
    cout << str << endl;
    str = clear_spaces(str);
    cout << str << endl;
    str = removeAnd(str);
    cout << str << endl;
    
    return str;
}


void check_availability( vector<pair<string, string>>& requests) 
{
    unordered_set<string> used_names; 
    for ( auto& request : requests) {
        string account_id = request.first;
        string proposed_name = request.second;
        string altered_name = alterString(proposed_name);
        if (altered_name.empty()) 
        {
            cout << account_id << "|Name not Available" << endl;
            continue;
        }
        if (used_names.find(altered_name) == used_names.end()) 
        {
            cout << account_id << "|Name Available" << endl;
            used_names.insert(altered_name);
        } 
        else 
        {
            cout << account_id << "|Name not Available" << endl;
        }
    }
}

int main() 
{
    vector<pair<string, string>> requests;
    int n;
    cout << "Enter the number of requests: ";
    cin >> n;
    cin.ignore();
    string line[n];
    for (int i=0; i<n; i++) getline(cin, line[i]);
    for (int j=0; j<n; j++)
    {
        int pipe = -1;
        for (int i = 0; i < line[j].length(); ++i) 
        {
            if (line[j][i] == '|') 
            {
                pipe = i;
                break;
            }
        }

        if (pipe != -1) 
        {
            string account_name = line[j].substr(0, pipe);
            string company_name = line[j].substr(pipe + 1);
            requests.push_back(make_pair(account_name, company_name));
        }
    }
    check_availability(requests);

    return 0;
}
