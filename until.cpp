#include <iostream>
#include <ctime>
#include <cstring>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    struct tm my_time;
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " YYYY-MM-dd [HH:mm:ss]" << endl;
        return 1;
    }

    int YYYY;
    int MM;
    int dd;

    my_time.tm_year = std::stoi(strtok(argv[1], "-"))-1900;
    my_time.tm_mon  = std::stoi(strtok(NULL, "-"))-1;
    my_time.tm_mday = std::stoi(strtok(NULL, "-"));
    
    if (argc > 2) {
        my_time.tm_hour = std::stoi(strtok(argv[2], ":"));
        my_time.tm_min = std::stoi(strtok(NULL, ":"));
        my_time.tm_sec = std::stoi(strtok(NULL, ":"));
    }
    else {
        my_time.tm_hour = 0;
        my_time.tm_min = 0;
        my_time.tm_sec = 0;
    }

    time_t current = time(NULL);
    time_t t = mktime(&my_time) - current;
    cout.fill('0');
    cout << setw(2) << (t/3600) << " "
         << setw(2) << ((t%3600)/60) << " "
         << setw(2) << (t%60) << endl;
}
