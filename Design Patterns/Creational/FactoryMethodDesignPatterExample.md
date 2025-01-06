# Factory Method Design Pattern

### The Factory Method Design Pattern is a creational pattern that provides an interface for creating objects but allows subclasses to alter the type of objects that will be created. It delegates the instantiation process to subclasses or specific methods, enabling loose coupling between the client and the concrete classes.

## Code Explanation

### 1. Abstract Product

  + Food: An abstract class representing the base product. Subclasses override the prepare() method to define specific preparation steps.

    ```cpp
    class Food{
    public:
        virtual void prepare() const = 0; // Pure virtual
        virtual ~Food() = default;
    };
    ```

### 2. Concrete Products

  These classes inherit from the Food class and implement the prepare() method:

  + **Chicken:**

    ```cpp
    class Chicken : public Food{
    public:
        void prepare() const override{
            cout<<"Preparing chicken . . . \n";
        }
    };
    ```
  + **Beff:**
    ```cpp
    class Beef : public Food{
    public:
        void prepare() const override{
            cout<<"Preparing beef . . . \n";
        }
    };
    ```
    
  + **Vegetables:**
    ```cpp
    class Vegetables : public Food{
    public:
        void prepare() const override{
            cout<<"Preparing vegetables . . . \n";
        }
    };
    ```

  + **Salad:**
    ```cpp
    class Salad : public Food{
    public:
        void prepare() const override{
            cout<<"Preparing salad . . . \n";
        }
    };
    ```
### 3. Food Factory

  + FoodFactory: The abstract factory that declares the method orderFood() for creating Food objects.

    ```cpp
    class FoodFactory{
    public:
        virtual Food* orderFood(const string& type) const = 0;
        virtual ~FoodFactory() = default;
    };
    ```

### 4. Concrete Factory

  + OrderFromRestaruant: Implements the factory method orderFood() to create Food objects based on the specified type.
    ```cpp
    class OrderFromRestaruant : public FoodFactory{
    public:
        Food* orderFood(const string& type) const override{
            if (type == "Chicken") return new Chicken();
            if (type == "Beef") return new Beef();
            if (type == "Salad") return new Salad();
            if (type == "Vegetables") return new Vegetables();
            cout << "Sorry we don't have " << type << "\n";
            return nullptr;
        }
    };
    ```
### 5. Usage in main Function

The main function demonstrates how to use the factory to create and prepare food items:

```cpp
int main(){
    OrderFromRestaruant restaurant;

    Food* food1 = restaurant.orderFood("Chicken");
    if(food1){
        food1->prepare();
        delete food1;
    }

    Food* food2 = restaurant.orderFood("Salad");
    if(food2){
        food2->prepare();
        delete food2;
    }

    Food* food3 = restaurant.orderFood("Pizza");
    if(food3){
        food3->prepare();
        delete food3;
    }
}
```

## Output

![image](https://github.com/user-attachments/assets/836f043c-e1a3-4f87-9c86-751f029e171c)

## Key Points of the Factory Method Pattern
1. Encapsulation: The client code (in main) is decoupled from the actual product classes (Chicken, Beef, etc.).
2. Extensibility: New products (e.g., Pizza) can be added without modifying the existing factory interface or client code.
3. Centralized Creation: All object creation logic is centralized in the factory class.

## Key Difference Between Factory Method and Abstract Factory

![image](https://github.com/user-attachments/assets/3a4dad1b-af9e-4fa1-8833-8762300f1eb7)
