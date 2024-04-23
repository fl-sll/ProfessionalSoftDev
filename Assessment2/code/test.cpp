#include <iostream>
#include <vector>

//// Forward declarations
class Patron;
class Host;
class Manager;
class FoodMaker;
class CoffeeMaker;

//// Base class for food and drink items
class MenuItem {
public:
    virtual ~MenuItem() {}
    virtual std::string getName() const = 0;
};

//// Food class
class Food : public MenuItem {
public:
    Food(std::string name) : name(name) {}
    std::string getName() const override { return name; }
private:
    std::string name;
};

//// Coffee base class
class Coffee : public MenuItem {
public:
    Coffee(std::string name) : name(name), sugars(0) {}
    std::string getName() const override { return name; }
    void addSugar(int amount) { sugars += amount; }
protected:
    std::string name;
    int sugars;
};

//// BlackCoffee subclass
class BlackCoffee : public Coffee {
public:
    BlackCoffee() : Coffee("Black Coffee") {}
};

//// WhiteCoffee subclass
class WhiteCoffee : public Coffee {
public:
    WhiteCoffee() : Coffee("White Coffee") {}
};

//// Order class
class Order {
public:
    void addItem(MenuItem* item) {
        items.push_back(item);
    }
    const std::vector<MenuItem*>& getItems() const {
        return items;
    }
private:
    std::vector<MenuItem*> items;
};

//// Patron class
class Patron {
public:
    Patron(std::string name) : name(name) {}
    std::string getName() const { return name; }
private:
    std::string name;
};

//// Manager class (Mediator)
class Manager {
public:
    void receiveOrder(Patron* patron, Order* order);
    void setFoodMaker(FoodMaker* maker) {
        foodMaker = maker;
    }
    void setCoffeeMaker(CoffeeMaker* maker) {
        coffeeMaker = maker;
    }
    void setHost(Host* hst) {
        host = hst;
    }
    //? Notify when coffee is ready
    void coffeeReady() {
        std::cout << "Coffee is ready!" << std::endl;
    }
    //? Notify when food is ready
    void foodReady() {
        std::cout << "Food is ready!" << std::endl;
    }
private:
    FoodMaker* foodMaker;
    CoffeeMaker* coffeeMaker;
    Host* host;
};

//// FoodMaker class
class FoodMaker {
public:
    void makeFood(MenuItem* item) {
        //? Simulate making food
        std::cout << "Making food: " << item->getName() << std::endl;
        //? Notify manager when food is ready
        manager->foodReady();
    }
    void setManager(Manager* mgr) {
        manager = mgr;
    }
private:
    Manager* manager;
};

//// CoffeeMaker class
class CoffeeMaker {
public:
    void makeCoffee(MenuItem* item) {
        //? Simulate making coffee
        std::cout << "Making coffee: " << item->getName() << std::endl;
        //? Notify manager when coffee is ready
        manager->coffeeReady();
    }
    void setManager(Manager* mgr) {
        manager = mgr;
    }
private:
    Manager* manager;
};

//// Host class (Facade)
class Host {
public:
    void takeOrder(Patron* patron, Order* order) {
        //? Host takes order from patron and forwards it to the manager
        manager->receiveOrder(patron, order);
    }
    void notifyPatron(std::string name, Order* order) {
        //? Host notifies the patron that their order is ready
        std::cout << "Order for " << name << " is ready:" << std::endl;
        for (auto item : order->getItems()) {
            std::cout << "- " << item->getName() << std::endl;
        }
    }
    void setManager(Manager* mgr) {
        manager = mgr;
    }
private:
    Manager* manager;
};

void Manager::receiveOrder(Patron* patron, Order* order) {
    //? Manager receives order from host and forwards it to appropriate makers
    for (auto item : order->getItems()) {
        if (dynamic_cast<Food*>(item)) {
            foodMaker->makeFood(item);
        } else if (dynamic_cast<Coffee*>(item)) {
            coffeeMaker->makeCoffee(item);
        }
    }
    //? Notify host when order is complete
    host->notifyPatron(patron->getName(), order);
}

int main() {
    //? Create objects
    Host host;
    Manager manager;
    FoodMaker foodMaker;
    CoffeeMaker coffeeMaker;

    //? Set relationships between objects
    host.setManager(&manager);
    manager.setHost(&host);
    manager.setFoodMaker(&foodMaker);
    manager.setCoffeeMaker(&coffeeMaker);
    foodMaker.setManager(&manager);
    coffeeMaker.setManager(&manager);

    //? Patron enters the cafe
    Patron patron("Alice");

    //? Patron gives order to the host
    Order order;
    order.addItem(new Food("Candy Bar"));
    order.addItem(new BlackCoffee());
    order.addItem(new WhiteCoffee());
    host.takeOrder(&patron, &order);

    return 0;
}