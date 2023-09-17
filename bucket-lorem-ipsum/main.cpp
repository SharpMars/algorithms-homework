#include <iostream>

using namespace std;

void bucketSort(string str, int buckets[])
{
    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case ' ':
            buckets[26]++;
            break;
        case ',':
            buckets[27]++;
            break;
        case '.':
            buckets[28]++;
            break;
        default:
            buckets[str[i] - 97]++;
            break;
        }
    }
}

int main()
{
    int buckets[29] = {0};

    //needs to be lower case
    string lorem = "lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    bucketSort(lorem, buckets);

    for (int i = 0; i < 29; i++)
    {
        switch (i)
        {
        case 26:
            cout << "Space: " << buckets[i] << endl;
            break;
        case 27:
            cout << "Period: " << buckets[i] << endl;
            break;
        case 28:
            cout << "Dot: " << buckets[i] << endl;
            break;
        default:
            cout << char(i + 97) << ": " << buckets[i] << endl;
            break;
        }
    }

    return 0;
}