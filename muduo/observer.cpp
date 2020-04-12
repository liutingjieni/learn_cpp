/*************************************************************************
	> File Name: observer.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年04月12日 星期日 16时53分57秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Observer 
{
 public:
    virtual ~Observer();
    virtual void update() = 0;
    void Observer(Observable *s)
    {
        s->register_(this);
        subject_ =s;
    }

    virtual ~Observer() 
    {
        subject_->unregister(this);
    }

    Observable *subject_;
};

class Observable 
{
 public:
    void register_(weak_ptr<Observer> x);
    //void unregister_(weak_ptr<Observer> x);
    void notifyObservers();
 private:
    mutable Mutexlock mutex_;
    vector<weak_ptr<Observer> > Observers_;
    typedef vector<weak_ptr<Observer> >::iterator Iterator;
};

mZ Observable::notifyObservers()
{
    MutexlockGuard lock(mutex_);
    Iterator it =Observers_.begin();
    while (it != Observers_.end()) {
        shared_ptr<Observer> obj(it->lock);
        if (obj) {
            obj->update();
            ++it;
        }
        else {
            it = Observers_.erase(it);
        }
    }
};
