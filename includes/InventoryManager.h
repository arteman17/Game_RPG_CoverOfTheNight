#pragma once

#include "Item.h"

#include <vector>

class InventoryManager {
public:
    std::vector<Item> items();
    void addItem(Item* item);

private:
    std::vector<Item> items_{ };
};
