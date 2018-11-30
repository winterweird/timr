#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <iomanip>
#include <cassert>

using std::endl;
using std::cout;
using std::setw;
using std::cin;
using std::cerr;
using std::vector;
using std::string;
using std::literals::chrono_literals::operator""s;

class countdown {
    public:
        countdown(int hours, int minutes, int seconds) {
            assert(hours >= 0);
            assert(minutes >= 0);
            assert(seconds >= 0);
            _seconds = hours*3600 + minutes*60 + seconds;
        }
        countdown(int minutes, int seconds) {
            assert(minutes >= 0);
            assert(seconds >= 0);
            _seconds = minutes*60 + seconds;
        }
        countdown(int seconds) {
            assert(seconds >= 0);
            _seconds = seconds;
        }
        bool done() const {
            return _seconds <= 0;
        }
        void tick() {
            if (_seconds > 0) --_seconds;
        }
        int hours() const {
            return _seconds / 3600;
        }
        int minutes() const {
            return (_seconds % 3600) / 60;
        }
        int seconds() const {
            return _seconds % 60;
        }
    private:
        int _seconds;
};

std::ostream& operator<<(std::ostream &os, const countdown& c) {
    std::ios_base::fmtflags f(os.flags());
    os.fill('0');
    os << setw(2) << c.hours()   << ":"
       << setw(2) << c.minutes() << ":"
       << setw(2) << c.seconds();
    os.flags(f);
    return os;
}

int main(int argc, char** argv) {
    // ESC[2J clears entire screen
    const string clearScreen = "\033[2J"; // NOTE: Not currently used
    // ESC[2K clears current line, ESC[0G puts cursor on 0th column of current line
    const string clearLine = "\033[2K\033[0G";
    
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    
    try {
        if (argc == 1) {
            // no arguments; read from stdin
            cin >> hours >> minutes >> seconds;
            if (!cin) {
                cerr << "Error: Requires integer input of <hours> <minutes> <seconds>" << endl;
                return 1;
            }
        }
        else if (argc == 2){
            seconds = std::stoi(argv[1]);
        }
        else if (argc == 3) {
            minutes = std::stoi(argv[1]);
            seconds = std::stoi(argv[2]);
        }
        else {
            hours = std::stoi(argv[1]);
            minutes = std::stoi(argv[2]);
            seconds = std::stoi(argv[3]);
        }
    } catch (std::invalid_argument& err) {
        cerr << "Error: All time arguments must be integers" << endl;;
        return 1;
    }
    
    if (hours < 0 || minutes < 0 || seconds < 0) {
        cerr << "Error: All time arguments must be non-negative" << endl;
        return 1;
    }
    countdown timer(hours, minutes, seconds);
    
    cout << clearLine << timer;
    cout.flush();
    while (!timer.done()) {
        std::this_thread::sleep_for(1s);
        timer.tick();
        cout << clearLine << timer;
        cout.flush();
    }

    cout << " " << endl;
}
