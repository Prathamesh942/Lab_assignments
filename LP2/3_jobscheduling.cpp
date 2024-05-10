#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Class to represent a job
class Job {
public:
    char id;
    int deadline;
    int profit;

    Job(char id, int deadline, int profit) : id(id), deadline(deadline), profit(profit) {}
};

// Function to compare jobs based on their profit
bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

// Class for Job Scheduling
class JobScheduler {
private:
    vector<Job> jobs;

public:
    JobScheduler(vector<Job> jobs) : jobs(jobs) {}

    // Function to perform job scheduling
    void scheduleJobs() {
        // Sort the jobs based on their profit in non-increasing order
        sort(jobs.begin(), jobs.end(), compare);

        int n = jobs.size();
        vector<char> result(n); // To store result (sequence of jobs)
        vector<bool> slot(n, false); // To keep track of free time slots

        // Iterate through all given jobs
        for (int i = 0; i < n; i++) {
            // Find a free slot for this job (Note that we start from the last possible slot)
            for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
                // Free slot found
                if (!slot[j]) {
                    result[j] = jobs[i].id;
                    slot[j] = true; // Mark this slot as occupied
                    break;
                }
            }
        }

        // Print the result
        for (int i = 0; i < n; i++) {
            if (slot[i])
                cout << result[i] << " ";
        }
    }
};

int main() {
    // Example jobs
    vector<Job> jobs = {
        Job('a', 2, 100),
        Job('b', 1, 19),
        Job('c', 2, 27),
        Job('d', 1, 25),
        Job('e', 3, 15)
    };

    // Create a JobScheduler object with the given jobs
    JobScheduler scheduler(jobs);

    // Print the sequence of jobs
    cout << "Sequence of jobs: ";
    scheduler.scheduleJobs();

    return 0;
}
