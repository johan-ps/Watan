#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;

class Subject {
    //std::vector<Observer*> observers;
    public:
    // virtual void attach(Observer) = 0;
    // virtual void detach(Observer) = 0;
    // virtual void notifyObserver(Observer) = 0;
    virtual ~Subject();
};

#endif
