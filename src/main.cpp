#include <iostream>
#include <fstream>
#include <iomanip>
#include "windows.h"

using namespace std;

class cuemaker {
public:
    cuemaker() { };
    ~cuemaker() { };
    void make();
private:
    int cnt = 1;
    string outputFilename, performer, title, audioFilename, audioType, subTitle, trackName, timeStamp;
};

void cuemaker::make() {
    cout << "Output filename:";
    getline(cin, outputFilename);

    ofstream fout;
    fout.open(outputFilename);

    cout << "Performer:";
    getline(cin, performer);
    fout << "PERFORMER \"" + performer + "\"\n";

    cout << "Title:";
    getline(cin, title);
    fout << "TITLE \"" + title + "\"\n";

    cout << "Audio filename:";
    getline(cin, audioFilename);
    cout << "Audio type:";
    cin >> audioType;
    fout << "FILE \"" + audioFilename + "\" " + audioType + "\n";

    cout << "Begin to make TRACK, type 'c' to continue, otherwise quit." << endl;
    string flag = "c";
    while (flag[0] == 'c') {
        if (cnt > 99) {
            cout << "Maximum track limit is reached" << endl;
            break;
        }
        cout << "Track " << cnt << endl;
        cout << "  Title:";
        getchar();
        getline(cin, trackName);
        fout << " TRACK " << setw(2) << setfill('0') << cnt << " AUDIO" << endl;
        fout << "  TITLE \"" << trackName << "\"\n";
        cout << "  Start time:";
        cin >> timeStamp;
        while (timeStamp.length() != 6) {
            cout << "Invalid length of time, try again." << endl;
            cin >> timeStamp;
        }
        if (cnt == 1 && timeStamp != "000000") {
            cout << "Track 01 must start from 00:00:00" << endl;
            timeStamp = "000000";
        }
        fout << "  INDEX 01 " << timeStamp.substr(0,2) << ":" << timeStamp.substr(2,2) << ":" << timeStamp.substr(4,2) + "\n";
        cnt++;
        cout << "type 'c' to continue, otherwise quit." << endl;
        cin >> flag;
    }
    fout.close();
    cout << "Cue file output finished.\n";
    system("pause");
}

int main() {
    cuemaker cueMaker;
    cueMaker.make();
    return 0;
}
