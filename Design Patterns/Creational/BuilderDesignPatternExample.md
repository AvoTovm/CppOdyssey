# Builder Design Pattern

The Builder Design Pattern is used to construct complex objects step by step. It separates the construction process from the representation, allowing the same construction process to create different representations.

This example demonstrates a salad menu system where users can customize salads using a builder.

---

## Implementation

### 1. Product Class: `Salad`

The `Salad` class represents the final product. It contains a list of ingredients and methods to add ingredients and display the salad.

```cpp
class Salad {
    private:
        vector<string> ingredients;

    public:
        void addIngredient(string ingridient) {
            ingredients.push_back(ingridient);
        }

        void showSalad() {
            cout << "Your salad contains:\n";
            for (auto ingredient : ingredients) {
                cout << "- " << ingredient << "\n";
            }
        }
};
```

### 2. Abstract Builder: `SaladBuilder`

The SaladBuilder class defines the interface for building a salad. It has methods to add various types of ingredients.

```cpp
class SaladBuilder {
    public:
        virtual ~SaladBuilder() {}
        virtual void addBase() = 0;
        virtual void addVegetables() = 0;
        virtual void addProtein() = 0;
        virtual void addDressing() = 0;
        virtual void addExtras() = 0;
        virtual Salad* getSalad() = 0;
};
```

-- --

### 3. Concrete Builder: `CustomSaladBuilder`

The `CustomSaladBuilder` class implements the `SaladBuilder` interface. It builds a salad by adding specific ingredients to the `Salad` object.

```cpp
class CustomSaladBuilder : public SaladBuilder {
    private:
        Salad* salad;

    public:
        CustomSaladBuilder() {
            reset();
        }

        ~CustomSaladBuilder() {
            delete salad;
        }

        void reset() {
            salad = new Salad();
        }

        void addBase() override {
            salad->addIngredient("Lettuce");
            salad->addIngredient("Spinach");
        }

        void addVegetables() override {
            salad->addIngredient("Tomatoes");
            salad->addIngredient("Cucumbers");
            salad->addIngredient("Carrots");
        }

        void addProtein() override {
            salad->addIngredient("Grilled Chicken");
            salad->addIngredient("Boiled Eggs");
            salad->addIngredient("Chickpeas");
        }

        void addDressing() override {
            salad->addIngredient("Olive Oil");
        }

        void addExtras() override {
            salad->addIngredient("Croutons");
            salad->addIngredient("Parmesan Cheese");
            salad->addIngredient("Sunflower Seeds");
        }

        Salad* getSalad() override {
            Salad* result = salad;
            reset();
            return result;
        }
};
```

-- --

### 4. Director Class: `SaladMenu`

The `SaladMenu` class defines the construction process. It uses the builder to create different types of salads.

```cpp
class SaladMenu {
    private:
        SaladBuilder* builder;

    public:
        SaladMenu(SaladBuilder* b) : builder(b) {}

        void makeFullSalad() {
            builder->addBase();
            builder->addVegetables();
            builder->addProtein();
            builder->addDressing();
            builder->addExtras();
        }

        void makeVegetarianSalad() {
            builder->addBase();
            builder->addVegetables();
            builder->addExtras();
        }
};
```

-- --

## 5. Main Function

The `main` function demonstrates the creation of full and vegetarian salads using the `SaladMenu` and `CustomSaladBuilder`.

```cpp
int main() {
    CustomSaladBuilder builder;
    SaladMenu menu(&builder);

    // Create a full salad
    cout << "------------------------------------\n";
    cout << "Making a full salad\n";
    menu.makeFullSalad();
    Salad* fullSalad = builder.getSalad();
    fullSalad->showSalad();
    delete fullSalad;
    cout << "------------------------------------\n";

    // Create a vegetarian salad
    cout << "Making a vegetarian salad\n";
    menu.makeVegetarianSalad();
    Salad* vegSalad = builder.getSalad();
    vegSalad->showSalad();
    delete vegSalad;
    cout << "------------------------------------\n";
}
```

![image](https://github.com/user-attachments/assets/f3a034c0-e568-4044-a157-cffe626c7e4b)

## Advantages of Using the Builder Pattern

1. Customizable Products: The builder pattern allows creating different variations of the product (e.g., full salad and vegetarian salad).
2. Encapsulation: Hides the construction logic from the client.
3. Reusability: The same builder can be used with different directors to create various products.

