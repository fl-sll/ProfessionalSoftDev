#include "./../header/foodmaker.h"
#include "./../header/manager.h"
#include "./../header/food.h"
#include "./../header/readJson.h"
#include <iostream>
#include <windows.h>
#include <vector>

FoodMaker::FoodMaker(std::vector<Food> food):food(food){}

void FoodMaker::makeFood(MenuItem *item)
{
    std::cout << "Making food: " << item->getName() << std::endl;
    this->delStock(item->getName());
    Sleep(1000);
    manager->foodReady();
};

void FoodMaker::setManager(Manager *mgr)
{
    manager = mgr;
}
void FoodMaker::delStock(std::string name)
{
    updateJsonFood(food, name);
}