#include <semaphore>
#include <vector>
#include <memory>
using namespace std;

class DiningPhilosophers {
    vector<unique_ptr<binary_semaphore>> fork;
    mutex m;

public:
    DiningPhilosophers() {
        for (int i = 0; i < 5; i++) {
            fork.push_back(make_unique<binary_semaphore>(1));
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) 
    {
        {
            lock_guard<mutex> lock(m);
            fork[(philosopher + 1) % 5]->acquire();
            fork[philosopher]->acquire();
        }

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        fork[(philosopher + 1) % 5]->release();

        putRightFork();
        fork[philosopher]->release();
    }
};
