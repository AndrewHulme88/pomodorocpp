#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <functional>
#include <iomanip>

void start_timer() {
    std::cout << "Time to work!" << std::endl;
}

void count_down(int count, std::function<void()> start_timer, int reps, std::string& check_label) {
    int count_min = count / 60;
    int count_sec = count % 60;
    std::string count_sec_str;

    if (count_sec == 0) {
        count_sec_str = "00";
    }
    else if (count_sec < 10) {
        count_sec_str = "0" + std::to_string(count_sec);
    }
    else {
        count_sec_str = std::to_string(count_sec);
    }

    std::cout << std::setfill('0') << std::setw(2) << count_min << ":" << count_sec_str << std::endl;

    if (count > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count_down(count - 1, start_timer, reps, check_label);
    }
    else {
        start_timer();
        std::string mark = "";
        int work_sessions = reps / 2;
        for (int i = 0; i < work_sessions; i++) {
            mark += "";
        }
        check_label = mark;
        std::cout << "Check Label: " << check_label << std::endl;
    }
}

int main() {
    int reps = 4;

    int work_duration = 25 * 60;
    int break_duration = 5 * 60;

    std::string check_label = "";

    for (int i = 0; i < reps; i++) {
        if (i % 2 == 0) {
            std::cout << "Work session started!" << std::endl;
            count_down(work_duration, start_timer, reps, check_label);
        }
        else {
            std::cout << "Break time!" << std::endl;
            count_down(break_duration, start_timer, reps, check_label);
        }
    }

    return 0;
}
