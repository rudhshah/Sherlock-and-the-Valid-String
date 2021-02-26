#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    int old_freq = 0;
    int max_freq = 0;
    int new_freq = 0;
    auto second_char = s.begin();
    bool warning = false;
    bool skip = false;
    sort(s.begin(), s.end()); // sort the string
    auto prev = *s.begin();

    for (auto i = s.begin(); i != s.end(); i++)
    {
        if (prev == *i)
        {
            old_freq++;
        }
        else
        {
            second_char = i;
            prev = *i;
            break;
        }

    }

    for (auto j = second_char; j != s.end(); j++)
    {

        cout << *j << " ";
        if (prev == *j)
        {
            new_freq++;
        }
        else
        {
            if (abs(old_freq - new_freq) > 1 )
            {
                if (new_freq > 1)
                {
                    return "NO";   
                }
                else if(warning)
                {
                    return "NO";
                }
                else
                {
                    warning = true;
                    skip = true;
                }
            }

            if ((!warning && abs(old_freq - new_freq) == 1))
            {
                warning = true;
                skip = true;
                //continue;
            }
            else if (abs(old_freq - new_freq) == 1 && warning)
            {
                return "NO";
            }
            if (!skip)
            {
                if (max_freq < new_freq)
                {
                    old_freq = new_freq;
                    max_freq = new_freq;
                }
            }
            new_freq = 1;
        }
        prev = *j;
    }

    if (abs(old_freq - new_freq) > 1)
    {
       if (new_freq > 1 )
        {
            return "NO";   
        }
        else if(warning)
        {
            return "NO";
        }
        else
        {
            warning = true;
        }
    }
    if ((warning && abs(old_freq - new_freq) >= 1))
    {
        if (!warning)
        {
            warning = true;
        }
        else
        {
            if (abs(old_freq - new_freq) == 1)
            {
                return "NO";
            }
        }

    }
    old_freq = new_freq;
    new_freq = 0;

    return "YES";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
