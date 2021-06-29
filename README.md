Introduction
---

This repo has two examples of delegation pattern using C++. One is a basic example that is defined in the terminology of the delegation pattern. The other is more "real world" example based of feed-handler for stock exchanges.

Delegation Pattern
---

A delegation pattern is a way to extend the functionality of a class without using inheritance. Instead, it uses composition, instead. 

There are two classes that are loosely connected to each other. One is called the "sender" and other is called the "receiver". The sender delegates some of the responsibilities of the work to be performed to the receiver. Thus, the receiver extends the functionality of the sender. The "sender" and "receiver" are named from the point of view of the who "sends" a request to whom. A "request" is a piece of work that needs to be done and is typically implemented as a function.

The sender *composes* a pointer or reference to an instance of the receiver class (rather its interface class). In order to make sure that the receiver has implemented certain set of functions, it implements an "interface". The sender can now call these functions at appropriate time during its execution.

```cpp
class sender
{
private:
    ireceiver &_delegate;

public:
    void do_work()
    {
        _delegate.do_actual_work(*this);
    }
};
```

As C++ does not have an "interface" keyword (as opposed to Java), one has to use an abstract class to define an "interface" that needs to be implemented by the receiver. The receiver inherits from "interface" abstract class (or classes) and overrides the functions defined in the "interface"


```cpp
class ireceiver
{
public:
    virtual void do_actual_work(const sender &) = 0;
};

class receiver : public ireceiver
{
    void do_actual_work(const sender &sender) override
    {
        std::cout << "Doing actual work for sender: " << sender.id() << std::endl;
    }
};    
```

Difference from Inheritance
---

If you want to extend the sender using inheritance, you have the receiver from the sender. You have to expose the details of the sender class. This might not be good idea. In contrast, the receiver needs to know only about the "interface" class.

```cpp

class sender
{
public:
    virtual void do_work(void){}
    string id(void);
};

class receiver : public sender
{
    void do_work(void) override
    {
        std::cout << "Doing actual work for sender: " << id() << std::endl;
    }
};   
```

- Delegation Pattern is a widely used pattern. Some languages have a built-in support for this.
- It is widely used in MacOS and iOS programming.
- It can be used to implement callbacks.
- Delegate function is passed a pointer(or reference) of the sender, so that it can call functionality within sender.

Code Example
---

https://github.com/waqqas/cpp-delegate-example

Building
---

- `mkdir build`
- `cd build`
- `cmake ..`
- `make`
