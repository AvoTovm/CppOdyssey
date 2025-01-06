# Observer Design Pattern

### The Observer Design Pattern defines a one-to-many dependency between objects so that when one object (the Subject) changes state, all its dependents (Observers) are notified and updated automatically.
### This pattern is widely used for event-handling systems, such as GUIs and messaging systems.

## Code

### 1. Base Classes
  + Observer: An interface for objects that want to be notified of changes in the subject.
    ```cpp
    class Observer{
    public:
        virtual ~Observer() = default;
        virtual void update(const string &message) = 0;
    };

    ```
  + Subject: An interface for managing observers.
    ```cpp
    class Subject{
    public:
        virtual ~Subject() = default;
        virtual void attach(Observer *observer) = 0;
        virtual void detach(Observer *observer) = 0;
        virtual void notify() = 0;
    };
    ```

### 2. Concrete Classes
  + ConcreteSubject: Implements the Subject interface and maintains the state to be observed.

    ```cpp
    class ConcreteSubject : public Subject{
    private:
        vector<Observer *> observers;
        string message;

    public:
        void attach(Observer *observer) override{
            observers.push_back(observer);
        }

        void detach(Observer *observer) override{
            observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
        }

        void notify() override{
            for(Observer *observer : observers){
                observer->update(message);
            }
        }

        void createMessage(const string &msg){
            message = msg;
            notify();
        }
    };
    ```
  + ConcreteObserver: Implements the Observer interface to react to changes in the subject.

    ```cpp
    class ConcreteObserver : public Observer{
    private:
        string observerName;

    public:
        explicit ConcreteObserver(const string &name) : observerName(name){}

        void update(const string &message) override{
            cout<<"Observer "<<observerName<<" received message "<<message<<"\n";
        }
    };

    ```

### 3. Usage in main Function
  + Create a ConcreteSubject object and attach multiple ConcreteObserver instances to it.
  + Send notifications by calling the createMessage method.

    ```cpp
    int main() {
      ConcreteSubject subject;
  
      ConcreteObserver observer1("Observer 1");
      ConcreteObserver observer2("Observer 2");
      ConcreteObserver observer3("Observer 3");
  
      subject.attach(&observer1);
      subject.attach(&observer2);
      subject.attach(&observer3);
  
      subject.createMessage("Hello, Observers!");
  
      cout << "\nDetaching Observer 2...\n\n";
      subject.detach(&observer2);
  
      subject.createMessage("Another message for the remaining observers!");
    }

    ```
## Output

![image](https://github.com/user-attachments/assets/96613816-b491-46e2-b6f5-74cd0e89f4a2)

## Key Benefits of the Observer Pattern

1. Loose Coupling: Observers and Subjects are loosely connected through interfaces.
2. Dynamic Behavior: You can add or remove observers dynamically.
3. Decoupled Notification: Subject and Observers communicate indirectly, enhancing reusability and maintainability. 
