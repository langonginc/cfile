#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

string pool[5005], respath;
int count = 0;

int main (int argc, char * argv[])
{
    // Pre
    // cout << argv[0];
    // freopen ("PathConf.txt", "r", stdin);
    // // cin >> respath;
    // getline (cin, respath);
    printf ("Reading config.txt...\n");
    freopen ("config.txt", "r", stdin);
    srand((unsigned) time(0));
    // cout << respath;

    // Read config file
    while (cin >> pool[count ++]);
    count --;
    printf ("Read %d lines.\n", count);

    // Print result
    int x = rand() % count;
    printf ("Output Line: ");
    cout << pool[x];
    freopen ("D:\\Extractor.txt", "w", stdout);
    cout << pool[x];


    fclose (stdout);
    fclose (stdin);
    freopen ("CON", "w", stdout);
    printf ("Showing Line in Notepad. Cache file: D:\\Extractor.txt\n");
    system ("notepad \"D:\\Extractor.txt\"");
    printf ("Deleting Cache file.\n");
    system ("del D:\\Extractor.txt");
    printf ("Finished!\n");    
    return 0;
}