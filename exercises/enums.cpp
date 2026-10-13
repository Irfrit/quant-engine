#include <cstdint>
#include <cstdio>
#include <iostream>

enum class Side { Buy, Sell };

enum class OrderStatus { New, Filled, Cancelled };

struct Order {
  std::uint64_t id;
  Side side;
  double price;
  std::uint32_t quantity;
  OrderStatus status;
};

void print_order(const Order &order) {
  std::cout << "Order ID: " << order.id << '\n';

  std::cout << "Side: ";
  switch (order.side) {
  case Side::Buy:
    std::cout << "Buy";
    break;
  case Side::Sell:
    std::cout << "Sell";
    break;
  }

  std::cout << "\nPrice: " << order.price;
  std::cout << "\nQuantity: " << order.quantity;

  std::cout << "\nStatus: ";
  switch (order.status) {
  case OrderStatus::New:
    std::cout << "New";
    break;
  case OrderStatus::Filled:
    std::cout << "Filled";
    break;
  case OrderStatus::Cancelled:
    std::cout << "Cancelled";
    break;
  }

  std::cout << '\n';
}

void print_side(Side side) {
  std::cout << "<Side: ";

  switch (side) {
  case Side::Buy:
    std::cout << "Buy";
    break;
  case Side::Sell:
    std::cout << "Sell";
    break;
  }

  std::cout << ">\n";
}

int signed_quantity(const Order &order) {
  switch (order.side) {
  case Side::Buy:
    return order.quantity;
  case Side::Sell:
    return -order.quantity;
  }
  return 0;
}

int main() {
  Order order{1001, Side::Buy, 102.50, 10, OrderStatus::New};

  Order order2{1002, Side::Sell, 102.50, 10, OrderStatus::New};

  Order order3{1003, Side::Sell, 101.75, 25, OrderStatus::Filled};
  print_order(order);
  print_order(order2);
  print_order(order3);

  std::cout << "Signed quantity: " << signed_quantity(order) << '\n';
  std::cout << "Signed quantity: " << signed_quantity(order2) << '\n';
  std::cout << "Signed quantity: " << signed_quantity(order3) << '\n';
}
