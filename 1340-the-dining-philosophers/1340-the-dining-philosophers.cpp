
class DiningPhilosophers {
    binary_semaphore fork[5] { 
        binary_semaphore(1),
        binary_semaphore(1),
        binary_semaphore(1),
        binary_semaphore(1),
        binary_semaphore(1)
    };

    mutex m; // to avoid deadlock

public:
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) 
    {
        {
            lock_guard<mutex> lock(m);
            fork[(philosopher + 1) % 5].acquire(); // right fork
            fork[philosopher].acquire();           // left fork
        }

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        fork[(philosopher + 1) % 5].release();

        putRightFork();
        fork[philosopher].release();
    }
};