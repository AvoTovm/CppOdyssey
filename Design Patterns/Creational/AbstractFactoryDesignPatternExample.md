# Abstract Factory Design Pattern

### The Abstract Factory Design Pattern provides an interface for creating families of related or dependent objects without specifying their concrete classes. This example demonstrates a gun shop system that uses an Abstract Factory to sell rifles and pistols.

---

## Implementation

### 1. Abstract Product: `Gun`

+ The `Gun` class is an abstract base class defining the interface for all types of guns. Each concrete gun (e.g., rifles and pistols) inherits from this class.

    ```cpp
    class Gun {
        public:
            virtual void shoot() const = 0; // Pure virtual function
            virtual ~Gun() = default;      // Virtual destructor
    };
-- --
### 2. Concrete Products: `Rifles` and `Pistols`

These classes inherit from Gun and implement the shoot method. Each class represents a specific type of gun.

+ `Rifles:`
  ```cpp
  class Rifles : public Gun {
    public:
        void shoot() const override {
            cout << "AK47 shooting 7.62 bullets\n";
            cout << "AK112 shooting 7.62 bullets\n";
            cout << "AK74 shooting 7.62 bullets\n";
        }
  };
  ```
+ `Pistols`
  ```cpp
  class Pistols : public Gun {
    public:
        void shoot() const override {
            cout << "Glock 17 shooting 9mm bullets\n";
            cout << "Berreta shooting 9mm bullets\n";
            cout << "Makarov shooting 9mm bullets\n";
        }
  };

  ```
-- --

### 3. Abstract Factory: `GunFactory`

The `GunFactory` class defines a factory interface for creating guns. It has a single pure virtual method `createGun`, which must be implemented by concrete factories.

```cpp
class GunFactory {
    public:
        virtual Gun* createGun() const = 0; // Pure virtual function
        virtual ~GunFactory() = default;   // Virtual destructor
};
```

-- --

### 4. Concrete Factories: `RifleFactory` and `PistolFactory`

These classes inherit from `GunFactory` and create specific types of guns.

+ `RifleFactory:`
  ```cpp
  class RifleFactory : public GunFactory {
    public:
        Gun* createGun() const override {
            return new Rifles(); // Creates a rifle
        }
  };
  ```
+ `PistolFactory:`
  ```cpp
  class PistolFactory : public GunFactory {
    public:
        Gun* createGun() const override {
            return new Pistols(); // Creates a pistol
        }
  };
  ```
-- --

### 5. Client Class: `GunShop`

The `GunShop` class acts as a client for the Abstract Factory. It uses a `GunFactory` to produce guns and sell them. The specific factory (e.g., `RifleFactory` or `PistolFactory`) is provided at runtime.

```cpp
class GunShop {
    public:
        GunShop(GunFactory* factory) : factory_(factory) {}

        void sellGun() const {
            Gun* gun = factory_->createGun(); // Create gun using the factory
            gun->shoot();                     // Display gun details
            delete gun;                       // Clean up
        }

    private:
        GunFactory* factory_; // Factory instance
};
```

### 6. Main Function

The `main` function demonstrates the creation of rifles and pistols using their respective factories and the `GunShop`.

```cpp
int main() {
    cout << "--------------------------------------------------------\n";
    cout << "Welcome to the gun shop!\n";
    cout << "--------------------------------------------------------\n";

    // Rifle Section
    cout << "These are all the rifles we have:\n";
    RifleFactory rifleFactory;
    GunShop rifleShop(&rifleFactory);
    rifleShop.sellGun();

    cout << "--------------------------------------------------------\n";

    // Pistol Section
    cout << "These are all the pistols we have:\n";
    PistolFactory pistolFactory;
    GunShop pistolShop(&pistolFactory);
    pistolShop.sellGun();

    cout << "--------------------------------------------------------\n";
}
```

## Output

![image](https://github.com/user-attachments/assets/e525a4aa-9cc6-4757-8fd1-101d8cc4203b)

## Advantages of Using Abstract Factory

1. Flexibility: Easily add new gun types by creating additional concrete factories and products.
2. Encapsulation: Separates object creation logic from the client (GunShop).
3. Scalability: Supports families of related objects.


