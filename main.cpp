#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;

void fillStrs(string *randStr, int size);
void printStrs(string * randStr, int size);
void strBubSort(string *str, int size);
void strSelSort(string *s, int size);
void linSearch(string *s, int size);
void binSearch(string *s, int size);

int main()
{
    srand(time(NULL));
    double cpu_time_used = 0;
    string randStrBub1[1000], randStrSel1[1000];
    string randStrBub3[3000], randStrSel3[3000];
    string randStrBub5[5000], randStrSel5[5000];
    string randStrBub7[7000], randStrSel7[7000];
    string randStrBub9[9000], randStrSel9[9000];
    string randStrBub11[11000];
    //declaring the variable below
    //is causing my program to crash..
    //string randStrSel11[11000];
    fillStrs(randStrBub1, 1000);
    fillStrs(randStrSel1, 1000);
    fillStrs(randStrBub3, 3000);
    fillStrs(randStrSel3, 3000);
    fillStrs(randStrBub5, 5000);
    fillStrs(randStrSel5, 5000);
    fillStrs(randStrBub7, 7000);
    fillStrs(randStrSel7, 7000);
    fillStrs(randStrBub9, 9000);
    fillStrs(randStrSel9, 9000);
    fillStrs(randStrBub11, 11000);
    clock_t start = clock();
    strBubSort(randStrBub1, 1000);
    clock_t stop = clock();
    cpu_time_used = (((double)stop - start)) / CLOCKS_PER_SEC;
    cout << "---------------------------------" << endl;
    cout << setw(20) << "bubble sort:" << endl;
    cout << "1000 strings: " << setw(8) << fixed <<
        setprecision(4) << cpu_time_used << " seconds" << endl;
    start = clock();
    strBubSort(randStrBub3, 3000);
    stop = clock();
    cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
    cout << "3000 strings: " << setw(8) << cpu_time_used << " seconds" << endl;
    start = clock();
    strBubSort(randStrBub5, 5000);
    stop = clock();
    cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
    cout << "5000 strings: " << setw(8) << cpu_time_used << " seconds" << endl;
    start = clock();
    strBubSort(randStrBub7, 7000);
    stop = clock();
    cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
    cout << "7000 strings: " << setw(8) << cpu_time_used << " seconds" << endl;
    start = clock();
    strBubSort(randStrBub9, 9000);
    stop = clock();
    cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
    cout << "9000 strings: " << setw(8) << cpu_time_used << " seconds" << endl;
    start = clock();
    strBubSort(randStrBub11, 11000);
    stop = clock();
    cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
    cout << "11000 strings: " << setw(7) << cpu_time_used << " seconds" << endl;
    cout << "---------------------------------" << endl;
    cout << setw(20) << "selection sort:" << endl;
    start = clock();
    strSelSort(randStrSel1, 1000);
    stop = clock();
    cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
    cout << "1000 strings: " << setw(8) << cpu_time_used << " seconds" << endl;
    start = clock();
    strSelSort(randStrSel3, 3000);
    stop = clock();
    cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
    cout << "3000 strings: " << setw(8) << cpu_time_used << " seconds" << endl;
    start = clock();
    strSelSort(randStrSel5, 5000);
    stop = clock();
    cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
    cout << "5000 strings: " << setw(8) << cpu_time_used << " seconds" << endl;
    start = clock();
    strSelSort(randStrSel7, 7000);
    stop = clock();
    cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
    cout << "7000 strings: " << setw(8) << cpu_time_used << " seconds" << endl;
    start = clock();
    strSelSort(randStrSel9, 9000);
    stop = clock();
    cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
    cout << "9000 strings: " << setw(8) << cpu_time_used << " seconds" << endl;
    //workaround to sort 11000 strings with selection
    fillStrs(randStrBub11, 11000);
    start = clock();
    strSelSort(randStrBub11, 11000);
    stop = clock();
    cpu_time_used = ((double) (stop - start)) / CLOCKS_PER_SEC;
    cout << "11000 strings: " << setw(7) << cpu_time_used << " seconds" << endl;

    cout << "---------------------------------" << endl;
    cout << setw(20) << "linear search:" << endl;
    linSearch(randStrBub11, 11000);
    cout << "---------------------------------" << endl;
    cout << setw(20) << "binary search:" << endl;
    binSearch(randStrBub11, 11000);
    cout << "---------------------------------" << endl;

    return 0;
}

void fillStrs(string *randStr, int size)
{
    char  charset[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
        'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
        'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    string str;
    int letter;

    for (int i=0;i<size;i++)
    {
   	    for (int j = 0; j < 15; j++ )
        {
	        letter = rand() % 52;
            str = str + charset[letter];
        }
        *randStr = str;
        str="";
        randStr++;
    }
}

void printStrs(string * randStr, int size)
{
    for (int i=0;i<size;i++)
    //for (randStr; randStr < &randStr[size-1];randStr++)
    {
        cout << *randStr << endl;
        randStr++;
    }
}

void strBubSort(string *s, int size)
{
    string temp;

    for (int pass=0;pass<size-1;pass++)
    {
        for (int i=0;i<size-1;i++)
        {
            if (s[i].compare(s[i+1]) > 0)
            {
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
            }
        }
    }
}

void strSelSort(string *s, int size)
{
    int i, minI;
    string minV;
    for (i =0; i < size-1; i++)
    {
        minI = i;
        minV = s[i];
        for(int j = i + 1; j < size; j++)
        {
            if (s[j] < minV)
            {
                minV = s[j];
                minI = j;
            }
        }
        s[minI] = s[i];
        s[i] = minV;
    }
}

void linSearch(string *s, int size)
{
    int element = 0;
    int j = 0;
    string target = "";
    int probes = 0;
    bool found = false;
    for (int i = 0;i<3000;i++)
    {
        int j = 0;
        found = false;
        element = rand() % 1000;
        target = s[element];
        while (j<size && !found)
        {
            if (s[j] == target)
            {
                found = true;
            }
            j++;
            probes++;
        }
    }
    cout << "avg number of probes: " << probes / 3000.0 << endl;
    cout << "theoretical avg: 3000/2 = 1500" << endl;
}

void binSearch(string *s, int size)
{
    int first = 0;
    int last = size - 1;
    int middle;
    bool found = false;
    int element = 0;
    string target = "";
    int probes = 0;

    for (int i=0;i<3000;i++)
    {
        first = 0;
        last = size -1;
        middle = 0;
        found = false;
        element = rand() % 1000;
        target = s[element];
        while (!found && first <= last)
        {
            middle = (first + last) / 2;
            if (s[middle] == target)
            {
                found = true;
            }
            else if (s[middle] > target)
            {
                   last = middle - 1;
            }
            else
            {
                   first = middle + 1;
            }
            probes++;
        }
    }
    cout << "avg num of probes: " << probes / 3000.0 << endl;
    cout << "theoretical avg: log2(3000) = 11.55" << endl;
}
