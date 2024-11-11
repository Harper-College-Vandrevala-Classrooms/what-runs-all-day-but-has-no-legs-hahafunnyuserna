#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;
using chrono::system_clock;

class Timer
{
    public:
        void start()
        {
            m_StartTime = system_clock::now();
            m_bRunning = true;
        }
        
        void stop()
        {
            m_EndTime = system_clock::now();
            m_bRunning = false;
        }
        
        double elapsedSeconds()
        {
            time_point<system_clock> endTime;
            
            if(m_bRunning)
            {
                endTime = system_clock::now();
            }
            else
            {
                endTime = m_EndTime;
            }
            
            return duration_cast<seconds>(endTime - m_StartTime).count();
        }
        
    private:
        time_point<system_clock> m_StartTime;
        time_point<system_clock> m_EndTime;
        bool m_bRunning = false;
};

int main()
{   
    Timer timer;

    while (true)
    {
        string actionChar;
        cout << "\nPlease input an action:\n[S] - Start the timer\n[T] - Stop the timer\n[E] - Show elapsed time\n[Q] - Quit\n";

        while ((!(cin >> actionChar)) || ((actionChar != "S") && (actionChar != "T") && (actionChar != "E") && (actionChar != "Q") && (actionChar != "s") && (actionChar != "t") && (actionChar != "e") && (actionChar != "q")))
        {
            cout << "ERROR: Invalid response. Please input an action.\n";
            cin.clear();
            cin.ignore(40, '\n');
        }

        if ((actionChar == "S") || (actionChar == "s"))
        {
            timer.start();
            cout << "Timer started.\n";
        }

        if ((actionChar == "T") || (actionChar == "t"))
        {
            timer.stop();
            cout << "Timer stopped at " << timer.elapsedSeconds() << " seconds.\n";
        }

        if ((actionChar == "E") || (actionChar == "e"))
        {
            cout << "Your timer is set for " << timer.elapsedSeconds() << " seconds.\n";
        }

        if ((actionChar == "Q") || (actionChar == "q"))
        {
            cout << "Goodbye.\n";
            break;
        }
    }
}