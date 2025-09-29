#include <iostream>
#include <vector>
#include <queue>

struct event {
    event(int start, int end, int id) {
        startTime = start;
        endTime = end;
        eventId = id;
    }
    int startTime;
    int endTime;
    int eventId;
};

struct cmp
{
    bool operator()(event a, event b){
        return a.endTime > b.endTime;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> s(n);
    std::vector<int> f(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> f[i];
    }

    std::priority_queue<event, std::vector<event>, cmp> eventQueue;
    for (int i = 0; i < n; i++) {
        eventQueue.push(event(s[i], f[i], i + 1));
    }

    std::vector<int> eventOrder;
    int numberOfEvent = 0;
    while (!eventQueue.empty()) {
        event chooseEvent = eventQueue.top();
        eventQueue.pop();
        numberOfEvent++;
        eventOrder.push_back(chooseEvent.eventId);
        while (!eventQueue.empty() && eventQueue.top().startTime < chooseEvent.endTime) eventQueue.pop();
    }
    
    std::cout << numberOfEvent << std::endl;
    std::cout << "(" << eventOrder[0];
    for(int i = 1; i < numberOfEvent ; i++){
        std::cout << "," << eventOrder[i];
    }
    std::cout << ")";

    return 0;
}