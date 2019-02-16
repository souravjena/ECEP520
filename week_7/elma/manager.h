#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <map>
#include <chrono>
#include <functional>

#include "elma.h"

namespace elma {

    using std::string;
    using std::vector;
    using std::map;
    using namespace std::chrono;

    class Channel;
    class Process;

    //! The Process Manager class. 
    class Manager {

        public: 

        //! Default constructor
        Manager() {}

        Manager& add_channel(Channel&);
        Manager& schedule(Process& process, high_resolution_clock::duration period);

        Channel& channel(string);

        Manager& all(std::function<void(Process&)> f);

        Manager& init();
        Manager& start();
        Manager& update();        
        Manager& stop();

        Manager& run(high_resolution_clock::duration);

        //! Getter
        //! \return The time the Manager was most recently started
        inline high_resolution_clock::time_point start_time() { return _start_time; }

        //! Getter
        //! \return The duration of time since the manager was most recently started
        inline high_resolution_clock::duration elapsed() { return _elapsed; }

        private:

        vector<Process *> _processes;
        map<string, Channel *> _channels;
        high_resolution_clock::time_point _start_time;
        high_resolution_clock::duration _elapsed;

    };

}

#endif