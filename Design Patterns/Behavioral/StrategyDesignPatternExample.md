# Strategy Design Pattern

### The Strategy Design Pattern defines a family of algorithms, encapsulates each one, and makes them interchangeable. It allows the algorithm to vary independently from the clients that use it. In this implementation, we demonstrate a payment system where the payment strategy can be dynamically set at runtime.

## Code Explaination

### 1.Base Class: PaymentStrategy

The PaymentStrategy is an abstract base class that declares the interface for all payment methods.

```cpp
class PaymentStrategy{
    public:
        virtual void pay(int amount) const = 0;
        virtual ~PaymentStrategy() = default;
};
```

### 2. Concrete Strategies

These are specific implementations of the PaymentStrategy interface:

+ Credit Card Payment:

   ```cpp
  class CreditCardPayment : public PaymentStrategy{
    private:
        string cardNumber;
    public:
        CreditCardPayment(const string& cardNumber) : cardNumber(cardNumber) {}

        void pay(int amount) const override {
            cout<<"Paid "<<amount<<" using Credit Card "<<cardNumber<<"\n";
        }
  };

  ```

+ PayPal Payment:

  ```cpp
  class PayPalPayment : public PaymentStrategy{
    private:
        string email;
    public:
        PayPalPayment(const string& email) : email(email) {}

        void pay(int amount) const override {
            cout<<"Paid "<<amount<<" using PayPal "<<email<<"\n";
        }
  };
  ```

+ Cryptocurrency Payment:

  ```cpp
  class CryptoPayment : public PaymentStrategy{
    private:
        string walletAddress;
    public:
        CryptoPayment(const string& walletAddress) : walletAddress(walletAddress) {}

        void pay(int amount) const override {
            cout<<"Paid "<<amount<<" using Cryptocurrency wallet "<<walletAddress<<"\n";
        }
  };

  ```

### 3. Context Class: **PaymentContext**

The PaymentContext class uses a PaymentStrategy object to execute the payment. It allows you to change the strategy at runtime.

```cpp
class PaymentContext{
    private:
        PaymentStrategy* strategy;
    public:
        PaymentContext() : strategy(nullptr){}

        void setPaymentStrategy(PaymentStrategy* newStrategy){
            strategy = newStrategy;
        }

        void executePayment(int amount) const{
            if(strategy){
                strategy->pay(amount);
            }else {
                cout<<"Payment strategy is not set for "<<strategy<<"\n";
            }
        }
};
```

## Key Benefits of the Strategy Pattern

1. Open/Closed Principle: You can add new payment strategies without modifying existing code.
2. Runtime Flexibility: Change the payment method dynamically.
3. Separation of Concerns: The context class focuses only on executing the strategy, not implementing it.
